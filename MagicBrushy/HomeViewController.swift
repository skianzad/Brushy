import UIKit

/// Figma: “Color with Drawy” home — category grid over hero illustration.
final class HomeViewController: UIViewController {

    /// Home tiles map 1:1 to `BuiltInColoringPages.library` packs via `packId`.
    private enum Category: Int, CaseIterable {
        case ocean = 0
        case magic = 1
        case animals = 2
        case food = 3
        case dinosaurs = 4
        case famousArt = 5
        case fantasy = 6
        case funStuff = 7
        case nature = 8
        case roomsScenes = 9
        case sports = 10
        case transportation = 11
        case winterSports = 12
        case naturePlants = 13

        var title: String {
            switch self {
            case .ocean: return "Ocean"
            case .magic: return "Magic"
            case .animals: return "Animals"
            case .food: return "Food"
            case .dinosaurs: return "Dinosaurs"
            case .famousArt: return "Art"
            case .fantasy: return "Fantasy"
            case .funStuff: return "Fun"
            case .nature: return "Nature"
            case .roomsScenes: return "Rooms"
            case .sports: return "Sports"
            case .transportation: return "Transit"
            case .winterSports: return "Winter"
            case .naturePlants: return "Plants"
            }
        }

        var packId: String {
            switch self {
            case .ocean: return "ocean"
            case .magic: return "magic"
            case .animals: return "animals"
            case .food: return "food"
            case .dinosaurs: return "dinosaurs"
            case .famousArt: return "famous_art"
            case .fantasy: return "fantasy"
            case .funStuff: return "fun_stuff"
            case .nature: return "nature"
            case .roomsScenes: return "rooms_scenes"
            case .sports: return "sports"
            case .transportation: return "transportation"
            case .winterSports: return "winter_sports"
            case .naturePlants: return "nature_plants"
            }
        }

        var accent: UIColor {
            switch self {
            case .animals: return FigmaTheme.animalsAccent
            case .ocean: return FigmaTheme.oceanAccent
            case .food: return FigmaTheme.foodAccent
            case .magic: return FigmaTheme.magicAccent
            case .dinosaurs: return FigmaTheme.dinosaursAccent
            case .famousArt: return FigmaTheme.famousArtAccent
            case .fantasy: return FigmaTheme.fantasyAccent
            case .funStuff: return FigmaTheme.funStuffAccent
            case .nature: return FigmaTheme.natureAccent
            case .roomsScenes: return FigmaTheme.roomsScenesAccent
            case .sports: return FigmaTheme.sportsAccent
            case .transportation: return FigmaTheme.transportationAccent
            case .winterSports: return FigmaTheme.winterSportsAccent
            case .naturePlants: return FigmaTheme.natureAccent
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
    private let gridStack = UIStackView()
    private let unlockButton = UIButton(type: .custom)
    /// Horizontal space between mascot and category grid; a flexible spacer grows here so the grid stays compact on the right.
    private let mascotToGridSpacer = UIView()

    /// Category tiles are intentionally smaller than “fill remaining width” so the hero art stays visible.
    private enum HomeCategoryTileMetrics {
        static let gridWidthFraction: CGFloat = 0.44
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

        populateCategoryGrid()

        mascotToGridSpacer.translatesAutoresizingMaskIntoConstraints = false
        mascotToGridSpacer.setContentHuggingPriority(.defaultLow, for: .horizontal)
        mascotToGridSpacer.setContentCompressionResistancePriority(.defaultLow, for: .horizontal)

        bodyStack.axis = .horizontal
        bodyStack.alignment = .center
        bodyStack.spacing = HomeCategoryTileMetrics.bodyStackSpacing
        bodyStack.translatesAutoresizingMaskIntoConstraints = false
        bodyStack.addArrangedSubview(mascotView)
        bodyStack.addArrangedSubview(mascotToGridSpacer)
        bodyStack.addArrangedSubview(gridStack)

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
        contentView.addSubview(bodyStack)
        view.addSubview(unlockButton)

        let g = view.safeAreaLayoutGuide
        NSLayoutConstraint.activate([
            // Hero fills the entire screen as a fixed background
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
            contentView.topAnchor.constraint(equalTo: scrollView.contentLayoutGuide.topAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.contentLayoutGuide.bottomAnchor),

            titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 24),
            titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -24),
            titleLabel.topAnchor.constraint(equalTo: g.topAnchor, constant: 12),

            bodyStack.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 10),
            bodyStack.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 20),
            bodyStack.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -20),
            bodyStack.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -24),

            // Mascot: 22% of view width, correct 499:656 aspect ratio
            mascotView.widthAnchor.constraint(equalTo: contentView.widthAnchor, multiplier: 0.22),
            mascotView.heightAnchor.constraint(equalTo: mascotView.widthAnchor, multiplier: 656.0 / 499.0),

            gridStack.widthAnchor.constraint(equalTo: contentView.widthAnchor, multiplier: HomeCategoryTileMetrics.gridWidthFraction),

            unlockButton.widthAnchor.constraint(equalToConstant: 56),
            unlockButton.heightAnchor.constraint(equalToConstant: 56),
            unlockButton.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -20),
            unlockButton.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),
        ])
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        Task { @MainActor in
            await LeapVLMModel.shared.load()
        }
    }

    private func applyTitleAttributedText() {
        let text = "Color with\nDrawy"
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
        let row4 = UIStackView()
        row4.axis = .horizontal
        row4.spacing = HomeCategoryTileMetrics.columnSpacing
        row4.distribution = .fillEqually

        row0.addArrangedSubview(makeTile(for: .ocean))
        row0.addArrangedSubview(makeTile(for: .magic))
        row0.addArrangedSubview(makeTile(for: .animals))
        row1.addArrangedSubview(makeTile(for: .food))
        row1.addArrangedSubview(makeTile(for: .dinosaurs))
        row1.addArrangedSubview(makeTile(for: .famousArt))
        row2.addArrangedSubview(makeTile(for: .fantasy))
        row2.addArrangedSubview(makeTile(for: .funStuff))
        row2.addArrangedSubview(makeTile(for: .nature))
        row3.addArrangedSubview(makeTile(for: .roomsScenes))
        row3.addArrangedSubview(makeTile(for: .sports))
        row3.addArrangedSubview(makeTile(for: .transportation))
        row4.addArrangedSubview(makeTile(for: .winterSports))
        row4.addArrangedSubview(makeTile(for: .naturePlants))
        row4.addArrangedSubview(UIView())
        gridStack.addArrangedSubview(row0)
        gridStack.addArrangedSubview(row1)
        gridStack.addArrangedSubview(row2)
        gridStack.addArrangedSubview(row3)
        gridStack.addArrangedSubview(row4)
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
        }))
        present(sheet, animated: true)
    }
}
