import UIKit

/// Background music volume and other app preferences.
final class MagicBrushySettingsViewController: UIViewController {

    private let cardView = UIView()
    private let titleLabel = UILabel()
    private let musicRow = UIStackView()
    private let musicIcon = UIImageView()
    private let musicSlider = UISlider()
    private let languageButton = UIButton(type: .system)

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.black.withAlphaComponent(0.35)
        preferredContentSize = CGSize(width: 320, height: 268)

        cardView.translatesAutoresizingMaskIntoConstraints = false
        cardView.backgroundColor = UIColor(white: 0.12, alpha: 0.94)
        cardView.layer.cornerRadius = 20
        cardView.layer.borderWidth = 2
        cardView.layer.borderColor = UIColor.white.withAlphaComponent(0.22).cgColor
        if #available(iOS 13.0, *) {
            cardView.layer.cornerCurve = .continuous
        }

        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        titleLabel.text = "Settings"
        titleLabel.textColor = FigmaTheme.creamText
        titleLabel.font = FigmaTheme.titleFont(size: 22)
        titleLabel.textAlignment = .center

        // MARK: Music row

        musicRow.axis = .horizontal
        musicRow.alignment = .center
        musicRow.spacing = 10
        musicRow.translatesAutoresizingMaskIntoConstraints = false

        musicIcon.translatesAutoresizingMaskIntoConstraints = false
        musicIcon.tintColor = FigmaTheme.primaryOrange
        musicIcon.contentMode = .scaleAspectFit
        musicIcon.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 20, weight: .semibold)
        musicIcon.setContentHuggingPriority(.required, for: .horizontal)

        musicSlider.translatesAutoresizingMaskIntoConstraints = false
        musicSlider.minimumValue = 0
        musicSlider.maximumValue = 1
        musicSlider.minimumTrackTintColor = FigmaTheme.primaryOrange
        musicSlider.maximumTrackTintColor = UIColor.white.withAlphaComponent(0.28)
        musicSlider.accessibilityLabel = "Background music"
        musicSlider.accessibilityHint = "Adjusts the quiet background tune across the app."
        musicSlider.addTarget(self, action: #selector(musicVolumeChanged), for: .valueChanged)

        let musicCaption = makeCaption("Background music")
        musicRow.addArrangedSubview(musicIcon)
        musicRow.addArrangedSubview(musicSlider)

        // MARK: Language row

        let langCaption = makeCaption("Response language")
        let langIconView = UIImageView(image: UIImage(systemName: "globe"))
        langIconView.translatesAutoresizingMaskIntoConstraints = false
        langIconView.tintColor = FigmaTheme.primaryOrange
        langIconView.contentMode = .scaleAspectFit
        langIconView.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 20, weight: .semibold)
        langIconView.setContentHuggingPriority(.required, for: .horizontal)

        languageButton.translatesAutoresizingMaskIntoConstraints = false
        languageButton.titleLabel?.font = FigmaTheme.bodyFont(size: 16, weight: .semibold)
        languageButton.setTitleColor(FigmaTheme.creamText, for: .normal)
        languageButton.backgroundColor = UIColor.white.withAlphaComponent(0.12)
        languageButton.layer.cornerRadius = 10
        if #available(iOS 13.0, *) { languageButton.layer.cornerCurve = .continuous }
        languageButton.contentHorizontalAlignment = .left
        languageButton.titleEdgeInsets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
        languageButton.accessibilityLabel = "Response language"
        languageButton.accessibilityHint = "Choose the language the painting coach speaks in."
        setupLanguageMenu()

        let langRow = UIStackView(arrangedSubviews: [langIconView, languageButton])
        langRow.axis = .horizontal
        langRow.alignment = .center
        langRow.spacing = 10
        langRow.translatesAutoresizingMaskIntoConstraints = false

        // MARK: Divider

        let divider = UIView()
        divider.translatesAutoresizingMaskIntoConstraints = false
        divider.backgroundColor = UIColor.white.withAlphaComponent(0.14)

        // MARK: Assemble

        cardView.addSubview(titleLabel)
        cardView.addSubview(musicCaption)
        cardView.addSubview(musicRow)
        cardView.addSubview(divider)
        cardView.addSubview(langCaption)
        cardView.addSubview(langRow)
        view.addSubview(cardView)

        NSLayoutConstraint.activate([
            cardView.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            cardView.centerYAnchor.constraint(equalTo: view.centerYAnchor),
            cardView.leadingAnchor.constraint(greaterThanOrEqualTo: view.leadingAnchor, constant: 28),
            cardView.trailingAnchor.constraint(lessThanOrEqualTo: view.trailingAnchor, constant: -28),
            cardView.widthAnchor.constraint(lessThanOrEqualToConstant: 360),
            cardView.widthAnchor.constraint(equalToConstant: 320).withPriority(.defaultHigh),

            titleLabel.topAnchor.constraint(equalTo: cardView.topAnchor, constant: 20),
            titleLabel.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            titleLabel.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            musicCaption.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 18),
            musicCaption.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            musicCaption.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            musicRow.topAnchor.constraint(equalTo: musicCaption.bottomAnchor, constant: 10),
            musicRow.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            musicRow.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            musicIcon.widthAnchor.constraint(equalToConstant: 28),
            musicIcon.heightAnchor.constraint(equalToConstant: 28),

            divider.topAnchor.constraint(equalTo: musicRow.bottomAnchor, constant: 18),
            divider.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            divider.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),
            divider.heightAnchor.constraint(equalToConstant: 1),

            langCaption.topAnchor.constraint(equalTo: divider.bottomAnchor, constant: 14),
            langCaption.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            langCaption.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            langRow.topAnchor.constraint(equalTo: langCaption.bottomAnchor, constant: 10),
            langRow.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            langRow.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),
            langRow.bottomAnchor.constraint(equalTo: cardView.bottomAnchor, constant: -22),

            langIconView.widthAnchor.constraint(equalToConstant: 28),
            langIconView.heightAnchor.constraint(equalToConstant: 28),
            languageButton.heightAnchor.constraint(equalToConstant: 38),
        ])

        syncMusicControlsFromStorage()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        syncMusicControlsFromStorage()
    }

    // MARK: - Music

    private func syncMusicControlsFromStorage() {
        musicSlider.value = MagicBrushyBackgroundMusic.storedUserVolumeScale()
        applyMusicVolumeIcon()
    }

    private func applyMusicVolumeIcon() {
        let quiet = musicSlider.value < 0.04
        musicIcon.image = UIImage(systemName: quiet ? "speaker.slash.fill" : "speaker.wave.2.fill")
    }

    @objc private func musicVolumeChanged(_ sender: UISlider) {
        MagicBrushyBackgroundMusic.setUserVolumeScale(sender.value)
        applyMusicVolumeIcon()
    }

    // MARK: - Language

    private func setupLanguageMenu() {
        updateLanguageButtonTitle(MagicBrushyLanguage.stored())

        if #available(iOS 14.0, *) {
            let actions = MagicBrushyLanguage.allCases.map { lang in
                UIAction(title: lang.displayName, state: MagicBrushyLanguage.stored() == lang ? .on : .off) { [weak self] _ in
                    MagicBrushyLanguage.store(lang)
                    self?.updateLanguageButtonTitle(lang)
                    self?.setupLanguageMenu()
                }
            }
            languageButton.menu = UIMenu(title: "", children: actions)
            languageButton.showsMenuAsPrimaryAction = true
        } else {
            languageButton.addTarget(self, action: #selector(languageButtonTapped), for: .touchUpInside)
        }
    }

    private func updateLanguageButtonTitle(_ lang: MagicBrushyLanguage) {
        languageButton.setTitle("  \(lang.displayName)", for: .normal)
    }

    @objc private func languageButtonTapped() {
        let sheet = UIAlertController(title: "Response language", message: nil, preferredStyle: .actionSheet)
        for lang in MagicBrushyLanguage.allCases {
            let current = MagicBrushyLanguage.stored() == lang
            let action = UIAlertAction(title: (current ? "✓ " : "    ") + lang.displayName, style: .default) { [weak self] _ in
                MagicBrushyLanguage.store(lang)
                self?.updateLanguageButtonTitle(lang)
            }
            sheet.addAction(action)
        }
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        sheet.popoverPresentationController?.sourceView = languageButton
        present(sheet, animated: true)
    }

    // MARK: - Helpers

    private func makeCaption(_ text: String) -> UILabel {
        let label = UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        label.text = text
        label.textColor = FigmaTheme.creamText.withAlphaComponent(0.92)
        label.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)
        return label
    }
}

// MARK: - Gear button + presentation

extension UIViewController {

    /// Chrome gear button (52×52) matching nav controls on the coloring screen.
    func makeMagicBrushySettingsGearButton() -> UIButton {
        let b = UIButton(type: .system)
        var cfg = UIButton.Configuration.plain()
        cfg.image = UIImage(systemName: "gearshape.fill")
        cfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 20, weight: .bold)
        cfg.baseForegroundColor = .white
        b.configuration = cfg
        b.translatesAutoresizingMaskIntoConstraints = false
        b.accessibilityLabel = "Settings"
        b.accessibilityHint = "Background music volume and preferences."
        b.backgroundColor = FigmaTheme.actionBlue
        b.layer.cornerRadius = 14
        b.layer.borderWidth = 4
        b.layer.borderColor = FigmaTheme.actionBlueBorder.cgColor
        b.layer.shadowColor = UIColor.black.cgColor
        b.layer.shadowOpacity = 0.18
        b.layer.shadowRadius = 4
        b.layer.shadowOffset = CGSize(width: 0, height: 2)
        b.addTarget(self, action: #selector(magicBrushySettingsGearTapped(_:)), for: .touchUpInside)
        NSLayoutConstraint.activate([
            b.widthAnchor.constraint(equalToConstant: 52),
            b.heightAnchor.constraint(equalToConstant: 52),
        ])
        return b
    }

    @objc func magicBrushySettingsGearTapped(_ sender: UIButton) {
        presentMagicBrushySettings(from: sender)
    }

    func presentMagicBrushySettings(from sourceView: UIView) {
        let settings = MagicBrushySettingsViewController()
        if traitCollection.userInterfaceIdiom == .pad {
            settings.modalPresentationStyle = .popover
            settings.popoverPresentationController?.sourceView = sourceView
            settings.popoverPresentationController?.sourceRect = sourceView.bounds
            settings.popoverPresentationController?.permittedArrowDirections = [.up, .down]
        } else {
            settings.modalPresentationStyle = .formSheet
            if #available(iOS 15.0, *) {
                settings.sheetPresentationController?.detents = [.medium()]
                settings.sheetPresentationController?.prefersGrabberVisible = true
            }
        }
        present(settings, animated: true)
    }
}

private extension NSLayoutConstraint {
    func withPriority(_ priority: UILayoutPriority) -> NSLayoutConstraint {
        self.priority = priority
        return self
    }
}
