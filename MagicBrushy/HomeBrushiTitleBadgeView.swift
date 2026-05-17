import UIKit

/// Transparent “Color with Brushi” lockup from Figma `122:1000` / `122:1001`.
final class HomeBrushiTitleBadgeView: UIView {

    enum Metrics {
        /// Exported PNG (`402×328`, RGBA).
        static let designWidth: CGFloat = 402
        static let designHeight: CGFloat = 328
        static var heightPerWidth: CGFloat { designHeight / designWidth }
    }

    private let artImageView = UIImageView()

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
        translatesAutoresizingMaskIntoConstraints = false
        isUserInteractionEnabled = false
        backgroundColor = .clear

        artImageView.translatesAutoresizingMaskIntoConstraints = false
        artImageView.contentMode = .scaleAspectFit
        artImageView.backgroundColor = .clear
        artImageView.image = UIImage(named: "HomeColorWithBrushi")

        addSubview(artImageView)

        NSLayoutConstraint.activate([
            artImageView.leadingAnchor.constraint(equalTo: leadingAnchor),
            artImageView.trailingAnchor.constraint(equalTo: trailingAnchor),
            artImageView.topAnchor.constraint(equalTo: topAnchor),
            artImageView.bottomAnchor.constraint(equalTo: bottomAnchor),
        ])
    }
}
