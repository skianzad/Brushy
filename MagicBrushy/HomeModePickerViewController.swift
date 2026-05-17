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
    private let unlockButton = UIButton(type: .custom)
    private var unlockMinHeightConstraint: NSLayoutConstraint!
    private lazy var settingsButton: MagicBrushySettingsGearButton = makeMagicBrushySettingsGearButton()

    private var freeCard: HomeModeCardView!
    private var coloringCard: HomeModeCardView!

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

        mascotView.image = UIImage(named: "BrushMascot")
        mascotView.contentMode = .scaleAspectFit
        mascotView.translatesAutoresizingMaskIntoConstraints = false
        mascotView.isUserInteractionEnabled = false

        homeTitleBadge.translatesAutoresizingMaskIntoConstraints = false
        homeTitleBadge.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
        homeTitleBadge.setContentCompressionResistancePriority(.defaultLow, for: .vertical)
        homeTitleBadge.setContentHuggingPriority(.defaultHigh, for: .vertical)

        coloringCard = HomeModeCardView(
            title: "Coloring",
            style: .coloring,
            previewImage: BuiltInColoringPages.previewImage(packId: "animals"),
            showsPlusBadge: false
        )
        coloringCard.tag = Mode.coloring.rawValue
        coloringCard.addTarget(self, action: #selector(modeCardTapped(_:)), for: .touchUpInside)

        freeCard = HomeModeCardView(
            title: "Free Draw",
            style: .freeDraw,
            previewImage: BuiltInColoringPages.previewImage(packId: BuiltInColoringPages.savedDrawingsPackId),
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
                equalTo: homeTitleBadge.widthAnchor,
                multiplier: HomeBrushiTitleBadgeView.Metrics.heightPerWidth
            ),
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

        subscriptionAccessObserver = NotificationCenter.default.addObserver(
            forName: .magicBrushySubscriptionAccessDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.applySubscribeButtonEnabledState()
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

    /// iPhone: compact row of square tiles + hugging mascot; iPad: original stacked layout.
    private func applyBodyLayout(for traitCollection: UITraitCollection) {
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        if phone {
            homeMainStack.alignment = .center
            bodyStack.alignment = .center
            bodyStack.distribution = .fill
            bodyStack.spacing = 10
            mascotWidthFractionConstraint.isActive = false
            mascotFixedWidthConstraint.isActive = true
            modeCardsStack.axis = .horizontal
            modeCardsStack.alignment = .fill
            modeCardsStack.distribution = .fill
            modeCardsStack.spacing = 10
            cardWidthToStackConstraint.isActive = false
            coloringCardWidthConstraint.isActive = true
            coloringCardHeightConstraint.isActive = true
            freeCardHeightConstraint.isActive = true
            modeCardsStack.setContentHuggingPriority(.required, for: .horizontal)
            modeCardsStack.setContentHuggingPriority(.required, for: .vertical)
            bodyStack.setContentHuggingPriority(.required, for: .horizontal)
            bodyStack.setContentCompressionResistancePriority(.required, for: .horizontal)
            topChromeTrailingToSafeConstraint.isActive = false
            topChromeTrailingToBodyConstraint.isActive = true
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
        }
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
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        Task { await SubscriptionManager.shared.refreshEntitlements() }
        applySubscribeButtonEnabledState()
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        let phone = MagicBrushyChromeMetrics.isPhone(traitCollection)
        let compact = traitCollection.verticalSizeClass == .compact
        bodyTopToHeaderConstraint?.constant = compact ? 4 : 8
        bodyBottomConstraint?.constant = compact ? -10 : -22
        homeMainStack.spacing = compact ? 10 : 16
        if !phone {
            bodyStack.spacing = compact ? 8 : HomeModePickerLayout.bodyStackSpacing
            modeCardsStack.spacing = compact ? 10 : HomeModePickerLayout.cardStackSpacing
        }
        if phone {
            layoutPhoneBody()
        }
        applyMascotLayout(for: traitCollection)
    }

    /// Sizes mascot + square cards from available space so the row stays centered without a wide empty gutter.
    private func layoutPhoneBody() {
        let mainW = homeMainStack.bounds.width
        let bodyH = bodyStack.bounds.height
        guard mainW > 80, bodyH > 60 else { return }

        let mascotW = max(min(132, mainW * 0.26), min(mainW * 0.37, BrushiMascotLayout.homeDisplaySize(for: traitCollection, image: mascotView.image).width + 8))
        mascotFixedWidthConstraint.constant = mascotW

        let cardRowW = mainW - mascotW - bodyStack.spacing
        let side = floor(min(bodyH, (cardRowW - modeCardsStack.spacing) / 2))
        guard side > 40 else { return }

        if coloringCardWidthConstraint.constant != side {
            coloringCardWidthConstraint.constant = side
            coloringCardHeightConstraint.constant = side
        }
    }

    @objc private func modeCardTapped(_ sender: UIControl) {
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

    init(title: String, style: Style, previewImage: UIImage?, showsPlusBadge: Bool) {
        super.init(frame: .zero)
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

        let titleBar = UIView()
        titleBar.translatesAutoresizingMaskIntoConstraints = false
        titleBar.backgroundColor = borderColor.withAlphaComponent(0.35)
        titleBar.isUserInteractionEnabled = false

        let titleLabel = UILabel()
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        titleLabel.text = title
        titleLabel.textColor = FigmaTheme.creamText
        titleLabel.font = FigmaTheme.bodyFont(size: HomeModePickerLayout.titleFontSize, weight: .semibold)
        titleLabel.textAlignment = .center
        titleLabel.adjustsFontSizeToFitWidth = true
        titleLabel.minimumScaleFactor = 0.7
        titleLabel.isUserInteractionEnabled = false

        let previewFrame = UIView()
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

        let preview = UIImageView(image: previewImage)
        preview.translatesAutoresizingMaskIntoConstraints = false
        preview.contentMode = .scaleAspectFit
        preview.isUserInteractionEnabled = false

        addSubview(fill)
        addSubview(wood)
        addSubview(titleBar)
        titleBar.addSubview(titleLabel)
        addSubview(previewFrame)
        previewFrame.addSubview(preview)

        if showsPlusBadge {
            let plusBadge = UIView()
            plusBadge.translatesAutoresizingMaskIntoConstraints = false
            plusBadge.backgroundColor = FigmaTheme.primaryOrange
            plusBadge.layer.cornerRadius = 22
            plusBadge.layer.borderWidth = 3
            plusBadge.layer.borderColor = FigmaTheme.primaryOrangeBorder.cgColor
            plusBadge.isUserInteractionEnabled = false
            FigmaTheme.applyCardShadow(to: plusBadge.layer)

            let plusIcon = UIImageView(
                image: UIImage(
                    systemName: "plus",
                    withConfiguration: UIImage.SymbolConfiguration(pointSize: 22, weight: .bold)
                )
            )
            plusIcon.translatesAutoresizingMaskIntoConstraints = false
            plusIcon.tintColor = .white
            plusIcon.contentMode = .scaleAspectFit
            plusBadge.addSubview(plusIcon)
            previewFrame.addSubview(plusBadge)

            NSLayoutConstraint.activate([
                plusBadge.centerXAnchor.constraint(equalTo: preview.centerXAnchor),
                plusBadge.centerYAnchor.constraint(equalTo: preview.centerYAnchor),
                plusBadge.widthAnchor.constraint(equalToConstant: 44),
                plusBadge.heightAnchor.constraint(equalToConstant: 44),
                plusIcon.centerXAnchor.constraint(equalTo: plusBadge.centerXAnchor),
                plusIcon.centerYAnchor.constraint(equalTo: plusBadge.centerYAnchor),
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
            titleBar.heightAnchor.constraint(equalToConstant: HomeModePickerLayout.titleBarHeight),

            titleLabel.leadingAnchor.constraint(equalTo: titleBar.leadingAnchor, constant: 8),
            titleLabel.trailingAnchor.constraint(equalTo: titleBar.trailingAnchor, constant: -8),
            titleLabel.centerYAnchor.constraint(equalTo: titleBar.centerYAnchor),

            previewFrame.leadingAnchor.constraint(equalTo: leadingAnchor, constant: HomeModePickerLayout.previewInset),
            previewFrame.trailingAnchor.constraint(equalTo: trailingAnchor, constant: -HomeModePickerLayout.previewInset),
            previewFrame.topAnchor.constraint(equalTo: titleBar.bottomAnchor, constant: HomeModePickerLayout.previewInset),
            previewFrame.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -HomeModePickerLayout.previewInset),

            preview.leadingAnchor.constraint(equalTo: previewFrame.leadingAnchor, constant: 8),
            preview.trailingAnchor.constraint(equalTo: previewFrame.trailingAnchor, constant: -8),
            preview.topAnchor.constraint(equalTo: previewFrame.topAnchor, constant: 8),
            preview.bottomAnchor.constraint(equalTo: previewFrame.bottomAnchor, constant: -8),
        ])
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
