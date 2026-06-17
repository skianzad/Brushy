import UIKit

/// “Brushi Coloring Games for Kids” lockup on the home hub (phone + iPad).
final class HomeBrushiTitleBadgeView: UIView {

    enum Metrics {
        /// Shared export (`IMG_4220` — crayon/pencil + wordmark).
        static let designWidth: CGFloat = 1612
        static let designHeight: CGFloat = 692

        static func heightPerWidth(isPhone: Bool) -> CGFloat {
            designHeight / designWidth
        }

        static func assetName(isPhone: Bool) -> String {
            isPhone ? "HomeColorWithBrushiPhone" : "HomeColorWithBrushi"
        }
    }

    private let artImageView = UIImageView()
    private var aspectRatioConstraint: NSLayoutConstraint?

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

        addSubview(artImageView)

        NSLayoutConstraint.activate([
            artImageView.leadingAnchor.constraint(equalTo: leadingAnchor),
            artImageView.trailingAnchor.constraint(equalTo: trailingAnchor),
            artImageView.topAnchor.constraint(equalTo: topAnchor),
            artImageView.bottomAnchor.constraint(equalTo: bottomAnchor),
        ])
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        guard previousTraitCollection?.userInterfaceIdiom != traitCollection.userInterfaceIdiom else { return }
        applyStyle(for: traitCollection)
    }

    /// Updates artwork and aspect ratio for the current idiom (call after adding constraints).
    func applyStyle(for traitCollection: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        artImageView.image = UIImage(named: Metrics.assetName(isPhone: phone))
        aspectRatioConstraint?.isActive = false
        aspectRatioConstraint = heightAnchor.constraint(
            equalTo: widthAnchor,
            multiplier: Metrics.heightPerWidth(isPhone: phone)
        )
        aspectRatioConstraint?.priority = .required
        aspectRatioConstraint?.isActive = true
    }
}
