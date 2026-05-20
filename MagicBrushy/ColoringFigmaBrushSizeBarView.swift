import UIKit

/// Yellow pill brush-size strip with one tap target per stroke preset (Figma `122:233` style).
final class ColoringFigmaBrushSizeBarView: UIView {

    var dotCount: Int = 5 { 
        didSet {
            let clampedCount = max(1, dotCount)
            if clampedCount != dotCount { dotCount = clampedCount; return }
            guard dotCount != oldValue else { return }   // nothing changed — don't rebuild
            rebuildHitTargets()
            setSelectedIndex(_selectedIndex, notify: false)
            setNeedsDisplay()
        }
    }

    private var _selectedIndex: Int = 0

    var selectedIndex: Int {
        get { _selectedIndex }
        set { setSelectedIndex(newValue, notify: false) }
    }

    var onSelectionChanged: ((Int) -> Void)?

    /// Fill for size dots — should match the active crayon stroke color.
    var dotFillColor: UIColor = UIColor(red: 20 / 255, green: 102 / 255, blue: 1, alpha: 1) {
        didSet {
            guard dotFillColor != oldValue else { return }
            setNeedsDisplay()
        }
    }

    private var hitButtons: [UIButton] = []
    private var barWidthConstraint: NSLayoutConstraint?
    private var barHeightConstraint: NSLayoutConstraint?

    private static let pillFill = ColoringFigmaToolbarChrome.limeChromeFill
    private static let pillStroke = ColoringFigmaToolbarChrome.limeChromeBorder

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
        isUserInteractionEnabled = true
        clipsToBounds = false
        backgroundColor = .clear
        contentMode = .redraw

        barWidthConstraint = widthAnchor.constraint(equalToConstant: 280)
        barHeightConstraint = heightAnchor.constraint(equalToConstant: 55)
        NSLayoutConstraint.activate([barWidthConstraint!, barHeightConstraint!])

        layer.shadowColor = UIColor.black.cgColor
        layer.shadowOpacity = 0.25
        layer.shadowRadius = 3.6
        layer.shadowOffset = CGSize(width: 0, height: 7)

        rebuildHitTargets()
    }

    private func rebuildHitTargets() {
        hitButtons.forEach { $0.removeFromSuperview() }
        hitButtons.removeAll()

        for i in 0..<dotCount {
            let b = UIButton(type: .custom)
            b.tag = i
            // TAMRC must be true so manually-set frames in layoutSubviews are respected.
            b.translatesAutoresizingMaskIntoConstraints = true
            b.autoresizingMask = []
            b.backgroundColor = .clear
            b.isUserInteractionEnabled = true
            b.accessibilityLabel = "Brush size \(i + 1) of \(dotCount)"
            b.accessibilityHint = "Pick how thick your paint is"
            b.addTarget(self, action: #selector(dotTapped(_:)), for: .touchUpInside)
            addSubview(b)
            hitButtons.append(b)
        }
        setNeedsLayout()
        layoutIfNeeded()   // apply frames synchronously so buttons are hittable immediately
        updateSelectionHighlight()
    }

    private func setSelectedIndex(_ index: Int, notify: Bool) {
        let maxIndex = max(0, dotCount - 1)
        let clamped = min(max(0, index), maxIndex)
        guard clamped != _selectedIndex else { return }
        _selectedIndex = clamped
        updateSelectionHighlight()
        setNeedsDisplay()
        if notify {
            onSelectionChanged?(clamped)
        }
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        let w = bounds.width
        let h = bounds.height
        guard w > 1, h > 1, dotCount > 0 else { return }

        // Equal-width columns — each dot gets a non-overlapping tap zone.
        let segmentW = w / CGFloat(dotCount)
        for (i, b) in hitButtons.enumerated() {
            b.frame = CGRect(x: CGFloat(i) * segmentW, y: 0, width: segmentW, height: h)
        }
        updateSelectionHighlight()
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext(), dotCount > 0 else { return }

        let pill = bounds.insetBy(dx: 2, dy: 2)
        let pillPath = UIBezierPath(roundedRect: pill, cornerRadius: min(13, pill.height * 0.14))
        ctx.setFillColor(Self.pillFill.cgColor)
        ctx.addPath(pillPath.cgPath)
        ctx.fillPath()
        ctx.setStrokeColor(Self.pillStroke.cgColor)
        ctx.setLineWidth(5)
        ctx.addPath(pillPath.cgPath)
        ctx.strokePath()

        for i in 0..<dotCount {
            let center = dotCenter(in: bounds, index: i, count: dotCount)
            let r = dotRadius(in: bounds.height, index: i, count: dotCount)
            let selected = i == _selectedIndex

            let dotRect = CGRect(x: center.x - r, y: center.y - r, width: r * 2, height: r * 2)
            ctx.setFillColor(dotFillColor.cgColor)
            ctx.fillEllipse(in: dotRect)

            ctx.setStrokeColor(UIColor.black.cgColor)
            ctx.setLineWidth(selected ? 4 : 3)
            ctx.strokeEllipse(in: dotRect.insetBy(dx: 1.5, dy: 1.5))

            if selected {
                ctx.setStrokeColor(UIColor.white.cgColor)
                ctx.setLineWidth(4)
                ctx.strokeEllipse(in: dotRect.insetBy(dx: -1, dy: -1))
            }
        }
    }

    private func dotCenter(in bounds: CGRect, index: Int, count: Int) -> CGPoint {
        let insetX = bounds.width * 0.13
        let usable = max(1, bounds.width - insetX * 2)
        let fraction: CGFloat
        if count <= 1 {
            fraction = 0.5
        } else {
            fraction = CGFloat(index) / CGFloat(count - 1)
        }
        return CGPoint(x: bounds.minX + insetX + usable * fraction, y: bounds.midY)
    }

    private func dotRadius(in height: CGFloat, index: Int, count: Int) -> CGFloat {
        let minR = height * 0.18
        let maxR = height * 0.34
        guard count > 1 else { return (minR + maxR) * 0.5 }
        let t = CGFloat(index) / CGFloat(count - 1)
        return minR + (maxR - minR) * t
    }

    func applyChromeMetrics(barWidth: CGFloat, barHeight: CGFloat) {
        barWidthConstraint?.constant = barWidth
        barHeightConstraint?.constant = barHeight
    }

    @objc private func dotTapped(_ sender: UIButton) {
        let index = sender.tag
        guard index >= 0, index < dotCount else { return }
        guard index != _selectedIndex else { return }
        setSelectedIndex(index, notify: true)
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }

    private func updateSelectionHighlight() {
        for (i, b) in hitButtons.enumerated() {
            let on = i == _selectedIndex
            b.transform = on ? CGAffineTransform(scaleX: 1.04, y: 1.04) : .identity
            b.accessibilityTraits = on ? [.button, .selected] : .button
        }
    }
}

enum ColoringFigmaToolbarChrome {

    /// Figma brush-size bar + undo chrome fill (`rgb 0.765, 0.937, 0.235`).
    static let limeChromeFill = UIColor(red: 195 / 255, green: 239 / 255, blue: 60 / 255, alpha: 1)
    /// Figma brush-size bar + undo chrome border (`rgb 0, 0.824, 0.416`).
    static let limeChromeBorder = UIColor(red: 0, green: 210 / 255, blue: 106 / 255, alpha: 1)
    static let undoGreen = limeChromeFill
    static let undoGreenBorder = limeChromeBorder
    static let cameraBlue = UIColor(red: 39 / 255, green: 100 / 255, blue: 220 / 255, alpha: 1)
    static let cameraBlueBorder = UIColor(red: 32 / 255, green: 80 / 255, blue: 180 / 255, alpha: 1)

    static func makeIconChromeButton(
        side: CGFloat,
        cornerRadius: CGFloat,
        fill: UIColor,
        border: UIColor,
        image: UIImage?,
        accessibilityLabel: String
    ) -> UIButton {
        let b = UIButton(type: .custom)
        b.translatesAutoresizingMaskIntoConstraints = false
        b.setImage(image, for: .normal)
        b.imageView?.contentMode = .scaleAspectFit
        b.backgroundColor = fill
        b.layer.cornerRadius = cornerRadius
        b.layer.borderWidth = 4
        b.layer.borderColor = border.cgColor
        b.clipsToBounds = true
        b.contentEdgeInsets = UIEdgeInsets(top: 8, left: 8, bottom: 8, right: 8)
        b.accessibilityLabel = accessibilityLabel
        FigmaTheme.applyCardShadow(to: b.layer)
        let wc = b.widthAnchor.constraint(equalToConstant: side)
        let hc = b.heightAnchor.constraint(equalToConstant: side)
        wc.isActive = true
        hc.isActive = true
        return b
    }

    static func brushBarSize(for tc: UITraitCollection, dotCount: Int) -> (width: CGFloat, height: CGFloat) {
        let phone = MagicBrushyChromeMetrics.isPhone(tc)
        let n = max(1, dotCount)
        // ≥48pt per segment keeps every dot easy to tap without overlap.
        let minSegment: CGFloat = 48
        if phone {
            let width = max(220, minSegment * CGFloat(n))
            return (width: width, height: 42)
        }
        let width = max(280, minSegment * CGFloat(n))
        return (width: width, height: 55)
    }
}
