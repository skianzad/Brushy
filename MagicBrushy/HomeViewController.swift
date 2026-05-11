import UIKit
import Photos

/// Figma-inspired home — category grid over hero illustration (“Color with Brushi”).
final class HomeViewController: UIViewController {

    /// Home tiles map 1:1 to `BuiltInColoringPages.library` packs via `packId`.
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

        var title: String {
            switch self {
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

        var isFree: Bool {
            self == .animals
        }
    }

    private static let unlockDefaultsKey = "MagicBrushyUnlockAllCategories"

    private let scrollView = UIScrollView()
    private let contentView = UIView()
    private let heroView = UIImageView()
    private let mascotView = UIImageView()
    private let titleLabel = UILabel()
    private let bodyStack = UIStackView()
    /// Vertical list of category rows; lives inside `categoryGridScrollView` so only two rows show at once.
    private let gridStack = UIStackView()
    private let categoryGridScrollView = UIScrollView()
    private let categoryGridContentView = UIView()
    private var categoryGridViewportHeightConstraint: NSLayoutConstraint!
    private let unlockButton = UIButton(type: .custom)
    /// Compact top-trailing chip while Leap assets download / load (non-blocking; short copy only while downloading).
    private let assetsLoadChip = UIView()
    private let assetsLoadSpinner = UIActivityIndicatorView(style: .medium)
    private let assetsLoadLabel = UILabel()
    private let assetsLoadProgress = UIProgressView(progressViewStyle: .bar)
    private var assetsLoadPanelObserver: NSObjectProtocol?
    /// Bottom-left (scroll content); sits above the saved strip when it is visible.
    private var mascotBottomToContentConstraint: NSLayoutConstraint!
    private var mascotBottomAboveSavedStripConstraint: NSLayoutConstraint!

    /// Title + category row + saved-drawing strip (bottom).
    private let homeMainStack = UIStackView()
    private let lastDrawingCard = UIView()
    private let savedDrawingsSectionTitle = UILabel()
    private let savedDrawingsScrollView = UIScrollView()
    private let savedDrawingsStack = UIStackView()
    /// Mirrors `savedDrawingsStack` order for tap / menu handlers.
    private var displayedSavedRecords: [LastDrawingStore.SavedDrawingRecord] = []

    /// Category tiles are intentionally smaller than “fill remaining width” so the hero art stays visible.
    private enum HomeCategoryTileMetrics {
        /// Wider grid so more tiles sit left of center (still leaves room for mascot + hero).
        static let gridWidthFraction: CGFloat = 0.62
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
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .black

        // Hero is a fixed full-screen background, not inside the scroll view,
        // so the nature scene is always visible regardless of content height.
        heroView.image = UIImage(named: "HomeHero")
        heroView.contentMode = .scaleAspectFill
        heroView.clipsToBounds = true
        heroView.translatesAutoresizingMaskIntoConstraints = false

        mascotView.image = UIImage(named: "BrushMascot")
        mascotView.contentMode = .scaleAspectFit
        mascotView.translatesAutoresizingMaskIntoConstraints = false

        titleLabel.numberOfLines = 2
        titleLabel.textAlignment = .center
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
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

        bodyStack.axis = .horizontal
        bodyStack.alignment = .center
        bodyStack.spacing = HomeCategoryTileMetrics.bodyStackSpacing
        bodyStack.translatesAutoresizingMaskIntoConstraints = false
        bodyStack.addArrangedSubview(categoryGridScrollView)

        styleUnlockButton()
        unlockButton.translatesAutoresizingMaskIntoConstraints = false
        unlockButton.addTarget(self, action: #selector(unlockTapped), for: .touchUpInside)

        scrollView.translatesAutoresizingMaskIntoConstraints = false
        scrollView.alwaysBounceVertical = true
        scrollView.showsVerticalScrollIndicator = true
        scrollView.showsHorizontalScrollIndicator = false
        scrollView.backgroundColor = .clear
        contentView.translatesAutoresizingMaskIntoConstraints = false
        contentView.backgroundColor = .clear

        // Layer order: hero → scrollView → unlockButton
        view.addSubview(heroView)
        view.addSubview(scrollView)
        scrollView.addSubview(contentView)
        contentView.addSubview(titleLabel)
        installLastDrawingStrip()
        homeMainStack.axis = .vertical
        homeMainStack.spacing = 16
        homeMainStack.alignment = .fill
        homeMainStack.translatesAutoresizingMaskIntoConstraints = false
        homeMainStack.addArrangedSubview(bodyStack)
        homeMainStack.addArrangedSubview(lastDrawingCard)
        contentView.addSubview(homeMainStack)
        mascotView.isUserInteractionEnabled = false
        contentView.addSubview(mascotView)
        view.addSubview(unlockButton)

        categoryGridViewportHeightConstraint = categoryGridScrollView.heightAnchor.constraint(equalToConstant: 240)

        let g = view.safeAreaLayoutGuide

        NSLayoutConstraint.activate([
            heroView.topAnchor.constraint(equalTo: view.topAnchor),
            heroView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            heroView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            heroView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            scrollView.topAnchor.constraint(equalTo: view.topAnchor),
            scrollView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            scrollView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            contentView.topAnchor.constraint(equalTo: scrollView.contentLayoutGuide.topAnchor),
            contentView.leadingAnchor.constraint(equalTo: scrollView.contentLayoutGuide.leadingAnchor),
            contentView.trailingAnchor.constraint(equalTo: scrollView.contentLayoutGuide.trailingAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.contentLayoutGuide.bottomAnchor),
            contentView.widthAnchor.constraint(equalTo: scrollView.frameLayoutGuide.widthAnchor),

            titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 24),
            titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -24),
            titleLabel.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 12),

            homeMainStack.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 10),
            homeMainStack.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 20),
            homeMainStack.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -20),
            homeMainStack.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -22),

            categoryGridScrollView.widthAnchor.constraint(equalTo: contentView.widthAnchor, multiplier: HomeCategoryTileMetrics.gridWidthFraction),
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

            unlockButton.widthAnchor.constraint(equalToConstant: 56),
            unlockButton.heightAnchor.constraint(equalToConstant: 56),
            unlockButton.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -20),
            unlockButton.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),

            mascotView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 16),
            mascotView.widthAnchor.constraint(equalTo: contentView.widthAnchor, multiplier: 0.2),
            mascotView.heightAnchor.constraint(equalTo: mascotView.widthAnchor, multiplier: 656.0 / 499.0),
        ])

        mascotBottomToContentConstraint = mascotView.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -22)
        mascotBottomAboveSavedStripConstraint = mascotView.bottomAnchor.constraint(equalTo: lastDrawingCard.topAnchor)
        mascotBottomToContentConstraint.isActive = true
        mascotBottomAboveSavedStripConstraint.isActive = false

        populateCategoryGrid()
        applyMascotVerticalForSavedStripVisibility()
        contentView.bringSubviewToFront(mascotView)

        installAssetsLoadPanel()
    }

    deinit {
        if let assetsLoadPanelObserver {
            NotificationCenter.default.removeObserver(assetsLoadPanelObserver)
        }
    }

    private func installAssetsLoadPanel() {
        let g = view.safeAreaLayoutGuide

        assetsLoadChip.translatesAutoresizingMaskIntoConstraints = false
        assetsLoadChip.backgroundColor = UIColor(white: 0.1, alpha: 0.88)
        assetsLoadChip.layer.cornerRadius = 14
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

        assetsLoadLabel.translatesAutoresizingMaskIntoConstraints = false
        assetsLoadLabel.textColor = .white
        assetsLoadLabel.font = FigmaTheme.bodyFont(size: 12, weight: .semibold)
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
        row.spacing = 8
        row.alignment = .center

        let stack = UIStackView(arrangedSubviews: [row, assetsLoadProgress])
        stack.axis = .vertical
        stack.spacing = 8
        stack.alignment = .fill
        stack.translatesAutoresizingMaskIntoConstraints = false

        assetsLoadChip.addSubview(stack)
        view.addSubview(assetsLoadChip)

        NSLayoutConstraint.activate([
            assetsLoadChip.topAnchor.constraint(equalTo: unlockButton.bottomAnchor, constant: 10),
            assetsLoadChip.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -20),
            assetsLoadChip.widthAnchor.constraint(lessThanOrEqualToConstant: 158),

            stack.topAnchor.constraint(equalTo: assetsLoadChip.topAnchor, constant: 10),
            stack.leadingAnchor.constraint(equalTo: assetsLoadChip.leadingAnchor, constant: 12),
            stack.trailingAnchor.constraint(equalTo: assetsLoadChip.trailingAnchor, constant: -12),
            stack.bottomAnchor.constraint(equalTo: assetsLoadChip.bottomAnchor, constant: -10),

            assetsLoadProgress.heightAnchor.constraint(equalToConstant: 4),
        ])

        assetsLoadPanelObserver = NotificationCenter.default.addObserver(
            forName: .leapVLMLoadPanelStateDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.refreshAssetsLoadOverlay()
        }

        view.bringSubviewToFront(assetsLoadChip)
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
                self.assetsLoadChip.transform = CGAffineTransform(translationX: 0, y: -6).scaledBy(x: 0.96, y: 0.96)
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
            assetsLoadChip.transform = CGAffineTransform(translationX: 0, y: -10).scaledBy(x: 0.92, y: 0.92)
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
    }

    private func applyMascotVerticalForSavedStripVisibility() {
        let showSaved = !lastDrawingCard.isHidden
        if showSaved {
            mascotBottomToContentConstraint.isActive = false
            mascotBottomAboveSavedStripConstraint.isActive = true
        } else {
            mascotBottomAboveSavedStripConstraint.isActive = false
            mascotBottomToContentConstraint.isActive = true
        }
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        updateCategoryGridViewportHeightIfNeeded()
    }

    /// Keeps the category area to exactly two tile rows (6 categories); remaining rows scroll inside `categoryGridScrollView`.
    private func updateCategoryGridViewportHeightIfNeeded() {
        let w = categoryGridScrollView.bounds.width
        guard w > 1 else { return }
        let col = HomeCategoryTileMetrics.columnSpacing
        let aspect = HomeCategoryTileMetrics.cardAspectHeightPerWidth
        let tileWidth = (w - 2 * col) / 3
        let rowHeight = tileWidth * aspect
        let visible = 2 * rowHeight + HomeCategoryTileMetrics.rowSpacing
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
        refreshLastDrawingStrip()
        refreshAssetsLoadOverlay()
    }

    private func installLastDrawingStrip() {
        lastDrawingCard.translatesAutoresizingMaskIntoConstraints = false
        lastDrawingCard.isHidden = true
        lastDrawingCard.layer.cornerRadius = 20
        lastDrawingCard.layer.borderWidth = 1.5
        lastDrawingCard.layer.borderColor = UIColor.white.withAlphaComponent(0.65).cgColor
        lastDrawingCard.backgroundColor = UIColor(red: 1, green: 252 / 255, blue: 248 / 255, alpha: 0.96)
        lastDrawingCard.layer.shadowColor = UIColor.black.cgColor
        lastDrawingCard.layer.shadowOpacity = 0.12
        lastDrawingCard.layer.shadowRadius = 10
        lastDrawingCard.layer.shadowOffset = CGSize(width: 0, height: 4)

        savedDrawingsSectionTitle.translatesAutoresizingMaskIntoConstraints = false
        savedDrawingsSectionTitle.text = "Your drawings"
        savedDrawingsSectionTitle.font = FigmaTheme.bodyFont(size: 14, weight: .bold)
        savedDrawingsSectionTitle.textColor = FigmaTheme.titleStroke.withAlphaComponent(0.88)

        savedDrawingsScrollView.translatesAutoresizingMaskIntoConstraints = false
        savedDrawingsScrollView.showsHorizontalScrollIndicator = true
        savedDrawingsScrollView.alwaysBounceHorizontal = true
        savedDrawingsScrollView.clipsToBounds = true

        savedDrawingsStack.axis = .horizontal
        savedDrawingsStack.spacing = 12
        savedDrawingsStack.alignment = .top
        savedDrawingsStack.translatesAutoresizingMaskIntoConstraints = false

        savedDrawingsScrollView.addSubview(savedDrawingsStack)

        let column = UIStackView(arrangedSubviews: [savedDrawingsSectionTitle, savedDrawingsScrollView])
        column.axis = .vertical
        column.spacing = 10
        column.alignment = .fill
        column.translatesAutoresizingMaskIntoConstraints = false

        lastDrawingCard.addSubview(column)
        NSLayoutConstraint.activate([
            column.topAnchor.constraint(equalTo: lastDrawingCard.topAnchor, constant: 12),
            column.leadingAnchor.constraint(equalTo: lastDrawingCard.leadingAnchor, constant: 14),
            column.trailingAnchor.constraint(equalTo: lastDrawingCard.trailingAnchor, constant: -14),
            column.bottomAnchor.constraint(equalTo: lastDrawingCard.bottomAnchor, constant: -12),

            savedDrawingsStack.topAnchor.constraint(equalTo: savedDrawingsScrollView.contentLayoutGuide.topAnchor),
            savedDrawingsStack.leadingAnchor.constraint(equalTo: savedDrawingsScrollView.contentLayoutGuide.leadingAnchor),
            savedDrawingsStack.bottomAnchor.constraint(equalTo: savedDrawingsScrollView.contentLayoutGuide.bottomAnchor),
            savedDrawingsStack.trailingAnchor.constraint(equalTo: savedDrawingsScrollView.contentLayoutGuide.trailingAnchor),
            savedDrawingsStack.heightAnchor.constraint(equalTo: savedDrawingsScrollView.frameLayoutGuide.heightAnchor),

            savedDrawingsScrollView.heightAnchor.constraint(equalToConstant: 152),
        ])
    }

    private func refreshLastDrawingStrip() {
        savedDrawingsStack.arrangedSubviews.forEach {
            savedDrawingsStack.removeArrangedSubview($0)
            $0.removeFromSuperview()
        }
        displayedSavedRecords = LastDrawingStore.allRecordsNewestFirst()
        guard !displayedSavedRecords.isEmpty else {
            lastDrawingCard.isHidden = true
            applyMascotVerticalForSavedStripVisibility()
            contentView.bringSubviewToFront(mascotView)
            return
        }
        lastDrawingCard.isHidden = false
        for (index, rec) in displayedSavedRecords.enumerated() {
            savedDrawingsStack.addArrangedSubview(makeSavedDrawingMiniCard(record: rec, index: index))
        }
        applyMascotVerticalForSavedStripVisibility()
        contentView.bringSubviewToFront(mascotView)
    }

    private func makeSavedDrawingMiniCard(record: LastDrawingStore.SavedDrawingRecord, index: Int) -> UIView {
        let card = UIView()
        card.translatesAutoresizingMaskIntoConstraints = false
        card.tag = index
        card.backgroundColor = UIColor.white.withAlphaComponent(0.58)
        card.layer.cornerRadius = 14
        card.layer.borderWidth = 2
        card.layer.borderColor = FigmaTheme.primaryOrange.withAlphaComponent(0.55).cgColor
        card.widthAnchor.constraint(equalToConstant: 114).isActive = true

        let thumb = UIImageView(image: LastDrawingStore.loadThumbnail(id: record.id))
        thumb.translatesAutoresizingMaskIntoConstraints = false
        thumb.contentMode = .scaleAspectFit
        thumb.clipsToBounds = true
        thumb.layer.cornerRadius = 10
        thumb.backgroundColor = UIColor(white: 0.93, alpha: 1)

        let title = UILabel()
        title.translatesAutoresizingMaskIntoConstraints = false
        title.text = record.pageTitle
        title.font = FigmaTheme.bodyFont(size: 11, weight: .semibold)
        title.textColor = UIColor(red: 12 / 255, green: 58 / 255, blue: 118 / 255, alpha: 1)
        title.numberOfLines = 2
        title.lineBreakMode = .byTruncatingTail
        title.textAlignment = .center

        var menuCfg = UIButton.Configuration.plain()
        menuCfg.image = UIImage(systemName: "ellipsis.circle.fill")
        menuCfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 22, weight: .semibold)
        menuCfg.baseForegroundColor = FigmaTheme.actionBlue
        let menuBtn = UIButton(type: .system)
        menuBtn.configuration = menuCfg
        menuBtn.tag = index
        menuBtn.accessibilityLabel = "Options for this drawing"
        menuBtn.translatesAutoresizingMaskIntoConstraints = false
        menuBtn.addTarget(self, action: #selector(savedDrawingMenuTapped(_:)), for: .touchUpInside)

        let tap = UITapGestureRecognizer(target: self, action: #selector(savedDrawingContinueTapped(_:)))
        card.addGestureRecognizer(tap)

        card.addSubview(thumb)
        card.addSubview(title)
        card.addSubview(menuBtn)

        NSLayoutConstraint.activate([
            thumb.topAnchor.constraint(equalTo: card.topAnchor, constant: 8),
            thumb.leadingAnchor.constraint(equalTo: card.leadingAnchor, constant: 8),
            thumb.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: -8),
            thumb.heightAnchor.constraint(equalToConstant: 78),

            menuBtn.topAnchor.constraint(equalTo: card.topAnchor, constant: 2),
            menuBtn.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: -2),
            menuBtn.widthAnchor.constraint(equalToConstant: 34),
            menuBtn.heightAnchor.constraint(equalToConstant: 34),

            title.topAnchor.constraint(equalTo: thumb.bottomAnchor, constant: 6),
            title.leadingAnchor.constraint(equalTo: card.leadingAnchor, constant: 4),
            title.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: -4),
            title.bottomAnchor.constraint(lessThanOrEqualTo: card.bottomAnchor, constant: -6),
        ])
        card.bringSubviewToFront(menuBtn)
        return card
    }

    @objc private func savedDrawingContinueTapped(_ gesture: UITapGestureRecognizer) {
        guard let v = gesture.view else { return }
        openSavedDrawing(at: v.tag)
    }

    @objc private func savedDrawingMenuTapped(_ sender: UIButton) {
        let index = sender.tag
        guard displayedSavedRecords.indices.contains(index) else { return }
        let rec = displayedSavedRecords[index]
        let sheet = UIAlertController(title: rec.pageTitle, message: nil, preferredStyle: .actionSheet)
        sheet.addAction(UIAlertAction(title: "Save to Photos", style: .default, handler: { [weak self] _ in
            self?.exportSavedDrawingToPhotos(record: rec)
        }))
        sheet.addAction(UIAlertAction(title: "Delete this drawing", style: .destructive, handler: { [weak self] _ in
            LastDrawingStore.deleteRecord(id: rec.id)
            UIImpactFeedbackGenerator(style: .light).impactOccurred()
            self?.refreshLastDrawingStrip()
        }))
        sheet.addAction(UIAlertAction(title: "Delete all drawings", style: .destructive, handler: { [weak self] _ in
            self?.confirmDeleteAllSavedDrawings()
        }))
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        if let pop = sheet.popoverPresentationController {
            pop.sourceView = sender
            pop.sourceRect = sender.bounds
        }
        present(sheet, animated: true)
    }

    private func confirmDeleteAllSavedDrawings() {
        let confirm = UIAlertController(
            title: "Delete all drawings?",
            message: "This removes every saved picture from this device. You can’t undo it.",
            preferredStyle: .alert
        )
        confirm.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        confirm.addAction(UIAlertAction(title: "Delete all", style: .destructive, handler: { [weak self] _ in
            LastDrawingStore.clearAll()
            UIImpactFeedbackGenerator(style: .medium).impactOccurred()
            self?.refreshLastDrawingStrip()
        }))
        present(confirm, animated: true)
    }

    private func openSavedDrawing(at index: Int) {
        guard displayedSavedRecords.indices.contains(index) else { return }
        let rec = displayedSavedRecords[index]
        guard let pack = BuiltInColoringPages.library.first(where: { $0.id == rec.packId }) else { return }
        let unlocked = UserDefaults.standard.bool(forKey: Self.unlockDefaultsKey)
        let packUnlocked = pack.id == "animals" || unlocked
        guard packUnlocked else {
            UIImpactFeedbackGenerator(style: .medium).impactOccurred()
            let sheet = UIAlertController(
                title: "Locked",
                message: "Unlock categories with the key to open this picture again.",
                preferredStyle: .alert
            )
            sheet.addAction(UIAlertAction(title: "OK", style: .default))
            present(sheet, animated: true)
            return
        }
        UIImpactFeedbackGenerator(style: .light).impactOccurred()
        let canvas = ColoringViewController()
        canvas.coloringBookPages = pack.pages
        let safeIndex = min(max(0, rec.pageIndex), max(0, pack.pages.count - 1))
        canvas.pinnedPageIndex = safeIndex
        canvas.sessionPackId = rec.packId
        canvas.continuingSavedDrawingId = rec.id
        LastDrawingStore.registerContinueDrawingSession(id: rec.id)
        if let underlay = LastDrawingStore.loadResumeUnderlay(id: rec.id) {
            canvas.pendingResumeComposite = underlay
            canvas.pendingResumeHasSeparateLineOverlay = true
        } else if let flat = LastDrawingStore.loadComposite(id: rec.id) {
            canvas.pendingResumeComposite = flat
            canvas.pendingResumeHasSeparateLineOverlay = false
        }
        navigationController?.pushViewController(canvas, animated: true)
    }

    private func exportSavedDrawingToPhotos(record: LastDrawingStore.SavedDrawingRecord) {
        guard let image = LastDrawingStore.loadComposite(id: record.id) else { return }
        let title = record.pageTitle
        let status = PHPhotoLibrary.authorizationStatus(for: .addOnly)
        switch status {
        case .authorized, .limited:
            saveImageToPhotoLibrary(image, title: title)
        case .notDetermined:
            PHPhotoLibrary.requestAuthorization(for: .addOnly) { [weak self] newStatus in
                DispatchQueue.main.async {
                    guard let self else { return }
                    if newStatus == .authorized || newStatus == .limited {
                        self.saveImageToPhotoLibrary(image, title: title)
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
                    let ok = UIAlertController(
                        title: "Saved",
                        message: "“\(title)” was added to your Photos library.",
                        preferredStyle: .alert
                    )
                    ok.addAction(UIAlertAction(title: "OK", style: .default))
                    self.present(ok, animated: true)
                } else {
                    let msg = error?.localizedDescription ?? "Could not save."
                    let err = UIAlertController(title: "Couldn’t save", message: msg, preferredStyle: .alert)
                    err.addAction(UIAlertAction(title: "OK", style: .default))
                    self.present(err, animated: true)
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

    private func applyTitleAttributedText() {
        let text = "Color with\nBrushi"
        let font = FigmaTheme.titleFont(size: 44)
        let paragraph = NSMutableParagraphStyle()
        paragraph.alignment = .center
        paragraph.lineSpacing = 2
        let attrs: [NSAttributedString.Key: Any] = [
            .font: font,
            .foregroundColor: FigmaTheme.creamText,
            .strokeColor: FigmaTheme.titleStroke,
            .strokeWidth: -4,
            .paragraphStyle: paragraph,
        ]
        titleLabel.attributedText =
        NSAttributedString(string: text, attributes: attrs)
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

        let unlockedAll = UserDefaults.standard.bool(forKey: Self.unlockDefaultsKey)
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
        lockHost.isHidden = category.isFree || unlockedAll

        let lock = UIImageView(image: UIImage(systemName: "lock.fill"))
        lock.tintColor = UIColor.label.withAlphaComponent(0.35)
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

        row0.addArrangedSubview(makeTile(for: .ocean))
        row0.addArrangedSubview(makeTile(for: .animals))
        row0.addArrangedSubview(makeTile(for: .dinosaurs))
        row1.addArrangedSubview(makeTile(for: .famousArt))
        row1.addArrangedSubview(makeTile(for: .fantasyAndMagic))
        row1.addArrangedSubview(makeTile(for: .food))
        row2.addArrangedSubview(makeTile(for: .naturePlants))
        row2.addArrangedSubview(makeTile(for: .sports))
        row2.addArrangedSubview(makeTile(for: .vehicles))
        let row3LeftPad = UIView()
        row3LeftPad.backgroundColor = .clear
        let row3RightPad = UIView()
        row3RightPad.backgroundColor = .clear
        row3.addArrangedSubview(row3LeftPad)
        row3.addArrangedSubview(makeTile(for: .winterSports))
        row3.addArrangedSubview(row3RightPad)
        gridStack.addArrangedSubview(row0)
        gridStack.addArrangedSubview(row1)
        gridStack.addArrangedSubview(row2)
        gridStack.addArrangedSubview(row3)
        refreshLastDrawingStrip()
    }

    @objc private func categoryTapped(_ gesture: UITapGestureRecognizer) {
        guard let v = gesture.view,
              let category = Category(rawValue: v.tag)
        else { return }

        let unlocked = UserDefaults.standard.bool(forKey: Self.unlockDefaultsKey)
        guard category.isFree || unlocked else {
            UIImpactFeedbackGenerator(style: .medium).impactOccurred()
            let sheet = UIAlertController(
                title: "Locked",
                message: "This pack is still locked. Tap the key button and unlock everything to try it early.",
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

    private func styleUnlockButton() {
        unlockButton.backgroundColor = FigmaTheme.primaryOrange
        unlockButton.layer.borderColor = FigmaTheme.primaryOrangeBorder.cgColor
        unlockButton.layer.borderWidth = 5
        unlockButton.layer.cornerRadius = 14
        unlockButton.layer.shadowColor = UIColor.black.cgColor
        unlockButton.layer.shadowOpacity = 0.25
        unlockButton.layer.shadowRadius = 8
        unlockButton.layer.shadowOffset = CGSize(width: 0, height: 4)

        let icon = UIImage(systemName: "key.fill")
        unlockButton.setImage(icon, for: .normal)
        unlockButton.tintColor = .white
        unlockButton.imageView?.contentMode = .scaleAspectFit
        unlockButton.contentEdgeInsets = UIEdgeInsets(top: 12, left: 12, bottom: 12, right: 12)
    }

    @objc private func unlockTapped() {
        let sheet = UIAlertController(title: "Unlock", message: "Enter 3 × 7 to unlock every category.", preferredStyle: .alert)
        sheet.addTextField { $0.keyboardType = .numberPad }
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        sheet.addAction(UIAlertAction(title: "Unlock", style: .default, handler: { [weak self] _ in
            guard let t = sheet.textFields?.first?.text?.trimmingCharacters(in: .whitespacesAndNewlines),
                  t == "21"
            else {
                UIImpactFeedbackGenerator(style: .rigid).impactOccurred()
                return
            }
            UserDefaults.standard.set(true, forKey: Self.unlockDefaultsKey)
            UIImpactFeedbackGenerator(style: .light).impactOccurred()
            self?.populateCategoryGrid()
            self?.refreshLastDrawingStrip()
        }))
        present(sheet, animated: true)
    }
}
