import UIKit

/// Full-screen coloring: built-in outlines, finger or Apple Pencil, on-device VLM feedback.
/// No Bluetooth pen stack — input is multitouch / Pencil only.
final class ColoringViewController: UIViewController {

    private let templateView = UIImageView()
    private let strokeView = ColoringStrokeView()
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
    /// When set (category flow), the segmented page picker stays hidden and this index is used.
    var pinnedPageIndex: Int?

    private let skyView = UIView()
    private let cloudContainer = UIView()
    private let homeButton = UIButton(type: .system)
    private let toolRow = UIStackView()
    private let figmaPaletteStack = UIStackView()
    private let prevPageButton = UIButton(type: .system)
    private let nextPageButton = UIButton(type: .system)
    private let doneButton = UIButton(type: .system)
    private let toolPairStack = UIStackView()
    /// Maps Figma crayon slot → indices in `palette`.  7 slots = 7 Figma crayon images.
    private let figmaPaletteOrder: [Int] = [6, 4, 3, 2, 1, 0, 7]
    private var crayonButtons: [CrayonPaletteControl] = []
    private var isEraserMode = false
    private var figmaStrokePaletteIndex: Int = 0
    private var brushToolButton: UIButton?
    private var eraserToolButton: UIButton?

    /// App-wide singleton model; loaded once at app startup from SceneDelegate.
    private let vlm = LeapVLMModel.shared

    /// Same order as `palette` — short words kids know.
    private let paletteKidNames = [
        "red", "orange", "yellow", "green", "blue", "deep blue", "purple", "pink", "brown", "black",
    ]

    private let palette: [UIColor] = [
        .systemRed, .systemOrange, .systemYellow, .systemGreen,
        .systemBlue, .systemIndigo, .systemPurple, .systemPink,
        .brown, .black,
    ]

    private var pageIndex = 0 {
        didSet { applyCurrentPage() }
    }

    private var pollTimer: Timer?
    /// After brush lift, defer VLM this long so a quick continuation cancels pending feedback (`onPaintingBegan` clears it).
    private static let feedbackIdleTriggerDelay: TimeInterval = 0.5
    private var pendingAutoFeedbackWork: DispatchWorkItem?
    /// Bumped when the user paints again, changes page, clears, etc. — stale VLM work discards its result.
    private var feedbackGeneration: UInt64 = 0

    override func viewDidLoad() {
        super.viewDidLoad()
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

        for page in BuiltInColoringPages.all {
            pageControl.insertSegment(withTitle: page.title, at: pageControl.numberOfSegments, animated: false)
        }
        pageControl.selectedSegmentIndex = pinnedPageIndex ?? 0
        pageControl.addTarget(self, action: #selector(pageChanged), for: .valueChanged)
        if pinnedPageIndex != nil {
            pageControl.isHidden = true
        }

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

        // ── Crayons (Figma-image based) ──────────────────────────────────────
        let crayonImageNames = ["FigmaCrayon1","FigmaCrayon2","FigmaCrayon3",
                                "FigmaCrayon4","FigmaCrayon5","FigmaCrayon6","FigmaCrayon7"]
        figmaPaletteStack.axis = .vertical
        figmaPaletteStack.spacing = 4
        figmaPaletteStack.alignment = .fill
        for (slot, _) in figmaPaletteOrder.enumerated() {
            let c = CrayonPaletteControl()
            c.tag = slot
            if slot < crayonImageNames.count {
                c.setCrayonImage(crayonImageNames[slot])
            }
            if slot < figmaCrayonPairs.count {
                c.setCrayonColors(figmaCrayonPairs[slot].0, figmaCrayonPairs[slot].1)
            }
            c.translatesAutoresizingMaskIntoConstraints = false
            c.heightAnchor.constraint(equalToConstant: 76).isActive = true
            c.addTarget(self, action: #selector(crayonPicked(_:)), for: UIControl.Event.touchUpInside)
            figmaPaletteStack.addArrangedSubview(c)
            crayonButtons.append(c)
        }

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

        // ── Mascot (brush character at the top) ──────────────────────────────
        let mascotImageView = UIImageView(image: UIImage(named: "BrushMascot"))
        mascotImageView.contentMode = .scaleAspectFit
        mascotImageView.clipsToBounds = false
        mascotImageView.translatesAutoresizingMaskIntoConstraints = false
        mascotImageView.heightAnchor.constraint(equalToConstant: 138).isActive = true

        let mascotContainer = UIView()
        mascotContainer.translatesAutoresizingMaskIntoConstraints = false
        mascotContainer.addSubview(mascotImageView)
        NSLayoutConstraint.activate([
            mascotImageView.centerXAnchor.constraint(equalTo: mascotContainer.centerXAnchor),
            mascotImageView.topAnchor.constraint(equalTo: mascotContainer.topAnchor, constant: -4),
            mascotImageView.bottomAnchor.constraint(equalTo: mascotContainer.bottomAnchor, constant: 4),
            mascotImageView.widthAnchor.constraint(lessThanOrEqualTo: mascotContainer.widthAnchor, multiplier: 0.95)
        ])

        // ── Right panel ───────────────────────────────────────────────────────
        let rightPanelStack = UIStackView(arrangedSubviews: [mascotContainer, toolPairStack, figmaPaletteStack])
        rightPanelStack.axis = .vertical
        rightPanelStack.spacing = 8
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
        let doneBtn = makeNavButton(icon: "checkmark", fill: FigmaTheme.actionBlue, border: FigmaTheme.actionBlueBorder)
        doneBtn.addTarget(self, action: #selector(requestFeedback), for: .touchUpInside)

        let navSpacer = UIView()
        navSpacer.setContentHuggingPriority(UILayoutPriority(1), for: .horizontal)
        toolRow.axis = .horizontal
        toolRow.spacing = 8
        toolRow.alignment = .center
        toolRow.addArrangedSubview(homeButton)
        toolRow.addArrangedSubview(prevBtn)
        toolRow.addArrangedSubview(nextBtn)
        toolRow.addArrangedSubview(doneBtn)
        toolRow.addArrangedSubview(navSpacer)
        toolRow.addArrangedSubview(modelStatusStack)

        let bar = UIStackView(arrangedSubviews: [toolRow])
        bar.axis = .vertical
        bar.spacing = 10

        // ── Canvas ────────────────────────────────────────────────────────────
        let canvasContainer = UIView()
        canvasContainer.translatesAutoresizingMaskIntoConstraints = false
        canvasContainer.backgroundColor = .clear

        templateView.translatesAutoresizingMaskIntoConstraints = false
        strokeView.translatesAutoresizingMaskIntoConstraints = false

        canvasContainer.addSubview(templateView)
        canvasContainer.addSubview(strokeView)

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
        let rightPanelWidth = rightPanelStack.widthAnchor.constraint(equalToConstant: 148)
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

            headerStack.topAnchor.constraint(equalTo: g.topAnchor, constant: 6),
            headerStack.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 10),
            headerStack.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -10),

            paintRow.topAnchor.constraint(equalTo: headerStack.bottomAnchor, constant: 8),
            paintRow.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 8),
            paintRow.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -8),
            paintRow.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -8),

            canvasContainer.heightAnchor.constraint(greaterThanOrEqualToConstant: 200),
            canvasAspect,
            rightPanelWidth,

            templateView.leadingAnchor.constraint(equalTo: canvasContainer.leadingAnchor),
            templateView.trailingAnchor.constraint(equalTo: canvasContainer.trailingAnchor),
            templateView.topAnchor.constraint(equalTo: canvasContainer.topAnchor),
            templateView.bottomAnchor.constraint(equalTo: canvasContainer.bottomAnchor),

            strokeView.leadingAnchor.constraint(equalTo: templateView.leadingAnchor),
            strokeView.trailingAnchor.constraint(equalTo: templateView.trailingAnchor),
            strokeView.topAnchor.constraint(equalTo: templateView.topAnchor),
            strokeView.bottomAnchor.constraint(equalTo: templateView.bottomAnchor),

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

        pageIndex = pinnedPageIndex ?? 0

        strokeView.onPaintingBegan = { [weak self] in
            self?.onColoringStrokeBegan()
        }
        strokeView.onCommittedStrokeEnded = { [weak self] in
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
        let fill = UIColor(red: 0.82, green: 0.75, blue: 0.62, alpha: 1)
        let stroke = UIColor(red: 0.65, green: 0.57, blue: 0.44, alpha: 1)
        styleChromeButton(b, fill: fill, border: stroke, cornerRadius: 14)
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
        navigationController?.popToRootViewController(animated: true)
    }

    @objc private func toolModeTapped(_ sender: UIButton) {
        isEraserMode = sender.tag == 1
        applyToolMode()
        refreshCrayonSelection(animated: true)
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }

    private func applyToolMode() {
        if isEraserMode {
            strokeView.strokeColor = .white
            strokeView.strokeWidth = 34
        } else {
            let slot = figmaStrokePaletteIndex.clamped(to: 0...(figmaPaletteOrder.count - 1))
            strokeView.strokeColor = slot < figmaCrayonPairs.count ? figmaCrayonPairs[slot].0 : palette[figmaPaletteOrder[slot]]
            strokeView.strokeWidth = 22
        }
        brushToolButton?.alpha = isEraserMode ? 0.55 : 1.0
        eraserToolButton?.alpha = isEraserMode ? 1.0 : 0.6
    }

    @objc private func crayonPicked(_ sender: CrayonPaletteControl) {
        figmaStrokePaletteIndex = sender.tag.clamped(to: 0...(figmaPaletteOrder.count - 1))
        isEraserMode = false
        applyToolMode()
        refreshCrayonSelection(animated: true)
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
    }

    private func refreshCrayonSelection(animated: Bool) {
        for c in crayonButtons {
            let on = c.tag == figmaStrokePaletteIndex && !isEraserMode
            let changes = {
                c.applySelected(on)
                c.transform = on ? CGAffineTransform(scaleX: 1.06, y: 1.06) : .identity
            }
            if animated {
                UIView.animate(withDuration: 0.18, animations: changes)
            } else {
                changes()
            }
        }
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

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if pollTimer == nil {
            startPollingVLMUi()
        }
        _ = modelForInference()
        refreshModelStatusIndicator()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        FeedbackAlbaSpeech.stopSpeaking()
        cancelFeedbackIdleTimer()
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
                self?.refreshLoadOverlay()
                self?.refreshModelStatusIndicator()
            }
        }
        return vlm
    }

    private func cancelFeedbackIdleTimer() {
        pendingAutoFeedbackWork?.cancel()
        pendingAutoFeedbackWork = nil
    }

    /// Discard pending timers, in-flight model work, and any generation token so old answers never land after a new gesture.
    private func invalidateFeedbackSession() {
        feedbackGeneration &+= 1
        cancelFeedbackIdleTimer()
        vlm.cancel()
    }

    private func onColoringStrokeBegan() {
        invalidateFeedbackSession()
        FeedbackAlbaSpeech.stopSpeaking()
    }

    private func scheduleFeedbackIdleTimer() {
        cancelFeedbackIdleTimer()
        guard !strokeView.chronologicalStrokeColors.isEmpty else { return }

        let work = DispatchWorkItem { [weak self] in
            guard let self else { return }
            self.pendingAutoFeedbackWork = nil
            self.runFeedbackPipeline()
        }
        pendingAutoFeedbackWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + Self.feedbackIdleTriggerDelay, execute: work)
    }

    private func applyObservationSnapshot() {
        refreshModelStatusIndicator()
        refreshLoadOverlay()
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
            modelStatusLabel.text = "AI: Download \(pct)%"
            modelStatusStack.accessibilityLabel = "Downloading art coach model, \(pct) percent complete"
        case .loadingIntoMemory:
            modelStatusDot.backgroundColor = .systemBlue
            modelStatusLabel.text = "AI: Loading…"
            modelStatusStack.accessibilityLabel = "Loading art coach model into memory"
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

    private func refreshLoadOverlay() {
        let show = vlm.isModelLoadPanelVisible
        loadOverlay.isHidden = !show
        loadOverlay.isUserInteractionEnabled = show
        guard show else { return }

        loadLabel.text = vlm.modelLoadStatusText
        loadProgress.isHidden = false
        loadProgress.progress = Float(vlm.modelDownloadProgressFraction)
        if vlm.modelLoadDidFail {
            loadLabel.textColor = UIColor.systemYellow
        } else {
            loadLabel.textColor = .white
        }
    }

    @objc private func pageChanged() {
        pageIndex = pageControl.selectedSegmentIndex
    }

    private func applyCurrentPage() {
        guard pageIndex >= 0, pageIndex < BuiltInColoringPages.all.count else { return }
        if !pageControl.isHidden {
            pageControl.selectedSegmentIndex = pageIndex
        }
        FeedbackAlbaSpeech.stopSpeaking()
        invalidateFeedbackSession()
        let page = BuiltInColoringPages.all[pageIndex]
        templateView.image = page.image
        strokeView.clearStrokes()
    }

    @objc private func colorPicked(_ sender: UIButton) {
        let i = sender.tag.clamped(to: 0...(palette.count - 1))
        strokeView.strokeColor = palette[i]
        sender.layer.borderColor = UIColor.label.cgColor
        UIView.animate(withDuration: 0.2) {
            sender.transform = CGAffineTransform(scaleX: 1.12, y: 1.12)
        } completion: { _ in
            UIView.animate(withDuration: 0.15) {
                sender.transform = .identity
                sender.layer.borderColor = UIColor.label.withAlphaComponent(0.2).cgColor
            }
        }
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
        FeedbackAlbaSpeech.stopSpeaking()
        runFeedbackPipeline()
    }

    private func runFeedbackPipeline() {
        let model = modelForInference()
        guard !model.running else { return }
        view.layoutIfNeeded()

        let bounds = strokeView.bounds
        guard bounds.width >= 16, bounds.height >= 16 else {
            return
        }

        let img = captureCanvasForVLM()
        let prompt = composeFeedbackPrompt()
        let previewImage = model.prepareImageForModelPreview(img) ?? img
        showVLMInputPreview(previewImage)
        model.maxTokens = 120

        let gen = feedbackGeneration
        Task { @MainActor [weak self] in
            guard let self else { return }
            #if DEBUG
            print("""
            [MagicBrushy][VLM] Sending request
            - image size: \(Int(img.size.width))x\(Int(img.size.height))
            - max output tokens: 96
            - prompt:
            \(prompt)
            """)
            #endif
            let inner = await model.generate(image: previewImage, prompt: prompt, maxOutputTokens: 96)
            await inner.value

            guard gen == self.feedbackGeneration else { return }
            let spoken = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(
                model.output.trimmingCharacters(in: .whitespacesAndNewlines)
            )
            guard !spoken.isEmpty, spoken != "…",
                  !spoken.hasPrefix("Failed:") else { return }
            await FeedbackAlbaSpeech.speakFeedback(spoken)
        }
    }

    /// Capture exactly what the user sees on the canvas (template + strokes), then VLM can downscale it.
    private func captureCanvasForVLM() -> UIImage {
        let size = strokeView.bounds.size
        guard size.width > 1, size.height > 1 else {
            return strokeView.snapshotComposite(underneath: templateView.image, in: strokeView.bounds)
        }

        let format = UIGraphicsImageRendererFormat.default()
        format.scale = 1
        format.opaque = true

        let renderer = UIGraphicsImageRenderer(size: size, format: format)
        return renderer.image { ctx in
            UIColor.white.setFill()
            ctx.fill(CGRect(origin: .zero, size: size))

            // Render both layers as currently displayed (includes UIImageView aspect-fit behavior).
            templateView.layer.render(in: ctx.cgContext)
            strokeView.layer.render(in: ctx.cgContext)
        }
    }

    private func showVLMInputPreview(_ image: UIImage) {
        vlmInputPreviewImageView.image = image
        vlmInputPreviewLabel.text = "VLM input\n\(Int(image.size.width))×\(Int(image.size.height))"
        vlmInputPreviewImageView.alpha = 1
        vlmInputPreviewLabel.alpha = 1
        vlmInputPreviewImageView.isHidden = false
        vlmInputPreviewLabel.isHidden = false

        UIView.animate(withDuration: 0.35, delay: 3.0, options: [.curveEaseInOut]) {
            self.vlmInputPreviewImageView.alpha = 0
            self.vlmInputPreviewLabel.alpha = 0
        } completion: { _ in
            self.vlmInputPreviewImageView.isHidden = true
            self.vlmInputPreviewLabel.isHidden = true
            self.vlmInputPreviewImageView.alpha = 1
            self.vlmInputPreviewLabel.alpha = 1
        }
    }

    private func composeFeedbackPrompt() -> String {
        let lastPoints = strokeView.lastFinishedStrokePointCount
        let lastColor = strokeView.chronologicalStrokeColors.last

        let paletteHintBlock: String
        if lastPoints > 30, let c = lastColor {
            let paintWord = simpleKidColorName(for: c)
            paletteHintBlock = "Their last big stroke was palette “\(paintWord)” — use this only if the photo matches."

        } else if lastPoints > 0 {
            paletteHintBlock = "No palette hint; use only the photo."
        } else {
            paletteHintBlock = "No new stroke tracked; peek at the picture and cheer gently."
        }

        let themeLine: String
        if pageIndex >= 0, pageIndex < BuiltInColoringPages.all.count {
            let t = BuiltInColoringPages.all[pageIndex].title
            themeLine = "Page: \(t)."
        } else {
            themeLine = ""
        }

        let opener = themeLine.isEmpty ? "A child colored this sheet (outlines + paint)." : "A child colored this sheet (outlines + paint). \(themeLine)"

        return """
\(opener) Look at the picture.

\(paletteHintBlock)

Your job: say one cheery thing about what they JUST painted—name the part and the color you see. If you are unsure, pick the brightest new patch of paint inside the outlines.

Speak to THEM: write one or two very short sentences, easy words, use "you" or "your". Start with warmth.

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

// MARK: - Figma-style crayon / brush chrome (kept in this file so it always compiles with the main target)

// Figma crayon palette: [mainColor, highlightColor] per slot matching figmaPaletteOrder.
let figmaCrayonPairs: [(UIColor, UIColor)] = [
    (UIColor(hex: "#BC14FF"), UIColor(hex: "#EF3CE3")), // purple
    (UIColor(hex: "#00D9FF"), UIColor(hex: "#6EC8FF")), // cyan
    (UIColor(hex: "#00D26A"), UIColor(hex: "#C3EF3C")), // green
    (UIColor(hex: "#FFE600"), UIColor(hex: "#E9EF3C")), // yellow
    (UIColor(hex: "#FF8032"), UIColor(hex: "#EFAA3C")), // orange
    (UIColor(hex: "#D20000"), UIColor(hex: "#EF3C69")), // red
    (UIColor(hex: "#FF82D3"), UIColor(hex: "#FF7CF6")), // pink
]

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

/// Vertical crayon drawn in CoreGraphics matching the Figma SVG structure:
/// rounded cap at top → dark band → wax body with oval label → dark band → pointed tip at bottom.
final class CrayonShapeView: UIView {

    var waxColor: UIColor = .systemBlue { didSet { setNeedsDisplay() } }
    var highlightColor: UIColor = .systemTeal { didSet { setNeedsDisplay() } }

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

        // ── Section heights (Figma SVG proportions, vertical orientation) ──
        // cap → band → body → band → pointed tip
        let capH:  CGFloat = H * 0.10
        let bandH: CGFloat = H * 0.025
        let bodyH: CGFloat = H * 0.60
        // tipH fills the rest (≈ 25%)

        let yBand1 = capH
        let yBody  = yBand1 + bandH
        let yBand2 = yBody  + bodyH
        let yTip   = yBand2 + bandH

        let cR   = W * 0.40                                                        // cap corner radius
        let dark = UIColor(red: 0.196, green: 0.106, blue: 0.255, alpha: 1)       // Figma #321B41

        // ── Full crayon outline path (rounded top, pointed bottom) ──
        let crayon = UIBezierPath()
        crayon.move(to: CGPoint(x: cR, y: 0))
        crayon.addLine(to: CGPoint(x: W - cR, y: 0))
        crayon.addArc(withCenter: CGPoint(x: W - cR, y: cR), radius: cR,
                      startAngle: -.pi / 2, endAngle: 0, clockwise: true)
        crayon.addLine(to: CGPoint(x: W, y: yTip))
        crayon.addLine(to: CGPoint(x: W / 2, y: H))          // tip point
        crayon.addLine(to: CGPoint(x: 0, y: yTip))
        crayon.addLine(to: CGPoint(x: 0, y: cR))
        crayon.addArc(withCenter: CGPoint(x: cR, y: cR), radius: cR,
                      startAngle: .pi, endAngle: -.pi / 2, clockwise: true)
        crayon.close()

        // Clip all fills to the crayon silhouette
        ctx.saveGState()
        ctx.addPath(crayon.cgPath)
        ctx.clip()

        // 1. Fill entire shape with wax color (body + tip share this)
        ctx.setFillColor(waxColor.cgColor)
        ctx.fill(bounds)

        // 2. Rounded cap — highlightColor (lighter top, matches Figma's brighter tip end)
        ctx.setFillColor(highlightColor.cgColor)
        ctx.fill(CGRect(x: 0, y: 0, width: W, height: yBand1))

        // 3. Dark separator band 1
        ctx.setFillColor(dark.cgColor)
        ctx.fill(CGRect(x: 0, y: yBand1, width: W, height: bandH))

        // 4. Dark oval label in the centre of the body (Figma ellipse)
        let lCX = W / 2
        let lCY = yBody + bodyH / 2
        let lrx = W * 0.38
        let lry = bodyH * 0.28
        ctx.setFillColor(dark.withAlphaComponent(0.45).cgColor)
        ctx.fillEllipse(in: CGRect(x: lCX - lrx, y: lCY - lry,
                                   width: lrx * 2, height: lry * 2))

        // 5. Dark separator band 2
        ctx.setFillColor(dark.cgColor)
        ctx.fill(CGRect(x: 0, y: yBand2, width: W, height: bandH))

        ctx.restoreGState()

        // 6. Subtle outline over the whole crayon
        ctx.setStrokeColor(UIColor.black.withAlphaComponent(0.14).cgColor)
        ctx.setLineWidth(0.8)
        ctx.addPath(crayon.cgPath)
        ctx.strokePath()
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        setNeedsDisplay()
    }
}

/// Tappable diagonal crayon drawn with CoreGraphics (Figma color palette).
final class CrayonPaletteControl: UIControl {

    let shape = CrayonShapeView()
    private let imageView = UIImageView()

    override var isHighlighted: Bool {
        didSet { alpha = isHighlighted ? 0.82 : 1 }
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        shape.setNeedsDisplay()
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

        imageView.translatesAutoresizingMaskIntoConstraints = false
        imageView.contentMode = .scaleAspectFit
        imageView.isUserInteractionEnabled = false
        addSubview(imageView)

        shape.translatesAutoresizingMaskIntoConstraints = false
        shape.isUserInteractionEnabled = false
        addSubview(shape)
        NSLayoutConstraint.activate([
            imageView.leadingAnchor.constraint(equalTo: leadingAnchor),
            imageView.trailingAnchor.constraint(equalTo: trailingAnchor),
            imageView.topAnchor.constraint(equalTo: topAnchor),
            imageView.bottomAnchor.constraint(equalTo: bottomAnchor),
            shape.leadingAnchor.constraint(equalTo: leadingAnchor),
            shape.trailingAnchor.constraint(equalTo: trailingAnchor),
            shape.topAnchor.constraint(equalTo: topAnchor),
            shape.bottomAnchor.constraint(equalTo: bottomAnchor),
        ])
    }

    func setCrayonImage(_ name: String) {
        let img = UIImage(named: name)
        imageView.image = img
        imageView.isHidden = (img == nil)
        shape.isHidden = (img != nil)
    }

    func setWaxColor(_ color: UIColor) {
        shape.waxColor = color
    }

    func setCrayonColors(_ main: UIColor, _ highlight: UIColor) {
        shape.waxColor = main
        shape.highlightColor = highlight
    }

    func applySelected(_ selected: Bool) {
        if selected {
            layer.shadowColor = UIColor.black.cgColor
            layer.shadowOpacity = 0.35
            layer.shadowRadius = 8
            layer.shadowOffset = CGSize(width: 0, height: 3)
        } else {
            layer.shadowOpacity = 0
        }
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
        ctx.setFillColor(UIColor(red: 0.96, green: 0.82, blue: 0.86, alpha: 1).cgColor)
        ctx.addPath(body.cgPath)
        ctx.fillPath()
        ctx.setStrokeColor(UIColor(white: 0.35, alpha: 0.35).cgColor)
        ctx.setLineWidth(0.8)
        ctx.addPath(body.cgPath)
        ctx.strokePath()
        let strap = UIBezierPath(roundedRect: CGRect(x: w * 0.22, y: h * 0.15, width: w * 0.56, height: h * 0.18), cornerRadius: 2)
        ctx.setFillColor(UIColor(white: 0.55, alpha: 1).cgColor)
        ctx.addPath(strap.cgPath)
        ctx.fillPath()
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        setNeedsDisplay()
    }
}

private extension BinaryInteger {
    func clamped(to range: ClosedRange<Self>) -> Self {
        Swift.min(Swift.max(self, range.lowerBound), range.upperBound)
    }
}
