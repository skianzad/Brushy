import UIKit

/// Persists per-page coloring progress for template (non-free-drawing) pages.
/// One JPEG per pack+page is stored in Application Support; old saves are silently
/// overwritten each time the child returns to the home screen.
enum TemplateProgressStore {

    private static var directoryURL: URL {
        let base = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask).first!
        let dir = base.appendingPathComponent("MagicBrushy/TemplateProgress", isDirectory: true)
        try? FileManager.default.createDirectory(at: dir, withIntermediateDirectories: true, attributes: nil)
        return dir
    }

    private static func fileURL(packId: String, pageIndex: Int) -> URL {
        let safe = packId.replacingOccurrences(of: "/", with: "_")
        return directoryURL.appendingPathComponent("tpl_\(safe)_\(pageIndex).jpg")
    }

    // MARK: – Public API

    static func save(packId: String, pageIndex: Int, underlay: UIImage) {
        guard let data = underlay.jpegData(compressionQuality: 0.9) else { return }
        let url = fileURL(packId: packId, pageIndex: pageIndex)
        try? data.write(to: url, options: .atomic)
    }

    static func load(packId: String, pageIndex: Int) -> UIImage? {
        let resolved = BuiltInColoringPages.resolvePackId(packId)
        if let image = loadFile(packId: resolved, pageIndex: pageIndex) { return image }
        if packId != resolved, let image = loadFile(packId: packId, pageIndex: pageIndex) { return image }
        for legacyId in BuiltInColoringPages.legacyPackIds(forResolvedId: resolved) {
            if let image = loadFile(packId: legacyId, pageIndex: pageIndex) { return image }
        }
        return nil
    }

    private static func loadFile(packId: String, pageIndex: Int) -> UIImage? {
        let url = fileURL(packId: packId, pageIndex: pageIndex)
        return UIImage(contentsOfFile: url.path)
    }

    struct ProgressRef: Equatable {
        let packId: String
        let pageIndex: Int
        let updatedAt: Date
    }

    /// Most recently saved template coloring (by file modification time).
    static func newestProgress() -> ProgressRef? {
        let dir = directoryURL
        guard let names = try? FileManager.default.contentsOfDirectory(atPath: dir.path) else { return nil }
        var best: ProgressRef?
        for name in names {
            guard let parsed = parseProgressFileName(name) else { continue }
            let url = dir.appendingPathComponent(name)
            let mod = (try? FileManager.default.attributesOfItem(atPath: url.path)[.modificationDate] as? Date)
                ?? .distantPast
            let ref = ProgressRef(packId: parsed.packId, pageIndex: parsed.pageIndex, updatedAt: mod)
            if best == nil || ref.updatedAt > best!.updatedAt {
                best = ref
            }
        }
        return best
    }

    private static func parseProgressFileName(_ name: String) -> (packId: String, pageIndex: Int)? {
        guard name.hasPrefix("tpl_"), name.hasSuffix(".jpg") else { return nil }
        let stem = String(name.dropFirst(4).dropLast(4))
        guard let sep = stem.lastIndex(of: "_") else { return nil }
        let pageStr = stem[stem.index(after: sep)...]
        guard let pageIndex = Int(pageStr) else { return nil }
        let packId = String(stem[..<sep])
        guard !packId.isEmpty else { return nil }
        return (packId, pageIndex)
    }

    static func delete(packId: String, pageIndex: Int) {
        try? FileManager.default.removeItem(at: fileURL(packId: packId, pageIndex: pageIndex))
    }

    static func deleteAll(packId: String) {
        let safe = packId.replacingOccurrences(of: "/", with: "_")
        let dir = directoryURL
        let prefix = "tpl_\(safe)_"
        guard let files = try? FileManager.default.contentsOfDirectory(atPath: dir.path) else { return }
        for name in files where name.hasPrefix(prefix) {
            try? FileManager.default.removeItem(at: dir.appendingPathComponent(name))
        }
    }

    /// Default cap when the grid has not laid out yet (still far above the old 280px shelf thumbs).
    static let defaultShelfPreviewMaxPixelSide: CGFloat = 1024

    /// Preview for category thumbnails: saved underlay (template + strokes, no outlines) plus line art on top, matching on-canvas stacking.
    /// - Parameter maxPixelSide: Target longest edge in **pixels**; pass cell image area × screen scale from the grid.
    static func shelfPreviewImage(
        templatePageImage: UIImage,
        savedUnderlay: UIImage,
        maxPixelSide: CGFloat = defaultShelfPreviewMaxPixelSide
    ) -> UIImage {
        let lineArt = templatePageImage.magicBrushyLineArtOverlay()
        let underlayPixelsW = savedUnderlay.size.width * savedUnderlay.scale
        let underlayPixelsH = savedUnderlay.size.height * savedUnderlay.scale
        let longest = max(underlayPixelsW, underlayPixelsH, 1)
        let cap = max(320, maxPixelSide)
        let scaleDown = min(1, cap / longest)
        let outPixelsW = max(1, floor(underlayPixelsW * scaleDown))
        let outPixelsH = max(1, floor(underlayPixelsH * scaleDown))
        let outSize = CGSize(width: outPixelsW, height: outPixelsH)
        let bounds = CGRect(origin: .zero, size: outSize)

        let format = UIGraphicsImageRendererFormat()
        format.scale = 1
        format.opaque = true

        return UIGraphicsImageRenderer(size: outSize, format: format).image { ctx in
            ctx.cgContext.interpolationQuality = .high
            UIColor.white.setFill()
            UIBezierPath(rect: bounds).fill()
            savedUnderlay.draw(in: aspectFitRect(for: savedUnderlay, in: bounds))
            lineArt.draw(in: aspectFitRect(for: lineArt, in: bounds))
        }
    }

    private static func aspectFitRect(for image: UIImage, in bounds: CGRect) -> CGRect {
        let sz = image.size
        guard sz.width > 0.5, sz.height > 0.5, bounds.width > 0.5, bounds.height > 0.5 else { return bounds }
        let scale = min(bounds.width / sz.width, bounds.height / sz.height)
        let w = sz.width * scale
        let h = sz.height * scale
        return CGRect(
            x: bounds.midX - w * 0.5,
            y: bounds.midY - h * 0.5,
            width: w,
            height: h
        )
    }
}
