import UIKit

/// Background music volume and other app preferences.
final class MagicBrushySettingsViewController: UIViewController {

    private let cardView = UIView()
    private let titleLabel = UILabel()
    private let musicRow = UIStackView()
    private let musicIcon = UIImageView()
    private let musicSlider = UISlider()
    private let coachVoiceButton = UIButton(type: .system)
    private let coachFeedbackRow = UIStackView()
    private let coachFeedbackCheckmark = UIImageView()
    private let coachFeedbackToggleButton = UIButton(type: .system)
    private let languageButton = UIButton(type: .system)

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.black.withAlphaComponent(0.35)
        preferredContentSize = CGSize(width: 320, height: 428)

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

        // MARK: Coach voice row

        let voiceCaption = makeCaption("Coach voice")
        let voiceIconView = UIImageView(image: UIImage(systemName: "waveform"))
        voiceIconView.translatesAutoresizingMaskIntoConstraints = false
        voiceIconView.tintColor = FigmaTheme.primaryOrange
        voiceIconView.contentMode = .scaleAspectFit
        voiceIconView.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 20, weight: .semibold)
        voiceIconView.setContentHuggingPriority(.required, for: .horizontal)

        coachVoiceButton.translatesAutoresizingMaskIntoConstraints = false
        coachVoiceButton.titleLabel?.font = FigmaTheme.bodyFont(size: 16, weight: .semibold)
        coachVoiceButton.setTitleColor(FigmaTheme.creamText, for: .normal)
        coachVoiceButton.backgroundColor = UIColor.white.withAlphaComponent(0.12)
        coachVoiceButton.layer.cornerRadius = 10
        if #available(iOS 13.0, *) { coachVoiceButton.layer.cornerCurve = .continuous }
        coachVoiceButton.contentHorizontalAlignment = .left
        coachVoiceButton.titleEdgeInsets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
        coachVoiceButton.accessibilityLabel = "Coach voice"
        coachVoiceButton.accessibilityHint = "Offline English voices or the device voice. Plays a short preview when you pick one."
        setupCoachVoiceMenu()

        let voiceRow = UIStackView(arrangedSubviews: [voiceIconView, coachVoiceButton])
        voiceRow.axis = .horizontal
        voiceRow.alignment = .center
        voiceRow.spacing = 10
        voiceRow.translatesAutoresizingMaskIntoConstraints = false

        // MARK: Coach feedback toggle

        let feedbackCaption = makeCaption("Coach feedback")
        let feedbackIconView = UIImageView(image: UIImage(systemName: "bubble.left.and.bubble.right.fill"))
        feedbackIconView.translatesAutoresizingMaskIntoConstraints = false
        feedbackIconView.tintColor = FigmaTheme.primaryOrange
        feedbackIconView.contentMode = .scaleAspectFit
        feedbackIconView.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 20, weight: .semibold)
        feedbackIconView.setContentHuggingPriority(.required, for: .horizontal)

        let feedbackLabel = UILabel()
        feedbackLabel.translatesAutoresizingMaskIntoConstraints = false
        feedbackLabel.text = "Automatic tips while coloring"
        feedbackLabel.textColor = FigmaTheme.creamText
        feedbackLabel.font = FigmaTheme.bodyFont(size: 16, weight: .semibold)
        feedbackLabel.numberOfLines = 2

        coachFeedbackCheckmark.translatesAutoresizingMaskIntoConstraints = false
        coachFeedbackCheckmark.tintColor = FigmaTheme.primaryOrange
        coachFeedbackCheckmark.contentMode = .scaleAspectFit
        coachFeedbackCheckmark.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 22, weight: .bold)
        coachFeedbackCheckmark.setContentHuggingPriority(.required, for: .horizontal)
        coachFeedbackCheckmark.setContentCompressionResistancePriority(.required, for: .horizontal)
        coachFeedbackCheckmark.isAccessibilityElement = false

        coachFeedbackToggleButton.translatesAutoresizingMaskIntoConstraints = false
        coachFeedbackToggleButton.backgroundColor = UIColor.white.withAlphaComponent(0.12)
        coachFeedbackToggleButton.layer.cornerRadius = 10
        if #available(iOS 13.0, *) { coachFeedbackToggleButton.layer.cornerCurve = .continuous }
        coachFeedbackToggleButton.addTarget(self, action: #selector(coachFeedbackToggleTapped), for: .touchUpInside)
        coachFeedbackToggleButton.accessibilityLabel = "Coach feedback"
        coachFeedbackToggleButton.accessibilityHint = "Turns automatic spoken tips on or off while you color."

        let feedbackTextStack = UIStackView(arrangedSubviews: [feedbackLabel])
        feedbackTextStack.axis = .vertical
        feedbackTextStack.alignment = .leading

        coachFeedbackRow.axis = .horizontal
        coachFeedbackRow.alignment = .center
        coachFeedbackRow.spacing = 10
        coachFeedbackRow.translatesAutoresizingMaskIntoConstraints = false
        coachFeedbackRow.isLayoutMarginsRelativeArrangement = true
        coachFeedbackRow.layoutMargins = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 12)
        coachFeedbackRow.addArrangedSubview(feedbackIconView)
        coachFeedbackRow.addArrangedSubview(feedbackTextStack)
        coachFeedbackRow.addArrangedSubview(coachFeedbackCheckmark)
        coachFeedbackRow.isUserInteractionEnabled = false
        feedbackIconView.isUserInteractionEnabled = false
        feedbackLabel.isUserInteractionEnabled = false
        feedbackTextStack.isUserInteractionEnabled = false
        coachFeedbackCheckmark.isUserInteractionEnabled = false
        coachFeedbackToggleButton.addSubview(coachFeedbackRow)
        NSLayoutConstraint.activate([
            coachFeedbackRow.topAnchor.constraint(equalTo: coachFeedbackToggleButton.topAnchor),
            coachFeedbackRow.leadingAnchor.constraint(equalTo: coachFeedbackToggleButton.leadingAnchor),
            coachFeedbackRow.trailingAnchor.constraint(equalTo: coachFeedbackToggleButton.trailingAnchor),
            coachFeedbackRow.bottomAnchor.constraint(equalTo: coachFeedbackToggleButton.bottomAnchor),
        ])

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
        cardView.addSubview(voiceCaption)
        cardView.addSubview(voiceRow)
        cardView.addSubview(feedbackCaption)
        cardView.addSubview(coachFeedbackToggleButton)
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

            voiceCaption.topAnchor.constraint(equalTo: musicRow.bottomAnchor, constant: 16),
            voiceCaption.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            voiceCaption.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            voiceRow.topAnchor.constraint(equalTo: voiceCaption.bottomAnchor, constant: 10),
            voiceRow.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            voiceRow.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            voiceIconView.widthAnchor.constraint(equalToConstant: 28),
            voiceIconView.heightAnchor.constraint(equalToConstant: 28),
            coachVoiceButton.heightAnchor.constraint(equalToConstant: 38),

            feedbackCaption.topAnchor.constraint(equalTo: voiceRow.bottomAnchor, constant: 16),
            feedbackCaption.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            feedbackCaption.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            coachFeedbackToggleButton.topAnchor.constraint(equalTo: feedbackCaption.bottomAnchor, constant: 10),
            coachFeedbackToggleButton.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            coachFeedbackToggleButton.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),
            coachFeedbackToggleButton.heightAnchor.constraint(greaterThanOrEqualToConstant: 44),

            feedbackIconView.widthAnchor.constraint(equalToConstant: 28),
            feedbackIconView.heightAnchor.constraint(equalToConstant: 28),
            coachFeedbackCheckmark.widthAnchor.constraint(equalToConstant: 26),
            coachFeedbackCheckmark.heightAnchor.constraint(equalToConstant: 26),

            divider.topAnchor.constraint(equalTo: coachFeedbackToggleButton.bottomAnchor, constant: 18),
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
        syncCoachFeedbackControls()

        let dismissTap = UITapGestureRecognizer(target: self, action: #selector(dismissFromBackgroundTap(_:)))
        dismissTap.delegate = self
        view.addGestureRecognizer(dismissTap)
    }

    @objc private func dismissFromBackgroundTap(_ recognizer: UITapGestureRecognizer) {
        let pt = recognizer.location(in: view)
        guard !cardView.frame.contains(pt) else { return }
        dismiss(animated: true)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        syncMusicControlsFromStorage()
        syncCoachFeedbackControls()
        syncCoachVoiceForCurrentLanguage()
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

    // MARK: - Coach feedback

    private func syncCoachFeedbackControls() {
        let on = MagicBrushyCoachAutoFeedback.isEnabled
        coachFeedbackCheckmark.image = UIImage(systemName: on ? "checkmark.circle.fill" : "circle")
        coachFeedbackToggleButton.accessibilityValue = on ? "On" : "Off"
    }

    @objc private func coachFeedbackToggleTapped() {
        let next = !MagicBrushyCoachAutoFeedback.isEnabled
        MagicBrushyCoachAutoFeedback.isEnabled = next
        syncCoachFeedbackControls()
    }

    // MARK: - Coach voice

    private func syncCoachVoiceForCurrentLanguage() {
        let lang = MagicBrushyLanguage.stored()
        MagicBrushyCoachVoice.applyLanguageChange(lang)
        updateCoachVoiceButtonTitle(MagicBrushyCoachVoice.stored())
        setupCoachVoiceMenu()
        let englishOnly = lang != .english
        coachVoiceButton.isEnabled = !englishOnly
        coachVoiceButton.alpha = englishOnly ? 0.72 : 1
        coachVoiceButton.accessibilityHint = englishOnly
            ? "Offline English voices are only available when response language is English."
            : "Offline English voices or the device voice. Plays a short preview when you pick one."
    }

    private func setupCoachVoiceMenu() {
        let lang = MagicBrushyLanguage.stored()
        updateCoachVoiceButtonTitle(MagicBrushyCoachVoice.stored())
        let voices = MagicBrushyCoachVoice.selectableCases(for: lang)

        if #available(iOS 14.0, *) {
            let actions = voices.map { voice in
                UIAction(title: voice.displayName, state: MagicBrushyCoachVoice.stored() == voice ? .on : .off) { [weak self] _ in
                    MagicBrushyCoachVoice.store(voice)
                    self?.updateCoachVoiceButtonTitle(voice)
                    self?.setupCoachVoiceMenu()
                    Task { @MainActor in
                        await FeedbackAlbaSpeech.speakFeedback(MagicBrushyCoachVoice.previewPhrase)
                    }
                }
            }
            coachVoiceButton.menu = UIMenu(title: "", children: actions)
            coachVoiceButton.showsMenuAsPrimaryAction = lang == .english
        } else {
            coachVoiceButton.addTarget(self, action: #selector(coachVoiceButtonTapped), for: .touchUpInside)
        }
    }

    private func updateCoachVoiceButtonTitle(_ voice: MagicBrushyCoachVoice) {
        coachVoiceButton.setTitle("  \(voice.displayName)", for: .normal)
    }

    @objc private func coachVoiceButtonTapped() {
        let lang = MagicBrushyLanguage.stored()
        guard lang == .english else { return }
        let sheet = UIAlertController(title: "Coach voice", message: nil, preferredStyle: .actionSheet)
        for voice in MagicBrushyCoachVoice.selectableCases(for: lang) {
            let current = MagicBrushyCoachVoice.stored() == voice
            let action = UIAlertAction(title: (current ? "✓ " : "    ") + voice.displayName, style: .default) { [weak self] _ in
                MagicBrushyCoachVoice.store(voice)
                self?.updateCoachVoiceButtonTitle(voice)
                Task { @MainActor in
                    await FeedbackAlbaSpeech.speakFeedback(MagicBrushyCoachVoice.previewPhrase)
                }
            }
            sheet.addAction(action)
        }
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        sheet.popoverPresentationController?.sourceView = coachVoiceButton
        present(sheet, animated: true)
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
                    self?.syncCoachVoiceForCurrentLanguage()
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
                self?.syncCoachVoiceForCurrentLanguage()
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

extension MagicBrushySettingsViewController: UIGestureRecognizerDelegate, UIPopoverPresentationControllerDelegate {
    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldReceive touch: UITouch) -> Bool {
        let pt = touch.location(in: view)
        return !cardView.frame.contains(pt)
    }

    func adaptivePresentationStyle(for controller: UIPresentationController) -> UIModalPresentationStyle {
        .none
    }
}

// MARK: - Gear button + presentation

/// Blue gear chrome matching nav controls on home / grid / coloring screens.
final class MagicBrushySettingsGearButton: UIButton {

    private var widthConstraint: NSLayoutConstraint!
    private var heightConstraint: NSLayoutConstraint!

    init() {
        super.init(frame: .zero)
        var cfg = UIButton.Configuration.plain()
        cfg.image = UIImage(systemName: "gearshape.fill")
        cfg.baseForegroundColor = .white
        configuration = cfg
        translatesAutoresizingMaskIntoConstraints = false
        accessibilityLabel = "Settings"
        accessibilityHint = "Background music, coach feedback, voice, and language."
        widthConstraint = widthAnchor.constraint(equalToConstant: 52)
        heightConstraint = heightAnchor.constraint(equalToConstant: 52)
        NSLayoutConstraint.activate([widthConstraint, heightConstraint])
    }

    @available(*, unavailable)
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func applyStyle(for traitCollection: UITraitCollection) {
        let side = MagicBrushyChromeMetrics.chromeButtonSide(traitCollection)
        widthConstraint.constant = side
        heightConstraint.constant = side
        MagicBrushyChromeMetrics.applySquareChrome(
            to: self,
            fill: FigmaTheme.actionBlue,
            border: FigmaTheme.actionBlueBorder,
            traitCollection: traitCollection,
            contentInsets: MagicBrushyChromeMetrics.navChromeContentInsets
        )
        var cfg = configuration ?? UIButton.Configuration.plain()
        cfg.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(
            pointSize: MagicBrushyChromeMetrics.chromeSymbolPointSize(traitCollection),
            weight: .bold
        )
        configuration = cfg
    }
}

extension UIViewController {

    /// Chrome gear button; call `applyStyle(for:)` from `traitCollectionDidChange` on each screen.
    func makeMagicBrushySettingsGearButton() -> MagicBrushySettingsGearButton {
        let b = MagicBrushySettingsGearButton()
        b.addTarget(self, action: #selector(magicBrushySettingsGearTapped(_:)), for: .touchUpInside)
        b.applyStyle(for: traitCollection)
        return b
    }

    @objc func magicBrushySettingsGearTapped(_ sender: UIButton) {
        presentMagicBrushySettings(from: sender)
    }

    func presentMagicBrushySettings(from sourceView: UIView) {
        let settings = MagicBrushySettingsViewController()
        if traitCollection.userInterfaceIdiom == .pad {
            settings.modalPresentationStyle = .popover
            let popover = settings.popoverPresentationController
            popover?.sourceView = sourceView
            popover?.sourceRect = sourceView.bounds
            popover?.permittedArrowDirections = [.up, .down]
            popover?.delegate = settings
        } else {
            settings.modalPresentationStyle = .overFullScreen
            settings.modalTransitionStyle = .crossDissolve
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
