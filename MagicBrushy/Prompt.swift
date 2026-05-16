import Foundation

/// VLM coach prompt strings and language suffixes for MagicBrushy.
enum Prompt {

    // MARK: - Language

    /// Appended to coach prompts so the model replies in the selected language.
    static func languageInstruction(for language: MagicBrushyLanguage) -> String {
        switch language {
        case .english:
            return ""
        case .arabic:
            return "\nIMPORTANT: Write your reply entirely in Arabic (العربية). Do not use any other language."
        case .spanish:
            return "\nIMPORTANT: Write your reply entirely in Spanish (Español). Do not use any other language."
        case .french:
            return "\nIMPORTANT: Write your reply entirely in French (Français). Do not use any other language."
        case .german:
            return "\nIMPORTANT: Write your reply entirely in German (Deutsch). Do not use any other language."
        case .japanese:
            return "\nIMPORTANT: Write your reply entirely in Japanese (日本語). Do not use any other language."
        case .korean:
            return "\nIMPORTANT: Write your reply entirely in Korean (한국어). Do not use any other language."
        case .chinese:
            return "\nIMPORTANT: Write your reply entirely in Chinese (中文). Do not use any other language."
        }
    }

    // MARK: - Coach (stroke idle)

    /// After the child pauses painting: praise the latest stroke / color.
    static func strokeFeedback(
        pageTitle: String?,
        lastStrokePointCount: Int,
        lastPaintColorName: String?
    ) -> String {
        let opener = sheetOpener(pageTitle: pageTitle)
        let paletteHint = paletteHintBlock(
            lastStrokePointCount: lastStrokePointCount,
            lastPaintColorName: lastPaintColorName
        )
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())

        return """
\(opener) Look at the picture.

\(paletteHint)

Your job:  Say sth about pychology of the color+object in simple kid words. If the subject is very obvious, you may weave it in briefly—do not guess random objects. \(noMapDirectionsRule)

\(spokenToChildRule)

\(spokenReplyOnlyFooter)\(lang)

"""

//say one cheery thing that names the color they just added with the object,
    }

    // MARK: - Coach (mascot tap — whole page)

    /// When the child taps the mascot: cheer for the entire drawing.
    static func wholeDrawingCheer(pageTitle: String?) -> String {
        let opener = sheetOpener(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())

        return """
\(opener) The photo shows the **whole coloring page** together (all outlines and all paint).

They just tapped their mascot buddy asking for a big cheer for their **entire drawing so far**—not only the newest dab of paint. Look at the full picture: how colors spread across the scene, how the page feels as one piece, and the subject of the line art if you can tell.

Your job: one warm, very short message in simple kid words about **the whole picture**—what you like about how they filled the page overall. Use "you" or "your". If you can, mention **two** small things you like (for example a color choice **and** the character or scene), but keep it to one or two tiny sentences. Vary how you start (\(neverYouHaveOpenersRule)). \(noMapDirectionsRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    // MARK: - Legacy mascot pose classifier

    /// Separate VLM call that returns one mascot pose identifier (unused; pose comes from coach text).
    static func mascotReactionClassification(poseLabels: [String]) -> String {
        let labels = poseLabels.sorted().joined(separator: ", ")
        return """
You see a child’s coloring page (template + paint). Pick ONE mascot pose name that fits the **mood of their work right now**—calm encouragement, pride in a new patch of color, quiet focus, warmth, playfulness, etc.

Use a **normal, varied** reaction for everyday coloring: prefer happy, supportive, thumbsUp, listening, thinking, neutral, caringHeart, celebrating, hello, talking, or tapReaction when the page looks like steady fun progress.

Reserve **surprised**, **excited**, and **oMouth** only when the picture clearly shows something unusually bold, messy-funny, or visually startling—not as a default.

Do **not** always pick the same pose across turns; match this specific photo.

Output rule: reply with EXACTLY ONE WORD — one of these camelCase identifiers and nothing else (no punctuation, no quotes, no explanation):
\(labels)

If unsure, use neutral.
"""
    }

    // MARK: - Shared fragments

    private static func sheetOpener(pageTitle: String?) -> String {
        if let title = pageTitle, !title.isEmpty {
            return "A child colored this sheet (outlines + paint). Page: \(title)."
        }
        return "A child colored this sheet (outlines + paint)."
    }

    private static func paletteHintBlock(
        lastStrokePointCount: Int,
        lastPaintColorName: String?
    ) -> String {
        if lastStrokePointCount > 30, let paintWord = lastPaintColorName {
            return "Their most recent big brush used palette color “\(paintWord)”—celebrate that color if you see it in the photo."
        }
        if lastStrokePointCount > 0, let paintWord = lastPaintColorName {
            return "Their most recent brush used palette color “\(paintWord)”—celebrate that color if you see it in the photo."
        }
        if lastStrokePointCount > 0 {
            return "They added a little paint recently; give a warm cheer without insisting on a specific color name."
        }
        return "No new stroke tracked; peek at the picture and cheer gently."
    }

    private static let noMapDirectionsRule =
        "Do not use map directions (no left, right, top, bottom, or “in the corner”)."

    private static let neverYouHaveOpenersRule =
        "never open with “You have a”, “You have an”, or “You’ve got a”"

    private static let spokenToChildRule = """
Speak to THEM: one or two very short sentences, easy words, use "you" or "your". Open with varied praise —never start with the stock phrase “You have a” or “You have an” or “You’ve got a”. Sound warm; you may add a tiny color-feeling phrase that fits that color.
"""

    private static let spokenReplyOnlyFooter = """
IMPORTANT: Reply with ONLY the words you say aloud—no rules, no quotes about yourself, no repeating this text, no bullets, no markdown, no symbols like <>. Never mention AI, robots, computers, phones, apps, or internet.
"""
}
