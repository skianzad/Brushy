import UIKit

/// Persists every coloring snapshot when the user returns home (bounded list); each has its own image files on disk.
enum LastDrawingStore {

    struct SavedDrawingRecord: Codable, Equatable {
        let id: UUID
        var packId: String
        var pageIndex: Int
        var pageTitle: String
        var updatedAt: Date
        let compositeFileName: String
        let thumbFileName: String
        /// Line-free “template + paint” JPEG for resume so line art can stay in `templateLineOverlayView` above strokes.
        let resumeUnderlayFileName: String?
    }

    private static let indexKey = "MagicBrushySavedDrawingsIndexV2"
    private static let legacyMetaKey = "MagicBrushyLastDrawingMetaV1"
    private static let legacyCompositeName = "last_drawing_composite.jpg"
    private static let legacyThumbName = "last_drawing_thumb.jpg"

    /// Cap so disk use stays bounded; oldest entries (and their files) are removed first.
    private static let maxSavedDrawings = 48

    private static var directoryURL: URL {
        let base = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask).first!
        let dir = base.appendingPathComponent("MagicBrushy", isDirectory: true)
        try? FileManager.default.createDirectory(at: dir, withIntermediateDirectories: true)
        return dir
    }

    private static func fileURL(_ name: String) -> URL {
        directoryURL.appendingPathComponent(name)
    }

    // MARK: - Public API

    static var hasAnySavedDrawing: Bool {
        migrateLegacyV1IfNeeded()
        return !loadIndex().isEmpty
    }

    /// Newest first.
    static func allRecordsNewestFirst() -> [SavedDrawingRecord] {
        migrateLegacyV1IfNeeded()
        return loadIndex().sorted { $0.updatedAt > $1.updatedAt }
    }

    static func record(id: UUID) -> SavedDrawingRecord? {
        loadIndex().first { $0.id == id }
    }

    static func loadThumbnail(id: UUID) -> UIImage? {
        guard let name = record(id: id)?.thumbFileName else { return nil }
        return UIImage(contentsOfFile: fileURL(name).path)
    }

    static func loadComposite(id: UUID) -> UIImage? {
        guard let name = record(id: id)?.compositeFileName else { return nil }
        return UIImage(contentsOfFile: fileURL(name).path)
    }

    static func loadResumeUnderlay(id: UUID) -> UIImage? {
        guard let name = record(id: id)?.resumeUnderlayFileName else { return nil }
        return UIImage(contentsOfFile: fileURL(name).path)
    }

    /// Appends a new saved drawing (does not replace previous saves).
    @discardableResult
    static func save(
        packId: String,
        pageIndex: Int,
        pageTitle: String,
        composite: UIImage,
        resumeUnderlay: UIImage?,
        thumbnailMaxEdge: CGFloat = 400
    ) -> UUID {
        migrateLegacyV1IfNeeded()
        return appendRecord(
            packId: packId,
            pageIndex: pageIndex,
            pageTitle: pageTitle,
            composite: composite,
            resumeUnderlay: resumeUnderlay,
            thumbnailMaxEdge: thumbnailMaxEdge
        )
    }

    /// Overwrites files for an existing record and moves it to the front of the index (newest). Returns false if `id` is missing.
    @discardableResult
    static func updateRecord(
        id: UUID,
        packId: String,
        pageIndex: Int,
        pageTitle: String,
        composite: UIImage,
        resumeUnderlay: UIImage?,
        thumbnailMaxEdge: CGFloat = 400
    ) -> Bool {
        migrateLegacyV1IfNeeded()
        var entries = loadIndex()
        guard let idx = entries.firstIndex(where: { $0.id == id }) else { return false }
        let old = entries.remove(at: idx)

        let cURL = fileURL(old.compositeFileName)
        let tURL = fileURL(old.thumbFileName)
        if let j = composite.jpegData(compressionQuality: 0.88) {
            try? j.write(to: cURL, options: .atomic)
        }
        let thumb = Self.downscale(composite, maxEdge: thumbnailMaxEdge)
        if let j = thumb.jpegData(compressionQuality: 0.82) {
            try? j.write(to: tURL, options: .atomic)
        }

        var underlayName = old.resumeUnderlayFileName
        if let underlay = resumeUnderlay, let j = underlay.jpegData(compressionQuality: 0.88) {
            if underlayName == nil {
                underlayName = "u_\(old.id.uuidString).jpg"
            }
            if let name = underlayName {
                try? j.write(to: fileURL(name), options: .atomic)
            }
        } else {
            if let name = underlayName {
                try? FileManager.default.removeItem(at: fileURL(name))
            }
            underlayName = nil
        }

        let rec = SavedDrawingRecord(
            id: old.id,
            packId: packId,
            pageIndex: pageIndex,
            pageTitle: pageTitle,
            updatedAt: Date(),
            compositeFileName: old.compositeFileName,
            thumbFileName: old.thumbFileName,
            resumeUnderlayFileName: underlayName
        )
        entries.insert(rec, at: 0)
        saveIndex(entries)
        return true
    }

    private static func appendRecord(
        packId: String,
        pageIndex: Int,
        pageTitle: String,
        composite: UIImage,
        resumeUnderlay: UIImage?,
        thumbnailMaxEdge: CGFloat = 400
    ) -> UUID {
        let id = UUID()
        let stem = id.uuidString
        let cName = "c_\(stem).jpg"
        let tName = "t_\(stem).jpg"
        let cURL = fileURL(cName)
        let tURL = fileURL(tName)

        var underlayName: String? = nil
        if let underlay = resumeUnderlay, let j = underlay.jpegData(compressionQuality: 0.88) {
            let u = "u_\(stem).jpg"
            let uURL = fileURL(u)
            do {
                try j.write(to: uURL, options: .atomic)
                underlayName = u
            } catch {}
        }

        let thumb = Self.downscale(composite, maxEdge: thumbnailMaxEdge)
        if let j = thumb.jpegData(compressionQuality: 0.82) {
            try? j.write(to: tURL, options: .atomic)
        }
        if let j = composite.jpegData(compressionQuality: 0.88) {
            try? j.write(to: cURL, options: .atomic)
        }

        var entries = loadIndex()
        let rec = SavedDrawingRecord(
            id: id,
            packId: packId,
            pageIndex: pageIndex,
            pageTitle: pageTitle,
            updatedAt: Date(),
            compositeFileName: cName,
            thumbFileName: tName,
            resumeUnderlayFileName: underlayName
        )
        entries.insert(rec, at: 0)
        trimEntries(&entries)
        saveIndex(entries)
        return id
    }

    static func deleteRecord(id: UUID) {
        migrateLegacyV1IfNeeded()
        var entries = loadIndex()
        guard let idx = entries.firstIndex(where: { $0.id == id }) else { return }
        let removed = entries.remove(at: idx)
        deleteFiles(for: removed)
        saveIndex(entries)
    }

    /// Removes every index entry and associated composite/thumbnail files (legacy names included).
    static func clearAll() {
        migrateLegacyV1IfNeeded()
        let entries = loadIndex()
        for e in entries { deleteFiles(for: e) }
        UserDefaults.standard.removeObject(forKey: indexKey)
        let legacyC = fileURL(legacyCompositeName)
        let legacyT = fileURL(legacyThumbName)
        try? FileManager.default.removeItem(at: legacyC)
        try? FileManager.default.removeItem(at: legacyT)
        UserDefaults.standard.removeObject(forKey: legacyMetaKey)
    }

    // MARK: - Legacy (single “last drawing”)

    private struct LegacyMetadata: Codable {
        var packId: String
        var pageIndex: Int
        var pageTitle: String
        var updatedAt: Date
    }

    private static var didRunLegacyMigration = false

    private static func migrateLegacyV1IfNeeded() {
        if didRunLegacyMigration { return }
        didRunLegacyMigration = true

        guard let data = UserDefaults.standard.data(forKey: legacyMetaKey),
              let old = try? JSONDecoder().decode(LegacyMetadata.self, from: data)
        else { return }

        let legacyC = fileURL(legacyCompositeName)
        let legacyT = fileURL(legacyThumbName)
        guard let composite = UIImage(contentsOfFile: legacyC.path) else {
            UserDefaults.standard.removeObject(forKey: legacyMetaKey)
            try? FileManager.default.removeItem(at: legacyT)
            return
        }

        _ = appendRecord(packId: old.packId, pageIndex: old.pageIndex, pageTitle: old.pageTitle, composite: composite, resumeUnderlay: nil)

        UserDefaults.standard.removeObject(forKey: legacyMetaKey)
        try? FileManager.default.removeItem(at: legacyC)
        try? FileManager.default.removeItem(at: legacyT)
    }

    // MARK: - Index + files

    private static func loadIndex() -> [SavedDrawingRecord] {
        guard let data = UserDefaults.standard.data(forKey: indexKey) else { return [] }
        return (try? JSONDecoder().decode([SavedDrawingRecord].self, from: data)) ?? []
    }

    private static func saveIndex(_ entries: [SavedDrawingRecord]) {
        if let data = try? JSONEncoder().encode(entries) {
            UserDefaults.standard.set(data, forKey: indexKey)
        }
    }

    private static func trimEntries(_ entries: inout [SavedDrawingRecord]) {
        while entries.count > maxSavedDrawings {
            let dropped = entries.removeLast()
            deleteFiles(for: dropped)
        }
    }

    private static func deleteFiles(for record: SavedDrawingRecord) {
        try? FileManager.default.removeItem(at: fileURL(record.compositeFileName))
        try? FileManager.default.removeItem(at: fileURL(record.thumbFileName))
        if let u = record.resumeUnderlayFileName {
            try? FileManager.default.removeItem(at: fileURL(u))
        }
    }

    private static func downscale(_ image: UIImage, maxEdge: CGFloat) -> UIImage {
        let s = max(image.size.width, image.size.height)
        guard s > maxEdge, s > 1 else { return image }
        let scale = maxEdge / s
        let out = CGSize(width: max(1, (image.size.width * scale).rounded()), height: max(1, (image.size.height * scale).rounded()))
        let format = UIGraphicsImageRendererFormat.default()
        format.scale = 1
        format.opaque = true
        return UIGraphicsImageRenderer(size: out, format: format).image { _ in
            UIColor.white.setFill()
            UIBezierPath(rect: CGRect(origin: .zero, size: out)).fill()
            image.draw(in: CGRect(origin: .zero, size: out))
        }
    }
}
