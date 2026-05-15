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
        guard let data = underlay.jpegData(compressionQuality: 0.82) else { return }
        let url = fileURL(packId: packId, pageIndex: pageIndex)
        try? data.write(to: url, options: .atomic)
    }

    static func load(packId: String, pageIndex: Int) -> UIImage? {
        let url = fileURL(packId: packId, pageIndex: pageIndex)
        return UIImage(contentsOfFile: url.path)
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

    /// Preview for category thumbnails: saved underlay (template + strokes, no outlines) plus line art on top, matching on-canvas stacking.
    static func shelfPreviewImage(templatePageImage: UIImage, savedUnderlay: UIImage) -> UIImage {
        let lineArt = templatePageImage.magicBrushyLineArtOverlay()
        let maxPixelSide: CGFloat = 280
        let longest = max(savedUnderlay.size.width, savedUnderlay.size.height)
        let scaleDown = min(1, maxPixelSide / max(longest, 1))
        let outW = max(1, floor(savedUnderlay.size.width * scaleDown))
        let outH = max(1, floor(savedUnderlay.size.height * scaleDown))
        let outSize = CGSize(width: outW, height: outH)
        let bounds = CGRect(origin: .zero, size: outSize)

        let format = UIGraphicsImageRendererFormat()
        format.scale = 1
        format.opaque = true

        return UIGraphicsImageRenderer(size: outSize, format: format).image { _ in
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
