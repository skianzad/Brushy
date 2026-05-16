import AVFoundation

/// Reads feedback aloud with bundled Piper Alba (Sherpa ONNX, same bundle layout as SmartDraw), then falls back to system en-GB.
enum FeedbackAlbaSpeech {

    /// Optional mascot mouth driver (set from `ColoringViewController`).
    @MainActor static weak var mascotLipSync: MascotLipSyncDriver?

    nonisolated static func stripEmojis(_ s: String) -> String {
        s.unicodeScalars
            .filter { scalar in
                let v = scalar.value
                if v <= 0x007E { return true }
                if v >= 0x00A0 && v <= 0x024F { return true }
                if v >= 0x1F600 && v <= 0x1F64F { return false }
                if v >= 0x1F300 && v <= 0x1F5FF { return false }
                if v >= 0x1F680 && v <= 0x1F6FF { return false }
                if v >= 0x1F900 && v <= 0x1F9FF { return false }
                if v >= 0x2600 && v <= 0x26FF { return false }
                if v >= 0x2700 && v <= 0x27BF { return false }
                if v >= 0xFE00 && v <= 0xFE0F { return false }
                if v == 0x200D { return false }
                return true
            }
            .map(Character.init)
            .reduce(into: "") { $0.append($1) }
            .trimmingCharacters(in: .whitespacesAndNewlines)
    }

    @MainActor
    static func speakFeedback(_ raw: String) async {
        let clean = stripEmojis(raw)
        guard !clean.isEmpty else { return }

        stopSpeaking()
        MagicBrushyBackgroundMusic.duckForMascotSpeech()
        defer { MagicBrushyBackgroundMusic.restoreVolumeAfterMascotSpeech() }

        let lang = MagicBrushyLanguage.stored()

        // Piper Alba is English-only — use it only when English is selected.
        if lang.usesPiperAlba, SherpaPiperAlbaVoice.isBundledVoiceAvailable {
            do {
                try await SherpaPiperAlbaVoice.speakAlbaBritishEnglish(clean) { text, duration in
                    Self.mascotLipSync?.startSherpaDrivenLipSync(text: text, duration: duration)
                }
            } catch {}
            Self.mascotLipSync?.sessionEnded()
            return
        }

        // All other languages (and English fallback) go through Apple TTS
        // with the matching voice for the selected language.
        await AppleFeedbackSynth.shared.speak(clean, languageTag: lang.bcp47Tag)
    }

    @MainActor
    static func stopSpeaking() {
        Self.mascotLipSync?.sessionEnded()
        SherpaVLMPlayback.stopPlayback()
        AppleFeedbackSynth.shared.stop()
        MagicBrushyBackgroundMusic.restoreVolumeAfterMascotSpeech()
    }

    /// Single shared synth so `stopSpeaking` can interrupt Apple fallback playback.
    @MainActor
    private final class AppleFeedbackSynth: NSObject, AVSpeechSynthesizerDelegate {
        static let shared = AppleFeedbackSynth()

        private let synth = AVSpeechSynthesizer()
        private var speakContinuation: CheckedContinuation<Void, Never>?

        private override init() {
            super.init()
            synth.delegate = self
        }

        func stop() {
            synth.stopSpeaking(at: .immediate)
            if let c = speakContinuation {
                speakContinuation = nil
                c.resume()
            }
        }

        func speak(_ text: String, languageTag: String = "en-GB") async {
            guard !text.isEmpty else { return }
            stop()
            FeedbackAlbaSpeech.mascotLipSync?.startAppleDrivenLipSync()
            let voice = Self.preferredVoice(for: languageTag)

            await withCheckedContinuation { (cont: CheckedContinuation<Void, Never>) in
                self.speakContinuation = cont
                let u = AVSpeechUtterance(string: text)
                u.voice = voice
                // Slightly slower than default → more relaxed, less mechanical.
                u.rate = AVSpeechUtteranceDefaultSpeechRate * 0.86
                // Raising pitch makes the voice brighter and warmer — closer to a
                // child-friendly tone without sounding cartoonish (range 0.5–2.0).
                u.pitchMultiplier = 1.18
                // A touch below full volume keeps the delivery soft and friendly.
                u.volume = 0.92
                synth.speak(u)
            }
        }

        func speechSynthesizer(
            _ synthesizer: AVSpeechSynthesizer,
            willSpeakRangeOfSpeechString characterRange: NSRange,
            utterance: AVSpeechUtterance
        ) {
            let s = utterance.speechString as NSString
            guard characterRange.location != NSNotFound, characterRange.length > 0 else { return }
            let sub = s.substring(with: characterRange)
            FeedbackAlbaSpeech.mascotLipSync?.appleWillSpeak(substring: sub)
        }

        func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didFinish utterance: AVSpeechUtterance) {
            FeedbackAlbaSpeech.mascotLipSync?.sessionEnded()
            guard let c = speakContinuation else { return }
            speakContinuation = nil
            c.resume()
        }

        func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didCancel utterance: AVSpeechUtterance) {
            FeedbackAlbaSpeech.mascotLipSync?.sessionEnded()
            guard let c = speakContinuation else { return }
            speakContinuation = nil
            c.resume()
        }

        /// Best available voice for the given BCP-47 language tag.
        /// Prefers Premium > Enhanced > Default quality, skips Siri voices (they can misbehave),
        /// and within each quality tier picks warmer-sounding (typically female) voices for kids.
        private static func preferredVoice(for languageTag: String) -> AVSpeechSynthesisVoice? {
            let all = AVSpeechSynthesisVoice.speechVoices()
                .filter { !$0.name.lowercased().contains("siri") }

            // Match exact tag first, then 2-letter language prefix.
            let exact = all.filter { $0.language == languageTag }
            let prefix = String(languageTag.prefix(2))
            let candidates = exact.isEmpty ? all.filter { $0.language.hasPrefix(prefix) } : exact
            guard !candidates.isEmpty else {
                return AVSpeechSynthesisVoice(language: languageTag)
            }

            // For English, prefer named British voices to keep the warm Alba character feel.
            if prefix == "en" {
                let enGB = candidates.filter { $0.language == "en-GB" }
                // Martha / Kate are the warmest enhanced GB voices on iOS 17.
                let nameOrder = ["Martha", "Kate", "Serena", "Daniel", "Arthur", "Oliver"]
                for name in nameOrder {
                    if let v = enGB.first(where: { $0.name.caseInsensitiveCompare(name) == .orderedSame }) {
                        return v
                    }
                }
                if let v = enGB.first { return v }
            }

            // Warm female-sounding voices per language — known pleasant voices for kids.
            let preferredNames: [String: [String]] = [
                "ar": ["Maged", "Layla"],
                "es": ["Monica", "Paulina", "Marisol"],
                "fr": ["Amelie", "Thomas", "Marie"],
                "de": ["Anna", "Petra", "Yannick"],
                "ja": ["Kyoko", "O-ren"],
                "ko": ["Yuna", "Sora"],
                "zh": ["Ting-Ting", "Sin-ji", "Mei-Jia"],
            ]
            if let names = preferredNames[prefix] {
                for name in names {
                    if let v = candidates.first(where: { $0.name.caseInsensitiveCompare(name) == .orderedSame }) {
                        return v
                    }
                }
            }

            // Quality tier fallback: Premium > Enhanced > any.
            if let premium = candidates.first(where: { $0.quality == .premium }) { return premium }
            if let enhanced = candidates.first(where: { $0.quality == .enhanced }) { return enhanced }
            return candidates.first ?? AVSpeechSynthesisVoice(language: languageTag)
        }
    }
}
