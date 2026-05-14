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

        if SherpaPiperAlbaVoice.isBundledVoiceAvailable {
            do {
                try await SherpaPiperAlbaVoice.speakAlbaBritishEnglish(clean) { text, duration in
                    Self.mascotLipSync?.startSherpaDrivenLipSync(text: text, duration: duration)
                }
            } catch {}
            Self.mascotLipSync?.sessionEnded()
            return
        }

        await AppleFeedbackSynth.shared.speak(clean)
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

        func speak(_ text: String) async {
            guard !text.isEmpty else { return }
            stop()
            FeedbackAlbaSpeech.mascotLipSync?.startAppleDrivenLipSync()
            let voice = Self.preferredBritishEnglishVoice()

            await withCheckedContinuation { (cont: CheckedContinuation<Void, Never>) in
                self.speakContinuation = cont
                let u = AVSpeechUtterance(string: text)
                u.voice = voice
                u.rate = AVSpeechUtteranceDefaultSpeechRate * 0.92
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

        /// Prefer British voices consistent with Alba (Sherpa Piper en-GB).
        private static func preferredBritishEnglishVoice() -> AVSpeechSynthesisVoice? {
            let enGB = AVSpeechSynthesisVoice.speechVoices().filter { $0.language == "en-GB" }
            let nameOrder = ["Martha", "Kate", "Serena", "Daniel", "Arthur", "Oliver"]
            for name in nameOrder {
                if let v = enGB.first(where: { $0.name.caseInsensitiveCompare(name) == .orderedSame }) {
                    return v
                }
            }
            return enGB.first ?? AVSpeechSynthesisVoice(language: "en-US")
        }
    }
}
