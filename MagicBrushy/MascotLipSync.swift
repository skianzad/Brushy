import UIKit

/// Swaps the mascot `UIImageView` between closed / open / “O” mouths while Alba speaks.
@MainActor
final class MascotLipSyncDriver: NSObject {

    weak var imageView: UIImageView?
    var mouthClosed: UIImage?
    var mouthOpen: UIImage?
    var mouthO: UIImage?

    private var restoreImage: UIImage?
    private var lipTimer: Timer?
    private var sherpaGlyphs: [Character] = []
    private var sherpaDuration: TimeInterval = 0
    private var sherpaStart: CFTimeInterval = 0
    private var mouthFlipPhase: Int = 0
    private var lastAppleMouthToggle: CFTimeInterval = 0
    /// Minimum time between closed/open swaps (Apple TTS path) — slower = calmer mouth.
    private static let appleMouthToggleInterval: CFTimeInterval = 0.18
    /// Sherpa path: timer cadence for closed ↔ open (larger = slower).
    private static let sherpaLipTimerInterval: TimeInterval = 0.16

    func attach(imageView: UIImageView, closed: UIImage?, open: UIImage?, oMouth: UIImage?) {
        self.imageView = imageView
        mouthClosed = closed
        mouthOpen = open ?? closed
        mouthO = oMouth ?? open ?? closed
    }

    func startSherpaDrivenLipSync(text: String, duration: TimeInterval) {
        stopTimer()
        restoreImage = imageView?.image
        mouthFlipPhase = 0
        sherpaGlyphs = Array(text)
        sherpaDuration = max(0.05, duration)
        sherpaStart = CACurrentMediaTime()
        lipTimer = Timer(timeInterval: Self.sherpaLipTimerInterval, repeats: true) { [weak self] _ in
            self?.sherpaFire()
        }
        if let lipTimer {
            RunLoop.main.add(lipTimer, forMode: .common)
        }
    }

    func startAppleDrivenLipSync() {
        stopTimer()
        restoreImage = imageView?.image
        mouthFlipPhase = 0
        lastAppleMouthToggle = 0
    }

    private func sherpaFire() {
        let elapsed = CACurrentMediaTime() - sherpaStart
        mouthFlipPhase &+= 1
        if elapsed > sherpaDuration + 0.08 {
            stopTimer()
            return
        }
        let n = max(1, sherpaGlyphs.count)
        let progress = min(1, elapsed / sherpaDuration)
        let idx = min(n - 1, max(0, Int(progress * Double(n))))
        let ch = sherpaGlyphs[idx]
        applyMouth(for: ch)
    }

    /// Apple `AVSpeechSynthesizer` path: often one word per callback.
    func appleWillSpeak(substring: String) {
        if substring.unicodeScalars.contains(where: { $0 == "o" || $0 == "O" }) {
            imageView?.image = mouthO
            return
        }
        if substring.contains(where: { $0.isLetter || $0.isNumber }) {
            let now = CACurrentMediaTime()
            if now - lastAppleMouthToggle >= Self.appleMouthToggleInterval {
                lastAppleMouthToggle = now
                mouthFlipPhase &+= 1
            }
            imageView?.image = (mouthFlipPhase & 1 == 0) ? mouthClosed : mouthOpen
        } else {
            imageView?.image = mouthClosed
        }
    }

    func sessionEnded() {
        stopTimer()
        guard let restoreImage else { return }
        if let iv = imageView {
            UIView.transition(with: iv, duration: 0.12, options: .transitionCrossDissolve) {
                iv.image = restoreImage
            }
        }
        self.restoreImage = nil
        sherpaGlyphs = []
    }

    private func stopTimer() {
        lipTimer?.invalidate()
        lipTimer = nil
    }

    private func applyMouth(for ch: Character) {
        if ch == "o" || ch == "O" {
            imageView?.image = mouthO
            return
        }
        if ch.isLetter || ch.isNumber {
            imageView?.image = (mouthFlipPhase & 1 == 0) ? mouthClosed : mouthOpen
        } else {
            imageView?.image = mouthClosed
        }
    }
}
