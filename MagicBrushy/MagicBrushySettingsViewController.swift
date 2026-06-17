import UIKit

/// Background music volume and other app preferences.
final class MagicBrushySettingsViewController: UIViewController {

    private let scrollView = UIScrollView()
    private let cardView = UIView()
    private let titleLabel = UILabel()

    private let brushiSectionStack = UIStackView()
    private let brushiResponsesCaption = UILabel()
    private let brushiResponsesToggleRow = UIStackView()
    private let brushiResponsesLabel = UILabel()
    private let brushiResponsesSwitch = UISwitch()
    private let brushiDownloadRow = UIStackView()
    private let brushiDownloadIcon = UIImageView()
    private let brushiDownloadButton = UIButton(type: .system)
    private let brushiLanguageCaption = UILabel()
    private let brushiLanguageRow = UIStackView()
    private let brushiVoiceCaption = UILabel()
    private let brushiVoiceRow = UIStackView()

    private let musicRow = UIStackView()
    private let musicIcon = UIImageView()
    private let musicSlider = UISlider()
    private let coachVoiceButton = UIButton(type: .system)
    private let languageButton = UIButton(type: .system)
    private let privacyButton = UIButton(type: .system)
    private let termsButton = UIButton(type: .system)
    private var intelligenceLoadObserver: NSObjectProtocol?

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.black.withAlphaComponent(0.35)

        scrollView.translatesAutoresizingMaskIntoConstraints = false
        scrollView.alwaysBounceVertical = true
        scrollView.showsVerticalScrollIndicator = true
        scrollView.backgroundColor = .clear
        scrollView.keyboardDismissMode = .onDrag
        scrollView.contentInsetAdjustmentBehavior = .never
        scrollView.indicatorStyle = .white

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

        configureBrushiSection()
        configureMusicSection()
        configureLegalSection()

        cardView.addSubview(titleLabel)
        cardView.addSubview(brushiSectionStack)
        cardView.addSubview(musicCaption)
        cardView.addSubview(musicRow)
        cardView.addSubview(legalCaption)
        cardView.addSubview(legalRow)
        scrollView.addSubview(cardView)
        view.addSubview(scrollView)

        let cardWidth = cardView.widthAnchor.constraint(equalToConstant: 320)
        cardWidth.priority = .required

        NSLayoutConstraint.activate([
            scrollView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: 8),
            scrollView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            scrollView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.safeAreaLayoutGuide.bottomAnchor, constant: -8),

            scrollView.contentLayoutGuide.widthAnchor.constraint(equalTo: scrollView.frameLayoutGuide.widthAnchor),

            cardView.topAnchor.constraint(equalTo: scrollView.contentLayoutGuide.topAnchor, constant: 16),
            cardView.bottomAnchor.constraint(equalTo: scrollView.contentLayoutGuide.bottomAnchor, constant: -28),
            cardView.centerXAnchor.constraint(equalTo: scrollView.frameLayoutGuide.centerXAnchor),
            cardWidth,
            cardView.leadingAnchor.constraint(greaterThanOrEqualTo: scrollView.frameLayoutGuide.leadingAnchor, constant: 16),
            cardView.trailingAnchor.constraint(lessThanOrEqualTo: scrollView.frameLayoutGuide.trailingAnchor, constant: -16),

            titleLabel.topAnchor.constraint(equalTo: cardView.topAnchor, constant: 20),
            titleLabel.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            titleLabel.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            brushiSectionStack.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 18),
            brushiSectionStack.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            brushiSectionStack.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            musicCaption.topAnchor.constraint(equalTo: brushiSectionStack.bottomAnchor, constant: 18),
            musicCaption.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            musicCaption.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            musicRow.topAnchor.constraint(equalTo: musicCaption.bottomAnchor, constant: 10),
            musicRow.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            musicRow.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            musicIcon.widthAnchor.constraint(equalToConstant: 28),
            musicIcon.heightAnchor.constraint(equalToConstant: 28),

            legalCaption.topAnchor.constraint(equalTo: musicRow.bottomAnchor, constant: 18),
            legalCaption.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            legalCaption.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),

            legalRow.topAnchor.constraint(equalTo: legalCaption.bottomAnchor, constant: 10),
            legalRow.leadingAnchor.constraint(equalTo: cardView.leadingAnchor, constant: 20),
            legalRow.trailingAnchor.constraint(equalTo: cardView.trailingAnchor, constant: -20),
            legalRow.bottomAnchor.constraint(equalTo: cardView.bottomAnchor, constant: -28),

            privacyButton.heightAnchor.constraint(equalToConstant: 38),
            termsButton.heightAnchor.constraint(equalToConstant: 38),
        ])

        syncMusicControlsFromStorage()
        syncBrushiSection()

        intelligenceLoadObserver = NotificationCenter.default.addObserver(
            forName: .leapVLMLoadPanelStateDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            self?.syncBrushiSection()
        }

        let dismissTap = UITapGestureRecognizer(target: self, action: #selector(dismissFromBackgroundTap(_:)))
        dismissTap.delegate = self
        view.addGestureRecognizer(dismissTap)
    }

    private lazy var musicCaption = makeCaption("Background music")
    private lazy var legalCaption = makeCaption("Parents & legal")
    private lazy var legalRow: UIStackView = {
        configureLegalButton(privacyButton, title: "Privacy Policy")
        configureLegalButton(termsButton, title: "Terms of Use")
        privacyButton.addTarget(self, action: #selector(openPrivacyPolicy), for: .touchUpInside)
        termsButton.addTarget(self, action: #selector(openTermsOfUse), for: .touchUpInside)
        let row = UIStackView(arrangedSubviews: [privacyButton, termsButton])
        row.axis = .horizontal
        row.alignment = .fill
        row.distribution = .fillEqually
        row.spacing = 10
        row.translatesAutoresizingMaskIntoConstraints = false
        return row
    }()

    // MARK: - Brushi section

    private func configureBrushiSection() {
        brushiSectionStack.axis = .vertical
        brushiSectionStack.spacing = 10
        brushiSectionStack.alignment = .fill
        brushiSectionStack.translatesAutoresizingMaskIntoConstraints = false

        brushiResponsesCaption.translatesAutoresizingMaskIntoConstraints = false
        brushiResponsesCaption.text = "Brushi Responses"
        brushiResponsesCaption.textColor = FigmaTheme.creamText
        brushiResponsesCaption.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)

        brushiResponsesLabel.translatesAutoresizingMaskIntoConstraints = false
        brushiResponsesLabel.text = "Brushi Responses"
        brushiResponsesLabel.textColor = FigmaTheme.creamText
        brushiResponsesLabel.font = FigmaTheme.bodyFont(size: 16, weight: .semibold)
        brushiResponsesLabel.numberOfLines = 2

        brushiResponsesSwitch.translatesAutoresizingMaskIntoConstraints = false
        brushiResponsesSwitch.onTintColor = FigmaTheme.primaryOrange
        brushiResponsesSwitch.addTarget(self, action: #selector(brushiResponsesSwitchChanged), for: .valueChanged)
        brushiResponsesSwitch.accessibilityLabel = "Brushi Responses"

        brushiResponsesToggleRow.axis = .horizontal
        brushiResponsesToggleRow.alignment = .center
        brushiResponsesToggleRow.spacing = 12
        brushiResponsesToggleRow.translatesAutoresizingMaskIntoConstraints = false
        brushiResponsesToggleRow.addArrangedSubview(brushiResponsesLabel)
        brushiResponsesToggleRow.addArrangedSubview(brushiResponsesSwitch)

        brushiDownloadIcon.translatesAutoresizingMaskIntoConstraints = false
        brushiDownloadIcon.image = UIImage(systemName: "sparkles")
        brushiDownloadIcon.tintColor = FigmaTheme.primaryOrange
        brushiDownloadIcon.contentMode = .scaleAspectFit
        brushiDownloadIcon.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 20, weight: .semibold)
        brushiDownloadIcon.setContentHuggingPriority(.required, for: .horizontal)

        brushiDownloadButton.translatesAutoresizingMaskIntoConstraints = false
        brushiDownloadButton.titleLabel?.font = FigmaTheme.bodyFont(size: 16, weight: .bold)
        brushiDownloadButton.titleLabel?.numberOfLines = 2
        brushiDownloadButton.titleLabel?.adjustsFontSizeToFitWidth = true
        brushiDownloadButton.titleLabel?.minimumScaleFactor = 0.85
        brushiDownloadButton.setTitleColor(UIColor(white: 0.12, alpha: 1), for: .normal)
        brushiDownloadButton.setTitleColor(UIColor(white: 0.12, alpha: 0.55), for: .disabled)
        brushiDownloadButton.backgroundColor = FigmaTheme.primaryOrange
        brushiDownloadButton.layer.cornerRadius = 10
        if #available(iOS 13.0, *) { brushiDownloadButton.layer.cornerCurve = .continuous }
        brushiDownloadButton.contentHorizontalAlignment = .center
        brushiDownloadButton.titleEdgeInsets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
        brushiDownloadButton.accessibilityLabel = "Download Brushi"
        brushiDownloadButton.accessibilityHint = "Downloads Brushi for on-device reactions to colors and drawings."
        brushiDownloadButton.addTarget(self, action: #selector(brushiDownloadTapped), for: .touchUpInside)

        brushiDownloadRow.axis = .horizontal
        brushiDownloadRow.alignment = .center
        brushiDownloadRow.spacing = 10
        brushiDownloadRow.translatesAutoresizingMaskIntoConstraints = false
        brushiDownloadRow.addArrangedSubview(brushiDownloadIcon)
        brushiDownloadRow.addArrangedSubview(brushiDownloadButton)

        brushiLanguageCaption.translatesAutoresizingMaskIntoConstraints = false
        brushiLanguageCaption.text = "Brushi Language"
        brushiLanguageCaption.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)

        let langIconView = makeOrangeSymbolIcon("globe")
        configurePickerButton(languageButton, accessibilityLabel: "Brushi Language", hint: "Choose the language Brushi speaks in.")
        setupLanguageMenu()
        brushiLanguageRow.axis = .horizontal
        brushiLanguageRow.alignment = .center
        brushiLanguageRow.spacing = 10
        brushiLanguageRow.translatesAutoresizingMaskIntoConstraints = false
        brushiLanguageRow.addArrangedSubview(langIconView)
        brushiLanguageRow.addArrangedSubview(languageButton)

        brushiVoiceCaption.translatesAutoresizingMaskIntoConstraints = false
        brushiVoiceCaption.text = "Brushi Voice"
        brushiVoiceCaption.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)

        let voiceIconView = makeOrangeSymbolIcon("waveform")
        configurePickerButton(coachVoiceButton, accessibilityLabel: "Brushi Voice", hint: "Offline English voices or the device voice. Plays a short preview when you pick one.")
        setupCoachVoiceMenu()
        brushiVoiceRow.axis = .horizontal
        brushiVoiceRow.alignment = .center
        brushiVoiceRow.spacing = 10
        brushiVoiceRow.translatesAutoresizingMaskIntoConstraints = false
        brushiVoiceRow.addArrangedSubview(voiceIconView)
        brushiVoiceRow.addArrangedSubview(coachVoiceButton)

        brushiSectionStack.addArrangedSubview(brushiResponsesCaption)
        brushiSectionStack.addArrangedSubview(brushiResponsesToggleRow)
        brushiSectionStack.addArrangedSubview(brushiDownloadRow)
        brushiSectionStack.addArrangedSubview(brushiLanguageCaption)
        brushiSectionStack.addArrangedSubview(brushiLanguageRow)
        brushiSectionStack.addArrangedSubview(brushiVoiceCaption)
        brushiSectionStack.addArrangedSubview(brushiVoiceRow)

        NSLayoutConstraint.activate([
            brushiDownloadIcon.widthAnchor.constraint(equalToConstant: 28),
            brushiDownloadIcon.heightAnchor.constraint(equalToConstant: 28),
            brushiDownloadButton.heightAnchor.constraint(greaterThanOrEqualToConstant: 44),
            langIconView.widthAnchor.constraint(equalToConstant: 28),
            langIconView.heightAnchor.constraint(equalToConstant: 28),
            voiceIconView.widthAnchor.constraint(equalToConstant: 28),
            voiceIconView.heightAnchor.constraint(equalToConstant: 28),
            languageButton.heightAnchor.constraint(equalToConstant: 38),
            coachVoiceButton.heightAnchor.constraint(equalToConstant: 38),
        ])
    }

    private func configureMusicSection() {
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

        musicRow.addArrangedSubview(musicIcon)
        musicRow.addArrangedSubview(musicSlider)
    }

    private func configureLegalSection() {}

    private func syncBrushiSection() {
        let vlm = LeapVLMModel.shared
        let responsesOn = MagicBrushyCoachAutoFeedback.isEnabled
        let downloaded = isBrushiReadyForResponses(vlm.modelBadgeState)

        brushiResponsesSwitch.isOn = responsesOn
        brushiResponsesSwitch.accessibilityValue = responsesOn ? "On" : "Off"

        brushiResponsesCaption.isHidden = downloaded
        brushiResponsesToggleRow.isHidden = !downloaded
        brushiLanguageCaption.isHidden = !downloaded
        brushiLanguageRow.isHidden = !downloaded
        brushiVoiceCaption.isHidden = !downloaded
        brushiVoiceRow.isHidden = !downloaded
        brushiDownloadRow.isHidden = downloaded

        if downloaded {
            applyBrushiDependentControlsEnabled(responsesOn)
        } else {
            syncBrushiDownloadButton(for: vlm.modelBadgeState)
        }
    }

    private func isBrushiReadyForResponses(_ state: LeapVLMModel.ModelBadgeState) -> Bool {
        if case .ready = state { return true }
        return false
    }

    private func syncBrushiDownloadButton(for state: LeapVLMModel.ModelBadgeState) {
        switch state {
        case .ready:
            break
        case .downloading(let progress):
            let pct = Int((progress * 100).rounded(.down))
            brushiDownloadButton.setTitle(
                pct > 0 ? "Downloading… \(pct)%" : "Downloading…",
                for: .normal
            )
            brushiDownloadButton.isEnabled = false
            brushiDownloadButton.accessibilityValue = pct > 0 ? "Downloading, \(pct) percent" : "Downloading"
        case .loadingIntoMemory:
            brushiDownloadButton.setTitle("Loading Brushi…", for: .normal)
            brushiDownloadButton.isEnabled = false
            brushiDownloadButton.accessibilityValue = "Loading"
        case .failed:
            brushiDownloadButton.setTitle("Try Again — \(MagicBrushyVLMConsent.downloadSizeString)", for: .normal)
            brushiDownloadButton.isEnabled = true
            brushiDownloadButton.accessibilityValue = "Download failed"
        case .simulatorPreview:
            brushiDownloadButton.setTitle("Available on Device Only", for: .normal)
            brushiDownloadButton.isEnabled = false
            brushiDownloadButton.accessibilityValue = "Simulator"
        case .downloadDeclined, .idleNotLoaded:
            brushiDownloadButton.setTitle("Download Now — \(MagicBrushyVLMConsent.downloadSizeString)", for: .normal)
            brushiDownloadButton.isEnabled = true
            brushiDownloadButton.accessibilityValue = "Not downloaded — \(MagicBrushyVLMConsent.downloadSizeString)"
        }
    }

    private func applyBrushiDependentControlsEnabled(_ enabled: Bool) {
        let subCaptionAlpha: CGFloat = enabled ? 0.72 : 0.42
        let controlAlpha: CGFloat = enabled ? 1 : 0.42

        brushiLanguageCaption.textColor = FigmaTheme.creamText.withAlphaComponent(subCaptionAlpha)
        brushiVoiceCaption.textColor = FigmaTheme.creamText.withAlphaComponent(subCaptionAlpha)
        brushiLanguageRow.alpha = controlAlpha
        brushiVoiceRow.alpha = controlAlpha

        languageButton.isEnabled = enabled
        if enabled {
            syncCoachVoiceForCurrentLanguage()
        } else {
            coachVoiceButton.isEnabled = false
            coachVoiceButton.menu = nil
            coachVoiceButton.showsMenuAsPrimaryAction = false
        }
    }

    @objc private func brushiResponsesSwitchChanged(_ sender: UISwitch) {
        MagicBrushyCoachAutoFeedback.isEnabled = sender.isOn
        syncBrushiSection()
    }

    @objc private func brushiDownloadTapped() {
        let vlm = LeapVLMModel.shared
        if case .ready = vlm.modelBadgeState { return }
        if vlm.isModelLoadPanelVisible, !vlm.modelLoadDidFail { return }

        MagicBrushyParentalGate.perform(
            from: self,
            title: "Grown-ups only",
            messagePrefix: MagicBrushyVLMConsent.parentalGateDownloadPrefix
        ) {
            MagicBrushyVLMConsent.markAccepted()
            self.syncBrushiSection()
            Task { @MainActor in
                await LeapVLMModel.shared.load()
                self.syncBrushiSection()
            }
        }
    }

    @objc private func dismissFromBackgroundTap(_ recognizer: UITapGestureRecognizer) {
        let pt = recognizer.location(in: view)
        let cardFrameInView = cardView.convert(cardView.bounds, to: view)
        guard !cardFrameInView.contains(pt) else { return }
        dismiss(animated: true)
    }

    deinit {
        if let intelligenceLoadObserver {
            NotificationCenter.default.removeObserver(intelligenceLoadObserver)
        }
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        if traitCollection.userInterfaceIdiom == .pad {
            preferredContentSize = CGSize(width: 320, height: 520)
        }
        syncMusicControlsFromStorage()
        syncCoachVoiceForCurrentLanguage()
        syncBrushiSection()
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

    // MARK: - Coach voice

    private func syncCoachVoiceForCurrentLanguage() {
        guard MagicBrushyCoachAutoFeedback.isEnabled else { return }
        let lang = MagicBrushyLanguage.stored()
        MagicBrushyCoachVoice.applyLanguageChange(lang)
        updateCoachVoiceButtonTitle(MagicBrushyCoachVoice.stored())
        setupCoachVoiceMenu()
        let englishOnly = lang != .english
        coachVoiceButton.isEnabled = !englishOnly
        coachVoiceButton.alpha = englishOnly ? 0.72 : 1
        coachVoiceButton.accessibilityHint = englishOnly
            ? "Offline English voices are only available when Brushi language is English."
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
        let sheet = UIAlertController(title: "Brushi voice", message: nil, preferredStyle: .actionSheet)
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
                    self?.syncBrushiSection()
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
        let sheet = UIAlertController(title: "Brushi language", message: nil, preferredStyle: .actionSheet)
        for lang in MagicBrushyLanguage.allCases {
            let current = MagicBrushyLanguage.stored() == lang
            let action = UIAlertAction(title: (current ? "✓ " : "    ") + lang.displayName, style: .default) { [weak self] _ in
                MagicBrushyLanguage.store(lang)
                self?.updateLanguageButtonTitle(lang)
                self?.syncCoachVoiceForCurrentLanguage()
                self?.syncBrushiSection()
            }
            sheet.addAction(action)
        }
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        sheet.popoverPresentationController?.sourceView = languageButton
        present(sheet, animated: true)
    }

    // MARK: - Helpers

    private func configurePickerButton(_ button: UIButton, accessibilityLabel: String, hint: String) {
        button.translatesAutoresizingMaskIntoConstraints = false
        button.titleLabel?.font = FigmaTheme.bodyFont(size: 16, weight: .semibold)
        button.setTitleColor(FigmaTheme.creamText, for: .normal)
        button.backgroundColor = UIColor.white.withAlphaComponent(0.12)
        button.layer.cornerRadius = 10
        if #available(iOS 13.0, *) { button.layer.cornerCurve = .continuous }
        button.contentHorizontalAlignment = .left
        button.titleEdgeInsets = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
        button.accessibilityLabel = accessibilityLabel
        button.accessibilityHint = hint
    }

    private func makeOrangeSymbolIcon(_ systemName: String) -> UIImageView {
        let icon = UIImageView(image: UIImage(systemName: systemName))
        icon.translatesAutoresizingMaskIntoConstraints = false
        icon.tintColor = FigmaTheme.primaryOrange
        icon.contentMode = .scaleAspectFit
        icon.preferredSymbolConfiguration = UIImage.SymbolConfiguration(pointSize: 20, weight: .semibold)
        icon.setContentHuggingPriority(.required, for: .horizontal)
        return icon
    }

    private func configureLegalButton(_ button: UIButton, title: String) {
        button.translatesAutoresizingMaskIntoConstraints = false
        button.setTitle(title, for: .normal)
        button.titleLabel?.font = FigmaTheme.bodyFont(size: 15, weight: .semibold)
        button.setTitleColor(FigmaTheme.creamText, for: .normal)
        button.backgroundColor = UIColor.white.withAlphaComponent(0.12)
        button.layer.cornerRadius = 10
        if #available(iOS 13.0, *) { button.layer.cornerCurve = .continuous }
    }

    @objc private func openPrivacyPolicy() {
        MagicBrushyParentalGate.openExternalURL(MagicBrushyLegal.privacyPolicyURL, from: self)
    }

    @objc private func openTermsOfUse() {
        MagicBrushyParentalGate.openExternalURL(MagicBrushyLegal.termsOfUseURL, from: self)
    }

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

/// Orange nav chrome (matches home) on home / grid / coloring screens.
final class MagicBrushySettingsGearButton: UIButton {

    private var widthConstraint: NSLayoutConstraint!
    private var heightConstraint: NSLayoutConstraint!

    init() {
        super.init(frame: .zero)
        translatesAutoresizingMaskIntoConstraints = false
        configuration = .plain()
        setContentCompressionResistancePriority(.required, for: .horizontal)
        setContentCompressionResistancePriority(.required, for: .vertical)
        setContentHuggingPriority(.required, for: .horizontal)
        setContentHuggingPriority(.required, for: .vertical)
        accessibilityLabel = "Settings"
        accessibilityHint = "Background music, Brushi responses, voice, and language."
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
        MagicBrushyChromeMetrics.applyHomeNavChrome(
            to: self,
            image: MagicBrushyChromeMetrics.chromeNavSettingsImage(),
            traitCollection: traitCollection
        )
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
