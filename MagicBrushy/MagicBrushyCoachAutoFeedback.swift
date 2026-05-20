import Foundation

/// Whether the painting coach speaks automatic tips while coloring.
enum MagicBrushyCoachAutoFeedback {
    static let didChangeNotification = Notification.Name("MagicBrushyCoachAutoFeedbackDidChange")

    private static let storageKey = "magicBrushy.coachAutoFeedbackEnabled"

    static var isEnabled: Bool {
        get {
            if UserDefaults.standard.object(forKey: storageKey) == nil { return true }
            return UserDefaults.standard.bool(forKey: storageKey)
        }
        set {
            let wasEnabled = UserDefaults.standard.object(forKey: storageKey) == nil
                ? true
                : UserDefaults.standard.bool(forKey: storageKey)
            guard wasEnabled != newValue else { return }
            UserDefaults.standard.set(newValue, forKey: storageKey)
            NotificationCenter.default.post(name: didChangeNotification, object: nil)
        }
    }
}
