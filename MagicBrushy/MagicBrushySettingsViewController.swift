import UIKit

/// Background music volume and other app preferences.
final class MagicBrushySettingsViewController: UIViewController {

    private let cardView = UIView()
    private let titleLabel = UILabel()
    private let musicRow = UIStackView()
    private let musicIcon = UIImageView()
    private let musicSlider = UISlider()

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.black.withAlphaComponent(0.35)
        preferredContentSize = CGSize(width: 320, height: 168)

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

        let musicCaption = UILabel()
        musicCaption.translatesAutoresizingMaskIntoConstraints = false
        musicCaption.text = "Background music"
        musicCaption.textColor = FigmaTheme.creamText.withAlphaComponent(0.92)
        musicCaption.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)

        musicRow.addArrangedSubview(musicIcon)
        musicRow.addArrangedSubview(musicSlider)

        cardView.addSubview(titleLabel)
        cardView.addSubview(musicCaption)
        cardView.addSubview(musicRow)
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
            musicRow.bottomAnchor.constraint(equalTo: cardView.bottomAnchor, constant: -22),

            musicIcon.widthAnchor.constraint(equalToConstant: 28),
            musicIcon.heightAnchor.constraint(equalToConstant: 28),
        ])

        syncMusicControlsFromStorage()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        syncMusicControlsFromStorage()
    }

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
