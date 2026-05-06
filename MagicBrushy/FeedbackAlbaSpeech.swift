import AVFoundation

/// Reads feedback aloud with bundled Piper Alba (Sherpa ONNX, same bundle layout as SmartDraw), then falls back to system en-GB.
enum FeedbackAlbaSpeech {

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

        if SherpaPiperAlbaVoice.isBundledVoiceAvailable {
            do {
                try await SherpaPiperAlbaVoice.speakAlbaBritishEnglish(clean)
                return
            } catch {}
        }

        await AppleFeedbackSynth.shared.speak(clean)
    }

    @MainActor
    static func stopSpeaking() {
        SherpaVLMPlayback.stopPlayback()
        AppleFeedbackSynth.shared.stop()
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
            let voice = Self.preferredBritishEnglishVoice()

            await withCheckedContinuation { (cont: CheckedContinuation<Void, Never>) in
                self.speakContinuation = cont
                let u = AVSpeechUtterance(string: text)
                u.voice = voice
                u.rate = AVSpeechUtteranceDefaultSpeechRate * 0.92
                synth.speak(u)
            }
        }

        func speechSynthesizer(_ _: AVSpeechSynthesizer, didFinish _: AVSpeechUtterance) {
            guard let c = speakContinuation else { return }
            speakContinuation = nil
            c.resume()
        }

        func speechSynthesizer(_ _: AVSpeechSynthesizer, didCancel _: AVSpeechUtterance) {
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
