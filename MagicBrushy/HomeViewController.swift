import UIKit

/// Home — landscape layout: unlock in header; title over mascot; category grid ~3.5×3 visible (clipped row hints scroll).
final class HomeViewController: UIViewController {

    private enum Category: Int, CaseIterable {
        case ocean = 0
        case animals = 1
        case dinosaurs = 2
        case famousArt = 3
        case fantasyAndMagic = 4
        case food = 5
        case naturePlants = 6
        case sports = 7
        case vehicles = 8
        case winterSports = 9
        case freeDrawing = 10

        var title: String {
            switch self {
            case .freeDrawing: return "Free draw"
            case .ocean: return "Ocean"
            case .animals: return "Animals"
            case .dinosaurs: return "Dinosaurs"
            case .famousArt: return "Art"
            case .fantasyAndMagic: return "Fantasy & Magic"
            case .food: return "Food"
            case .naturePlants: return "Nature & Plants"
            case .sports: return "Sports"
            case .vehicles: return "Vehicles"
            case .winterSports: return "Winter"
            }
        }

        var packId: String {
            switch self {
            case .freeDrawing: return BuiltInColoringPages.savedDrawingsPackId
            case .ocean: return "ocean"
            case .animals: return "animals"
            case .dinosaurs: return "dinosaurs"
            case .famousArt: return "famous_art"
            case .fantasyAndMagic: return "fantasy_and_magic"
            case .food: return "food"
            case .naturePlants: return "nature_plants"
            case .sports: return "sports"
            case .vehicles: return "vehicles"
            case .winterSports: return "winter_sports"
            }
        }

        var accent: UIColor {
            switch self {
            case .freeDrawing: return FigmaTheme.actionBlue
            case .animals: return FigmaTheme.animalsAccent
            case .ocean: return FigmaTheme.oceanAccent
            case .dinosaurs: return FigmaTheme.dinosaursAccent
            case .famousArt: return FigmaTheme.famousArtAccent
            case .fantasyAndMagic: return FigmaTheme.fantasyAccent
            case .food: return FigmaTheme.foodAccent
            case .naturePlants: return FigmaTheme.natureAccent
            case .sports: return FigmaTheme.sportsAccent
            case .vehicles: return FigmaTheme.vehiclesAccent
            case .winterSports: return FigmaTheme.winterSportsAccent
            }
        }

        var isFreeTier: Bool {
            switch self {
            case .freeDrawing, .ocean, .animals:
                return true
            default:
                return false
            }
        }
    }

    private var subscriptionAccessObserver: NSObjectProtocol?

    private let scrollView = UIScrollView()
    private let contentView = UIView()
    private let heroView = FigmaAlignedHeroBackgroundView()
    private let headerView = UIView()
    private let mascotColumn = UIView()
    /// Holds stroke (behind) + fill + scroll; stroke extends past fill like Figma export.
    private let categoryGridPanelWrapper = UIView()
    private let categoryGridPanelStroke = UIView()
    private let categoryGridPanel = UIView()
    private let mascotView = UIImageView()
    private let titleLabel = UILabel()
    private let bodyStack = UIStackView()
    private let gridStack = UIStackView()
    private let categoryGridScrollView = UIScrollView()
    private let categoryGridContentView = UIView()
    private var categoryGridViewportHeightConstraint: NSLayoutConstraint!
    private let unlockButton = UIButton(type: .custom)

    private let musicVolumeStack = UIStackView()
    private let musicVolumeIcon = UIImageView()
    private let musicVolumeSlider = UISlider()

    private let assetsLoadChip = UIView()
    private let assetsLoadSpinner = UIActivityIndicatorView(style: .medium)
    private let assetsLoadLabel = UILabel()
    private let assetsLoadProgress = UIProgressView(progressViewStyle: .bar)
    private var assetsLoadPanelObserver: NSObjectProtocol?

    private var mainStackTopConstraint: NSLayoutConstraint!
    private var mainStackBottomConstraint: NSLayoutConstraint!
    private var scrollViewTopToHeaderConstraint: NSLayoutConstraint!

    private let homeMainStack = UIStackView()

    private enum HomeCategoryTileMetrics {
        /// Wider column so the mascot reads larger next to the grid.
        static let mascotColumnWidthFraction: CGFloat = 0.37
        /// Scroll viewport height = this many tile rows (3 columns fixed).
        static let categoryGridVisibleRowsRegular: CGFloat = 3.5
        static let categoryGridVisibleRowsCompact: CGFloat = 2.25
        static let rowSpacing: CGFloat = 8
        static let columnSpacing: CGFloat = 8
        static let bodyStackSpacing: CGFloat = 12
        static let cardCornerRadius: CGFloat = 10
        static let cardBorderWidth: CGFloat = 4
        static let footerHeight: CGFloat = 36
        static let footerOutset: CGFloat = 4
        static let labelFontSize: CGFloat = 15
        static let previewHorizontalInset: CGFloat = 8
        static let previewTopInset: CGFloat = 6
        static let previewBottomToFooter: CGFloat = 4
        static let lockSize: CGFloat = 26
        static let cardAspectHeightPerWidth: CGFloat = 254.0 / 329.0
        static let panelContentInset: CGFloat = 12
        /// Figma category panel (772×880 frame): inner fill radius, outer stroke ring.
        static let panelFillCornerRadius: CGFloat = 14.85
        static let panelStrokeCornerRadius: CGFloat = 22.27
        static let panelStrokeBorderWidth: CGFloat = 7.42
        static let panelStrokeOutset: CGFloat = 7.42
        static var panelStrokeSizeDelta: CGFloat { panelStrokeOutset * 2 }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .black

        heroView.heroImage = UIImage(named: "HomeHero")
        heroView.translatesAutoresizingMaskIntoConstraints = false

        headerView.translatesAutoresizingMaskIntoConstraints = false
        headerView.backgroundColor = .clear

        mascotColumn.translatesAutoresizingMaskIntoConstraints = false
        mascotColumn.clipsToBounds = false

        categoryGridPanelWrapper.translatesAutoresizingMaskIntoConstraints = false
        categoryGridPanelWrapper.backgroundColor = .clear
        categoryGridPanelWrapper.clipsToBounds = false

        categoryGridPanelStroke.translatesAutoresizingMaskIntoConstraints = false
        categoryGridPanelStroke.backgroundColor = .clear
        categoryGridPanelStroke.layer.borderWidth = HomeCategoryTileMetrics.panelStrokeBorderWidth
        categoryGridPanelStroke.layer.borderColor = UIColor(red: 0.002, green: 0.684, blue: 1, alpha: 1).cgColor
        categoryGridPanelStroke.layer.cornerRadius = HomeCategoryTileMetrics.panelStrokeCornerRadius
        categoryGridPanelStroke.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            categoryGridPanelStroke.layer.cornerCurve = .continuous
        }

        categoryGridPanel.translatesAutoresizingMaskIntoConstraints = false
        categoryGridPanel.backgroundColor = UIColor(red: 0.4, green: 0.87, blue: 1, alpha: 1)
        categoryGridPanel.layer.cornerRadius = HomeCategoryTileMetrics.panelFillCornerRadius
        categoryGridPanel.clipsToBounds = true
        if #available(iOS 13.0, *) {
            categoryGridPanel.layer.cornerCurve = .continuous
        }
        FigmaTheme.applyCardShadow(to: categoryGridPanelWrapper.layer)

        mascotView.image = UIImage(named: "BrushMascot")
        mascotView.contentMode = .scaleAspectFit
        mascotView.translatesAutoresizingMaskIntoConstraints = false

        titleLabel.numberOfLines = 2
        titleLabel.textAlignment = .center
        titleLabel.lineBreakMode = .byTruncatingTail
        titleLabel.adjustsFontSizeToFitWidth = true
        titleLabel.minimumScaleFactor = 0.72
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        titleLabel.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
        titleLabel.setContentCompressionResistancePriority(.required, for: .vertical)
        applyTitleAttributedText()

        gridStack.axis = .vertical
        gridStack.spacing = HomeCategoryTileMetrics.rowSpacing
        gridStack.translatesAutoresizingMaskIntoConstraints = false

        categoryGridScrollView.translatesAutoresizingMaskIntoConstraints = false
        categoryGridScrollView.alwaysBounceVertical = true
        categoryGridScrollView.showsVerticalScrollIndicator = true
        categoryGridScrollView.clipsToBounds = true
        categoryGridContentView.translatesAutoresizingMaskIntoConstraints = false
        categoryGridScrollView.addSubview(categoryGridContentView)
        categoryGridContentView.addSubview(gridStack)

        categoryGridPanelWrapper.addSubview(categoryGridPanelStroke)
        categoryGridPanelWrapper.addSubview(categoryGridPanel)
        categoryGridPanel.addSubview(categoryGridScrollView)

        bodyStack.axis = .horizontal
        bodyStack.alignment = .bottom
        bodyStack.spacing = HomeCategoryTileMetrics.bodyStackSpacing
        bodyStack.distribution = .fill
        bodyStack.translatesAutoresizingMaskIntoConstraints = false
        bodyStack.addArrangedSubview(mascotColumn)
        bodyStack.addArrangedSubview(categoryGridPanelWrapper)

        mascotColumn.addSubview(titleLabel)
        mascotColumn.addSubview(mascotView)

        configureUnlockButton()
        unlockButton.translatesAutoresizingMaskIntoConstraints = false
        unlockButton.addTarget(self, action: #selector(unlockTapped), for: .touchUpInside)

        musicVolumeStack.axis = .horizontal
        musicVolumeStack.alignment = .center
        musicVolumeStack.spacing = 6
        musicVolumeStack.translatesAutoresizingMaskIntoConstraints = false
        musicVolumeIcon.translatesAutoresizingMaskIntoConstraints = false
        musicVolumeIcon.tintColor = FigmaTheme.primaryOrange
        musicVolumeIcon.contentMode = .scaleAspectFit
        musicVolumeIcon.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 17, weight: .semibold)
        musicVolumeIcon.image = UIImage(systemName: "speaker.wave.2.fill")
        musicVolumeIcon.setContentHuggingPriority(.required, for: .horizontal)
        musicVolumeIcon.setContentCompressionResistancePriority(.required, for: .horizontal)

        musicVolumeSlider.translatesAutoresizingMaskIntoConstraints = false
        musicVolumeSlider.minimumValue = 0
        musicVolumeSlider.maximumValue = 1
        musicVolumeSlider.value = MagicBrushyBackgroundMusic.storedUserVolumeScale()
        musicVolumeSlider.minimumTrackTintColor = FigmaTheme.primaryOrange
        musicVolumeSlider.maximumTrackTintColor = UIColor.white.withAlphaComponent(0.28)
        musicVolumeSlider.setContentCompressionResistancePriority(.required, for: .horizontal)
        musicVolumeSlider.accessibilityLabel = "Background music"
        musicVolumeSlider.accessibilityHint = "Adjusts the quiet background tune on this screen and while coloring."
        musicVolumeSlider.addTarget(self, action: #selector(musicVolumeChanged), for: .valueChanged)

        musicVolumeStack.addArrangedSubview(musicVolumeIcon)
        musicVolumeStack.addArrangedSubview(musicVolumeSlider)
        applyMusicVolumeIconForCurrentSlider()

        headerView.addSubview(musicVolumeStack)
        headerView.addSubview(unlockButton)

        scrollView.translatesAutoresizingMaskIntoConstraints = false
        scrollView.alwaysBounceVertical = true
        scrollView.showsVerticalScrollIndicator = true
        scrollView.showsHorizontalScrollIndicator = false
        scrollView.backgroundColor = .clear
        contentView.translatesAutoresizingMaskIntoConstraints = false
        contentView.backgroundColor = .clear

        homeMainStack.axis = .vertical
        homeMainStack.spacing = 16
        homeMainStack.alignment = .fill
        homeMainStack.translatesAutoresizingMaskIntoConstraints = false
        homeMainStack.addArrangedSubview(bodyStack)
        contentView.addSubview(homeMainStack)

        NSLayoutConstraint.activate([
            mascotColumn.widthAnchor.constraint(equalTo: contentView.widthAnchor, multiplier: HomeCategoryTileMetrics.mascotColumnWidthFraction),
            mascotColumn.heightAnchor.constraint(equalTo: categoryGridPanelWrapper.heightAnchor),
        ])

        mascotView.isUserInteractionEnabled = false

        view.addSubview(heroView)
        view.addSubview(scrollView)
        scrollView.addSubview(contentView)
        view.addSubview(headerView)

        categoryGridViewportHeightConstraint = categoryGridScrollView.heightAnchor.constraint(equalToConstant: 240)

        let g = view.safeAreaLayoutGuide

        scrollViewTopToHeaderConstraint = scrollView.topAnchor.constraint(equalTo: headerView.bottomAnchor, constant: 8)
        mainStackTopConstraint = homeMainStack.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 10)
        mainStackBottomConstraint = homeMainStack.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -22)

        NSLayoutConstraint.activate([
            heroView.topAnchor.constraint(equalTo: view.topAnchor),
            heroView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            heroView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            heroView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            headerView.topAnchor.constraint(equalTo: g.topAnchor, constant: 4),
            headerView.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 18),
            headerView.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -18),

            musicVolumeStack.leadingAnchor.constraint(equalTo: categoryGridPanelWrapper.leadingAnchor),
            musicVolumeStack.centerYAnchor.constraint(equalTo: unlockButton.centerYAnchor),
            musicVolumeStack.trailingAnchor.constraint(lessThanOrEqualTo: unlockButton.leadingAnchor, constant: -12),
            musicVolumeIcon.widthAnchor.constraint(equalToConstant: 26),
            musicVolumeIcon.heightAnchor.constraint(equalToConstant: 26),
            musicVolumeSlider.widthAnchor.constraint(equalToConstant: 128),

            unlockButton.topAnchor.constraint(equalTo: headerView.topAnchor, constant: 2),
            unlockButton.trailingAnchor.constraint(equalTo: headerView.trailingAnchor),
            unlockButton.bottomAnchor.constraint(equalTo: headerView.bottomAnchor, constant: -4),
            unlockButton.leadingAnchor.constraint(greaterThanOrEqualTo: musicVolumeStack.trailingAnchor, constant: 12),
            unlockButton.heightAnchor.constraint(greaterThanOrEqualToConstant: 44),

            titleLabel.topAnchor.constraint(equalTo: mascotColumn.topAnchor, constant: 2),
            titleLabel.centerXAnchor.constraint(equalTo: mascotColumn.centerXAnchor),
            titleLabel.leadingAnchor.constraint(greaterThanOrEqualTo: mascotColumn.leadingAnchor, constant: 2),
            titleLabel.trailingAnchor.constraint(lessThanOrEqualTo: mascotColumn.trailingAnchor, constant: -2),

            mascotView.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 10),
            mascotView.leadingAnchor.constraint(equalTo: mascotColumn.leadingAnchor, constant: 2),
            mascotView.trailingAnchor.constraint(equalTo: mascotColumn.trailingAnchor, constant: -2),
            mascotView.bottomAnchor.constraint(equalTo: mascotColumn.bottomAnchor),

            scrollViewTopToHeaderConstraint,
            scrollView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            scrollView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            contentView.topAnchor.constraint(equalTo: scrollView.contentLayoutGuide.topAnchor),
            contentView.leadingAnchor.constraint(equalTo: scrollView.contentLayoutGuide.leadingAnchor),
            contentView.trailingAnchor.constraint(equalTo: scrollView.contentLayoutGuide.trailingAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.contentLayoutGuide.bottomAnchor),
            contentView.widthAnchor.constraint(equalTo: scrollView.frameLayoutGuide.widthAnchor),

            mainStackTopConstraint,
            homeMainStack.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 16),
            homeMainStack.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -16),
            mainStackBottomConstraint,

            categoryGridPanel.topAnchor.constraint(equalTo: categoryGridPanelWrapper.topAnchor),
            categoryGridPanel.leadingAnchor.constraint(equalTo: categoryGridPanelWrapper.leadingAnchor),
            categoryGridPanel.trailingAnchor.constraint(equalTo: categoryGridPanelWrapper.trailingAnchor),
            categoryGridPanel.bottomAnchor.constraint(equalTo: categoryGridPanelWrapper.bottomAnchor),

            categoryGridPanelStroke.centerXAnchor.constraint(equalTo: categoryGridPanel.centerXAnchor),
            categoryGridPanelStroke.centerYAnchor.constraint(equalTo: categoryGridPanel.centerYAnchor),
            categoryGridPanelStroke.widthAnchor.constraint(equalTo: categoryGridPanel.widthAnchor, constant: HomeCategoryTileMetrics.panelStrokeSizeDelta),
            categoryGridPanelStroke.heightAnchor.constraint(equalTo: categoryGridPanel.heightAnchor, constant: HomeCategoryTileMetrics.panelStrokeSizeDelta),

            categoryGridScrollView.topAnchor.constraint(equalTo: categoryGridPanel.topAnchor, constant: HomeCategoryTileMetrics.panelContentInset),
            categoryGridScrollView.leadingAnchor.constraint(equalTo: categoryGridPanel.leadingAnchor, constant: HomeCategoryTileMetrics.panelContentInset),
            categoryGridScrollView.trailingAnchor.constraint(equalTo: categoryGridPanel.trailingAnchor, constant: -HomeCategoryTileMetrics.panelContentInset),
            categoryGridScrollView.bottomAnchor.constraint(equalTo: categoryGridPanel.bottomAnchor, constant: -HomeCategoryTileMetrics.panelContentInset),
            categoryGridViewportHeightConstraint,

            categoryGridContentView.topAnchor.constraint(equalTo: categoryGridScrollView.contentLayoutGuide.topAnchor),
            categoryGridContentView.leadingAnchor.constraint(equalTo: categoryGridScrollView.contentLayoutGuide.leadingAnchor),
            categoryGridContentView.trailingAnchor.constraint(equalTo: categoryGridScrollView.contentLayoutGuide.trailingAnchor),
            categoryGridContentView.bottomAnchor.constraint(equalTo: categoryGridScrollView.contentLayoutGuide.bottomAnchor),
            categoryGridContentView.widthAnchor.constraint(equalTo: categoryGridScrollView.frameLayoutGuide.widthAnchor),

            gridStack.topAnchor.constraint(equalTo: categoryGridContentView.topAnchor),
            gridStack.leadingAnchor.constraint(equalTo: categoryGridContentView.leadingAnchor),
            gridStack.trailingAnchor.constraint(equalTo: categoryGridContentView.trailingAnchor),
            gridStack.bottomAnchor.constraint(equalTo: categoryGridContentView.bottomAnchor),
        ])

        subscriptionAccessObserver = NotificationCenter.default.addObserver(
            forName: .magicBrushySubscriptionAccessDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.populateCategoryGrid()
            self?.applySubscribeButtonEnabledState()
        }
        SubscriptionManager.shared.start()
        populateCategoryGrid()
        applySubscribeButtonEnabledState()
        Task { await SubscriptionManager.shared.refreshEntitlements() }
        contentView.bringSubviewToFront(mascotColumn)
        view.bringSubviewToFront(headerView)

        installAssetsLoadPanel()
    }

    deinit {
        if let assetsLoadPanelObserver {
            NotificationCenter.default.removeObserver(assetsLoadPanelObserver)
        }
        if let subscriptionAccessObserver {
            NotificationCenter.default.removeObserver(subscriptionAccessObserver)
        }
    }

    private func installAssetsLoadPanel() {
        assetsLoadChip.translatesAutoresizingMaskIntoConstraints = false
        assetsLoadChip.backgroundColor = UIColor(white: 0.1, alpha: 0.88)
        assetsLoadChip.layer.cornerRadius = 9
        if #available(iOS 13.0, *) {
            assetsLoadChip.layer.cornerCurve = .continuous
        }
        assetsLoadChip.layer.borderWidth = 1
        assetsLoadChip.layer.borderColor = UIColor.white.withAlphaComponent(0.2).cgColor
        assetsLoadChip.clipsToBounds = true
        assetsLoadChip.isHidden = true
        assetsLoadChip.alpha = 0
        assetsLoadChip.isUserInteractionEnabled = false

        assetsLoadSpinner.translatesAutoresizingMaskIntoConstraints = false
        assetsLoadSpinner.color = FigmaTheme.primaryOrange
        assetsLoadSpinner.hidesWhenStopped = true
        assetsLoadSpinner.transform = CGAffineTransform(scaleX: 0.72, y: 0.72)

        assetsLoadLabel.translatesAutoresizingMaskIntoConstraints = false
        assetsLoadLabel.textColor = .white
        assetsLoadLabel.font = FigmaTheme.bodyFont(size: 9, weight: .semibold)
        assetsLoadLabel.numberOfLines = 1
        assetsLoadLabel.textAlignment = .natural
        assetsLoadLabel.adjustsFontSizeToFitWidth = true
        assetsLoadLabel.minimumScaleFactor = 0.85

        assetsLoadProgress.translatesAutoresizingMaskIntoConstraints = false
        assetsLoadProgress.progressTintColor = FigmaTheme.primaryOrange
        assetsLoadProgress.trackTintColor = UIColor.white.withAlphaComponent(0.28)
        assetsLoadProgress.layer.cornerRadius = 2
        assetsLoadProgress.clipsToBounds = true
        assetsLoadProgress.progress = 0

        let row = UIStackView(arrangedSubviews: [assetsLoadSpinner, assetsLoadLabel])
        row.axis = .horizontal
        row.spacing = 4
        row.alignment = .center

        let stack = UIStackView(arrangedSubviews: [row, assetsLoadProgress])
        stack.axis = .vertical
        stack.spacing = 3
        stack.alignment = .fill
        stack.translatesAutoresizingMaskIntoConstraints = false

        assetsLoadChip.addSubview(stack)
        categoryGridPanel.addSubview(assetsLoadChip)

        let topInset = HomeCategoryTileMetrics.panelContentInset + 2
        NSLayoutConstraint.activate([
            assetsLoadChip.centerXAnchor.constraint(equalTo: categoryGridPanel.centerXAnchor),
            assetsLoadChip.topAnchor.constraint(equalTo: categoryGridPanel.topAnchor, constant: topInset),
            assetsLoadChip.widthAnchor.constraint(equalToConstant: 108),

            stack.topAnchor.constraint(equalTo: assetsLoadChip.topAnchor, constant: 4),
            stack.leadingAnchor.constraint(equalTo: assetsLoadChip.leadingAnchor, constant: 5),
            stack.trailingAnchor.constraint(equalTo: assetsLoadChip.trailingAnchor, constant: -5),
            stack.bottomAnchor.constraint(equalTo: assetsLoadChip.bottomAnchor, constant: -4),

            assetsLoadProgress.heightAnchor.constraint(equalToConstant: 4),
        ])

        assetsLoadPanelObserver = NotificationCenter.default.addObserver(
            forName: .leapVLMLoadPanelStateDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.refreshAssetsLoadOverlay()
        }

        categoryGridPanel.bringSubviewToFront(assetsLoadChip)
        view.bringSubviewToFront(headerView)
    }

    private func stopAssetsLoadChipAnimations() {
        assetsLoadSpinner.stopAnimating()
        assetsLoadChip.layer.removeAnimation(forKey: "assetsLoadShimmer")
    }

    private func setAssetsLoadChipProgressShimmer(_ active: Bool) {
        assetsLoadChip.layer.removeAnimation(forKey: "assetsLoadShimmer")
        guard active else { return }
        let anim = CABasicAnimation(keyPath: "opacity")
        anim.fromValue = 1.0
        anim.toValue = 0.65
        anim.duration = 0.7
        anim.autoreverses = true
        anim.repeatCount = .infinity
        anim.timingFunction = CAMediaTimingFunction(name: .easeInEaseOut)
        assetsLoadChip.layer.add(anim, forKey: "assetsLoadShimmer")
    }

    private func refreshAssetsLoadOverlay() {
        let vlm = LeapVLMModel.shared
        let show = vlm.isModelLoadPanelVisible

        if !show {
            stopAssetsLoadChipAnimations()
            UIView.animate(withDuration: 0.22, delay: 0, options: [.curveEaseIn]) {
                self.assetsLoadChip.alpha = 0
                self.assetsLoadChip.transform = CGAffineTransform(scaleX: 0.96, y: 0.96)
            } completion: { _ in
                self.assetsLoadChip.isHidden = true
                self.assetsLoadChip.transform = .identity
            }
            return
        }

        let wasHidden = assetsLoadChip.isHidden
        if wasHidden {
            assetsLoadChip.isHidden = false
            assetsLoadChip.alpha = 0
            assetsLoadChip.transform = CGAffineTransform(scaleX: 0.92, y: 0.92)
            categoryGridPanel.bringSubviewToFront(assetsLoadChip)
            UIView.animate(
                withDuration: 0.42,
                delay: 0,
                usingSpringWithDamping: 0.78,
                initialSpringVelocity: 0.55,
                options: [.allowUserInteraction]
            ) {
                self.assetsLoadChip.alpha = 1
                self.assetsLoadChip.transform = .identity
            }
        }

        assetsLoadLabel.textColor = .white

        if vlm.modelLoadDidFail {
            stopAssetsLoadChipAnimations()
            assetsLoadLabel.isHidden = false
            assetsLoadLabel.text = "Couldn't load"
            assetsLoadLabel.textColor = UIColor.systemYellow
            assetsLoadProgress.isHidden = true
            categoryGridPanel.bringSubviewToFront(assetsLoadChip)
            return
        }

        switch vlm.modelBadgeState {
        case .downloading(let p):
            let pct = Int((p * 100).rounded(.down))
            assetsLoadLabel.isHidden = false
            assetsLoadLabel.text = pct > 0 ? "Downloading \(pct)%" : "Downloading…"
            assetsLoadProgress.isHidden = false
            assetsLoadProgress.setProgress(Float(p), animated: !wasHidden)
            assetsLoadSpinner.stopAnimating()
            setAssetsLoadChipProgressShimmer(true)
        case .loadingIntoMemory:
            assetsLoadLabel.text = nil
            assetsLoadLabel.isHidden = true
            assetsLoadProgress.isHidden = true
            assetsLoadChip.layer.removeAnimation(forKey: "assetsLoadShimmer")
            assetsLoadSpinner.startAnimating()
        default:
            assetsLoadLabel.isHidden = true
            assetsLoadProgress.isHidden = true
            assetsLoadChip.layer.removeAnimation(forKey: "assetsLoadShimmer")
            assetsLoadSpinner.startAnimating()
        }
        categoryGridPanel.bringSubviewToFront(assetsLoadChip)
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        applyLayoutMetricsForCurrentTraits()
    }

    /// Three columns; `categoryGridVisibleRows*` sets how many rows (fractional = clipped row).
    private func updateCategoryGridViewportHeightIfNeeded() {
        let w = categoryGridScrollView.bounds.width
        guard w > 1 else { return }
        let col = HomeCategoryTileMetrics.columnSpacing
        let aspect = HomeCategoryTileMetrics.cardAspectHeightPerWidth
        let tileWidth = (w - 2 * col) / 3
        let rowHeight = tileWidth * aspect
        let visibleRows: CGFloat = isCompactHeight
            ? HomeCategoryTileMetrics.categoryGridVisibleRowsCompact
            : HomeCategoryTileMetrics.categoryGridVisibleRowsRegular
        let visible = visibleRows * rowHeight + (ceil(visibleRows) - 1) * HomeCategoryTileMetrics.rowSpacing
        guard abs(categoryGridViewportHeightConstraint.constant - visible) > 0.5 else { return }
        categoryGridViewportHeightConstraint.constant = visible
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        Task { @MainActor in
            await LeapVLMModel.shared.load()
        }
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        musicVolumeSlider.value = MagicBrushyBackgroundMusic.storedUserVolumeScale()
        applyMusicVolumeIconForCurrentSlider()
        refreshAssetsLoadOverlay()
        Task { await SubscriptionManager.shared.refreshEntitlements() }
        applySubscribeButtonEnabledState()
    }

    private var isCompactHeight: Bool {
        traitCollection.verticalSizeClass == .compact
    }

    private func applyLayoutMetricsForCurrentTraits() {
        let compact = isCompactHeight
        scrollViewTopToHeaderConstraint?.constant = compact ? 4 : 8
        mainStackTopConstraint?.constant = compact ? 6 : 10
        mainStackBottomConstraint?.constant = compact ? -10 : -22
        homeMainStack.spacing = compact ? 10 : 16
        bodyStack.spacing = compact ? 8 : HomeCategoryTileMetrics.bodyStackSpacing
        applyTitleAttributedText()
        updateCategoryGridViewportHeightIfNeeded()
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        guard previousTraitCollection?.verticalSizeClass != traitCollection.verticalSizeClass else { return }
        applyLayoutMetricsForCurrentTraits()
    }

    private func applyTitleAttributedText() {
        let text = "Color with\nBrushi"
        let fontSize: CGFloat = isCompactHeight ? 36 : 56
        let font = FigmaTheme.titleFont(size: fontSize)
        let paragraph = NSMutableParagraphStyle()
        paragraph.alignment = .center
        paragraph.lineBreakMode = .byTruncatingTail
        paragraph.lineSpacing = 2
        let attrs: [NSAttributedString.Key: Any] = [
            .font: font,
            .foregroundColor: FigmaTheme.creamText,
            .strokeColor: FigmaTheme.titleStroke,
            .strokeWidth: -4,
            .paragraphStyle: paragraph,
        ]
        titleLabel.attributedText = NSAttributedString(string: text, attributes: attrs)
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
        unlockButton.isEnabled = !full
        unlockButton.alpha = full ? 0.55 : 1

        var cfg = UIButton.Configuration.filled()
        cfg.title = full ? "Unlocked" : "Unlock all"
        let symbolName = full ? "lock.open.fill" : "lock.fill"
        let symCfg = UIImage.SymbolConfiguration(pointSize: 17, weight: .semibold)
        cfg.image = UIImage(systemName: symbolName, withConfiguration: symCfg)
        cfg.imagePlacement = .leading
        cfg.imagePadding = 8
        cfg.contentInsets = NSDirectionalEdgeInsets(top: 10, leading: 16, bottom: 10, trailing: 16)
        cfg.cornerStyle = .large
        cfg.baseForegroundColor = .white
        cfg.baseBackgroundColor = FigmaTheme.primaryOrange
        cfg.background.strokeColor = FigmaTheme.primaryOrangeBorder
        cfg.background.strokeWidth = 3
        cfg.titleTextAttributesTransformer = UIConfigurationTextAttributesTransformer { incoming in
            var out = incoming
            out.font = FigmaTheme.bodyFont(size: 15, weight: .bold)
            return out
        }
        unlockButton.configuration = cfg
    }

    private func makeTile(for category: Category) -> UIView {
        let container = UIView()
        container.translatesAutoresizingMaskIntoConstraints = false
        container.tag = category.rawValue

        let card = UIView()
        card.translatesAutoresizingMaskIntoConstraints = false
        card.backgroundColor = .white
        card.layer.cornerRadius = HomeCategoryTileMetrics.cardCornerRadius
        card.layer.borderWidth = HomeCategoryTileMetrics.cardBorderWidth
        card.layer.borderColor = category.accent.cgColor
        FigmaTheme.applyCardShadow(to: card.layer)

        let unlockedAll = SubscriptionManager.shared.hasFullLibraryAccess
        let preview = UIImageView(image: BuiltInColoringPages.previewImage(packId: category.packId))
        preview.contentMode = .scaleAspectFit
        preview.translatesAutoresizingMaskIntoConstraints = false

        let footer = UIView()
        footer.translatesAutoresizingMaskIntoConstraints = false
        footer.backgroundColor = category.accent

        let label = UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = category.title
        label.textColor = FigmaTheme.creamText
        label.font = FigmaTheme.bodyFont(size: HomeCategoryTileMetrics.labelFontSize, weight: .semibold)
        label.textAlignment = .center
        label.adjustsFontSizeToFitWidth = true
        label.minimumScaleFactor = 0.6

        let lockHost = UIView()
        lockHost.translatesAutoresizingMaskIntoConstraints = false
        lockHost.backgroundColor = UIColor.white.withAlphaComponent(0.55)
        lockHost.isHidden = category.isFreeTier || unlockedAll

        let lockSym = UIImage.SymbolConfiguration(pointSize: HomeCategoryTileMetrics.lockSize * 0.55, weight: .semibold)
        let lock = UIImageView(image: UIImage(systemName: "lock.fill", withConfiguration: lockSym))
        lock.tintColor = category.accent
        lock.contentMode = .scaleAspectFit
        lock.translatesAutoresizingMaskIntoConstraints = false

        container.addSubview(card)
        card.addSubview(preview)
        card.addSubview(footer)
        footer.addSubview(label)
        card.addSubview(lockHost)
        lockHost.addSubview(lock)

        let tap = UITapGestureRecognizer(target: self, action: #selector(categoryTapped(_:)))
        container.addGestureRecognizer(tap)

        NSLayoutConstraint.activate([
            card.topAnchor.constraint(equalTo: container.topAnchor),
            card.leadingAnchor.constraint(equalTo: container.leadingAnchor),
            card.trailingAnchor.constraint(equalTo: container.trailingAnchor),
            card.bottomAnchor.constraint(equalTo: container.bottomAnchor),
            card.heightAnchor.constraint(equalTo: card.widthAnchor, multiplier: HomeCategoryTileMetrics.cardAspectHeightPerWidth),

            footer.leadingAnchor.constraint(equalTo: card.leadingAnchor, constant: -HomeCategoryTileMetrics.footerOutset),
            footer.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: HomeCategoryTileMetrics.footerOutset),
            footer.bottomAnchor.constraint(equalTo: card.bottomAnchor, constant: HomeCategoryTileMetrics.footerOutset),
            footer.heightAnchor.constraint(equalToConstant: HomeCategoryTileMetrics.footerHeight),

            label.leadingAnchor.constraint(equalTo: footer.leadingAnchor, constant: 6),
            label.trailingAnchor.constraint(equalTo: footer.trailingAnchor, constant: -6),
            label.topAnchor.constraint(equalTo: footer.topAnchor, constant: 2),
            label.bottomAnchor.constraint(equalTo: footer.bottomAnchor, constant: -2),

            preview.leadingAnchor.constraint(equalTo: card.leadingAnchor, constant: HomeCategoryTileMetrics.previewHorizontalInset),
            preview.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: -HomeCategoryTileMetrics.previewHorizontalInset),
            preview.topAnchor.constraint(equalTo: card.topAnchor, constant: HomeCategoryTileMetrics.previewTopInset),
            preview.bottomAnchor.constraint(equalTo: footer.topAnchor, constant: -HomeCategoryTileMetrics.previewBottomToFooter),

            lockHost.leadingAnchor.constraint(equalTo: card.leadingAnchor),
            lockHost.trailingAnchor.constraint(equalTo: card.trailingAnchor),
            lockHost.topAnchor.constraint(equalTo: card.topAnchor),
            lockHost.bottomAnchor.constraint(equalTo: footer.topAnchor),

            lock.centerXAnchor.constraint(equalTo: lockHost.centerXAnchor),
            lock.centerYAnchor.constraint(equalTo: lockHost.centerYAnchor),
            lock.widthAnchor.constraint(equalToConstant: HomeCategoryTileMetrics.lockSize),
            lock.heightAnchor.constraint(equalToConstant: HomeCategoryTileMetrics.lockSize),
        ])

        return container
    }

    private func populateCategoryGrid() {
        gridStack.arrangedSubviews.forEach {
            gridStack.removeArrangedSubview($0)
            $0.removeFromSuperview()
        }
        let row0 = UIStackView()
        row0.axis = .horizontal
        row0.spacing = HomeCategoryTileMetrics.columnSpacing
        row0.distribution = .fillEqually
        let row1 = UIStackView()
        row1.axis = .horizontal
        row1.spacing = HomeCategoryTileMetrics.columnSpacing
        row1.distribution = .fillEqually
        let row2 = UIStackView()
        row2.axis = .horizontal
        row2.spacing = HomeCategoryTileMetrics.columnSpacing
        row2.distribution = .fillEqually
        let row3 = UIStackView()
        row3.axis = .horizontal
        row3.spacing = HomeCategoryTileMetrics.columnSpacing
        row3.distribution = .fillEqually

        row0.addArrangedSubview(makeTile(for: .freeDrawing))
        row0.addArrangedSubview(makeTile(for: .ocean))
        row0.addArrangedSubview(makeTile(for: .animals))
        row1.addArrangedSubview(makeTile(for: .dinosaurs))
        row1.addArrangedSubview(makeTile(for: .famousArt))
        row1.addArrangedSubview(makeTile(for: .fantasyAndMagic))
        row2.addArrangedSubview(makeTile(for: .food))
        row2.addArrangedSubview(makeTile(for: .naturePlants))
        row2.addArrangedSubview(makeTile(for: .sports))
        row3.addArrangedSubview(makeTile(for: .vehicles))
        row3.addArrangedSubview(makeTile(for: .winterSports))
        let row3Spacer = UIView()
        row3Spacer.backgroundColor = .clear
        row3Spacer.isUserInteractionEnabled = false
        row3.addArrangedSubview(row3Spacer)
        gridStack.addArrangedSubview(row0)
        gridStack.addArrangedSubview(row1)
        gridStack.addArrangedSubview(row2)
        gridStack.addArrangedSubview(row3)
    }

    @objc private func categoryTapped(_ gesture: UITapGestureRecognizer) {
        guard let v = gesture.view,
              let category = Category(rawValue: v.tag)
        else { return }

        let unlocked = SubscriptionManager.shared.hasFullLibraryAccess
        guard category.isFreeTier || unlocked else {
            UIImpactFeedbackGenerator(style: .medium).impactOccurred()
            let sheet = UIAlertController(
                title: "Locked",
                message: "Subscribe on the home screen to open every category, or try Free draw, Ocean, and Animals in the top row.",
                preferredStyle: .alert
            )
            sheet.addAction(UIAlertAction(title: "OK", style: .default))
            present(sheet, animated: true)
            return
        }

        let grid = CategoryGridViewController()
        grid.initialPackId = category.packId
        navigationController?.pushViewController(grid, animated: true)
    }

    private func applyMusicVolumeIconForCurrentSlider() {
        let quiet = musicVolumeSlider.value < 0.04
        let name = quiet ? "speaker.slash.fill" : "speaker.wave.2.fill"
        musicVolumeIcon.image = UIImage(systemName: name)
    }

    @objc private func musicVolumeChanged(_ sender: UISlider) {
        MagicBrushyBackgroundMusic.setUserVolumeScaleFromHome(sender.value)
        applyMusicVolumeIconForCurrentSlider()
    }

    @objc private func unlockTapped() {
        guard !SubscriptionManager.shared.hasFullLibraryAccess else { return }
        let sheet = UIAlertController(
            title: "Full library",
            message: "Subscribe with your Apple ID, restore a past purchase, or solve a quick multiplication puzzle to unlock every category. The top row (Free draw, Ocean, Animals) stays free.",
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
        sheet.addAction(UIAlertAction(title: "Unlock", style: .default, handler: { [weak self] _ in
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
            self?.populateCategoryGrid()
            self?.applySubscribeButtonEnabledState()
        }))
        present(sheet, animated: true)
    }
}
