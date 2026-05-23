import UIKit
import Photos

/// Full-screen coloring: built-in outlines, finger or Apple Pencil, on-device VLM feedback.
/// No Bluetooth pen stack — input is multitouch / Pencil only.
final class ColoringViewController: UIViewController, UIGestureRecognizerDelegate {

    /// Output length caps passed to `LeapVLMModel.generate(maxOutputTokens:)` — prompt text unchanged.
    private enum VLMCoachTokenLimits {
        /// Idle per-stroke feedback: ~1–2 short kid sentences.
        static let strokeFeedbackMaxOutput = 60
        /// Mascot tap / whole-page cheer (longer reply OK).
        static let wholeDrawingMaxOutput = 96
        /// Page-open welcome: ~2 short sentences (model was emitting 80+ tokens at 128).
        static let pageLoadWelcomeMaxOutput = 60
    }

    private enum TopChromeMetrics {
        /// Pin the nav row to the safe-area top (no extra gap under the status bar).
        static let menuTopOffset: CGFloat = 0
        static let menuHorizontalInset: CGFloat = 2
        static let menuTrailingInset: CGFloat = 10
        /// Nudge the home / tool row right so its leading edge matches the visible canvas edge (scaled page).
        static let navRowCanvasLeadingAlignmentOffset: CGFloat = 6
        /// Slightly reduce system safe-area padding so content can sit closer to edges.
        static let additionalSafeAreaShrink = UIEdgeInsets(top: 0, left: -4, bottom: -6, right: -4)
    }

    private var coloringOnPhone: ColoringOnPhone!

    private let canvasContainer = UIView()
    private let templateView = UIImageView()
    /// Flattened snapshot when resuming from `LastDrawingStore` (sits between template and live strokes).
    private let resumeSnapshotView = UIImageView()
    private let strokeView = ColoringStrokeView()
    /// Line art only, above strokes so white eraser cannot hide template outlines.
    private let templateLineOverlayView = UIImageView()
    private let mascotImageView = UIImageView()
    private let mascotLipSync = MascotLipSyncDriver()
    /// Wraps mascot art and the tap-for-cheer gesture.
    private let mascotContainer = UIView()
    private let paintRow = ColoringPhonePassThroughStackView()
    private let headerChromeStack = UIStackView()
    private let rightPanelStack = UIStackView()
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
        BuiltInColoringPages.library.first(where: { $0.id == "ocean" })?.pages
        ?? BuiltInColoringPages.library.first?.pages
        ?? []

    /// Set when pushing from the category grid so we can persist `LastDrawingStore` on the way home.
    var sessionPackId: String?

    private var isFreeDrawingSession: Bool {
        sessionPackId == BuiltInColoringPages.savedDrawingsPackId
    }

    private var strokeWidthPresets: [CGFloat] {
        isFreeDrawingSession ? freeDrawStrokeWidthPresets : templateStrokeWidthPresets
    }

    /// iPad only: minimum last-stroke crop size on the canvas (free draw uses a larger crop window).
    private var vlmStrokeCropMinCanvasFraction: CGFloat {
        isFreeDrawingSession ? 0.5 : 1.0 / 3.0
    }

    /// Phone sends the full page to the VLM (no stroke zoom crop) for faster, stable inference.
    private var usesFullPageVLMInput: Bool {
        traitCollection.userInterfaceIdiom == .phone
    }

    /// Saved free-drawing files: capture sharper than on-screen 1× points (grid + resume).
    private enum SavedDrawingCapture {
        static let minPixelWidth: CGFloat = 1536
        static let maxPixelEdge: CGFloat = 2048
        static let galleryThumbnailMaxEdge: CGFloat = 720
    }
    /// Set when opening from the home “Your drawings” strip; home overwrites this record instead of appending a new save.
    var continuingSavedDrawingId: UUID?
    /// When continuing from the home “last drawing” strip, flattened art to show under new strokes.
    var pendingResumeComposite: UIImage?
    /// True when `pendingResumeComposite` is a line-free underlay; line art comes from `templateLineOverlayView` so the eraser cannot remove outlines.
    var pendingResumeHasSeparateLineOverlay = false
    private var didConsumePendingResumeComposite = false

    private let drawingBackgroundView = UIImageView()
    private let homeButton = UIButton(type: .custom)
    private let toolRow = UIStackView()
    private let doneButton = UIButton(type: .system)
    private let toolPairStack = UIStackView()
    /// Holds `crayonScrollView` so Auto Layout gives the scroll view a **bounded** height (required for vertical scrolling).
    private let crayonScrollContainer = UIView()
    private let crayonScrollView = CrayonPaletteScrollView()
    private let crayonStack = UIStackView()
    private var crayonControls: [MagicCrayonControl] = []
    private var crayonRowHeightConstraints: [NSLayoutConstraint] = []
    private var crayonScrollViewportHeightConstraint: NSLayoutConstraint!
    /// Display order (top → bottom): rainbow, then earth tones, then black & white last.
    /// Each value is a 0-based index into `palette` / `Colors/NN-color.png` (01→0, 02→1 …).
    private var crayonPaletteDisplayOrder: [Int] {
        guard palette.count == 30 else { return Array(0..<palette.count) }
        return MagicBrushyCrayonResources.rainbowDisplayOrder
    }
    private var isEraserMode = false
    /// Index in `palette` when brush mode.
    /// Default wax: sky blue (`colors/03-color.png` → palette index 2).
    private var strokePaletteIndex: Int = 2
    private var brushToolButton: UIButton?
    private var eraserToolButton: UIButton?

    // ── Stroke-size picker (canvas top-trailing, five “paint blobs”) ───────
    private let templateStrokeWidthPresets: [CGFloat] = [10, 16, 22, 30, 40]
    private let freeDrawStrokeWidthPresets: [CGFloat] = [6, 10, 14, 18, 24]
    /// Index into `strokeWidthPresets` (0 = smallest dot on the yellow strip).
    private var selectedStrokeSizeIndex: Int = 2
    private let brushSizeChrome = ColoringCollapsibleBrushSizeChrome()
    private let undoChromeButton = UIButton(type: .custom)
    private let cameraChromeButton = UIButton(type: .custom)
    private let topChromeLeftRow = UIStackView()
    private let topChromeRightRow = UIStackView()

    // ── Compact-layout adaptive constraints ──────────────────────────────────
    /// Width + height constraints for nav bar buttons (home, undo, redo, save, settings).
    private var navButtonSizeConstraints: [NSLayoutConstraint] = []
    private var toolRowMinHeightConstraint: NSLayoutConstraint!
    /// Nav chrome buttons whose symbol size / corner radius adapt on iPhone.
    private var chromeNavButtons: [UIButton] = []
    private var settingsGearButton: MagicBrushySettingsGearButton?
    /// Width / height constraints for brush / eraser tool buttons (kept square).
    private var toolButtonHeightConstraints: [NSLayoutConstraint] = []
    private var toolButtonWidthConstraints: [NSLayoutConstraint] = []
    private var toolPairStackHeightConstraint: NSLayoutConstraint!
    /// Right crayon-rail width.
    private var rightPanelWidthConstraint: NSLayoutConstraint?
    private var paintRowLeadingConstraint: NSLayoutConstraint!
    private var paintRowTrailingConstraint: NSLayoutConstraint!
    /// Phone only: pin paintRow to the real screen edge (bypasses safe-area gap on the right).
    private var paintRowTrailingScreenEdgeConstraint: NSLayoutConstraint!
    private var headerLeadingCanvasConstraint: NSLayoutConstraint!
    private var headerLeadingPaintRowConstraint: NSLayoutConstraint!
    private var headerTopConstraint: NSLayoutConstraint!
    private var paintRowTopToHeaderBottomConstraint: NSLayoutConstraint!
    private var paintRowTopToHeaderTopConstraint: NSLayoutConstraint!
    private var canvasAspectConstraint: NSLayoutConstraint!
    private var mascotImageWidthConstraint: NSLayoutConstraint!
    private var mascotImageHeightConstraint: NSLayoutConstraint!
    private var mascotImageCenterXConstraint: NSLayoutConstraint!
    private var mascotImageLeadingConstraint: NSLayoutConstraint!
    private var mascotImageTopConstraint: NSLayoutConstraint!
    private var mascotRailWidthConstraint: NSLayoutConstraint!
    private let rightPanelPhoneTopSpacer = UIView()
    private var rightPanelPhoneTopSpacerHeight: NSLayoutConstraint!
    private var paintRowTopToSafeAreaConstraint: NSLayoutConstraint!
    private var topChromeLeftRowHeightConstraint: NSLayoutConstraint!
    private var topChromeRightRowHeightConstraint: NSLayoutConstraint!

    /// App-wide singleton model; loaded once at app startup from SceneDelegate.
    private let vlm = LeapVLMModel.shared

    /// Same order as bundled `Colors/01-color.png` … `30-color.png` — short words for a11y + VLM hints.
    private let paletteKidNames = [
        "light pink", "dark gray", "sky blue", "green", "yellow", "orange", "red", "pink purple", "purple", "magenta",
        "violet", "purple blue", "blue", "royal blue", "bright blue", "navy", "teal blue", "aqua", "sea green", "mint",
        "forest green", "yellow green", "white", "gold", "amber", "orange red", "rust red", "brown",
        "terracotta", "sand",
    ]

    /// Stroke colors from each PNG in `MagicBrushy/Colors/` — sampled at the **wax tip** (see `MagicBrushyCrayonResources`).
    private let palette: [UIColor] = MagicBrushyCrayonResources.strokeColors
    private let crayonSwatchImages: [UIImage] = MagicBrushyCrayonResources.swatchImages

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
    /// Page indices that already received the open-page VLM welcome this session.
    private var welcomedPageIndices = Set<Int>()
    private var pendingPageWelcomeWork: DispatchWorkItem?
    /// Show **sleepy** only after this long without painting (not from coach text).
    private static let mascotLongInactivityDelay: TimeInterval = 60
    private var mascotInactivityWork: DispatchWorkItem?
    private var mascotShowingSleepyFromInactivity = false
    override func viewDidLoad() {
        super.viewDidLoad()
        NotificationCenter.default.addObserver(
            self,
            selector: #selector(coachAutoFeedbackSettingChanged),
            name: MagicBrushyCoachAutoFeedback.didChangeNotification,
            object: nil
        )
        additionalSafeAreaInsets = TopChromeMetrics.additionalSafeAreaShrink
        let g = view.safeAreaLayoutGuide
        view.backgroundColor = .black

        drawingBackgroundView.translatesAutoresizingMaskIntoConstraints = false
        drawingBackgroundView.image = UIImage(named: "ColoringDrawingBackground")
        drawingBackgroundView.contentMode = .scaleAspectFill
        drawingBackgroundView.clipsToBounds = true
        drawingBackgroundView.backgroundColor = FigmaTheme.skyBlue

        templateView.contentMode = .scaleAspectFit
        templateView.layer.minificationFilter = .linear
        templateView.layer.magnificationFilter = .linear
        templateView.clipsToBounds = true
        templateView.backgroundColor = FigmaTheme.canvasFill
        templateView.layer.cornerRadius = 24
        templateView.layer.borderWidth = 0

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
        toolPairStack.spacing = ColoringCrayonPaletteLayout.toolPairSpacing
        toolPairStack.alignment = .center
        toolPairStack.distribution = .fill
        toolPairStack.addArrangedSubview(brushToolButton!)
        toolPairStack.addArrangedSubview(eraserToolButton!)
        toolPairStack.translatesAutoresizingMaskIntoConstraints = false
        toolPairStack.setContentCompressionResistancePriority(.required, for: .vertical)
        toolPairStack.setContentHuggingPriority(.required, for: .vertical)
        brushToolButton?.setContentCompressionResistancePriority(.required, for: .vertical)
        eraserToolButton?.setContentCompressionResistancePriority(.required, for: .vertical)
        toolPairStackHeightConstraint = toolPairStack.heightAnchor.constraint(
            equalToConstant: ColoringCrayonPaletteLayout.toolButtonHeight
        )
        toolPairStackHeightConstraint.isActive = true

        // ── Crayons (custom horizontal wax crayons, scrollable) ─────────────
        crayonScrollContainer.translatesAutoresizingMaskIntoConstraints = false
        crayonScrollContainer.backgroundColor = .clear
        crayonScrollContainer.clipsToBounds = true
        crayonScrollContainer.setContentHuggingPriority(.required, for: .vertical)
        crayonScrollContainer.setContentCompressionResistancePriority(.required, for: .vertical)
        crayonScrollViewportHeightConstraint = crayonScrollContainer.heightAnchor.constraint(
            equalToConstant: ColoringCrayonPaletteLayout.scrollViewportHeight(for: traitCollection)
        )

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
        crayonScrollView.backgroundColor = .clear
        crayonScrollView.keyboardDismissMode = .onDrag
        crayonScrollView.panGestureRecognizer.cancelsTouchesInView = true

        crayonScrollContainer.addSubview(crayonScrollView)
        NSLayoutConstraint.activate([
            crayonScrollView.topAnchor.constraint(equalTo: crayonScrollContainer.topAnchor),
            crayonScrollView.leadingAnchor.constraint(equalTo: crayonScrollContainer.leadingAnchor),
            crayonScrollView.trailingAnchor.constraint(equalTo: crayonScrollContainer.trailingAnchor),
            crayonScrollView.bottomAnchor.constraint(equalTo: crayonScrollContainer.bottomAnchor),
            crayonScrollViewportHeightConstraint,
        ])

        crayonStack.axis = .vertical
        crayonStack.spacing = ColoringCrayonPaletteLayout.crayonStackSpacing(for: traitCollection)
        crayonStack.isLayoutMarginsRelativeArrangement = false
        crayonStack.alignment = .fill
        crayonStack.distribution = .fill
        crayonStack.translatesAutoresizingMaskIntoConstraints = false
        crayonStack.backgroundColor = .clear
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
            let wax = palette[paletteIndex.clamped(to: 0...(palette.count - 1))]
            let img = crayonSwatchImages.indices.contains(paletteIndex) ? crayonSwatchImages[paletteIndex] : nil
            c.setSwatch(image: img, wax: wax)
            c.translatesAutoresizingMaskIntoConstraints = false
            let rowH = c.heightAnchor.constraint(
                equalToConstant: ColoringCrayonPaletteLayout.crayonRowHeight(for: traitCollection)
            )
            rowH.isActive = true
            crayonRowHeightConstraints.append(rowH)
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
        mascotImageView.setContentHuggingPriority(.required, for: .vertical)
        mascotImageView.setContentCompressionResistancePriority(.required, for: .vertical)
        mascotLipSync.attach(
            imageView: mascotImageView,
            closed: UIImage(named: "MascotTalkingMouthClosed")
                ?? MascotReactionState.talking.loadImage(),
            open: UIImage(named: "MascotTalkingMouthOpen")
                ?? MascotReactionState.happy.loadImage(),
            oMouth: UIImage(named: "MascotTalkingMouthO")
                ?? MascotReactionState.oMouth.loadImage()
        )

        let mascotContainer = self.mascotContainer
        mascotContainer.translatesAutoresizingMaskIntoConstraints = false
        mascotContainer.clipsToBounds = false
        mascotContainer.setContentHuggingPriority(.required, for: .vertical)
        mascotContainer.setContentCompressionResistancePriority(.required, for: .vertical)
        mascotContainer.addSubview(mascotImageView)

        let mascotDisplay = BrushiMascotLayout.coloringRailDisplaySize(for: traitCollection, image: mascotImage)

        let mascotTap = UITapGestureRecognizer(target: self, action: #selector(mascotTapped))
        mascotTap.delegate = self
        mascotContainer.addGestureRecognizer(mascotTap)
        mascotContainer.isUserInteractionEnabled = true

        mascotImageWidthConstraint = mascotImageView.widthAnchor.constraint(equalToConstant: mascotDisplay.width)
        mascotImageHeightConstraint = mascotImageView.heightAnchor.constraint(equalToConstant: mascotDisplay.height)
        mascotImageCenterXConstraint = mascotImageView.centerXAnchor.constraint(
            equalTo: mascotContainer.centerXAnchor
        )
        mascotImageLeadingConstraint = mascotImageView.leadingAnchor.constraint(
            equalTo: mascotContainer.leadingAnchor,
            constant: -14
        )
        mascotRailWidthConstraint = mascotContainer.widthAnchor.constraint(
            equalToConstant: BrushiMascotLayout.rightRailWidth(for: traitCollection)
        )
        mascotImageTopConstraint = mascotImageView.topAnchor.constraint(equalTo: mascotContainer.topAnchor)
        NSLayoutConstraint.activate([
            mascotImageCenterXConstraint,
            mascotImageTopConstraint,
            mascotImageView.bottomAnchor.constraint(equalTo: mascotContainer.bottomAnchor),
            mascotImageWidthConstraint,
            mascotImageHeightConstraint,
        ])

        // ── Right panel ───────────────────────────────────────────────────────
        rightPanelPhoneTopSpacer.backgroundColor = .clear
        rightPanelPhoneTopSpacer.translatesAutoresizingMaskIntoConstraints = false
        rightPanelPhoneTopSpacer.isHidden = true
        rightPanelPhoneTopSpacerHeight = rightPanelPhoneTopSpacer.heightAnchor.constraint(equalToConstant: 0)
        rightPanelPhoneTopSpacerHeight.isActive = true
        rightPanelStack.addArrangedSubview(rightPanelPhoneTopSpacer)
        rightPanelStack.addArrangedSubview(mascotContainer)
        rightPanelStack.addArrangedSubview(toolPairStack)
        rightPanelStack.addArrangedSubview(crayonScrollContainer)
        rightPanelStack.axis = .vertical
        rightPanelStack.spacing = ColoringCrayonPaletteLayout.rightPanelStackSpacing
        rightPanelStack.distribution = .fill
        rightPanelStack.alignment = .fill
        rightPanelStack.translatesAutoresizingMaskIntoConstraints = false
        rightPanelStack.setContentHuggingPriority(.defaultHigh, for: .horizontal)
        rightPanelStack.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
        // Above the canvas layer so crayons overlap the page's right edge.
        rightPanelStack.layer.zPosition = 100
        rightPanelStack.clipsToBounds = false
        rightPanelStack.setCustomSpacing(ColoringCrayonPaletteLayout.mascotToToolsSpacing, after: mascotContainer)

        // ── Top nav bar (Figma `3-2098`) ─────────────────────────────────────
        let navSide = MagicBrushyChromeMetrics.chromeButtonSide(traitCollection)
        let navChromeInsets = MagicBrushyChromeMetrics.navChromeContentInsets
        homeButton.configuration = .plain()
        homeButton.setContentCompressionResistancePriority(.required, for: .horizontal)
        homeButton.setContentCompressionResistancePriority(.required, for: .vertical)
        homeButton.setContentHuggingPriority(.required, for: .horizontal)
        homeButton.setContentHuggingPriority(.required, for: .vertical)
        MagicBrushyChromeMetrics.applyHomeNavChrome(
            to: homeButton,
            image: MagicBrushyChromeMetrics.chromeNavHomeImage(),
            traitCollection: traitCollection
        )
        homeButton.addTarget(self, action: #selector(homeTapped), for: .touchUpInside)
        homeButton.isHidden = navigationController == nil
        homeButton.translatesAutoresizingMaskIntoConstraints = false
        let homeW = homeButton.widthAnchor.constraint(equalToConstant: navSide)
        let homeH = homeButton.heightAnchor.constraint(equalToConstant: navSide)
        NSLayoutConstraint.activate([homeW, homeH])
        navButtonSizeConstraints += [homeW, homeH]
        chromeNavButtons.append(homeButton)

        let settingsBtn = makeMagicBrushySettingsGearButton()
        settingsGearButton = settingsBtn

        let cameraImage = UIImage(named: "ColoringToolbarCamera")?.withRenderingMode(.alwaysOriginal)
        let undoImage = UIImage(named: "ColoringToolbarUndo")?.withRenderingMode(.alwaysOriginal)

        cameraChromeButton.removeFromSuperview()
        undoChromeButton.removeFromSuperview()
        cameraChromeButton.translatesAutoresizingMaskIntoConstraints = false
        undoChromeButton.translatesAutoresizingMaskIntoConstraints = false

        MagicBrushyChromeMetrics.applySquareChrome(
            to: cameraChromeButton,
            fill: FigmaTheme.actionBlue,
            border: FigmaTheme.actionBlueBorder,
            traitCollection: traitCollection,
            contentInsets: navChromeInsets
        )
        cameraChromeButton.setImage(cameraImage, for: .normal)
        cameraChromeButton.imageView?.contentMode = .scaleAspectFit
        cameraChromeButton.setContentCompressionResistancePriority(.required, for: .horizontal)
        cameraChromeButton.setContentCompressionResistancePriority(.required, for: .vertical)
        cameraChromeButton.setContentHuggingPriority(.required, for: .horizontal)
        cameraChromeButton.setContentHuggingPriority(.required, for: .vertical)
        cameraChromeButton.accessibilityLabel = "Save to Photos"
        cameraChromeButton.addTarget(self, action: #selector(saveColoringTapped), for: .touchUpInside)

        MagicBrushyChromeMetrics.applySquareChrome(
            to: undoChromeButton,
            fill: ColoringFigmaToolbarChrome.undoGreen,
            border: ColoringFigmaToolbarChrome.undoGreenBorder,
            traitCollection: traitCollection,
            contentInsets: navChromeInsets
        )
        undoChromeButton.setImage(undoImage, for: .normal)
        undoChromeButton.imageView?.contentMode = .scaleAspectFit
        undoChromeButton.setContentCompressionResistancePriority(.required, for: .horizontal)
        undoChromeButton.setContentCompressionResistancePriority(.required, for: .vertical)
        undoChromeButton.setContentHuggingPriority(.required, for: .horizontal)
        undoChromeButton.setContentHuggingPriority(.required, for: .vertical)
        undoChromeButton.accessibilityLabel = "Undo"
        undoChromeButton.addTarget(self, action: #selector(undoStroke), for: .touchUpInside)

        let camW = cameraChromeButton.widthAnchor.constraint(equalToConstant: navSide)
        let camH = cameraChromeButton.heightAnchor.constraint(equalToConstant: navSide)
        let undoW = undoChromeButton.widthAnchor.constraint(equalToConstant: navSide)
        let undoH = undoChromeButton.heightAnchor.constraint(equalToConstant: navSide)
        NSLayoutConstraint.activate([camW, camH, undoW, undoH])
        navButtonSizeConstraints += [camW, camH, undoW, undoH]
        chromeNavButtons.append(contentsOf: [cameraChromeButton, undoChromeButton])

        brushSizeChrome.setContentCompressionResistancePriority(.required, for: .horizontal)
        brushSizeChrome.setContentCompressionResistancePriority(.required, for: .vertical)
        brushSizeChrome.setContentHuggingPriority(.required, for: .horizontal)
        brushSizeChrome.setContentHuggingPriority(.required, for: .vertical)
        brushSizeChrome.dotCount = strokeWidthPresets.count
        brushSizeChrome.selectedIndex = selectedStrokeSizeIndex
        brushSizeChrome.onSelectionChanged = { [weak self] index in
            guard let self else { return }
            self.selectedStrokeSizeIndex = index
            self.applyStrokeWidthFromSelection()
            self.refreshStrokeSizeAppearance()
        }
        let barSize = ColoringFigmaToolbarChrome.brushBarSize(for: traitCollection, dotCount: strokeWidthPresets.count)
        let collapsedSide = ColoringFigmaToolbarChrome.phoneCollapsedBrushSizeSide(for: traitCollection)
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        brushSizeChrome.applyMetrics(
            expandedWidth: barSize.width,
            expandedHeight: barSize.height,
            collapsedSide: collapsedSide,
            traitCollection: traitCollection
        )
        brushSizeChrome.configureForPhone(phone, traitCollection: traitCollection)

        topChromeLeftRow.axis = .horizontal
        topChromeLeftRow.spacing = 8
        topChromeLeftRow.alignment = .center
        topChromeLeftRowHeightConstraint = topChromeLeftRow.heightAnchor.constraint(equalToConstant: navSide)
        topChromeLeftRowHeightConstraint.isActive = true
        topChromeLeftRow.addArrangedSubview(homeButton)
        topChromeLeftRow.addArrangedSubview(settingsBtn)
        topChromeLeftRow.addArrangedSubview(cameraChromeButton)

        topChromeRightRow.axis = .horizontal
        topChromeRightRow.spacing = 10
        topChromeRightRow.alignment = .center
        topChromeRightRowHeightConstraint = topChromeRightRow.heightAnchor.constraint(equalToConstant: navSide)
        topChromeRightRowHeightConstraint.isActive = true
        topChromeRightRow.addArrangedSubview(brushSizeChrome)
        topChromeRightRow.addArrangedSubview(undoChromeButton)

        let navSpacer = UIView()
        navSpacer.setContentHuggingPriority(UILayoutPriority(1), for: .horizontal)
        toolRow.axis = .horizontal
        toolRow.spacing = 8
        toolRow.alignment = .center
        toolRow.distribution = .fill
        toolRow.addArrangedSubview(topChromeLeftRow)
        toolRow.addArrangedSubview(navSpacer)
        toolRow.addArrangedSubview(topChromeRightRow)
        toolRow.setContentCompressionResistancePriority(.required, for: .vertical)
        toolRow.setContentHuggingPriority(.required, for: .vertical)
        topChromeLeftRow.setContentCompressionResistancePriority(.required, for: .vertical)
        topChromeRightRow.setContentCompressionResistancePriority(.required, for: .vertical)
        modelStatusStack.isHidden = true

        let bar = UIStackView(arrangedSubviews: [toolRow])
        bar.axis = .vertical
        bar.spacing = 10
        bar.setContentCompressionResistancePriority(.required, for: .vertical)
        toolRowMinHeightConstraint = toolRow.heightAnchor.constraint(
            greaterThanOrEqualToConstant: MagicBrushyChromeMetrics.chromeButtonSide(traitCollection)
        )
        toolRowMinHeightConstraint.isActive = true

        // ── Canvas ────────────────────────────────────────────────────────────
        canvasContainer.translatesAutoresizingMaskIntoConstraints = false
        canvasContainer.backgroundColor = .clear
        // Keep the drawing stack below the right rail so crayon tips can overlap the canvas visually.
        canvasContainer.layer.zPosition = 0

        templateView.translatesAutoresizingMaskIntoConstraints = false
        strokeView.translatesAutoresizingMaskIntoConstraints = false
        templateLineOverlayView.translatesAutoresizingMaskIntoConstraints = false
        templateLineOverlayView.contentMode = .scaleAspectFit
        templateLineOverlayView.layer.minificationFilter = .linear
        templateLineOverlayView.layer.magnificationFilter = .linear
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

        paintRow.axis = .horizontal
        paintRow.alignment = .fill
        paintRow.spacing = 10
        paintRow.clipsToBounds = false
        paintRow.translatesAutoresizingMaskIntoConstraints = false
        canvasContainer.setContentHuggingPriority(.defaultLow, for: .horizontal)
        canvasContainer.setContentCompressionResistancePriority(.defaultLow, for: .horizontal)
        paintRow.addArrangedSubview(canvasContainer)
        paintRow.addArrangedSubview(rightPanelStack)

        bar.translatesAutoresizingMaskIntoConstraints = false
        paintRow.translatesAutoresizingMaskIntoConstraints = false

        headerChromeStack.addArrangedSubview(bar)
        headerChromeStack.axis = .vertical
        headerChromeStack.spacing = 8
        headerChromeStack.translatesAutoresizingMaskIntoConstraints = false
        headerChromeStack.isLayoutMarginsRelativeArrangement = false
        headerChromeStack.insetsLayoutMarginsFromSafeArea = false
        headerChromeStack.setContentCompressionResistancePriority(.required, for: .vertical)
        headerChromeStack.setContentHuggingPriority(.required, for: .vertical)
        view.addSubview(drawingBackgroundView)
        view.addSubview(paintRow)
        view.addSubview(headerChromeStack)
        headerChromeStack.layer.zPosition = 200

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
        // #if DEBUG
        // installVLMInputPreviewChrome()
        // #endif

        canvasAspectConstraint = canvasContainer.widthAnchor.constraint(
            equalTo: canvasContainer.heightAnchor,
            multiplier: 4 / 5
        )
        canvasAspectConstraint.priority = .defaultHigh
        let rightPanelWidth = rightPanelStack.widthAnchor.constraint(equalToConstant: ColoringCrayonPaletteLayout.rightPanelWidth)
        rightPanelWidth.priority = .required
        rightPanelWidthConstraint = rightPanelWidth

        NSLayoutConstraint.activate([
            drawingBackgroundView.topAnchor.constraint(equalTo: view.topAnchor),
            drawingBackgroundView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            drawingBackgroundView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            drawingBackgroundView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            headerChromeStack.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -TopChromeMetrics.menuTrailingInset),
            paintRow.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -6),

            canvasContainer.heightAnchor.constraint(greaterThanOrEqualToConstant: 200),
            canvasAspectConstraint,
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
        ])
        paintRowLeadingConstraint = paintRow.leadingAnchor.constraint(
            equalTo: g.leadingAnchor,
            constant: TopChromeMetrics.menuHorizontalInset
        )
        paintRowTrailingConstraint = paintRow.trailingAnchor.constraint(
            equalTo: g.trailingAnchor,
            constant: -10
        )
        // Phone uses the real screen edge so the crayon panel has no safe-area gap on the right.
        paintRowTrailingScreenEdgeConstraint = paintRow.trailingAnchor.constraint(
            equalTo: view.trailingAnchor
        )
        paintRowLeadingConstraint.isActive = true
        paintRowTrailingConstraint.isActive = true
        headerTopConstraint = headerChromeStack.topAnchor.constraint(
            equalTo: view.safeAreaLayoutGuide.topAnchor,
            constant: TopChromeMetrics.menuTopOffset
        )
        headerLeadingCanvasConstraint = headerChromeStack.leadingAnchor.constraint(
            equalTo: canvasContainer.leadingAnchor,
            constant: TopChromeMetrics.navRowCanvasLeadingAlignmentOffset
        )
        headerLeadingPaintRowConstraint = headerChromeStack.leadingAnchor.constraint(
            equalTo: paintRow.leadingAnchor,
            constant: 0
        )
        paintRowTopToHeaderBottomConstraint = paintRow.topAnchor.constraint(
            equalTo: headerChromeStack.bottomAnchor,
            constant: 8
        )
        paintRowTopToHeaderTopConstraint = paintRow.topAnchor.constraint(
            equalTo: headerChromeStack.topAnchor
        )
        paintRowTopToSafeAreaConstraint = paintRow.topAnchor.constraint(
            equalTo: view.safeAreaLayoutGuide.topAnchor,
            constant: 4
        )
        coloringOnPhone = ColoringOnPhone(host: makeColoringOnPhoneHost())
        coloringOnPhone.installChromeRows(navSide: navSide)
        coloringOnPhone.onZoomChanged = { [weak self] in
            guard let self else { return }
            self.applyCanvasVisualTransform()
            self.coloringOnPhone.updateZoomGesturesEnabled(for: self.traitCollection)
        }
        headerTopConstraint.isActive = true
        headerLeadingCanvasConstraint.isActive = true
        paintRowTopToHeaderBottomConstraint.isActive = true

        // #if DEBUG
        // activateVLMInputPreviewConstraints(safeGuide: g)
        // #endif

        let presetCount = strokeWidthPresets.count
        if isFreeDrawingSession || MagicBrushyChromeMetrics.isPhone(traitCollection) {
            selectedStrokeSizeIndex = 0
        } else {
            selectedStrokeSizeIndex = max(0, presetCount / 2)
        }
        brushSizeChrome.dotCount = presetCount
        brushSizeChrome.selectedIndex = selectedStrokeSizeIndex
        applyStrokeWidthFromSelection()
        refreshStrokeSizeAppearance()

        installPhoneCanvasZoomGestures()
        applyLayoutForTraitCollection(traitCollection)
        applyCanvasVisualTransform()

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

    private func activeCrayonStrokeColor() -> UIColor {
        if isEraserMode { return .white }
        let i = strokePaletteIndex.clamped(to: 0...(palette.count - 1))
        return palette[i]
    }

    private func refreshStrokeSizeAppearance() {
        let index = selectedStrokeSizeIndex.clamped(to: 0...(strokeWidthPresets.count - 1))
        // Never reset dotCount here — it rebuilds all buttons unnecessarily and wipes their frames.
        brushSizeChrome.selectedIndex = index
        brushSizeChrome.dotFillColor = activeCrayonStrokeColor()
        let preset = strokeWidthPresets[index]
        brushSizeChrome.bar.accessibilityValue = "\(Int(preset)) points wide"
    }

    private func applyStrokeWidthFromSelection() {
        let index = selectedStrokeSizeIndex.clamped(to: 0...(strokeWidthPresets.count - 1))
        strokeView.strokeWidth = strokeWidthPresets[index]
    }

    private static let eraserToolIdleFill = UIColor(red: 1, green: 0.93, blue: 0.86, alpha: 1)

    private static func toolIconSide(for tc: UITraitCollection) -> CGFloat {
        let toolSide = MagicBrushyChromeMetrics.isPhone(tc)
            ? ColoringOnPhoneMetrics.toolButtonSide
            : ColoringCrayonPaletteLayout.toolButtonHeight
        return toolSide * 0.68
    }

    private func makeBrushToolButton() -> UIButton {
        let b = UIButton(type: .custom)
        b.tag = 0
        styleChromeButton(b, fill: FigmaTheme.primaryOrange, border: FigmaTheme.primaryOrangeBorder, cornerRadius: 14)
        let iconSide = Self.toolIconSide(for: traitCollection)
        if let img = UIImage(named: "FigmaBrush") {
            let iv = UIImageView(image: img)
            iv.contentMode = .scaleAspectFit
            iv.translatesAutoresizingMaskIntoConstraints = false
            iv.isUserInteractionEnabled = false
            iv.transform = CGAffineTransform(rotationAngle: .pi / 4)
            b.addSubview(iv)
            NSLayoutConstraint.activate([
                iv.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                iv.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                iv.widthAnchor.constraint(equalToConstant: iconSide),
                iv.heightAnchor.constraint(equalToConstant: iconSide),
            ])
        } else {
            let icon = PaintBrushIconView()
            icon.translatesAutoresizingMaskIntoConstraints = false
            icon.isUserInteractionEnabled = false
            b.addSubview(icon)
            NSLayoutConstraint.activate([
                icon.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                icon.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                icon.widthAnchor.constraint(equalToConstant: iconSide),
                icon.heightAnchor.constraint(equalToConstant: iconSide),
            ])
        }
        b.addTarget(self, action: #selector(toolModeTapped(_:)), for: .touchUpInside)
        b.translatesAutoresizingMaskIntoConstraints = false
        let toolSide = ColoringCrayonPaletteLayout.toolButtonHeight
        let brushH = b.heightAnchor.constraint(equalToConstant: toolSide)
        let brushW = b.widthAnchor.constraint(equalToConstant: toolSide)
        brushH.isActive = true
        brushW.isActive = true
        toolButtonHeightConstraints.append(brushH)
        toolButtonWidthConstraints.append(brushW)
        return b
    }

    private func makeEraserToolButton() -> UIButton {
        let b = UIButton(type: .custom)
        b.tag = 1
        styleChromeButton(b, fill: Self.eraserToolIdleFill, border: FigmaTheme.primaryOrangeBorder, cornerRadius: 14)
        b.layer.borderWidth = 5
        b.layer.shadowOpacity = 0.28
        b.layer.shadowRadius = 5
        let iconSide = Self.toolIconSide(for: traitCollection)
        if let img = UIImage(named: "FigmaEraser") {
            let iv = UIImageView(image: img)
            iv.contentMode = .scaleAspectFit
            iv.translatesAutoresizingMaskIntoConstraints = false
            iv.isUserInteractionEnabled = false
            b.addSubview(iv)
            NSLayoutConstraint.activate([
                iv.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                iv.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                iv.widthAnchor.constraint(equalToConstant: iconSide),
                iv.heightAnchor.constraint(equalToConstant: iconSide),
            ])
        } else {
            let icon = EraserIconView()
            icon.translatesAutoresizingMaskIntoConstraints = false
            icon.isUserInteractionEnabled = false
            b.addSubview(icon)
            NSLayoutConstraint.activate([
                icon.centerXAnchor.constraint(equalTo: b.centerXAnchor),
                icon.centerYAnchor.constraint(equalTo: b.centerYAnchor),
                icon.widthAnchor.constraint(equalToConstant: iconSide),
                icon.heightAnchor.constraint(equalToConstant: iconSide),
            ])
        }
        b.addTarget(self, action: #selector(toolModeTapped(_:)), for: .touchUpInside)
        b.translatesAutoresizingMaskIntoConstraints = false
        let toolSide = ColoringCrayonPaletteLayout.toolButtonHeight
        let eraserH = b.heightAnchor.constraint(equalToConstant: toolSide)
        let eraserW = b.widthAnchor.constraint(equalToConstant: toolSide)
        eraserH.isActive = true
        eraserW.isActive = true
        toolButtonHeightConstraints.append(eraserH)
        toolButtonWidthConstraints.append(eraserW)
        return b
    }

    @objc private func homeTapped() {
        interruptCoachAudioAndWork()
        guard let packId = sessionPackId else {
            navigationController?.popToRootViewController(animated: true)
            return
        }

        let isFreeDrawing = packId == BuiltInColoringPages.savedDrawingsPackId

        if isFreeDrawing, strokeView.hasUserPaint, coloringBookPages.indices.contains(pageIndex) {
            // Persist free-drawing session to LastDrawingStore so it appears in the grid.
            let title = coloringBookPages[pageIndex].title
            // Legacy flat resume hides the line overlay; outlines live inside the JPEG — no true line-free underlay to save.
            let canSaveLineFreeUnderlay = resumeSnapshotView.isHidden || !templateLineOverlayView.isHidden
            let composite = captureCanvasForSavedDrawing(includeLineOverlay: true)
            let underlay = canSaveLineFreeUnderlay
                ? captureCanvasForSavedDrawing(includeLineOverlay: false)
                : nil
            let thumbMaxEdge = SavedDrawingCapture.galleryThumbnailMaxEdge
            let continueTargetId = continuingSavedDrawingId ?? LastDrawingStore.peekContinueDrawingSessionId()
            if let existingId = continueTargetId {
                let didUpdate = LastDrawingStore.updateRecord(
                    id: existingId,
                    packId: packId,
                    pageIndex: pageIndex,
                    pageTitle: title,
                    composite: composite,
                    resumeUnderlay: underlay,
                    thumbnailMaxEdge: thumbMaxEdge
                )
                if !didUpdate {
                    _ = LastDrawingStore.save(
                        packId: packId,
                        pageIndex: pageIndex,
                        pageTitle: title,
                        composite: composite,
                        resumeUnderlay: underlay,
                        thumbnailMaxEdge: thumbMaxEdge
                    )
                }
                continuingSavedDrawingId = nil
            } else {
                _ = LastDrawingStore.save(
                    packId: packId,
                    pageIndex: pageIndex,
                    pageTitle: title,
                    composite: composite,
                    resumeUnderlay: underlay,
                    thumbnailMaxEdge: thumbMaxEdge
                )
            }
            LastDrawingStore.clearContinueDrawingSession()

        } else if !isFreeDrawing {
            // Persist template coloring so the child's work remains when they return.
            saveCurrentTemplateProgressIfNeeded()
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
        updateToolButtonChrome()
        refreshStrokeSizeAppearance()
    }

    private func updateToolButtonChrome() {
        let selectedFill = FigmaTheme.primaryOrange
        let idleFill = Self.eraserToolIdleFill
        let border = FigmaTheme.primaryOrangeBorder
        brushToolButton?.backgroundColor = isEraserMode ? idleFill : selectedFill
        brushToolButton?.layer.borderColor = border.cgColor
        eraserToolButton?.backgroundColor = isEraserMode ? selectedFill : idleFill
        eraserToolButton?.layer.borderColor = border.cgColor
        brushToolButton?.alpha = isEraserMode ? 0.55 : 1.0
        eraserToolButton?.alpha = isEraserMode ? 1.0 : 0.95
    }

    deinit {
        pollTimer?.invalidate()
        cancelFeedbackIdleTimer()
        NotificationCenter.default.removeObserver(self)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Keep the shared model loaded; only stop active generation on this screen.
        vlm.cancel()
        refreshModelStatusIndicator()
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        let sizeClassChanged = previousTraitCollection?.verticalSizeClass != traitCollection.verticalSizeClass
        let idiomChanged = previousTraitCollection?.userInterfaceIdiom != traitCollection.userInterfaceIdiom
        guard sizeClassChanged || idiomChanged else { return }
        applyLayoutForTraitCollection(traitCollection)
    }

    private func updateCrayonScrollViewportHeightIfNeeded() {
        crayonScrollViewportHeightConstraint?.constant = ColoringCrayonPaletteLayout.scrollViewportHeight(for: traitCollection)
    }

    /// Adjusts button and panel sizes for iPhone vs iPad (and tighter spacing in landscape).
    private func applyLayoutForTraitCollection(_ tc: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(tc)
        let compact = tc.verticalSizeClass == .compact
        let navSize = MagicBrushyChromeMetrics.chromeButtonSide(tc)
        let panelWidth = phone
            ? coloringOnPhone.sidePanelWidth(for: tc, brushDotCount: strokeWidthPresets.count)
            : BrushiMascotLayout.rightRailWidth(for: tc)
        let toolHeight: CGFloat = phone
            ? ColoringOnPhoneMetrics.toolButtonSide
            : ColoringCrayonPaletteLayout.toolButtonHeight
        let navCorner = MagicBrushyChromeMetrics.chromeCornerRadius(tc)
        let navBorder = MagicBrushyChromeMetrics.chromeBorderWidth(tc)
        let navChromeInsets = MagicBrushyChromeMetrics.navChromeContentInsets
        let barSize = ColoringFigmaToolbarChrome.brushBarSize(for: tc, dotCount: strokeWidthPresets.count)

        for c in navButtonSizeConstraints { c.constant = navSize }
        for c in toolButtonHeightConstraints { c.constant = toolHeight }
        for c in toolButtonWidthConstraints { c.constant = toolHeight }
        toolPairStackHeightConstraint?.constant = toolHeight
        rightPanelWidthConstraint?.constant = panelWidth
        brushSizeChrome.dotCount = strokeWidthPresets.count
        let chromeSide = navSize
        brushSizeChrome.applyMetrics(
            expandedWidth: barSize.width,
            expandedHeight: barSize.height,
            collapsedSide: chromeSide,
            traitCollection: tc
        )
        brushSizeChrome.configureForPhone(phone, traitCollection: tc)
        topChromeLeftRowHeightConstraint?.constant = chromeSide
        topChromeRightRowHeightConstraint?.constant = chromeSide
        coloringOnPhone.updateChromeRowHeights(chromeSide)
        topChromeRightRow.spacing = (phone && compact) ? 6 : 10
        topChromeLeftRow.spacing = phone ? 6 : 8

        for b in chromeNavButtons {
            b.layer.cornerRadius = navCorner
            b.layer.borderWidth = navBorder
            if b === homeButton {
                MagicBrushyChromeMetrics.applyHomeNavChrome(
                    to: b,
                    image: MagicBrushyChromeMetrics.chromeNavHomeImage(),
                    traitCollection: tc
                )
            } else if b === cameraChromeButton {
                MagicBrushyChromeMetrics.applySquareChrome(
                    to: b,
                    fill: FigmaTheme.actionBlue,
                    border: FigmaTheme.actionBlueBorder,
                    traitCollection: tc,
                    contentInsets: navChromeInsets
                )
            } else if b === undoChromeButton {
                MagicBrushyChromeMetrics.applySquareChrome(
                    to: b,
                    fill: ColoringFigmaToolbarChrome.undoGreen,
                    border: ColoringFigmaToolbarChrome.undoGreenBorder,
                    traitCollection: tc,
                    contentInsets: navChromeInsets
                )
            }
        }
        settingsGearButton?.applyStyle(for: tc)
        toolRowMinHeightConstraint?.constant = MagicBrushyChromeMetrics.chromeButtonSide(tc)

        let crayonRowH = phone
            ? ColoringOnPhoneMetrics.crayonRowHeight(phonePanelWidth: panelWidth)
            : ColoringCrayonPaletteLayout.crayonRowHeight(for: tc)
        for c in crayonRowHeightConstraints { c.constant = crayonRowH }
        crayonStack.spacing = ColoringCrayonPaletteLayout.crayonStackSpacing(for: tc)
        crayonScrollViewportHeightConstraint?.constant = phone
            ? ColoringCrayonPaletteLayout.scrollViewportHeight(for: tc, phonePanelWidth: panelWidth)
            : ColoringCrayonPaletteLayout.scrollViewportHeight(for: tc)

        updateMascotDisplaySize(for: tc)
        toolPairStack.axis = .horizontal
        toolPairStack.distribution = phone ? .fillEqually : .fill
        coloringOnPhone.applyLayout(
            isPhone: phone,
            traitCollection: tc,
            brushDotCount: strokeWidthPresets.count,
            setCanvasAspectRatio: { [weak self] ratio, priority in
                self?.setCanvasAspectRatio(widthOverHeight: ratio, priority: priority)
            },
            applyCanvasVisualTransform: { [weak self] in
                self?.applyCanvasVisualTransform()
            }
        )
        coloringOnPhone.updateZoomGesturesEnabled(for: tc)
        if !phone {
            coloringOnPhone.resetZoom(applyCanvasVisualTransform: { [weak self] in
                self?.applyCanvasVisualTransform()
            })
        }
    }

    private func setCanvasAspectRatio(widthOverHeight ratio: CGFloat, priority: UILayoutPriority) {
        canvasAspectConstraint?.isActive = false
        canvasAspectConstraint = canvasContainer.widthAnchor.constraint(
            equalTo: canvasContainer.heightAnchor,
            multiplier: ratio
        )
        canvasAspectConstraint.priority = priority
        if !coloringOnPhone.usesCanvasOverlayLayout {
            canvasAspectConstraint.isActive = true
        }
    }

    private func installPhoneCanvasZoomGestures() {
        coloringOnPhone.installCanvasZoomGestures(on: canvasContainer, traitCollection: traitCollection)
    }

    private func applyCanvasVisualTransform() {
        canvasContainer.transform = coloringOnPhone.canvasTransform(for: traitCollection)
    }

    private func makeColoringOnPhoneHost() -> ColoringOnPhone.Host {
        ColoringOnPhone.Host(
            view: view,
            paintRow: paintRow,
            canvasContainer: canvasContainer,
            headerChromeStack: headerChromeStack,
            rightPanelStack: rightPanelStack,
            mascotContainer: mascotContainer,
            toolPairStack: toolPairStack,
            crayonScrollContainer: crayonScrollContainer,
            homeButton: homeButton,
            cameraChromeButton: cameraChromeButton,
            undoChromeButton: undoChromeButton,
            brushSizeChrome: brushSizeChrome,
            settingsGearButton: settingsGearButton,
            topChromeLeftRow: topChromeLeftRow,
            topChromeRightRow: topChromeRightRow,
            rightPanelPhoneTopSpacer: rightPanelPhoneTopSpacer,
            rightPanelPhoneTopSpacerHeight: rightPanelPhoneTopSpacerHeight,
            paintRowLeadingConstraint: paintRowLeadingConstraint,
            paintRowTrailingConstraint: paintRowTrailingConstraint,
            paintRowTrailingScreenEdgeConstraint: paintRowTrailingScreenEdgeConstraint,
            headerLeadingCanvasConstraint: headerLeadingCanvasConstraint,
            headerLeadingPaintRowConstraint: headerLeadingPaintRowConstraint,
            paintRowTopToHeaderBottomConstraint: paintRowTopToHeaderBottomConstraint,
            paintRowTopToHeaderTopConstraint: paintRowTopToHeaderTopConstraint,
            paintRowTopToSafeAreaConstraint: paintRowTopToSafeAreaConstraint,
            headerTopConstraint: headerTopConstraint,
            rightPanelWidthConstraint: rightPanelWidthConstraint,
            mascotRailWidthConstraint: mascotRailWidthConstraint,
            mascotImageCenterXConstraint: mascotImageCenterXConstraint,
            mascotImageLeadingConstraint: mascotImageLeadingConstraint,
            mascotImageTopConstraint: mascotImageTopConstraint,
            setStackCanvasAspectConstraintActive: { [weak self] active in
                self?.canvasAspectConstraint.isActive = active
            }
        )
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        applyLayoutForTraitCollection(traitCollection)
        navigationController?.view.backgroundColor = .black
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
        applyPendingResumeCompositeIfNeeded()
        updateCrayonScrollViewportHeightIfNeeded()
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
        schedulePageLoadWelcome()
        scheduleMascotInactivityTimer()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        if isMovingFromParent {
            LastDrawingStore.clearContinueDrawingSession()
        }
        interruptCoachAudioAndWork()
        FeedbackAlbaSpeech.mascotLipSync = nil
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

    private func cancelPendingPageWelcomeWork() {
        pendingPageWelcomeWork?.cancel()
        pendingPageWelcomeWork = nil
    }

    /// Full reset: page / clear / undo — drop pending mascot reaction and all VLM work.
    private func invalidateFeedbackSession() {
        feedbackGeneration &+= 1
        reactionSession &+= 1
        lastMascotReaction = nil
        cancelFeedbackIdleTimer()
        cancelMascotInactivityTimer()
        cancelPendingReactionWork()
        cancelPendingPageWelcomeWork()
        vlm.cancel()
        hideVLMInputPreviewImmediate()
    }

    /// Stop mascot speech immediately and cancel pending coach VLM / welcome work (home, page change, leave).
    private func interruptCoachAudioAndWork() {
        invalidateFeedbackSession()
        FeedbackAlbaSpeech.stopSpeaking()
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
        wakeMascotFromInactivitySleepy()
        invalidatePaintingFeedbackOnly()
        FeedbackAlbaSpeech.stopSpeaking()
        scheduleMascotInactivityTimer()
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
        // Eraser pen-lift: do not schedule idle coach VLM.
        guard !isEraserMode else { return }
        // Settings coach-feedback off: skip auto-feedback.
        if !MagicBrushyCoachAutoFeedback.isEnabled { return }

        let work = DispatchWorkItem { [weak self] in
            guard let self else { return }
            self.pendingAutoFeedbackWork = nil
            // Re-check at fire time (user may have turned coach feedback off after stroke ended).
            if !MagicBrushyCoachAutoFeedback.isEnabled { return }
            // User may have switched to eraser before the idle delay elapsed.
            guard !self.isEraserMode else { return }
            self.runSpeechFeedbackPipeline()
        }
        pendingAutoFeedbackWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + Self.feedbackIdleTriggerDelay, execute: work)
        scheduleMascotInactivityTimer()
    }

    private func cancelMascotInactivityTimer() {
        mascotInactivityWork?.cancel()
        mascotInactivityWork = nil
    }

    private func scheduleMascotInactivityTimer() {
        cancelMascotInactivityTimer()
        guard view.window != nil else { return }
        if !MagicBrushyCoachAutoFeedback.isEnabled { return }

        let work = DispatchWorkItem { [weak self] in
            guard let self else { return }
            self.mascotInactivityWork = nil
            self.applyLongInactivitySleepyIfNeeded()
        }
        mascotInactivityWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + Self.mascotLongInactivityDelay, execute: work)
    }

    private func wakeMascotFromInactivitySleepy() {
        guard mascotShowingSleepyFromInactivity || lastMascotReaction == .sleepy else { return }
        mascotShowingSleepyFromInactivity = false
        applyMascotReaction(.neutral)
    }

    private func applyLongInactivitySleepyIfNeeded() {
        guard view.window != nil else { return }
        if !MagicBrushyCoachAutoFeedback.isEnabled { return }
        if vlm.running {
            scheduleMascotInactivityTimer()
            return
        }
        mascotShowingSleepyFromInactivity = true
        applyMascotReaction(.sleepy)
    }

    @objc private func coachAutoFeedbackSettingChanged() {
        guard !MagicBrushyCoachAutoFeedback.isEnabled else { return }
        cancelFeedbackIdleTimer()
        cancelPendingReactionWork()
        FeedbackAlbaSpeech.stopSpeaking()
        vlm.cancel()
        applyMascotReaction(.supportive)
    }

    private func playMascotClapHaptics() {
        let a = UIImpactFeedbackGenerator(style: .medium)
        a.prepare()
        a.impactOccurred()
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.09) {
            UIImpactFeedbackGenerator(style: .light).impactOccurred()
        }
    }

    /// Tapping the mascot: haptic “clap”, then coach praise for the **entire** page via VLM.
    @objc private func mascotTapped() {
        playMascotClapHaptics()
        applyMascotReaction(.celebrating)

        feedbackGeneration &+= 1
        let gen = feedbackGeneration
        cancelFeedbackIdleTimer()
        cancelPendingReactionWork()
        FeedbackAlbaSpeech.stopSpeaking()
        vlm.cancel()

        runMascotWholeDrawingCheer(feedbackGen: gen)
    }

    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldReceive touch: UITouch) -> Bool {
        if coloringOnPhone.isPhoneCanvasGesture(gestureRecognizer) {
            return true
        }
        return true
    }

    func gestureRecognizer(
        _ gestureRecognizer: UIGestureRecognizer,
        shouldRecognizeSimultaneouslyWith otherGestureRecognizer: UIGestureRecognizer
    ) -> Bool {
        if coloringOnPhone.isPhoneCanvasGesture(gestureRecognizer) {
            return otherGestureRecognizer.view === strokeView || otherGestureRecognizer.view?.isDescendant(of: strokeView) == true
        }
        return false
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
            if pct > 0 {
                modelStatusLabel.text = "AI: Download the model… \(pct)%"
                modelStatusStack.accessibilityLabel = "Downloading the art coach model, \(pct) percent complete"
            } else {
                modelStatusLabel.text = "AI: Loading…"
                modelStatusStack.accessibilityLabel = "Loading art coach model"
            }
        case .loadingIntoMemory:
            modelStatusDot.backgroundColor = .systemBlue
            modelStatusLabel.text = "AI: Loading…"
            modelStatusStack.accessibilityLabel = "Loading art coach model"
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

    /// Model download / load chip lives on `HomeViewController` only; keep chrome unobstructed here.
    private func refreshLoadOverlay() {
        loadOverlay.isHidden = true
        loadOverlay.isUserInteractionEnabled = false
    }

    /// Saves strokes for the current template page (non-free-drawing) so they survive a page switch or home tap.
    private func saveCurrentTemplateProgressIfNeeded() {
        guard let packId = sessionPackId,
              packId != BuiltInColoringPages.savedDrawingsPackId else { return }
        let hasPaint = strokeView.hasUserPaint || !resumeSnapshotView.isHidden
        guard hasPaint else { return }
        let canSaveLineFreeUnderlay = resumeSnapshotView.isHidden || !templateLineOverlayView.isHidden
        guard canSaveLineFreeUnderlay else { return }
        let pxScale = view.window?.screen.scale ?? UIScreen.main.scale
        let underlay = captureCanvasBitmap(includeLineOverlay: false, displayScale: pxScale)
        TemplateProgressStore.save(packId: packId, pageIndex: pageIndex, underlay: underlay)
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
        interruptCoachAudioAndWork()
        clearResumeSnapshot()
        let page = coloringBookPages[pageIndex]
        let isBlankFreeDraw = sessionPackId == BuiltInColoringPages.savedDrawingsPackId
        if isBlankFreeDraw {
            templateView.image = page.image
            templateLineOverlayView.image = nil
            templateLineOverlayView.isHidden = true
        } else {
            // Line art only in the overlay — avoid drawing the same ink in `templateView` (looked 2× thick).
            templateView.image = nil
            templateView.backgroundColor = FigmaTheme.canvasFill
            templateLineOverlayView.image = page.image.magicBrushyLineArtOverlay()
            templateLineOverlayView.isHidden = false
        }
        strokeView.clearStrokes()
        // On mid-session page switches (no pending resume set by the caller), restore saved template progress.
        // The initial page load uses pendingResumeComposite instead (applied after layout via applyPendingResumeCompositeIfNeeded).
        if pendingResumeComposite == nil,
           let packId = sessionPackId,
           packId != BuiltInColoringPages.savedDrawingsPackId,
           let underlay = TemplateProgressStore.load(packId: packId, pageIndex: pageIndex) {
            resumeSnapshotView.image = underlay
            resumeSnapshotView.isHidden = false
            templateView.isHidden = true
            // Line overlay stays visible above the snapshot.
        }
        schedulePageLoadWelcome()
    }

    @objc private func clearStrokes() {
        interruptCoachAudioAndWork()
        strokeView.clearStrokes()
    }

    @objc private func undoStroke() {
        interruptCoachAudioAndWork()
        guard strokeView.undoLastStroke() else { return }
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }

    @objc private func redoStroke() {
        interruptCoachAudioAndWork()
        guard strokeView.redoLastStroke() else { return }
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
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
            let labels = MascotReactionState.allCases.map { String(describing: $0) }
            let reactionPrompt = Prompt.mascotReactionClassification(poseLabels: labels)

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
            let previewImage = self.prepareImageForVLMInput(img)
            let prompt = self.makeStrokeFeedbackPrompt()
            // self.showVLMInputPreview(previewImage, prompt: prompt, tag: "Stroke")

            let strokeTokenCap = VLMCoachTokenLimits.strokeFeedbackMaxOutput
            model.maxTokens = strokeTokenCap
            #if DEBUG
            print("""
            [Brushi][VLM][Feedback] image \(Int(img.size.width))x\(Int(img.size.height)), max tokens \(strokeTokenCap)
            \(prompt)
            """)
            #endif
            let task = await model.generate(
                image: previewImage,
                prompt: prompt,
                maxOutputTokens: strokeTokenCap
            )
            await task.value
            guard feedbackGen == self.feedbackGeneration else { return }
            let raw = model.output.trimmingCharacters(in: .whitespacesAndNewlines)
            let pose = Reaction.mascotPoseFromCoachResponse(raw, avoidingRepeatOf: self.lastMascotReaction)
            self.applyMascotReaction(pose)

            let spoken = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(raw)
            #if DEBUG
            print("[Brushi][VLM][Feedback] mascot pose: \(String(describing: pose))")
            print("[Brushi][VLM][Feedback] spoken: \(spoken)")
            #endif
            guard !spoken.isEmpty, spoken != "…",
                  !spoken.hasPrefix("Failed:") else { return }
            await FeedbackAlbaSpeech.speakFeedback(spoken)
        }
    }

    /// After a page is shown: VLM names the scene, notes prior color if any, and encourages finishing the page.
    private func schedulePageLoadWelcome() {
        #if targetEnvironment(simulator)
        return
        #endif
        cancelPendingPageWelcomeWork()
        guard coloringBookPages.indices.contains(pageIndex) else { return }
        guard welcomedPageIndices.contains(pageIndex) == false else { return }
        if !MagicBrushyCoachAutoFeedback.isEnabled { return }

        let pageAtSchedule = pageIndex
        let work = DispatchWorkItem { [weak self] in
            self?.runPageLoadWelcome(pageAtSchedule: pageAtSchedule)
        }
        pendingPageWelcomeWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.3, execute: work)
    }

    private func runPageLoadWelcome(pageAtSchedule: Int) {
        #if targetEnvironment(simulator)
        return
        #endif
        guard pageAtSchedule == pageIndex else { return }
        guard coloringBookPages.indices.contains(pageIndex) else { return }
        guard !welcomedPageIndices.contains(pageIndex) else { return }
        if !MagicBrushyCoachAutoFeedback.isEnabled { return }

        let welcomeGen = feedbackGeneration
        applyMascotReaction(.hello)
        vlm.cancel()
        FeedbackAlbaSpeech.stopSpeaking()

        Task { @MainActor [weak self] in
            guard let self else { return }
            let model = self.modelForInference()
            var spins = 0
            while model.running, spins < 120 {
                try? await Task.sleep(nanoseconds: 80_000_000)
                spins += 1
            }
            guard !model.running else { return }
            guard welcomeGen == self.feedbackGeneration else { return }
            guard pageAtSchedule == self.pageIndex else { return }
            guard !self.welcomedPageIndices.contains(pageAtSchedule) else { return }

            self.view.layoutIfNeeded()
            self.applyPendingResumeCompositeIfNeeded()
            let bounds = self.strokeView.bounds
            guard bounds.width >= 16, bounds.height >= 16 else {
                self.schedulePageLoadWelcome()
                return
            }

            self.welcomedPageIndices.insert(pageAtSchedule)

            if self.isFreeDrawingSession, self.freeDrawPageIsVisuallyBlankForWelcome() {
                let spoken = Prompt.freeDrawEmptyPageEncouragement()
                #if DEBUG
                print("[Brushi][VLM][PageLoad][FreeDraw] blank page — local welcome: \(spoken)")
                #endif
                guard !spoken.isEmpty else { return }
                await FeedbackAlbaSpeech.speakFeedback(spoken)
                return
            }

            let img = self.captureCanvasForVLMFullPage()
            let prompt = self.makePageLoadWelcomePrompt()

            let tokenCap = VLMCoachTokenLimits.pageLoadWelcomeMaxOutput
            model.maxTokens = tokenCap
            #if DEBUG
            print("""
            [Brushi][VLM][PageLoad] image \(Int(img.size.width))x\(Int(img.size.height)), max tokens \(tokenCap), edge \(Int(LeapVLMModel.coachPageLoadMaxImageEdge))
            \(prompt)
            """)
            #endif
            let task = await model.generate(
                image: img,
                prompt: prompt,
                maxOutputTokens: tokenCap,
                maxImageEdge: LeapVLMModel.coachPageLoadMaxImageEdge,
                minDimensionFractionOfSource: self.usesFullPageVLMInput ? 0.35 : (1.0 / 3.0)
            )
            await task.value
            guard welcomeGen == self.feedbackGeneration else { return }
            guard pageAtSchedule == self.pageIndex else { return }

            let raw = model.output.trimmingCharacters(in: .whitespacesAndNewlines)
            let pose = Reaction.mascotPoseFromCoachResponse(raw, avoidingRepeatOf: self.lastMascotReaction)
            self.applyMascotReaction(pose)

            let spoken = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(raw)
            #if DEBUG
            print("[Brushi][VLM][PageLoad] mascot pose: \(String(describing: pose))")
            print("[Brushi][VLM][PageLoad] spoken: \(spoken)")
            #endif
            guard !spoken.isEmpty, spoken != "…",
                  !spoken.hasPrefix("Failed:") else { return }
            await FeedbackAlbaSpeech.speakFeedback(spoken)
        }
    }

    /// Mascot tap: full-page snapshot (no stroke zoom crop) and a prompt about the **entire** drawing.
    private func runMascotWholeDrawingCheer(feedbackGen: UInt64) {
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
            self.view.layoutIfNeeded()
            let bounds = self.strokeView.bounds
            guard bounds.width >= 16, bounds.height >= 16 else { return }

            let img = self.captureCanvasForVLMFullPage()
            let previewImage = self.prepareImageForVLMInput(img)
            let prompt = self.makeWholeDrawingCheerPrompt()
            // self.showVLMInputPreview(previewImage, prompt: prompt, tag: "Whole page")

            let wholePageTokenCap = VLMCoachTokenLimits.wholeDrawingMaxOutput
            model.maxTokens = wholePageTokenCap
            #if DEBUG
            print("""
            [Brushi][VLM][WholeDrawing] image \(Int(img.size.width))x\(Int(img.size.height)), max tokens \(wholePageTokenCap)
            \(prompt)
            """)
            #endif
            let task = await model.generate(
                image: previewImage,
                prompt: prompt,
                maxOutputTokens: wholePageTokenCap
            )
            await task.value
            guard feedbackGen == self.feedbackGeneration else { return }
            let raw = model.output.trimmingCharacters(in: .whitespacesAndNewlines)
            let pose = Reaction.mascotPoseFromCoachResponse(raw, avoidingRepeatOf: self.lastMascotReaction)
            self.applyMascotReaction(pose)

            let spoken = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(raw)
            #if DEBUG
            print("[Brushi][VLM][WholeDrawing] mascot pose: \(String(describing: pose))")
            print("[Brushi][VLM][WholeDrawing] spoken: \(spoken)")
            #endif
            guard !spoken.isEmpty, spoken != "…",
                  !spoken.hasPrefix("Failed:") else { return }
            await FeedbackAlbaSpeech.speakFeedback(spoken)
        }
    }

    private func applyMascotReaction(_ state: MascotReactionState) {
        guard let image = state.loadImage() else { return }
        lastMascotReaction = state
        if state == .sleepy {
            mascotShowingSleepyFromInactivity = true
        } else {
            mascotShowingSleepyFromInactivity = false
            scheduleMascotInactivityTimer()
        }
        UIView.transition(with: mascotImageView, duration: 0.22, options: .transitionCrossDissolve) {
            self.mascotImageView.image = image
        }
        updateMascotDisplaySize()
    }

    private func updateMascotDisplaySize(for traitCollection: UITraitCollection? = nil) {
        let tc = traitCollection ?? self.traitCollection
        let mascotSize = BrushiMascotLayout.coloringRailDisplaySize(for: tc, image: mascotImageView.image)
        mascotImageWidthConstraint?.constant = mascotSize.width
        mascotImageHeightConstraint?.constant = mascotSize.height
        // let sleepyVisual = lastMascotReaction == .sleepy
        // let scale = sleepyVisual ? BrushiMascotLayout.coloringSleepyVisualScale : 1
        mascotImageView.transform = .identity
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

    /// Crops a full-canvas capture (same coordinates as `strokeView.bounds`) to a subrect for the VLM. Does not change on-screen drawing.
    private func vlmImageByCroppingFullCanvas(_ full: UIImage, to strokeViewRect: CGRect) -> UIImage {
        let canvas = CGSize(width: max(1, full.size.width), height: max(1, full.size.height))
        let r = strokeViewRect.intersection(CGRect(origin: .zero, size: canvas))
        guard r.width > 8, r.height > 8 else { return full }

        let format = UIGraphicsImageRendererFormat.default()
        format.scale = full.scale
        format.opaque = true
        return UIGraphicsImageRenderer(size: r.size, format: format).image { _ in
            full.draw(at: CGPoint(x: -r.origin.x, y: -r.origin.y))
        }
    }

    /// Full coloring sheet for the vision model (no last-stroke zoom crop).
    private func captureCanvasForVLMFullPage() -> UIImage {
        captureCanvasBitmap(includeLineOverlay: true, displayScale: 1)
    }

    /// Full canvas at 1×; on iPad, optionally cropped around the last stroke (iPhone always uses the full page).
    private func captureCanvasForVLM() -> UIImage {
        let full = captureCanvasForVLMFullPage()
        guard !usesFullPageVLMInput,
              let crop = strokeView.vlmCropRectAroundLastFinishedStroke(
                minCanvasFraction: vlmStrokeCropMinCanvasFraction
              ) else { return full }
        return vlmImageByCroppingFullCanvas(full, to: crop)
    }

    private func prepareImageForVLMInput(_ image: UIImage) -> UIImage {
        let model = modelForInference()
        return model.prepareImageForModelPreview(image) ?? image
    }

    /// Scale factor so saved JPEGs have enough pixels for full-screen resume (not just point-size × 1×).
    private func exportScaleForSavedDrawing() -> CGFloat {
        view.layoutIfNeeded()
        let pt = strokeView.bounds.size
        guard pt.width > 1, pt.height > 1 else {
            return view.window?.screen.scale ?? UIScreen.main.scale
        }
        let screenScale = view.window?.screen.scale ?? UIScreen.main.scale
        let widthTarget = max(
            pt.width * screenScale,
            min(SavedDrawingCapture.minPixelWidth, pt.width * screenScale * 1.25)
        )
        var scale = widthTarget / pt.width
        let longEdge = max(pt.width, pt.height)
        if longEdge * scale > SavedDrawingCapture.maxPixelEdge {
            scale = SavedDrawingCapture.maxPixelEdge / longEdge
        }
        return max(scale, 1)
    }

    /// High-resolution capture for `LastDrawingStore` (composite + resume underlay).
    private func captureCanvasForSavedDrawing(includeLineOverlay: Bool) -> UIImage {
        captureCanvasBitmap(
            includeLineOverlay: includeLineOverlay,
            displayScale: exportScaleForSavedDrawing()
        )
    }

    /// Capture for saving to Photos (Retina resolution).
    private func captureCanvasForExport() -> UIImage {
        captureCanvasForSavedDrawing(includeLineOverlay: true)
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

    #if DEBUG
    private func installVLMInputPreviewChrome() {
        vlmInputPreviewImageView.translatesAutoresizingMaskIntoConstraints = false
        vlmInputPreviewImageView.contentMode = .scaleAspectFit
        vlmInputPreviewImageView.backgroundColor = UIColor.black.withAlphaComponent(0.65)
        vlmInputPreviewImageView.layer.cornerRadius = 10
        vlmInputPreviewImageView.layer.borderWidth = 1.5
        vlmInputPreviewImageView.layer.borderColor = UIColor.white.withAlphaComponent(0.8).cgColor
        vlmInputPreviewImageView.clipsToBounds = true
        vlmInputPreviewImageView.isHidden = true
        vlmInputPreviewImageView.isUserInteractionEnabled = false

        vlmInputPreviewLabel.translatesAutoresizingMaskIntoConstraints = false
        vlmInputPreviewLabel.font = .monospacedSystemFont(ofSize: 11, weight: .medium)
        vlmInputPreviewLabel.textColor = .white
        vlmInputPreviewLabel.textAlignment = .left
        vlmInputPreviewLabel.numberOfLines = 0
        vlmInputPreviewLabel.backgroundColor = UIColor.black.withAlphaComponent(0.72)
        vlmInputPreviewLabel.layer.cornerRadius = 8
        vlmInputPreviewLabel.clipsToBounds = true
        vlmInputPreviewLabel.isHidden = true
        view.addSubview(vlmInputPreviewImageView)
        view.addSubview(vlmInputPreviewLabel)
    }

    private func activateVLMInputPreviewConstraints(safeGuide g: UILayoutGuide) {
        NSLayoutConstraint.activate([
            vlmInputPreviewImageView.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 12),
            vlmInputPreviewImageView.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -12),
            vlmInputPreviewImageView.widthAnchor.constraint(equalTo: g.widthAnchor, multiplier: 1.0 / 3.0),
            vlmInputPreviewImageView.heightAnchor.constraint(equalTo: g.heightAnchor, multiplier: 1.0 / 3.0),

            vlmInputPreviewLabel.leadingAnchor.constraint(equalTo: vlmInputPreviewImageView.leadingAnchor, constant: 6),
            vlmInputPreviewLabel.trailingAnchor.constraint(equalTo: vlmInputPreviewImageView.trailingAnchor, constant: -6),
            vlmInputPreviewLabel.topAnchor.constraint(equalTo: vlmInputPreviewImageView.topAnchor, constant: 6),
        ])
    }
    #endif

    private func hideVLMInputPreviewImmediate() {
        #if DEBUG
        vlmInputPreviewHideWork?.cancel()
        vlmInputPreviewHideWork = nil
        vlmInputPreviewImageView.layer.removeAllAnimations()
        vlmInputPreviewLabel.layer.removeAllAnimations()
        vlmInputPreviewImageView.isHidden = true
        vlmInputPreviewLabel.isHidden = true
        vlmInputPreviewImageView.alpha = 1
        vlmInputPreviewLabel.alpha = 1
        #endif
    }

    private func showVLMInputPreview(_ image: UIImage, prompt: String, tag: String) {
        #if DEBUG
        vlmInputPreviewHideWork?.cancel()
        vlmInputPreviewImageView.image = image
        let promptPreview = prompt.trimmingCharacters(in: .whitespacesAndNewlines)
        let clipped = promptPreview.count > 280
            ? String(promptPreview.prefix(280)) + "…"
            : promptPreview
        vlmInputPreviewLabel.text = """
        VLM [\(tag)]
        \(Int(image.size.width))×\(Int(image.size.height)) px
        \(clipped)
        """
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
        DispatchQueue.main.asyncAfter(deadline: .now() + 8.0, execute: work)
        #else
        _ = image
        _ = prompt
        _ = tag
        #endif
    }

    private func currentPageTitle() -> String? {
        guard pageIndex >= 0, pageIndex < coloringBookPages.count else { return nil }
        return coloringBookPages[pageIndex].title
    }

    private func makeStrokeFeedbackPrompt() -> String {
        let lastColor = strokeView.chronologicalStrokeColors.last
        let paintName = lastColor.map { simpleKidColorName(for: $0) }
        return Prompt.strokeFeedback(
            pageTitle: currentPageTitle(),
            lastStrokePointCount: strokeView.lastFinishedStrokePointCount,
            lastPaintColorName: paintName,
            isFreeDrawing: isFreeDrawingSession
        )
    }

    private func makeWholeDrawingCheerPrompt() -> String {
        Prompt.wholeDrawingCheer(
            pageTitle: currentPageTitle(),
            isFreeDrawing: isFreeDrawingSession
        )
    }

    private func makePageLoadWelcomePrompt() -> String {
        let hasPriorPaint = canvasHasPriorPaintForPageWelcome()
        return Prompt.pageLoadWelcome(
            pageTitle: currentPageTitle(),
            hasPriorPaint: hasPriorPaint,
            isFreeDrawing: isFreeDrawingSession
        )
    }

    /// Saved underlay, pending resume, or live strokes when the page opens (not a blank sheet).
    private func canvasHasPriorPaintForPageWelcome() -> Bool {
        if strokeView.hasUserPaint { return true }
        if pendingResumeComposite != nil { return true }
        if !resumeSnapshotView.isHidden, resumeSnapshotView.image != nil { return true }
        return false
    }

    /// Free draw only: local empty-page line when the canvas is still fully blank (not when resuming art).
    private func freeDrawPageIsVisuallyBlankForWelcome() -> Bool {
        applyPendingResumeCompositeIfNeeded()
        if canvasHasPriorPaintForPageWelcome() { return false }
        return !freeDrawCapturedCanvasHasVisibleMarks()
    }

    /// Samples the composed canvas (paper + resume + strokes) for any non-white marks.
    private func freeDrawCapturedCanvasHasVisibleMarks() -> Bool {
        let img = captureCanvasBitmap(includeLineOverlay: false, displayScale: 1)
        guard let raw = renderSmallRGBAThumbnail(from: img, side: 48) else { return false }
        let side = 48
        var markPixels = 0
        let minMarks = 10
        for row in 0..<side {
            for col in 0..<side {
                let base = (row * side + col) * 4
                let a = raw[base + 3]
                guard a > 12 else { continue }
                let r = Int(raw[base])
                let g = Int(raw[base + 1])
                let b = Int(raw[base + 2])
                if r < 248 || g < 248 || b < 248 {
                    markPixels += 1
                    if markPixels >= minMarks { return true }
                }
            }
        }
        return false
    }

    private func renderSmallRGBAThumbnail(from image: UIImage, side: Int) -> [UInt8]? {
        guard let cgImage = image.cgImage, side > 0 else { return nil }
        var raw = [UInt8](repeating: 0, count: side * side * 4)
        let ok: Bool = raw.withUnsafeMutableBytes { buf in
            guard let ctx = CGContext(
                data: buf.baseAddress,
                width: side,
                height: side,
                bitsPerComponent: 8,
                bytesPerRow: side * 4,
                space: CGColorSpaceCreateDeviceRGB(),
                bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue
            ) else { return false }
            ctx.interpolationQuality = .medium
            ctx.draw(cgImage, in: CGRect(x: 0, y: 0, width: side, height: side))
            return true
        }
        return ok ? raw : nil
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

// MARK: - Crayon swatch trim

private extension UIImage {
    /// Drops transparent margins in `colors 2` PNGs so rows can size to the wax body only.
    func croppedToOpaqueContent(alphaThreshold: UInt8 = 12) -> UIImage {
        guard let cg = cgImage,
              var rect = Self.opaquePixelBounds(in: cg, threshold: alphaThreshold) else {
            return self
        }
        rect = rect.intersection(CGRect(x: 0, y: 0, width: cg.width, height: cg.height))
        guard let cropped = cg.cropping(to: rect) else { return self }
        return UIImage(cgImage: cropped, scale: scale, orientation: imageOrientation)
    }

    static func opaquePixelBounds(in cg: CGImage, threshold: UInt8) -> CGRect? {
        guard cg.bitsPerPixel == 32, cg.bitsPerComponent == 8 else { return nil }
        let w = cg.width
        let h = cg.height
        guard let data = cg.dataProvider?.data, let bytes = CFDataGetBytePtr(data) else { return nil }
        let bpr = cg.bytesPerRow
        let alphaIndex: Int
        switch cg.alphaInfo {
        case .first, .premultipliedFirst, .noneSkipFirst:
            alphaIndex = 0
        default:
            alphaIndex = 3
        }

        var minX = w
        var minY = h
        var maxX = 0
        var maxY = 0
        var found = false
        for y in 0..<h {
            let row = y * bpr
            for x in 0..<w {
                let a = bytes[row + x * 4 + alphaIndex]
                if a > threshold {
                    found = true
                    minX = min(minX, x)
                    minY = min(minY, y)
                    maxX = max(maxX, x)
                    maxY = max(maxY, y)
                }
            }
        }
        guard found else { return nil }
        return CGRect(x: minX, y: minY, width: maxX - minX + 1, height: maxY - minY + 1)
    }
}

// MARK: - Bundled crayon PNG swatches (`MagicBrushy/Colors`, synced from `colors 2/`)

private enum MagicBrushyCrayonResources {
    private static let bundleSubdirectory = "Colors"
    private static let pngCount = 30

    /// Top → bottom in the crayon rail: ROYGBIV, then earth tones, black & white last.
    static let rainbowDisplayOrder: [Int] = [
        6,                          // red
        25, 26, 5,                  // orange family
        4, 23, 24,                  // yellow family
        3, 21, 19, 18, 20,          // green family
        17, 16,                     // teal / aqua
        2,                          // sky blue
        14, 12, 13, 15,             // blues
        11, 10, 8, 9, 7,            // indigo / violet / purple / pink
        0,                          // light pink
        27, 28, 29,                 // brown, terracotta, sand
        1,                          // black
        22,                         // white
    ]

    /// `01-color.png` … `30-color.png` in the app bundle (folder reference `Colors`).
    static let swatchImages: [UIImage] = {
        var out: [UIImage] = []
        out.reserveCapacity(pngCount)
        for i in 1...pngCount {
            let name = String(format: "%02d-color", i)
            guard let url = Bundle.main.url(forResource: name, withExtension: "png", subdirectory: bundleSubdirectory),
                  let img = UIImage(contentsOfFile: url.path) else { continue }
            out.append(img.croppedToOpaqueContent())
        }
        return out
    }()

    /// Brush / VLM stroke color: sampled from the **tip** of each swatch PNG, with a few tuned overrides.
    static let strokeColors: [UIColor] = {
        var colors = swatchImages.map { strokeColorFromSwatchTip($0) }
        applyStrokeColorOverrides(&colors)
        return colors
    }()

    /// Brand-aligned stroke colors (see `FigmaTheme.Brand`).
    private static let strokeColorOverrides: [Int: UIColor] = [
        0: FigmaTheme.Brand.mascotPink,
        1: FigmaTheme.Brand.softBlack,
        2: FigmaTheme.Brand.skyBlue,
        3: FigmaTheme.Brand.successGreen,
        4: FigmaTheme.Brand.rewardYellow,
        5: FigmaTheme.Brand.playOrange,
        6: FigmaTheme.Brand.warningRed,
        8: FigmaTheme.Brand.imaginationPurple,
        9: FigmaTheme.Brand.imaginationPurple,
        22: FigmaTheme.Brand.warmWhite,
    ]

    private static func applyStrokeColorOverrides(_ colors: inout [UIColor]) {
        for (index, color) in strokeColorOverrides where colors.indices.contains(index) {
            colors[index] = color
        }
    }

    /// Renders a small RGBA thumbnail, then averages non-white / non-transparent pixels in `col` / `row` ranges.
    private static func averageColor(
        raw: [UInt8],
        side: Int,
        colRange: Range<Int>,
        rowRange: Range<Int>
    ) -> UIColor? {
        var rSum: CGFloat = 0, gSum: CGFloat = 0, bSum: CGFloat = 0
        var count: CGFloat = 0

        for row in rowRange {
            for col in colRange {
                guard col >= 0, col < side, row >= 0, row < side else { continue }
                let base = (row * side + col) * 4
                let a = raw[base + 3]
                guard a > 10 else { continue }
                let rf = CGFloat(raw[base]) / CGFloat(a)
                let gf = CGFloat(raw[base + 1]) / CGFloat(a)
                let bf = CGFloat(raw[base + 2]) / CGFloat(a)
                guard !(rf > 0.88 && gf > 0.88 && bf > 0.88) else { continue }
                rSum += rf
                gSum += gf
                bSum += bf
                count += 1
            }
        }
        guard count > 2 else { return nil }
        return UIColor(
            red: min(1, rSum / count),
            green: min(1, gSum / count),
            blue: min(1, bSum / count),
            alpha: 1
        )
    }

    private static func renderThumbnailRGBA(image: UIImage, side: Int) -> [UInt8]? {
        guard let cgImage = image.cgImage else { return nil }
        var raw = [UInt8](repeating: 0, count: side * side * 4)
        let ok: Bool = raw.withUnsafeMutableBytes { buf in
            guard let ctx = CGContext(
                data: buf.baseAddress,
                width: side,
                height: side,
                bitsPerComponent: 8,
                bytesPerRow: side * 4,
                space: CGColorSpaceCreateDeviceRGB(),
                bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue
            ) else { return false }
            ctx.interpolationQuality = .medium
            ctx.draw(cgImage, in: CGRect(x: 0, y: 0, width: side, height: side))
            return true
        }
        return ok ? raw : nil
    }

    /// Wax tip sits on the **left** of each swatch; sample a few pixels right of the outer edge.
    private static let tipColStartFraction: CGFloat = 0.10
    private static let tipColEndFraction: CGFloat = 0.28

    private static func strokeColorFromSwatchTip(_ image: UIImage) -> UIColor {
        let side = 40
        guard let raw = renderThumbnailRGBA(image: image, side: side) else { return .darkGray }

        let rowLo = side * 20 / 100
        let rowHi = side * 80 / 100
        let tipStart = max(0, Int((CGFloat(side) * tipColStartFraction).rounded(.down)))
        let tipEnd = min(side, Int((CGFloat(side) * tipColEndFraction).rounded(.up)))

        if let tip = averageColor(
            raw: raw,
            side: side,
            colRange: tipStart..<tipEnd,
            rowRange: rowLo..<rowHi
        ) {
            return tip
        }

        let leftEnd = side * 35 / 100
        if let left = averageColor(raw: raw, side: side, colRange: 0..<leftEnd, rowRange: rowLo..<rowHi) {
            return left
        }

        let midLo = side / 4
        let midHi = side - side / 4
        if let c = averageColor(raw: raw, side: side, colRange: midLo..<midHi, rowRange: midLo..<midHi) {
            return c
        }
        return .darkGray
    }
}

// MARK: - Magic crayon palette (horizontal wax crayons, scrollable)

/// Layout for the coloring screen right rail (crayons + panel width). Tuned to match Figma-style chunky crayons.
private enum ColoringCrayonPaletteLayout {
    static let rightPanelWidth: CGFloat = 210
    /// Mascot is drawn 25% larger than the base rail fit (crayon column width stays `rightPanelWidth`).
    static let mascotScale: CGFloat = 1.25
    static var mascotLayoutWidth: CGFloat { rightPanelWidth * mascotScale }

    static func mascotLayoutWidth(for traitCollection: UITraitCollection) -> CGFloat {
        BrushiMascotLayout.layoutWidth(for: traitCollection)
    }
    static let rightPanelStackSpacing: CGFloat = 10
    /// Tight gap under mascot so tools sit closer and the character reads larger.
    static let mascotToToolsSpacing: CGFloat = 2
    /// Trimmed `colors 2` wax body is ~206×71; row height follows rail width so crayons fill the column.
    private static let swatchContentHeightPerWidth: CGFloat = 71.0 / 206.0
    static let shapeHeightMultiplier: CGFloat = 1.0

    static func crayonRowHeight(for traitCollection: UITraitCollection) -> CGFloat {
        let railW = BrushiMascotLayout.rightRailWidth(for: traitCollection) - 4
        return ceil(railW * swatchContentHeightPerWidth)
    }

    static func crayonStackSpacing(for traitCollection: UITraitCollection) -> CGFloat {
        _ = traitCollection
        return 1
    }
    static let scrollContainerMinHeight: CGFloat = 180
    /// How many crayon rows are visible in the rail (4.5 = half of the 5th peeks).
    static let visibleCrayonRows: CGFloat = 4.5

    static func scrollViewportHeight(
        for traitCollection: UITraitCollection,
        phonePanelWidth: CGFloat? = nil
    ) -> CGFloat {
        let rowH: CGFloat
        if let phonePanelWidth {
            rowH = ColoringOnPhoneMetrics.crayonRowHeight(phonePanelWidth: phonePanelWidth)
        } else {
            rowH = crayonRowHeight(for: traitCollection)
        }
        let spacing = crayonStackSpacing(for: traitCollection)
        let rows = visibleCrayonRows
        return rows * rowH + max(0, rows - 1) * spacing
    }
    static let toolButtonHeight: CGFloat = 72
    /// Side gap between brush and eraser (~1 mm; scales with screen density).
    static var toolPairSpacing: CGFloat {
        ColoringOnPhoneMetrics.toolPairSpacing
    }
    /// Drawing page scale (uniform) and nudge vs. the stack layout.
    static let canvasVisualScale: CGFloat = 0.97
    /// Shift canvas + aligned chrome slightly left (logical points).
    static let canvasShiftLeftPoints: CGFloat = 6
}

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

/*
 Superseded crayon art (kept for reference; do not re-enable without removing PNG swatches):

 • `HorizontalCrayonShapeView` — CoreGraphics “wax crayon” vector (Figma-aligned).
 • `Assets.xcassets` / `FigmaCrayon1`…`FigmaCrayon7` — SVG exports; never wired in Swift after vector path.

 Palette UI now uses `MagicBrushy/Colors/01-color.png` … `30-color.png` via `MagicBrushyCrayonResources` + `MagicCrayonControl`.
*/

private final class MagicCrayonControl: UIControl {

    private let glassRingView = UIView()
    private let swatchView = UIImageView()
    private let shineOverlay = CAGradientLayer()
    private let glassRingShine = CAGradientLayer()

    private static let selectedScale = CGAffineTransform(scaleX: 1.02, y: 1.04)

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
        clipsToBounds = false
        isExclusiveTouch = false

        glassRingView.isUserInteractionEnabled = false
        glassRingView.isHidden = true
        glassRingView.backgroundColor = .clear
        glassRingView.layer.cornerRadius = 8
        glassRingView.layer.borderWidth = 2
        glassRingView.layer.borderColor = UIColor.white.withAlphaComponent(0.88).cgColor
        glassRingView.layer.shadowColor = UIColor.white.cgColor
        glassRingView.layer.shadowOpacity = 0.7
        glassRingView.layer.shadowRadius = 8
        glassRingView.layer.shadowOffset = .zero
        if #available(iOS 13.0, *) {
            glassRingView.layer.cornerCurve = .continuous
        }
        glassRingShine.colors = [
            UIColor.white.withAlphaComponent(0.55).cgColor,
            UIColor.white.withAlphaComponent(0.12).cgColor,
            UIColor.clear.cgColor,
        ]
        glassRingShine.locations = [0, 0.42, 1]
        glassRingShine.startPoint = CGPoint(x: 0.1, y: 0.08)
        glassRingShine.endPoint = CGPoint(x: 0.9, y: 0.92)
        glassRingView.layer.addSublayer(glassRingShine)
        glassRingView.translatesAutoresizingMaskIntoConstraints = false

        swatchView.isUserInteractionEnabled = false
        swatchView.contentMode = .scaleAspectFill
        swatchView.clipsToBounds = true
        swatchView.layer.cornerRadius = 8
        swatchView.backgroundColor = .clear
        swatchView.translatesAutoresizingMaskIntoConstraints = false

        shineOverlay.colors = [
            UIColor.white.withAlphaComponent(0.5).cgColor,
            UIColor.white.withAlphaComponent(0.18).cgColor,
            UIColor.clear.cgColor,
        ]
        shineOverlay.locations = [0, 0.38, 1]
        shineOverlay.startPoint = CGPoint(x: 0.08, y: 0.05)
        shineOverlay.endPoint = CGPoint(x: 0.92, y: 0.95)
        shineOverlay.isHidden = true
        swatchView.layer.addSublayer(shineOverlay)

        addSubview(swatchView)
        addSubview(glassRingView)
        NSLayoutConstraint.activate([
            swatchView.leadingAnchor.constraint(equalTo: leadingAnchor),
            swatchView.trailingAnchor.constraint(equalTo: trailingAnchor),
            swatchView.topAnchor.constraint(equalTo: topAnchor),
            swatchView.bottomAnchor.constraint(equalTo: bottomAnchor),
            glassRingView.leadingAnchor.constraint(equalTo: swatchView.leadingAnchor),
            glassRingView.trailingAnchor.constraint(equalTo: swatchView.trailingAnchor),
            glassRingView.topAnchor.constraint(equalTo: swatchView.topAnchor),
            glassRingView.bottomAnchor.constraint(equalTo: swatchView.bottomAnchor),
        ])
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        CATransaction.begin()
        CATransaction.setDisableActions(true)
        glassRingShine.frame = glassRingView.bounds
        glassRingShine.cornerRadius = glassRingView.layer.cornerRadius
        shineOverlay.frame = swatchView.bounds
        shineOverlay.cornerRadius = swatchView.layer.cornerRadius
        CATransaction.commit()
    }

    func setSwatch(image: UIImage?, wax _: UIColor) {
        swatchView.image = image
    }

    func setSelected(_ selected: Bool, animated: Bool) {
        let apply = {
            if selected {
                self.glassRingView.isHidden = false
                self.glassRingView.alpha = 1
                self.shineOverlay.isHidden = false
                self.transform = Self.selectedScale
            } else {
                self.glassRingView.isHidden = true
                self.shineOverlay.isHidden = true
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
        ctx.rotate(by: .pi / 4)

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
