import Foundation
import StoreKit
import UIKit

extension Notification.Name {
    /// Posted on the main thread when subscription or legacy unlock state may have changed.
    static let magicBrushySubscriptionAccessDidChange = Notification.Name("MagicBrushy.subscriptionAccessDidChange")
}

/// StoreKit 2 subscription gate. Wire the same product ID in App Store Connect (auto‑renewable subscription).
///
/// **Setup (required before App Store review):**
/// 1. In App Store Connect → your app → Subscriptions, create a subscription group and an auto‑renewable product whose **Product ID** matches `premiumProductID`.
/// 2. In Xcode → Signing & Capabilities → add **In-App Purchase**.
/// 3. For local testing, add a **StoreKit Configuration** file and assign it in the Run scheme.
@MainActor
final class SubscriptionManager {

    static let shared = SubscriptionManager()

    /// Same key as `HomeViewController` / legacy “unlock all” (kept for internal builds and migration).
    static let legacyUnlockAllKey = "MagicBrushyUnlockAllCategories"

    /// Must match the auto‑renewable subscription’s Product ID in App Store Connect exactly.
    static let premiumProductID = "Senscilab.MagicBrushy.premium"

    /// Pack IDs available without a subscription (first row on the home grid).
    static let freeTierPackIds: Set<String> = [BuiltInColoringPages.savedDrawingsPackId, "ocean", "animals"]

    private(set) var hasActiveSubscription = false

    private var transactionUpdatesTask: Task<Void, Never>?
    private var didStartListening = false

    private init() {}

    /// Legacy QA unlock or an active App Store subscription.
    var hasFullLibraryAccess: Bool {
        UserDefaults.standard.bool(forKey: Self.legacyUnlockAllKey) || hasActiveSubscription
    }

    func canOpenPack(id: String) -> Bool {
        Self.freeTierPackIds.contains(id) || hasFullLibraryAccess
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
        var subscribed = false
        for await entitlement in Transaction.currentEntitlements {
            guard case .verified(let transaction) = entitlement else { continue }
            if transaction.productID == Self.premiumProductID {
                subscribed = true
                break
            }
        }
        if subscribed != hasActiveSubscription {
            hasActiveSubscription = subscribed
            NotificationCenter.default.post(name: .magicBrushySubscriptionAccessDidChange, object: nil)
        }
    }

    func purchase(from viewController: UIViewController) async {
        do {
            let products = try await Product.products(for: [Self.premiumProductID])
            guard let product = products.first else {
                presentSimpleAlert(
                    on: viewController,
                    title: "Store not ready",
                    message: "No subscription product was returned for “\(Self.premiumProductID)”. Create this auto‑renewable subscription in App Store Connect and enable In‑App Purchase for the app target."
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
            if hasActiveSubscription {
                presentSimpleAlert(on: viewController, title: "Restored", message: "Your subscription is active on this device.")
            } else if UserDefaults.standard.bool(forKey: Self.legacyUnlockAllKey) {
                presentSimpleAlert(on: viewController, title: "Restored", message: "A previous unlock is still active on this device.")
            } else {
                presentSimpleAlert(
                    on: viewController,
                    title: "No subscription found",
                    message: "We couldn’t find an active subscription for this Apple ID. Tap Subscribe if you haven’t purchased yet."
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
