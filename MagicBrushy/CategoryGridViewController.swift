import UIKit
import Photos

/// Browse shelves: diamond back + white stroked title in one header row, page grid, then saved drawings at bottom (pack chips commented out).
final class CategoryGridViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {

    /// Set before the controller loads (e.g. from the home tile) to open on a specific shelf.
    var initialPackId: String?

    private var selectedPackIndex = 0 {
        didSet { refreshPackChrome() }
    }

    private let backgroundImageView = FigmaAlignedHeroBackgroundView()
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
    private let headerRow = UIStackView()
    private let headerLeadingContainer = UIView()
    private let headerTrailingContainer = UIView()
    private lazy var settingsButton: UIButton = makeMagicBrushySettingsGearButton()
    private let backButtonChrome = UIView()
    private let backDiamondRotator = UIView()
    private let backButtonStroke = UIView()
    private let backButtonFill = UIView()
    private let backButton = UIButton(type: .custom)

    private enum BackChromeMetrics {
        static let size: CGFloat = 90.9
        /// Square side before 45° rotation so the diamond fits the `size` × `size` layout box.
        static var diamondSquareSide: CGFloat { size / 2.0.squareRoot() }
        static let fillCornerRadius: CGFloat = 12.73
        static let strokeOutset: CGFloat = 2.52
        static var strokeSizeDelta: CGFloat { strokeOutset * 2 }
        static let strokeCornerRadius: CGFloat = 15.24
        static let strokeBorderWidth: CGFloat = 5.03
        static let fillColor = UIColor(red: 1, green: 0.539, blue: 0.012, alpha: 1)
        static let strokeColor = UIColor(red: 0.863, green: 0.404, blue: 0.153, alpha: 1)
        static let shadowRadius: CGFloat = 7.27
        static let shadowOffsetY: CGFloat = 7.27
    }
    private let categoryScroll = UIScrollView()
    private let categoryStack = UIStackView()
    private var categoryButtons: [UIButton] = []

    private let mainColumn = UIStackView()
    private let gridFill = UIView()

    private let lastDrawingCard = UIView()
    private let savedDrawingsSectionTitle = UILabel()
    private let savedDrawingsScrollView = UIScrollView()
    private let savedDrawingsStack = UIStackView()
    private var savedDrawingsHeightConstraint: NSLayoutConstraint!
    private var displayedSavedRecords: [LastDrawingStore.SavedDrawingRecord] = []

    private var currentPages: [BuiltInColoringPages.Page] {
        guard selectedPackIndex >= 0, selectedPackIndex < BuiltInColoringPages.library.count else {
            return []
        }
        return BuiltInColoringPages.library[selectedPackIndex].pages
    }

    private enum GridItem {
        case templatePage(page: BuiltInColoringPages.Page, pageIndex: Int)
        case savedFreeDrawing(record: LastDrawingStore.SavedDrawingRecord, recordIndex: Int)
    }

    private var currentGridItems: [GridItem] {
        guard selectedPackIndex >= 0, selectedPackIndex < BuiltInColoringPages.library.count else { return [] }
        let pack = BuiltInColoringPages.library[selectedPackIndex]
        let pages = pack.pages.enumerated().map { GridItem.templatePage(page: $0.element, pageIndex: $0.offset) }
        if pack.id == BuiltInColoringPages.savedDrawingsPackId {
            let saved = displayedSavedRecords.enumerated().map {
                GridItem.savedFreeDrawing(record: $0.element, recordIndex: $0.offset)
            }
            return pages + saved
        }
        return pages
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        LastDrawingStore.purgeLegacyNonFreeDrawingSavesIfNeeded()
        if let id = initialPackId,
           let idx = BuiltInColoringPages.library.firstIndex(where: { $0.id == id }) {
            selectedPackIndex = idx
        }
        view.backgroundColor = .black

        navigationController?.setNavigationBarHidden(true, animated: false)

        backgroundImageView.heroImage = UIImage(named: "HomeHero")
        backgroundImageView.translatesAutoresizingMaskIntoConstraints = false

        blurEffectView.translatesAutoresizingMaskIntoConstraints = false
        blurEffectView.isUserInteractionEnabled = false

        titleLabel.textAlignment = .center
        titleLabel.numberOfLines = 1
        titleLabel.lineBreakMode = .byTruncatingTail
        titleLabel.adjustsFontSizeToFitWidth = true
        titleLabel.minimumScaleFactor = 0.45
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        titleLabel.setContentHuggingPriority(.defaultLow, for: .horizontal)
        titleLabel.setContentCompressionResistancePriority(.defaultHigh, for: .horizontal)
        applyCategoryTitleAttributes()

        headerRow.axis = .horizontal
        headerRow.alignment = .center
        headerRow.spacing = 12
        headerRow.distribution = .fill
        headerRow.translatesAutoresizingMaskIntoConstraints = false
        headerRow.clipsToBounds = false
        headerLeadingContainer.translatesAutoresizingMaskIntoConstraints = false
        headerLeadingContainer.backgroundColor = .clear
        headerTrailingContainer.translatesAutoresizingMaskIntoConstraints = false
        headerTrailingContainer.backgroundColor = .clear
        headerTrailingContainer.addSubview(settingsButton)

        headerRow.addArrangedSubview(headerLeadingContainer)
        headerRow.addArrangedSubview(titleLabel)
        headerRow.addArrangedSubview(headerTrailingContainer)

        headerLeadingContainer.addSubview(backButtonChrome)

        backButtonChrome.translatesAutoresizingMaskIntoConstraints = false
        backButtonChrome.backgroundColor = .clear
        backButtonChrome.clipsToBounds = false
        backButtonChrome.layer.shadowColor = UIColor(red: 0, green: 0, blue: 0, alpha: 0.25).cgColor
        backButtonChrome.layer.shadowOpacity = 1
        backButtonChrome.layer.shadowRadius = BackChromeMetrics.shadowRadius
        backButtonChrome.layer.shadowOffset = CGSize(width: 0, height: BackChromeMetrics.shadowOffsetY)
        backButtonChrome.layer.masksToBounds = false

        backButtonStroke.translatesAutoresizingMaskIntoConstraints = false
        backButtonStroke.backgroundColor = .clear
        backButtonStroke.layer.borderWidth = BackChromeMetrics.strokeBorderWidth
        backButtonStroke.layer.borderColor = BackChromeMetrics.strokeColor.cgColor
        backButtonStroke.layer.cornerRadius = BackChromeMetrics.strokeCornerRadius
        backButtonStroke.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            backButtonStroke.layer.cornerCurve = .continuous
        }

        backDiamondRotator.translatesAutoresizingMaskIntoConstraints = false
        backDiamondRotator.backgroundColor = .clear
        backDiamondRotator.clipsToBounds = false

        backButtonFill.translatesAutoresizingMaskIntoConstraints = false
        backButtonFill.backgroundColor = BackChromeMetrics.fillColor
        backButtonFill.layer.cornerRadius = BackChromeMetrics.fillCornerRadius
        backButtonFill.clipsToBounds = true
        backButtonFill.isUserInteractionEnabled = false
        if #available(iOS 13.0, *) {
            backButtonFill.layer.cornerCurve = .continuous
        }

        backButton.translatesAutoresizingMaskIntoConstraints = false
        backButton.backgroundColor = .clear
        backButton.tintColor = .white
        let chevron = UIImage(systemName: "chevron.left", withConfiguration: UIImage.SymbolConfiguration(pointSize: 26, weight: .bold))
        backButton.setImage(chevron, for: .normal)
        backButton.accessibilityLabel = "Back"
        backButton.addTarget(self, action: #selector(goBack), for: .touchUpInside)
        backButton.transform = CGAffineTransform(rotationAngle: -.pi / 4)

        backButtonChrome.addSubview(backDiamondRotator)
        backDiamondRotator.addSubview(backButtonStroke)
        backDiamondRotator.addSubview(backButtonFill)
        backDiamondRotator.addSubview(backButton)
        backDiamondRotator.transform = CGAffineTransform(rotationAngle: .pi / 4)

        // Horizontal pack chips (commented out — pack comes from home / `initialPackId`).
        /*
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
        */

        gridFill.translatesAutoresizingMaskIntoConstraints = false
        gridFill.addSubview(collectionView)

        mainColumn.axis = .vertical
        mainColumn.spacing = 12
        mainColumn.alignment = .fill
        mainColumn.translatesAutoresizingMaskIntoConstraints = false
        // mainColumn.addArrangedSubview(categoryScroll)
        mainColumn.addArrangedSubview(gridFill)
        // mainColumn.addArrangedSubview(lastDrawingCard)   // saved-strip commented out

        gridFill.setContentHuggingPriority(.defaultLow, for: .vertical)
        // lastDrawingCard.setContentHuggingPriority(.defaultHigh, for: .vertical)

        // installSavedDrawingsStrip()   // saved-strip commented out

        view.addSubview(backgroundImageView)
        view.addSubview(blurEffectView)
        view.addSubview(headerRow)
        view.addSubview(mainColumn)

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

            headerRow.topAnchor.constraint(equalTo: g.topAnchor, constant: 8),
            headerRow.leadingAnchor.constraint(equalTo: g.leadingAnchor, constant: 12),
            headerRow.trailingAnchor.constraint(equalTo: g.trailingAnchor, constant: -12),

            backButtonChrome.widthAnchor.constraint(equalToConstant: BackChromeMetrics.size),
            backButtonChrome.heightAnchor.constraint(equalToConstant: BackChromeMetrics.size),

            headerLeadingContainer.widthAnchor.constraint(equalToConstant: BackChromeMetrics.size),
            headerTrailingContainer.widthAnchor.constraint(equalTo: headerLeadingContainer.widthAnchor),

            settingsButton.centerXAnchor.constraint(equalTo: headerTrailingContainer.centerXAnchor),
            settingsButton.centerYAnchor.constraint(equalTo: headerTrailingContainer.centerYAnchor),

            backButtonChrome.leadingAnchor.constraint(equalTo: headerLeadingContainer.leadingAnchor),
            backButtonChrome.trailingAnchor.constraint(equalTo: headerLeadingContainer.trailingAnchor),
            backButtonChrome.topAnchor.constraint(equalTo: headerLeadingContainer.topAnchor),
            backButtonChrome.bottomAnchor.constraint(equalTo: headerLeadingContainer.bottomAnchor),

            backDiamondRotator.topAnchor.constraint(equalTo: backButtonChrome.topAnchor),
            backDiamondRotator.leadingAnchor.constraint(equalTo: backButtonChrome.leadingAnchor),
            backDiamondRotator.trailingAnchor.constraint(equalTo: backButtonChrome.trailingAnchor),
            backDiamondRotator.bottomAnchor.constraint(equalTo: backButtonChrome.bottomAnchor),

            backButtonStroke.centerXAnchor.constraint(equalTo: backDiamondRotator.centerXAnchor),
            backButtonStroke.centerYAnchor.constraint(equalTo: backDiamondRotator.centerYAnchor),
            backButtonStroke.widthAnchor.constraint(equalToConstant: BackChromeMetrics.diamondSquareSide + BackChromeMetrics.strokeSizeDelta),
            backButtonStroke.heightAnchor.constraint(equalToConstant: BackChromeMetrics.diamondSquareSide + BackChromeMetrics.strokeSizeDelta),

            backButtonFill.centerXAnchor.constraint(equalTo: backDiamondRotator.centerXAnchor),
            backButtonFill.centerYAnchor.constraint(equalTo: backDiamondRotator.centerYAnchor),
            backButtonFill.widthAnchor.constraint(equalToConstant: BackChromeMetrics.diamondSquareSide),
            backButtonFill.heightAnchor.constraint(equalToConstant: BackChromeMetrics.diamondSquareSide),

            backButton.centerXAnchor.constraint(equalTo: backButtonFill.centerXAnchor),
            backButton.centerYAnchor.constraint(equalTo: backButtonFill.centerYAnchor),
            backButton.widthAnchor.constraint(equalTo: backButtonFill.widthAnchor),
            backButton.heightAnchor.constraint(equalTo: backButtonFill.heightAnchor),

            mainColumn.topAnchor.constraint(equalTo: headerRow.bottomAnchor, constant: 14),
            mainColumn.leadingAnchor.constraint(equalTo: g.leadingAnchor),
            mainColumn.trailingAnchor.constraint(equalTo: g.trailingAnchor),
            mainColumn.bottomAnchor.constraint(equalTo: g.bottomAnchor),

            /*
            categoryScroll.heightAnchor.constraint(equalToConstant: 52),

            categoryStack.leadingAnchor.constraint(equalTo: categoryScroll.contentLayoutGuide.leadingAnchor, constant: 16),
            categoryStack.trailingAnchor.constraint(equalTo: categoryScroll.contentLayoutGuide.trailingAnchor, constant: -16),
            categoryStack.centerYAnchor.constraint(equalTo: categoryScroll.frameLayoutGuide.centerYAnchor),
            categoryStack.heightAnchor.constraint(lessThanOrEqualTo: categoryScroll.frameLayoutGuide.heightAnchor),
            */

            collectionView.topAnchor.constraint(equalTo: gridFill.topAnchor),
            collectionView.leadingAnchor.constraint(equalTo: gridFill.leadingAnchor),
            collectionView.trailingAnchor.constraint(equalTo: gridFill.trailingAnchor),
            collectionView.bottomAnchor.constraint(equalTo: gridFill.bottomAnchor),
        ])
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        // refreshSavedDrawingsStrip()   // saved-strip commented out
        // Reload so saved free drawings appear inline in the free-drawing grid.
        displayedSavedRecords = LastDrawingStore.allSavedGalleryRecordsNewestFirst()
        collectionView.reloadData()
    }

    private func installSavedDrawingsStrip() {
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
        savedDrawingsSectionTitle.text = "Free drawings"
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

            { savedDrawingsHeightConstraint = savedDrawingsScrollView.heightAnchor.constraint(equalToConstant: 132); return savedDrawingsHeightConstraint }(),
        ])
    }

    private func refreshSavedDrawingsStrip() {
        // Saved-strip UI is commented out; refresh the collection view instead.
        displayedSavedRecords = LastDrawingStore.allSavedGalleryRecordsNewestFirst()
        collectionView.reloadData()
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

    @objc func savedDrawingMenuTapped(_ sender: UIButton) {
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
            self?.refreshSavedDrawingsStrip()
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
            title: "Delete all free drawings?",
            message: "This removes every saved blank-paper picture from this device. You can’t undo it.",
            preferredStyle: .alert
        )
        confirm.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        confirm.addAction(UIAlertAction(title: "Delete all", style: .destructive, handler: { [weak self] _ in
            LastDrawingStore.deleteAllRecords(withPackId: BuiltInColoringPages.savedDrawingsPackId)
            UIImpactFeedbackGenerator(style: .medium).impactOccurred()
            self?.refreshSavedDrawingsStrip()
        }))
        present(confirm, animated: true)
    }

    private func openSavedDrawing(at index: Int) {
        guard displayedSavedRecords.indices.contains(index) else { return }
        let rec = displayedSavedRecords[index]
        guard rec.packId == BuiltInColoringPages.savedDrawingsPackId else { return }
        guard let pack = BuiltInColoringPages.library.first(where: { $0.id == rec.packId }) else { return }
        let packUnlocked = SubscriptionManager.shared.canOpenPack(id: pack.id)
        guard packUnlocked else {
            UIImpactFeedbackGenerator(style: .medium).impactOccurred()
            let sheet = UIAlertController(
                title: "Locked",
                message: "Subscribe on the home screen to open drawings from this pack again.",
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

    /// Large pack name: white fill + orange stroke (matches diamond back control).
    private func applyCategoryTitleAttributes() {
        let text = BuiltInColoringPages.library.indices.contains(selectedPackIndex)
            ? BuiltInColoringPages.library[selectedPackIndex].title
            : "Categories"
        let compact = traitCollection.verticalSizeClass == .compact
        let fontSize: CGFloat = compact ? 44 : 58
        let font = FigmaTheme.titleFont(size: fontSize)
        let paragraph = NSMutableParagraphStyle()
        paragraph.alignment = .center
        paragraph.lineBreakMode = .byTruncatingTail
        let attrs: [NSAttributedString.Key: Any] = [
            .font: font,
            .foregroundColor: UIColor.white,
            .strokeColor: BackChromeMetrics.fillColor,
            .strokeWidth: -4.5,
            .paragraphStyle: paragraph,
        ]
        titleLabel.attributedText = NSAttributedString(string: text, attributes: attrs)
    }

    /*
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

    @objc private func categoryChipTapped(_ sender: UIButton) {
        let i = sender.tag
        guard i >= 0, i < BuiltInColoringPages.library.count, i != selectedPackIndex else { return }
        selectedPackIndex = i
    }
    */

    private func refreshPackChrome() {
        applyCategoryTitleAttributes()
        applyGridColumns()
        collectionView.reloadData()
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        updateBackButtonChromeShadowPath()
        applyGridColumns()
    }

    private func updateBackButtonChromeShadowPath() {
        let b = backButtonChrome.bounds
        guard b.width > 1, b.height > 1 else { return }
        let r = BackChromeMetrics.fillCornerRadius
        backButtonChrome.layer.shadowPath = UIBezierPath(roundedRect: b, cornerRadius: r).cgPath
    }

    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        if previousTraitCollection?.verticalSizeClass != traitCollection.verticalSizeClass {
            applyCategoryTitleAttributes()
        }
        applyGridColumns()
    }

    private func applyGridColumns() {
        guard let layout = collectionView.collectionViewLayout as? UICollectionViewFlowLayout else { return }
        let horizontalInset = layout.sectionInset.left + layout.sectionInset.right
        let verticalInset = layout.sectionInset.top + layout.sectionInset.bottom
        let interItemSpacing = layout.minimumInteritemSpacing
        let lineSpacing = layout.minimumLineSpacing
        let availableWidth = max(1, collectionView.bounds.width - horizontalInset)

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
        currentGridItems.count
    }

    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: Cell.reuseId, for: indexPath) as! Cell
        switch currentGridItems[indexPath.item] {
        case .templatePage(let page, let pageIndex):
            let pack = BuiltInColoringPages.library[selectedPackIndex]
            let thumb: UIImage
            if pack.id != BuiltInColoringPages.savedDrawingsPackId,
               let underlay = TemplateProgressStore.load(packId: pack.id, pageIndex: pageIndex) {
                thumb = TemplateProgressStore.shelfPreviewImage(templatePageImage: page.image, savedUnderlay: underlay)
            } else {
                thumb = page.image
            }
            let isBlankPaperStarter = pack.id == BuiltInColoringPages.savedDrawingsPackId && pageIndex == 0
            cell.configure(
                image: thumb,
                title: page.title,
                isSavedDrawing: false,
                showsNewDrawingPlus: isBlankPaperStarter,
                menuTarget: nil,
                menuTag: 0
            )
        case .savedFreeDrawing(let rec, let idx):
            cell.configure(
                image: LastDrawingStore.loadThumbnail(id: rec.id),
                title: rec.pageTitle,
                isSavedDrawing: true,
                showsNewDrawingPlus: false,
                menuTarget: self,
                menuTag: idx
            )
        }
        return cell
    }

    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        switch currentGridItems[indexPath.item] {
        case .templatePage(_, let pageIndex):
            openTemplatePage(pageIndex: pageIndex)
        case .savedFreeDrawing(_, let recordIndex):
            openSavedDrawing(at: recordIndex)
        }
    }

    private func openTemplatePage(pageIndex: Int) {
        LastDrawingStore.clearContinueDrawingSession()
        let pack = BuiltInColoringPages.library[selectedPackIndex]
        let canvas = ColoringViewController()
        canvas.coloringBookPages = currentPages
        canvas.pinnedPageIndex = pageIndex
        canvas.sessionPackId = pack.id
        if pack.id != BuiltInColoringPages.savedDrawingsPackId,
           let underlay = TemplateProgressStore.load(packId: pack.id, pageIndex: pageIndex) {
            canvas.pendingResumeComposite = underlay
            canvas.pendingResumeHasSeparateLineOverlay = true
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
        private let newDrawingBadge = UIView()
        private let newDrawingPlus = UIImageView()
        private let menuButton = UIButton(type: .system)
        private var menuButtonAction: UIAction?

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

            var menuCfg = UIButton.Configuration.plain()
            menuCfg.image = UIImage(systemName: "ellipsis.circle.fill")
            menuCfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 18, weight: .semibold)
            menuCfg.baseForegroundColor = FigmaTheme.actionBlue
            menuButton.configuration = menuCfg
            menuButton.translatesAutoresizingMaskIntoConstraints = false
            menuButton.isHidden = true

            newDrawingBadge.translatesAutoresizingMaskIntoConstraints = false
            newDrawingBadge.backgroundColor = FigmaTheme.primaryOrange
            newDrawingBadge.layer.cornerRadius = 26
            newDrawingBadge.layer.borderWidth = 3
            newDrawingBadge.layer.borderColor = FigmaTheme.primaryOrangeBorder.cgColor
            newDrawingBadge.isHidden = true
            newDrawingBadge.isUserInteractionEnabled = false
            FigmaTheme.applyCardShadow(to: newDrawingBadge.layer)

            newDrawingPlus.translatesAutoresizingMaskIntoConstraints = false
            newDrawingPlus.tintColor = .white
            newDrawingPlus.contentMode = .scaleAspectFit
            newDrawingPlus.image = UIImage(
                systemName: "plus",
                withConfiguration: UIImage.SymbolConfiguration(pointSize: 28, weight: .bold)
            )
            newDrawingPlus.isUserInteractionEnabled = false

            newDrawingBadge.addSubview(newDrawingPlus)

            contentView.addSubview(imageView)
            contentView.addSubview(titleLabel)
            contentView.addSubview(newDrawingBadge)
            contentView.addSubview(menuButton)

            NSLayoutConstraint.activate([
                imageView.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 10),
                imageView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 10),
                imageView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -10),
                imageView.bottomAnchor.constraint(equalTo: titleLabel.topAnchor, constant: -4),

                titleLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 6),
                titleLabel.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -6),
                titleLabel.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -6),

                menuButton.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 2),
                menuButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -2),
                menuButton.widthAnchor.constraint(equalToConstant: 30),
                menuButton.heightAnchor.constraint(equalToConstant: 30),

                newDrawingBadge.centerXAnchor.constraint(equalTo: imageView.centerXAnchor),
                newDrawingBadge.centerYAnchor.constraint(equalTo: imageView.centerYAnchor),
                newDrawingBadge.widthAnchor.constraint(equalToConstant: 52),
                newDrawingBadge.heightAnchor.constraint(equalToConstant: 52),

                newDrawingPlus.centerXAnchor.constraint(equalTo: newDrawingBadge.centerXAnchor),
                newDrawingPlus.centerYAnchor.constraint(equalTo: newDrawingBadge.centerYAnchor),
            ])
        }

        override func prepareForReuse() {
            super.prepareForReuse()
            newDrawingBadge.isHidden = true
        }

        func configure(
            image: UIImage?,
            title: String,
            isSavedDrawing: Bool,
            showsNewDrawingPlus: Bool,
            menuTarget: AnyObject?,
            menuTag: Int
        ) {
            imageView.image = image
            titleLabel.text = title
            imageView.contentMode = isSavedDrawing ? .scaleAspectFill : .scaleAspectFit
            imageView.clipsToBounds = isSavedDrawing
            imageView.layer.cornerRadius = isSavedDrawing ? 6 : 0
            contentView.layer.borderColor = isSavedDrawing
                ? FigmaTheme.primaryOrange.withAlphaComponent(0.55).cgColor
                : FigmaTheme.primaryOrange.cgColor
            newDrawingBadge.isHidden = !showsNewDrawingPlus
            accessibilityLabel = showsNewDrawingPlus ? "New blank drawing" : title
            accessibilityHint = showsNewDrawingPlus ? "Starts a fresh sheet to draw on." : nil
            menuButton.isHidden = !isSavedDrawing
            if let target = menuTarget as? CategoryGridViewController, isSavedDrawing {
                menuButton.tag = menuTag
                menuButton.removeTarget(nil, action: nil, for: .touchUpInside)
                menuButton.addTarget(target, action: #selector(CategoryGridViewController.savedDrawingMenuTapped(_:)), for: .touchUpInside)
            }
        }

        required init?(coder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
    }
}
