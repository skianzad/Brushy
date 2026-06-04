import UIKit

/// MagicBrushy mascot poses aligned with the 4×4 reaction sheet (Neutral … Sleepy).
/// Asset catalog image names: `MascotStateNeutral` … `MascotStateSleepy`.
enum MascotReactionState: String, CaseIterable, Codable {
    case neutral = "MascotStateNeutral"
    case hello = "MascotStateHello"
    case talking = "MascotStateTalking"
    case oMouth = "MascotStateOMouth"
    case happy = "MascotStateHappy"
    case excited = "MascotStateExcited"
    case surprised = "MascotStateSurprised"
    case curious = "MascotStateCurious"
    case thinking = "MascotStateThinking"
    case supportive = "MascotStateSupportive"
    case caringHeart = "MascotStateCaringHeart"
    case thumbsUp = "MascotStateThumbsUp"
    case celebrating = "MascotStateCelebrating"
    case listening = "MascotStateListening"
    case tapReaction = "MascotStateTapReaction"
    /// Long painting inactivity only — not mapped from coach VLM text (`Reaction`).
    /// Runtime imageset: `MascotStateSleepy` (keep in sync with `BrushMascotSleepy` source art).
    case sleepy = "MascotStateSleepy"

    /// Catalog imageset name (same as `rawValue`).
    var assetName: String { rawValue }

    /// Human-readable label (matches design sheet).
    var displayTitle: String {
        switch self {
        case .neutral: return "Neutral"
        case .hello: return "Hello"
        case .talking: return "Talking"
        case .oMouth: return "O Mouth"
        case .happy: return "Happy"
        case .excited: return "Excited"
        case .surprised: return "Surprised"
        case .curious: return "Curious"
        case .thinking: return "Thinking"
        case .supportive: return "Supportive"
        case .caringHeart: return "Caring Heart"
        case .thumbsUp: return "Thumbs Up"
        case .celebrating: return "Celebrating"
        case .listening: return "Listening"
        case .tapReaction: return "Tap Reaction"
        case .sleepy: return "Sleepy"
        }
    }

    func loadImage() -> UIImage? {
        UIImage(named: assetName)
    }

    /// Sheet order 1…16 (row-major on the reference grid).
    var sheetIndex: Int {
        switch self {
        case .neutral: return 1
        case .hello: return 2
        case .talking: return 3
        case .oMouth: return 4
        case .happy: return 5
        case .excited: return 6
        case .surprised: return 7
        case .curious: return 8
        case .thinking: return 9
        case .supportive: return 10
        case .caringHeart: return 11
        case .thumbsUp: return 12
        case .celebrating: return 13
        case .listening: return 14
        case .tapReaction: return 15
        case .sleepy: return 16
        }
    }

    // Source artwork: character/*.png → Assets.xcassets (MascotState… + MascotTalkingMouth…).
    // See character/ folder for neutral, hello, open, oshaped, happy, etc.
}
