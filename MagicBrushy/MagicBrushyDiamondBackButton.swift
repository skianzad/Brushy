import UIKit

/// Orange diamond back control (matches category grid header).
final class MagicBrushyDiamondBackButton: UIView {

    private static let fillColor = UIColor(red: 1, green: 0.539, blue: 0.012, alpha: 1)
    private static let strokeColor = UIColor(red: 0.863, green: 0.404, blue: 0.153, alpha: 1)
    private static let strokeCornerRadius: CGFloat = 15.24
    private static let strokeBorderWidth: CGFloat = 5.03
    private static let shadowRadius: CGFloat = 7.27
    private static let shadowOffsetY: CGFloat = 7.27

    let button = UIButton(type: .custom)

    private let chrome = UIView()
    private let diamondRotator = UIView()
    private let stroke = UIView()
    private let fill = UIView()

    private var widthConstraint: NSLayoutConstraint!
    private var heightConstraint: NSLayoutConstraint!
    private var strokeWidthConstraint: NSLayoutConstraint!
    private var strokeHeightConstraint: NSLayoutConstraint!
    private var fillWidthConstraint: NSLayoutConstraint!
    private var fillHeightConstraint: NSLayoutConstraint!

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
        chrome.layer.shadowRadius = Self.shadowRadius
        chrome.layer.shadowOffset = CGSize(width: 0, height: Self.shadowOffsetY)
        chrome.layer.masksToBounds = false

        diamondRotator.translatesAutoresizingMaskIntoConstraints = false
        diamondRotator.backgroundColor = .clear
        diamondRotator.clipsToBounds = false
        diamondRotator.transform = CGAffineTransform(rotationAngle: .pi / 4)

        stroke.translatesAutoresizingMaskIntoConstraints = false
        stroke.backgroundColor = .clear
        stroke.layer.borderWidth = Self.strokeBorderWidth
        stroke.layer.borderColor = Self.strokeColor.cgColor
        stroke.layer.cornerRadius = Self.strokeCornerRadius
        stroke.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            stroke.layer.cornerCurve = .continuous
        }

        fill.translatesAutoresizingMaskIntoConstraints = false
        fill.backgroundColor = Self.fillColor
        fill.layer.cornerRadius = 12.73
        fill.clipsToBounds = true
        fill.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            fill.layer.cornerCurve = .continuous
        }

        button.translatesAutoresizingMaskIntoConstraints = false
        button.backgroundColor = .clear
        button.tintColor = .white
        button.transform = CGAffineTransform(rotationAngle: -.pi / 4)

        addSubview(chrome)
        chrome.addSubview(diamondRotator)
        diamondRotator.addSubview(stroke)
        diamondRotator.addSubview(fill)
        diamondRotator.addSubview(button)

        widthConstraint = widthAnchor.constraint(equalToConstant: 90.9)
        heightConstraint = heightAnchor.constraint(equalToConstant: 90.9)
        strokeWidthConstraint = stroke.widthAnchor.constraint(equalToConstant: 70)
        strokeHeightConstraint = stroke.heightAnchor.constraint(equalToConstant: 70)
        fillWidthConstraint = fill.widthAnchor.constraint(equalToConstant: 64)
        fillHeightConstraint = fill.heightAnchor.constraint(equalToConstant: 64)

        NSLayoutConstraint.activate([
            widthConstraint,
            heightConstraint,

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
            strokeWidthConstraint,
            strokeHeightConstraint,

            fill.centerXAnchor.constraint(equalTo: diamondRotator.centerXAnchor),
            fill.centerYAnchor.constraint(equalTo: diamondRotator.centerYAnchor),
            fillWidthConstraint,
            fillHeightConstraint,

            button.centerXAnchor.constraint(equalTo: fill.centerXAnchor),
            button.centerYAnchor.constraint(equalTo: fill.centerYAnchor),
            button.widthAnchor.constraint(equalTo: fill.widthAnchor),
            button.heightAnchor.constraint(equalTo: fill.heightAnchor),
        ])
    }

    func applyLayout(for traitCollection: UITraitCollection) {
        let side = MagicBrushyChromeMetrics.diamondBackSide(traitCollection)
        let square = MagicBrushyChromeMetrics.diamondSquareSide(for: side)
        let corner = MagicBrushyChromeMetrics.isPhone(traitCollection) ? 9.0 : 12.73
        widthConstraint.constant = side
        heightConstraint.constant = side
        strokeWidthConstraint.constant = square + MagicBrushyChromeMetrics.diamondStrokeSizeDelta
        strokeHeightConstraint.constant = square + MagicBrushyChromeMetrics.diamondStrokeSizeDelta
        fillWidthConstraint.constant = square
        fillHeightConstraint.constant = square
        fill.layer.cornerRadius = corner
        let chevron = UIImage(
            systemName: "chevron.left",
            withConfiguration: UIImage.SymbolConfiguration(
                pointSize: MagicBrushyChromeMetrics.diamondChevronPointSize(traitCollection),
                weight: .bold
            )
        )
        button.setImage(chevron, for: .normal)
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        let b = chrome.bounds
        guard b.width > 1, b.height > 1 else { return }
        chrome.layer.shadowPath = UIBezierPath(
            roundedRect: b,
            cornerRadius: fill.layer.cornerRadius
        ).cgPath
    }

    func addTarget(_ target: Any?, action: Selector, for controlEvents: UIControl.Event) {
        button.addTarget(target, action: action, for: controlEvents)
    }
}
