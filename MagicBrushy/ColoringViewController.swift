import UIKit
import Photos

/// Full-screen coloring: built-in outlines, finger or Apple Pencil, on-device VLM feedback.
/// No Bluetooth pen stack — input is multitouch / Pencil only.
final class ColoringViewController: UIViewController {

    private enum TopChromeMetrics {
        /// Pin the nav row to the safe-area top (no extra gap under the status bar).
        static let menuTopOffset: CGFloat = 0
        static let menuHorizontalInset: CGFloat = 6
        /// Slightly reduce system safe-area padding so content can sit closer to edges.
        static let additionalSafeAreaShrink = UIEdgeInsets(top: 0, left: -4, bottom: -6, right: -4)
    }

    private let templateView = UIImageView()
    /// Flattened snapshot when resuming from `LastDrawingStore` (sits between template and live strokes).
    private let resumeSnapshotView = UIImageView()
    private let strokeView = ColoringStrokeView()
    /// Line art only, above strokes so white eraser cannot hide template outlines.
    private let templateLineOverlayView = UIImageView()
    private let mascotImageView = UIImageView()
    private let mascotLipSync = MascotLipSyncDriver()
    /// Segments filled in `viewDidLoad`; avoids building outline bitmaps during storyboard instantiation.
    private let pageControl = UISegmentedControl()
    private let feedbackButton = UIButton(type: .system)
    private let clearButton = UIButton(type: .system)
    private let undoButton = UIButton(type: .system)
    private let loadOverlay = UIView()
    private let loadLabel = UILabel()
    private let loadProgress = UIProgressView(progressViewStyle: .default)
    private let vlmInputPreviewImageView = UIImageView()
    private let vlmInputPreviewLabel = UILabel()
    private let modelStatusDot = UIView(frame: .zero)
    private let modelStatusLabel = UILabel()
    private let modelStatusStack = UIStackView()
    /// When set from the category grid, this page is selected on first layout.
    var pinnedPageIndex: Int?
    /// Pages for this canvas session (defaults to the first built-in shelf).
    var coloringBookPages: [BuiltInColoringPages.Page] =
        BuiltInColoringPages.library.first(where: { $0.id == "animals" })?.pages
        ?? BuiltInColoringPages.library.first?.pages
        ?? []

    /// Set when pushing from the category grid so we can persist `LastDrawingStore` on the way home.
    var sessionPackId: String?
    /// Set when opening from the home “Your drawings” strip; home overwrites this record instead of appending a new save.
    var continuingSavedDrawingId: UUID?
    /// When continuing from the home “last drawing” strip, flattened art to show under new strokes.
    var pendingResumeComposite: UIImage?
    /// True when `pendingResumeComposite` is a line-free underlay; line art comes from `templateLineOverlayView` so the eraser cannot remove outlines.
    var pendingResumeHasSeparateLineOverlay = false
    private var didConsumePendingResumeComposite = false

    private let skyView = UIView()
    private let cloudContainer = UIView()
    private let homeButton = UIButton(type: .system)
    private let toolRow = UIStackView()
    private let prevPageButton = UIButton(type: .system)
    private let nextPageButton = UIButton(type: .system)
    private let doneButton = UIButton(type: .system)
    private let toolPairStack = UIStackView()
    /// Holds `crayonScrollView` so Auto Layout gives the scroll view a **bounded** height (required for vertical scrolling).
    private let crayonScrollContainer = UIView()
    private let crayonScrollView = CrayonPaletteScrollView()
    private let crayonStack = UIStackView()
    private var crayonControls: [MagicCrayonControl] = []
    /// Display order (top → bottom): maps to indices in `palette`.
    private var crayonPaletteDisplayOrder: [Int] { Array(0..<palette.count) }
    private var isEraserMode = false
    /// Index in `palette` when brush mode.
    private var strokePaletteIndex: Int = 4
    private var brushToolButton: UIButton?
    private var eraserToolButton: UIButton?

    // ── Stroke-size picker (canvas top-trailing, five “paint blobs”) ───────
    private let strokeWidthPresets: [CGFloat] = [10, 16, 22, 30, 40]
    private var selectedStrokeSizeIndex: Int = 2
    private var strokeSizeButtons: [UIButton] = []
    private var strokeSizeDotViews: [UIView] = []
    private let strokeSizeStack = UIStackView()

    /// App-wide singleton model; loaded once at app startup from SceneDelegate.
    private let vlm = LeapVLMModel.shared

    /// Same order as `palette` — short words kids know.
    private let paletteKidNames = [
        "red", "orange", "yellow", "green", "blue", "deep blue", "purple", "pink", "brown", "black",
        "cyan", "coral", "gold", "light green", "lavender", "rose",
        "lime", "peach", "sky", "lilac", "maroon", "navy", "olive", "tan",
        "cream", "gray", "magenta", "turquoise",
    ]

    private let palette: [UIColor] = [
        .systemRed, .systemOrange, .systemYellow, .systemGreen,
        .systemBlue, .systemIndigo, .systemPurple, .systemPink,
        .brown, .black,
        UIColor(red: 0, green: 0.75, blue: 0.83, alpha: 1),
        UIColor(red: 1, green: 0.45, blue: 0.42, alpha: 1),
        UIColor(red: 0.85, green: 0.65, blue: 0.13, alpha: 1),
        UIColor(red: 0.56, green: 0.93, blue: 0.56, alpha: 1),
        UIColor(red: 0.58, green: 0.44, blue: 0.86, alpha: 1),
        UIColor(red: 0.97, green: 0.51, blue: 0.75, alpha: 1),
        UIColor(red: 0.55, green: 0.94, blue: 0.25, alpha: 1),
        UIColor(red: 1, green: 0.72, blue: 0.56, alpha: 1),
        UIColor(red: 0.53, green: 0.81, blue: 0.98, alpha: 1),
        UIColor(red: 0.78, green: 0.64, blue: 0.86, alpha: 1),
        UIColor(red: 0.55, green: 0.1, blue: 0.2, alpha: 1),
        UIColor(red: 0.0, green: 0.2, blue: 0.45, alpha: 1),
        UIColor(red: 0.45, green: 0.52, blue: 0.18, alpha: 1),
        UIColor(red: 0.82, green: 0.71, blue: 0.55, alpha: 1),
        UIColor(red: 0.98, green: 0.95, blue: 0.82, alpha: 1),
        UIColor(red: 0.55, green: 0.57, blue: 0.6, alpha: 1),
        UIColor(red: 0.86, green: 0.2, blue: 0.65, alpha: 1),
        UIColor(red: 0.25, green: 0.88, blue: 0.82, alpha: 1),
    ]

    private var pageIndex = 0 {
        didSet { applyCurrentPage() }
    }

    private var pollTimer: Timer?
    /// After brush lift, defer VLM this long so a quick continuation cancels pending feedback (`onPaintingBegan` clears it).
    private static let feedbackIdleTriggerDelay: TimeInterval = 0.3
    private var pendingAutoFeedbackWork: DispatchWorkItem?
    private var pendingReactionWork: DispatchWorkItem?
    /// Bumped when the user paints again, changes page, clears, etc. — stale **spoken feedback** VLM work discards its result.
    private var feedbackGeneration: UInt64 = 0
    /// Last mascot pose applied after coach VLM — passed into semantic mapping to reduce back-to-back duplicates.
    private var lastMascotReaction: MascotReactionState?
    /// Bumped on page change / clear / undo only — **not** on every new stroke, so debounced mascot reactions can still apply after pen lift.
    private var reactionSession: UInt64 = 0
    private var vlmInputPreviewHideWork: DispatchWorkItem?
    /// When set, auto-feedback is suppressed until this date (user tapped mascot to mute).
    private var feedbackPausedUntil: Date?
    /// Label floating over the mascot showing the pause countdown.
    private let mascotPauseBadge = UILabel()

    override func viewDidLoad() {
        super.viewDidLoad()
        additionalSafeAreaInsets = TopChromeMetrics.additionalSafeAreaShrink
        let g = view.safeAreaLayoutGuide
        view.backgroundColor = FigmaTheme.skyBlue

        skyView.translatesAutoresizingMaskIntoConstraints = false
        skyView.backgroundColor = FigmaTheme.skyBlue
        cloudContainer.translatesAutoresizingMaskIntoConstraints = false
        cloudContainer.backgroundColor = .clear

        templateView.contentMode = .scaleAspectFit
        templateView.clipsToBounds = true
        templateView.backgroundColor = FigmaTheme.canvasFill
        templateView.layer.cornerRadius = 24
        templateView.layer.borderWidth = 5
        templateView.layer.borderColor = FigmaTheme.canvasBorder.cgColor

        for page in coloringBookPages {
            pageControl.insertSegment(withTitle: page.title, at: pageControl.numberOfSegments, animated: false)
        }
        pageControl.selectedSegmentIndex = min(max(0, pinnedPageIndex ?? 0), max(0, coloringBookPages.count - 1))
        pageControl.addTarget(self, action: #selector(pageChanged), for: .valueChanged)
        pageControl.isHidden = coloringBookPages.count <= 1
        styleSkySegmentedPagePicker(pageControl)

        feedbackButton.setTitle("Feedback", for: .normal)
        feedbackButton.titleLabel?.font = FigmaTheme.bodyFont(size: 17, weight: .semibold)
        styleChromeButton(feedbackButton, fill: FigmaTheme.primaryOrange, border: FigmaTheme.primaryOrangeBorder)

        clearButton.setTitle("Clear", for: .normal)
        clearButton.titleLabel?.font = FigmaTheme.bodyFont(size: 17, weight: .semibold)
        styleChromeButton(clearButton, fill: FigmaTheme.primaryOrange, border: FigmaTheme.primaryOrangeBorder)
        clearButton.addTarget(self, action: #selector(clearStrokes), for: .touchUpInside)

        undoButton.setTitle("Undo", for: .normal)
        undoButton.titleLabel?.font = FigmaTheme.bodyFont(size: 17, weight: .semibold)
        styleChromeButton(undoButton, fill: FigmaTheme.actionBlue, border: FigmaTheme.actionBlueBorder)
        undoButton.addTarget(self, action: #selector(undoStroke), for: .touchUpInside)

        feedbackButton.addTarget(self, action: #selector(requestFeedback), for: .touchUpInside)

        modelStatusDot.translatesAutoresizingMaskIntoConstraints = false
        modelStatusDot.layer.cornerRadius = 5
        modelStatusDot.clipsToBounds = true
        modelStatusLabel.translatesAutoresizingMaskIntoConstraints = false
        modelStatusLabel.font = .preferredFont(forTextStyle: .caption1)
        modelStatusLabel.textColor = .secondaryLabel
        modelStatusLabel.text = "AI: …"
        modelStatusLabel.numberOfLines = 1
        modelStatusLabel.lineBreakMode = .byTruncatingTail
        modelStatusLabel.setContentCompressionResistancePriority(.defaultLow, for: .horizontal)
        modelStatusStack.axis = .horizontal
        modelStatusStack.alignment = .center
        modelStatusStack.spacing = 8
        modelStatusStack.isAccessibilityElement = true
        modelStatusStack.accessibilityTraits = .updatesFrequently
        modelStatusStack.addArrangedSubview(modelStatusDot)
        modelStatusStack.addArrangedSubview(modelStatusLabel)
        modelStatusDot.widthAnchor.constraint(equalToConstant: 10).isActive = true
        modelStatusDot.heightAnchor.constraint(equalToConstant: 10).isActive = true

        // ── Tool pair (brush + eraser, side by side) ─────────────────────────
        brushToolButton = makeBrushToolButton()
        eraserToolButton = makeEraserToolButton()
        toolPairStack.axis = .horizontal
        toolPairStack.spacing = 10
        toolPairStack.alignment = .center
        toolPairStack.distribution = .fillEqually
        toolPairStack.addArrangedSubview(brushToolButton!)
        toolPairStack.addArrangedSubview(eraserToolButton!)
        toolPairStack.translatesAutoresizingMaskIntoConstraints = false

        // ── Crayons (custom horizontal wax crayons, scrollable) ─────────────
        crayonScrollContainer.translatesAutoresizingMaskIntoConstraints = false
        crayonScrollContainer.backgroundColor = .clear
        crayonScrollContainer.clipsToBounds = true
        crayonScrollContainer.setContentHuggingPriority(UILayoutPriority(1), for: .vertical)
        crayonScrollContainer.setContentCompressionResistancePriority(UILayoutPriority(1), for: .vertical)

        crayonScrollView.translatesAutoresizingMaskIntoConstraints = false
        crayonScrollView.showsVerticalScrollIndicator = true
        crayonScrollView.indicatorStyle = .default
        crayonScrollView.alwaysBounceVertical = true
        crayonScrollView.bounces = true
        crayonScrollView.isDirectionalLockEnabled = true
        crayonScrollView.isScrollEnabled = true
        crayonScrollView.decelerationRate = .normal
        crayonScrollView.contentInsetAdjustmentBehavior = .never
        crayonScrollView.automaticallyAdjustsScrollIndicatorInsets = false
        // Let the pan gesture cancel touches in crayons once the user moves (see CrayonPaletteScrollView).
        crayonScrollView.canCancelContentTouches = true
        crayonScrollView.delaysContentTouches = true
        crayonScrollView.clipsToBounds = true
        crayonScrollView.keyboardDismissMode = .onDrag
        crayonScrollView.panGestureRecognizer.cancelsTouchesInView = true

        crayonScrollContainer.addSubview(crayonScrollView)
        NSLayoutConstraint.activate([
            crayonScrollView.topAnchor.constraint(equalTo: crayonScrollContainer.topAnchor),
            crayonScrollView.leadingAnchor.constraint(equalTo: crayonScrollContainer.leadingAnchor),
            crayonScrollView.trailingAnchor.constraint(equalTo: crayonScrollContainer.trailingAnchor),
            crayonScrollView.bottomAnchor.constraint(equalTo: crayonScrollContainer.bottomAnchor),
            crayonScrollContainer.heightAnchor.constraint(greaterThanOrEqualToConstant: 120),
        ])

        crayonStack.axis = .vertical
        crayonStack.spacing = 7
        crayonStack.isLayoutMarginsRelativeArrangement = false
        crayonStack.alignment = .fill
        crayonStack.distribution = .fill
        crayonStack.translatesAutoresizingMaskIntoConstraints = false
        crayonScrollView.addSubview(crayonStack)
        NSLayoutConstraint.activate([
            crayonStack.topAnchor.constraint(equalTo: crayonScrollView.contentLayoutGuide.topAnchor),
            crayonStack.leadingAnchor.constraint(equalTo: crayonScrollView.contentLayoutGuide.leadingAnchor),
            crayonStack.trailingAnchor.constraint(equalTo: crayonScrollView.contentLayoutGuide.trailingAnchor),
            crayonStack.bottomAnchor.constraint(equalTo: crayonScrollView.contentLayoutGuide.bottomAnchor),
            crayonStack.widthAnchor.constraint(equalTo: crayonScrollView.frameLayoutGuide.widthAnchor),
        ])

        for paletteIndex in crayonPaletteDisplayOrder where palette.indices.contains(paletteIndex) {
            let c = MagicCrayonControl()
            c.tag = paletteIndex
            c.accessibilityLabel = paletteKidNames[paletteIndex.clamped(to: 0...(paletteKidNames.count - 1))]
            c.setColors(
                wax: palette[paletteIndex.clamped(to: 0...(palette.count - 1))],
                highlight: HorizontalCrayonShapeView.defaultHighlight(
                    for: palette[paletteIndex.clamped(to: 0...(palette.count - 1))]
                )
            )
            c.translatesAutoresizingMaskIntoConstraints = false
            c.heightAnchor.constraint(equalToConstant: 52).isActive = true
            c.addTarget(self, action: #selector(crayonTapped(_:)), for: .touchUpInside)
            crayonStack.addArrangedSubview(c)
            crayonControls.append(c)
        }

        // ── Mascot (brush character at the top) ──────────────────────────────
        let mascotImage = MascotReactionState.hello.loadImage()
            ?? MascotReactionState.neutral.loadImage()
            ?? UIImage(named: "BrushMascot01")
        mascotImageView.image = mascotImage
        mascotImageView.contentMode = .scaleAspectFit
        mascotImageView.clipsToBounds = false
        mascotImageView.translatesAutoresizingMaskIntoConstraints = false
        mascotImageView.heightAnchor.constraint(equalToConstant: 300).isActive = true
        mascotLipSync.attach(
            imageView: mascotImageView,
            closed: UIImage(named: "MascotTalkingMouthClosed")
                ?? MascotReactionState.talking.loadImage(),
            open: UIImage(named: "MascotTalkingMouthOpen")
                ?? MascotReactionState.happy.loadImage(),
            oMouth: UIImage(named: "MascotTalkingMouthO")
                ?? MascotReactionState.oMouth.loadImage()
        )

        let mascotContainer = UIView()
        mascotContainer.translatesAutoresizingMaskIntoConstraints = false
        mascotContainer.addSubview(mascotImageView)

        mascotPauseBadge.translatesAutoresizingMaskIntoConstraints = false
        mascotPauseBadge.font = FigmaTheme.bodyFont(size: 13, weight: .bold)
        mascotPauseBadge.textColor = .white
        mascotPauseBadge.textAlignment = .center
        mascotPauseBadge.backgroundColor = UIColor.black.withAlphaComponent(0.55)
        mascotPauseBadge.layer.cornerRadius = 12
        mascotPauseBadge.clipsToBounds = true
        mascotPauseBadge.isHidden = true
        mascotContainer.addSubview(mascotPauseBadge)

        let mascotTap = UITapGestureRecognizer(target: self, action: #selector(mascotTapped))
        mascotContainer.addGestureRecognizer(mascotTap)
        mascotContainer.isUserInteractionEnabled = true

        NSLayoutConstraint.activate([
            mascotImageView.centerXAnchor.constraint(equalTo: mascotContainer.centerXAnchor),
            mascotImageView.topAnchor.constraint(equalTo: mascotContainer.topAnchor, constant: -4),
            mascotImageView.bottomAnchor.constraint(equalTo: mascotContainer.bottomAnchor, constant: 4),
            mascotImageView.widthAnchor.constraint(lessThanOrEqualTo: mascotContainer.widthAnchor, multiplier: 0.98),

            mascotPauseBadge.centerXAnchor.constraint(equalTo: mascotContainer.centerXAnchor),
            mascotPauseBadge.bottomAnchor.constraint(equalTo: mascotContainer.bottomAnchor, constant: -8),
            mascotPauseBadge.widthAnchor.constraint(greaterThanOrEqualToConstant: 80),
            mascotPauseBadge.heightAnchor.constraint(equalToConstant: 26),
        ])

        // ── Right panel ───────────────────────────────────────────────────────
        let rightPanelStack = UIStackView(arrangedSubviews: [mascotContainer, toolPairStack, crayonScrollContainer])
        rightPanelStack.axis = .vertical
        rightPanelStack.spacing = 10
        rightPanelStack.distribution = .fill
        rightPanelStack.alignment = .fill
        rightPanelStack.translatesAutoresizingMaskIntoConstraints = false
        rightPanelStack.setContentHuggingPriority(.defaultHigh, for: .horizontal)
        rightPanelStack.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)

        // ── Top nav bar ───────────────────────────────────────────────────────
        func makeNavButton(icon: String, fill: UIColor, border: UIColor) -> UIButton {
            let b = UIButton(type: .system)
            var cfg = UIButton.Configuration.plain()
            cfg.image = UIImage(systemName: icon)
            cfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 20, weight: .bold)
            cfg.baseForegroundColor = .white
            b.configuration = cfg
            styleChromeButton(b, fill: fill, border: border, cornerRadius: 14)
            b.translatesAutoresizingMaskIntoConstraints = false
            b.widthAnchor.constraint(equalToConstant: 52).isActive = true
            b.heightAnchor.constraint(equalToConstant: 52).isActive = true
            return b
        }

        var homeCfg = UIButton.Configuration.plain()
        homeCfg.image = UIImage(systemName: "house.fill")
        homeCfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 22, weight: .bold)
        homeCfg.baseForegroundColor = .white
        homeButton.configuration = homeCfg
        styleChromeButton(homeButton, fill: FigmaTheme.primaryOrange, border: FigmaTheme.primaryOrangeBorder, cornerRadius: 14)
        homeButton.addTarget(self, action: #selector(homeTapped), for: .touchUpInside)
        homeButton.isHidden = navigationController == nil
        homeButton.translatesAutoresizingMaskIntoConstraints = false
        homeButton.widthAnchor.constraint(equalToConstant: 52).isActive = true
        homeButton.heightAnchor.constraint(equalToConstant: 52).isActive = true

        prevPageButton.addTarget(self, action: #selector(undoStroke), for: .touchUpInside)
        nextPageButton.addTarget(self, action: #selector(clearStrokes), for: .touchUpInside)
        doneButton.addTarget(self, action: #selector(requestFeedback), for: .touchUpInside)

        let prevBtn = makeNavButton(icon: "chevron.left", fill: FigmaTheme.actionBlue, border: FigmaTheme.actionBlueBorder)
        prevBtn.addTarget(self, action: #selector(undoStroke), for: .touchUpInside)
        let nextBtn = makeNavButton(icon: "chevron.right", fill: FigmaTheme.actionBlue, border: FigmaTheme.actionBlueBorder)
        nextBtn.addTarget(self, action: #selector(clearStrokes), for: .touchUpInside)
        // let doneBtn = makeNavButton(icon: "checkmark", ...) — checkmark button removed (no-op)

        let saveBtn = makeNavButton(icon: "square.and.arrow.down", fill: FigmaTheme.actionBlue, border: FigmaTheme.actionBlueBorder)
        saveBtn.accessibilityLabel = "Save to Photos"
        saveBtn.addTarget(self, action: #selector(saveColoringTapped), for: .touchUpInside)

        let navSpacer = UIView()
        navSpacer.setContentHuggingPriority(UILayoutPriority(1), for: .horizontal)
        toolRow.axis = .horizontal
        toolRow.spacing = 8
        toolRow.alignment = .center
        toolRow.addArrangedSubview(homeButton)
        toolRow.addArrangedSubview(prevBtn)
        toolRow.addArrangedSubview(nextBtn)
        toolRow.addArrangedSubview(saveBtn)
        toolRow.addArrangedSubview(navSpacer)
        modelStatusStack.isHidden = true

        let bar = UIStackView(arrangedSubviews: [toolRow])
        bar.axis = .vertical
        bar.spacing = 10

        // ── Canvas ────────────────────────────────────────────────────────────
        let canvasContainer = UIView()
        canvasContainer.translatesAutoresizingMaskIntoConstraints = false
        canvasContainer.backgroundColor = .clear

        templateView.translatesAutoresizingMaskIntoConstraints = false
        strokeView.translatesAutoresizingMaskIntoConstraints = false
        templateLineOverlayView.translatesAutoresizingMaskIntoConstraints = false
        templateLineOverlayView.contentMode = .scaleAspectFit
        templateLineOverlayView.clipsToBounds = true
        templateLineOverlayView.layer.cornerRadius = 24
        templateLineOverlayView.backgroundColor = .clear
        templateLineOverlayView.isUserInteractionEnabled = false

        resumeSnapshotView.translatesAutoresizingMaskIntoConstraints = false
        resumeSnapshotView.contentMode = .scaleAspectFit
        resumeSnapshotView.backgroundColor = .clear
        resumeSnapshotView.clipsToBounds = true
        resumeSnapshotView.isUserInteractionEnabled = false
        resumeSnapshotView.isHidden = true

        canvasContainer.addSubview(templateView)
        canvasContainer.addSubview(resumeSnapshotView)
        canvasContainer.addSubview(strokeView)
        canvasContainer.addSubview(templateLineOverlayView)

        strokeSizeStack.axis = .vertical
        strokeSizeStack.spacing = 5
        strokeSizeStack.alignment = .trailing
        strokeSizeStack.distribution = .fill
        strokeSizeStack.translatesAutoresizingMaskIntoConstraints = false
        strokeSizeStack.isUserInteractionEnabled = true
        let dotVisualDiameters: [CGFloat] = [8, 11, 13, 16, 19]
        strokeSizeButtons.removeAll()
        strokeSizeDotViews.removeAll()
        for i in 0..<min(5, strokeWidthPresets.count) {
            let b = makeStrokeSizeBlobButton(index: i, dotDiameter: dotVisualDiameters[i])
            strokeSizeButtons.append(b)
            strokeSizeStack.addArrangedSubview(b)
        }
        canvasContainer.addSubview(strokeSizeStack)
        NSLayoutConstraint.activate([
            strokeSizeStack.topAnchor.constraint(equalTo: canvasContainer.topAnchor, constant: 10),
            strokeSizeStack.trailingAnchor.constraint(equalTo: canvasContainer.trailingAnchor, constant: -10),
        ])

        let paintRow = UIStackView()
        paintRow.axis = .horizontal
        paintRow.alignment = .fill
        paintRow.spacing = 10
        paintRow.translatesAutoresizingMaskIntoConstraints = false
        canvasContainer.setContentHuggingPriority(.defaultLow, for: .horizontal)
        canvasContainer.setContentCompressionResistancePriority(.defaultLow, for: .horizontal)
        paintRow.addArrangedSubview(canvasContainer)
        paintRow.addArrangedSubview(rightPanelStack)

        pageControl.translatesAutoresizingMaskIntoConstraints = false
        bar.translatesAutoresizingMaskIntoConstraints = false
        paintRow.translatesAutoresizingMaskIntoConstraints = false

        let headerStack = UIStackView(arrangedSubviews: [bar])
        headerStack.axis = .vertical
        headerStack.spacing = 8
        headerStack.translatesAutoresizingMaskIntoConstraints = false
        headerStack.isLayoutMarginsRelativeArrangement = false
        headerStack.insetsLayoutMarginsFromSafeArea = false
        if !pageControl.isHidden {
            headerStack.insertArrangedSubview(pageControl, at: 0)
        }

        view.addSubview(skyView)
        view.addSubview(cloudContainer)
        view.addSubview(headerStack)
        view.addSubview(paintRow)

        installClouds()

        loadOverlay.translatesAutoresizingMaskIntoConstraints = false
        loadOverlay.backgroundColor = UIColor.black.withAlphaComponent(0.45)
        loadOverlay.isHidden = true
        loadOverlay.isUserInteractionEnabled = true
        loadLabel.translatesAutoresizingMaskIntoConstraints = false
        loadLabel.textColor = .white
        loadLabel.numberOfLines = 0
        loadLabel.font = .preferredFont(forTextStyle: .callout)
        loadLabel.textAlignment = .center
        loadProgress.translatesAutoresizingMaskIntoConstraints = false

        loadOverlay.addSubview(loadLabel)
        loadOverlay.addSubview(loadProgress)
        view.addSubview(loadOverlay)
        vlmInputPreviewImageView.translatesAutoresizingMaskIntoConstraints = false
        vlmInputPreviewImageView.contentMode = .scaleAspectFit
        vlmInputPreviewImageView.backgroundColor = UIColor.black.withAlphaComponent(0.65)
        vlmInputPreviewImageView.layer.cornerRadius = 10
        vlmInputPreviewImageView.layer.borderWidth = 1.5
        vlmInputPreviewImageView.layer.borderColor = UIColor.white.withAlphaComponent(0.8).cgColor
        vlmInputPreviewImageView.clipsToBounds = true
        vlmInputPreviewImageView.isHidden = true

        vlmInputPreviewLabel.translatesAutoresizingMaskIntoConstraints = false
        vlmInputPreviewLabel.font = .preferredFont(forTextStyle: .caption2)
        vlmInputPreviewLabel.textColor = .white
        vlmInputPreviewLabel.textAlignment = .center
        vlmInputPreviewLabel.numberOfLines = 2
        vlmInputPreviewLabel.backgroundColor = UIColor.black.withAlphaComponent(0.6)
        vlmInputPreviewLabel.layer.cornerRadius = 8
        vlmInputPreviewLabel.clipsToBounds = true
        vlmInputPreviewLabel.isHidden = true
        view.addSubview(vlmInputPreviewImageView)
        view.addSubview(vlmInputPreviewLabel)

        let canvasAspect = canvasContainer.widthAnchor.constraint(equalTo: canvasContainer.heightAnchor, multiplier: 4 / 5)
        canvasAspect.priority = .defaultHigh
        let rightPanelWidth = rightPanelStack.widthAnchor.constraint(equalToConstant: 172)
        rightPanelWidth.priority = .required

        NSLayoutConstraint.activate([
            skyView.topAnchor.constraint(equalTo: view.topAnchor),
            skyView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            skyView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            skyView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            cloudContainer.topAnchor.constraint(equalTo: view.topAnchor),
            cloudContainer.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            cloudContainer.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            cloudContainer.heightAnchor.constraint(equalTo: view.heightAnchor, multiplier: 0.55),

            headerStack.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: TopChromeMetrics.menuTopOffset),
            headerStack.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: TopChromeMetrics.menuHorizontalInset),
            headerStack.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -TopChromeMetrics.menuHorizontalInset),

            paintRow.topAnchor.constraint(equalTo: headerStack.bottomAnchor, constant: 8),
            paintRow.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 6),
            paintRow.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -6),
            paintRow.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -6),

            canvasContainer.heightAnchor.constraint(greaterThanOrEqualToConstant: 200),
            canvasAspect,
            rightPanelWidth,

            templateView.leadingAnchor.constraint(equalTo: canvasContainer.leadingAnchor),
            templateView.trailingAnchor.constraint(equalTo: canvasContainer.trailingAnchor),
            templateView.topAnchor.constraint(equalTo: canvasContainer.topAnchor),
            templateView.bottomAnchor.constraint(equalTo: canvasContainer.bottomAnchor),

            resumeSnapshotView.leadingAnchor.constraint(equalTo: templateView.leadingAnchor),
            resumeSnapshotView.trailingAnchor.constraint(equalTo: templateView.trailingAnchor),
            resumeSnapshotView.topAnchor.constraint(equalTo: templateView.topAnchor),
            resumeSnapshotView.bottomAnchor.constraint(equalTo: templateView.bottomAnchor),

            strokeView.leadingAnchor.constraint(equalTo: templateView.leadingAnchor),
            strokeView.trailingAnchor.constraint(equalTo: templateView.trailingAnchor),
            strokeView.topAnchor.constraint(equalTo: templateView.topAnchor),
            strokeView.bottomAnchor.constraint(equalTo: templateView.bottomAnchor),

            templateLineOverlayView.leadingAnchor.constraint(equalTo: templateView.leadingAnchor),
            templateLineOverlayView.trailingAnchor.constraint(equalTo: templateView.trailingAnchor),
            templateLineOverlayView.topAnchor.constraint(equalTo: templateView.topAnchor),
            templateLineOverlayView.bottomAnchor.constraint(equalTo: templateView.bottomAnchor),

            loadOverlay.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            loadOverlay.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            loadOverlay.topAnchor.constraint(equalTo: view.topAnchor),
            loadOverlay.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            loadLabel.centerXAnchor.constraint(equalTo: loadOverlay.centerXAnchor),
            loadLabel.centerYAnchor.constraint(equalTo: loadOverlay.centerYAnchor, constant: -20),
            loadLabel.leadingAnchor.constraint(greaterThanOrEqualTo: loadOverlay.leadingAnchor, constant: 24),
            loadLabel.trailingAnchor.constraint(lessThanOrEqualTo: loadOverlay.trailingAnchor, constant: -24),

            loadProgress.topAnchor.constraint(equalTo: loadLabel.bottomAnchor, constant: 12),
            loadProgress.leadingAnchor.constraint(equalTo: loadOverlay.leadingAnchor, constant: 48),
            loadProgress.trailingAnchor.constraint(equalTo: loadOverlay.trailingAnchor, constant: -48),

            vlmInputPreviewImageView.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 14),
            vlmInputPreviewImageView.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -14),
            vlmInputPreviewImageView.widthAnchor.constraint(equalToConstant: 112),
            vlmInputPreviewImageView.heightAnchor.constraint(equalToConstant: 112),

            vlmInputPreviewLabel.leadingAnchor.constraint(equalTo: vlmInputPreviewImageView.leadingAnchor),
            vlmInputPreviewLabel.trailingAnchor.constraint(equalTo: vlmInputPreviewImageView.trailingAnchor),
            vlmInputPreviewLabel.bottomAnchor.constraint(equalTo: vlmInputPreviewImageView.topAnchor, constant: -6),
        ])

        let start = pinnedPageIndex ?? 0
        pageIndex = min(max(0, start), max(0, coloringBookPages.count - 1))

        strokeView.onPaintingBegan = { [weak self] in
            self?.onColoringStrokeBegan()
        }
        strokeView.onCommittedStrokeEnded = { [weak self] in
            // self?.scheduleDebouncedStrokeReaction()  // legacy: separate reaction VLM; mascot pose now comes from combined prompt with coach line
            self?.scheduleFeedbackIdleTimer()
        }
        applyToolMode()
        refreshCrayonSelection(animated: false)

        view.bringSubviewToFront(loadOverlay)
    }

    /// Removes the default gray “track” / hairline on `UISegmentedControl` so it blends with the sky background.
    private func styleSkySegmentedPagePicker(_ sc: UISegmentedControl) {
        let sky = FigmaTheme.skyBlue
        sc.backgroundColor = sky
        sc.clipsToBounds = false
        sc.layer.borderWidth = 0
        sc.layer.cornerRadius = 0
        sc.apportionsSegmentWidthsByContent = true

        let normalAttrs: [NSAttributedString.Key: Any] = [
            .foregroundColor: FigmaTheme.coastTitle,
            .font: FigmaTheme.bodyFont(size: 13, weight: .semibold),
        ]
        let selectedAttrs: [NSAttributedString.Key: Any] = [
            .foregroundColor: UIColor.white,
            .font: FigmaTheme.bodyFont(size: 13, weight: .semibold),
        ]
        sc.setTitleTextAttributes(normalAttrs, for: .normal)
        sc.setTitleTextAttributes(selectedAttrs, for: .selected)

        let empty = UIImage()
        sc.setBackgroundImage(empty, for: .normal, barMetrics: .default)
        sc.setBackgroundImage(empty, for: .selected, barMetrics: .default)
        sc.setBackgroundImage(empty, for: .highlighted, barMetrics: .default)
        sc.setBackgroundImage(empty, for: .disabled, barMetrics: .default)
        sc.setDividerImage(empty, forLeftSegmentState: .normal, rightSegmentState: .normal, barMetrics: .default)
        sc.setDividerImage(empty, forLeftSegmentState: .selected, rightSegmentState: .normal, barMetrics: .default)
        sc.setDividerImage(empty, forLeftSegmentState: .normal, rightSegmentState: .selected, barMetrics: .default)

        if #available(iOS 13.0, *) {
            sc.selectedSegmentTintColor = FigmaTheme.actionBlue
        }
    }

    private func styleChromeButton(_ button: UIButton, fill: UIColor, border: UIColor, cornerRadius: CGFloat = 12) {
        button.backgroundColor = fill
        button.layer.cornerRadius = cornerRadius
        button.layer.borderWidth = 4
        button.layer.borderColor = border.cgColor
        button.tintColor = .white
        button.contentEdgeInsets = UIEdgeInsets(top: 8, left: 10, bottom: 8, right: 10)
        button.layer.shadowColor = UIColor.black.cgColor
        button.layer.shadowOpacity = 0.18
        button.layer.shadowRadius = 4
        button.layer.shadowOffset = CGSize(width: 0, height: 2)
    }

    /// Rounded “paint blob” matching nav chrome size; inner dot shows relative thickness.
    private func makeStrokeSizeBlobButton(index: Int, dotDiameter: CGFloat) -> UIButton {
        let b = UIButton(type: .custom)
        b.tag = index
        b.translatesAutoresizingMaskIntoConstraints = false
        b.layer.cornerRadius = 26
        b.clipsToBounds = false
        b.accessibilityLabel = "Brush size \(index + 1) of \(strokeWidthPresets.count)"
        b.accessibilityHint = "Pick how thick your paint is"
        b.widthAnchor.constraint(equalToConstant: 52).isActive = true
        b.heightAnchor.constraint(equalToConstant: 52).isActive = true
        b.layer.shadowColor = UIColor.black.cgColor
        b.layer.shadowOpacity = 0.2
        b.layer.shadowRadius = 4
        b.layer.shadowOffset = CGSize(width: 0, height: 2)

        let dot = UIView()
        dot.translatesAutoresizingMaskIntoConstraints = false
        dot.backgroundColor = UIColor.white.withAlphaComponent(0.92)
        dot.layer.cornerRadius = dotDiameter * 0.5
        dot.isUserInteractionEnabled = false
        b.addSubview(dot)
        strokeSizeDotViews.append(dot)
        NSLayoutConstraint.activate([
            dot.centerXAnchor.constraint(equalTo: b.centerXAnchor),
            dot.centerYAnchor.constraint(equalTo: b.centerYAnchor, constant: 1),
            dot.widthAnchor.constraint(equalToConstant: dotDiameter),
            dot.heightAnchor.constraint(equalToConstant: dotDiameter),
        ])

        let gloss = UIView()
        gloss.translatesAutoresizingMaskIntoConstraints = false
        gloss.backgroundColor = UIColor.white.withAlphaComponent(0.35)
        gloss.layer.cornerRadius = 5
        gloss.isUserInteractionEnabled = false
        b.addSubview(gloss)
        NSLayoutConstraint.activate([
            gloss.leadingAnchor.constraint(equalTo: b.leadingAnchor, constant: 10),
            gloss.topAnchor.constraint(equalTo: b.topAnchor, constant: 8),
            gloss.widthAnchor.constraint(equalToConstant: 14),
            gloss.heightAnchor.constraint(equalToConstant: 8),
        ])

        b.addTarget(self, action: #selector(strokeSizeTouchDown(_:)), for: .touchDown)
        b.addTarget(self, action: #selector(strokeSizeTouchUp(_:)), for: [.touchUpInside, .touchCancel, .touchDragExit])
        b.addTarget(self, action: #selector(strokeSizeButtonTapped(_:)), for: .touchUpInside)
        return b
    }

    private func refreshStrokeSizeAppearance() {
        let presets = strokeWidthPresets
        guard !strokeSizeButtons.isEmpty else { return }
        let cIdx = strokePaletteIndex.clamped(to: 0...(palette.count - 1))
        let crayon = palette[cIdx]
        let rim = crayon.magicBrushyStrokeChromeBorder()
        for (i, b) in strokeSizeButtons.enumerated() {
            let on = i == selectedStrokeSizeIndex
            b.backgroundColor = crayon.withAlphaComponent(on ? 1 : 0.7)
            b.layer.borderWidth = on ? 4 : 2.5
            b.layer.borderColor = (on ? UIColor.white : rim).cgColor
            let scale: CGFloat = on ? 1.06 : 1
            b.transform = CGAffineTransform(scaleX: scale, y: scale)
            if i < strokeSizeDotViews.count {
                strokeSizeDotViews[i].backgroundColor = UIColor.white.withAlphaComponent(on ? 1 : 0.88)
            }
            if i < presets.count {
                b.accessibilityValue = "\(Int(presets[i])) points wide"
                b.accessibilityTraits = on ? [.button, .selected] : .button
            }
        }
    }

    private func applyStrokeWidthFromSelection() {
        let i = selectedStrokeSizeIndex.clamped(to: 0...(strokeWidthPresets.count - 1))
        strokeView.strokeWidth = strokeWidthPresets[i]
    }

    private func makeBrushToolButton() -> UIButton {
        let b = UIButton(type: .custom)
        b.tag = 0
        styleChromeButton(b, fill: FigmaTheme.primaryOrange, border: FigmaTheme.primaryOrangeBorder, cornerRadius: 14)
        if let img = UIImage(named: "FigmaBrush") {
            let iv = UIImageView(image: img)
            iv.contentMode = .scaleAspectFit
            iv.translatesAutoresizingMaskIntoConstraints = false
            iv.isUserInteractionEnabled = false
            b.addSubview(iv)
            NSLayoutConstraint.activate([
                iv.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                iv.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                iv.widthAnchor.constraint(equalToConstant: 38),
                iv.heightAnchor.constraint(equalToConstant: 38),
            ])
        } else {
            let icon = PaintBrushIconView()
            icon.translatesAutoresizingMaskIntoConstraints = false
            icon.isUserInteractionEnabled = false
            b.addSubview(icon)
            NSLayoutConstraint.activate([
                icon.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                icon.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                icon.widthAnchor.constraint(equalToConstant: 36),
                icon.heightAnchor.constraint(equalToConstant: 36),
            ])
        }
        b.addTarget(self, action: #selector(toolModeTapped(_:)), for: .touchUpInside)
        b.translatesAutoresizingMaskIntoConstraints = false
        b.heightAnchor.constraint(equalToConstant: 62).isActive = true
        return b
    }

    private func makeEraserToolButton() -> UIButton {
        let b = UIButton(type: .custom)
        b.tag = 1
        // Orange chrome (matches app palette; distinct from solid brush button).
        let fill = UIColor(red: 1, green: 0.93, blue: 0.86, alpha: 1)
        styleChromeButton(b, fill: fill, border: FigmaTheme.primaryOrangeBorder, cornerRadius: 14)
        b.layer.borderWidth = 5
        b.layer.shadowOpacity = 0.28
        b.layer.shadowRadius = 5
        if let img = UIImage(named: "FigmaEraser") {
            let iv = UIImageView(image: img)
            iv.contentMode = .scaleAspectFit
            iv.translatesAutoresizingMaskIntoConstraints = false
            iv.isUserInteractionEnabled = false
            b.addSubview(iv)
            NSLayoutConstraint.activate([
                iv.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                iv.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                iv.widthAnchor.constraint(equalToConstant: 38),
                iv.heightAnchor.constraint(equalToConstant: 38),
            ])
        } else {
            let icon = EraserIconView()
            icon.translatesAutoresizingMaskIntoConstraints = false
            icon.isUserInteractionEnabled = false
            b.addSubview(icon)
            NSLayoutConstraint.activate([
                icon.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                icon.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                icon.widthAnchor.constraint(equalToConstant: 34),
                icon.heightAnchor.constraint(equalToConstant: 34),
            ])
        }
        b.addTarget(self, action: #selector(toolModeTapped(_:)), for: .touchUpInside)
        b.translatesAutoresizingMaskIntoConstraints = false
        b.heightAnchor.constraint(equalToConstant: 62).isActive = true
        return b
    }

    private func installClouds() {
        cloudContainer.subviews.forEach { $0.removeFromSuperview() }
        func makeCloud() -> UIImageView {
            let iv = UIImageView(image: UIImage(systemName: "cloud.fill"))
            iv.tintColor = UIColor.white.withAlphaComponent(0.9)
            iv.contentMode = .scaleAspectFit
            iv.translatesAutoresizingMaskIntoConstraints = false
            return iv
        }
        let c1 = makeCloud()
        let c2 = makeCloud()
        let c3 = makeCloud()
        cloudContainer.addSubview(c1)
        cloudContainer.addSubview(c2)
        cloudContainer.addSubview(c3)
        NSLayoutConstraint.activate([
            c1.leadingAnchor.constraint(equalTo: cloudContainer.leadingAnchor, constant: 6),
            c1.topAnchor.constraint(equalTo: cloudContainer.topAnchor, constant: 8),
            c1.widthAnchor.constraint(equalTo: cloudContainer.widthAnchor, multiplier: 0.42),
            c1.heightAnchor.constraint(equalTo: c1.widthAnchor, multiplier: 0.55),

            c2.leadingAnchor.constraint(equalTo: c1.trailingAnchor, constant: -36),
            c2.topAnchor.constraint(equalTo: cloudContainer.topAnchor, constant: 22),
            c2.widthAnchor.constraint(equalTo: cloudContainer.widthAnchor, multiplier: 0.36),
            c2.heightAnchor.constraint(equalTo: c2.widthAnchor, multiplier: 0.55),

            c3.trailingAnchor.constraint(equalTo: cloudContainer.trailingAnchor, constant: -4),
            c3.topAnchor.constraint(equalTo: cloudContainer.topAnchor, constant: 36),
            c3.widthAnchor.constraint(equalTo: cloudContainer.widthAnchor, multiplier: 0.34),
            c3.heightAnchor.constraint(equalTo: c3.widthAnchor, multiplier: 0.55),
        ])
    }

    @objc private func homeTapped() {
        if let packId = sessionPackId,
           strokeView.hasUserPaint,
           coloringBookPages.indices.contains(pageIndex) {
            let title = coloringBookPages[pageIndex].title
            let pxScale = view.window?.screen.scale ?? UIScreen.main.scale
            // Legacy flat resume hides the line overlay; outlines live inside the JPEG — no true line-free underlay to save.
            let canSaveLineFreeUnderlay = resumeSnapshotView.isHidden || !templateLineOverlayView.isHidden
            let composite = captureCanvasForExport()
            let underlay = canSaveLineFreeUnderlay
                ? captureCanvasBitmap(includeLineOverlay: false, displayScale: pxScale)
                : nil
            let continueTargetId = continuingSavedDrawingId ?? LastDrawingStore.peekContinueDrawingSessionId()
            if let existingId = continueTargetId {
                let didUpdate = LastDrawingStore.updateRecord(
                    id: existingId,
                    packId: packId,
                    pageIndex: pageIndex,
                    pageTitle: title,
                    composite: composite,
                    resumeUnderlay: underlay
                )
                if !didUpdate {
                    _ = LastDrawingStore.save(
                        packId: packId,
                        pageIndex: pageIndex,
                        pageTitle: title,
                        composite: composite,
                        resumeUnderlay: underlay
                    )
                }
                continuingSavedDrawingId = nil
            } else {
                _ = LastDrawingStore.save(
                    packId: packId,
                    pageIndex: pageIndex,
                    pageTitle: title,
                    composite: composite,
                    resumeUnderlay: underlay
                )
            }
            LastDrawingStore.clearContinueDrawingSession()
        }
        navigationController?.popToRootViewController(animated: true)
    }

    @objc private func toolModeTapped(_ sender: UIButton) {
        isEraserMode = sender.tag == 1
        applyToolMode()
        refreshCrayonSelection(animated: true)
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }

    @objc private func crayonTapped(_ sender: MagicCrayonControl) {
        strokePaletteIndex = sender.tag.clamped(to: 0...(palette.count - 1))
        isEraserMode = false
        applyToolMode()
        refreshCrayonSelection(animated: true)
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }

    private func refreshCrayonSelection(animated: Bool) {
        for c in crayonControls {
            let on = c.tag == strokePaletteIndex && !isEraserMode
            c.setSelected(on, animated: animated)
        }
        refreshStrokeSizeAppearance()
    }

    private func applyToolMode() {
        applyStrokeWidthFromSelection()
        if isEraserMode {
            strokeView.strokeColor = .white
        } else {
            let i = strokePaletteIndex.clamped(to: 0...(palette.count - 1))
            strokeView.strokeColor = palette[i]
        }
        brushToolButton?.alpha = isEraserMode ? 0.55 : 1.0
        eraserToolButton?.alpha = isEraserMode ? 1.0 : 0.95
    }

    deinit {
        pollTimer?.invalidate()
        cancelFeedbackIdleTimer()
        pauseCountdownTimer?.invalidate()
        NotificationCenter.default.removeObserver(self)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Keep the shared model loaded; only stop active generation on this screen.
        vlm.cancel()
        refreshModelStatusIndicator()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        navigationController?.view.backgroundColor = FigmaTheme.skyBlue
        if let nav = navigationController {
            let barAppearance = UINavigationBarAppearance()
            barAppearance.configureWithTransparentBackground()
            barAppearance.shadowColor = .clear
            barAppearance.shadowImage = UIImage()
            nav.navigationBar.standardAppearance = barAppearance
            nav.navigationBar.scrollEdgeAppearance = barAppearance
            nav.navigationBar.compactAppearance = barAppearance
            if #available(iOS 15.0, *) {
                nav.navigationBar.compactScrollEdgeAppearance = barAppearance
            }
            nav.navigationBar.setBackgroundImage(UIImage(), for: .default)
            nav.navigationBar.shadowImage = UIImage()
        }
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        hideFullWidthHairlineUnderStatusBarIfNeeded()
        applyPendingResumeCompositeIfNeeded()
    }

    /// Some `UISegmentedControl` builds add a ~1pt tall full-width separator along the **top** edge; hide it after layout.
    private func hideFullWidthHairlineUnderStatusBarIfNeeded() {
        guard !pageControl.isHidden, pageControl.bounds.width > 10 else { return }
        for sub in pageControl.subviews {
            let w = sub.bounds.width
            let h = sub.bounds.height
            let top = sub.frame.minY
            guard h > 0, h <= 2.5, w >= pageControl.bounds.width * 0.88, top < 4 else { continue }
            sub.isHidden = true
        }
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        // First `viewDidLayoutSubviews` can run before the canvas has final bounds; apply resume once geometry is stable.
        view.layoutIfNeeded()
        applyPendingResumeCompositeIfNeeded()
        FeedbackAlbaSpeech.mascotLipSync = mascotLipSync
        if pollTimer == nil {
            startPollingVLMUi()
        }
        _ = modelForInference()
        refreshModelStatusIndicator()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if isMovingFromParent {
            LastDrawingStore.clearContinueDrawingSession()
        }
        FeedbackAlbaSpeech.stopSpeaking()
        FeedbackAlbaSpeech.mascotLipSync = nil
        // Cancel in-flight coach inference so the next screen / page starts clean (each `generate` uses a new conversation).
        invalidateFeedbackSession()
        pollTimer?.invalidate()
        pollTimer = nil
    }

    private func startPollingVLMUi() {
        pollTimer?.invalidate()
        let t = Timer(timeInterval: 0.5, repeats: true) { [weak self] _ in
            Task { @MainActor [weak self] in
                self?.applyObservationSnapshot()
            }
        }
        RunLoop.main.add(t, forMode: .common)
        pollTimer = t
    }

    private func modelForInference() -> LeapVLMModel {
        vlm.onModelLoadPanelStateChanged = { [weak self] in
            DispatchQueue.main.async {
                self?.refreshModelStatusIndicator()
            }
        }
        return vlm
    }

    private func cancelFeedbackIdleTimer() {
        pendingAutoFeedbackWork?.cancel()
        pendingAutoFeedbackWork = nil
    }

    private func cancelPendingReactionWork() {
        pendingReactionWork?.cancel()
        pendingReactionWork = nil
    }

    /// Full reset: page / clear / undo — drop pending mascot reaction and all VLM work.
    private func invalidateFeedbackSession() {
        feedbackGeneration &+= 1
        reactionSession &+= 1
        lastMascotReaction = nil
        cancelFeedbackIdleTimer()
        cancelPendingReactionWork()
        vlm.cancel()
        hideVLMInputPreviewImmediate()
    }

    /// New stroke started — stop deferred **speech** and cancel in-flight VLM, but keep the debounced **reaction** work item
    /// so a lift → short pause → new stroke does not lose `feedbackGeneration` before the reaction task runs.
    private func invalidatePaintingFeedbackOnly() {
        feedbackGeneration &+= 1
        cancelFeedbackIdleTimer()
        vlm.cancel()
        hideVLMInputPreviewImmediate()
    }

    private func onColoringStrokeBegan() {
        invalidatePaintingFeedbackOnly()
        FeedbackAlbaSpeech.stopSpeaking()
    }

    /*
    private func scheduleDebouncedStrokeReaction() {
        cancelPendingReactionWork()
        guard !strokeView.chronologicalStrokeColors.isEmpty else { return }
        let snap = reactionSession
        let work = DispatchWorkItem { [weak self] in
            guard let self else { return }
            self.pendingReactionWork = nil
            self.runReactionOnlyPipeline(reactionSnap: snap)
        }
        pendingReactionWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + Self.reactionDebounceDelay, execute: work)
    }
    */

    private func scheduleFeedbackIdleTimer() {
        cancelFeedbackIdleTimer()
        guard !strokeView.chronologicalStrokeColors.isEmpty else { return }
        // Mascot-mute: skip auto-feedback while paused.
        if let until = feedbackPausedUntil, Date() < until { return }

        let work = DispatchWorkItem { [weak self] in
            guard let self else { return }
            self.pendingAutoFeedbackWork = nil
            // Re-check pause at fire time (user may have muted after stroke ended).
            if let until = self.feedbackPausedUntil, Date() < until { return }
            self.runSpeechFeedbackPipeline()
        }
        pendingAutoFeedbackWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + Self.feedbackIdleTriggerDelay, execute: work)
    }

    private static let feedbackPauseDuration: TimeInterval = 60

    @objc private func mascotTapped() {
        let now = Date()
        // If already paused and still within the window, tapping again cancels the pause early.
        if let until = feedbackPausedUntil, now < until {
            feedbackPausedUntil = nil
            updateMascotPauseBadge()
            applyMascotReaction(.hello)
            UIImpactFeedbackGenerator(style: .light).impactOccurred()
            return
        }

        feedbackPausedUntil = now.addingTimeInterval(Self.feedbackPauseDuration)
        cancelFeedbackIdleTimer()
        cancelPendingReactionWork()
        vlm.cancel()
        UIImpactFeedbackGenerator(style: .medium).impactOccurred()
        applyMascotReaction(.sleepy)
        updateMascotPauseBadge()
        scheduleMascotPauseCountdown()
    }

    private var pauseCountdownTimer: Timer?

    private func scheduleMascotPauseCountdown() {
        pauseCountdownTimer?.invalidate()
        pauseCountdownTimer = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { [weak self] t in
            guard let self else { t.invalidate(); return }
            self.updateMascotPauseBadge()
            if self.feedbackPausedUntil == nil || Date() >= (self.feedbackPausedUntil ?? Date()) {
                self.feedbackPausedUntil = nil
                self.updateMascotPauseBadge()
                self.applyMascotReaction(.hello)
                t.invalidate()
                self.pauseCountdownTimer = nil
            }
        }
    }

    private func updateMascotPauseBadge() {
        guard let until = feedbackPausedUntil, Date() < until else {
            mascotPauseBadge.isHidden = true
            return
        }
        let secs = max(0, Int(until.timeIntervalSinceNow.rounded(.up)))
        mascotPauseBadge.text = "🤫 \(secs)s"
        mascotPauseBadge.isHidden = false
    }

    private func applyObservationSnapshot() {
        refreshModelStatusIndicator()
    }

    private func refreshModelStatusIndicator() {
        if vlm.running {
            modelStatusDot.backgroundColor = .systemBlue
            modelStatusLabel.text = "AI: Thinking…"
            modelStatusStack.accessibilityLabel = "Art coach model is generating feedback"
            return
        }

        switch vlm.modelBadgeState {
        case .idleNotLoaded:
            modelStatusDot.backgroundColor = UIColor.tertiaryLabel.withAlphaComponent(0.85)
            modelStatusLabel.text = "AI: Idle"
            modelStatusStack.accessibilityLabel = "Art coach model not loaded yet"
        case .downloading(let p):
            let pct = Int((p * 100).rounded(.down))
            modelStatusDot.backgroundColor = .systemBlue
            modelStatusLabel.text = "AI: Assets \(pct)%"
            modelStatusStack.accessibilityLabel = "Loading and downloading assets, \(pct) percent complete"
        case .loadingIntoMemory:
            modelStatusDot.backgroundColor = .systemBlue
            modelStatusLabel.text = "AI: Preparing…"
            modelStatusStack.accessibilityLabel = "Preparing assets"
        case .ready:
            modelStatusDot.backgroundColor = .systemGreen
            modelStatusLabel.text = "AI: Ready"
            modelStatusStack.accessibilityLabel = "Art coach model is ready"
        case .failed(let message):
            modelStatusDot.backgroundColor = .systemRed
            modelStatusLabel.text = "AI: Error"
            modelStatusStack.accessibilityLabel = "Art coach model failed: \(message)"
        case .simulatorPreview:
            modelStatusDot.backgroundColor = .systemOrange
            modelStatusLabel.text = "AI: Simulator"
            modelStatusStack.accessibilityLabel = "Simulator build; on-device model is not loaded"
        }
    }

    /// Full-screen model download UI lives on `HomeViewController` only; keep chrome unobstructed here.
    private func refreshLoadOverlay() {
        loadOverlay.isHidden = true
        loadOverlay.isUserInteractionEnabled = false
    }

    @objc private func pageChanged() {
        pageIndex = pageControl.selectedSegmentIndex
    }

    private func clearResumeSnapshot() {
        resumeSnapshotView.image = nil
        resumeSnapshotView.isHidden = true
        resumeSnapshotView.contentMode = .scaleAspectFit
        templateLineOverlayView.contentMode = .scaleAspectFit
        templateView.isHidden = false
        templateLineOverlayView.isHidden = false
    }

    private func applyPendingResumeCompositeIfNeeded() {
        guard !didConsumePendingResumeComposite, let img = pendingResumeComposite else { return }
        // Match on-screen + `captureCanvasBitmap`: aspect-fit art inside the canvas (same as `templateView`).
        let b = strokeView.bounds
        guard b.width > 1, b.height > 1 else { return }
        didConsumePendingResumeComposite = true
        let separateLines = pendingResumeHasSeparateLineOverlay
        pendingResumeComposite = nil
        pendingResumeHasSeparateLineOverlay = false
        resumeSnapshotView.contentMode = .scaleAspectFit
        if separateLines {
            templateLineOverlayView.contentMode = .scaleAspectFit
        }
        resumeSnapshotView.image = img
        resumeSnapshotView.isHidden = false
        templateView.isHidden = true
        templateLineOverlayView.isHidden = !separateLines
    }

    private func applyCurrentPage() {
        guard pageIndex >= 0, pageIndex < coloringBookPages.count else { return }
        clearResumeSnapshot()
        if !pageControl.isHidden {
            pageControl.selectedSegmentIndex = pageIndex
        }
        FeedbackAlbaSpeech.stopSpeaking()
        invalidateFeedbackSession()
        let page = coloringBookPages[pageIndex]
        templateView.image = page.image
        templateLineOverlayView.image = page.image.magicBrushyLineArtOverlay()
        strokeView.clearStrokes()
    }

    @objc private func strokeSizeTouchDown(_ sender: UIButton) {
        UIView.animate(withDuration: 0.12, delay: 0, options: [.curveEaseIn]) {
            sender.transform = sender.transform.scaledBy(x: 0.92, y: 0.92)
        }
    }

    @objc private func strokeSizeTouchUp(_ sender: UIButton) {
        refreshStrokeSizeAppearance()
    }

    @objc private func strokeSizeButtonTapped(_ sender: UIButton) {
        let i = sender.tag.clamped(to: 0...(strokeWidthPresets.count - 1))
        guard i != selectedStrokeSizeIndex else { return }
        selectedStrokeSizeIndex = i
        applyStrokeWidthFromSelection()
        refreshStrokeSizeAppearance()
        UIImpactFeedbackGenerator(style: .medium).impactOccurred()
    }

    @objc private func clearStrokes() {
        invalidateFeedbackSession()
        FeedbackAlbaSpeech.stopSpeaking()
        strokeView.clearStrokes()
    }

    @objc private func undoStroke() {
        invalidateFeedbackSession()
        FeedbackAlbaSpeech.stopSpeaking()
        strokeView.undoLastStroke()
    }

    @objc private func requestFeedback() {
        cancelFeedbackIdleTimer()
        cancelPendingReactionWork()
        reactionSession &+= 1
        FeedbackAlbaSpeech.stopSpeaking()
        runFeedbackPipeline()
    }

    /*
    /// Legacy: mascot reaction only (second VLM). Superseded by `Reaction.combinedCoachPrompt` + single `generate`.
    private func runReactionOnlyPipeline(reactionSnap: UInt64) {
        Task { @MainActor [weak self] in
            guard let self else { return }
            guard reactionSnap == self.reactionSession else { return }
            let model = self.modelForInference()
            var spins = 0
            while model.running, spins < 120 {
                try? await Task.sleep(nanoseconds: 80_000_000)
                spins += 1
            }
            guard !model.running else { return }
            guard reactionSnap == self.reactionSession else { return }
            guard !self.strokeView.chronologicalStrokeColors.isEmpty else { return }
            self.view.layoutIfNeeded()
            let bounds = self.strokeView.bounds
            guard bounds.width >= 16, bounds.height >= 16 else { return }

            let img = self.captureCanvasForVLM()
            let previewImage = model.prepareImageForModelPreview(img) ?? img
            self.showVLMInputPreview(previewImage)
            let reactionPrompt = Reaction.classificationPrompt()

            model.maxTokens = 64
            let reactionTask = await model.generate(
                image: previewImage,
                prompt: reactionPrompt,
                maxOutputTokens: 32
            )
            await reactionTask.value

            guard reactionSnap == self.reactionSession else { return }
            if let pose = Reaction.parseMascotReaction(from: model.output) {
                self.applyMascotReaction(pose)
            }
        }
    }
    */

    /// After idle: original coach-only VLM; mascot pose from that same reply.
    private func runSpeechFeedbackPipeline() {
        let gen = feedbackGeneration
        runCoachFeedbackVLM(feedbackGen: gen, requireStrokeHistory: true)
    }

    /// Checkmark: same original coach-only VLM + mascot from reply.
    private func runFeedbackPipeline() {
        let gen = feedbackGeneration
        runCoachFeedbackVLM(feedbackGen: gen, requireStrokeHistory: false)
    }

    private func runCoachFeedbackVLM(feedbackGen: UInt64, requireStrokeHistory: Bool) {
        Task { @MainActor [weak self] in
            guard let self else { return }
            let model = self.modelForInference()
            var spins = 0
            while model.running, spins < 120 {
                try? await Task.sleep(nanoseconds: 80_000_000)
                spins += 1
            }
            guard !model.running else { return }
            guard feedbackGen == self.feedbackGeneration else { return }
            if requireStrokeHistory {
                guard !self.strokeView.chronologicalStrokeColors.isEmpty else { return }
            }
            self.view.layoutIfNeeded()
            let bounds = self.strokeView.bounds
            guard bounds.width >= 16, bounds.height >= 16 else { return }

            let img = self.captureCanvasForVLM()
            let previewImage = model.prepareImageForModelPreview(img) ?? img
            // self.showVLMInputPreview(previewImage)
            let prompt = self.composeFeedbackPrompt()

            model.maxTokens = 120
            #if DEBUG
            print("""
            [Brushi][VLM][Feedback] image \(Int(img.size.width))x\(Int(img.size.height)), max tokens 96
            \(prompt)
            """)
            #endif
            let task = await model.generate(
                image: previewImage,
                prompt: prompt,
                maxOutputTokens: 96
            )
            await task.value

            guard feedbackGen == self.feedbackGeneration else { return }
            let raw = model.output.trimmingCharacters(in: .whitespacesAndNewlines)
            let pose = Reaction.mascotPoseFromCoachResponse(raw, avoidingRepeatOf: self.lastMascotReaction)
            self.applyMascotReaction(pose)

            let spoken = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(raw)
            guard !spoken.isEmpty, spoken != "…",
                  !spoken.hasPrefix("Failed:") else { return }
            await FeedbackAlbaSpeech.speakFeedback(spoken)
        }
    }

    private func applyMascotReaction(_ state: MascotReactionState) {
        guard let image = state.loadImage() else { return }
        lastMascotReaction = state
        UIView.transition(with: mascotImageView, duration: 0.22, options: .transitionCrossDissolve) {
            self.mascotImageView.image = image
        }
    }

    /// Pixels of `image` laid out like `UIImageView` with **aspect fit** inside `bounds` (matches `templateView` on screen).
    private func aspectFitRect(for image: UIImage, in bounds: CGRect) -> CGRect {
        let sz = image.size
        guard sz.width > 0.5, sz.height > 0.5, bounds.width > 0.5, bounds.height > 0.5 else { return bounds }
        let scale = min(bounds.width / sz.width, bounds.height / sz.height)
        let w = sz.width * scale
        let h = sz.height * scale
        return CGRect(
            x: bounds.midX - w * 0.5,
            y: bounds.midY - h * 0.5,
            width: w,
            height: h
        )
    }

    /// Renders template and/or resume underlay, live strokes, and optionally line art (same stacking as on screen when the overlay is visible).
    /// - Parameters:
    ///   - includeLineOverlay: When false, produces a resume underlay (no black outlines) so outlines can stay in `templateLineOverlayView` above strokes.
    ///   - displayScale: `1` keeps VLM captures smaller; use screen scale for Photos export.
    private func captureCanvasBitmap(includeLineOverlay: Bool, displayScale: CGFloat) -> UIImage {
        view.layoutIfNeeded()
        let size = strokeView.bounds.size
        guard size.width > 1, size.height > 1 else {
            return strokeView.snapshotComposite(
                underneath: templateView.image,
                lineOverlay: includeLineOverlay ? templateLineOverlayView.image : nil,
                in: strokeView.bounds
            )
        }

        let format = UIGraphicsImageRendererFormat.default()
        format.scale = max(1, displayScale)
        format.opaque = true

        let drawRect = CGRect(origin: .zero, size: size)
        let renderer = UIGraphicsImageRenderer(size: size, format: format)
        return renderer.image { _ in
            UIColor.white.setFill()
            UIBezierPath(rect: drawRect).fill()

            if !resumeSnapshotView.isHidden, let base = resumeSnapshotView.image {
                // Resume JPEG was composed for the same canvas; filling the rect matches `scaleAspectFit` when aspects match.
                let baseRect = resumeSnapshotView.contentMode == .scaleAspectFit
                    ? aspectFitRect(for: base, in: drawRect)
                    : drawRect
                base.draw(in: baseRect)
            } else if let tpl = templateView.image {
                tpl.draw(in: aspectFitRect(for: tpl, in: drawRect))
            }

            if let strokes = strokeView.strokesOnlyImage(displayScale: format.scale) {
                strokes.draw(in: drawRect)
            }

            if includeLineOverlay,
               !templateLineOverlayView.isHidden,
               let line = templateLineOverlayView.image {
                let lineRect = templateLineOverlayView.contentMode == .scaleAspectFit
                    ? aspectFitRect(for: line, in: drawRect)
                    : drawRect
                line.draw(in: lineRect)
            }
        }
    }

    /// Capture for the vision model (1× scale to limit memory).
    private func captureCanvasForVLM() -> UIImage {
        captureCanvasBitmap(includeLineOverlay: true, displayScale: 1)
    }

    /// Capture for saving to Photos (Retina resolution).
    private func captureCanvasForExport() -> UIImage {
        let s = view.window?.screen.scale ?? UIScreen.main.scale
        return captureCanvasBitmap(includeLineOverlay: true, displayScale: s)
    }

    @objc private func saveColoringTapped() {
        let title = coloringBookPages.indices.contains(pageIndex) ? coloringBookPages[pageIndex].title : "Coloring"

        let status = PHPhotoLibrary.authorizationStatus(for: .addOnly)
        switch status {
        case .authorized, .limited:
            saveImageToPhotoLibrary(captureCanvasForExport(), title: title)
        case .notDetermined:
            PHPhotoLibrary.requestAuthorization(for: .addOnly) { [weak self] newStatus in
                DispatchQueue.main.async {
                    guard let self else { return }
                    if newStatus == .authorized || newStatus == .limited {
                        self.saveImageToPhotoLibrary(self.captureCanvasForExport(), title: title)
                    } else {
                        self.presentPhotoAccessDeniedAlert()
                    }
                }
            }
        default:
            presentPhotoAccessDeniedAlert()
        }
    }

    private func saveImageToPhotoLibrary(_ image: UIImage, title: String) {
        PHPhotoLibrary.shared().performChanges({
            let request = PHAssetChangeRequest.creationRequestForAsset(from: image)
            request.creationDate = Date()
        }, completionHandler: { [weak self] success, error in
            DispatchQueue.main.async {
                guard let self else { return }
                if success {
                    UINotificationFeedbackGenerator().notificationOccurred(.success)
                    let sheet = UIAlertController(
                        title: "Saved",
                        message: "“\(title)” was added to your Photos library.",
                        preferredStyle: .alert
                    )
                    sheet.addAction(UIAlertAction(title: "OK", style: .default))
                    self.present(sheet, animated: true)
                } else {
                    let msg = error?.localizedDescription ?? "Could not save."
                    let sheet = UIAlertController(title: "Couldn’t save", message: msg, preferredStyle: .alert)
                    sheet.addAction(UIAlertAction(title: "OK", style: .default))
                    self.present(sheet, animated: true)
                }
            }
        })
    }

    private func presentPhotoAccessDeniedAlert() {
        let sheet = UIAlertController(
            title: "Photos access needed",
            message: "Allow Brushi to add photos in Settings so your coloring can be saved.",
            preferredStyle: .alert
        )
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        sheet.addAction(UIAlertAction(title: "Open Settings", style: .default) { _ in
            if let url = URL(string: UIApplication.openSettingsURLString) {
                UIApplication.shared.open(url)
            }
        })
        present(sheet, animated: true)
    }

    private func hideVLMInputPreviewImmediate() {
        vlmInputPreviewHideWork?.cancel()
        vlmInputPreviewHideWork = nil
        vlmInputPreviewImageView.layer.removeAllAnimations()
        vlmInputPreviewLabel.layer.removeAllAnimations()
        vlmInputPreviewImageView.isHidden = true
        vlmInputPreviewLabel.isHidden = true
        vlmInputPreviewImageView.alpha = 1
        vlmInputPreviewLabel.alpha = 1
    }

    private func showVLMInputPreview(_ image: UIImage) {
        vlmInputPreviewHideWork?.cancel()
        vlmInputPreviewImageView.image = image
        vlmInputPreviewLabel.text = "VLM input\n\(Int(image.size.width))×\(Int(image.size.height))"
        vlmInputPreviewImageView.alpha = 1
        vlmInputPreviewLabel.alpha = 1
        vlmInputPreviewImageView.isHidden = false
        vlmInputPreviewLabel.isHidden = false
        view.bringSubviewToFront(vlmInputPreviewImageView)
        view.bringSubviewToFront(vlmInputPreviewLabel)

        let work = DispatchWorkItem { [weak self] in
            guard let self else { return }
            UIView.animate(withDuration: 0.35, delay: 0, options: [.curveEaseInOut]) {
                self.vlmInputPreviewImageView.alpha = 0
                self.vlmInputPreviewLabel.alpha = 0
            } completion: { _ in
                self.vlmInputPreviewImageView.isHidden = true
                self.vlmInputPreviewLabel.isHidden = true
                self.vlmInputPreviewImageView.alpha = 1
                self.vlmInputPreviewLabel.alpha = 1
                self.vlmInputPreviewHideWork = nil
            }
        }
        vlmInputPreviewHideWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + 3.0, execute: work)
    }

    private func composeFeedbackPrompt() -> String {
        let lastPoints = strokeView.lastFinishedStrokePointCount
        let lastColor = strokeView.chronologicalStrokeColors.last
        // Location hint disabled — coach should focus on *which color* they used, not where on the page.
        // let spatial = strokeView.lastFinishedStrokeSpatialHint()

        let paletteHintBlock: String
        if lastPoints > 30, let c = lastColor {
            let paintWord = simpleKidColorName(for: c)
            paletteHintBlock = "Their most recent big brush used palette color “\(paintWord)”—celebrate that color if you see it in the photo."

        } else if lastPoints > 0, let c = lastColor {
            let paintWord = simpleKidColorName(for: c)
            paletteHintBlock = "Their most recent brush used palette color “\(paintWord)”—celebrate that color if you see it in the photo."

        } else if lastPoints > 0 {
            paletteHintBlock = "They added a little paint recently; give a warm cheer without insisting on a specific color name."
        } else {
            paletteHintBlock = "No new stroke tracked; peek at the picture and cheer gently."
        }

        /*
        let spatialBlock: String
        if let s = spatial {
            spatialBlock = "\(s) Aim your praise at that region first."
        } else {
            spatialBlock = "Find the patch of paint that looks newest or brightest compared with the rest, usually near the last finger path."
        }
        */

        let themeLine: String
        if pageIndex >= 0, pageIndex < coloringBookPages.count {
            let t = coloringBookPages[pageIndex].title
            themeLine = "Page: \(t)."
        } else {
            themeLine = ""
        }

        let opener = themeLine.isEmpty ? "A child colored this sheet (outlines + paint)." : "A child colored this sheet (outlines + paint). \(themeLine)"

        return """
\(opener) Look at the picture.

\(paletteHintBlock)

Your job: say one cheery thing that names the color they just added, in simple kid words. If the photo makes it obvious what they colored, name that thing too—only when you are fairly sure; do not guess random objects. Do not use map directions (no left, right, top, bottom, or “in the corner”).

Speak to THEM: one or two very short sentences, easy words, use "you" or "your". Start with compliment inspired by the color. Sound warm. You may add a tiny color-feeling phrase that fits that color—avoid repeating the same opening every time (do not always start with “You are so bright”).

IMPORTANT: Reply with ONLY the words you say aloud—no rules, no quotes about yourself, no repeating this text, no bullets, no markdown, no symbols like <>. Never mention AI, robots, computers, phones, apps, or internet.

"""
    }

    /// Nearest app palette swatch name so "history" stays consistent with the picker.
    private func simpleKidColorName(for color: UIColor) -> String {
        var r: CGFloat = 0, g: CGFloat = 0, b: CGFloat = 0, a: CGFloat = 0
        guard color.cgColor.colorSpace?.model == .rgb,
              color.getRed(&r, green: &g, blue: &b, alpha: &a)
        else {
            var white: CGFloat = 0
            if color.getWhite(&white, alpha: &a) {
                return white < 0.42 ? paletteKidNames[paletteKidNames.count - 1] : "paint"
            }
            return "paint"
        }

        func dist(_ pc: UIColor) -> CGFloat {
            var rr: CGFloat = 0, gg: CGFloat = 0, bb: CGFloat = 0, aa: CGFloat = 0
            guard pc.getRed(&rr, green: &gg, blue: &bb, alpha: &aa) else { return 999 }
            let dr = r - rr
            let dg = g - gg
            let db = b - bb
            return dr * dr + dg * dg + db * db
        }

        var best = 0
        var bestD = CGFloat.greatestFiniteMagnitude
        for i in palette.indices {
            let d = dist(palette[i])
            if d < bestD {
                bestD = d
                best = i
            }
        }
        return paletteKidNames[best.clamped(to: 0...(paletteKidNames.count - 1))]
    }
}

// MARK: - Magic crayon palette (horizontal wax crayons, drawn in code)

/// Scroll view that hands drags to scrolling even when the gesture starts on a `UIControl` (crayon).
private final class CrayonPaletteScrollView: UIScrollView {

    override init(frame: CGRect) {
        super.init(frame: frame)
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }

    override func touchesShouldCancel(in view: UIView) -> Bool {
        if view is MagicCrayonControl { return true }
        if view is UIControl { return true }
        return super.touchesShouldCancel(in: view)
    }
}

/// Renders a single horizontal crayon (tip on the left, rounded cap on the right).
private final class HorizontalCrayonShapeView: UIView {

    var waxColor: UIColor = .systemBlue { didSet { setNeedsDisplay() } }
    var highlightColor: UIColor = .white { didSet { setNeedsDisplay() } }

    static func defaultHighlight(for wax: UIColor) -> UIColor {
        var r: CGFloat = 0, g: CGFloat = 0, b: CGFloat = 0, a: CGFloat = 0
        guard wax.getRed(&r, green: &g, blue: &b, alpha: &a) else { return wax }
        let t: CGFloat = 0.38
        return UIColor(
            red: r + (1 - r) * t,
            green: g + (1 - g) * t,
            blue: b + (1 - b) * t,
            alpha: a
        )
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
        backgroundColor = .clear
        contentMode = .redraw
        isOpaque = false
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        backgroundColor = .clear
        contentMode = .redraw
        isOpaque = false
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext() else { return }
        let W = bounds.width
        let H = bounds.height
        let tipW = W * 0.22
        let rCap = min(H * 0.42, (W - tipW) * 0.48)
        let topY = H * 0.10
        let botY = H * 0.90
        let dark = UIColor(red: 0.20, green: 0.12, blue: 0.22, alpha: 1)
        let bandH = max(1.2, H * 0.09)

        let outline = UIBezierPath()
        outline.move(to: CGPoint(x: 0, y: H / 2))
        outline.addLine(to: CGPoint(x: tipW, y: topY))
        outline.addLine(to: CGPoint(x: W - rCap, y: topY))
        outline.addArc(
            withCenter: CGPoint(x: W - rCap, y: H / 2),
            radius: rCap,
            startAngle: -.pi / 2,
            endAngle: .pi / 2,
            clockwise: true
        )
        outline.addLine(to: CGPoint(x: tipW, y: botY))
        outline.close()

        ctx.saveGState()
        ctx.addPath(outline.cgPath)
        ctx.clip()

        ctx.setFillColor(waxColor.cgColor)
        ctx.fill(bounds)

        ctx.setFillColor(highlightColor.withAlphaComponent(0.95).cgColor)
        ctx.fill(CGRect(x: tipW, y: topY, width: W - tipW - rCap * 0.2, height: (H / 2 - topY) + bandH * 0.2))

        ctx.setFillColor(dark.cgColor)
        ctx.fill(CGRect(x: tipW + (W - tipW - rCap) * 0.38, y: topY + bandH, width: bandH * 0.75, height: (botY - topY) - bandH * 2))

        ctx.restoreGState()

        ctx.setStrokeColor(UIColor.black.withAlphaComponent(0.18).cgColor)
        ctx.setLineWidth(max(0.6, H * 0.04))
        ctx.addPath(outline.cgPath)
        ctx.strokePath()
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        setNeedsDisplay()
    }
}

private final class MagicCrayonControl: UIControl {

    private let shapeView = HorizontalCrayonShapeView()

    override var isHighlighted: Bool {
        didSet { alpha = isHighlighted ? 0.88 : 1 }
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
        backgroundColor = .clear
        isExclusiveTouch = false
        shapeView.isUserInteractionEnabled = false
        shapeView.translatesAutoresizingMaskIntoConstraints = false
        addSubview(shapeView)
        NSLayoutConstraint.activate([
            shapeView.leadingAnchor.constraint(equalTo: leadingAnchor, constant: 2),
            shapeView.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -2),
            shapeView.centerYAnchor.constraint(equalTo: centerYAnchor),
            shapeView.heightAnchor.constraint(equalTo: heightAnchor, multiplier: 0.62),
        ])
    }

    func setColors(wax: UIColor, highlight: UIColor) {
        shapeView.waxColor = wax
        shapeView.highlightColor = highlight
    }

    func setSelected(_ selected: Bool, animated: Bool) {
        let apply = {
            if selected {
                self.layer.shadowColor = UIColor.white.cgColor
                self.layer.shadowOpacity = 0.95
                self.layer.shadowRadius = 7
                self.layer.shadowOffset = .zero
                self.transform = CGAffineTransform(scaleX: 1.05, y: 1.05)
            } else {
                self.layer.shadowOpacity = 0
                self.transform = .identity
            }
        }
        if animated {
            UIView.animate(withDuration: 0.18, delay: 0, options: [.curveEaseOut], animations: apply)
        } else {
            apply()
        }
    }
}

// MARK: - Brush chrome helpers

extension UIColor {
    convenience init(hex: String) {
        let h = hex.trimmingCharacters(in: CharacterSet(charactersIn: "#"))
        var rgb: UInt64 = 0
        Scanner(string: h).scanHexInt64(&rgb)
        let r = CGFloat((rgb >> 16) & 0xFF) / 255
        let g = CGFloat((rgb >> 8) & 0xFF) / 255
        let b = CGFloat(rgb & 0xFF) / 255
        self.init(red: r, green: g, blue: b, alpha: 1)
    }
}

/// Paintbrush icon (bristles + ferrule + handle) for the brush tool button.
final class PaintBrushIconView: UIView {

    override init(frame: CGRect) {
        super.init(frame: frame)
        backgroundColor = .clear
        contentMode = .redraw
        isOpaque = false
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        backgroundColor = .clear
        contentMode = .redraw
        isOpaque = false
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext() else { return }
        let w = bounds.width, h = bounds.height
        let cx = w / 2, cy = h / 2

        // Draw as a diagonal pencil (matching Figma's FigmaBrush shape)
        ctx.translateBy(x: cx, y: cy)
        ctx.rotate(by: -.pi / 4)

        let pLen = min(w, h) * 1.28
        let pH   = pLen * 0.18
        let x0 = -pLen / 2, top = -pH / 2, bot = pH / 2

        // Dark graphite tip
        let tipPath = UIBezierPath()
        tipPath.move(to: CGPoint(x: x0, y: 0))
        tipPath.addLine(to: CGPoint(x: x0 + pLen * 0.08, y: top + pH * 0.28))
        tipPath.addLine(to: CGPoint(x: x0 + pLen * 0.08, y: bot - pH * 0.28))
        tipPath.close()
        ctx.setFillColor(UIColor(red: 0.2, green: 0.16, blue: 0.12, alpha: 1).cgColor)
        ctx.addPath(tipPath.cgPath); ctx.fillPath()

        // Wood cone
        let woodPath = UIBezierPath()
        woodPath.move(to: CGPoint(x: x0 + pLen * 0.08, y: top + pH * 0.28))
        woodPath.addLine(to: CGPoint(x: x0 + pLen * 0.08, y: bot - pH * 0.28))
        woodPath.addLine(to: CGPoint(x: x0 + pLen * 0.20, y: bot))
        woodPath.addLine(to: CGPoint(x: x0 + pLen * 0.20, y: top))
        woodPath.close()
        ctx.setFillColor(UIColor(red: 0.91, green: 0.72, blue: 0.47, alpha: 1).cgColor)
        ctx.addPath(woodPath.cgPath); ctx.fillPath()

        // Yellow body
        let bodyR: CGFloat = pH * 0.14
        let bodyPath = UIBezierPath(roundedRect: CGRect(x: x0 + pLen * 0.20, y: top, width: pLen * 0.60, height: pH), cornerRadius: bodyR)
        ctx.setFillColor(UIColor(hex: "#F2C94C").cgColor)
        ctx.addPath(bodyPath.cgPath); ctx.fillPath()

        // White label zigzag area
        let lblPath = UIBezierPath(roundedRect: CGRect(x: x0 + pLen * 0.22, y: top + pH * 0.25, width: pLen * 0.54, height: pH * 0.25), cornerRadius: 1.5)
        ctx.setFillColor(UIColor.white.withAlphaComponent(0.65).cgColor)
        ctx.addPath(lblPath.cgPath); ctx.fillPath()

        // Orange band
        let bandPath = UIBezierPath(roundedRect: CGRect(x: x0 + pLen * 0.80, y: top, width: pLen * 0.05, height: pH), cornerRadius: 1)
        ctx.setFillColor(UIColor(hex: "#F2994A").cgColor)
        ctx.addPath(bandPath.cgPath); ctx.fillPath()

        // Pink eraser cap
        let capPath = UIBezierPath(roundedRect: CGRect(x: x0 + pLen * 0.85, y: top, width: pLen * 0.15, height: pH), cornerRadius: bodyR)
        ctx.setFillColor(UIColor(hex: "#F2C94C").cgColor)
        ctx.addPath(capPath.cgPath); ctx.fillPath()
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        setNeedsDisplay()
    }
}

/// Soft eraser pill icon for the eraser tool.
final class EraserIconView: UIView {

    override init(frame: CGRect) {
        super.init(frame: frame)
        backgroundColor = .clear
        contentMode = .redraw
        isOpaque = false
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        backgroundColor = .clear
        contentMode = .redraw
        isOpaque = false
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext() else { return }
        let w = bounds.width
        let h = bounds.height
        let body = UIBezierPath(roundedRect: CGRect(x: w * 0.12, y: h * 0.28, width: w * 0.76, height: h * 0.5), cornerRadius: h * 0.12)
        ctx.setFillColor(FigmaTheme.primaryOrange.cgColor)
        ctx.addPath(body.cgPath)
        ctx.fillPath()
        ctx.setStrokeColor(FigmaTheme.primaryOrangeBorder.cgColor)
        ctx.setLineWidth(max(1.2, h * 0.04))
        ctx.addPath(body.cgPath)
        ctx.strokePath()
        let strap = UIBezierPath(roundedRect: CGRect(x: w * 0.22, y: h * 0.15, width: w * 0.56, height: h * 0.18), cornerRadius: 2)
        ctx.setFillColor(FigmaTheme.primaryOrangeBorder.withAlphaComponent(0.92).cgColor)
        ctx.addPath(strap.cgPath)
        ctx.fillPath()
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        setNeedsDisplay()
    }
}

private extension UIColor {
    /// Darker rim for stroke-size “bubble” buttons on a crayon-colored fill.
    func magicBrushyStrokeChromeBorder() -> UIColor {
        var h: CGFloat = 0, s: CGFloat = 0, b: CGFloat = 0, a: CGFloat = 0
        if getHue(&h, saturation: &s, brightness: &b, alpha: &a) {
            return UIColor(hue: h, saturation: min(1, s + 0.06), brightness: max(0.1, b * 0.66), alpha: 1)
        }
        var w: CGFloat = 0
        if getWhite(&w, alpha: &a) {
            return UIColor(white: max(0, w - 0.32), alpha: 1)
        }
        return FigmaTheme.actionBlueBorder
    }
}

private extension BinaryInteger {
    func clamped(to range: ClosedRange<Self>) -> Self {
        Swift.min(Swift.max(self, range.lowerBound), range.upperBound)
    }
}
