import UIKit

/// Browse shelves: horizontal category chips + a grid of outlines (coastal-style layout).
final class CategoryGridViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {

    /// Set before the controller loads (e.g. from the home tile) to open on a specific shelf.
    var initialPackId: String?

    private var selectedPackIndex = 0 {
        didSet { refreshPackChrome() }
    }

    private lazy var collectionView: UICollectionView = {
        let layout = UICollectionViewFlowLayout()
        layout.minimumInteritemSpacing = 12
        layout.minimumLineSpacing = 16
        layout.sectionInset = UIEdgeInsets(top: 8, left: 20, bottom: 24, right: 20)
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
    private let backButton = UIButton(type: .system)
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
        view.backgroundColor = FigmaTheme.coastBackground

        navigationController?.setNavigationBarHidden(true, animated: false)

        titleLabel.text = BuiltInColoringPages.library.indices.contains(selectedPackIndex)
            ? BuiltInColoringPages.library[selectedPackIndex].title
            : "Categories"
        titleLabel.textAlignment = .center
        titleLabel.numberOfLines = 1
        titleLabel.font = FigmaTheme.titleFont(size: 34)
        titleLabel.textColor = FigmaTheme.coastTitle
        titleLabel.translatesAutoresizingMaskIntoConstraints = false

        var backCfg = UIButton.Configuration.plain()
        backCfg.image = UIImage(systemName: "chevron.backward.circle.fill")
        backCfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 28, weight: .bold)
        backCfg.baseForegroundColor = FigmaTheme.coastChip
        backButton.configuration = backCfg
        backButton.translatesAutoresizingMaskIntoConstraints = false
        backButton.addTarget(self, action: #selector(goBack), for: .touchUpInside)

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

        view.addSubview(backButton)
        view.addSubview(titleLabel)
        view.addSubview(categoryScroll)
        view.addSubview(collectionView)

        let g = view.safeAreaLayoutGuide
        NSLayoutConstraint.activate([
            backButton.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 12),
            backButton.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),

            titleLabel.centerXAnchor.constraint(equalTo: g.centerXAnchor),
            titleLabel.centerYAnchor.constraint(equalTo: backButton.centerYAnchor),
            titleLabel.leadingAnchor.constraint(greaterThanOrEqualTo: backButton.trailingAnchor, constant: 8),

            categoryScroll.topAnchor.constraint(equalTo: backButton.bottomAnchor, constant: 12),
            categoryScroll.leadingAnchor.constraint(equalTo: g.leadingAnchor),
            categoryScroll.trailingAnchor.constraint(equalTo: g.trailingAnchor),
            categoryScroll.heightAnchor.constraint(equalToConstant: 48),

            categoryStack.leadingAnchor.constraint(equalTo: categoryScroll.contentLayoutGuide.leadingAnchor, constant: 16),
            categoryStack.trailingAnchor.constraint(equalTo: categoryScroll.contentLayoutGuide.trailingAnchor, constant: -16),
            categoryStack.centerYAnchor.constraint(equalTo: categoryScroll.frameLayoutGuide.centerYAnchor),
            categoryStack.heightAnchor.constraint(lessThanOrEqualTo: categoryScroll.frameLayoutGuide.heightAnchor),

            collectionView.topAnchor.constraint(equalTo: categoryScroll.bottomAnchor, constant: 12),
            collectionView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            collectionView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            collectionView.bottomAnchor.constraint(equalTo: g.bottomAnchor),
        ])
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
        titleLabel.text = BuiltInColoringPages.library[selectedPackIndex].title
        for (i, b) in categoryButtons.enumerated() {
            let pack = BuiltInColoringPages.library[i]
            var cfg = UIButton.Configuration.filled()
            cfg.title = pack.title
            cfg.image = UIImage(systemName: pack.symbolName)
            cfg.imagePlacement = .leading
            cfg.imagePadding = 6
            cfg.contentInsets = NSDirectionalEdgeInsets(top: 8, leading: 14, bottom: 8, trailing: 14)
            cfg.baseForegroundColor = .white
            cfg.background.backgroundColor = i == selectedPackIndex ? FigmaTheme.coastChipSelected : FigmaTheme.coastChip
            cfg.cornerStyle = .capsule
            cfg.titleLineBreakMode = .byClipping
            cfg.titleTextAttributesTransformer = UIConfigurationTextAttributesTransformer { incoming in
                var out = incoming
                out.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)
                return out
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

        // First shelf: force a 2x3 viewport (2 columns, 3 rows visible) and keep scrolling for extras.
        if selectedPackIndex == 0 {
            let columns: CGFloat = 2
            let rows: CGFloat = 3

            let widthRaw = availableWidth - interItemSpacing * (columns - 1)
            let widthBasedCellW = max(72, floor(widthRaw / columns))

            let availableHeight = max(1, collectionView.bounds.height - verticalInset)
            let rowHeight = max(56, floor((availableHeight - lineSpacing * (rows - 1)) / rows))
            let heightBasedCellW = floor(rowHeight / 0.78)

            let cellW = min(widthBasedCellW, heightBasedCellW)
            layout.itemSize = CGSize(width: cellW, height: cellW * 0.78)
            return
        }

        let columns: CGFloat = traitCollection.horizontalSizeClass == .regular ? 4 : 2
        let raw = availableWidth - interItemSpacing * (columns - 1)
        let cellW = max(72, floor(raw / columns))
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
        let canvas = ColoringViewController()
        canvas.coloringBookPages = currentPages
        canvas.pinnedPageIndex = indexPath.item
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
            contentView.layer.cornerRadius = 14
            contentView.clipsToBounds = true
            contentView.backgroundColor = .white
            contentView.layer.borderWidth = 3
            contentView.layer.borderColor = FigmaTheme.coastChip.withAlphaComponent(0.35).cgColor

            imageView.contentMode = .scaleAspectFit
            imageView.translatesAutoresizingMaskIntoConstraints = false

            titleLabel.font = FigmaTheme.bodyFont(size: 14, weight: .semibold)
            titleLabel.textColor = FigmaTheme.coastTitle
            titleLabel.textAlignment = .center
            titleLabel.translatesAutoresizingMaskIntoConstraints = false

            contentView.addSubview(imageView)
            contentView.addSubview(titleLabel)

            NSLayoutConstraint.activate([
                imageView.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 8),
                imageView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 8),
                imageView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -8),
                imageView.bottomAnchor.constraint(equalTo: titleLabel.topAnchor, constant: -4),

                titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 6),
                titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -6),
                titleLabel.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -8),
            ])
        }

        required init?(coder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
    }
}
