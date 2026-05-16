import Foundation

/// Languages the VLM coach can reply in.
enum MagicBrushyLanguage: String, CaseIterable {
    case english  = "English"
    case arabic   = "Arabic"
    case spanish  = "Spanish"
    case french   = "French"
    case german   = "German"
    case japanese = "Japanese"
    case korean   = "Korean"
    case chinese  = "Chinese"

    /// Flag emoji shown next to the language name in the picker.
    var flag: String {
        switch self {
        case .english:  return "🇺🇸"
        case .arabic:   return "🇸🇦"
        case .spanish:  return "🇪🇸"
        case .french:   return "🇫🇷"
        case .german:   return "🇩🇪"
        case .japanese: return "🇯🇵"
        case .korean:   return "🇰🇷"
        case .chinese:  return "🇨🇳"
        }
    }

    /// Display label used in the settings UI.
    var displayName: String { "\(flag) \(rawValue)" }

    /// Instruction appended to every VLM prompt so the model replies in the chosen language.
    /// Empty for English because all prompts are already written in English.
    var promptInstruction: String {
        switch self {
        case .english:  return ""
        case .arabic:   return "\nIMPORTANT: Write your reply entirely in Arabic (العربية). Do not use any other language."
        case .spanish:  return "\nIMPORTANT: Write your reply entirely in Spanish (Español). Do not use any other language."
        case .french:   return "\nIMPORTANT: Write your reply entirely in French (Français). Do not use any other language."
        case .german:   return "\nIMPORTANT: Write your reply entirely in German (Deutsch). Do not use any other language."
        case .japanese: return "\nIMPORTANT: Write your reply entirely in Japanese (日本語). Do not use any other language."
        case .korean:   return "\nIMPORTANT: Write your reply entirely in Korean (한국어). Do not use any other language."
        case .chinese:  return "\nIMPORTANT: Write your reply entirely in Chinese (中文). Do not use any other language."
        }
    }

    // MARK: - Persistence

    private static let defaultsKey = "magicBrushyVLMLanguage"

    static func stored() -> MagicBrushyLanguage {
        let raw = UserDefaults.standard.string(forKey: defaultsKey) ?? ""
        return MagicBrushyLanguage(rawValue: raw) ?? .english
    }

    static func store(_ lang: MagicBrushyLanguage) {
        UserDefaults.standard.set(lang.rawValue, forKey: defaultsKey)
    }
}
