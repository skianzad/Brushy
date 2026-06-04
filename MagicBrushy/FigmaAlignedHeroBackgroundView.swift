import UIKit

/// Full-screen hero from Figma: iPad portrait artboard (1366×2047, top offset −544) or iPhone landscape (`167:11`).
final class FigmaAlignedHeroBackgroundView: UIView {

    private let stage = UIView()
    private let imageLayer = CALayer()

    private static let tabletDesignWidth: CGFloat = 1366
    private static let tabletDesignHeight: CGFloat = 2047
    private static let tabletDesignTopInset: CGFloat = -544

    /// Figma iPhone `image 1` — 2162×1002 landscape.
    private static let phoneDesignWidth: CGFloat = 2162
    private static let phoneDesignHeight: CGFloat = 1002

    private var stageTopConstraint: NSLayoutConstraint!
    private var stageHeightMultiplier: NSLayoutConstraint!
    private var usesPhoneLandscapeLayout = false

    var heroImage: UIImage? {
        didSet {
            guard let img = heroImage else {
                imageLayer.contents = nil
                return
            }
            imageLayer.contents = img.cgImage
            imageLayer.contentsScale = img.scale
            applyLayoutProfile(for: img)
        }
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
        backgroundColor = .black

        stage.translatesAutoresizingMaskIntoConstraints = false
        stage.clipsToBounds = false
        addSubview(stage)

        imageLayer.contentsGravity = .resizeAspectFill
        stage.layer.addSublayer(imageLayer)

        stageTopConstraint = stage.topAnchor.constraint(equalTo: topAnchor, constant: 0)
        stageHeightMultiplier = stage.heightAnchor.constraint(
            equalTo: stage.widthAnchor,
            multiplier: Self.tabletDesignHeight / Self.tabletDesignWidth
        )
        NSLayoutConstraint.activate([
            stage.leadingAnchor.constraint(equalTo: leadingAnchor),
            stage.trailingAnchor.constraint(equalTo: trailingAnchor),
            stage.widthAnchor.constraint(equalTo: widthAnchor),
            stageHeightMultiplier,
            stageTopConstraint,
        ])
    }

    private func applyLayoutProfile(for image: UIImage) {
        let phone = image.size.width > image.size.height * 1.12
        usesPhoneLandscapeLayout = phone
        stageHeightMultiplier.isActive = false
        stageHeightMultiplier = stage.heightAnchor.constraint(
            equalTo: stage.widthAnchor,
            multiplier: phone
                ? Self.phoneDesignHeight / Self.phoneDesignWidth
                : Self.tabletDesignHeight / Self.tabletDesignWidth
        )
        stageHeightMultiplier.isActive = true
        setNeedsLayout()
    }

    override func layoutSubviews() {
        let w = bounds.width
        if w > 0.5 {
            if usesPhoneLandscapeLayout {
                stageTopConstraint.constant = 0
            } else {
                stageTopConstraint.constant = (Self.tabletDesignTopInset / Self.tabletDesignWidth) * w
            }
        }
        super.layoutSubviews()

        let b = stage.bounds
        CATransaction.begin()
        CATransaction.setDisableActions(true)
        imageLayer.bounds = CGRect(origin: .zero, size: b.size)
        imageLayer.position = CGPoint(x: b.midX, y: b.midY)
        if usesPhoneLandscapeLayout {
            imageLayer.transform = CATransform3DIdentity
        } else {
            imageLayer.transform = CATransform3DMakeAffineTransform(
                CGAffineTransform(a: 1.06, b: 0, c: 0, d: 1, tx: -0.06, ty: 0)
            )
        }
        CATransaction.commit()
    }
}
