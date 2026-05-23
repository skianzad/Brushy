import UIKit

/// Pill progress bar from the Figma download screen (wood track + golden fill on wood).
final class BrushiFigmaDownloadProgressView: UIView {

    private static let woodImage = UIImage(named: "CategoryGridPanelWood")

    private let shellWoodImageView = UIImageView()
    private let trackContainer = UIView()
    private let trackWoodImageView = UIImageView()
    private let fillView = UIView()
    private let fillWoodImageView = UIImageView()
    private let fillGradient = CAGradientLayer()
    private var fillWidthConstraint: NSLayoutConstraint?
    private var displayedProgress: CGFloat = 0
    private var pendingAnimateAfterLayout = false

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
        clipsToBounds = true
        layer.borderWidth = 8
        layer.borderColor = FigmaTheme.bootstrapProgressBorder.cgColor
        backgroundColor = FigmaTheme.categoryPanelWoodFallback

        configureWoodImageView(shellWoodImageView)
        configureWoodImageView(trackWoodImageView)
        configureWoodImageView(fillWoodImageView)

        trackContainer.translatesAutoresizingMaskIntoConstraints = false
        trackContainer.backgroundColor = .clear
        trackContainer.clipsToBounds = true

        fillView.translatesAutoresizingMaskIntoConstraints = false
        fillView.clipsToBounds = true
        fillView.backgroundColor = .clear
        fillView.layer.zPosition = 1
        fillGradient.colors = [
            UIColor(red: 1, green: 0.78, blue: 0.05, alpha: 0.95).cgColor,
            UIColor(red: 1, green: 0.92, blue: 0.35, alpha: 0.9).cgColor,
        ]
        fillGradient.startPoint = CGPoint(x: 0, y: 0.5)
        fillGradient.endPoint = CGPoint(x: 1, y: 0.5)
        fillView.layer.addSublayer(fillGradient)

        addSubview(shellWoodImageView)
        addSubview(trackContainer)
        trackContainer.addSubview(trackWoodImageView)
        trackContainer.addSubview(fillView)
        fillView.addSubview(fillWoodImageView)
        trackContainer.bringSubviewToFront(fillView)

        fillWidthConstraint = fillView.widthAnchor.constraint(equalToConstant: 0)

        let inset: CGFloat = 8
        NSLayoutConstraint.activate([
            shellWoodImageView.topAnchor.constraint(equalTo: topAnchor),
            shellWoodImageView.leadingAnchor.constraint(equalTo: leadingAnchor),
            shellWoodImageView.trailingAnchor.constraint(equalTo: trailingAnchor),
            shellWoodImageView.bottomAnchor.constraint(equalTo: bottomAnchor),

            trackContainer.leadingAnchor.constraint(equalTo: leadingAnchor, constant: inset),
            trackContainer.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -inset),
            trackContainer.topAnchor.constraint(equalTo: topAnchor, constant: inset),
            trackContainer.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -inset),

            trackWoodImageView.topAnchor.constraint(equalTo: trackContainer.topAnchor),
            trackWoodImageView.leadingAnchor.constraint(equalTo: trackContainer.leadingAnchor),
            trackWoodImageView.trailingAnchor.constraint(equalTo: trackContainer.trailingAnchor),
            trackWoodImageView.bottomAnchor.constraint(equalTo: trackContainer.bottomAnchor),

            fillView.leadingAnchor.constraint(equalTo: trackContainer.leadingAnchor),
            fillView.topAnchor.constraint(equalTo: trackContainer.topAnchor),
            fillView.bottomAnchor.constraint(equalTo: trackContainer.bottomAnchor),
            fillWidthConstraint!,

            fillWoodImageView.topAnchor.constraint(equalTo: trackContainer.topAnchor),
            fillWoodImageView.bottomAnchor.constraint(equalTo: trackContainer.bottomAnchor),
            fillWoodImageView.leadingAnchor.constraint(equalTo: trackContainer.leadingAnchor),
            fillWoodImageView.widthAnchor.constraint(equalTo: trackContainer.widthAnchor),
        ])

        setProgress(0, animated: false)
    }

    private func configureWoodImageView(_ imageView: UIImageView) {
        imageView.translatesAutoresizingMaskIntoConstraints = false
        imageView.image = Self.woodImage
        imageView.contentMode = .scaleAspectFill
        imageView.clipsToBounds = true
        imageView.isUserInteractionEnabled = false
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        let r = bounds.height * 0.5
        layer.cornerRadius = r
        shellWoodImageView.layer.cornerRadius = r
        trackContainer.layer.cornerRadius = max(0, r - 8)
        fillView.layer.cornerRadius = max(0, r - 8)

        if trackContainer.bounds.width > 1 {
            let animate = pendingAnimateAfterLayout
            pendingAnimateAfterLayout = false
            applyFillWidth(animated: animate)
        }
        syncFillGradientFrame()
    }

    func setProgress(_ value: CGFloat, animated: Bool) {
        stopIndeterminateAnimation()
        displayedProgress = min(1, max(0, value))
        if trackContainer.bounds.width > 1 {
            applyFillWidth(animated: animated)
        } else {
            pendingAnimateAfterLayout = animated
            setNeedsLayout()
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

    private func applyFillWidth(animated: Bool) {
        let trackW = trackContainer.bounds.width
        guard trackW > 1 else { return }

        let clamped = displayedProgress
        let minFill: CGFloat = clamped > 0 ? 8 : 0
        let targetW = max(minFill, trackW * clamped)
        fillWidthConstraint?.constant = targetW

        let layoutFill = { [weak self] in
            guard let self else { return }
            self.trackContainer.layoutIfNeeded()
            self.syncFillGradientFrame()
        }

        if animated {
            UIView.animate(
                withDuration: 0.4,
                delay: 0,
                options: [.curveEaseInOut, .beginFromCurrentState, .allowUserInteraction],
                animations: layoutFill
            )
        } else {
            layoutFill()
        }
    }

    private func syncFillGradientFrame() {
        CATransaction.begin()
        CATransaction.setDisableActions(true)
        fillGradient.frame = fillView.bounds
        CATransaction.commit()
    }

    private func startIndeterminateAnimation() {
        stopIndeterminateAnimation()
        let anim = CABasicAnimation(keyPath: "opacity")
        anim.fromValue = 1
        anim.toValue = 0.55
        anim.duration = 0.85
        anim.autoreverses = true
        anim.repeatCount = .infinity
        anim.timingFunction = CAMediaTimingFunction(name: .easeInEaseOut)
        fillGradient.add(anim, forKey: "bootstrapPulse")
    }

    private func stopIndeterminateAnimation() {
        fillGradient.removeAnimation(forKey: "bootstrapPulse")
        fillGradient.opacity = 1
    }
}
