//
//  LeapVLMModel.swift
//  MagicBrushy
//
//  Simulator and device implementations are split so the Simulator target never references
//  Leap Swift APIs (Liquid’s GPU stack commonly abort()s the Simulator process).
//

import Foundation
import UIKit

#if targetEnvironment(simulator)

@MainActor
final class LeapVLMModel {

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

    public func load() async {
        // No-op — never touch Liquid native layers in Simulator builds.
        modelInfo = "Simulator preview (no Leap)"
    }

    public func generate(
        image: UIImage,
        prompt: String,
        maxOutputTokens: Int? = nil
    ) async -> Task<Void, Never> {
        _ = image
        _ = prompt
        _ = maxOutputTokens

        if let currentTask, running {
            return currentTask
        }

        running = true
        currentTask?.cancel()
        onModelLoadPanelStateChanged?()

        let task = Task { @MainActor in
            self.output = Self.simulatorMessage
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
        onModelLoadPanelStateChanged?()
    }

    private func finishInferenceSession() async {
        if evaluationState == .generatingResponse {
            evaluationState = .idle
        }
        running = false
        onModelLoadPanelStateChanged?()
    }
}

#else

import LeapSDK

@MainActor
final class LeapVLMModel {

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

    /// Shown next to an on-screen status dot (download / loaded / failure).
    public var modelBadgeState: ModelBadgeState {
        if modelRunner != nil { return .ready }
        if modelLoadDidFail { return .failed(message: modelLoadStatusText.isEmpty ? "Load error" : modelLoadStatusText) }
        if isModelLoadPanelVisible {
            if modelDownloadProgressFraction < 1 - 1e-6 { return .downloading(progress: modelDownloadProgressFraction) }
            return .loadingIntoMemory
        }
        return .idleNotLoaded
    }

    public var onModelLoadPanelStateChanged: (() -> Void)?

    private static let modelName = "LFM2.5-VL-1.6B"
    private static let quantization = "Q4_0"
    private static let maxImageEdge: CGFloat = 512

    var maxTokens = 240
    let displayEveryNTokens = 4

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

    private func publishLoadPanel(visible: Bool, progress: Double, status: String, failed: Bool) {
        isModelLoadPanelVisible = visible
        modelDownloadProgressFraction = min(1, max(0, progress))
        modelLoadStatusText = status
        modelLoadDidFail = failed
        modelInfo = status
        onModelLoadPanelStateChanged?()
    }

    private func hideLoadPanelLoaded() {
        isModelLoadPanelVisible = false
        modelDownloadProgressFraction = 1
        modelLoadDidFail = false
        modelLoadStatusText = ""
        modelInfo = "Loaded"
        onModelLoadPanelStateChanged?()
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

        publishLoadPanel(
            visible: true,
            progress: 0,
            status: "Downloading \(Self.modelName)…",
            failed: false)

        let task = Task<Void, Never> { @MainActor [weak self] in
            guard let self else { return }
            do {
                let runner = try await Leap.shared.load(
                    model: Self.modelName,
                    quantization: Self.quantization,
                    progress: { [weak self] progress, _ in
                        Task { @MainActor in
                            guard let self else { return }
                            if progress < 1.0 {
                                let pct = Int((progress * 100).rounded(.down))
                                self.publishLoadPanel(
                                    visible: true,
                                    progress: Double(progress),
                                    status: "Downloading \(Self.modelName)… \(pct)%",
                                    failed: false)
                            } else {
                                self.publishLoadPanel(
                                    visible: true,
                                    progress: 1,
                                    status: "Loading model into memory…",
                                    failed: false)
                            }
                        }
                    }
                )
                self.modelRunner = runner
                self.hideLoadPanelLoaded()
            } catch {
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
        onModelLoadPanelStateChanged?()
    }

    public func generate(
        image: UIImage,
        prompt: String,
        maxOutputTokens: Int? = nil
    ) async -> Task<Void, Never> {

        if let currentTask, running {
            return currentTask
        }

        running = true
        currentTask?.cancel()
        onModelLoadPanelStateChanged?()

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

                guard let jpegData = Self.resizedJPEGData(from: image, maxEdge: Self.maxImageEdge) else {
                    self.output = "Failed: could not encode image"
                    await self.finishInferenceSession()
                    return
                }

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
                }
            } catch {
                if !Task.isCancelled {
                    self.output = "Failed: \(error.localizedDescription)"
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
        onModelLoadPanelStateChanged?()
    }

    private static func resizedJPEGData(from image: UIImage, maxEdge: CGFloat) -> Data? {
        let size = image.size
        guard size.width > 0, size.height > 0 else { return nil }

        let ratio = min(maxEdge / size.width, maxEdge / size.height, 1)
        let newSize = CGSize(width: size.width * ratio, height: size.height * ratio)

        let renderer = UIGraphicsImageRenderer(size: newSize)
        let resized = renderer.image { _ in
            image.draw(in: CGRect(origin: .zero, size: newSize))
        }
        return resized.jpegData(compressionQuality: 0.9)
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

        return s.trimmingCharacters(in: .whitespacesAndNewlines)
    }
}
