import Foundation
import NaturalLanguage

/// Mascot pose from VLM coach text (pose labels / prompts live in `Prompt.swift`).
enum Reaction {

    // MARK: - Semantic anchors (Apple `NLEmbedding` sentence vectors)

    /// Short lines whose **meaning** should match typical Alba coach utterances per pose (English).
    private static let reactionAnchorPhrases: [MascotReactionState: [String]] = [
        .neutral: [
            "I am quietly looking at your picture.",
            "Taking it all in without a big reaction.",
            "Just noticing what you did there.",
        ],
        .hello: [
            "Hi there welcome to your coloring page.",
            "Hello friend good to see you painting.",
            "Hey there lets have fun with colors today.",
        ],
        .talking: [
            "I want to chat with you about your drawing.",
            "Let me tell you something about this picture.",
            "I am speaking to you right now about your art.",
        ],
        .oMouth: [
            "Oh my goodness look at that big shape.",
            "Wow an open mouth big surprise on the page.",
            "Ooh that circle really pops out.",
        ],
        .happy: [
            "I love the colors you chose it looks cheerful.",
            "That is a beautiful happy patch of paint.",
            "Your picture makes me smile it is so nice.",
        ],
        .excited: [
            "I am so excited about how bright this is.",
            "This is super cool I cannot wait to see more.",
            "Your energy here feels really pumped up.",
        ],
        .surprised: [
            "Wow I did not expect that bold stroke.",
            "Whoa that really stands out amazing surprise.",
            "That is incredible I am astonished by this part.",
        ],
        .curious: [
            "I wonder what that part will become.",
            "Hmm interesting choice what is happening here.",
            "I am curious about this little corner you painted.",
        ],
        .thinking: [
            "Maybe you could try adding another color next.",
            "I am thinking about what might look good beside it.",
            "How about a gentle idea for the next step.",
        ],
        .supportive: [
            "Keep going you are doing great take your time.",
            "I am proud of you for sticking with it.",
            "You have got this I am right here cheering softly.",
        ],
        .caringHeart: [
            "That is so sweet and gentle I care about your art.",
            "Sending you a warm hug for this lovely picture.",
            "Your heart really shows in these soft colors.",
        ],
        .thumbsUp: [
            "Nice work that deserves a thumbs up.",
            "Well done you nailed that part.",
            "Good job I approve of how that turned out.",
        ],
        .celebrating: [
            "Yay hooray you did something fantastic.",
            "Lets celebrate this awesome splash of color.",
            "Party time that patch looks like a victory cheer.",
        ],
        .listening: [
            "Tell me more about what you were imagining.",
            "I am listening if you want to explain your idea.",
            "I hear you and I want to know your story.",
        ],
        .tapReaction: [
            "Oops a silly little messy moment that is funny.",
            "Uh oh playful smudge we can laugh about it.",
            "Whoops a tiny boop of paint went wild.",
        ],
        .sleepy: [
            "That soft part feels cozy like bedtime.",
            "Gentle yawn this corner looks sleepy and calm.",
            "Restful colors like a quiet nap time scene.",
        ],
    ]

    private static let embedLock = NSLock()
    private static var cachedUnitPrototypes: [MascotReactionState: [Double]]?

    /// Pick a catalog pose from the coach reply: explicit identifier, **sentence embedding** vs anchors, then keyword heuristics.
    static func mascotPoseFromCoachResponse(
        _ raw: String,
        avoidingRepeatOf last: MascotReactionState? = nil
    ) -> MascotReactionState {
        let cleaned = Self.stripControlNoise(raw)
        guard !cleaned.isEmpty else { return .neutral }

        if let explicit = Self.parseWholeWordReactionIdentifier(from: cleaned) {
            return Self.applyAvoidRepeat(best: explicit, score: 1.0, ranked: [(explicit, 1.0)], last: last)
        }

        if let picked = Self.poseFromSentenceEmbedding(cleaned, avoidingRepeatOf: last) {
            return picked
        }

        if let kw = Self.poseFromKeywordHeuristics(cleaned) {
            return Self.applyAvoidRepeat(best: kw, score: 0.75, ranked: [(kw, 0.75)], last: last)
        }

        return .neutral
    }

    /// Maps free-form model output to a catalog pose; returns nil if nothing recognized.
    static func parseMascotReaction(from raw: String) -> MascotReactionState? {
        let cleaned = Self.stripControlNoise(raw)
        guard !cleaned.isEmpty else { return nil }

        if let id = Self.parseWholeWordReactionIdentifier(from: cleaned) {
            return id
        }

        let lc = cleaned.lowercased()
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

    // MARK: - Whole-word identifier (model outputs `happy`, `surprised`, …)

    private static func parseWholeWordReactionIdentifier(from cleaned: String) -> MascotReactionState? {
        let lc = cleaned.lowercased()
        let namesByLength = MascotReactionState.allCases
            .map { String(describing: $0).lowercased() }
            .sorted { $0.count > $1.count }

        for name in namesByLength {
            if Self.containsWholeWord(lc, word: name) {
                return MascotReactionState.allCases.first { String(describing: $0).lowercased() == name }
            }
        }
        return nil
    }

    // MARK: - Sentence embedding match

    private static func poseFromSentenceEmbedding(
        _ cleaned: String,
        avoidingRepeatOf last: MascotReactionState?
    ) -> MascotReactionState? {
        guard let emb = NLEmbedding.sentenceEmbedding(for: .english) else { return nil }

        let text = String(cleaned.prefix(512))
        guard let textNums = emb.vector(for: text), !textNums.isEmpty else { return nil }
        let textVec = Self.l2Normalize(textNums) ?? []

        let protos = Self.unitPrototypes(embedding: emb)
        guard !protos.isEmpty else { return nil }

        var ranked: [(MascotReactionState, Double)] = []
        for (state, proto) in protos {
            let s = Self.dot(textVec, proto)
            ranked.append((state, s))
        }
        ranked.sort { $0.1 > $1.1 }

        guard let top = ranked.first else { return nil }
        /// Below this, open-vocabulary similarity is too weak — fall back to keywords.
        let minConfidence: Double = 0.18
        guard top.1 >= minConfidence else { return nil }

        if ranked.count >= 2 {
            let second = ranked[1]
            let margin = top.1 - second.1
            /// Ambiguous cloud — keywords often disambiguate better.
            if margin < 0.028 {
                return nil
            }
        }

        return Self.applyAvoidRepeat(best: top.0, score: top.1, ranked: ranked, last: last)
    }

    private static func applyAvoidRepeat(
        best: MascotReactionState,
        score: Double,
        ranked: [(MascotReactionState, Double)],
        last: MascotReactionState?
    ) -> MascotReactionState {
        guard let last, best == last, ranked.count >= 2 else { return best }
        let runner = ranked[1]
        /// If the top pose matches what we just showed, prefer a close runner-up so the mascot does not feel “stuck.”
        if runner.1 >= score - 0.08 {
            return runner.0
        }
        return best
    }

    private static func unitPrototypes(embedding emb: NLEmbedding) -> [MascotReactionState: [Double]] {
        embedLock.lock()
        defer { embedLock.unlock() }
        if let cached = cachedUnitPrototypes {
            return cached
        }

        var out: [MascotReactionState: [Double]] = [:]
        for state in MascotReactionState.allCases {
            let phrases = reactionAnchorPhrases[state] ?? []
            var vecs: [[Double]] = []
            for phrase in phrases {
                guard let nums = emb.vector(for: phrase), !nums.isEmpty else { continue }
                if let n = Self.l2Normalize(nums) {
                    vecs.append(n)
                }
            }
            guard !vecs.isEmpty else { continue }
            let dim = vecs[0].count
            var acc = [Double](repeating: 0, count: dim)
            for v in vecs {
                guard v.count == dim else { continue }
                for i in 0..<dim {
                    acc[i] += v[i]
                }
            }
            let inv = 1.0 / Double(vecs.count)
            let mean = acc.map { $0 * inv }
            if let unit = Self.l2Normalize(mean) {
                out[state] = unit
            }
        }
        cachedUnitPrototypes = out
        return out
    }

    private static func l2Normalize(_ v: [Double]) -> [Double]? {
        var s = 0.0
        for x in v { s += x * x }
        let n = sqrt(s)
        guard n > 1e-9 else { return nil }
        return v.map { $0 / n }
    }

    private static func dot(_ a: [Double], _ b: [Double]) -> Double {
        guard a.count == b.count, !a.isEmpty else { return 0 }
        var s = 0.0
        for i in 0..<a.count {
            s += a[i] * b[i]
        }
        return s
    }

    // MARK: - Keyword fallback

    private static func poseFromKeywordHeuristics(_ cleaned: String) -> MascotReactionState? {
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
