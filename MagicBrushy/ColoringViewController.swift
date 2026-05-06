import UIKit

/// Full-screen coloring: built-in outlines, finger or Apple Pencil, on-device VLM feedback.
/// No Bluetooth pen stack — input is multitouch / Pencil only.
final class ColoringViewController: UIViewController {

    private let templateView = UIImageView()
    private let strokeView = ColoringStrokeView()
    /// Segments filled in `viewDidLoad`; avoids building outline bitmaps during storyboard instantiation.
    private let pageControl = UISegmentedControl()
    private let paletteStack = UIStackView()
    private let feedbackButton = UIButton(type: .system)
    private let clearButton = UIButton(type: .system)
    private let undoButton = UIButton(type: .system)
    private let feedbackText = UITextView()
    private let loadOverlay = UIView()
    private let loadLabel = UILabel()
    private let loadProgress = UIProgressView(progressViewStyle: .default)
    private let modelStatusDot = UIView(frame: .zero)
    private let modelStatusLabel = UILabel()
    private let modelStatusStack = UIStackView()
    /// Created lazily; weights prefetch on appear so the status badge reflects download/load.
    private var vlm: LeapVLMModel?

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
        view.backgroundColor = .systemBackground

        templateView.contentMode = .scaleAspectFit
        templateView.clipsToBounds = true
        templateView.backgroundColor = .white
        templateView.layer.cornerRadius = 12
        templateView.layer.borderWidth = 1
        templateView.layer.borderColor = UIColor.separator.cgColor

        feedbackText.isEditable = false
        feedbackText.isScrollEnabled = true
        feedbackText.font = .preferredFont(forTextStyle: .body)
        feedbackText.backgroundColor = UIColor.secondarySystemBackground
        feedbackText.layer.cornerRadius = 10
        feedbackText.textContainerInset = UIEdgeInsets(top: 10, left: 10, bottom: 10, right: 10)
        feedbackText.text = "Tips also play a moment after you lift your finger or pencil. Tap Feedback anytime — Alba reads aloud when the voice files are bundled. Everything stays on this device."

        for page in BuiltInColoringPages.all {
            pageControl.insertSegment(withTitle: page.title, at: pageControl.numberOfSegments, animated: false)
        }
        pageControl.selectedSegmentIndex = 0
        pageControl.addTarget(self, action: #selector(pageChanged), for: .valueChanged)

        feedbackButton.setTitle("Feedback", for: .normal)
        feedbackButton.titleLabel?.font = .preferredFont(forTextStyle: .headline)
        feedbackButton.addTarget(self, action: #selector(requestFeedback), for: .touchUpInside)

        clearButton.setTitle("Clear", for: .normal)
        clearButton.addTarget(self, action: #selector(clearStrokes), for: .touchUpInside)

        undoButton.setTitle("Undo", for: .normal)
        undoButton.addTarget(self, action: #selector(undoStroke), for: .touchUpInside)

        paletteStack.axis = .horizontal
        paletteStack.spacing = 10
        paletteStack.distribution = .equalSpacing
        paletteStack.alignment = .center
        for (i, color) in palette.enumerated() {
            let b = UIButton(type: .custom)
            b.tag = i
            b.backgroundColor = color
            b.layer.cornerRadius = 18
            b.layer.borderWidth = 2
            b.layer.borderColor = UIColor.label.withAlphaComponent(0.2).cgColor
            b.translatesAutoresizingMaskIntoConstraints = false
            b.widthAnchor.constraint(equalToConstant: 36).isActive = true
            b.heightAnchor.constraint(equalToConstant: 36).isActive = true
            b.addTarget(self, action: #selector(colorPicked(_:)), for: .touchUpInside)
            paletteStack.addArrangedSubview(b)
        }

        let bar = UIStackView(arrangedSubviews: [undoButton, clearButton, UIView(), feedbackButton])
        bar.axis = .horizontal
        bar.spacing = 16
        bar.alignment = .center

        let bottomStack = UIStackView(arrangedSubviews: [paletteStack, bar, feedbackText])
        bottomStack.axis = .vertical
        bottomStack.spacing = 12
        bottomStack.translatesAutoresizingMaskIntoConstraints = false

        let canvasContainer = UIView()
        canvasContainer.translatesAutoresizingMaskIntoConstraints = false
        canvasContainer.backgroundColor = .clear

        templateView.translatesAutoresizingMaskIntoConstraints = false
        strokeView.translatesAutoresizingMaskIntoConstraints = false

        canvasContainer.addSubview(templateView)
        canvasContainer.addSubview(strokeView)

        pageControl.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(pageControl)
        view.addSubview(canvasContainer)
        view.addSubview(bottomStack)

        loadOverlay.translatesAutoresizingMaskIntoConstraints = false
        loadOverlay.backgroundColor = UIColor.black.withAlphaComponent(0.45)
        loadOverlay.isHidden = true
        loadLabel.translatesAutoresizingMaskIntoConstraints = false
        loadLabel.textColor = .white
        loadLabel.numberOfLines = 0
        loadLabel.font = .preferredFont(forTextStyle: .callout)
        loadLabel.textAlignment = .center
        loadProgress.translatesAutoresizingMaskIntoConstraints = false

        loadOverlay.addSubview(loadLabel)
        loadOverlay.addSubview(loadProgress)
        view.addSubview(loadOverlay)

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
        modelStatusStack.translatesAutoresizingMaskIntoConstraints = false
        modelStatusStack.isAccessibilityElement = true
        modelStatusStack.accessibilityTraits = .updatesFrequently
        modelStatusStack.addArrangedSubview(modelStatusDot)
        modelStatusStack.addArrangedSubview(modelStatusLabel)
        view.addSubview(modelStatusStack)

        let g = view.safeAreaLayoutGuide
        NSLayoutConstraint.activate([
            pageControl.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),
            pageControl.centerXAnchor.constraint(equalTo: g.centerXAnchor),

            modelStatusDot.widthAnchor.constraint(equalToConstant: 10),
            modelStatusDot.heightAnchor.constraint(equalToConstant: 10),
            modelStatusStack.centerYAnchor.constraint(equalTo: pageControl.centerYAnchor),
            modelStatusStack.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -12),
            modelStatusStack.leadingAnchor.constraint(greaterThanOrEqualTo: pageControl.trailingAnchor, constant: 8),

            canvasContainer.topAnchor.constraint(equalTo: pageControl.bottomAnchor, constant: 8),
            canvasContainer.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 16),
            canvasContainer.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -16),
            canvasContainer.bottomAnchor.constraint(equalTo: bottomStack.topAnchor, constant: -12),

            bottomStack.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 16),
            bottomStack.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -16),
            bottomStack.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -12),
            feedbackText.heightAnchor.constraint(greaterThanOrEqualToConstant: 100),

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
        ])

        strokeView.strokeColor = palette[0]
        strokeView.onPaintingBegan = { [weak self] in
            self?.onColoringStrokeBegan()
        }
        strokeView.onCommittedStrokeEnded = { [weak self] in
            self?.scheduleFeedbackIdleTimer()
        }
        applyCurrentPage()

        view.bringSubviewToFront(loadOverlay)
        view.bringSubviewToFront(modelStatusStack)
    }

    deinit {
        pollTimer?.invalidate()
        cancelFeedbackIdleTimer()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if pollTimer == nil {
            startPollingVLMUi()
        }
        let warm = modelForInference()
        Task { await warm.load() }
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
        let t = Timer(timeInterval: 0.08, repeats: true) { [weak self] _ in
            Task { @MainActor [weak self] in
                self?.applyObservationSnapshot()
            }
        }
        RunLoop.main.add(t, forMode: .common)
        pollTimer = t
    }

    private func modelForInference() -> LeapVLMModel {
        if let vlm { return vlm }
        let created = LeapVLMModel()
        created.onModelLoadPanelStateChanged = { [weak self] in
            DispatchQueue.main.async {
                self?.refreshLoadOverlay()
                self?.refreshModelStatusIndicator()
            }
        }
        vlm = created
        return created
    }

    private func cancelFeedbackIdleTimer() {
        pendingAutoFeedbackWork?.cancel()
        pendingAutoFeedbackWork = nil
    }

    /// Discard pending timers, in-flight model work, and any generation token so old answers never land after a new gesture.
    private func invalidateFeedbackSession() {
        feedbackGeneration &+= 1
        cancelFeedbackIdleTimer()
        vlm?.cancel()
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
        guard let vlm else { return }
        refreshLoadOverlay()
        if !vlm.output.isEmpty {
            feedbackText.text = vlm.output
        }
    }

    private func refreshModelStatusIndicator() {
        guard let vlm else {
            modelStatusDot.backgroundColor = UIColor.tertiaryLabel.withAlphaComponent(0.85)
            modelStatusLabel.text = "AI: …"
            modelStatusStack.accessibilityLabel = "Art coach model status not started"
            return
        }

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
        guard let vlm else {
            loadOverlay.isHidden = true
            return
        }
        loadOverlay.isHidden = !vlm.isModelLoadPanelVisible && !vlm.running
        if vlm.running {
            loadOverlay.isHidden = false
            loadLabel.text = "Thinking…"
            loadProgress.setProgress(1, animated: false)
            loadProgress.isHidden = true
            return
        }
        guard vlm.isModelLoadPanelVisible else { return }

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
        FeedbackAlbaSpeech.stopSpeaking()
        invalidateFeedbackSession()
        let page = BuiltInColoringPages.all[pageIndex]
        templateView.image = page.image
        strokeView.clearStrokes()
        feedbackText.text = "Nice — you opened “\(page.title)”. Color it — tips arrive a moment after you lift the brush; tap Feedback anytime."
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
        feedbackText.text = "…"

        let bounds = strokeView.bounds
        guard bounds.width >= 16, bounds.height >= 16 else {
            feedbackText.text = "Canvas isn’t ready yet — rotate the device or tap Feedback again."
            return
        }

        let img = strokeView.snapshotComposite(underneath: templateView.image, in: bounds)
        model.maxTokens = 120

        let gen = feedbackGeneration
        Task { @MainActor [weak self] in
            guard let self else { return }
            let inner = await model.generate(image: img, prompt: self.composeFeedbackPrompt(), maxOutputTokens: 96)
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

Your job: say one cheery thing about what they JUST painted—name the part 1qand the color you see. If you are unsure, pick the brightest new patch of paint inside the outlines.

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

private extension BinaryInteger {
    func clamped(to range: ClosedRange<Self>) -> Self {
        Swift.min(Swift.max(self, range.lowerBound), range.upperBound)
    }
}
