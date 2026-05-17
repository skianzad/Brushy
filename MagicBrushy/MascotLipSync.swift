import UIKit

/// Mascot art with a soft alpha falloff at the edges so harsh export fringes don’t pop on lip-sync swaps.
final class MascotSoftEdgeImageView: UIImageView {

    /// Fraction of width faded on each left/right edge.
    var horizontalEdgeFadeFraction: CGFloat = 0.10
    /// Fraction of height faded on each top/bottom edge.
    var verticalEdgeFadeFraction: CGFloat = 0.07

    private let edgeMaskLayer = CALayer()
    private var cachedMaskPixelSize: CGSize = .zero

    convenience init() {
        self.init(frame: .zero)
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
        installEdgeMask()
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        installEdgeMask()
    }

    private func installEdgeMask() {
        layer.mask = edgeMaskLayer
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        updateEdgeMaskIfNeeded()
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        guard previousTraitCollection?.displayScale != traitCollection.displayScale else { return }
        cachedMaskPixelSize = .zero
        setNeedsLayout()
    }

    private func updateEdgeMaskIfNeeded() {
        let size = bounds.size
        guard size.width > 1, size.height > 1 else { return }
        let scale = window?.screen.scale ?? traitCollection.displayScale
        let pixelSize = CGSize(width: size.width * scale, height: size.height * scale)
        edgeMaskLayer.frame = bounds
        guard pixelSize != cachedMaskPixelSize || edgeMaskLayer.contents == nil else { return }
        cachedMaskPixelSize = pixelSize
        edgeMaskLayer.contentsScale = scale
        edgeMaskLayer.contents = Self.makeEdgeFadeMask(
            pixelSize: pixelSize,
            horizontalFade: horizontalEdgeFadeFraction,
            verticalFade: verticalEdgeFadeFraction
        )
    }

    private static func smoothstep(_ edge0: CGFloat, _ edge1: CGFloat, _ x: CGFloat) -> CGFloat {
        guard edge1 > edge0 else { return x >= edge1 ? 1 : 0 }
        let t = max(0, min(1, (x - edge0) / (edge1 - edge0)))
        return t * t * (3 - 2 * t)
    }

    private static func makeEdgeFadeMask(
        pixelSize: CGSize,
        horizontalFade: CGFloat,
        verticalFade: CGFloat
    ) -> CGImage? {
        let w = max(1, Int(pixelSize.width.rounded(.up)))
        let h = max(1, Int(pixelSize.height.rounded(.up)))
        let fadeX = max(1, horizontalFade * CGFloat(w))
        let fadeY = max(1, verticalFade * CGFloat(h))
        var pixels = [UInt8](repeating: 0, count: w * h)
        for y in 0..<h {
            let fy = min(
                smoothstep(0, fadeY, CGFloat(y)),
                smoothstep(0, fadeY, CGFloat(h - 1 - y))
            )
            for x in 0..<w {
                let fx = min(
                    smoothstep(0, fadeX, CGFloat(x)),
                    smoothstep(0, fadeX, CGFloat(w - 1 - x))
                )
                pixels[y * w + x] = UInt8(min(255, max(0, fx * fy * 255)))
            }
        }
        guard let provider = CGDataProvider(data: Data(pixels) as CFData) else { return nil }
        return CGImage(
            width: w,
            height: h,
            bitsPerComponent: 8,
            bitsPerPixel: 8,
            bytesPerRow: w,
            space: CGColorSpaceCreateDeviceGray(),
            bitmapInfo: CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue),
            provider: provider,
            decode: nil,
            shouldInterpolate: true,
            intent: .defaultIntent
        )
    }
}

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
    /// Mouth timeline lags wall clock so we stay closer to **heard** audio after `play()` (DAC / route / small buffer delay).
    private static let sherpaHeardAudioLeadInSeconds: TimeInterval = 0.05
    /// Short cross-fade between mouth frames — softens hard export edges when paired with `MascotSoftEdgeImageView`.
    private static let mouthCrossfadeDuration: TimeInterval = 0.07

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
        sherpaFire()
    }

    func startAppleDrivenLipSync() {
        stopTimer()
        restoreImage = imageView?.image
        mouthFlipPhase = 0
        lastAppleMouthToggle = 0
    }

    private func sherpaFire() {
        let rawElapsed = CACurrentMediaTime() - sherpaStart
        let lipElapsed = max(0, rawElapsed - Self.sherpaHeardAudioLeadInSeconds)
        mouthFlipPhase &+= 1
        if lipElapsed > sherpaDuration + 0.08 {
            stopTimer()
            return
        }
        let n = max(1, sherpaGlyphs.count)
        let progress = min(1, lipElapsed / sherpaDuration)
        let idx = min(n - 1, max(0, Int(progress * Double(n))))
        let ch = sherpaGlyphs[idx]
        applyMouth(for: ch)
    }

    /// Apple `AVSpeechSynthesizer` path: often one word per callback.
    func appleWillSpeak(substring: String) {
        if substring.unicodeScalars.contains(where: { $0 == "o" || $0 == "O" }) {
            setMouthImage(mouthO)
            return
        }
        if substring.contains(where: { $0.isLetter || $0.isNumber }) {
            let now = CACurrentMediaTime()
            if now - lastAppleMouthToggle >= Self.appleMouthToggleInterval {
                lastAppleMouthToggle = now
                mouthFlipPhase &+= 1
            }
            setMouthImage((mouthFlipPhase & 1 == 0) ? mouthClosed : mouthOpen)
        } else {
            setMouthImage(mouthClosed)
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
            setMouthImage(mouthO)
            return
        }
        if ch.isLetter || ch.isNumber {
            setMouthImage((mouthFlipPhase & 1 == 0) ? mouthClosed : mouthOpen)
        } else {
            setMouthImage(mouthClosed)
        }
    }

    private func setMouthImage(_ image: UIImage?) {
        guard let iv = imageView else { return }
        guard let image else {
            iv.image = nil
            return
        }
        if iv.image === image { return }
        UIView.transition(with: iv, duration: Self.mouthCrossfadeDuration, options: .transitionCrossDissolve) {
            iv.image = image
        }
    }
}
