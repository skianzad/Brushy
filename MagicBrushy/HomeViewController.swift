import UIKit

/// Figma: “Color with Drawy” home — category grid over hero illustration.
final class HomeViewController: UIViewController {

    private enum Category: Int, CaseIterable {
        case animals = 0
        case ocean = 1
        case food = 2
        case magic = 3

        var title: String {
            switch self {
            case .animals: return "Animals"
            case .ocean: return "Ocean"
            case .food: return "Food"
            case .magic: return "Magic"
            }
        }

        var accent: UIColor {
            switch self {
            case .animals: return FigmaTheme.animalsAccent
            case .ocean: return FigmaTheme.oceanAccent
            case .food: return FigmaTheme.foodAccent
            case .magic: return FigmaTheme.magicAccent
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
        gridStack.spacing = 20
        gridStack.translatesAutoresizingMaskIntoConstraints = false

        populateCategoryGrid()

        bodyStack.axis = .horizontal
        bodyStack.alignment = .center
        bodyStack.spacing = 18
        bodyStack.translatesAutoresizingMaskIntoConstraints = false
        bodyStack.addArrangedSubview(mascotView)
        bodyStack.addArrangedSubview(gridStack)

        styleUnlockButton()
        unlockButton.translatesAutoresizingMaskIntoConstraints = false
        unlockButton.addTarget(self, action: #selector(unlockTapped), for: .touchUpInside)

        scrollView.translatesAutoresizingMaskIntoConstraints = false
        scrollView.alwaysBounceVertical = false
        scrollView.showsVerticalScrollIndicator = false
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
            // Lock the scroll content to exactly the visible frame height so nothing scrolls
            contentView.heightAnchor.constraint(equalTo: scrollView.frameLayoutGuide.heightAnchor),

            titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 24),
            titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -24),
            titleLabel.topAnchor.constraint(equalTo: g.topAnchor, constant: 20),

            bodyStack.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 12),
            bodyStack.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 20),
            bodyStack.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -20),
            bodyStack.bottomAnchor.constraint(equalTo: g.bottomAnchor, constant: -20),

            // Mascot: 22% of view width, correct 499:656 aspect ratio
            mascotView.widthAnchor.constraint(equalTo: contentView.widthAnchor, multiplier: 0.22),
            mascotView.heightAnchor.constraint(equalTo: mascotView.widthAnchor, multiplier: 656.0 / 499.0),

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
        card.layer.cornerRadius = 13
        card.layer.borderWidth = 6
        card.layer.borderColor = category.accent.cgColor
        FigmaTheme.applyCardShadow(to: card.layer)

        let preview = UIImageView(image: BuiltInColoringPages.all.first?.image)
        preview.contentMode = .scaleAspectFit
        preview.translatesAutoresizingMaskIntoConstraints = false

        let footer = UIView()
        footer.translatesAutoresizingMaskIntoConstraints = false
        footer.backgroundColor = category.accent

        let label = UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = category.title
        label.textColor = FigmaTheme.creamText
        label.font = FigmaTheme.bodyFont(size: 22, weight: .semibold)
        label.textAlignment = .center
        label.adjustsFontSizeToFitWidth = true
        label.minimumScaleFactor = 0.6

        let lockHost = UIView()
        lockHost.translatesAutoresizingMaskIntoConstraints = false
        lockHost.backgroundColor = UIColor.white.withAlphaComponent(0.55)
        lockHost.isHidden = category.isFree

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
            card.heightAnchor.constraint(equalTo: card.widthAnchor, multiplier: 254 / 329),

            footer.leadingAnchor.constraint(equalTo: card.leadingAnchor, constant: -6),
            footer.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: 6),
            footer.bottomAnchor.constraint(equalTo: card.bottomAnchor, constant: 6),
            footer.heightAnchor.constraint(equalToConstant: 56),

            label.leadingAnchor.constraint(equalTo: footer.leadingAnchor, constant: 8),
            label.trailingAnchor.constraint(equalTo: footer.trailingAnchor, constant: -8),
            label.topAnchor.constraint(equalTo: footer.topAnchor, constant: 4),
            label.bottomAnchor.constraint(equalTo: footer.bottomAnchor, constant: -4),

            preview.leadingAnchor.constraint(equalTo: card.leadingAnchor, constant: 12),
            preview.trailingAnchor.constraint(equalTo: card.trailingAnchor, constant: -12),
            preview.topAnchor.constraint(equalTo: card.topAnchor, constant: 10),
            preview.bottomAnchor.constraint(equalTo: footer.topAnchor, constant: -6),

            lockHost.leadingAnchor.constraint(equalTo: card.leadingAnchor),
            lockHost.trailingAnchor.constraint(equalTo: card.trailingAnchor),
            lockHost.topAnchor.constraint(equalTo: card.topAnchor),
            lockHost.bottomAnchor.constraint(equalTo: footer.topAnchor),

            lock.centerXAnchor.constraint(equalTo: lockHost.centerXAnchor),
            lock.centerYAnchor.constraint(equalTo: lockHost.centerYAnchor),
            lock.widthAnchor.constraint(equalToConstant: 44),
            lock.heightAnchor.constraint(equalToConstant: 44),
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
        row0.spacing = 20
        row0.distribution = .fillEqually
        let row1 = UIStackView()
        row1.axis = .horizontal
        row1.spacing = 20
        row1.distribution = .fillEqually

        row0.addArrangedSubview(makeTile(for: .ocean))
        row0.addArrangedSubview(makeTile(for: .magic))
        row1.addArrangedSubview(makeTile(for: .animals))
        row1.addArrangedSubview(makeTile(for: .food))
        gridStack.addArrangedSubview(row0)
        gridStack.addArrangedSubview(row1)
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

        guard category == .animals else {
            let sheet = UIAlertController(title: category.title, message: "More outlines are coming soon.", preferredStyle: .alert)
            sheet.addAction(UIAlertAction(title: "OK", style: .default))
            present(sheet, animated: true)
            return
        }

        navigationController?.pushViewController(CategoryGridViewController(), animated: true)
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
