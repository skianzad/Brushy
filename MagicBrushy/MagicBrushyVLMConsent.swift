import Foundation

/// Parent/guardian opt-in before the one-time on-device Intelligence (VLM coach) download.
enum MagicBrushyVLMConsent {

    private static let declinedKey = "magicBrushy.vlmDownloadDeclined"
    private static let acceptedKey = "magicBrushy.vlmDownloadAccepted"

    static var userDeclinedDownload: Bool {
        UserDefaults.standard.bool(forKey: declinedKey)
    }

    static var userAcceptedDownload: Bool {
        UserDefaults.standard.bool(forKey: acceptedKey)
    }

    static func markDeclined() {
        UserDefaults.standard.set(true, forKey: declinedKey)
        UserDefaults.standard.set(false, forKey: acceptedKey)
    }

    static func markAccepted() {
        UserDefaults.standard.set(false, forKey: declinedKey)
        UserDefaults.standard.set(true, forKey: acceptedKey)
    }

    /// First-launch prompt before any registry download (skipped when weights are already cached).
    @MainActor
    static func shouldShowDownloadPrompt() -> Bool {
        #if targetEnvironment(simulator)
        return false
        #else
        if userDeclinedDownload || userAcceptedDownload { return false }
        return !LeapVLMModel.isModelBundleAvailableOnDevice
        #endif
    }

    /// Approximate combined download size of LFM2.5-VL-1.6B-Q4_0 + mmproj-Q8_0 (≈664 MB + 556 MB).
    static let downloadSizeString = "approx. 1.2 GB"

    static let downloadPromptTitle = "Download Brushi Intelligence?"

    static let downloadPromptMessage = """
    Get spoken tips while your child colors. Intelligence runs fully on this device—no chat costs, no cloud, and drawings stay private.

    One-time download: \(downloadSizeString). Wi-Fi recommended.
    """

    static let parentalGateDownloadPrefix = "This downloads Brushi Intelligence (\(downloadSizeString)) onto this device. Ask a parent or guardian."
}
