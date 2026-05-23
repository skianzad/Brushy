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
        "You colored that in so nicely!",
        "That patch looks proud and happy!",
        "What a magic bit of color!",
        "You are so creative",

    ]

    private static func randomStrokePraiseOpener() -> String {
        strokePraiseOpeners.randomElement() ?? "Wow, nice color!"
    }

    /// After the child pauses painting: praise the latest stroke / color (coloring pages) or shapes (free draw).
    static func strokeFeedback(
        pageTitle: String?,
        lastStrokePointCount: Int,
        lastPaintColorName: String?,
        isFreeDrawing: Bool = false
    ) -> String {
        if isFreeDrawing {
            return strokeFeedbackFreeDrawing(
                pageTitle: pageTitle,
                lastStrokePointCount: lastStrokePointCount,
                lastPaintColorName: lastPaintColorName
            )
        }
        return strokeFeedbackColoring(
            pageTitle: pageTitle,
            lastStrokePointCount: lastStrokePointCount,
            lastPaintColorName: lastPaintColorName
        )
    }

    /// Coloring-book idle feedback — unchanged color-first coach copy.
    private static func strokeFeedbackColoring(
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

\(vlmFlexibilityRule)

You may offer exactly (one or two) very short sentences total (nothing longer). You may name the color they used if you can see it. You may add one tiny idea about how that color feels with what they painted—only if it is obvious; do not guess random objects. \(noMapDirectionsRule)

Start your spoken reply with a phrase in the spirit of: “\(praiseStarter)” — adapt the words to fit their color and picture; do not copy “Great job using the … color” or long lectures.\(openerLanguageNote)

\(spokenToChildRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    private static let freeDrawStrokePraiseOpeners: [String] = [
        "Ooh, a new piece of your picture!",
        "That line adds something fun!",
        "I wonder what that shape is!",
        "Look what you drew just now!",
        "That mark makes your drawing grow!",
        "What a neat new bit!",
        "Your picture is coming alive!",
        "That stroke tells a little story!",
        "I see something forming there!",
        "What a creative dab!",
        "That squiggle looks like an idea!",
        "You just grew your drawing!",
        "What is that turning into?",
        "A fresh mark—nice!",
        "That adds a whole new part!",
        "Your page has a new surprise!",
        "I like that new line you made!",
        "That blob could be anything fun!",
        "You’re building something cool!",
        "What a bold new stroke!",
        "That curve makes me curious!",
        "Your drawing just got bigger!",
        "That looks like the start of something!",
        "Ooh, what are you making there?",
        "That new bit changes the whole picture!",
        "You drew that so confidently!",
        "That shape has personality!",
        "What a playful new mark!",
        "Your picture has more story now!",
        "That line connects the dots!",
        "I see a new friend in your drawing!",
        "That stroke feels full of imagination!",
        "You added a secret little detail!",
        "What a twist in your picture!",
        "That mark looks like it belongs!",
        "Your drawing is finding its shape!",
        "That’s a clever new addition!",
        "You just opened a new chapter!",
        "What a spark of an idea!",
        "That new part makes me smile!",
    ]

    private static func randomFreeDrawStrokePraiseOpener() -> String {
        freeDrawStrokePraiseOpeners.randomElement() ?? "Ooh, a new piece of your picture!"
    }

    private static func strokeFeedbackFreeDrawing(
        pageTitle: String?,
        lastStrokePointCount: Int,
        lastPaintColorName: String?
    ) -> String {
        let opener = sheetOpenerFreeDraw(pageTitle: pageTitle)
        let drawingHint = freeDrawDrawingHintBlock(
            lastStrokePointCount: lastStrokePointCount,
            lastPaintColorName: lastPaintColorName
        )
        let praiseStarter = randomFreeDrawStrokePraiseOpener()
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())
        let language = MagicBrushyLanguage.stored()
        let openerLanguageNote = language == .english
            ? ""
            : " Say the opening in \(language.rawValue), keeping the same cheerful tone."

        return """
\(opener) Look at their free drawing on blank paper.

\(drawingHint)

\(vlmFlexibilityRule)

Say exactly one or two very short sentences to the child (nothing longer). Cheer shapes or what the drawing might be—only if the picture suggests it (sun, house, animal, face, path, flower). You may name a color only if it helps; do not make the whole reply about colors. \(noMapDirectionsRule)

Start your spoken reply with a phrase in the spirit of: “\(praiseStarter)” — adapt it to their shapes; do not copy long lectures.\(openerLanguageNote)

\(spokenToChildRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    // MARK: - Coach (page load)

    /// When a page first appears: coloring template welcome, or free-draw welcome.
    static func pageLoadWelcome(
        pageTitle: String?,
        hasPriorPaint: Bool,
        isFreeDrawing: Bool = false
    ) -> String {
        if isFreeDrawing {
            return pageLoadWelcomeFreeDrawing(pageTitle: pageTitle, hasPriorPaint: hasPriorPaint)
        }
        return pageLoadWelcomeColoring(pageTitle: pageTitle, hasPriorPaint: hasPriorPaint)
    }

    // MARK: - Coach (home mode picker)

    /// Spoken on the home screen with lip sync — references last coloring / free draw or introduces both modes.
    /// - Parameter isPhone: On phone, cards are side by side (coloring left, free draw right); on iPad, stacked (top / bottom).
    static func homeModePickerWelcome(
        recents: RecentDrawingActivity.HomeRecentsSummary,
        isPhone: Bool
    ) -> String {
        if recents.hasLastColoring, recents.hasLastFreeDraw {
            return homeModePickerWelcomeBoth(isPhone: isPhone)
        }
        if recents.hasLastColoring {
            return homeModePickerWelcomeColoringOnly(
                pageTitle: recents.lastColoringPageTitle ?? "picture",
                packTitle: recents.lastColoringPackTitle,
                isPhone: isPhone
            )
        }
        if recents.hasLastFreeDraw {
            return homeModePickerWelcomeFreeDrawOnly(
                drawingTitle: recents.lastFreeDrawTitle ?? "drawing",
                isPhone: isPhone
            )
        }
        return homeModePickerWelcomeIntro(isPhone: isPhone)
    }

    private static func homeModePickerWelcomeBoth(isPhone: Bool) -> String {
        let lines: [String]
        if isPhone {
            lines = [
                "Hi! You can keep coloring what you see on the left, or tap Free Draw on the right to keep drawing!",
                "Hey friend! Tap Coloring on the left to keep going with that picture, or Free Draw on the right for your drawing!",
                "Welcome back! Continue your coloring on the left, or your free drawing on the right—whichever you feel like!",
            ]
        } else {
            lines = [
                "Hi! You can keep coloring at the top, or tap Free Draw below to keep drawing!",
                "Hey friend! Tap Coloring on top to keep going with that picture, or Free Draw on the bottom for your drawing!",
                "Welcome back! Continue your coloring up top, or your free drawing down below—whichever you feel like!",
            ]
        }
        return lines.randomElement() ?? lines[0]
    }

    private static func homeModePickerWelcomeColoringOnly(
        pageTitle: String,
        packTitle: String?,
        isPhone: Bool
    ) -> String {
        let subject = spokenPictureLabel(pageTitle: pageTitle, packTitle: packTitle)
        let whereCard = isPhone ? "the Coloring card on the left" : "the Coloring card on top"
        let lines = [
            "Hey! Tap \(whereCard) to jump back into \(subject) and keep adding colors!",
            "Your \(subject) is waiting on \(whereCard)—tap it when you want to keep painting!",
            "Ready for more? Open Coloring to finish \(subject)—you were doing great!",
        ]
        return lines.randomElement() ?? lines[0]
    }

    private static func homeModePickerWelcomeFreeDrawOnly(drawingTitle: String, isPhone: Bool) -> String {
        let label = kidFriendlyDrawingLabel(drawingTitle)
        let whereCard = isPhone ? "Free Draw on the right" : "Free Draw below"
        let lines = [
            "Hey! Tap \(whereCard) to open \(label) again—or start a fresh page whenever you like!",
            "Your free drawing is on the green card—tap \(whereCard) to keep building \(label)!",
            "Welcome back! Tap \(whereCard)—\(label) is ready for you!",
        ]
        return lines.randomElement() ?? lines[0]
    }

    private static func homeModePickerWelcomeIntro(isPhone: Bool) -> String {
        let lines: [String]
        if isPhone {
            lines = [
                "Hi! I am Brushi! Tap Coloring on the left to pick a picture and fill it with crayons, or Free Draw on the right for blank paper—draw anything you imagine!",
                "Hello! Coloring on the left lets you paint fun pictures line by line. Free Draw on the right is empty paper for your own ideas!",
                "Hey there! Choose Coloring on the left for ready-made pictures to color, or Free Draw on the right to make your own art!",
            ]
        } else {
            lines = [
                "Hi! I am Brushi! Tap Coloring to pick a picture and fill it with crayons, or tap Free Draw for blank paper—draw anything you imagine!",
                "Hello! Coloring lets you paint fun pictures line by line. Free Draw is empty paper for your own ideas—tap either card to start!",
                "Hey there! Choose Coloring for ready-made pictures to color, or Free Draw to make your own art from scratch!",
            ]
        }
        return lines.randomElement() ?? lines[0]
    }

    private static func spokenPictureLabel(pageTitle: String, packTitle: String?) -> String {
        let page = pageTitle.trimmingCharacters(in: .whitespacesAndNewlines)
        if page.isEmpty { return "your picture" }
        if let pack = packTitle?.trimmingCharacters(in: .whitespacesAndNewlines), !pack.isEmpty,
           !page.localizedCaseInsensitiveContains(pack) {
            return "your \(page) from \(pack)"
        }
        return "your \(page)"
    }

    private static func kidFriendlyDrawingLabel(_ title: String) -> String {
        let t = title.trimmingCharacters(in: .whitespacesAndNewlines)
        if t.isEmpty || t.localizedCaseInsensitiveCompare("Blank paper") == .orderedSame {
            return "your drawing"
        }
        return "your \(t)"
    }

    /// Spoken when free draw opens on **fully blank** paper only (no saved art, no strokes; no VLM).
    static func freeDrawEmptyPageEncouragement() -> String {
        freeDrawEmptyPageEncouragements.randomElement()
            ?? "This paper is all yours—pick a color and draw anything you dream up!"
    }

    private static let freeDrawEmptyPageEncouragements: [String] = [
        "This paper is all yours—pick a color and draw anything you dream up!",
        "A blank page is like magic—what will you make first?",
        "You can draw anything here—start with one fun line!",
        "Empty paper, big ideas—grab a crayon and go!",
        "Your imagination gets to run the show—make the first mark!",
        "Nothing on the page yet—that means endless possibilities!",
        "Ready to create? Pick a color and draw something only you can think of!",
        "Fresh paper! What shape or doodle will you try first?",
        "This is your studio—start drawing whenever you feel ready!",
        "Blank paper is waiting for your first brilliant stroke!",
    ]

    /// Coloring-book page open — unchanged copy.
    private static func pageLoadWelcomeColoring(pageTitle: String?, hasPriorPaint: Bool) -> String {
        let opener = sheetOpener(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())
        let progressNote = """
              Welcome them to today’s sheet and invite them to pick colors and start filling it in.
            """
        _ = hasPriorPaint

        return """
\(opener)

The child just opened this page. Look at the line art and the paint.

\(progressNote)

Your job: **two or three** short spoken sentences (about **25–45 words** total)—warm, simple kid words, not a lecture. Cover these beats **talking TO the child** (use the examples’ tone):
1) Name today’s picture.
2) Invite the child to keep going.

\(spokenToChildRule)
\(neverThirdPersonSpokenRule)
\(noMapDirectionsRule) \(neverYouHaveOpenersRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    private static func pageLoadWelcomeFreeDrawing(pageTitle: String?, hasPriorPaint: Bool) -> String {
        let opener = sheetOpenerFreeDraw(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())
        let progressNote = hasPriorPaint
            ? """
              They already have marks on the page. Welcome them back; notice one simple thing about what is already there (a shape, path, or idea—only if you clearly see it). Invite them to keep building the picture.
            """
            : """
              The page should be empty. Give warm encouragement to pick a color and make the first line, shape, or doodle. Sound excited that they can create anything—do not describe things that are not on the page.
            """

        return """
\(opener)

The child just opened this free-draw page. Look at the blank paper and any marks.

\(progressNote)

Your job: two or three short spoken sentences (about 20–40 words total)—warm, simple kid words. Focus on drawing and creativity, not color lectures. \(noMapDirectionsRule) \(neverYouHaveOpenersRule)

\(spokenToChildRule)
\(neverThirdPersonSpokenRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    // MARK: - Coach (mascot tap — whole page)

    /// When the child taps the mascot: cheer for the entire drawing.
    static func wholeDrawingCheer(pageTitle: String?, isFreeDrawing: Bool = false) -> String {
        if isFreeDrawing {
            return wholeDrawingCheerFreeDrawing(pageTitle: pageTitle)
        }
        return wholeDrawingCheerColoring(pageTitle: pageTitle)
    }

    /// Coloring-book mascot tap — unchanged color/scene-first coach copy.
    private static func wholeDrawingCheerColoring(pageTitle: String?) -> String {
        let opener = sheetOpener(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())

        return """
\(opener) The photo shows the **whole coloring page** together (all outlines and all paint).

The child just tapped their mascot buddy asking for a big cheer for their **entire drawing so far**—not only the newest dab of paint. Look at the full picture: how colors spread across the scene, how the page feels as one piece, and the subject of the line art if you can tell.

\(vlmFlexibilityRule)

You may give one warm, very short message in simple kid words about **the whole picture**—what you like about how they filled the page overall. You may mention **two** small things you like (for example a color choice **and** the character or scene), but you may keep it to one or two tiny sentences. Vary how you start (\(neverYouHaveOpenersRule)). \(noMapDirectionsRule)

\(spokenToChildRule)
\(neverThirdPersonSpokenRule)

\(spokenReplyOnlyFooter)\(lang)

"""
    }

    private static func wholeDrawingCheerFreeDrawing(pageTitle: String?) -> String {
        let opener = sheetOpenerFreeDraw(pageTitle: pageTitle)
        let lang = languageInstruction(for: MagicBrushyLanguage.stored())

        return """
\(opener) The photo shows their whole free drawing on blank paper (no template outlines).

The child tapped their mascot for a big cheer about everything they drew so far. Look at the full page: shapes, paths, and how the picture fits together.

\(vlmFlexibilityRule)

Say one or two very short sentences in simple kid words. Praise what the drawing might be or what story the shapes tell. You may add one tiny cheer about a color or a part you like—but do not make the reply only about colors. Vary how you start (\(neverYouHaveOpenersRule)). \(noMapDirectionsRule)

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

    /// Coloring pages only (template outlines + paint).
    private static func sheetOpener(pageTitle: String?) -> String {
        if let title = pageTitle, !title.isEmpty {
            return "A child colored this sheet (outlines + paint). Page: \(title)."
        }
        return "A child colored this sheet (outlines + paint)."
    }

    private static func sheetOpenerFreeDraw(pageTitle: String?) -> String {
        if let title = pageTitle, !title.isEmpty {
            return "A child is freely drawing on blank paper (no template outlines). Session: \(title)."
        }
        return "A child is freely drawing on blank paper (no template outlines)."
    }

    private static func freeDrawDrawingHintBlock(
        lastStrokePointCount: Int,
        lastPaintColorName: String?
    ) -> String {
        if lastStrokePointCount > 30, let paintWord = lastPaintColorName {
            return "the kid’s most recent stroke was large and used palette color “\(paintWord)”— you may cheer shapes or what the drawing might be; color is optional."
        }
        if lastStrokePointCount > 30 {
            return "the kid just made a large new mark— you may notice what grew on the page."
        }
        if lastStrokePointCount > 0, let paintWord = lastPaintColorName {
            return "the kid’s most recent brush used palette color “\(paintWord)”— you may mention it briefly if you see it; shapes matter more."
        }
        if lastStrokePointCount > 0 {
            return "the kid added a small fresh mark— you may cheer what looks new."
        }
        return "peek at the free drawing and cheer gently."
    }

    private static func paletteHintBlock(
        lastStrokePointCount: Int,
        lastPaintColorName: String?
    ) -> String {
        if lastStrokePointCount > 30, let paintWord = lastPaintColorName {
            return "the kid most recent big brush used palette color “\(paintWord)”— you may celebrate that color if you see it in the photo."
        }
        if lastStrokePointCount > 0, let paintWord = lastPaintColorName {
            return "the kid most recent brush used palette color “\(paintWord)”— you may celebrate that color if you see it in the photo."
        }
        if lastStrokePointCount > 0 {
            return "The kid added a little paint recently; you may give a warm cheer without insisting on a specific color name."
        }
        return "No new stroke tracked; peek at the picture and cheer gently."
    }

    /// Shared coach/VLM hint: permission to adapt beats and length to what is on the image.
    private static let vlmFlexibilityRule = """
You may adapt, skip, or shorten anything below—only say what honestly fits what you see. Keep wording fresh; you do not need to follow every beat.
"""

    private static let noMapDirectionsRule =
        "Do not use map directions (no left, right, top, bottom, or “in the corner”)."

    private static let neverYouHaveOpenersRule =
        "never open with “You have a”, “You have an”, or “You’ve got a”"

    private static let neverThirdPersonSpokenRule = """
In your spoken reply, talk to the child (second person). Never say “They are coloring”, “They are”, “The child is”, or “Their”—use “you”, “your”, “you’re” instead.
"""

    private static let spokenToChildRule = """
Speak to the child aloud: easy words, always “you” or “your”, never “they” or “their” about the child. Never start with “You have a”, “You have an”, or “You’ve got a”. No third sentence.
"""
    private static let spokenReplyOnlyFooter = """
IMPORTANT: Reply with ONLY the words you say aloud to the child—no rules, no quotes about yourself, no repeating any line from this prompt (including hints about marks, palette colors, or “look for what changed”). No bullets, no asterisks, no markdown, no symbols like <>. Never mention AI, robots, computers, phones, apps, or internet.
"""
}
