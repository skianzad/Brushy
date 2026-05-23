//
//  VLMCoachOnDemandResources.swift
//  MagicBrushy
//
//  Art-coach weights ship as an App Store On-Demand Resource tag (`vlm-coach-model`).
//  See OnDemandResources/README.md for staging GGUF files into the Xcode project.
//

import Foundation

#if !targetEnvironment(simulator)

/// Fetches the `vlm-coach-model` ODR pack and materializes GGUF files under Application Support.
enum VLMCoachOnDemandResources {

    static let tag = "vlm-coach-model"
    static let bundleSubdirectory = "VLMCoachModel"
    static let installedVersionKey = "magicBrushy.vlmCoachODRInstalledVersion"

    struct ResolvedWeights: Equatable {
        let gguf: URL
        let mmproj: URL?
    }

    /// True when the app bundle includes the ODR pack marker (version JSON in `VLMCoachModel/`).
    static var isPackConfiguredInApp: Bool {
        Bundle.main.url(
            forResource: "vlm-coach-model-version",
            withExtension: "json",
            subdirectory: bundleSubdirectory
        ) != nil
    }

    /// Weights already copied to Application Support (survives ODR purge).
    static func resolvedWeightsOnDisk() -> ResolvedWeights? {
        guard let root = persistentStoreDirectory(),
              FileManager.default.fileExists(atPath: root.path) else { return nil }
        return scanWeights(in: root)
    }

    /// Ensures ODR is on device, copies into Application Support, returns local paths for Leap.
    static func ensureMaterialized(progress: @escaping (Double) -> Void) async throws -> ResolvedWeights {
        if let existing = resolvedWeightsOnDisk(),
           installedVersionMatchesBundle() {
            progress(1)
            return existing
        }

        guard isPackConfiguredInApp else {
            throw VLMCoachODRError.packNotConfigured
        }

        let request = NSBundleResourceRequest(tags: [tag])
        request.loadingPriority = NSBundleResourceRequestLoadingPriorityUrgent

        let progressObservation = request.progress.observe(\.fractionCompleted) { observed, _ in
            progress(min(1, max(0, observed.fractionCompleted)))
        }

        defer { progressObservation.invalidate() }

        try await withCheckedThrowingContinuation { (continuation: CheckedContinuation<Void, Error>) in
            request.beginAccessingResources { error in
                if let error {
                    continuation.resume(throwing: error)
                } else {
                    continuation.resume()
                }
            }
        }

        defer { request.endAccessingResources() }

        guard let bundleRoot = bundleResourceDirectory() else {
            throw VLMCoachODRError.missingBundleDirectory
        }
        guard let resolved = try copyWeights(from: bundleRoot) else {
            throw VLMCoachODRError.missingGGUF
        }
        persistInstalledVersionFromBundle()
        progress(1)
        return resolved
    }

    // MARK: - Private

    enum VLMCoachODRError: Error, LocalizedError, Equatable {
        case packNotConfigured
        case missingBundleDirectory
        case missingGGUF

        var errorDescription: String? {
            switch self {
            case .packNotConfigured:
                return "Art coach model pack is not bundled for on-demand download."
            case .missingBundleDirectory:
                return "Could not find the art coach model folder after download."
            case .missingGGUF:
                return "Art coach model files are missing. Add LFM2.5-VL GGUF weights to the ODR pack."
            }
        }
    }

    private static func persistentStoreDirectory() -> URL? {
        guard let base = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask).first else {
            return nil
        }
        return base
            .appendingPathComponent("MagicBrushy", isDirectory: true)
            .appendingPathComponent(bundleSubdirectory, isDirectory: true)
    }

    private static func bundleResourceDirectory() -> URL? {
        if let resource = Bundle.main.resourceURL {
            let subdir = resource.appendingPathComponent(bundleSubdirectory, isDirectory: true)
            if FileManager.default.fileExists(atPath: subdir.path),
               directoryContainsCoachGGUF(subdir) {
                return subdir
            }
            if directoryContainsCoachGGUF(resource) {
                return resource
            }
        }
        if let url = Bundle.main.url(forResource: bundleSubdirectory, withExtension: nil),
           directoryContainsCoachGGUF(url) {
            return url
        }
        return nil
    }

    private static func directoryContainsCoachGGUF(_ directory: URL) -> Bool {
        guard let entries = try? FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil) else {
            return false
        }
        return entries.contains { url in
            guard url.pathExtension.lowercased() == "gguf" else { return false }
            let name = url.lastPathComponent.lowercased()
            return name.contains("lfm2.5-vl") || name.contains("lfm2.5_vl")
        }
    }

    private static func installedVersionMatchesBundle() -> Bool {
        guard let bundleVersion = readBundleVersion() else { return false }
        let installed = UserDefaults.standard.integer(forKey: installedVersionKey)
        return installed == bundleVersion
    }

    private static func persistInstalledVersionFromBundle() {
        if let version = readBundleVersion() {
            UserDefaults.standard.set(version, forKey: installedVersionKey)
        }
    }

    private static func readBundleVersion() -> Int? {
        guard let url = Bundle.main.url(
            forResource: "vlm-coach-model-version",
            withExtension: "json",
            subdirectory: bundleSubdirectory
        ),
              let data = try? Data(contentsOf: url),
              let json = try? JSONSerialization.jsonObject(with: data) as? [String: Any],
              let version = json["version"] as? Int else {
            return nil
        }
        return version
    }

    @discardableResult
    private static func copyWeights(from sourceRoot: URL) throws -> ResolvedWeights? {
        let fm = FileManager.default
        guard let destRoot = persistentStoreDirectory() else { return nil }
        try fm.createDirectory(at: destRoot, withIntermediateDirectories: true)

        let entries = try fm.contentsOfDirectory(at: sourceRoot, includingPropertiesForKeys: nil)
        for source in entries where source.pathExtension.lowercased() == "gguf" {
            let dest = destRoot.appendingPathComponent(source.lastPathComponent)
            if fm.fileExists(atPath: dest.path) {
                try fm.removeItem(at: dest)
            }
            try fm.copyItem(at: source, to: dest)
        }

        return scanWeights(in: destRoot)
    }

    private static func scanWeights(in directory: URL) -> ResolvedWeights? {
        let fm = FileManager.default
        guard let entries = try? fm.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil) else {
            return nil
        }
        let gguFs = entries.filter { $0.pathExtension.lowercased() == "gguf" }
        let main = gguFs.first { url in
            let name = url.lastPathComponent.lowercased()
            return name.contains("lfm") && !name.contains("mmproj")
        } ?? gguFs.first { !$0.lastPathComponent.lowercased().contains("mmproj") }
        let mmproj = gguFs.first { $0.lastPathComponent.lowercased().contains("mmproj") }
        guard let main else { return nil }
        return ResolvedWeights(gguf: main, mmproj: mmproj)
    }
}

#endif
