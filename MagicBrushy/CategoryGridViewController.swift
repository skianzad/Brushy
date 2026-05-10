import UIKit

/// Browse shelves: horizontal category chips + a grid of outlines (home-style hero + orange accents).
final class CategoryGridViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {

    /// Set before the controller loads (e.g. from the home tile) to open on a specific shelf.
    var initialPackId: String?

    private var selectedPackIndex = 0 {
        didSet { refreshPackChrome() }
    }

    private let backgroundImageView = UIImageView()
    private let blurEffectView = UIVisualEffectView(effect: UIBlurEffect(style: .systemThinMaterialLight))

    private lazy var collectionView: UICollectionView = {
        let layout = UICollectionViewFlowLayout()
        layout.minimumInteritemSpacing = 14
        layout.minimumLineSpacing = 18
        layout.sectionInset = UIEdgeInsets(top: 10, left: 20, bottom: 28, right: 20)
        let cv = UICollectionView(frame: .zero, collectionViewLayout: layout)
        cv.backgroundColor = .clear
        cv.alwaysBounceVertical = true
        cv.dataSource = self
        cv.delegate = self
        cv.register(Cell.self, forCellWithReuseIdentifier: Cell.reuseId)
        cv.translatesAutoresizingMaskIntoConstraints = false
        return cv
    }()

    private let titleLabel = UILabel()
    private let backButton = UIButton(type: .custom)
    private let categoryScroll = UIScrollView()
    private let categoryStack = UIStackView()
    private var categoryButtons: [UIButton] = []

    private var currentPages: [BuiltInColoringPages.Page] {
        guard selectedPackIndex >= 0, selectedPackIndex < BuiltInColoringPages.library.count else {
            return []
        }
        return BuiltInColoringPages.library[selectedPackIndex].pages
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        if let id = initialPackId,
           let idx = BuiltInColoringPages.library.firstIndex(where: { $0.id == id }) {
            selectedPackIndex = idx
        }
        view.backgroundColor = .black

        navigationController?.setNavigationBarHidden(true, animated: false)

        backgroundImageView.image = UIImage(named: "HomeHero")
        backgroundImageView.contentMode = .scaleAspectFill
        backgroundImageView.clipsToBounds = true
        backgroundImageView.translatesAutoresizingMaskIntoConstraints = false

        blurEffectView.translatesAutoresizingMaskIntoConstraints = false
        blurEffectView.isUserInteractionEnabled = false

        titleLabel.textAlignment = .center
        titleLabel.numberOfLines = 2
        titleLabel.lineBreakMode = .byTruncatingTail
        titleLabel.adjustsFontSizeToFitWidth = true
        titleLabel.minimumScaleFactor = 0.55
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        applyCategoryTitleAttributes()

        backButton.translatesAutoresizingMaskIntoConstraints = false
        backButton.backgroundColor = FigmaTheme.primaryOrange
        backButton.layer.cornerRadius = 12
        backButton.layer.borderWidth = 3
        backButton.layer.borderColor = FigmaTheme.primaryOrangeBorder.cgColor
        backButton.tintColor = .white
        let chevron = UIImage(systemName: "chevron.left", withConfiguration: UIImage.SymbolConfiguration(pointSize: 18, weight: .bold))
        backButton.setImage(chevron, for: .normal)
        backButton.contentEdgeInsets = UIEdgeInsets(top: 10, left: 12, bottom: 10, right: 12)
        backButton.accessibilityLabel = "Back"
        backButton.addTarget(self, action: #selector(goBack), for: .touchUpInside)
        FigmaTheme.applyCardShadow(to: backButton.layer)

        categoryScroll.translatesAutoresizingMaskIntoConstraints = false
        categoryScroll.showsHorizontalScrollIndicator = false
        categoryScroll.alwaysBounceHorizontal = true
        categoryScroll.backgroundColor = .clear

        categoryStack.axis = .horizontal
        categoryStack.spacing = 10
        categoryStack.alignment = .center
        categoryStack.translatesAutoresizingMaskIntoConstraints = false

        categoryScroll.addSubview(categoryStack)
        buildCategoryChips()

        view.addSubview(backgroundImageView)
        view.addSubview(blurEffectView)
        view.addSubview(backButton)
        view.addSubview(titleLabel)
        view.addSubview(categoryScroll)
        view.addSubview(collectionView)

        let g = view.safeAreaLayoutGuide
        NSLayoutConstraint.activate([
            backgroundImageView.topAnchor.constraint(equalTo: view.topAnchor),
            backgroundImageView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            backgroundImageView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            backgroundImageView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            blurEffectView.topAnchor.constraint(equalTo: view.topAnchor),
            blurEffectView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            blurEffectView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            blurEffectView.bottomAnchor.constraint(equalTo: view.bottomAnchor),

            backButton.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 14),
            backButton.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),

            titleLabel.centerXAnchor.constraint(equalTo: g.centerXAnchor),
            titleLabel.centerYAnchor.constraint(equalTo: backButton.centerYAnchor),
            titleLabel.leadingAnchor.constraint(greaterThanOrEqualTo: backButton.trailingAnchor, constant: 10),
            titleLabel.trailingAnchor.constraint(lessThanOrEqualTo: g.trailingAnchor, constant: -16),

            categoryScroll.topAnchor.constraint(equalTo: backButton.bottomAnchor, constant: 14),
            categoryScroll.leadingAnchor.constraint(equalTo: g.leadingAnchor),
            categoryScroll.trailingAnchor.constraint(equalTo: g.trailingAnchor),
            categoryScroll.heightAnchor.constraint(equalToConstant: 52),

            categoryStack.leadingAnchor.constraint(equalTo: categoryScroll.contentLayoutGuide.leadingAnchor, constant: 16),
            categoryStack.trailingAnchor.constraint(equalTo: categoryScroll.contentLayoutGuide.trailingAnchor, constant: -16),
            categoryStack.centerYAnchor.constraint(equalTo: categoryScroll.frameLayoutGuide.centerYAnchor),
            categoryStack.heightAnchor.constraint(lessThanOrEqualTo: categoryScroll.frameLayoutGuide.heightAnchor),

            collectionView.topAnchor.constraint(equalTo: categoryScroll.bottomAnchor, constant: 14),
            collectionView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            collectionView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            collectionView.bottomAnchor.constraint(equalTo: g.bottomAnchor),
        ])
    }

    /// Bubble title: cream fill + orange stroke (matches home “Color with Drawy” treatment).
    private func applyCategoryTitleAttributes() {
        let text = BuiltInColoringPages.library.indices.contains(selectedPackIndex)
            ? BuiltInColoringPages.library[selectedPackIndex].title
            : "Categories"
        let font = FigmaTheme.titleFont(size: 34)
        let paragraph = NSMutableParagraphStyle()
        paragraph.alignment = .center
        paragraph.lineBreakMode = .byTruncatingTail
        let attrs: [NSAttributedString.Key: Any] = [
            .font: font,
            .foregroundColor: FigmaTheme.creamText,
            .strokeColor: FigmaTheme.titleStroke,
            .strokeWidth: -3.5,
            .paragraphStyle: paragraph,
        ]
        titleLabel.attributedText = NSAttributedString(string: text, attributes: attrs)
    }

    private func buildCategoryChips() {
        categoryStack.arrangedSubviews.forEach {
            categoryStack.removeArrangedSubview($0)
            $0.removeFromSuperview()
        }
        categoryButtons.removeAll()

        for (i, pack) in BuiltInColoringPages.library.enumerated() {
            let b = UIButton(type: .system)
            b.tag = i
            b.addTarget(self, action: #selector(categoryChipTapped(_:)), for: .touchUpInside)
            categoryStack.addArrangedSubview(b)
            categoryButtons.append(b)
        }
        refreshPackChrome()
    }

    private func refreshPackChrome() {
        applyCategoryTitleAttributes()
        for (i, b) in categoryButtons.enumerated() {
            let pack = BuiltInColoringPages.library[i]
            let selected = i == selectedPackIndex
            var cfg = UIButton.Configuration.filled()
            cfg.title = pack.title
            cfg.image = UIImage(systemName: pack.symbolName)
            cfg.imagePlacement = .leading
            cfg.imagePadding = 6
            cfg.contentInsets = NSDirectionalEdgeInsets(top: 9, leading: 14, bottom: 9, trailing: 14)
            cfg.cornerStyle = .capsule
            cfg.titleLineBreakMode = .byTruncatingTail
            cfg.titleTextAttributesTransformer = UIConfigurationTextAttributesTransformer { incoming in
                var out = incoming
                out.font = FigmaTheme.bodyFont(size: 14, weight: .semibold)
                return out
            }
            if selected {
                cfg.baseForegroundColor = .white
                cfg.baseBackgroundColor = FigmaTheme.primaryOrange
                cfg.background.strokeColor = FigmaTheme.primaryOrangeBorder
                cfg.background.strokeWidth = 2
            } else {
                cfg.baseForegroundColor = UIColor(red: 12 / 255, green: 58 / 255, blue: 118 / 255, alpha: 1)
                cfg.baseBackgroundColor = UIColor(white: 1, alpha: 0.92)
                cfg.background.strokeColor = FigmaTheme.primaryOrange
                cfg.background.strokeWidth = 2.5
            }
            b.configuration = cfg
        }
        applyGridColumns()
        collectionView.reloadData()
    }

    @objc private func categoryChipTapped(_ sender: UIButton) {
        let i = sender.tag
        guard i >= 0, i < BuiltInColoringPages.library.count, i != selectedPackIndex else { return }
        selectedPackIndex = i
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        applyGridColumns()
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        applyGridColumns()
    }

    private func applyGridColumns() {
        guard let layout = collectionView.collectionViewLayout as? UICollectionViewFlowLayout else { return }
        let horizontalInset = layout.sectionInset.left + layout.sectionInset.right
        let verticalInset = layout.sectionInset.top + layout.sectionInset.bottom
        let interItemSpacing = layout.minimumInteritemSpacing
        let lineSpacing = layout.minimumLineSpacing
        let availableWidth = max(1, collectionView.bounds.width - horizontalInset)

        // Match pick-a-page slide: 3 columns × 2 rows visible; scroll for more.
        let columns: CGFloat = 3
        let rows: CGFloat = 2

        let widthRaw = availableWidth - interItemSpacing * (columns - 1)
        let widthBasedCellW = max(72, floor(widthRaw / columns))

        let availableHeight = max(1, collectionView.bounds.height - verticalInset)
        let rowHeight = max(56, floor((availableHeight - lineSpacing * (rows - 1)) / rows))
        let heightBasedCellW = floor(rowHeight / 0.78)

        let cellW = min(widthBasedCellW, heightBasedCellW)
        layout.itemSize = CGSize(width: cellW, height: cellW * 0.78)
    }

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        currentPages.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: Cell.reuseId, for: indexPath) as! Cell
        let page = currentPages[indexPath.item]
        cell.imageView.image = page.image
        cell.titleLabel.text = page.title
        return cell
    }

    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        LastDrawingStore.clearContinueDrawingSession()
        let canvas = ColoringViewController()
        canvas.coloringBookPages = currentPages
        canvas.pinnedPageIndex = indexPath.item
        if BuiltInColoringPages.library.indices.contains(selectedPackIndex) {
            canvas.sessionPackId = BuiltInColoringPages.library[selectedPackIndex].id
        }
        navigationController?.pushViewController(canvas, animated: true)
    }

    @objc private func goBack() {
        navigationController?.popViewController(animated: true)
    }

    private final class Cell: UICollectionViewCell {
        static let reuseId = "cell"

        let imageView = UIImageView()
        let titleLabel = UILabel()

        override init(frame: CGRect) {
            super.init(frame: frame)
            contentView.layer.cornerRadius = 12
            contentView.clipsToBounds = true
            contentView.backgroundColor = .white
            contentView.layer.borderWidth = 2
            contentView.layer.borderColor = FigmaTheme.primaryOrange.cgColor
            FigmaTheme.applyCardShadow(to: contentView.layer)

            imageView.contentMode = .scaleAspectFit
            imageView.translatesAutoresizingMaskIntoConstraints = false

            titleLabel.font = FigmaTheme.bodyFont(size: 11, weight: .semibold)
            titleLabel.textColor = FigmaTheme.titleStroke.withAlphaComponent(0.75)
            titleLabel.textAlignment = .center
            titleLabel.numberOfLines = 1
            titleLabel.lineBreakMode = .byTruncatingTail
            titleLabel.translatesAutoresizingMaskIntoConstraints = false

            contentView.addSubview(imageView)
            contentView.addSubview(titleLabel)

            NSLayoutConstraint.activate([
                imageView.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 10),
                imageView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 10),
                imageView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -10),
                imageView.bottomAnchor.constraint(equalTo: titleLabel.topAnchor, constant: -4),

                titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 6),
                titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -6),
                titleLabel.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -6),
            ])
        }

        required init?(coder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
    }
}
