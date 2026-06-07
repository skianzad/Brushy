import UIKit

/// App Store Kids Category (ages 4–6) helpers: parental gate, legal links, subscription disclosure.
enum MagicBrushyLegal {

    /// Must match the Privacy Policy URL in App Store Connect.
    static let privacyPolicyURL = URL(string: "https://senscilab.com/brushi/privacy")!

    /// Must match the Terms of Use (EULA) URL in App Store Connect.
    static let termsOfUseURL = URL(string: "https://senscilab.com/brushi/terms")!

    static let freeTierSummary = "Ocean, Animals, and Free Draw stay free."

    static var premiumPurchaseDisclosure: String {
        """
        Brushi Premium is a one-time purchase through your Apple ID. \
        It unlocks every category on this Apple ID and can be restored with Restore purchases. \
        Ocean, Animals, and Free Draw stay free.
        """
    }
}

enum MagicBrushyParentalGate {

    /// Simple adult verification before purchases, restore, or leaving the app (Kids Category).
    static func perform(
        from viewController: UIViewController,
        title: String = "Grown-ups only",
        messagePrefix: String = "Please ask a parent or guardian.",
        onPassed: @escaping () -> Void,
        onCancelled: (() -> Void)? = nil
    ) {
        let a = Int.random(in: 11...24)
        let b = Int.random(in: 11...24)
        let expected = a + b
        let alert = UIAlertController(
            title: title,
            message: "\(messagePrefix) What is \(a) + \(b)?",
            preferredStyle: .alert
        )
        alert.addTextField { field in
            field.keyboardType = .numberPad
            field.accessibilityLabel = "Answer"
        }
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel) { _ in
            onCancelled?()
        })
        alert.addAction(UIAlertAction(title: "Continue", style: .default) { _ in
            guard let raw = alert.textFields?.first?.text?.trimmingCharacters(in: .whitespacesAndNewlines),
                  let answer = Int(raw),
                  answer == expected
            else {
                UIImpactFeedbackGenerator(style: .rigid).impactOccurred()
                return
            }
            onPassed()
        })
        viewController.present(alert, animated: true)
    }

    static func openExternalURL(_ url: URL, from viewController: UIViewController) {
        perform(
            from: viewController,
            title: "Leave Brushi?",
            messagePrefix: "This opens a website. Ask a parent or guardian."
        ) {
            UIApplication.shared.open(url)
        }
    }

    static func openSystemSettings(from viewController: UIViewController) {
        guard let url = URL(string: UIApplication.openSettingsURLString) else { return }
        perform(
            from: viewController,
            title: "Grown-ups only",
            messagePrefix: "This opens the device Settings app. Ask a parent or guardian."
        ) {
            UIApplication.shared.open(url)
        }
    }
}

extension SubscriptionManager {

    func presentFullLibraryUnlock(
        from viewController: UIViewController,
        popoverSourceView: UIView?,
        popoverSourceRect: CGRect? = nil
    ) {
        let alreadyOwned = hasFullLibraryAccess
        let title = alreadyOwned ? "Brushi Premium" : "Full library"
        let message: String
        if alreadyOwned {
            message = """
            All coloring categories are unlocked. \(MagicBrushyLegal.freeTierSummary)

            On a new device, ask a parent or guardian to use Restore purchases with the same Apple ID.
            """
        } else {
            message = """
            Ask a parent or guardian to unlock every coloring category. \(MagicBrushyLegal.freeTierSummary)

            \(MagicBrushyLegal.premiumPurchaseDisclosure)
            """
        }
        let sheet = UIAlertController(title: title, message: message, preferredStyle: .actionSheet)

        if !alreadyOwned {
            sheet.addAction(UIAlertAction(title: "Buy Brushi Premium", style: .default) { _ in
                MagicBrushyParentalGate.perform(from: viewController) {
                    Task { await self.purchase(from: viewController) }
                }
            })
        }
        sheet.addAction(UIAlertAction(title: "Restore purchases", style: .default) { _ in
            MagicBrushyParentalGate.perform(from: viewController) {
                Task { await self.restorePurchases(from: viewController) }
            }
        })
        addLegalActions(to: sheet, from: viewController)
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))

        if let pop = sheet.popoverPresentationController {
            pop.sourceView = popoverSourceView ?? viewController.view
            pop.sourceRect = popoverSourceRect ?? popoverSourceView?.bounds
                ?? CGRect(x: viewController.view.bounds.midX, y: viewController.view.bounds.midY, width: 1, height: 1)
        }
        viewController.present(sheet, animated: true)
    }

    func presentPremiumUpsell(
        from viewController: UIViewController,
        title: String,
        message: String,
        popoverSourceView: UIView? = nil
    ) {
        let fullMessage = """
        \(message)

        \(MagicBrushyLegal.premiumPurchaseDisclosure)
        """
        let sheet = UIAlertController(title: title, message: fullMessage, preferredStyle: .actionSheet)
        sheet.addAction(UIAlertAction(title: "Buy Brushi Premium", style: .default) { _ in
            MagicBrushyParentalGate.perform(from: viewController) {
                Task { await self.purchase(from: viewController) }
            }
        })
        sheet.addAction(UIAlertAction(title: "Restore purchases", style: .default) { _ in
            MagicBrushyParentalGate.perform(from: viewController) {
                Task { await self.restorePurchases(from: viewController) }
            }
        })
        addLegalActions(to: sheet, from: viewController)
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        if let pop = sheet.popoverPresentationController {
            pop.sourceView = popoverSourceView ?? viewController.view
            pop.sourceRect = popoverSourceView?.bounds
                ?? CGRect(x: viewController.view.bounds.midX, y: viewController.view.bounds.midY, width: 1, height: 1)
        }
        viewController.present(sheet, animated: true)
    }

    private func addLegalActions(to sheet: UIAlertController, from viewController: UIViewController) {
        sheet.addAction(UIAlertAction(title: "Privacy Policy", style: .default) { _ in
            MagicBrushyParentalGate.openExternalURL(MagicBrushyLegal.privacyPolicyURL, from: viewController)
        })
        sheet.addAction(UIAlertAction(title: "Terms of Use", style: .default) { _ in
            MagicBrushyParentalGate.openExternalURL(MagicBrushyLegal.termsOfUseURL, from: viewController)
        })
    }
}
