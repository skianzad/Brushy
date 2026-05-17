import Foundation

/// Offline / system voice for the painting coach (English only for Sherpa engines).
enum MagicBrushyCoachVoice: String, CaseIterable {
    case alba = "alba"
    case kokoroSky = "kokoro_sky"
    case kokoroBella = "kokoro_bella"
    case kokoroEmma = "kokoro_emma"
    case kokoroSarah = "kokoro_sarah"
    case apple = "apple"

    var displayName: String {
        switch self {
        case .alba: return "Alba (British)"
        case .kokoroSky: return "Sky (American)"
        case .kokoroBella: return "Bella (American)"
        case .kokoroEmma: return "Emma (British)"
        case .kokoroSarah: return "Sarah (American)"
        case .apple: return "Device voice"
        }
    }

    /// Kokoro `sid` when this case uses the bundled Kokoro model; nil otherwise.
    var kokoroSpeakerId: Int32? {
        switch self {
        case .kokoroSky: return 4
        case .kokoroBella: return 1
        case .kokoroEmma: return 7
        case .kokoroSarah: return 3
        default: return nil
        }
    }

    var usesSherpaAlba: Bool { self == .alba }
    var usesSherpaKokoro: Bool { kokoroSpeakerId != nil }
    var usesAppleTTS: Bool { self == .apple }

    /// Voices that can actually be selected (bundled Sherpa assets may be absent in dev builds).
    static var selectableCases: [MagicBrushyCoachVoice] {
        allCases.filter { voice in
            if voice.usesSherpaAlba { return SherpaPiperAlbaVoice.isBundledVoiceAvailable }
            if voice.usesSherpaKokoro { return SherpaKokoroVoice.isBundledVoiceAvailable }
            return true
        }
    }

    // MARK: - Persistence

    private static let defaultsKey = "magicBrushyCoachVoice"

    static func stored() -> MagicBrushyCoachVoice {
        let raw = UserDefaults.standard.string(forKey: defaultsKey) ?? ""
        if let v = MagicBrushyCoachVoice(rawValue: raw) { return v }
        if SherpaKokoroVoice.isBundledVoiceAvailable { return .kokoroSky }
        return .alba
    }

    static func store(_ voice: MagicBrushyCoachVoice) {
        UserDefaults.standard.set(voice.rawValue, forKey: defaultsKey)
    }

    /// Short line used when previewing a voice in Settings.
    static let previewPhrase = "Hi! I'm Brushi. Let's color together!"
}
