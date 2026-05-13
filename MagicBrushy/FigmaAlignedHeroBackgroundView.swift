import UIKit

/// Full-screen hero matching Figma export: 1366×2047 artboard, top offset −544, slight `CALayer` transform.
final class FigmaAlignedHeroBackgroundView: UIView {

    private let stage = UIView()
    private let imageLayer = CALayer()

    private static let designWidth: CGFloat = 1366
    private static let designHeight: CGFloat = 2047
    private static let designTopInset: CGFloat = -544

    private var stageTopConstraint: NSLayoutConstraint!

    var heroImage: UIImage? {
        didSet {
            guard let img = heroImage else {
                imageLayer.contents = nil
                return
            }
            imageLayer.contents = img.cgImage
            imageLayer.contentsScale = img.scale
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

        imageLayer.contentsGravity = .resize
        stage.layer.addSublayer(imageLayer)

        stageTopConstraint = stage.topAnchor.constraint(equalTo: topAnchor, constant: 0)
        NSLayoutConstraint.activate([
            stage.leadingAnchor.constraint(equalTo: leadingAnchor),
            stage.trailingAnchor.constraint(equalTo: trailingAnchor),
            stage.widthAnchor.constraint(equalTo: widthAnchor),
            stage.heightAnchor.constraint(equalTo: stage.widthAnchor, multiplier: Self.designHeight / Self.designWidth),
            stageTopConstraint,
        ])
    }

    override func layoutSubviews() {
        let w = bounds.width
        if w > 0.5 {
            stageTopConstraint.constant = (Self.designTopInset / Self.designWidth) * w
        }
        super.layoutSubviews()

        let b = stage.bounds
        CATransaction.begin()
        CATransaction.setDisableActions(true)
        imageLayer.bounds = CGRect(origin: .zero, size: b.size)
        imageLayer.position = CGPoint(x: b.midX, y: b.midY)
        imageLayer.transform = CATransform3DMakeAffineTransform(
            CGAffineTransform(a: 1.06, b: 0, c: 0, d: 1, tx: -0.06, ty: 0)
        )
        CATransaction.commit()
    }
}
