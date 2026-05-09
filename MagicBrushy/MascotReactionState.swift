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

    /*
     Source artwork (May 9, 2026 exports in `Winter_Sports/`) mapped to catalog names.
     Spare exports not used here: `12_14_05 AM (1).png`, `12_14_06 AM (2–5).png` — swap in Images.xcassets if a pose needs replacing.

     | # | State          | Source file                                      |
     |---|----------------|--------------------------------------------------|
     | 1 | Neutral        | ChatGPT Image May 9, 2026, 12_10_22 AM (1).png   |
     | 2 | Hello          | ChatGPT Image May 9, 2026, 12_10_22 AM (2).png   |
     | 3 | Talking        | ChatGPT Image May 9, 2026, 12_10_22 AM (3).png   |
     | 4 | O Mouth        | ChatGPT Image May 9, 2026, 12_10_22 AM (4).png   |
     | 5 | Happy          | ChatGPT Image May 9, 2026, 12_10_22 AM (5).png   |
     | 6 | Excited        | ChatGPT Image May 9, 2026, 12_10_23 AM (6).png   |
     | 7 | Surprised      | ChatGPT Image May 9, 2026, 12_10_23 AM (7).png   |
     | 8 | Curious        | ChatGPT Image May 9, 2026, 12_10_23 AM (8).png   |
     | 9 | Thinking       | ChatGPT Image May 9, 2026, 12_10_29 AM.png       |
     |10 | Supportive     | ChatGPT Image May 9, 2026, 12_13_57 AM (1).png   |
     |11 | Caring Heart   | ChatGPT Image May 9, 2026, 12_13_57 AM (2).png   |
     |12 | Thumbs Up      | ChatGPT Image May 9, 2026, 12_13_57 AM (3).png   |
     |13 | Celebrating    | ChatGPT Image May 9, 2026, 12_13_57 AM (4).png   |
     |14 | Listening      | ChatGPT Image May 9, 2026, 12_13_58 AM (5).png   |
     |15 | Tap Reaction   | ChatGPT Image May 9, 2026, 12_13_58 AM (6).png   |
     |16 | Sleepy         | ChatGPT Image May 9, 2026, 12_13_58 AM (7).png   |
     */
}
