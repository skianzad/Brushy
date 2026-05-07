import UIKit

/// Figma: Animals grid of built-in outlines before entering the canvas.
final class CategoryGridViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {

    private lazy var collectionView: UICollectionView = {
        let layout = UICollectionViewFlowLayout()
        layout.minimumInteritemSpacing = 18
        layout.minimumLineSpacing = 22
        layout.sectionInset = UIEdgeInsets(top: 12, left: 24, bottom: 24, right: 24)
        let cv = UICollectionView(frame: .zero, collectionViewLayout: layout)
        cv.backgroundColor = .clear
        cv.dataSource = self
        cv.delegate = self
        cv.register(Cell.self, forCellWithReuseIdentifier: Cell.reuseId)
        cv.translatesAutoresizingMaskIntoConstraints = false
        return cv
    }()

    private let titleLabel = UILabel()
    private let backButton = UIButton(type: .system)

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor(white: 0.97, alpha: 1)

        navigationController?.setNavigationBarHidden(true, animated: false)

        titleLabel.text = "Animals"
        titleLabel.textAlignment = .center
        titleLabel.numberOfLines = 1
        titleLabel.font = FigmaTheme.titleFont(size: 40)
        titleLabel.textColor = FigmaTheme.animalsAccent
        titleLabel.translatesAutoresizingMaskIntoConstraints = false

        var backCfg = UIButton.Configuration.plain()
        backCfg.image = UIImage(systemName: "chevron.backward.circle.fill")
        backCfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 28, weight: .bold)
        backCfg.baseForegroundColor = FigmaTheme.primaryOrange
        backButton.configuration = backCfg
        backButton.translatesAutoresizingMaskIntoConstraints = false
        backButton.addTarget(self, action: #selector(goBack), for: .touchUpInside)

        view.addSubview(backButton)
        view.addSubview(titleLabel)
        view.addSubview(collectionView)

        let g = view.safeAreaLayoutGuide
        NSLayoutConstraint.activate([
            backButton.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 12),
            backButton.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),

            titleLabel.centerXAnchor.constraint(equalTo: g.centerXAnchor),
            titleLabel.centerYAnchor.constraint(equalTo: backButton.centerYAnchor),
            titleLabel.leadingAnchor.constraint(greaterThanOrEqualTo: backButton.trailingAnchor, constant: 8),

            collectionView.topAnchor.constraint(equalTo: backButton.bottomAnchor, constant: 16),
            collectionView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            collectionView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            collectionView.bottomAnchor.constraint(equalTo: g.bottomAnchor),
        ])
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        if let layout = collectionView.collectionViewLayout as? UICollectionViewFlowLayout {
            let inset = layout.sectionInset.left + layout.sectionInset.right
            let spacing = layout.minimumInteritemSpacing
            let w = collectionView.bounds.width - inset - spacing
            let cellW = max(140, floor(w / 2))
            layout.itemSize = CGSize(width: cellW, height: cellW * 0.78)
        }
    }

    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        BuiltInColoringPages.all.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: Cell.reuseId, for: indexPath) as! Cell
        cell.imageView.image = BuiltInColoringPages.all[indexPath.item].image
        cell.titleLabel.text = BuiltInColoringPages.all[indexPath.item].title
        return cell
    }

    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let canvas = ColoringViewController()
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
            contentView.layer.cornerRadius = 18
            contentView.clipsToBounds = true
            contentView.backgroundColor = .white
            contentView.layer.borderWidth = 4
            contentView.layer.borderColor = FigmaTheme.canvasBorder.cgColor

            imageView.contentMode = .scaleAspectFit
            imageView.translatesAutoresizingMaskIntoConstraints = false

            titleLabel.font = FigmaTheme.bodyFont(size: 17, weight: .semibold)
            titleLabel.textColor = .label
            titleLabel.textAlignment = .center
            titleLabel.translatesAutoresizingMaskIntoConstraints = false

            contentView.addSubview(imageView)
            contentView.addSubview(titleLabel)

            NSLayoutConstraint.activate([
                imageView.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 10),
                imageView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 10),
                imageView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -10),
                imageView.bottomAnchor.constraint(equalTo: titleLabel.topAnchor, constant: -6),

                titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 8),
                titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -8),
                titleLabel.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -10),
            ])
        }

        required init?(coder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
    }
}
