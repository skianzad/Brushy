import UIKit

private enum HomeModePickerLayout {
    static let mascotColumnWidthFraction: CGFloat = 0.37
    static let bodyStackSpacing: CGFloat = 16
    static let cardStackSpacing: CGFloat = 16
    /// Slightly narrower than the cards column (heights unchanged).
    static let cardWidthFraction: CGFloat = 0.90
    static let cardCornerRadius: CGFloat = 11.5
    static let cardBorderWidth: CGFloat = 5.75
    static let titleBarHeight: CGFloat = 46
    static let titleFontSize: CGFloat = 20
    static let previewInset: CGFloat = 10
    static let previewCornerRadius: CGFloat = 15
    static let previewBorderWidth: CGFloat = 6.9
    static let titleBadgeMaxHeightFraction: CGFloat = 0.40

    /// iPhone landscape — fill more of the safe area with mascot + mode cards.
    static let phoneMainHorizontalInset: CGFloat = 10
    static let phoneBodyTopGap: CGFloat = 2
    static let phoneBodyBottomGap: CGFloat = -6
    static let phoneBodyStackSpacing: CGFloat = 8
    static let phoneCardStackSpacing: CGFloat = 8
    static let phoneMascotWidthFraction: CGFloat = 0.34
    static let phoneMascotMaxWidth: CGFloat = 178
    static let phoneCardHeightFill: CGFloat = 0.98
    static let phoneTitleBarHeight: CGFloat = 42
    static let phoneTitleFontSize: CGFloat = 18
    static let phoneCardCornerRadius: CGFloat = 12.5
    static let phoneCardBorderWidth: CGFloat = 6.2
    static let phonePreviewCornerRadius: CGFloat = 16
    static let phonePreviewBorderWidth: CGFloat = 7.2
    static let phoneTitleBadgeMaxHeightFraction: CGFloat = 0.32
}

/// Root hub (Figma `122:632`) — choose Free Draw vs Coloring before the category grid.
final class HomeModePickerViewController: UIViewController {

    private enum Mode: Int {
        case freeDraw = 0
        case coloring = 1
    }

    private let heroView = FigmaAlignedHeroBackgroundView()
    private let topChromeRow = UIStackView()
    private let homeMainStack = UIStackView()
    private let bodyStack = UIStackView()
    private let mascotColumn = UIView()
    /// Vertical stack: Coloring (top) then Free Draw (bottom).
    private let modeCardsStack = UIStackView()
    private let homeTitleBadge = HomeBrushiTitleBadgeView()
    private let mascotView = UIImageView()
    private let mascotLipSync = MascotLipSyncDriver()
    private var homeWelcomeGeneration = 0
    private var homeWelcomeWork: DispatchWorkItem?
    private var coachAutoFeedbackObserver: NSObjectProtocol?
    private let unlockButton = UIButton(type: .custom)
    private var unlockMinHeightConstraint: NSLayoutConstraint!
    private lazy var settingsButton: MagicBrushySettingsGearButton = makeMagicBrushySettingsGearButton()

    private var freeCard: HomeModeCardView!
    private var coloringCard: HomeModeCardView!
    private let coloringPlaceholderPreview = BuiltInColoringPages.previewImage(packId: "ocean")
    private let freeDrawPlaceholderPreview = BuiltInColoringPages.previewImage(
        packId: BuiltInColoringPages.savedDrawingsPackId
    )

    private var bodyTopToHeaderConstraint: NSLayoutConstraint!
    private var bodyBottomConstraint: NSLayoutConstraint!
    private var cardWidthToStackConstraint: NSLayoutConstraint!
    private var coloringCardWidthConstraint: NSLayoutConstraint!
    private var coloringCardHeightConstraint: NSLayoutConstraint!
    private var freeCardHeightConstraint: NSLayoutConstraint!
    private var mascotWidthFractionConstraint: NSLayoutConstraint!
    private var mascotFixedWidthConstraint: NSLayoutConstraint!
    private var topChromeTrailingToSafeConstraint: NSLayoutConstraint!
    private var topChromeTrailingToBodyConstraint: NSLayoutConstraint!
    private var homeMainLeadingConstraint: NSLayoutConstraint!
    private var homeMainTrailingConstraint: NSLayoutConstraint!
    private var mascotWidthConstraint: NSLayoutConstraint!
    private var mascotHeightConstraint: NSLayoutConstraint!
    private var mascotCenterXConstraint: NSLayoutConstraint!
    private var mascotFillLeadingConstraint: NSLayoutConstraint!
    private var mascotFillTrailingConstraint: NSLayoutConstraint!
    private var subscriptionAccessObserver: NSObjectProtocol?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .black
        navigationController?.setNavigationBarHidden(true, animated: false)

        heroView.heroImage = UIImage(named: "HomeHero")
        heroView.translatesAutoresizingMaskIntoConstraints = false

        mascotColumn.translatesAutoresizingMaskIntoConstraints = false
        mascotColumn.clipsToBounds = false

        let mascotHello = MascotReactionState.hello.loadImage()
            ?? MascotReactionState.neutral.loadImage()
            ?? UIImage(named: "BrushMascot")
        mascotView.image = mascotHello
        mascotView.contentMode = .scaleAspectFit
        mascotView.translatesAutoresizingMaskIntoConstraints = false
        mascotView.isUserInteractionEnabled = false
        mascotLipSync.attach(
            imageView: mascotView,
            closed: UIImage(named: "MascotTalkingMouthClosed")
                ?? MascotReactionState.talking.loadImage(),
            open: UIImage(named: "MascotTalkingMouthOpen")
                ?? MascotReactionState.happy.loadImage(),
            oMouth: UIImage(named: "MascotTalkingMouthO")
                ?? MascotReactionState.oMouth.loadImage()
        )

        homeTitleBadge.translatesAutoresizingMaskIntoConstraints = false
        homeTitleBadge.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
        homeTitleBadge.setContentCompressionResistancePriority(.defaultLow, for: .vertical)
        homeTitleBadge.setContentHuggingPriority(.defaultHigh, for: .vertical)

        coloringCard = HomeModeCardView(
            title: "Coloring",
            style: .coloring,
            previewImage: coloringPlaceholderPreview,
            showsPlusBadge: false
        )
        coloringCard.tag = Mode.coloring.rawValue
        coloringCard.addTarget(self, action: #selector(modeCardTapped(_:)), for: .touchUpInside)

        freeCard = HomeModeCardView(
            title: "Free Draw",
            style: .freeDraw,
            previewImage: freeDrawPlaceholderPreview,
            showsPlusBadge: true
        )
        freeCard.tag = Mode.freeDraw.rawValue
        freeCard.addTarget(self, action: #selector(modeCardTapped(_:)), for: .touchUpInside)

        modeCardsStack.axis = .vertical
        modeCardsStack.spacing = HomeModePickerLayout.cardStackSpacing
        modeCardsStack.distribution = .fillEqually
        modeCardsStack.alignment = .center
        modeCardsStack.translatesAutoresizingMaskIntoConstraints = false
        modeCardsStack.addArrangedSubview(coloringCard)
        modeCardsStack.addArrangedSubview(freeCard)

        bodyStack.axis = .horizontal
        bodyStack.alignment = .fill
        bodyStack.spacing = HomeModePickerLayout.bodyStackSpacing
        bodyStack.distribution = .fill
        bodyStack.translatesAutoresizingMaskIntoConstraints = false
        bodyStack.addArrangedSubview(mascotColumn)
        bodyStack.addArrangedSubview(modeCardsStack)

        mascotColumn.addSubview(homeTitleBadge)
        mascotColumn.addSubview(mascotView)

        configureUnlockButton()
        unlockButton.translatesAutoresizingMaskIntoConstraints = false
        unlockButton.addTarget(self, action: #selector(unlockTapped), for: .touchUpInside)
        unlockButton.setContentCompressionResistancePriority(.required, for: .horizontal)
        unlockButton.setContentHuggingPriority(.required, for: .horizontal)

        topChromeRow.axis = .horizontal
        topChromeRow.spacing = 10
        topChromeRow.alignment = .center
        topChromeRow.distribution = .fill
        topChromeRow.translatesAutoresizingMaskIntoConstraints = false
        topChromeRow.addArrangedSubview(settingsButton)
        topChromeRow.addArrangedSubview(unlockButton)

        homeMainStack.axis = .vertical
        homeMainStack.spacing = 16
        homeMainStack.alignment = .fill
        homeMainStack.distribution = .fill
        homeMainStack.translatesAutoresizingMaskIntoConstraints = false
        homeMainStack.addArrangedSubview(bodyStack)

        view.addSubview(heroView)
        view.addSubview(homeMainStack)
        view.addSubview(topChromeRow)

        let g = view.safeAreaLayoutGuide
        bodyTopToHeaderConstraint = homeMainStack.topAnchor.constraint(equalTo: topChromeRow.bottomAnchor, constant: 8)
        bodyBottomConstraint = homeMainStack.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -22)

        NSLayoutConstraint.activate([
            heroView.topAnchor.constraint(equalTo: view.topAnchor),
            heroView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            heroView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            heroView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            topChromeRow.topAnchor.constraint(equalTo: g.topAnchor, constant: 4),
            topChromeRow.leadingAnchor.constraint(greaterThanOrEqualTo: g.leadingAnchor, constant: 16),
            { unlockMinHeightConstraint = unlockButton.heightAnchor.constraint(
                greaterThanOrEqualToConstant: MagicBrushyChromeMetrics.unlockMinHeight(traitCollection)
            ); return unlockMinHeightConstraint }(),

            bodyTopToHeaderConstraint,
            bodyBottomConstraint,
        ])
        homeMainLeadingConstraint = homeMainStack.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 16)
        homeMainTrailingConstraint = homeMainStack.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -16)
        topChromeTrailingToSafeConstraint = topChromeRow.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -16)
        topChromeTrailingToBodyConstraint = topChromeRow.trailingAnchor.constraint(equalTo: bodyStack.trailingAnchor)
        topChromeTrailingToBodyConstraint.isActive = false
        mascotWidthFractionConstraint = mascotColumn.widthAnchor.constraint(
            equalTo: homeMainStack.widthAnchor,
            multiplier: HomeModePickerLayout.mascotColumnWidthFraction
        )
        mascotFixedWidthConstraint = mascotColumn.widthAnchor.constraint(equalToConstant: 120)
        mascotFixedWidthConstraint.isActive = false
        NSLayoutConstraint.activate([
            homeMainLeadingConstraint,
            homeMainTrailingConstraint,
            topChromeTrailingToSafeConstraint,
            mascotWidthFractionConstraint,

            homeTitleBadge.topAnchor.constraint(equalTo: mascotColumn.topAnchor),
            homeTitleBadge.leadingAnchor.constraint(equalTo: mascotColumn.leadingAnchor),
            homeTitleBadge.trailingAnchor.constraint(equalTo: mascotColumn.trailingAnchor),
            homeTitleBadge.heightAnchor.constraint(
                lessThanOrEqualTo: mascotColumn.heightAnchor,
                multiplier: HomeModePickerLayout.titleBadgeMaxHeightFraction
            ),

            mascotView.topAnchor.constraint(greaterThanOrEqualTo: homeTitleBadge.bottomAnchor, constant: 8),
            mascotView.bottomAnchor.constraint(equalTo: mascotColumn.bottomAnchor),

            freeCard.widthAnchor.constraint(equalTo: coloringCard.widthAnchor),
        ])
        cardWidthToStackConstraint = coloringCard.widthAnchor.constraint(
            equalTo: modeCardsStack.widthAnchor,
            multiplier: HomeModePickerLayout.cardWidthFraction
        )
        coloringCardWidthConstraint = coloringCard.widthAnchor.constraint(equalToConstant: 120)
        coloringCardHeightConstraint = coloringCard.heightAnchor.constraint(equalToConstant: 120)
        freeCardHeightConstraint = freeCard.heightAnchor.constraint(equalTo: coloringCard.heightAnchor)
        NSLayoutConstraint.activate([
            coloringCardWidthConstraint,
            coloringCardHeightConstraint,
            freeCard.widthAnchor.constraint(equalTo: coloringCard.widthAnchor),
            freeCardHeightConstraint,
        ])
        mascotCenterXConstraint = mascotView.centerXAnchor.constraint(equalTo: mascotColumn.centerXAnchor)
        mascotFillLeadingConstraint = mascotView.leadingAnchor.constraint(equalTo: mascotColumn.leadingAnchor, constant: 2)
        mascotFillTrailingConstraint = mascotView.trailingAnchor.constraint(equalTo: mascotColumn.trailingAnchor, constant: -2)
        let mascotSize = BrushiMascotLayout.homeDisplaySize(for: traitCollection, image: mascotView.image)
        mascotWidthConstraint = mascotView.widthAnchor.constraint(equalToConstant: mascotSize.width)
        mascotHeightConstraint = mascotView.heightAnchor.constraint(equalToConstant: mascotSize.height)

        applyBodyLayout(for: traitCollection)
        homeTitleBadge.applyStyle(for: traitCollection)

        subscriptionAccessObserver = NotificationCenter.default.addObserver(
            forName: .magicBrushySubscriptionAccessDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.applySubscribeButtonEnabledState()
        }
        coachAutoFeedbackObserver = NotificationCenter.default.addObserver(
            forName: MagicBrushyCoachAutoFeedback.didChangeNotification,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            guard let self else { return }
            if !MagicBrushyCoachAutoFeedback.isEnabled {
                self.cancelHomeWelcomeSpeech()
            }
        }
        SubscriptionManager.shared.start()
        applySubscribeButtonEnabledState()
        Task { await SubscriptionManager.shared.refreshEntitlements() }
        view.bringSubviewToFront(topChromeRow)
        applyTopChromeLayout(for: traitCollection)
    }

    private func applyTopChromeLayout(for traitCollection: UITraitCollection) {
        settingsButton.applyStyle(for: traitCollection)
        unlockMinHeightConstraint?.constant = MagicBrushyChromeMetrics.unlockMinHeight(traitCollection)
        applySubscribeButtonEnabledState()
    }

    /// iPhone: enlarged mascot + side-by-side mode cards; iPad: stacked layout in the right column.
    private func applyBodyLayout(for traitCollection: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        if phone {
            homeMainStack.alignment = .fill
            bodyStack.alignment = .bottom
            bodyStack.distribution = .fill
            bodyStack.spacing = HomeModePickerLayout.phoneBodyStackSpacing
            mascotWidthFractionConstraint.isActive = false
            mascotFixedWidthConstraint.isActive = true
            modeCardsStack.axis = .horizontal
            modeCardsStack.alignment = .fill
            modeCardsStack.distribution = .fillEqually
            modeCardsStack.spacing = HomeModePickerLayout.phoneCardStackSpacing
            cardWidthToStackConstraint.isActive = false
            coloringCardWidthConstraint.isActive = true
            coloringCardHeightConstraint.isActive = true
            freeCardHeightConstraint.isActive = true
            modeCardsStack.setContentHuggingPriority(.defaultLow, for: .horizontal)
            modeCardsStack.setContentHuggingPriority(.defaultLow, for: .vertical)
            bodyStack.setContentHuggingPriority(.defaultLow, for: .horizontal)
            bodyStack.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
            topChromeTrailingToSafeConstraint.isActive = false
            topChromeTrailingToBodyConstraint.isActive = true
            homeMainLeadingConstraint.constant = HomeModePickerLayout.phoneMainHorizontalInset
            homeMainTrailingConstraint.constant = -HomeModePickerLayout.phoneMainHorizontalInset
            coloringCard.applyPhoneChrome(true)
            freeCard.applyPhoneChrome(true)
        } else {
            homeMainStack.alignment = .fill
            bodyStack.alignment = .fill
            bodyStack.distribution = .fill
            bodyStack.spacing = HomeModePickerLayout.bodyStackSpacing
            mascotFixedWidthConstraint.isActive = false
            mascotWidthFractionConstraint.isActive = true
            modeCardsStack.axis = .vertical
            modeCardsStack.alignment = .center
            modeCardsStack.distribution = .fillEqually
            modeCardsStack.spacing = HomeModePickerLayout.cardStackSpacing
            cardWidthToStackConstraint.isActive = true
            coloringCardWidthConstraint.isActive = false
            coloringCardHeightConstraint.isActive = false
            freeCardHeightConstraint.isActive = false
            modeCardsStack.setContentHuggingPriority(.defaultLow, for: .horizontal)
            modeCardsStack.setContentHuggingPriority(.defaultLow, for: .vertical)
            bodyStack.setContentHuggingPriority(.defaultLow, for: .horizontal)
            bodyStack.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
            topChromeTrailingToBodyConstraint.isActive = false
            topChromeTrailingToSafeConstraint.isActive = true
            homeMainLeadingConstraint.constant = 16
            homeMainTrailingConstraint.constant = -16
            coloringCard.applyPhoneChrome(false)
            freeCard.applyPhoneChrome(false)
        }
        homeTitleBadge.applyStyle(for: traitCollection)
        view.setNeedsLayout()
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        let idiomChanged = previousTraitCollection?.userInterfaceIdiom != traitCollection.userInterfaceIdiom
        if idiomChanged {
            applyTopChromeLayout(for: traitCollection)
            applyBodyLayout(for: traitCollection)
            applyMascotLayout(for: traitCollection)
        }
    }

    private func applyMascotLayout(for traitCollection: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        if phone {
            let mascotSize = BrushiMascotLayout.homeDisplaySize(for: traitCollection, image: mascotView.image)
            mascotWidthConstraint.constant = mascotSize.width
            mascotHeightConstraint.constant = mascotSize.height
            mascotWidthConstraint.isActive = true
            mascotHeightConstraint.isActive = true
            mascotCenterXConstraint.isActive = true
            mascotFillLeadingConstraint.isActive = false
            mascotFillTrailingConstraint.isActive = false
        } else {
            mascotWidthConstraint.isActive = false
            mascotHeightConstraint.isActive = false
            mascotCenterXConstraint.isActive = false
            mascotFillLeadingConstraint.isActive = true
            mascotFillTrailingConstraint.isActive = true
        }
    }

    deinit {
        if let subscriptionAccessObserver {
            NotificationCenter.default.removeObserver(subscriptionAccessObserver)
        }
        if let coachAutoFeedbackObserver {
            NotificationCenter.default.removeObserver(coachAutoFeedbackObserver)
        }
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        refreshModeCardPreviews()
        Task { await SubscriptionManager.shared.refreshEntitlements() }
        applySubscribeButtonEnabledState()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        FeedbackAlbaSpeech.mascotLipSync = mascotLipSync
        scheduleHomeWelcomeSpeech()
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        cancelHomeWelcomeSpeech()
        FeedbackAlbaSpeech.mascotLipSync = nil
    }

    private func refreshModeCardPreviews() {
        if let thumb = RecentDrawingActivity.latestColoringThumbnail() {
            coloringCard.setPreviewImage(thumb, contentMode: .scaleAspectFit)
        } else {
            coloringCard.setPreviewImage(coloringPlaceholderPreview, contentMode: .scaleAspectFit)
        }

        if let thumb = RecentDrawingActivity.latestFreeDrawingThumbnail() {
            freeCard.setPreviewImage(thumb, contentMode: .scaleAspectFit)
            freeCard.setShowsPlusBadge(false)
        } else {
            freeCard.setPreviewImage(freeDrawPlaceholderPreview, contentMode: .scaleAspectFit)
            freeCard.setShowsPlusBadge(true)
        }
    }

    private func scheduleHomeWelcomeSpeech() {
        guard MagicBrushyCoachAutoFeedback.isEnabled else { return }
        homeWelcomeWork?.cancel()
        homeWelcomeGeneration += 1
        let generation = homeWelcomeGeneration
        let work = DispatchWorkItem { [weak self] in
            self?.runHomeWelcomeSpeech(generation: generation)
        }
        homeWelcomeWork = work
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.55, execute: work)
    }

    private func runHomeWelcomeSpeech(generation: Int) {
        guard generation == homeWelcomeGeneration else { return }
        guard MagicBrushyCoachAutoFeedback.isEnabled else { return }
        guard view.window != nil else { return }

        let recents = RecentDrawingActivity.homeRecents()
        let isPhone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        let spoken = Prompt.homeModePickerWelcome(recents: recents, isPhone: isPhone)
        guard !spoken.isEmpty else { return }

        if let hello = MascotReactionState.hello.loadImage() {
            mascotView.image = hello
        }

        Task { @MainActor [weak self] in
            guard let self, generation == self.homeWelcomeGeneration else { return }
            await FeedbackAlbaSpeech.speakFeedback(spoken)
        }
    }

    private func cancelHomeWelcomeSpeech() {
        homeWelcomeWork?.cancel()
        homeWelcomeWork = nil
        homeWelcomeGeneration += 1
        FeedbackAlbaSpeech.stopSpeaking()
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        let compact = traitCollection.verticalSizeClass == .compact
        if phone {
            bodyTopToHeaderConstraint?.constant = HomeModePickerLayout.phoneBodyTopGap
            bodyBottomConstraint?.constant = HomeModePickerLayout.phoneBodyBottomGap
            homeMainStack.spacing = 8
        } else {
            bodyTopToHeaderConstraint?.constant = compact ? 4 : 8
            bodyBottomConstraint?.constant = compact ? -10 : -22
            homeMainStack.spacing = compact ? 10 : 16
            bodyStack.spacing = compact ? 8 : HomeModePickerLayout.bodyStackSpacing
            modeCardsStack.spacing = compact ? 10 : HomeModePickerLayout.cardStackSpacing
        }
        if phone {
            layoutPhoneBody()
        }
        applyMascotLayout(for: traitCollection)
    }

    /// Sizes mascot + mode cards to fill iPhone landscape body height.
    private func layoutPhoneBody() {
        let mainW = homeMainStack.bounds.width
        let bodyH = bodyStack.bounds.height
        guard mainW > 80, bodyH > 60 else { return }

        let mascotBase = BrushiMascotLayout.homeDisplaySize(for: traitCollection, image: mascotView.image).width
        let mascotW = min(
            HomeModePickerLayout.phoneMascotMaxWidth,
            max(mascotBase + 10, mainW * HomeModePickerLayout.phoneMascotWidthFraction)
        )
        mascotFixedWidthConstraint.constant = mascotW

        let cardRowW = mainW - mascotW - bodyStack.spacing
        let cardH = floor(bodyH * HomeModePickerLayout.phoneCardHeightFill)
        let cardW = floor((cardRowW - modeCardsStack.spacing) / 2)
        let side = min(cardH, cardW)
        guard side > 48 else { return }

        if coloringCardWidthConstraint.constant != side {
            coloringCardWidthConstraint.constant = side
            coloringCardHeightConstraint.constant = side
        }
    }

    @objc private func modeCardTapped(_ sender: UIControl) {
        cancelHomeWelcomeSpeech()
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
        guard let mode = Mode(rawValue: sender.tag) else { return }
        switch mode {
        case .freeDraw:
            let grid = CategoryGridViewController()
            grid.initialPackId = BuiltInColoringPages.savedDrawingsPackId
            navigationController?.pushViewController(grid, animated: true)
        case .coloring:
            navigationController?.pushViewController(HomeViewController(), animated: true)
        }
    }

    private func configureUnlockButton() {
        unlockButton.layer.shadowColor = UIColor.black.cgColor
        unlockButton.layer.shadowOpacity = 0.22
        unlockButton.layer.shadowRadius = 8
        unlockButton.layer.shadowOffset = CGSize(width: 0, height: 3)
        applySubscribeButtonEnabledState()
    }

    private func applySubscribeButtonEnabledState() {
        let full = SubscriptionManager.shared.hasFullLibraryAccess
        let tc = traitCollection
        unlockButton.isEnabled = !full
        unlockButton.alpha = full ? 0.55 : 1

        var cfg = UIButton.Configuration.filled()
        cfg.title = full ? "Unlocked" : "Unlock all"
        let symbolName = full ? "lock.open.fill" : "lock.fill"
        let symCfg = UIImage.SymbolConfiguration(
            pointSize: MagicBrushyChromeMetrics.unlockSymbolPointSize(tc),
            weight: .semibold
        )
        cfg.image = UIImage(systemName: symbolName, withConfiguration: symCfg)
        cfg.imagePlacement = .leading
        cfg.imagePadding = MagicBrushyChromeMetrics.isPhone(tc) ? 6 : 8
        cfg.contentInsets = MagicBrushyChromeMetrics.unlockContentInsets(tc)
        cfg.cornerStyle = .large
        cfg.baseForegroundColor = .white
        cfg.baseBackgroundColor = FigmaTheme.primaryOrange
        cfg.background.strokeColor = FigmaTheme.primaryOrangeBorder
        cfg.background.strokeWidth = 3
        let titleSize = MagicBrushyChromeMetrics.unlockTitleFontSize(tc)
        cfg.titleTextAttributesTransformer = UIConfigurationTextAttributesTransformer { incoming in
            var out = incoming
            out.font = FigmaTheme.bodyFont(size: titleSize, weight: .bold)
            return out
        }
        unlockButton.configuration = cfg
    }

    @objc private func unlockTapped() {
        guard !SubscriptionManager.shared.hasFullLibraryAccess else { return }
        let sheet = UIAlertController(
            title: "Full library",
            message: "Subscribe with your Apple ID, restore a past purchase, or solve a quick multiplication puzzle to unlock every coloring category. Free Draw is always free.",
            preferredStyle: .actionSheet
        )
        sheet.addAction(UIAlertAction(title: "Subscribe", style: .default, handler: { [weak self] _ in
            guard let self else { return }
            Task { await SubscriptionManager.shared.purchase(from: self) }
        }))
        sheet.addAction(UIAlertAction(title: "Restore purchases", style: .default, handler: { [weak self] _ in
            guard let self else { return }
            Task { await SubscriptionManager.shared.restorePurchases(from: self) }
        }))
        sheet.addAction(UIAlertAction(title: "Solve puzzle", style: .default, handler: { [weak self] _ in
            self?.presentPuzzleCodeUnlock()
        }))
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        if let pop = sheet.popoverPresentationController {
            pop.sourceView = unlockButton
            pop.sourceRect = unlockButton.bounds
        }
        present(sheet, animated: true)
    }

    private func presentPuzzleCodeUnlock() {
        let a = Int.random(in: 3...9)
        let b = Int.random(in: 3...9)
        let expectedAnswer = a * b
        let sheet = UIAlertController(
            title: "Unlock",
            message: "What is \(a) × \(b)? Enter the answer to unlock every category.",
            preferredStyle: .alert
        )
        sheet.addTextField { $0.keyboardType = .numberPad }
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        sheet.addAction(UIAlertAction(title: "Unlock", style: .default, handler: { _ in
            guard let raw = sheet.textFields?.first?.text?.trimmingCharacters(in: .whitespacesAndNewlines),
                  let userAnswer = Int(raw),
                  userAnswer == expectedAnswer
            else {
                UIImpactFeedbackGenerator(style: .rigid).impactOccurred()
                return
            }
            UserDefaults.standard.set(true, forKey: SubscriptionManager.legacyUnlockAllKey)
            UIImpactFeedbackGenerator(style: .light).impactOccurred()
            NotificationCenter.default.post(name: .magicBrushySubscriptionAccessDidChange, object: nil)
            self.applySubscribeButtonEnabledState()
        }))
        present(sheet, animated: true)
    }
}

// MARK: - Mode card (Figma `122:824` / `122:989`)

private final class HomeModeCardView: UIButton {

    enum Style {
        case freeDraw
        case coloring
    }

    private let previewImageView: UIImageView
    private let cardTitleLabel: UILabel
    private let titleBar: UIView
    private let previewFrame: UIView
    private var titleBarHeightConstraint: NSLayoutConstraint!
    private var plusBadge: UIView?

    init(title: String, style: Style, previewImage: UIImage?, showsPlusBadge: Bool) {
        previewImageView = UIImageView(image: previewImage)
        titleBar = UIView()
        cardTitleLabel = UILabel()
        previewFrame = UIView()

        super.init(frame: .zero)

        previewImageView.translatesAutoresizingMaskIntoConstraints = false
        previewImageView.contentMode = .scaleAspectFit
        previewImageView.isUserInteractionEnabled = false

        translatesAutoresizingMaskIntoConstraints = false
        clipsToBounds = true
        isUserInteractionEnabled = true
        adjustsImageWhenHighlighted = false
        layer.cornerRadius = HomeModePickerLayout.cardCornerRadius
        if #available(iOS 13.0, *) {
            layer.cornerCurve = .continuous
        }
        layer.borderWidth = HomeModePickerLayout.cardBorderWidth

        let fillColor: UIColor
        let borderColor: UIColor
        let previewBorderColor: UIColor
        switch style {
        case .freeDraw:
            fillColor = FigmaTheme.freeDrawModeFill
            borderColor = FigmaTheme.freeDrawModeBorder
            previewBorderColor = FigmaTheme.freeDrawModeBorder
        case .coloring:
            fillColor = FigmaTheme.coloringModeFill
            borderColor = FigmaTheme.coloringModeBorder
            previewBorderColor = FigmaTheme.coloringModeBorder
        }
        layer.borderColor = borderColor.cgColor
        FigmaTheme.applyCardShadow(to: layer)

        let fill = UIView()
        fill.translatesAutoresizingMaskIntoConstraints = false
        fill.backgroundColor = fillColor
        fill.isUserInteractionEnabled = false

        let wood = UIImageView(image: UIImage(named: "HomeModeCardWood"))
        wood.translatesAutoresizingMaskIntoConstraints = false
        wood.contentMode = .scaleAspectFill
        wood.alpha = 0.5
        wood.clipsToBounds = true
        wood.isUserInteractionEnabled = false

        titleBar.translatesAutoresizingMaskIntoConstraints = false
        titleBar.backgroundColor = borderColor.withAlphaComponent(0.35)
        titleBar.isUserInteractionEnabled = false

        cardTitleLabel.translatesAutoresizingMaskIntoConstraints = false
        cardTitleLabel.text = title
        cardTitleLabel.textColor = FigmaTheme.creamText
        cardTitleLabel.font = FigmaTheme.bodyFont(size: HomeModePickerLayout.titleFontSize, weight: .semibold)
        cardTitleLabel.textAlignment = .center
        cardTitleLabel.adjustsFontSizeToFitWidth = true
        cardTitleLabel.minimumScaleFactor = 0.7
        cardTitleLabel.isUserInteractionEnabled = false

        previewFrame.translatesAutoresizingMaskIntoConstraints = false
        previewFrame.backgroundColor = .white
        previewFrame.layer.cornerRadius = HomeModePickerLayout.previewCornerRadius
        previewFrame.layer.borderWidth = HomeModePickerLayout.previewBorderWidth
        previewFrame.layer.borderColor = previewBorderColor.cgColor
        previewFrame.clipsToBounds = true
        previewFrame.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            previewFrame.layer.cornerCurve = .continuous
        }

        addSubview(fill)
        addSubview(wood)
        addSubview(titleBar)
        titleBar.addSubview(cardTitleLabel)
        addSubview(previewFrame)
        previewFrame.addSubview(previewImageView)

        if showsPlusBadge {
            let badge = UIView()
            badge.translatesAutoresizingMaskIntoConstraints = false
            badge.backgroundColor = FigmaTheme.primaryOrange
            badge.layer.cornerRadius = 22
            badge.layer.borderWidth = 3
            badge.layer.borderColor = FigmaTheme.primaryOrangeBorder.cgColor
            badge.isUserInteractionEnabled = false
            FigmaTheme.applyCardShadow(to: badge.layer)

            let plusIcon = UIImageView(
                image: UIImage(
                    systemName: "plus",
                    withConfiguration: UIImage.SymbolConfiguration(pointSize: 22, weight: .bold)
                )
            )
            plusIcon.translatesAutoresizingMaskIntoConstraints = false
            plusIcon.tintColor = .white
            plusIcon.contentMode = .scaleAspectFit
            badge.addSubview(plusIcon)
            previewFrame.addSubview(badge)
            plusBadge = badge

            NSLayoutConstraint.activate([
                badge.centerXAnchor.constraint(equalTo: previewImageView.centerXAnchor),
                badge.centerYAnchor.constraint(equalTo: previewImageView.centerYAnchor),
                badge.widthAnchor.constraint(equalToConstant: 44),
                badge.heightAnchor.constraint(equalToConstant: 44),
                plusIcon.centerXAnchor.constraint(equalTo: badge.centerXAnchor),
                plusIcon.centerYAnchor.constraint(equalTo: badge.centerYAnchor),
            ])
        }

        NSLayoutConstraint.activate([
            fill.topAnchor.constraint(equalTo: topAnchor),
            fill.leadingAnchor.constraint(equalTo: leadingAnchor),
            fill.trailingAnchor.constraint(equalTo: trailingAnchor),
            fill.bottomAnchor.constraint(equalTo: bottomAnchor),

            wood.topAnchor.constraint(equalTo: topAnchor),
            wood.leadingAnchor.constraint(equalTo: leadingAnchor),
            wood.trailingAnchor.constraint(equalTo: trailingAnchor),
            wood.bottomAnchor.constraint(equalTo: bottomAnchor),

            titleBar.topAnchor.constraint(equalTo: topAnchor),
            titleBar.leadingAnchor.constraint(equalTo: leadingAnchor),
            titleBar.trailingAnchor.constraint(equalTo: trailingAnchor),
            { titleBarHeightConstraint = titleBar.heightAnchor.constraint(
                equalToConstant: HomeModePickerLayout.titleBarHeight
            ); return titleBarHeightConstraint }(),

            cardTitleLabel.leadingAnchor.constraint(equalTo: titleBar.leadingAnchor, constant: 8),
            cardTitleLabel.trailingAnchor.constraint(equalTo: titleBar.trailingAnchor, constant: -8),
            cardTitleLabel.centerYAnchor.constraint(equalTo: titleBar.centerYAnchor),

            previewFrame.leadingAnchor.constraint(equalTo: leadingAnchor, constant: HomeModePickerLayout.previewInset),
            previewFrame.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -HomeModePickerLayout.previewInset),
            previewFrame.topAnchor.constraint(equalTo: titleBar.bottomAnchor, constant: HomeModePickerLayout.previewInset),
            previewFrame.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -HomeModePickerLayout.previewInset),

            previewImageView.leadingAnchor.constraint(equalTo: previewFrame.leadingAnchor, constant: 8),
            previewImageView.trailingAnchor.constraint(equalTo: previewFrame.trailingAnchor, constant: -8),
            previewImageView.topAnchor.constraint(equalTo: previewFrame.topAnchor, constant: 8),
            previewImageView.bottomAnchor.constraint(equalTo: previewFrame.bottomAnchor, constant: -8),
        ])
    }

    func applyPhoneChrome(_ phone: Bool) {
        layer.cornerRadius = phone
            ? HomeModePickerLayout.phoneCardCornerRadius
            : HomeModePickerLayout.cardCornerRadius
        layer.borderWidth = phone
            ? HomeModePickerLayout.phoneCardBorderWidth
            : HomeModePickerLayout.cardBorderWidth
        titleBarHeightConstraint.constant = phone
            ? HomeModePickerLayout.phoneTitleBarHeight
            : HomeModePickerLayout.titleBarHeight
        cardTitleLabel.font = FigmaTheme.bodyFont(
            size: phone ? HomeModePickerLayout.phoneTitleFontSize : HomeModePickerLayout.titleFontSize,
            weight: .semibold
        )
        previewFrame.layer.cornerRadius = phone
            ? HomeModePickerLayout.phonePreviewCornerRadius
            : HomeModePickerLayout.previewCornerRadius
        previewFrame.layer.borderWidth = phone
            ? HomeModePickerLayout.phonePreviewBorderWidth
            : HomeModePickerLayout.previewBorderWidth
    }

    func setPreviewImage(_ image: UIImage?, contentMode: UIView.ContentMode) {
        previewImageView.image = image
        previewImageView.contentMode = contentMode
    }

    func setShowsPlusBadge(_ shows: Bool) {
        plusBadge?.isHidden = !shows
    }

    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override var isHighlighted: Bool {
        didSet { alpha = isHighlighted ? 0.88 : 1 }
    }

    /// Entire card surface (including preview/thumbnail) accepts taps.
    override func point(inside point: CGPoint, with event: UIEvent?) -> Bool {
        bounds.contains(point)
    }
}
