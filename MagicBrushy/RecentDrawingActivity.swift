import UIKit

/// Thumbnails and labels for the home mode picker — last free drawing and last template coloring, kept separate.
enum RecentDrawingActivity {

    struct HomeRecentsSummary: Equatable {
        let lastColoringPageTitle: String?
        let lastColoringPackTitle: String?
        let lastFreeDrawTitle: String?

        var hasLastColoring: Bool { lastColoringPageTitle != nil }
        var hasLastFreeDraw: Bool { lastFreeDrawTitle != nil }
        var bothEmpty: Bool { !hasLastColoring && !hasLastFreeDraw }
    }

    static func homeRecents() -> HomeRecentsSummary {
        HomeRecentsSummary(
            lastColoringPageTitle: lastColoringPageTitle(),
            lastColoringPackTitle: lastColoringPackTitle(),
            lastFreeDrawTitle: lastFreeDrawTitle()
        )
    }

    /// Most recent saved free-drawing gallery thumbnail, if any.
    static func latestFreeDrawingThumbnail() -> UIImage? {
        guard let rec = LastDrawingStore.allSavedGalleryRecordsNewestFirst().first else { return nil }
        return LastDrawingStore.loadThumbnail(id: rec.id)
            ?? LastDrawingStore.loadComposite(id: rec.id)
    }

    /// Most recent in-progress template coloring (strokes over line art), if any.
    static func latestColoringThumbnail(maxPixelSide: CGFloat = 480) -> UIImage? {
        guard let ref = TemplateProgressStore.newestProgress(),
              let pack = BuiltInColoringPages.library.first(where: { $0.id == ref.packId }),
              pack.pages.indices.contains(ref.pageIndex)
        else { return nil }
        let page = pack.pages[ref.pageIndex]
        guard let underlay = TemplateProgressStore.load(packId: ref.packId, pageIndex: ref.pageIndex) else {
            return page.image
        }
        return TemplateProgressStore.shelfPreviewImage(
            templatePageImage: page.image,
            savedUnderlay: underlay,
            maxPixelSide: maxPixelSide
        )
    }

    private static func lastColoringPageTitle() -> String? {
        guard let ref = TemplateProgressStore.newestProgress(),
              let pack = BuiltInColoringPages.library.first(where: { $0.id == ref.packId }),
              pack.pages.indices.contains(ref.pageIndex)
        else { return nil }
        return pack.pages[ref.pageIndex].title
    }

    private static func lastColoringPackTitle() -> String? {
        guard let ref = TemplateProgressStore.newestProgress(),
              let pack = BuiltInColoringPages.library.first(where: { $0.id == ref.packId })
        else { return nil }
        return pack.title
    }

    private static func lastFreeDrawTitle() -> String? {
        guard let rec = LastDrawingStore.allSavedGalleryRecordsNewestFirst().first else { return nil }
        return rec.pageTitle
    }
}
