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

        progressView.setProgress(0.02, animated: false)
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
        Task { @MainActor [weak self] in
            guard let self else { return }
            #if targetEnvironment(simulator)
            try? await Task.sleep(nanoseconds: 350_000_000)
            self.transitionToHomeIfNeeded()
            #else
            await LeapVLMModel.shared.load()
            self.refreshFromModelState()
            self.transitionToHomeIfNeeded()
            #endif
        }
    }

    @objc private func retryTapped() {
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
            progressView.setIndeterminateActive(false)
            displayedDownloadProgress = max(displayedDownloadProgress, CGFloat(p))
            let pct = Int((displayedDownloadProgress * 100).rounded(.down))
            setCaptionText("Downloading content… \(pct)%")
            refreshProgressBarFromDisplayedFraction(animated: true)
            progressView.accessibilityLabel = "Download progress, \(pct) percent"
        case .loadingIntoMemory:
            setCaptionText("Loading content…")
            displayedDownloadProgress = 1
            progressView.setIndeterminateActive(true)
            progressView.setProgress(1, animated: true)
            progressView.accessibilityLabel = "Loading content into memory"
        case .ready, .simulatorPreview:
            progressView.setIndeterminateActive(false)
            progressView.setProgress(1, animated: true)
            setCaptionText("Loading content...")
            progressView.accessibilityLabel = "Loading content"
        default:
            progressView.setIndeterminateActive(false)
            setCaptionText("Downloading content… 0%")
            displayedDownloadProgress = max(displayedDownloadProgress, 0.02)
            refreshProgressBarFromDisplayedFraction(animated: false)
            progressView.accessibilityLabel = "Download starting"
        }

        transitionToHomeIfNeeded()
    }

    private func refreshProgressBarFromDisplayedFraction(animated: Bool = false) {
        progressView.setProgress(displayedDownloadProgress, animated: animated)
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
