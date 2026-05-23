import UIKit

/// Blue pill brush-size strip with one tap target per stroke preset (Figma `122:233`).
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

    private static let pillFill = ColoringFigmaToolbarChrome.brushBarFill
    private static let pillStroke = ColoringFigmaToolbarChrome.brushBarBorder

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

        // Edge-to-edge tap bands between dot centers so the smallest size is easy to hit.
        for i in 0..<dotCount {
            let center = dotCenter(in: bounds, index: i, count: dotCount).x
            let left: CGFloat
            let right: CGFloat
            if dotCount == 1 {
                left = bounds.minX
                right = bounds.maxX
            } else if i == 0 {
                left = bounds.minX
                right = (center + dotCenter(in: bounds, index: i + 1, count: dotCount).x) * 0.5
            } else if i == dotCount - 1 {
                left = (dotCenter(in: bounds, index: i - 1, count: dotCount).x + center) * 0.5
                right = bounds.maxX
            } else {
                left = (dotCenter(in: bounds, index: i - 1, count: dotCount).x + center) * 0.5
                right = (center + dotCenter(in: bounds, index: i + 1, count: dotCount).x) * 0.5
            }
            hitButtons[i].frame = CGRect(x: left, y: 0, width: max(1, right - left), height: h)
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

    /// Figma brush-size bar `122:233` fill (`#3C98EF`).
    static let brushBarFill = FigmaTheme.actionBlue
    /// Figma brush-size bar `122:233` border (`#2764DC`).
    static let brushBarBorder = UIColor(red: 39 / 255, green: 100 / 255, blue: 220 / 255, alpha: 1)

    /// Figma undo chrome fill (`rgb 0.765, 0.937, 0.235`).
    static let limeChromeFill = UIColor(red: 195 / 255, green: 239 / 255, blue: 60 / 255, alpha: 1)
    /// Figma undo chrome border (`rgb 0, 0.824, 0.416`).
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
        let n = max(1, dotCount)
        let height = MagicBrushyChromeMetrics.chromeButtonSide(tc)
        // ≥48pt per segment keeps every dot easy to tap without overlap.
        let minSegment: CGFloat = 48
        let minWidth: CGFloat = MagicBrushyChromeMetrics.isPhone(tc) ? 220 : 280
        let width = max(minWidth, minSegment * CGFloat(n))
        return (width: width, height: height)
    }

    static func phoneCollapsedBrushSizeSide(for tc: UITraitCollection) -> CGFloat {
        MagicBrushyChromeMetrics.chromeButtonSide(tc)
    }
}

// MARK: - iPhone collapsible brush-size chrome

/// On iPhone, shows a compact square toggle; tap to expand the full size bar and free canvas width when collapsed.
final class ColoringCollapsibleBrushSizeChrome: UIView {

    let bar = ColoringFigmaBrushSizeBarView()

    var dotCount: Int {
        get { bar.dotCount }
        set {
            bar.dotCount = newValue
            togglePreview.dotCount = newValue
        }
    }

    var selectedIndex: Int {
        get { bar.selectedIndex }
        set {
            bar.selectedIndex = newValue
            togglePreview.selectedIndex = newValue
            togglePreview.setNeedsDisplay()
        }
    }

    var dotFillColor: UIColor {
        get { bar.dotFillColor }
        set {
            bar.dotFillColor = newValue
            togglePreview.dotFillColor = newValue
            togglePreview.setNeedsDisplay()
        }
    }

    var onSelectionChanged: ((Int) -> Void)? {
        didSet { wireBarSelectionHandler() }
    }

    private(set) var isExpanded = false
    var phoneCollapsibleEnabled = false

    private let toggleButton = UIButton(type: .custom)
    private let togglePreview = BrushSizeTogglePreviewView()
    private var chromeWidthConstraint: NSLayoutConstraint!
    private var chromeHeightConstraint: NSLayoutConstraint!
    private var barWidthConstraint: NSLayoutConstraint!
    private var barLeadingConstraint: NSLayoutConstraint!
    private var barTrailingConstraint: NSLayoutConstraint!
    private var toggleLeadingConstraint: NSLayoutConstraint!
    private var toggleTrailingConstraint: NSLayoutConstraint!
    private var expandedBarWidth: CGFloat = 220
    private var collapsedSide: CGFloat = 38
    private var barHeight: CGFloat = 42

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
        setContentCompressionResistancePriority(.required, for: .horizontal)
        setContentHuggingPriority(.required, for: .horizontal)

        bar.translatesAutoresizingMaskIntoConstraints = false
        addSubview(bar)

        toggleButton.translatesAutoresizingMaskIntoConstraints = false
        toggleButton.backgroundColor = ColoringFigmaToolbarChrome.brushBarFill
        toggleButton.layer.borderColor = ColoringFigmaToolbarChrome.brushBarBorder.cgColor
        toggleButton.clipsToBounds = true
        toggleButton.accessibilityLabel = "Brush size"
        toggleButton.accessibilityHint = "Shows brush thickness options"
        toggleButton.addTarget(self, action: #selector(toggleTapped), for: .touchUpInside)
        toggleButton.addSubview(togglePreview)
        addSubview(toggleButton)

        togglePreview.isUserInteractionEnabled = false
        togglePreview.translatesAutoresizingMaskIntoConstraints = false

        chromeWidthConstraint = widthAnchor.constraint(equalToConstant: expandedBarWidth)
        chromeHeightConstraint = heightAnchor.constraint(equalToConstant: barHeight)
        barWidthConstraint = bar.widthAnchor.constraint(equalToConstant: expandedBarWidth)
        barLeadingConstraint = bar.leadingAnchor.constraint(equalTo: leadingAnchor)
        barTrailingConstraint = bar.trailingAnchor.constraint(equalTo: trailingAnchor)
        toggleLeadingConstraint = toggleButton.leadingAnchor.constraint(equalTo: leadingAnchor)
        toggleTrailingConstraint = toggleButton.trailingAnchor.constraint(equalTo: trailingAnchor)
        NSLayoutConstraint.activate([
            chromeWidthConstraint,
            chromeHeightConstraint,
            barWidthConstraint,
            barLeadingConstraint,
            bar.centerYAnchor.constraint(equalTo: centerYAnchor),
            bar.heightAnchor.constraint(equalTo: heightAnchor),
            toggleLeadingConstraint,
            toggleButton.centerYAnchor.constraint(equalTo: centerYAnchor),
            toggleButton.widthAnchor.constraint(equalTo: heightAnchor),
            toggleButton.heightAnchor.constraint(equalTo: heightAnchor),
            togglePreview.centerXAnchor.constraint(equalTo: toggleButton.centerXAnchor),
            togglePreview.centerYAnchor.constraint(equalTo: toggleButton.centerYAnchor),
            togglePreview.widthAnchor.constraint(equalTo: toggleButton.widthAnchor, multiplier: 0.62),
            togglePreview.heightAnchor.constraint(equalTo: togglePreview.widthAnchor),
        ])
        barTrailingConstraint.isActive = false
        toggleTrailingConstraint.isActive = false

        wireBarSelectionHandler()
    }

    private func wireBarSelectionHandler() {
        bar.onSelectionChanged = { [weak self] index in
            guard let self else { return }
            self.togglePreview.selectedIndex = index
            self.togglePreview.setNeedsDisplay()
            self.onSelectionChanged?(index)
            if self.phoneCollapsibleEnabled {
                self.setExpanded(false, animated: true)
            }
        }
    }

    func applyMetrics(
        expandedWidth: CGFloat,
        expandedHeight: CGFloat,
        collapsedSide: CGFloat,
        traitCollection: UITraitCollection
    ) {
        expandedBarWidth = expandedWidth
        self.collapsedSide = collapsedSide
        // Match home / settings / camera / undo square chrome height.
        let chromeHeight = collapsedSide
        barHeight = chromeHeight
        bar.applyChromeMetrics(barWidth: expandedWidth, barHeight: chromeHeight)
        barWidthConstraint.constant = expandedWidth
        chromeHeightConstraint.constant = chromeHeight
        toggleButton.layer.cornerRadius = MagicBrushyChromeMetrics.chromeCornerRadius(traitCollection)
        toggleButton.layer.borderWidth = MagicBrushyChromeMetrics.chromeBorderWidth(traitCollection)
        if #available(iOS 13.0, *) {
            toggleButton.layer.cornerCurve = .continuous
        }
        updateChromeWidth(animated: false)
    }

    func configureForPhone(_ phone: Bool, traitCollection: UITraitCollection) {
        let wasPhone = phoneCollapsibleEnabled
        phoneCollapsibleEnabled = phone
        setPhoneTrailingExpansionLayout(phone)
        if phone {
            if !wasPhone { setExpanded(false, animated: false) }
            toggleButton.accessibilityHint = "Tap to choose brush thickness"
        } else {
            setExpanded(true, animated: false)
            toggleButton.accessibilityHint = "Pick how thick your paint is"
        }
        updateChromeWidth(animated: false)
    }

    /// On iPhone the bar grows left (toward the canvas) from the undo side of the rail.
    private func setPhoneTrailingExpansionLayout(_ phone: Bool) {
        barLeadingConstraint.isActive = !phone
        toggleLeadingConstraint.isActive = !phone
        barTrailingConstraint.isActive = phone
        toggleTrailingConstraint.isActive = phone
    }

    func setExpanded(_ expanded: Bool, animated: Bool) {
        guard phoneCollapsibleEnabled || expanded else { return }
        isExpanded = expanded
        toggleButton.accessibilityValue = expanded ? "Expanded" : "Collapsed, tap to expand"
        if phoneCollapsibleEnabled {
            layer.zPosition = expanded ? 150 : 0
        }
        let apply = {
            self.updateChromeWidth(animated: false)
        }
        if animated {
            UIView.animate(withDuration: 0.22, delay: 0, options: [.curveEaseOut], animations: apply)
        } else {
            apply()
        }
    }

    private func updateChromeWidth(animated: Bool) {
        let showBar = !phoneCollapsibleEnabled || isExpanded
        bar.isHidden = !showBar
        bar.isUserInteractionEnabled = showBar
        toggleButton.isHidden = phoneCollapsibleEnabled && isExpanded
        let width = phoneCollapsibleEnabled && !isExpanded ? collapsedSide : expandedBarWidth
        chromeWidthConstraint.constant = width
        if !animated { layoutIfNeeded() }
    }

    /// Expanded bar extends left over the canvas; UIKit skips subviews when the touch is outside `bounds`.
    override func hitTest(_ point: CGPoint, with event: UIEvent?) -> UIView? {
        guard !isHidden, isUserInteractionEnabled, alpha >= 0.01 else { return nil }
        if phoneCollapsibleEnabled, isExpanded, !bar.isHidden, bar.isUserInteractionEnabled {
            let local = convert(point, to: bar)
            if let hit = bar.hitTest(local, with: event) { return hit }
        }
        return super.hitTest(point, with: event)
    }

    @objc private func toggleTapped() {
        guard phoneCollapsibleEnabled else { return }
        setExpanded(!isExpanded, animated: true)
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }
}

/// Single-dot preview for the collapsed brush-size toggle.
private final class BrushSizeTogglePreviewView: UIView {

    var selectedIndex = 0
    var dotCount = 5
    var dotFillColor = UIColor(red: 20 / 255, green: 102 / 255, blue: 1, alpha: 1)

    override init(frame: CGRect) {
        super.init(frame: frame)
        backgroundColor = .clear
        isOpaque = false
        contentMode = .redraw
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        backgroundColor = .clear
        isOpaque = false
        contentMode = .redraw
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext(), dotCount > 0 else { return }
        let count = max(1, dotCount)
        let idx = min(max(0, selectedIndex), count - 1)
        let minR = bounds.height * 0.22
        let maxR = bounds.height * 0.42
        let t = count > 1 ? CGFloat(idx) / CGFloat(count - 1) : 0.5
        let r = minR + (maxR - minR) * t
        let center = CGPoint(x: bounds.midX, y: bounds.midY)
        let dotRect = CGRect(x: center.x - r, y: center.y - r, width: r * 2, height: r * 2)
        ctx.setFillColor(dotFillColor.cgColor)
        ctx.fillEllipse(in: dotRect)
        ctx.setStrokeColor(UIColor.black.cgColor)
        ctx.setLineWidth(3)
        ctx.strokeEllipse(in: dotRect.insetBy(dx: 1, dy: 1))
        ctx.setStrokeColor(UIColor.white.cgColor)
        ctx.setLineWidth(2.5)
        ctx.strokeEllipse(in: dotRect.insetBy(dx: -0.5, dy: -0.5))
    }
}
