import UIKit

/// Pill progress bar from the Figma download screen (blue border, water track, yellow fill).
final class BrushiFigmaDownloadProgressView: UIView {

    private let trackContainer = UIView()
    private let waveOverlay = BrushiProgressWaveOverlayView()
    private let fillView = UIView()
    private let fillGradient = CAGradientLayer()
    private var fillWidthConstraint: NSLayoutConstraint?

    var progress: CGFloat = 0 {
        didSet { setProgress(progress, animated: true) }
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
        commonInit()
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        commonInit()
    }

    private func commonInit() {
        clipsToBounds = false
        layer.borderWidth = 8
        layer.borderColor = FigmaTheme.bootstrapProgressBorder.cgColor
        backgroundColor = .white

        trackContainer.translatesAutoresizingMaskIntoConstraints = false
        trackContainer.backgroundColor = FigmaTheme.bootstrapProgressTrack
        trackContainer.clipsToBounds = true

        waveOverlay.translatesAutoresizingMaskIntoConstraints = false
        waveOverlay.isUserInteractionEnabled = false

        fillView.translatesAutoresizingMaskIntoConstraints = false
        fillView.clipsToBounds = true
        fillGradient.colors = [
            UIColor(red: 1, green: 0.82, blue: 0.12, alpha: 1).cgColor,
            UIColor(red: 1, green: 0.96, blue: 0.72, alpha: 1).cgColor,
        ]
        fillGradient.startPoint = CGPoint(x: 0, y: 0.5)
        fillGradient.endPoint = CGPoint(x: 1, y: 0.5)
        fillView.layer.addSublayer(fillGradient)

        addSubview(trackContainer)
        trackContainer.addSubview(waveOverlay)
        trackContainer.addSubview(fillView)

        fillWidthConstraint = fillView.widthAnchor.constraint(equalTo: trackContainer.widthAnchor, multiplier: 0.01)

        let inset: CGFloat = 8
        NSLayoutConstraint.activate([
            trackContainer.leadingAnchor.constraint(equalTo: leadingAnchor, constant: inset),
            trackContainer.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -inset),
            trackContainer.topAnchor.constraint(equalTo: topAnchor, constant: inset),
            trackContainer.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -inset),

            waveOverlay.leadingAnchor.constraint(equalTo: trackContainer.leadingAnchor),
            waveOverlay.trailingAnchor.constraint(equalTo: trackContainer.trailingAnchor),
            waveOverlay.topAnchor.constraint(equalTo: trackContainer.topAnchor),
            waveOverlay.bottomAnchor.constraint(equalTo: trackContainer.bottomAnchor),

            fillView.leadingAnchor.constraint(equalTo: trackContainer.leadingAnchor),
            fillView.topAnchor.constraint(equalTo: trackContainer.topAnchor),
            fillView.bottomAnchor.constraint(equalTo: trackContainer.bottomAnchor),
            fillWidthConstraint!,
        ])

        setProgress(0, animated: false)
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        let r = bounds.height * 0.5
        layer.cornerRadius = r
        trackContainer.layer.cornerRadius = max(0, r - 8)
        fillView.layer.cornerRadius = max(0, r - 8)
        CATransaction.begin()
        CATransaction.setDisableActions(true)
        fillGradient.frame = fillView.bounds
        CATransaction.commit()
    }

    func setProgress(_ value: CGFloat, animated: Bool) {
        stopIndeterminateAnimation()
        let clamped = min(1, max(0, value))
        fillWidthConstraint?.isActive = false
        fillWidthConstraint = fillView.widthAnchor.constraint(
            equalTo: trackContainer.widthAnchor,
            multiplier: max(0.01, clamped)
        )
        fillWidthConstraint?.isActive = true
        if animated {
            UIView.animate(withDuration: 0.28, delay: 0, options: [.curveEaseOut, .allowUserInteraction]) {
                self.layoutIfNeeded()
            }
        } else {
            layoutIfNeeded()
        }
    }

    func setIndeterminateActive(_ active: Bool) {
        if active {
            setProgress(0.88, animated: true)
            startIndeterminateAnimation()
        } else {
            stopIndeterminateAnimation()
        }
    }

    private func startIndeterminateAnimation() {
        stopIndeterminateAnimation()
        let anim = CABasicAnimation(keyPath: "opacity")
        anim.fromValue = 1
        anim.toValue = 0.68
        anim.duration = 0.85
        anim.autoreverses = true
        anim.repeatCount = .infinity
        anim.timingFunction = CAMediaTimingFunction(name: .easeInEaseOut)
        fillView.layer.add(anim, forKey: "bootstrapPulse")
    }

    private func stopIndeterminateAnimation() {
        fillView.layer.removeAnimation(forKey: "bootstrapPulse")
        fillView.alpha = 1
    }
}

// MARK: - Wavy water texture inside the track

private final class BrushiProgressWaveOverlayView: UIView {

    override class var layerClass: AnyClass { CAShapeLayer.self }

    private var waveLayer: CAShapeLayer { layer as! CAShapeLayer }

    override init(frame: CGRect) {
        super.init(frame: frame)
        waveLayer.fillColor = UIColor(red: 0.22, green: 0.72, blue: 0.95, alpha: 0.35).cgColor
        isOpaque = false
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    override func layoutSubviews() {
        super.layoutSubviews()
        waveLayer.path = wavePath(in: bounds).cgPath
    }

    private func wavePath(in rect: CGRect) -> UIBezierPath {
        let path = UIBezierPath()
        let midY = rect.midY
        let amp = rect.height * 0.14
        let waveLen = max(rect.width / 4, 40)
        path.move(to: CGPoint(x: 0, y: midY))
        var x: CGFloat = 0
        while x <= rect.width + waveLen {
            let y = midY + sin((x / waveLen) * .pi * 2) * amp
            path.addLine(to: CGPoint(x: x, y: y))
            x += 4
        }
        path.addLine(to: CGPoint(x: rect.width, y: rect.height))
        path.addLine(to: CGPoint(x: 0, y: rect.height))
        path.close()
        return path
    }
}
