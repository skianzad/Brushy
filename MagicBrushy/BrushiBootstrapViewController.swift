import UIKit

/// Full-screen download / load gate shown before the home screen (Figma sky + pill progress).
final class BrushiBootstrapViewController: UIViewController {

    private let heroView = FigmaAlignedHeroBackgroundView()
    private let statusLabel = UILabel()
    private let progressView = BrushiFigmaDownloadProgressView()
    private let retryButton = UIButton(type: .system)
    private var loadPanelObserver: NSObjectProtocol?
    private var didTransitionToHome = false
    /// UI fill never moves backward during one bootstrap download attempt.
    private var displayedDownloadProgress: CGFloat = 0
    /// Download / memory phases fill only to half; `playPreHomeProgressRitual` completes to 100% before home.
    private static let bootstrapProgressCap: CGFloat = 0.5
    private var memoryLoadFillTimer: Timer?
    private var preHomeProgressTask: Task<Void, Never>?
    private var bootstrapLoadTask: Task<Void, Never>?
    private var didPresentDownloadConsent = false

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = FigmaTheme.bootstrapSky

        heroView.heroImage = MagicBrushyChromeMetrics.landscapeBackgroundImage(for: traitCollection)
        heroView.backgroundColor = FigmaTheme.bootstrapSky
        heroView.translatesAutoresizingMaskIntoConstraints = false

        statusLabel.translatesAutoresizingMaskIntoConstraints = false
        statusLabel.numberOfLines = 2
        statusLabel.textAlignment = .center
        statusLabel.adjustsFontSizeToFitWidth = true
        statusLabel.minimumScaleFactor = 0.65
        applyOutlinedCaptionStyle(to: statusLabel)
        statusLabel.text = "Loading content..."

        progressView.translatesAutoresizingMaskIntoConstraints = false
        progressView.accessibilityLabel = "Loading progress"

        retryButton.translatesAutoresizingMaskIntoConstraints = false
        retryButton.setTitle("Try again", for: .normal)
        retryButton.titleLabel?.font = FigmaTheme.bodyFont(size: 18, weight: .bold)
        retryButton.setTitleColor(FigmaTheme.bootstrapProgressBorder, for: .normal)
        retryButton.backgroundColor = UIColor.white.withAlphaComponent(0.92)
        retryButton.layer.cornerRadius = 14
        if #available(iOS 13.0, *) { retryButton.layer.cornerCurve = .continuous }
        retryButton.contentEdgeInsets = UIEdgeInsets(top: 10, left: 22, bottom: 10, right: 22)
        retryButton.isHidden = true
        retryButton.addTarget(self, action: #selector(retryTapped), for: .touchUpInside)

        view.addSubview(heroView)
        view.addSubview(statusLabel)
        view.addSubview(progressView)
        view.addSubview(retryButton)

        let g = view.safeAreaLayoutGuide
        NSLayoutConstraint.activate([
            heroView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            heroView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            heroView.topAnchor.constraint(equalTo: view.topAnchor),
            heroView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            progressView.centerYAnchor.constraint(equalTo: g.centerYAnchor, constant: 12),
            progressView.centerXAnchor.constraint(equalTo: g.centerXAnchor),
            progressView.leadingAnchor.constraint(greaterThanOrEqualTo: g.leadingAnchor, constant: 36),
            progressView.trailingAnchor.constraint(lessThanOrEqualTo: g.trailingAnchor, constant: -36),
            progressView.widthAnchor.constraint(lessThanOrEqualToConstant: 720),
            progressView.heightAnchor.constraint(equalToConstant: 52),

            statusLabel.bottomAnchor.constraint(equalTo: progressView.topAnchor, constant: -22),
            statusLabel.centerXAnchor.constraint(equalTo: g.centerXAnchor),
            statusLabel.leadingAnchor.constraint(greaterThanOrEqualTo: g.leadingAnchor, constant: 28),
            statusLabel.trailingAnchor.constraint(lessThanOrEqualTo: g.trailingAnchor, constant: -28),

            retryButton.topAnchor.constraint(equalTo: progressView.bottomAnchor, constant: 28),
            retryButton.centerXAnchor.constraint(equalTo: g.centerXAnchor),
        ])

        let progressWidth = progressView.widthAnchor.constraint(equalTo: g.widthAnchor, multiplier: 0.62)
        progressWidth.priority = .defaultHigh
        progressWidth.isActive = true

        loadPanelObserver = NotificationCenter.default.addObserver(
            forName: .leapVLMLoadPanelStateDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.refreshFromModelState()
        }

        progressView.setProgress(0, animated: false)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        view.layoutIfNeeded()
        progressView.setProgress(displayedDownloadProgress, animated: false)
        refreshFromModelState()
        beginBootstrapAfterConsentCheck()
    }

    private func beginBootstrapAfterConsentCheck() {
        if MagicBrushyVLMConsent.shouldShowDownloadPrompt() {
            presentDownloadConsentIfNeeded()
            return
        }
        if MagicBrushyVLMConsent.userDeclinedDownload {
            proceedToHomeSkippingModel()
            return
        }
        startBootstrapLoadIfNeeded()
    }

    private func presentDownloadConsentIfNeeded() {
        guard !didPresentDownloadConsent else { return }
        didPresentDownloadConsent = true
        progressView.isHidden = true
        setCaptionText("Welcome to Brushi!")

        let alert = UIAlertController(
            title: MagicBrushyVLMConsent.downloadPromptTitle,
            message: MagicBrushyVLMConsent.downloadPromptMessage,
            preferredStyle: .alert
        )
        alert.addAction(UIAlertAction(title: "Not Now", style: .cancel) { [weak self] _ in
            self?.presentSkipDownloadConfirmation()
        })
        alert.addAction(UIAlertAction(title: "Download", style: .default) { [weak self] _ in
            guard let self else { return }
            MagicBrushyParentalGate.perform(
                from: self,
                title: "Grown-ups only",
                messagePrefix: MagicBrushyVLMConsent.parentalGateDownloadPrefix,
                onPassed: {
                    MagicBrushyVLMConsent.markAccepted()
                    self.progressView.isHidden = false
                    self.setCaptionText("Downloading Brushi… 0%")
                    self.startBootstrapLoadIfNeeded()
                },
                onCancelled: { [weak self] in
                    self?.didPresentDownloadConsent = false
                    self?.presentDownloadConsentIfNeeded()
                }
            )
        })
        present(alert, animated: true)
    }

    private func presentSkipDownloadConfirmation() {
        let alert = UIAlertController(
            title: MagicBrushyVLMConsent.skipDownloadConfirmTitle,
            message: MagicBrushyVLMConsent.skipDownloadConfirmMessage,
            preferredStyle: .alert
        )
        alert.addAction(UIAlertAction(title: "Go Back", style: .cancel) { [weak self] _ in
            self?.didPresentDownloadConsent = false
            self?.presentDownloadConsentIfNeeded()
        })
        alert.addAction(UIAlertAction(title: "Continue", style: .default) { [weak self] _ in
            MagicBrushyVLMConsent.markDeclined()
            self?.proceedToHomeSkippingModel()
        })
        present(alert, animated: true)
    }

    private func proceedToHomeSkippingModel() {
        guard !didTransitionToHome else { return }
        bootstrapLoadTask?.cancel()
        bootstrapLoadTask = nil
        preHomeProgressTask?.cancel()
        stopMemoryLoadFillAnimation()
        progressView.isHidden = true
        retryButton.isHidden = true
        setCaptionText("Welcome to Brushi!")
        preHomeProgressTask = Task { @MainActor [weak self] in
            guard let self else { return }
            try? await Task.sleep(nanoseconds: 500_000_000)
            guard !Task.isCancelled else { return }
            self.preHomeProgressTask = nil
            self.transitionToHomeIfNeeded(allowWithoutModel: true)
        }
    }

    deinit {
        memoryLoadFillTimer?.invalidate()
        preHomeProgressTask?.cancel()
        bootstrapLoadTask?.cancel()
        if let loadPanelObserver {
            NotificationCenter.default.removeObserver(loadPanelObserver)
        }
    }

    private static func sanitizeProgress(_ value: CGFloat) -> CGFloat {
        guard value.isFinite else { return 0 }
        return min(1, max(0, value))
    }

    private func applyOutlinedCaptionStyle(to label: UILabel) {
        let font = FigmaTheme.titleFont(size: 34)
        label.font = font
        label.textColor = FigmaTheme.bootstrapProgressBorder
        label.layer.shadowColor = UIColor.white.cgColor
        label.layer.shadowOffset = .zero
        label.layer.shadowRadius = 0
        label.layer.shadowOpacity = 1
        // Crisp white outline via negative stroke (attributed updates in refresh).
    }

    private func setCaptionText(_ text: String) {
        let font = FigmaTheme.titleFont(size: 34)
        let attrs: [NSAttributedString.Key: Any] = [
            .font: font,
            .foregroundColor: FigmaTheme.bootstrapProgressBorder,
            .strokeColor: UIColor.white,
            .strokeWidth: -5.5,
        ]
        statusLabel.attributedText = NSAttributedString(string: text, attributes: attrs)
    }

    private func startBootstrapLoadIfNeeded() {
        guard bootstrapLoadTask == nil else { return }
        progressView.setIndeterminateActive(false)
        displayedDownloadProgress = 0
        refreshProgressBarFromDisplayedFraction(animated: false)
        bootstrapLoadTask = Task { @MainActor [weak self] in
            defer { self?.bootstrapLoadTask = nil }
            guard let self else { return }
            #if targetEnvironment(simulator)
            await self.animateSimulatorBootstrapFill()
            self.schedulePreHomeProgressIfNeeded()
            #else
            await LeapVLMModel.shared.load()
            self.stopMemoryLoadFillAnimation()
            self.refreshFromModelState()
            if !LeapVLMModel.shared.modelLoadDidFail {
                self.schedulePreHomeProgressIfNeeded()
            }
            #endif
        }
    }

    #if targetEnvironment(simulator)
    private func animateSimulatorBootstrapFill() async {
        progressView.setIndeterminateActive(false)
        let halfSteps = 14
        for step in 0...halfSteps {
            displayedDownloadProgress = (CGFloat(step) / CGFloat(halfSteps)) * 0.5
            let pct = Int((displayedDownloadProgress * 100).rounded(.down))
            setCaptionText("Loading content… \(pct)%")
            refreshProgressBarFromDisplayedFraction(animated: step > 0)
            try? await Task.sleep(nanoseconds: 30_000_000)
        }
    }
    #endif

    @objc private func retryTapped() {
        stopMemoryLoadFillAnimation()
        preHomeProgressTask?.cancel()
        preHomeProgressTask = nil
        bootstrapLoadTask?.cancel()
        bootstrapLoadTask = nil
        retryButton.isHidden = true
        displayedDownloadProgress = 0
        setCaptionText("Downloading Brushi… 0%")
        progressView.isHidden = false
        progressView.setProgress(0, animated: false)
        startBootstrapLoadIfNeeded()
    }

    private func refreshFromModelState() {
        guard isViewLoaded, !didTransitionToHome else { return }
        let vlm = LeapVLMModel.shared

        if vlm.modelLoadDidFail {
            stopMemoryLoadFillAnimation()
            progressView.setIndeterminateActive(false)
            progressView.isHidden = true
            setCaptionText("Couldn't load content")
            retryButton.isHidden = false
            return
        }

        retryButton.isHidden = true
        progressView.isHidden = false

        switch vlm.modelBadgeState {
        case .downloading(let p):
            stopMemoryLoadFillAnimation()
            progressView.setIndeterminateActive(false)
            displayedDownloadProgress = max(
                displayedDownloadProgress,
                min(Self.bootstrapProgressCap, Self.sanitizeProgress(CGFloat(p)))
            )
            let pct = Int((displayedDownloadProgress * 100).rounded(.down))
            setCaptionText("Downloading Brushi… \(pct)%")
            refreshProgressBarFromDisplayedFraction(animated: true)
            progressView.accessibilityLabel = "Download progress, \(pct) percent"
        case .loadingIntoMemory:
            progressView.setIndeterminateActive(false)
            setCaptionText("Loading content…")
            startMemoryLoadFillAnimationIfNeeded()
            progressView.accessibilityLabel = "Loading content into memory"
        case .ready, .simulatorPreview:
            stopMemoryLoadFillAnimation()
            progressView.setIndeterminateActive(false)
            schedulePreHomeProgressIfNeeded()
            return
        default:
            progressView.setIndeterminateActive(false)
            if displayedDownloadProgress > 0 {
                setCaptionText("Loading content…")
                progressView.accessibilityLabel = "Loading content"
            } else {
                setCaptionText("Loading content… 0%")
                progressView.accessibilityLabel = "Loading starting"
            }
            refreshProgressBarFromDisplayedFraction(animated: displayedDownloadProgress > 0)
        }
    }

    private func refreshProgressBarFromDisplayedFraction(animated: Bool = false) {
        progressView.setProgress(Self.sanitizeProgress(displayedDownloadProgress), animated: animated)
    }

    /// When weights are already on disk, Leap gives no byte progress — ease the yellow bar toward full.
    private func startMemoryLoadFillAnimationIfNeeded() {
        memoryLoadFillTimer?.invalidate()
        let start = displayedDownloadProgress
        let cap = Self.bootstrapProgressCap
        let remaining = max(0, cap - start)
        guard remaining > 0.02 else {
            displayedDownloadProgress = cap
            refreshProgressBarFromDisplayedFraction(animated: true)
            return
        }
        let steps = 28
        var tick = 0
        memoryLoadFillTimer = Timer.scheduledTimer(withTimeInterval: 0.06, repeats: true) { [weak self] timer in
            guard let self else {
                timer.invalidate()
                return
            }
            tick += 1
            let t = min(1, CGFloat(tick) / CGFloat(steps))
            self.displayedDownloadProgress = Self.sanitizeProgress(min(cap, start + remaining * t))
            self.refreshProgressBarFromDisplayedFraction(animated: true)
            if tick >= steps || self.displayedDownloadProgress >= cap - 0.01 {
                self.displayedDownloadProgress = cap
                self.refreshProgressBarFromDisplayedFraction(animated: true)
                timer.invalidate()
                self.memoryLoadFillTimer = nil
            }
        }
        if let memoryLoadFillTimer {
            RunLoop.main.add(memoryLoadFillTimer, forMode: .common)
        }
    }

    private func stopMemoryLoadFillAnimation() {
        memoryLoadFillTimer?.invalidate()
        memoryLoadFillTimer = nil
    }

    /// After weights are ready, ease the bar to 50% then 100% so loading feels visible before home.
    private func schedulePreHomeProgressIfNeeded() {
        guard !didTransitionToHome else { return }
        guard preHomeProgressTask == nil else { return }
        #if !targetEnvironment(simulator)
        guard case .ready = LeapVLMModel.shared.modelBadgeState else { return }
        #endif

        preHomeProgressTask = Task { @MainActor [weak self] in
            guard let self else { return }
            await self.playPreHomeProgressRitual()
            guard !Task.isCancelled else { return }
            self.preHomeProgressTask = nil
            self.transitionToHomeIfNeeded()
        }
    }

    private func playPreHomeProgressRitual() async {
        stopMemoryLoadFillAnimation()
        progressView.setIndeterminateActive(false)
        progressView.isHidden = false

        let half = Self.bootstrapProgressCap
        displayedDownloadProgress = half
        setCaptionText("Loading content… 50%")
        refreshProgressBarFromDisplayedFraction(animated: true)
        progressView.accessibilityLabel = "Loading content, 50 percent"
        try? await Task.sleep(nanoseconds: 450_000_000)

        guard !Task.isCancelled else { return }

        displayedDownloadProgress = 1
        setCaptionText("Loading content… 100%")
        refreshProgressBarFromDisplayedFraction(animated: true)
        progressView.accessibilityLabel = "Loading content, 100 percent"
        try? await Task.sleep(nanoseconds: 450_000_000)
    }

    private func transitionToHomeIfNeeded(allowWithoutModel: Bool = false) {
        guard !didTransitionToHome else { return }
        let vlm = LeapVLMModel.shared
        #if targetEnvironment(simulator)
        // Simulator never downloads; proceed after brief branded screen.
        #else
        if !allowWithoutModel {
            guard case .ready = vlm.modelBadgeState else { return }
        }
        #endif

        guard let window = view.window ?? UIApplication.shared.connectedScenes
            .compactMap({ $0 as? UIWindowScene })
            .flatMap(\.windows)
            .first(where: \.isKeyWindow) else { return }

        didTransitionToHome = true
        progressView.setIndeterminateActive(false)

        let homeRoot = MagicBrushyRootNavigation.makeLetterboxedRoot()
        UIView.transition(with: window, duration: 0.5, options: .transitionCrossDissolve) {
            window.rootViewController = homeRoot
        }
    }
}

// MARK: - Shared root stack (bootstrap → home)

enum MagicBrushyRootNavigation {

    static func makeNavigationController() -> UINavigationController {
        let nav = UINavigationController(rootViewController: HomeModePickerViewController())
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
        nav.navigationBar.isTranslucent = true
        nav.navigationBar.setBackgroundImage(UIImage(), for: .default)
        nav.navigationBar.shadowImage = UIImage()
        nav.navigationBar.isHidden = true
        return nav
    }

    static func makeLetterboxedRoot() -> UIViewController {
        LandscapeLetterboxHostViewController(embedded: makeNavigationController())
    }
}
