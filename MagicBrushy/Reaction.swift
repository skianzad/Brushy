import Foundation

/// Mascot pose from VLM coach text (original single-prompt flow) + optional legacy classifier prompt (commented).
enum Reaction {

    // MARK: - Legacy separate reaction-only prompt (unused; pose comes from coach response text)
    /*
    static func classificationPrompt() -> String {
        let labels = MascotReactionState.allCases
            .map { String(describing: $0) }
            .sorted()
            .joined(separator: ", ")
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
    */

    /// Pick a catalog pose from the **first** (coach-only) VLM reply: optional embedded camelCase token, else light keyword heuristics, else neutral.
    static func mascotPoseFromCoachResponse(_ raw: String) -> MascotReactionState {
        let cleaned = Self.stripControlNoise(raw)
        guard !cleaned.isEmpty else { return .neutral }

        if let fromToken = Self.parseMascotReaction(from: cleaned) {
            return fromToken
        }

        let s = cleaned.lowercased()
        func has(_ pattern: String) -> Bool {
            guard let re = try? NSRegularExpression(pattern: pattern, options: .caseInsensitive) else { return false }
            return re.firstMatch(in: s, options: [], range: NSRange(s.startIndex..., in: s)) != nil
        }

        if has(#"\b(wow|whoa|surpris|amazing|incredible|astonish)\b"#) { return .surprised }
        if has(#"\b(yay|hooray|celebrat|party|woo[- ]?hoo)\b"#) { return .celebrating }
        if has(#"\b(curio|wonder|hmm|what a|look at that)\b"#) { return .curious }
        if has(#"\b(think|maybe try|try adding|next time)\b"#) { return .thinking }
        if has(#"\b(listen|hear you|tell me)\b"#) { return .listening }
        if has(#"\b(sleepy|tired|rest|nap)\b"#) { return .sleepy }
        if has(#"\b(hug|care|gentle|sweet heart|lovely heart)\b"#) { return .caringHeart }
        if has(#"\b(thumbs|high five|you did it)\b"#) { return .thumbsUp }
        if has(#"\b(hello|hi there|hey there)\b"#) { return .hello }
        if has(#"\b(support|keep going|you've got|proud of you)\b"#) { return .supportive }
        if has(#"\b(excited|can't wait|so cool)\b"#) { return .excited }
        if has(#"\b(oops|uh oh|messy|whoops)\b"#) { return .tapReaction }
        if has(#"\b(great|good job|nice|beautiful|pretty|love it|fun|awesome|cool|cheer)\b"#) { return .happy }

        return .neutral
    }

    /// Maps free-form model output to a catalog pose; returns nil if nothing recognized.
    static func parseMascotReaction(from raw: String) -> MascotReactionState? {
        let cleaned = Self.stripControlNoise(raw)
        guard !cleaned.isEmpty else { return nil }

        let lc = cleaned.lowercased()
        let namesByLength = MascotReactionState.allCases
            .map { String(describing: $0).lowercased() }
            .sorted { $0.count > $1.count }

        for name in namesByLength {
            if Self.containsWholeWord(lc, word: name) {
                return MascotReactionState.allCases.first { String(describing: $0).lowercased() == name }
            }
        }

        for state in MascotReactionState.allCases {
            let asset = state.rawValue.lowercased()
            if lc.contains(asset) {
                return state
            }
            let short = asset.replacingOccurrences(of: "mascotstate", with: "")
            if short.count >= 4, lc.contains(short) {
                return state
            }
        }

        return nil
    }

    private static func stripControlNoise(_ s: String) -> String {
        var t = s.trimmingCharacters(in: .whitespacesAndNewlines)
        if let re = try? NSRegularExpression(pattern: #"<\|[^>]+>"#, options: []) {
            let full = NSRange(t.startIndex..., in: t)
            t = re.stringByReplacingMatches(in: t, options: [], range: full, withTemplate: "")
        }
        return t.trimmingCharacters(in: .whitespacesAndNewlines)
    }

    private static func containsWholeWord(_ haystack: String, word: String) -> Bool {
        guard let re = try? NSRegularExpression(
            pattern: "\\b\(NSRegularExpression.escapedPattern(for: word))\\b",
            options: .caseInsensitive
        ) else { return false }
        let range = NSRange(haystack.startIndex..., in: haystack)
        return re.firstMatch(in: haystack, options: [], range: range) != nil
    }
}
