import UIKit

/// “Color with Brushi” lockup — iPad uses Figma `122:1001`; iPhone uses `167:474`.
final class HomeBrushiTitleBadgeView: UIView {

    enum Metrics {
        /// iPad / regular width (`122:1001` export).
        static let regularDesignWidth: CGFloat = 402
        static let regularDesignHeight: CGFloat = 328
        /// iPhone (`167:474` export).
        static let phoneDesignWidth: CGFloat = 1163
        static let phoneDesignHeight: CGFloat = 443

        static func heightPerWidth(isPhone: Bool) -> CGFloat {
            isPhone
                ? phoneDesignHeight / phoneDesignWidth
                : regularDesignHeight / regularDesignWidth
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
