import UIKit

/// Orange diamond back control (matches `CategoryGridViewController` header).
final class MagicBrushyDiamondBackButton: UIView {

    enum Metrics {
        static let size: CGFloat = 90.9
        static var diamondSquareSide: CGFloat { size / 2.0.squareRoot() }
        static let fillCornerRadius: CGFloat = 12.73
        static let strokeOutset: CGFloat = 2.52
        static var strokeSizeDelta: CGFloat { strokeOutset * 2 }
        static let strokeCornerRadius: CGFloat = 15.24
        static let strokeBorderWidth: CGFloat = 5.03
        static let fillColor = UIColor(red: 1, green: 0.539, blue: 0.012, alpha: 1)
        static let strokeColor = UIColor(red: 0.863, green: 0.404, blue: 0.153, alpha: 1)
        static let shadowRadius: CGFloat = 7.27
        static let shadowOffsetY: CGFloat = 7.27
    }

    let button = UIButton(type: .custom)

    private let chrome = UIView()
    private let diamondRotator = UIView()
    private let stroke = UIView()
    private let fill = UIView()

    override init(frame: CGRect) {
        super.init(frame: frame)
        commonInit()
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        commonInit()
    }

    private func commonInit() {
        translatesAutoresizingMaskIntoConstraints = false
        clipsToBounds = false
        isAccessibilityElement = true
        accessibilityTraits = .button
        accessibilityLabel = "Back"

        chrome.translatesAutoresizingMaskIntoConstraints = false
        chrome.backgroundColor = .clear
        chrome.clipsToBounds = false
        chrome.layer.shadowColor = UIColor(red: 0, green: 0, blue: 0, alpha: 0.25).cgColor
        chrome.layer.shadowOpacity = 1
        chrome.layer.shadowRadius = Metrics.shadowRadius
        chrome.layer.shadowOffset = CGSize(width: 0, height: Metrics.shadowOffsetY)
        chrome.layer.masksToBounds = false

        diamondRotator.translatesAutoresizingMaskIntoConstraints = false
        diamondRotator.backgroundColor = .clear
        diamondRotator.clipsToBounds = false
        diamondRotator.transform = CGAffineTransform(rotationAngle: .pi / 4)

        stroke.translatesAutoresizingMaskIntoConstraints = false
        stroke.backgroundColor = .clear
        stroke.layer.borderWidth = Metrics.strokeBorderWidth
        stroke.layer.borderColor = Metrics.strokeColor.cgColor
        stroke.layer.cornerRadius = Metrics.strokeCornerRadius
        stroke.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            stroke.layer.cornerCurve = .continuous
        }

        fill.translatesAutoresizingMaskIntoConstraints = false
        fill.backgroundColor = Metrics.fillColor
        fill.layer.cornerRadius = Metrics.fillCornerRadius
        fill.clipsToBounds = true
        fill.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            fill.layer.cornerCurve = .continuous
        }

        button.translatesAutoresizingMaskIntoConstraints = false
        button.backgroundColor = .clear
        button.tintColor = .white
        let chevron = UIImage(
            systemName: "chevron.left",
            withConfiguration: UIImage.SymbolConfiguration(pointSize: 26, weight: .bold)
        )
        button.setImage(chevron, for: .normal)
        button.transform = CGAffineTransform(rotationAngle: -.pi / 4)

        addSubview(chrome)
        chrome.addSubview(diamondRotator)
        diamondRotator.addSubview(stroke)
        diamondRotator.addSubview(fill)
        diamondRotator.addSubview(button)

        NSLayoutConstraint.activate([
            widthAnchor.constraint(equalToConstant: Metrics.size),
            heightAnchor.constraint(equalToConstant: Metrics.size),

            chrome.topAnchor.constraint(equalTo: topAnchor),
            chrome.leadingAnchor.constraint(equalTo: leadingAnchor),
            chrome.trailingAnchor.constraint(equalTo: trailingAnchor),
            chrome.bottomAnchor.constraint(equalTo: bottomAnchor),

            diamondRotator.topAnchor.constraint(equalTo: chrome.topAnchor),
            diamondRotator.leadingAnchor.constraint(equalTo: chrome.leadingAnchor),
            diamondRotator.trailingAnchor.constraint(equalTo: chrome.trailingAnchor),
            diamondRotator.bottomAnchor.constraint(equalTo: chrome.bottomAnchor),

            stroke.centerXAnchor.constraint(equalTo: diamondRotator.centerXAnchor),
            stroke.centerYAnchor.constraint(equalTo: diamondRotator.centerYAnchor),
            stroke.widthAnchor.constraint(equalToConstant: Metrics.diamondSquareSide + Metrics.strokeSizeDelta),
            stroke.heightAnchor.constraint(equalToConstant: Metrics.diamondSquareSide + Metrics.strokeSizeDelta),

            fill.centerXAnchor.constraint(equalTo: diamondRotator.centerXAnchor),
            fill.centerYAnchor.constraint(equalTo: diamondRotator.centerYAnchor),
            fill.widthAnchor.constraint(equalToConstant: Metrics.diamondSquareSide),
            fill.heightAnchor.constraint(equalToConstant: Metrics.diamondSquareSide),

            button.centerXAnchor.constraint(equalTo: fill.centerXAnchor),
            button.centerYAnchor.constraint(equalTo: fill.centerYAnchor),
            button.widthAnchor.constraint(equalTo: fill.widthAnchor),
            button.heightAnchor.constraint(equalTo: fill.heightAnchor),
        ])
    }

    func addTarget(_ target: Any?, action: Selector, for controlEvents: UIControl.Event) {
        button.addTarget(target, action: action, for: controlEvents)
    }
}
