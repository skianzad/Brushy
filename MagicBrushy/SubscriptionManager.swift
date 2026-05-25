import Foundation
import StoreKit
import UIKit

extension Notification.Name {
    /// Posted on the main thread when premium purchase or legacy unlock state may have changed.
    static let magicBrushySubscriptionAccessDidChange = Notification.Name("MagicBrushy.subscriptionAccessDidChange")
}

/// StoreKit 2 gate for the one-time **non-consumable** premium unlock.
///
/// **Setup (required before App Store review):**
/// 1. App Store Connect → your app → **In-App Purchases** → **Non-Consumable** (not Consumable, not Subscription).
/// 2. Product ID must match `premiumProductID` exactly.
/// 3. Xcode → Signing & Capabilities → **In-App Purchase**.
/// 4. Local testing: `MagicBrushyProducts.storekit` is wired in the Run scheme.
@MainActor
final class SubscriptionManager {

    static let shared = SubscriptionManager()

    /// Legacy QA unlock (Debug builds only).
    static let legacyUnlockAllKey = "MagicBrushyUnlockAllCategories"

    /// Must match the non-consumable Product ID in App Store Connect exactly.
    static let premiumProductID = "Senscilab.MagicBrushy.premium"

    /// Pack IDs available without purchasing premium.
    static let freeTierPackIds: Set<String> = [BuiltInColoringPages.savedDrawingsPackId, "ocean", "dinosaurs"]

    /// Free tier: one saved blank-paper drawing; no delete until premium is owned.
    static let freeTierMaxSavedFreeDrawings = 1

    private(set) var ownsPremiumUnlock = false

    private var transactionUpdatesTask: Task<Void, Never>?
    private var didStartListening = false

    private init() {}

    /// Purchased premium or legacy QA unlock (Debug only).
    var hasFullLibraryAccess: Bool {
        #if DEBUG
        if UserDefaults.standard.bool(forKey: Self.legacyUnlockAllKey) { return true }
        #endif
        return ownsPremiumUnlock
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
        transactionUpdatesTask?.cancel()
        transactionUpdatesTask = Task { [weak self] in
            for await update in Transaction.updates {
                await self?.handle(transactionUpdate: update)
            }
        }
        Task { await refreshEntitlements() }
    }

    private func handle(transactionUpdate: VerificationResult<Transaction>) async {
        if case .verified(let transaction) = transactionUpdate, transaction.productID == Self.premiumProductID {
            await transaction.finish()
        }
        await refreshEntitlements()
    }

    func refreshEntitlements() async {
        var ownsPremium = false
        for await entitlement in Transaction.currentEntitlements {
            guard case .verified(let transaction) = entitlement else { continue }
            if transaction.productID == Self.premiumProductID {
                ownsPremium = true
                break
            }
        }
        if ownsPremium != ownsPremiumUnlock {
            ownsPremiumUnlock = ownsPremium
            NotificationCenter.default.post(name: .magicBrushySubscriptionAccessDidChange, object: nil)
        }
    }

    func purchase(from viewController: UIViewController) async {
        do {
            let products = try await Product.products(for: [Self.premiumProductID])
            guard let product = products.first else {
                #if DEBUG
                let testingHint = """

                Testing from Xcode?
                • Product → Scheme → Edit Scheme → Run → Options
                • Set StoreKit Configuration to MagicBrushyProducts.storekit
                • Stop the app, Run again (⌘R)

                Testing TestFlight or a device build without StoreKit?
                • App Store Connect → In-App Purchases → Non-Consumable
                • Product ID: \(Self.premiumProductID)
                • Wait up to an hour after creating it, then try again
                """
                #else
                let testingHint = """

                Ask a parent to try again later. If you already bought Brushi Premium, tap Restore purchases.
                """
                #endif
                presentSimpleAlert(
                    on: viewController,
                    title: "Store not ready",
                    message: "No product was returned for “\(Self.premiumProductID)”.\(testingHint)"
                )
                return
            }
            let result = try await product.purchase()
            switch result {
            case .success(let verification):
                let transaction = try checkVerified(verification)
                await transaction.finish()
                await refreshEntitlements()
            case .userCancelled:
                break
            case .pending:
                presentSimpleAlert(on: viewController, title: "Pending", message: "This purchase is waiting for approval (for example Ask to Buy).")
            @unknown default:
                break
            }
        } catch {
            presentSimpleAlert(on: viewController, title: "Purchase didn’t go through", message: error.localizedDescription)
        }
    }

    func restorePurchases(from viewController: UIViewController) async {
        do {
            try await AppStore.sync()
            await refreshEntitlements()
            if ownsPremiumUnlock {
                presentSimpleAlert(on: viewController, title: "Restored", message: "Brushi Premium is active on this device.")
            } else {
                presentSimpleAlert(
                    on: viewController,
                    title: "No purchase found",
                    message: "We couldn’t find Brushi Premium for this Apple ID. Tap Unlock all if you haven’t purchased yet."
                )
            }
        } catch {
            presentSimpleAlert(on: viewController, title: "Couldn’t restore", message: error.localizedDescription)
        }
    }

    private func checkVerified(_ result: VerificationResult<Transaction>) throws -> Transaction {
        switch result {
        case .unverified:
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
