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

    /// Short praise openers rotated into per-stroke prompts so the model does not repeat “Great job using…”.
    private static let strokePraiseOpeners: [String] = [
        "Wow, that color pops!",
        "Ooh, what a bright dab!",
        "Nice pick for that spot!",
        "That shade looks so cheerful!",
        "I love how that area glows!",
        "What a happy splash of paint!",
        "That bit looks extra special!",
        "You made that patch shine!",
        "So pretty on that part!",
        "That stroke looks super smooth!",
        "What a cozy color touch!",
        "That hue fits right in!",
        "Look how fun that looks!",
        "That color makes me smile!",
        "Yay, more life on the page!",
        "What a playful brush of color!",
        "That spot looks warm and friendly!",
        "How neat you filled that in!",
        "That area looks bold and bright!",
        "What a lovely color choice!",
        "You’re making the picture sing!",
        "That paint looks just right there!",
        "What a sweet little color hug!",
        "That corner looks so lively now!",
        "How bright and brave that is!",
        "That dab feels full of energy!",
        "What a sunny color moment!",
        "You colored that in so nicely!",
        "That patch looks proud and happy!",
        "What a magic bit of color!",
    ]

    private static func randomStrokePraiseOpener() -> String {
        strokePraiseOpeners.randomElement() ?? "Wow, nice color!"
    }

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
        let praiseStarter = randomStrokePraiseOpener()
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())
        let language = MagicBrushyLanguage.stored()
        let openerLanguageNote = language == .english
            ? ""
            : " Say the opening in \(language.rawValue), keeping the same cheerful tone."

        return """
\(opener) Look at the picture.

\(paletteHint)

Your job: exactly **one or two** very short sentences total (nothing longer). Name the color they used if you can see it. You may add one tiny idea about how that color feels with what they painted—only if it is obvious; do not guess random objects. \(noMapDirectionsRule)

**Start** your spoken reply with a phrase in the spirit of: “\(praiseStarter)” — adapt the words to fit their color and picture; do not copy “Great job using the … color” or long lectures.\(openerLanguageNote)

\(spokenToChildRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    // MARK: - Coach (page load)

    /// When a coloring page first appears: name the scene, note any color already on the page, invite finishing the rest.
    static func pageLoadWelcome(pageTitle: String?, hasPriorPaint: Bool) -> String {
        let opener = sheetOpener(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())
        let progressNote = hasPriorPaint
            ? """
The picture already has **some colored areas** from before (saved progress). You must mention that they already started—name **one** color or area you can see (for example blue waves or a yellow sun).
"""
            : """
The picture is mostly **uncolored** so far. Welcome them to today’s sheet and invite them to pick colors and start filling it in.
"""

        return """
\(opener) The photo is the **whole coloring page** (outlines plus any paint).

The child just opened this page. Look at the line art and the paint.

\(progressNote)

Your job: **two or three** short spoken sentences (about **25–45 words** total)—warm, simple kid words, not a lecture. Cover these beats **talking TO the child** (use the examples’ tone):
1) Name today’s picture—e.g. "You're coloring a boat today!" or "This is a fun boat picture to color!"
2)\(hasPriorPaint ? " Compliment one color or patch they already filled—e.g. \"Your sun is so yellow!\" or \"I love the blue waves you started.\"" : " Welcome them—e.g. \"Let's add some color to this page!\"")
3) Invite them to keep going—e.g. "Keep coloring more of the picture!"

\(spokenToChildRule)
\(neverThirdPersonSpokenRule)
\(noMapDirectionsRule) \(neverYouHaveOpenersRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    // MARK: - Coach (mascot tap — whole page)

    /// When the child taps the mascot: cheer for the entire drawing.
    static func wholeDrawingCheer(pageTitle: String?) -> String {
        let opener = sheetOpener(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())

        return """
\(opener) The photo shows the **whole coloring page** together (all outlines and all paint).

They just tapped their mascot buddy asking for a big cheer for their **entire drawing so far**—not only the newest dab of paint. Look at the full picture: how colors spread across the scene, how the page feels as one piece, and the subject of the line art if you can tell.

Your job: one warm, very short message in simple kid words about **the whole picture**—what you like about how they filled the page overall. If you can, mention **two** small things you like (for example a color choice **and** the character or scene), but keep it to one or two tiny sentences. Vary how you start (\(neverYouHaveOpenersRule)). \(noMapDirectionsRule)

\(spokenToChildRule)
\(neverThirdPersonSpokenRule)

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
            return "Their most recent big brush used palette color “\(paintWord)”— you may celebrate that color if you see it in the photo."
        }
        if lastStrokePointCount > 0, let paintWord = lastPaintColorName {
            return "Their most recent brush used palette color “\(paintWord)”— you may celebrate that color if you see it in the photo."
        }
        if lastStrokePointCount > 0 {
            return "They added a little paint recently; you may give a warm cheer without insisting on a specific color name."
        }
        return "No new stroke tracked; peek at the picture and cheer gently."
    }

    private static let noMapDirectionsRule =
        "Do not use map directions (no left, right, top, bottom, or “in the corner”)."

    private static let neverYouHaveOpenersRule =
        "never open with “You have a”, “You have an”, or “You’ve got a”"

    private static let neverThirdPersonSpokenRule = """
In your spoken reply, talk **to** the child (second person). Never say “They are coloring”, “They are”, “The child is”, or “Their”—use “you”, “your”, “you’re” instead.
"""

    private static let spokenToChildRule = """
Speak **to** the child aloud: easy words, always “you” or “your”, never “they” or “their” about the child. Never start with “You have a”, “You have an”, or “You’ve got a”. No third sentence.
"""
    private static let spokenReplyOnlyFooter = """
IMPORTANT: Reply with ONLY the words you say aloud—no rules, no quotes about yourself, no repeating this text, no bullets, no markdown, no symbols like <>. Never mention AI, robots, computers, phones, apps, or internet.
"""
}
