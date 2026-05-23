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
    private var memoryLoadFillTimer: Timer?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = FigmaTheme.bootstrapSky

        heroView.heroImage = UIImage(named: "HomeHero")
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
        startBootstrapLoadIfNeeded()
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        refreshProgressBarFromDisplayedFraction()
    }

    deinit {
        memoryLoadFillTimer?.invalidate()
        if let loadPanelObserver {
            NotificationCenter.default.removeObserver(loadPanelObserver)
        }
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
        progressView.setIndeterminateActive(false)
        displayedDownloadProgress = 0
        refreshProgressBarFromDisplayedFraction(animated: false)
        Task { @MainActor [weak self] in
            guard let self else { return }
            #if targetEnvironment(simulator)
            await self.animateSimulatorBootstrapFill()
            self.transitionToHomeIfNeeded()
            #else
            await LeapVLMModel.shared.load()
            self.stopMemoryLoadFillAnimation()
            self.refreshFromModelState()
            self.transitionToHomeIfNeeded()
            #endif
        }
    }

    #if targetEnvironment(simulator)
    private func animateSimulatorBootstrapFill() async {
        progressView.setIndeterminateActive(false)
        for step in 0...24 {
            displayedDownloadProgress = CGFloat(step) / 24
            let pct = Int((displayedDownloadProgress * 100).rounded(.down))
            setCaptionText("Loading content… \(pct)%")
            refreshProgressBarFromDisplayedFraction(animated: step > 0)
            try? await Task.sleep(nanoseconds: 25_000_000)
        }
    }
    #endif

    @objc private func retryTapped() {
        stopMemoryLoadFillAnimation()
        retryButton.isHidden = true
        displayedDownloadProgress = 0
        setCaptionText("Downloading content… 0%")
        progressView.isHidden = false
        progressView.setProgress(0, animated: false)
        Task { @MainActor in
            await LeapVLMModel.shared.load()
            refreshFromModelState()
            transitionToHomeIfNeeded()
        }
    }

    private func refreshFromModelState() {
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
            displayedDownloadProgress = max(displayedDownloadProgress, CGFloat(p))
            let pct = Int((displayedDownloadProgress * 100).rounded(.down))
            setCaptionText("Downloading content… \(pct)%")
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
            displayedDownloadProgress = 1
            refreshProgressBarFromDisplayedFraction(animated: true)
            setCaptionText("Loading content...")
            progressView.accessibilityLabel = "Loading content"
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

        transitionToHomeIfNeeded()
    }

    private func refreshProgressBarFromDisplayedFraction(animated: Bool = false) {
        progressView.setProgress(displayedDownloadProgress, animated: animated)
    }

    /// When weights are already on disk, Leap gives no byte progress — ease the yellow bar toward full.
    private func startMemoryLoadFillAnimationIfNeeded() {
        memoryLoadFillTimer?.invalidate()
        let start = displayedDownloadProgress
        let remaining = max(0, 1 - start)
        guard remaining > 0.02 else {
            displayedDownloadProgress = 1
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
            self.displayedDownloadProgress = start + remaining * t
            self.refreshProgressBarFromDisplayedFraction(animated: true)
            if tick >= steps {
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

    private func transitionToHomeIfNeeded() {
        guard !didTransitionToHome else { return }
        let vlm = LeapVLMModel.shared
        #if targetEnvironment(simulator)
        // Simulator never downloads; proceed after brief branded screen.
        #else
        guard case .ready = vlm.modelBadgeState else { return }
        #endif

        didTransitionToHome = true
        progressView.setIndeterminateActive(false)

        guard let window = view.window ?? UIApplication.shared.connectedScenes
            .compactMap({ $0 as? UIWindowScene })
            .flatMap(\.windows)
            .first(where: \.isKeyWindow) else { return }

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
