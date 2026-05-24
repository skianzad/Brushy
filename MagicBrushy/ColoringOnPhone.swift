import UIKit

// MARK: - Pass-through stack

/// Forwards hits only to side-rail subviews so the canvas underneath receives drawing touches.
final class ColoringPhonePassThroughStackView: UIStackView {
    override func hitTest(_ point: CGPoint, with event: UIEvent?) -> UIView? {
        guard !isHidden, isUserInteractionEnabled, alpha >= 0.01, bounds.contains(point) else { return nil }

        let interactive = arrangedSubviews.filter {
            $0.isUserInteractionEnabled && !$0.isHidden && $0.alpha >= 0.01
        }
        let leftRail = interactive.min { $0.frame.minX < $1.frame.minX }
        let rightRail = interactive.max { $0.frame.maxX < $1.frame.maxX }

        // Leading rail first (chrome row prioritized inside `ColoringPhoneLeftRailStackView`).
        if let leftRail, leftRail !== rightRail {
            let local = convert(point, to: leftRail)
            if let hit = leftRail.hitTest(local, with: event) { return hit }
        }
        if let rightRail {
            let local = convert(point, to: rightRail)
            if let hit = rightRail.hitTest(local, with: event) { return hit }
        }
        for subview in interactive where subview !== leftRail && subview !== rightRail {
            if let hit = forwardHit(to: subview, point: point, event: event) { return hit }
        }
        return nil
    }

    private func forwardHit(to subview: UIView, point: CGPoint, event: UIEvent?) -> UIView? {
        subview.hitTest(convert(point, to: subview), with: event)
    }
}

/// Leading rail: chrome row (home / settings / camera) wins over the mascot column below.
final class ColoringPhoneLeftRailStackView: UIStackView {
    weak var chromeRow: UIView?

    override func hitTest(_ point: CGPoint, with event: UIEvent?) -> UIView? {
        guard !isHidden, isUserInteractionEnabled, alpha >= 0.01 else { return nil }
        if let chromeRow, !chromeRow.isHidden, chromeRow.isUserInteractionEnabled {
            let local = convert(point, to: chromeRow)
            if let hit = chromeRow.hitTest(local, with: event) { return hit }
        }
        return super.hitTest(point, with: event)
    }
}

/// Trailing rail: in-bounds hits use normal layout; overflow catches the expanded brush bar over the canvas.
final class ColoringPhoneSideRailStackView: UIStackView {
    override func hitTest(_ point: CGPoint, with event: UIEvent?) -> UIView? {
        guard !isHidden, isUserInteractionEnabled, alpha >= 0.01 else { return nil }
        if bounds.contains(point), let hit = super.hitTest(point, with: event), hit !== self {
            return hit
        }
        return findOverflowDescendant(at: point, event: event, in: self)
    }

    private func findOverflowDescendant(at point: CGPoint, event: UIEvent?, in view: UIView) -> UIView? {
        guard view.isUserInteractionEnabled, !view.isHidden, view.alpha >= 0.01 else { return nil }
        for subview in view.subviews.reversed() {
            let local = view.convert(point, to: subview)
            if let hit = findOverflowDescendant(at: local, event: event, in: subview) { return hit }
            guard !subview.bounds.contains(local) else { continue }
            if let hit = subview.hitTest(local, with: event) { return hit }
        }
        return nil
    }
}

// MARK: - Metrics

enum ColoringOnPhoneMetrics {

    static let toolButtonSide: CGFloat = 50
    static let paintRowLeadingInset: CGFloat = 0
    static let paintRowTrailingInset: CGFloat = 0
    static let paintRowRailSpacing: CGFloat = 2
    static let canvasVisualScale: CGFloat = 1
    static let canvasMinZoom: CGFloat = 1
    static let canvasMaxZoom: CGFloat = 3
    static let paintRowTopInset: CGFloat = 10
    static let paintRowTopInsetWhenInactive: CGFloat = 4

    private static let swatchContentHeightPerWidth: CGFloat = 71.0 / 206.0
    private static let crayonRailMinimum: CGFloat = 76
    static let crayonHeightMultiplier: CGFloat = 1.10

    static var toolPairSpacing: CGFloat {
        max(3, (4 * UIScreen.main.nativeScale / UIScreen.main.scale).rounded(.toNearestOrAwayFromZero))
    }

    static func crayonRowHeight(phonePanelWidth: CGFloat) -> CGFloat {
        ceil((phonePanelWidth - 4) * swatchContentHeightPerWidth * crayonHeightMultiplier)
    }

    private static func leftPanelMinWidth(for traitCollection: UITraitCollection) -> CGFloat {
        let side = MagicBrushyChromeMetrics.chromeButtonSide(traitCollection)
        let spacing: CGFloat = 6
        return side * 3 + spacing * 2 + 8
    }

    private static func rightPanelMinWidth(for traitCollection: UITraitCollection) -> CGFloat {
        let navSide = MagicBrushyChromeMetrics.chromeButtonSide(traitCollection)
        let chromeRowWidth = navSide * 2 + 6
        let toolPairWidth = toolButtonSide * 2 + toolPairSpacing
        return max(crayonRailMinimum, chromeRowWidth, toolPairWidth)
    }

    static func sidePanelWidth(for traitCollection: UITraitCollection, brushDotCount: Int) -> CGFloat {
        _ = brushDotCount
        return max(
            leftPanelMinWidth(for: traitCollection),
            rightPanelMinWidth(for: traitCollection)
        )
    }
}

// MARK: - Layout

/// iPhone coloring chrome: side rails, full-height 4:3 canvas overlay, pinch/pan zoom.
final class ColoringOnPhone: NSObject, UIGestureRecognizerDelegate {

    struct Host {
        unowned let view: UIView
        unowned let paintRow: UIStackView
        unowned let canvasContainer: UIView
        unowned let headerChromeStack: UIStackView
        unowned let rightPanelStack: UIStackView
        unowned let mascotContainer: UIView
        unowned let toolPairStack: UIStackView
        unowned let crayonScrollContainer: UIView
        unowned let homeButton: UIButton
        unowned let cameraChromeButton: UIButton
        unowned let undoChromeButton: UIButton
        unowned let brushSizeChrome: ColoringCollapsibleBrushSizeChrome
        weak var settingsGearButton: MagicBrushySettingsGearButton?
        unowned let topChromeLeftRow: UIStackView
        unowned let topChromeRightRow: UIStackView
        unowned let rightPanelPhoneTopSpacer: UIView
        unowned var rightPanelPhoneTopSpacerHeight: NSLayoutConstraint!
        unowned var paintRowLeadingConstraint: NSLayoutConstraint!
        unowned var paintRowTrailingConstraint: NSLayoutConstraint!
        unowned var paintRowTrailingScreenEdgeConstraint: NSLayoutConstraint!
        unowned var headerLeadingCanvasConstraint: NSLayoutConstraint!
        unowned var headerLeadingPaintRowConstraint: NSLayoutConstraint!
        unowned var paintRowTopToHeaderBottomConstraint: NSLayoutConstraint!
        unowned var paintRowTopToHeaderTopConstraint: NSLayoutConstraint!
        unowned var paintRowTopToSafeAreaConstraint: NSLayoutConstraint!
        unowned var headerTopConstraint: NSLayoutConstraint!
        unowned var rightPanelWidthConstraint: NSLayoutConstraint?
        unowned var mascotRailWidthConstraint: NSLayoutConstraint!
        unowned var mascotImageCenterXConstraint: NSLayoutConstraint!
        unowned var mascotImageLeadingConstraint: NSLayoutConstraint!
        unowned var mascotImageTopConstraint: NSLayoutConstraint!
        var setStackCanvasAspectConstraintActive: (Bool) -> Void
    }

    let leftPanelStack = ColoringPhoneLeftRailStackView()
    let leftPanelChromeRow = UIStackView()
    let rightPanelChromeRow = UIStackView()

    private(set) var leftPanelWidthConstraint: NSLayoutConstraint!
    private(set) var leftPanelChromeRowHeightConstraint: NSLayoutConstraint!
    private(set) var rightPanelChromeRowHeightConstraint: NSLayoutConstraint!

    private(set) var canvasPinchGesture: UIPinchGestureRecognizer!
    private(set) var canvasPanGesture: UIPanGestureRecognizer!

    var isLayoutActive: Bool { usesThreeColumnLayout }
    var usesCanvasOverlayLayout: Bool { canvasUsesOverlayLayout }
    var mascotIsOnLeadingRail: Bool { usesThreeColumnLayout }

    private let host: Host
    private let leftPanelMascotSpacer = UIView()
    private let phoneCanvasMiddleSpacer = UIView()
    private var usesThreeColumnLayout = false
    private var canvasUsesOverlayLayout = false
    private var phoneCanvasOverlayConstraints: [NSLayoutConstraint] = []
    private var userZoom: CGFloat = 1
    private var panOffset: CGPoint = .zero
    private var pinchBaselineZoom: CGFloat = 1
    private var panBaselineOffset: CGPoint = .zero
    var onZoomChanged: (() -> Void)?

    init(host: Host) {
        self.host = host
        super.init()
    }

    func installChromeRows(navSide: CGFloat) {
        leftPanelStack.axis = .vertical
        leftPanelStack.alignment = .center
        leftPanelStack.spacing = 8
        leftPanelStack.distribution = .fill
        leftPanelStack.translatesAutoresizingMaskIntoConstraints = false
        leftPanelStack.isHidden = true
        leftPanelStack.chromeRow = leftPanelChromeRow

        leftPanelChromeRow.axis = .horizontal
        leftPanelChromeRow.alignment = .center
        leftPanelChromeRow.spacing = 6
        leftPanelChromeRow.distribution = .fill
        leftPanelChromeRow.translatesAutoresizingMaskIntoConstraints = false
        leftPanelChromeRowHeightConstraint = leftPanelChromeRow.heightAnchor.constraint(equalToConstant: navSide)
        leftPanelChromeRowHeightConstraint.isActive = true

        rightPanelChromeRow.axis = .horizontal
        rightPanelChromeRow.alignment = .center
        rightPanelChromeRow.spacing = 6
        rightPanelChromeRow.distribution = .fill
        rightPanelChromeRow.translatesAutoresizingMaskIntoConstraints = false
        rightPanelChromeRow.clipsToBounds = false
        rightPanelChromeRowHeightConstraint = rightPanelChromeRow.heightAnchor.constraint(equalToConstant: navSide)
        rightPanelChromeRowHeightConstraint.isActive = true

        leftPanelMascotSpacer.backgroundColor = .clear
        leftPanelMascotSpacer.setContentHuggingPriority(.defaultLow, for: .vertical)
        leftPanelMascotSpacer.setContentCompressionResistancePriority(.defaultLow, for: .vertical)

        leftPanelWidthConstraint = leftPanelStack.widthAnchor.constraint(equalToConstant: navSide)
    }

    func updateChromeRowHeights(_ chromeSide: CGFloat) {
        leftPanelChromeRowHeightConstraint?.constant = chromeSide
        rightPanelChromeRowHeightConstraint?.constant = chromeSide
    }

    func sidePanelWidth(for traitCollection: UITraitCollection, brushDotCount: Int) -> CGFloat {
        ColoringOnPhoneMetrics.sidePanelWidth(for: traitCollection, brushDotCount: brushDotCount)
    }

    func applyLayout(
        isPhone: Bool,
        traitCollection tc: UITraitCollection,
        brushDotCount: Int,
        setCanvasAspectRatio: (CGFloat, UILayoutPriority) -> Void,
        applyCanvasVisualTransform: () -> Void
    ) {
        let sidePanelWidth = sidePanelWidth(for: tc, brushDotCount: brushDotCount)
        leftPanelWidthConstraint?.constant = sidePanelWidth
        host.rightPanelWidthConstraint?.constant = sidePanelWidth

        if isPhone {
            host.headerChromeStack.isHidden = true
            leftPanelStack.isHidden = false
            leftPanelStack.alignment = .leading
            host.rightPanelStack.alignment = .fill
            host.headerLeadingCanvasConstraint.isActive = false
            host.headerLeadingPaintRowConstraint.isActive = false
            host.paintRowTopToHeaderBottomConstraint.isActive = false
            host.paintRowTopToHeaderTopConstraint.isActive = false
            host.paintRowTopToSafeAreaConstraint.isActive = true
            host.paintRowTopToSafeAreaConstraint.constant = ColoringOnPhoneMetrics.paintRowTopInset

            configureSidePanels()
            setCanvasOverlayLayoutEnabled(true)

            if !usesThreeColumnLayout {
                if !host.paintRow.arrangedSubviews.contains(leftPanelStack) {
                    host.paintRow.insertArrangedSubview(leftPanelStack, at: 0)
                }
                if leftPanelWidthConstraint?.isActive != true {
                    leftPanelWidthConstraint?.isActive = true
                }
            }

            host.mascotRailWidthConstraint.constant = sidePanelWidth
            host.mascotRailWidthConstraint.isActive = true
            host.mascotImageCenterXConstraint.isActive = true
            host.mascotImageLeadingConstraint.isActive = false
            host.mascotImageLeadingConstraint.constant = 0
            host.mascotImageTopConstraint.constant = 0
            host.mascotContainer.setContentHuggingPriority(.defaultLow, for: .horizontal)
            host.mascotContainer.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)

            setCanvasAspectRatio(4.0 / 3.0, .required)
            usesThreeColumnLayout = true
        } else {
            setCanvasOverlayLayoutEnabled(false)
            host.paintRowTopToSafeAreaConstraint.constant = ColoringOnPhoneMetrics.paintRowTopInsetWhenInactive
            host.headerChromeStack.isHidden = false
            leftPanelStack.isHidden = true
            host.headerLeadingCanvasConstraint.isActive = true
            host.headerLeadingPaintRowConstraint.isActive = false
            host.paintRowTopToSafeAreaConstraint.isActive = false
            host.paintRowTopToHeaderTopConstraint.isActive = false
            host.paintRowTopToHeaderBottomConstraint.isActive = true
            host.paintRowTopToHeaderBottomConstraint.constant = 8
            host.headerTopConstraint.constant = 0
            host.rightPanelPhoneTopSpacerHeight.constant = 0

            if usesThreeColumnLayout {
                restorePadChromeLayout()
            }

            host.mascotRailWidthConstraint.isActive = false
            host.mascotImageLeadingConstraint.isActive = false
            host.mascotImageCenterXConstraint.isActive = true
            host.mascotImageTopConstraint.constant = 0
            host.mascotContainer.setContentHuggingPriority(.required, for: .vertical)
            host.mascotContainer.setContentCompressionResistancePriority(.required, for: .vertical)

            setCanvasAspectRatio(4.0 / 5.0, .defaultHigh)
            host.view.bringSubviewToFront(host.headerChromeStack)
            usesThreeColumnLayout = false
        }

        applyPaintRowInsets(for: tc)
        applyCanvasVisualTransform()
    }

    func applyPaintRowInsets(for tc: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(tc)
        host.paintRowLeadingConstraint.constant = phone
            ? ColoringOnPhoneMetrics.paintRowLeadingInset
            : 2
        if phone {
            host.paintRowTrailingConstraint.isActive = false
            host.paintRowTrailingScreenEdgeConstraint.isActive = true
        } else {
            host.paintRowTrailingScreenEdgeConstraint.isActive = false
            host.paintRowTrailingConstraint.isActive = true
            host.paintRowTrailingConstraint.constant = -10
        }
        if phone {
            host.paintRow.spacing = ColoringOnPhoneMetrics.paintRowRailSpacing
            host.paintRow.setCustomSpacing(
                ColoringOnPhoneMetrics.paintRowRailSpacing,
                after: phoneCanvasMiddleSpacer
            )
            host.rightPanelWidthConstraint?.priority = .required
        } else {
            host.paintRow.spacing = 10
            host.paintRow.setCustomSpacing(10, after: host.canvasContainer)
            host.rightPanelWidthConstraint?.priority = .required
        }
        if phone, mascotIsOnLeadingRail {
            host.mascotImageLeadingConstraint.constant = 0
            host.mascotImageTopConstraint.constant = 0
        } else if mascotIsOnLeadingRail {
            host.mascotImageLeadingConstraint.constant = -14
            host.mascotImageTopConstraint.constant = 0
        } else {
            host.mascotImageTopConstraint.constant = 0
        }
    }

    func installCanvasZoomGestures(on canvasContainer: UIView, traitCollection: UITraitCollection) {
        let pinch = UIPinchGestureRecognizer(target: self, action: #selector(handleCanvasPinch(_:)))
        pinch.delegate = self
        canvasContainer.addGestureRecognizer(pinch)
        canvasPinchGesture = pinch

        let pan = UIPanGestureRecognizer(target: self, action: #selector(handleCanvasPan(_:)))
        pan.minimumNumberOfTouches = 2
        pan.maximumNumberOfTouches = 2
        pan.delegate = self
        canvasContainer.addGestureRecognizer(pan)
        canvasPanGesture = pan

        updateZoomGesturesEnabled(for: traitCollection)
    }

    func updateZoomGesturesEnabled(for traitCollection: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        canvasPinchGesture?.isEnabled = phone
        canvasPanGesture?.isEnabled = phone && userZoom > ColoringOnPhoneMetrics.canvasMinZoom + 0.01
    }

    func canvasTransform(for traitCollection: UITraitCollection) -> CGAffineTransform {
        guard MagicBrushyChromeMetrics.isPhone(traitCollection) else {
            return CGAffineTransform(translationX: -6, y: 0)
                .scaledBy(x: 0.97, y: 0.97)
        }
        let scale = ColoringOnPhoneMetrics.canvasVisualScale * userZoom
        return CGAffineTransform(translationX: panOffset.x, y: panOffset.y)
            .scaledBy(x: scale, y: scale)
    }

    func resetZoom(applyCanvasVisualTransform: () -> Void) {
        userZoom = 1
        panOffset = .zero
        applyCanvasVisualTransform()
    }

    func isPhoneCanvasGesture(_ gestureRecognizer: UIGestureRecognizer) -> Bool {
        gestureRecognizer === canvasPinchGesture || gestureRecognizer === canvasPanGesture
    }

    // MARK: - Private

    private func configureSidePanels() {
        detachFromArrangedStack(host.homeButton)
        detachFromArrangedStack(host.cameraChromeButton)
        detachFromArrangedStack(host.undoChromeButton)
        detachFromArrangedStack(host.brushSizeChrome)
        host.settingsGearButton.map { detachFromArrangedStack($0) }
        detachFromArrangedStack(host.mascotContainer)
        detachFromArrangedStack(leftPanelChromeRow)
        detachFromArrangedStack(rightPanelChromeRow)

        clearArrangedSubviews(of: leftPanelChromeRow)
        clearArrangedSubviews(of: rightPanelChromeRow)
        clearArrangedSubviews(of: leftPanelStack)
        clearArrangedSubviews(of: host.rightPanelStack)

        leftPanelChromeRow.addArrangedSubview(host.homeButton)
        if let settingsGearButton = host.settingsGearButton {
            leftPanelChromeRow.addArrangedSubview(settingsGearButton)
        }
        leftPanelChromeRow.addArrangedSubview(host.cameraChromeButton)

        leftPanelStack.addArrangedSubview(leftPanelChromeRow)
        leftPanelStack.addArrangedSubview(leftPanelMascotSpacer)
        leftPanelStack.addArrangedSubview(host.mascotContainer)

        rightPanelChromeRow.addArrangedSubview(host.brushSizeChrome)
        rightPanelChromeRow.addArrangedSubview(host.undoChromeButton)

        host.rightPanelStack.addArrangedSubview(rightPanelChromeRow)
        host.rightPanelStack.addArrangedSubview(host.toolPairStack)
        host.rightPanelStack.addArrangedSubview(host.crayonScrollContainer)
        applyPhoneChromeZOrdering()
    }

    private func applyPhoneChromeZOrdering() {
        leftPanelChromeRow.layer.zPosition = 30
        leftPanelMascotSpacer.layer.zPosition = 0
        host.mascotContainer.layer.zPosition = 0
        rightPanelChromeRow.layer.zPosition = 30
        host.toolPairStack.layer.zPosition = 20
        host.crayonScrollContainer.layer.zPosition = 0
    }

    private func clearPhoneChromeZOrdering() {
        leftPanelChromeRow.layer.zPosition = 0
        leftPanelMascotSpacer.layer.zPosition = 0
        host.mascotContainer.layer.zPosition = 0
        rightPanelChromeRow.layer.zPosition = 0
        host.toolPairStack.layer.zPosition = 0
        host.crayonScrollContainer.layer.zPosition = 0
    }

    private func restorePadChromeLayout() {
        leftPanelStack.alignment = .center
        host.rightPanelStack.alignment = .fill
        detachFromArrangedStack(host.homeButton)
        detachFromArrangedStack(host.cameraChromeButton)
        detachFromArrangedStack(host.undoChromeButton)
        detachFromArrangedStack(host.brushSizeChrome)
        host.settingsGearButton.map { detachFromArrangedStack($0) }
        detachFromArrangedStack(host.mascotContainer)
        detachFromArrangedStack(leftPanelStack)
        clearArrangedSubviews(of: leftPanelChromeRow)
        clearArrangedSubviews(of: rightPanelChromeRow)

        clearArrangedSubviews(of: host.topChromeLeftRow)
        clearArrangedSubviews(of: host.topChromeRightRow)
        clearArrangedSubviews(of: host.rightPanelStack)

        host.topChromeLeftRow.addArrangedSubview(host.homeButton)
        if let settingsGearButton = host.settingsGearButton {
            host.topChromeLeftRow.addArrangedSubview(settingsGearButton)
        }
        host.topChromeLeftRow.addArrangedSubview(host.cameraChromeButton)
        host.topChromeRightRow.addArrangedSubview(host.brushSizeChrome)
        host.topChromeRightRow.addArrangedSubview(host.undoChromeButton)

        host.rightPanelPhoneTopSpacer.isHidden = true
        host.rightPanelStack.addArrangedSubview(host.rightPanelPhoneTopSpacer)
        host.rightPanelStack.addArrangedSubview(host.mascotContainer)
        host.rightPanelStack.addArrangedSubview(host.toolPairStack)
        host.rightPanelStack.addArrangedSubview(host.crayonScrollContainer)
        host.rightPanelStack.setCustomSpacing(2, after: host.mascotContainer)

        leftPanelWidthConstraint?.isActive = false
        clearPhoneChromeZOrdering()
    }

    private func setCanvasOverlayLayoutEnabled(_ enabled: Bool) {
        guard enabled != canvasUsesOverlayLayout else { return }
        canvasUsesOverlayLayout = enabled

        if enabled {
            if let stackIndex = host.paintRow.arrangedSubviews.firstIndex(of: host.canvasContainer) {
                host.paintRow.removeArrangedSubview(host.canvasContainer)
                if stackIndex <= host.paintRow.arrangedSubviews.count {
                    host.paintRow.insertArrangedSubview(phoneCanvasMiddleSpacer, at: stackIndex)
                } else {
                    host.paintRow.addArrangedSubview(phoneCanvasMiddleSpacer)
                }
            }
            host.canvasContainer.removeFromSuperview()
            host.view.insertSubview(host.canvasContainer, belowSubview: host.paintRow)

            phoneCanvasMiddleSpacer.backgroundColor = .clear
            phoneCanvasMiddleSpacer.isUserInteractionEnabled = false
            leftPanelMascotSpacer.isUserInteractionEnabled = false
            phoneCanvasMiddleSpacer.setContentHuggingPriority(.defaultLow, for: .horizontal)
            phoneCanvasMiddleSpacer.setContentCompressionResistancePriority(.defaultLow, for: .horizontal)

            host.setStackCanvasAspectConstraintActive(false)
            phoneCanvasOverlayConstraints = [
                host.canvasContainer.heightAnchor.constraint(equalTo: host.paintRow.heightAnchor),
                host.canvasContainer.widthAnchor.constraint(
                    equalTo: host.canvasContainer.heightAnchor,
                    multiplier: 4.0 / 3.0
                ),
                host.canvasContainer.centerXAnchor.constraint(equalTo: host.paintRow.centerXAnchor),
                host.canvasContainer.centerYAnchor.constraint(equalTo: host.paintRow.centerYAnchor),
            ]
            NSLayoutConstraint.activate(phoneCanvasOverlayConstraints)

            leftPanelStack.layer.zPosition = 100
            host.canvasContainer.layer.zPosition = 0
        } else {
            NSLayoutConstraint.deactivate(phoneCanvasOverlayConstraints)
            phoneCanvasOverlayConstraints = []

            host.paintRow.removeArrangedSubview(phoneCanvasMiddleSpacer)
            phoneCanvasMiddleSpacer.removeFromSuperview()

            host.canvasContainer.removeFromSuperview()
            let insertIndex = host.paintRow.arrangedSubviews.firstIndex(of: host.rightPanelStack)
                ?? host.paintRow.arrangedSubviews.count
            host.paintRow.insertArrangedSubview(host.canvasContainer, at: insertIndex)

            host.setStackCanvasAspectConstraintActive(true)
            leftPanelStack.layer.zPosition = 0
        }
    }

    private func detachFromArrangedStack(_ view: UIView) {
        if let stack = view.superview as? UIStackView {
            stack.removeArrangedSubview(view)
        }
        view.removeFromSuperview()
    }

    private func clearArrangedSubviews(of stack: UIStackView) {
        stack.arrangedSubviews.forEach { detachFromArrangedStack($0) }
    }

    @objc private func handleCanvasPinch(_ gesture: UIPinchGestureRecognizer) {
        switch gesture.state {
        case .began:
            pinchBaselineZoom = userZoom
        case .changed:
            userZoom = min(
                max(ColoringOnPhoneMetrics.canvasMinZoom, pinchBaselineZoom * gesture.scale),
                ColoringOnPhoneMetrics.canvasMaxZoom
            )
            onZoomChanged?()
        case .ended, .cancelled, .failed:
            if userZoom <= ColoringOnPhoneMetrics.canvasMinZoom + 0.01 {
                panOffset = .zero
            }
            onZoomChanged?()
        default:
            break
        }
    }

    @objc private func handleCanvasPan(_ gesture: UIPanGestureRecognizer) {
        guard userZoom > ColoringOnPhoneMetrics.canvasMinZoom + 0.01 else { return }
        switch gesture.state {
        case .began:
            panBaselineOffset = panOffset
        case .changed:
            let t = gesture.translation(in: host.view)
            panOffset = CGPoint(x: panBaselineOffset.x + t.x, y: panBaselineOffset.y + t.y)
            onZoomChanged?()
        default:
            break
        }
    }
}
