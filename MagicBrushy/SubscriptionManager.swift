import Foundation
import os.log
import StoreKit
import UIKit

private let brushiPremiumLog = Logger(subsystem: "Senscilab.MagicBrushy", category: "BrushiPremium")

extension Notification.Name {
    /// Posted on the main thread when premium purchase state may have changed.
    static let magicBrushySubscriptionAccessDidChange = Notification.Name("MagicBrushy.subscriptionAccessDidChange")
}

/// StoreKit 2 gate for the one-time **non-consumable** premium unlock.
///
/// **Setup (required before App Store review):**
/// 1. App Store Connect → your app → **In-App Purchases** → **Non-Consumable**.
/// 2. Product ID must match `premiumProductID` exactly.
/// 3. Attach the IAP to an app version and upload a build before sandbox testing on device.
/// 4. Xcode → Signing & Capabilities → **In-App Purchase**.
/// 5. Scheme → Run → Options → **StoreKit Configuration = None** (real App Store sandbox only).
@MainActor
final class SubscriptionManager {

    static let shared = SubscriptionManager()

    /// Must match the non-consumable Product ID in App Store Connect exactly.
    static let premiumProductID = "Senscilab.MagicBrushy.premium"

    /// Pack IDs available without purchasing premium (release builds).
    static let freeTierPackIds: Set<String> = [BuiltInColoringPages.savedDrawingsPackId, "ocean", "animals"]

    /// Free tier: one saved blank-paper drawing; no delete until premium is owned.
    static let freeTierMaxSavedFreeDrawings = 1

    private(set) var ownsPremiumUnlock = false

    private var transactionUpdatesTask: Task<Void, Never>?
    private var didStartListening = false

    private init() {}

    /// Logs to Xcode console — filter with `Brushi Premium`.
    private static func log(_ message: String) {
        print("Brushi Premium: \(message)")
        brushiPremiumLog.info("\(message, privacy: .public)")
    }

    /// Debug builds unlock every category for development; release requires Brushi Premium.
    var hasFullLibraryAccess: Bool {
        #if DEBUG
        return true
        #else
        return ownsPremiumUnlock
        #endif
    }

    func canOpenPack(id: String) -> Bool {
        Self.freeTierPackIds.contains(id) || hasFullLibraryAccess
    }

    var canDeleteFreeDrawings: Bool { hasFullLibraryAccess }

    func savedFreeDrawingCount() -> Int {
        LastDrawingStore.allSavedGalleryRecordsNewestFirst().count
    }

    func canStartAnotherFreeDrawing() -> Bool {
        hasFullLibraryAccess || savedFreeDrawingCount() < Self.freeTierMaxSavedFreeDrawings
    }

    func start() {
        guard !didStartListening else { return }
        didStartListening = true
        Self.log("StoreKit listener started for product \(Self.premiumProductID)")
        transactionUpdatesTask?.cancel()
        transactionUpdatesTask = Task { [weak self] in
            for await update in Transaction.updates {
                await self?.handle(transactionUpdate: update)
            }
        }
        Task {
            await refreshEntitlements(context: "app start")
            await probeAppStoreProduct(context: "app start")
        }
    }

    /// Fetches Brushi Premium from App Store Connect (sandbox/production). Logs bundle ID for Connect cross-check.
    private func probeAppStoreProduct(context: String) async {
        let bundleID = Bundle.main.bundleIdentifier ?? "unknown"
        Self.log("[\(context)] bundleID=\(bundleID), productID=\(Self.premiumProductID)")

        for attempt in 1...3 {
            do {
                let products = try await Product.products(for: [Self.premiumProductID])
                if let product = products.first {
                    Self.log("[\(context) attempt \(attempt)] App Store returned “\(product.displayName)” — \(product.displayPrice)")
                    return
                }
                Self.log("[\(context) attempt \(attempt)] App Store returned 0 products (no error)")
            } catch {
                Self.log("[\(context) attempt \(attempt)] App Store error — \(error.localizedDescription)")
            }
            if attempt < 3 {
                try? await Task.sleep(nanoseconds: 2_000_000_000)
            }
        }

        Self.log("""
        [\(context)] Still 0 products from Apple. App code is OK — finish Connect setup:
        1) Agreements → Paid Applications Agreement = Active
        2) App version page → In-App Purchases → add Brushi Premium
        3) Upload a build to that version (Archive → Upload)
        4) Install via TestFlight (recommended) or run on device after upload
        5) iPhone Settings → Developer → Sandbox Account → sign in
        6) Scheme → Run → Options → StoreKit Configuration = None
        """)
    }

    private func handle(transactionUpdate: VerificationResult<Transaction>) async {
        switch transactionUpdate {
        case .verified(let transaction):
            Self.log("Transaction update — product \(transaction.productID), id \(transaction.id)")
            if transaction.productID == Self.premiumProductID {
                await transaction.finish()
                Self.log("Finished Brushi Premium transaction \(transaction.id)")
            }
        case .unverified(let transaction, let error):
            Self.log("Unverified transaction — product \(transaction.productID), error \(error.localizedDescription)")
        }
        await refreshEntitlements(context: "transaction update")
    }

    func refreshEntitlements(context: String = "refresh") async {
        var ownsPremium = false
        var entitlementIDs: [String] = []
        for await entitlement in Transaction.currentEntitlements {
            guard case .verified(let transaction) = entitlement else { continue }
            entitlementIDs.append(transaction.productID)
            if transaction.productID == Self.premiumProductID {
                ownsPremium = true
            }
        }
        Self.log("[\(context)] entitlements=\(entitlementIDs.joined(separator: ", ")); ownsPremium=\(ownsPremium) (was \(ownsPremiumUnlock))")
        if ownsPremium != ownsPremiumUnlock {
            ownsPremiumUnlock = ownsPremium
            Self.log("Premium access changed → \(ownsPremium ? "unlocked" : "locked")")
            NotificationCenter.default.post(name: .magicBrushySubscriptionAccessDidChange, object: nil)
        }
    }

    func purchase(from viewController: UIViewController) async {
        Self.log("Purchase requested for \(Self.premiumProductID)")
        do {
            let products = try await Product.products(for: [Self.premiumProductID])
            Self.log("Product.products returned \(products.count) item(s)")
            guard let product = products.first else {
                Self.log("No product returned — check App Store Connect, sandbox account, and IAP attached to app version")
                presentSimpleAlert(
                    on: viewController,
                    title: "Store not ready",
                    message: """
                    Brushi Premium isn’t available yet. Ask a parent or guardian to try again later.

                    If you already bought Brushi Premium, tap Restore purchases.
                    """
                )
                return
            }
            Self.log("Loaded “\(product.displayName)” — \(product.displayPrice)")
            let result = try await product.purchase()
            switch result {
            case .success(let verification):
                Self.log("Purchase succeeded, verifying transaction…")
                let transaction = try checkVerified(verification)
                Self.log("Verified transaction \(transaction.id)")
                await transaction.finish()
                await refreshEntitlements(context: "purchase success")
            case .userCancelled:
                Self.log("Purchase cancelled by user")
            case .pending:
                Self.log("Purchase pending (e.g. Ask to Buy)")
                presentSimpleAlert(on: viewController, title: "Pending", message: "This purchase is waiting for approval (for example Ask to Buy).")
            @unknown default:
                Self.log("Purchase returned unknown result")
            }
        } catch {
            Self.log("Purchase failed — \(error.localizedDescription)")
            presentSimpleAlert(on: viewController, title: "Purchase didn’t go through", message: error.localizedDescription)
        }
    }

    func restorePurchases(from viewController: UIViewController) async {
        Self.log("Restore purchases requested")
        do {
            try await AppStore.sync()
            Self.log("AppStore.sync completed")
            await refreshEntitlements(context: "restore")
            if ownsPremiumUnlock {
                Self.log("Restore found Brushi Premium")
                presentSimpleAlert(on: viewController, title: "Restored", message: "Brushi Premium is active on this device.")
            } else {
                Self.log("Restore found no Brushi Premium for this Apple ID")
                presentSimpleAlert(
                    on: viewController,
                    title: "No purchase found",
                    message: "We couldn’t find Brushi Premium for this Apple ID. Tap Unlock all if you haven’t purchased yet."
                )
            }
        } catch {
            Self.log("Restore failed — \(error.localizedDescription)")
            presentSimpleAlert(on: viewController, title: "Couldn’t restore", message: error.localizedDescription)
        }
    }

    private func checkVerified(_ result: VerificationResult<Transaction>) throws -> Transaction {
        switch result {
        case .unverified(_, let error):
            Self.log("Transaction verification failed — \(error.localizedDescription)")
            throw SubscriptionStoreError.failedVerification
        case .verified(let safe):
            return safe
        }
    }

    private func presentSimpleAlert(on viewController: UIViewController, title: String, message: String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default))
        viewController.present(alert, animated: true)
    }
}

private enum SubscriptionStoreError: Error {
    case failedVerification
}
