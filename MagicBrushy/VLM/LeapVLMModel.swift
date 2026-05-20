//
//  LeapVLMModel.swift
//  MagicBrushy
//
//  Simulator and device implementations are split so the Simulator target never references
//  Leap Swift APIs (Liquid’s GPU stack commonly abort()s the Simulator process).
//

import Foundation
import UIKit

extension Notification.Name {
    /// Posted when model download / load panel visibility or progress changes (home screen chip).
    static let leapVLMLoadPanelStateDidChange = Notification.Name("LeapVLMModel.loadPanelStateDidChange")
}

#if targetEnvironment(simulator)

@MainActor
final class LeapVLMModel {
    static let shared = LeapVLMModel()

    public enum ModelBadgeState: Equatable {
        case idleNotLoaded
        case downloading(progress: Double)
        case loadingIntoMemory
        case ready
        case failed(message: String)
        case simulatorPreview
    }

    public var running = false
    public var modelInfo = ""
    public var output = ""
    public var promptTime: String = ""

    public var modelBadgeState: ModelBadgeState { .simulatorPreview }

    public private(set) var isModelLoadPanelVisible = false
    public private(set) var modelDownloadProgressFraction: Double = 0
    public private(set) var modelLoadStatusText = ""
    public private(set) var modelLoadDidFail = false

    public var onModelLoadPanelStateChanged: (() -> Void)?

    var maxTokens = 240
    let displayEveryNTokens = 4

    private var currentTask: Task<Void, Never>?

    enum EvaluationState: String, CaseIterable {
        case idle = "Idle"
        case processingPrompt = "Processing Prompt"
        case generatingResponse = "Generating Response"
    }

    public var evaluationState = EvaluationState.idle

    private static let simulatorMessage =
        "The Leap VLM only runs reliably on device (Simulator GPU builds may abort). Use a physical iPad or iPhone to get AI coloring feedback."

    public init() {}

    private func notifyLoadPanelStateChanged() {
        onModelLoadPanelStateChanged?()
        NotificationCenter.default.post(name: .leapVLMLoadPanelStateDidChange, object: self)
    }

    public func prepareImageForModelPreview(_ image: UIImage) -> UIImage? {
        image
    }

    public func load() async {
        // No-op — never touch Liquid native layers in Simulator builds.
        modelInfo = "Simulator preview (no Leap)"
    }

    public func generate(
        image: UIImage,
        prompt: String,
        maxOutputTokens: Int? = nil,
        maxImageEdge: CGFloat = LeapVLMModel.coachMaxImageEdge,
        minDimensionFractionOfSource: CGFloat = 1.0 / 3.0
    ) async -> Task<Void, Never> {
        _ = image
        _ = prompt
        _ = maxOutputTokens
        _ = maxImageEdge
        _ = minDimensionFractionOfSource

        if let currentTask, running {
            return currentTask
        }

        running = true
        currentTask?.cancel()
        notifyLoadPanelStateChanged()

        let task = Task { @MainActor in
            self.output = Self.simulatorMessage
            MagicBrushyVLMDebugLog.response("Simulator", output: self.output)
            await self.finishInferenceSession()
        }
        currentTask = task
        return task
    }

    public func cancel() {
        currentTask?.cancel()
        currentTask = nil
        running = false
        output = ""
        promptTime = ""
        evaluationState = .idle
        notifyLoadPanelStateChanged()
    }

    private func finishInferenceSession() async {
        if evaluationState == .generatingResponse {
            evaluationState = .idle
        }
        running = false
        notifyLoadPanelStateChanged()
    }
}

#else

import LeapSDK

@MainActor
final class LeapVLMModel {
    static let shared = LeapVLMModel()

    public enum ModelBadgeState: Equatable {
        case idleNotLoaded
        case downloading(progress: Double)
        case loadingIntoMemory
        case ready
        case failed(message: String)
        case simulatorPreview
    }

    public var running = false
    public var modelInfo = ""
    public var output = ""
    public var promptTime: String = ""

    public private(set) var isModelLoadPanelVisible = false
    public private(set) var modelDownloadProgressFraction: Double = 0
    public private(set) var modelLoadStatusText = ""
    public private(set) var modelLoadDidFail = false

    private enum ModelLoadPhase {
        case idle
        case downloading
        case loadingIntoMemory
    }

    private var modelLoadPhase: ModelLoadPhase = .idle
    /// Display-only; never moves backward during a single download attempt.
    private var peakDownloadProgressFraction: Double = 0
    /// After this fraction the file is on disk; remaining work is load-into-memory (Leap often never sends exactly 1.0).
    private static let downloadFinishedProgressThreshold = 0.99
    private static let modelBundleOnDiskKey = "magicBrushy.vlmModelBundleOnDisk"

    private static var hasModelBundleOnDisk: Bool {
        UserDefaults.standard.bool(forKey: modelBundleOnDiskKey)
    }

    private static func markModelBundleOnDisk() {
        UserDefaults.standard.set(true, forKey: modelBundleOnDiskKey)
    }

    /// True when the GGUF bundle is already present (persisted flag or on-disk scan for upgrades).
    private static func modelBundleIsAvailableLocally() -> Bool {
        if hasModelBundleOnDisk { return true }
        let fm = FileManager.default
        let roots = [
            fm.urls(for: .applicationSupportDirectory, in: .userDomainMask).first,
            fm.urls(for: .cachesDirectory, in: .userDomainMask).first,
        ].compactMap { $0 }
        for root in roots {
            guard let enumerator = fm.enumerator(
                at: root,
                includingPropertiesForKeys: nil,
                options: [.skipsHiddenFiles]
            ) else { continue }
            for case let url as URL in enumerator {
                guard url.pathExtension.lowercased() == "gguf" else { continue }
                if url.lastPathComponent.localizedCaseInsensitiveContains(modelName) {
                    markModelBundleOnDisk()
                    return true
                }
            }
        }
        return false
    }

    /// Shown next to an on-screen status dot (download / loaded / failure).
    public var modelBadgeState: ModelBadgeState {
        if modelRunner != nil { return .ready }
        if modelLoadDidFail { return .failed(message: modelLoadStatusText.isEmpty ? "Load error" : modelLoadStatusText) }
        if isModelLoadPanelVisible {
            switch modelLoadPhase {
            case .downloading:
                return .downloading(progress: modelDownloadProgressFraction)
            case .loadingIntoMemory:
                return .loadingIntoMemory
            case .idle:
                break
            }
        }
        return .idleNotLoaded
    }

    public var onModelLoadPanelStateChanged: (() -> Void)?

    private static let modelName = "LFM2.5-VL-1.6B"
    private static let quantization = "Q4_0"
    /// Upper bound for vision encoder input (longest edge in **pixels**).
    private static let maxImageEdge: CGFloat = 512
    /// Coach calls (stroke / whole-page) use a smaller cap for faster on-device inference.
    static let coachMaxImageEdge: CGFloat = 384
    /// Page-open welcome: smaller image → fewer vision tokens and faster prefill.
    static let coachPageLoadMaxImageEdge: CGFloat = 288

    var maxTokens = 240
    let displayEveryNTokens = 4
    public private(set) var lastPromptSent = ""
    public private(set) var lastImageSizeSent: CGSize = .zero
    public private(set) var lastJpegByteCountSent: Int = 0

    private var modelRunner: (any ModelRunner)?
    private var currentTask: Task<Void, Never>?
    private var pendingLoadTask: Task<Void, Never>?

    enum EvaluationState: String, CaseIterable {
        case idle = "Idle"
        case processingPrompt = "Processing Prompt"
        case generatingResponse = "Generating Response"
    }

    public var evaluationState = EvaluationState.idle

    public init() {}

    private func notifyLoadPanelStateChanged() {
        onModelLoadPanelStateChanged?()
        NotificationCenter.default.post(name: .leapVLMLoadPanelStateDidChange, object: self)
    }

    public func prepareImageForModelPreview(
        _ image: UIImage,
        minDimensionFractionOfSource: CGFloat = 1.0 / 3.0
    ) -> UIImage? {
        Self.resizedImage(
            from: image,
            maxEdge: Self.maxImageEdge,
            minDimensionFractionOfSource: minDimensionFractionOfSource
        )
    }

    private func publishLoadPanel(visible: Bool, progress: Double, status: String, failed: Bool) {
        isModelLoadPanelVisible = visible
        modelDownloadProgressFraction = min(1, max(0, progress))
        modelLoadStatusText = status
        modelLoadDidFail = failed
        if failed {
            modelLoadPhase = .idle
            peakDownloadProgressFraction = 0
        }
        modelInfo = status
        notifyLoadPanelStateChanged()
    }

    private func hideLoadPanelLoaded() {
        Self.markModelBundleOnDisk()
        isModelLoadPanelVisible = false
        modelDownloadProgressFraction = 1
        modelLoadDidFail = false
        modelLoadStatusText = ""
        modelLoadPhase = .idle
        peakDownloadProgressFraction = 0
        modelInfo = "Loaded"
        notifyLoadPanelStateChanged()
    }

    private func publishDownloadProgress(_ rawProgress: Double) {
        guard modelLoadPhase != .loadingIntoMemory else { return }
        modelLoadPhase = .downloading
        let clamped = min(1, max(0, rawProgress))
        peakDownloadProgressFraction = max(peakDownloadProgressFraction, clamped)
        modelDownloadProgressFraction = peakDownloadProgressFraction
        let pct = Int((peakDownloadProgressFraction * 100).rounded(.down))
        modelLoadStatusText = "Downloading model… \(pct)%"
        modelLoadDidFail = false
        isModelLoadPanelVisible = true
        modelInfo = modelLoadStatusText
        notifyLoadPanelStateChanged()
    }

    private func publishLoadingIntoMemory() {
        Self.markModelBundleOnDisk()
        modelLoadPhase = .loadingIntoMemory
        modelDownloadProgressFraction = 1
        modelLoadStatusText = "Loading model into memory…"
        modelLoadDidFail = false
        isModelLoadPanelVisible = true
        modelInfo = modelLoadStatusText
        notifyLoadPanelStateChanged()
    }

    private func resetLoadAttemptState() {
        modelLoadDidFail = false
        isModelLoadPanelVisible = true
        peakDownloadProgressFraction = 0
        modelDownloadProgressFraction = 0
        if Self.modelBundleIsAvailableLocally() {
            publishLoadingIntoMemory()
        } else {
            modelLoadPhase = .downloading
            modelLoadStatusText = "Downloading model… 0%"
            modelInfo = modelLoadStatusText
            notifyLoadPanelStateChanged()
        }
    }

    private func _load() async throws {
        if modelRunner != nil {
            hideLoadPanelLoaded()
            return
        }

        if let existing = pendingLoadTask {
            await existing.value
            if modelRunner == nil {
                throw NSError(domain: "LeapVLMModel", code: -1,
                              userInfo: [NSLocalizedDescriptionKey: "Model failed to load"])
            }
            return
        }

        resetLoadAttemptState()
        UIApplication.shared.isIdleTimerDisabled = true
        defer { UIApplication.shared.isIdleTimerDisabled = false }

        let task = Task<Void, Never> { @MainActor [weak self] in
            guard let self else { return }
            do {
                let runner = try await Leap.shared.load(
                    model: Self.modelName,
                    quantization: Self.quantization,
                    progress: { [weak self] progress, _ in
                        Task { @MainActor in
                            guard let self else { return }
                            let fraction = Double(progress)
                            if self.modelLoadPhase == .loadingIntoMemory {
                                return
                            }
                            if fraction >= 1.0 || fraction >= Self.downloadFinishedProgressThreshold {
                                self.publishDownloadProgress(1.0)
                                self.publishLoadingIntoMemory()
                            } else if Self.modelBundleIsAvailableLocally() {
                                // Cached bundle: low progress values are load-into-memory, not download.
                                self.publishLoadingIntoMemory()
                            } else {
                                self.publishDownloadProgress(fraction)
                            }
                        }
                    }
                )
                self.modelRunner = runner
                self.hideLoadPanelLoaded()
            } catch {
                self.modelLoadPhase = .idle
                self.peakDownloadProgressFraction = 0
                self.publishLoadPanel(
                    visible: true,
                    progress: 0,
                    status: "Couldn’t load model: \(error.localizedDescription)",
                    failed: true)
            }
            self.pendingLoadTask = nil
        }
        pendingLoadTask = task
        await task.value

        if modelRunner == nil {
            throw NSError(domain: "LeapVLMModel", code: -1,
                          userInfo: [NSLocalizedDescriptionKey: "Model failed to load"])
        }
    }

    public func load() async {
        do {
            try await _load()
        } catch {
            publishLoadPanel(
                visible: true,
                progress: 0,
                status: "Couldn’t load model: \(error.localizedDescription)",
                failed: true)
        }
    }

    private func finishInferenceSession() async {
        if evaluationState == .generatingResponse {
            evaluationState = .idle
        }
        running = false
        notifyLoadPanelStateChanged()
    }

    public func generate(
        image: UIImage,
        prompt: String,
        maxOutputTokens: Int? = nil,
        maxImageEdge: CGFloat = LeapVLMModel.coachMaxImageEdge,
        minDimensionFractionOfSource: CGFloat = 1.0 / 3.0
    ) async -> Task<Void, Never> {

        if let currentTask, running {
            return currentTask
        }

        running = true
        currentTask?.cancel()
        notifyLoadPanelStateChanged()

        let tokenCap = maxOutputTokens.map { max(8, $0) } ?? maxTokens
        let charBudget = max(32, tokenCap * 5)
        let displayStride = displayEveryNTokens

        let task = Task { @MainActor in
            do {
                try await self._load()
                if Task.isCancelled {
                    await self.finishInferenceSession()
                    return
                }

                guard let runner = self.modelRunner else {
                    self.output = "Failed: model not loaded"
                    await self.finishInferenceSession()
                    return
                }

                guard let jpegData = Self.resizedJPEGData(
                    from: image,
                    maxEdge: maxImageEdge,
                    minDimensionFractionOfSource: minDimensionFractionOfSource
                ) else {
                    self.output = "Failed: could not encode image"
                    await self.finishInferenceSession()
                    return
                }

                self.lastPromptSent = prompt
                self.lastImageSizeSent = image.size
                self.lastJpegByteCountSent = jpegData.count

                self.evaluationState = .processingPrompt
                self.output = ""

                let llmStart = Date()
                let imageContent = ChatMessageContent.fromJPEGData(jpegData)
                let message = ChatMessage(
                    role: .user,
                    content: [imageContent as ChatMessageContent, ChatMessageContent.text(prompt)],
                    reasoningContent: nil,
                    functionCalls: nil
                )

                let conversation = runner.createConversation(systemPrompt: nil)
                var seenFirstToken = false
                var accumulated = ""
                var chunkIndex = 0

                streaming: for try await resp in conversation.generateResponse(message: message) {
                    if Task.isCancelled { break streaming }

                    switch onEnum(of: resp) {
                    case .chunk(let chunk):
                        accumulated.append(chunk.text)
                        chunkIndex += 1
                        if !seenFirstToken, !chunk.text.isEmpty {
                            seenFirstToken = true
                            let ms = Int(Date().timeIntervalSince(llmStart) * 1000)
                            self.evaluationState = .generatingResponse
                            self.promptTime = "\(ms) ms"
                        }
                        if chunkIndex % displayStride == 0 || accumulated.count >= charBudget {
                            self.output = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(accumulated)
                        }
                        if accumulated.count >= charBudget {
                            break streaming
                        }
                    case .complete:
                        break streaming
                    default:
                        break
                    }
                }

                if !Task.isCancelled {
                    self.output = MagicBrushyVLMOutputCleanup.sanitizeKidFeedback(accumulated)
                    MagicBrushyVLMDebugLog.response(
                        "Generate",
                        output: self.output,
                        promptTime: self.promptTime,
                        rawBeforeCleanup: accumulated
                    )
                }
            } catch {
                if !Task.isCancelled {
                    self.output = "Failed: \(error.localizedDescription)"
                    MagicBrushyVLMDebugLog.response("Generate", output: self.output, promptTime: self.promptTime)
                }
            }
            await self.finishInferenceSession()
        }

        currentTask = task
        return task
    }

    public func cancel() {
        currentTask?.cancel()
        currentTask = nil
        running = false
        output = ""
        promptTime = ""
        evaluationState = .idle
        notifyLoadPanelStateChanged()
    }

    private static func resizedJPEGData(
        from image: UIImage,
        maxEdge: CGFloat,
        minDimensionFractionOfSource: CGFloat = 1.0 / 3.0
    ) -> Data? {
        guard let resized = resizedImage(
            from: image,
            maxEdge: maxEdge,
            minDimensionFractionOfSource: minDimensionFractionOfSource
        ) else { return nil }
        return resized.jpegData(compressionQuality: 0.9)
    }

    /// Downscales for the VLM cap but never below `minDimensionFractionOfSource` of the source pixel width or height.
    private static func resizedImage(
        from image: UIImage,
        maxEdge: CGFloat,
        minDimensionFractionOfSource: CGFloat = 1.0 / 3.0
    ) -> UIImage? {
        let srcPixelW = image.size.width * image.scale
        let srcPixelH = image.size.height * image.scale
        guard srcPixelW > 0.5, srcPixelH > 0.5 else { return nil }

        let fraction = min(1, max(0.1, minDimensionFractionOfSource))
        // minW/minH are capped at maxEdge so this constraint never inflates the image above the model's cap.
        let minW = min(srcPixelW * fraction, maxEdge)
        let minH = min(srcPixelH * fraction, maxEdge)
        var w = srcPixelW
        var h = srcPixelH
        let downscale = min(maxEdge / w, maxEdge / h, 1)
        w *= downscale
        h *= downscale
        w = max(w, minW)
        h = max(h, minH)

        let newSize = CGSize(width: max(1, floor(w)), height: max(1, floor(h)))
        let format = UIGraphicsImageRendererFormat()
        format.scale = 1
        format.opaque = true
        let renderer = UIGraphicsImageRenderer(size: newSize, format: format)
        return renderer.image { _ in
            image.draw(in: CGRect(origin: .zero, size: newSize))
        }
    }
}

#endif

// MARK: - Kid feedback cleanup (prompt echo + chat template leakage)

enum MagicBrushyVLMOutputCleanup {

    /// Strips Leap/Llama style control tokens (`<|...|>`), log-style junk, echoed instructions, assistant markers.
    static func sanitizeKidFeedback(_ raw: String) -> String {
        var s = raw.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !s.isEmpty else { return "" }

        if let re = try? NSRegularExpression(pattern: #"<\|[^>]+>"#, options: []) {
            let full = NSRange(s.startIndex..., in: s)
            s = re.stringByReplacingMatches(in: s, options: [], range: full, withTemplate: "").trimmingCharacters(in: .whitespacesAndNewlines)
        }

        let logJunkMarks = ["encoding image slice", "image slice encoded", "decoding image batch", "[2026-", "[INFO"]
        for mark in logJunkMarks {
            if let r = s.range(of: mark, options: .caseInsensitive) {
                s = String(s[..<r.lowerBound]).trimmingCharacters(in: .whitespacesAndNewlines)
            }
        }

        if let assistantRange = s.range(of: "<|im_start|>assistant", options: [.caseInsensitive, .backwards]) {
            let tail = String(s[assistantRange.upperBound...]).trimmingCharacters(in: .whitespacesAndNewlines)
            if tail.count >= 4 { s = tail }
        }

        let bannedFragments = [
            "say exactly one", "tiny easy words", "never say ai", "keyword lists",
            "do not cram", "talk to a small child",
            "only name something if",
            "important: reply with only",
            "output rule:",
        ]

        let lines = s.split { $0.isNewline }.map(String.init).map { $0.trimmingCharacters(in: .whitespaces) }.filter { !$0.isEmpty }

        var rest = lines
        while let first = rest.first {
            let lf = first.trimmingCharacters(in: .whitespaces)
            guard lf.caseInsensitiveCompare("assistant") == .orderedSame || lf.caseInsensitiveCompare("assistant:") == .orderedSame
            else { break }
            rest.removeFirst()
        }

        let kept = rest.filter { line in
            let lc = line.lowercased()
            return !bannedFragments.contains(where: lc.contains)
        }

        let joined = kept.joined(separator: " ").trimmingCharacters(in: .whitespacesAndNewlines)
        if joined.count >= 4 {
            s = joined
        }

        while s.contains("  ") { s = s.replacingOccurrences(of: "  ", with: " ") }

        s = stripStaleYouHaveOpeners(s)
        s = rewriteThirdPersonCoachLines(s)

        return s.trimmingCharacters(in: .whitespacesAndNewlines)
    }

    /// Models often echo prompt wording (“They are coloring…”) despite instructions—rewrite for TTS.
    private static func rewriteThirdPersonCoachLines(_ raw: String) -> String {
        var s = raw
        let pairs: [(String, String)] = [
            ("They are coloring", "You're coloring"),
            ("they are coloring", "you're coloring"),
            ("They are ", "You're "),
            ("they are ", "you're "),
            ("They're coloring", "You're coloring"),
            ("they're coloring", "you're coloring"),
            ("Their ", "Your "),
            ("their ", "your "),
            ("The child is coloring", "You're coloring"),
            ("the child is coloring", "you're coloring"),
        ]
        for (from, to) in pairs {
            s = s.replacingOccurrences(of: from, with: to)
        }
        return s
    }

    /// Models often echo “You have a …” when naming the scene; prompt discourages it—strip if it still leaks through.
    private static func stripStaleYouHaveOpeners(_ raw: String) -> String {
        let t = raw.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !t.isEmpty else { return t }
        let lower = t.lowercased()
        let prefixes = [
            "you have a ",
            "you have an ",
            "you've got a ",
            "you've got an ",
            "you have the ",
        ]
        for p in prefixes where lower.hasPrefix(p) {
            var rest = String(t.dropFirst(p.count)).trimmingCharacters(in: .whitespacesAndNewlines)
            guard !rest.isEmpty else { return t }
            if let first = rest.first {
                rest = String(first).uppercased() + rest.dropFirst()
            }
            return rest
        }
        return t
    }
}

// MARK: - Debug logging

#if DEBUG
enum MagicBrushyVLMDebugLog {
    static func response(
        _ tag: String,
        output: String,
        promptTime: String = "",
        rawBeforeCleanup: String? = nil
    ) {
        let timing = promptTime.isEmpty ? "" : " first-token \(promptTime)"
        print("[Brushi][VLM][\(tag)]\(timing)\n\(output)")
        if let raw = rawBeforeCleanup,
           raw.trimmingCharacters(in: .whitespacesAndNewlines) != output.trimmingCharacters(in: .whitespacesAndNewlines) {
            print("[Brushi][VLM][\(tag)][raw]\n\(raw)")
        }
    }
}
#else
enum MagicBrushyVLMDebugLog {
    static func response(
        _ tag: String,
        output: String,
        promptTime: String = "",
        rawBeforeCleanup: String? = nil
    ) {}
}
#endif
