import UIKit

/// Vector line-art packs shown in the category browser and on the canvas.
enum BuiltInColoringPages {

    struct Page {
        let title: String
        let image: UIImage
    }

    /// One browsable shelf (horizontal category bar → thumbnails).
    struct CategoryPack {
        let id: String
        let title: String
        /// SF Symbol name for the category chip.
        let symbolName: String
        let pages: [Page]
    }

    /// Home / grid “Your drawings” and `LastDrawingStore` writes are limited to this pack so other shelves keep full-color templates under the user’s strokes.
    static let savedDrawingsPackId = "free_drawing"

    /// All shelves, in the order they appear in the horizontal category bar (matches home tiles + extras).
    static let library: [CategoryPack] = {
        [
            CategoryPack(id: BuiltInColoringPages.savedDrawingsPackId, title: "Free Draw", symbolName: "pencil.and.outline", pages: [
                Page(title: "New drawing", image: renderBlankFreeDrawingPaper()),
            ]),
            CategoryPack(id: "animals", title: "Animals", symbolName: "pawprint.fill", pages: pagesFromAsset("Animals", count: 12)),
            CategoryPack(id: "dinosaurs", title: "Dinosaurs", symbolName: "lizard.fill", pages: pagesFromAsset("Dinosaurs", count: 12)),
            CategoryPack(id: "fall", title: "Fall", symbolName: "leaf.fill", pages: pagesFromAsset("Fall", count: 12)),
            CategoryPack(id: "food", title: "Food", symbolName: "fork.knife", pages: pagesFromAsset("Food", count: 12)),
            CategoryPack(id: "magic", title: "Magic", symbolName: "moon.stars.fill", pages: pagesFromAsset("Magic", count: 12, pageTitlePrefix: "Magic")),
            CategoryPack(id: "music", title: "Music", symbolName: "music.note", pages: pagesFromAsset("Music", count: 12)),
            CategoryPack(id: "nature", title: "Nature", symbolName: "leaf.circle.fill", pages: pagesFromAsset("Nature", count: 16)),
            CategoryPack(id: "ocean", title: "Ocean", symbolName: "water.waves", pages: pagesFromAsset("Ocean", count: 16)),
            CategoryPack(id: "school", title: "School", symbolName: "backpack.fill", pages: pagesFromAsset("School", count: 12)),
            CategoryPack(id: "sports", title: "Sports", symbolName: "sportscourt.fill", pages: pagesFromAsset("Sports", count: 16)),
            CategoryPack(id: "transportation", title: "Transportation", symbolName: "car.fill", pages: pagesFromAsset("Transportation", count: 12)),
            CategoryPack(id: "winter", title: "Winter", symbolName: "snowflake", pages: pagesFromAsset("Winter", count: 12)),
        ]
    }()

    /// Retired pack ids from older app versions → current `library` ids.
    private static let retiredPackIdAliases: [String: String] = [
        "fantasy_and_magic": "magic",
        "nature_plants": "nature",
        "vehicles": "transportation",
        "winter_sports": "winter",
    ]

    static func resolvePackId(_ id: String) -> String {
        retiredPackIdAliases[id] ?? id
    }

    static func pack(withId id: String) -> CategoryPack? {
        let resolved = resolvePackId(id)
        return library.first { $0.id == resolved }
    }

    static func legacyPackIds(forResolvedId resolvedId: String) -> [String] {
        retiredPackIdAliases.compactMap { legacy, current in current == resolvedId ? legacy : nil }
    }

    private static func pageFromAsset(_ assetName: String, fallbackTitle: String) -> Page {
        guard let raw = UIImage(named: assetName) else {
            return Page(title: fallbackTitle, image: renderHouse())
        }
        return Page(title: fallbackTitle, image: raw.magicBrushyNormalizedAssetScale())
    }

    private static func pagesFromAsset(_ prefix: String, count: Int, pageTitlePrefix: String? = nil) -> [Page] {
        let label = pageTitlePrefix ?? prefix
        return (1...count).map { i in
            let assetName = String(format: "%@_%02d", prefix, i)
            return pageFromAsset(assetName, fallbackTitle: "\(label) \(i)")
        }
    }

    /// Flattened pages for legacy call sites that expect a single list.
    static var all: [Page] { library.first(where: { $0.id == "ocean" })?.pages ?? library.first?.pages ?? [] }

    /// First thumbnail for a home / browse tile.
    static func previewImage(packId: String) -> UIImage? {
        pack(withId: packId)?.pages.first?.image.magicBrushyCompositedOnPaper()
    }

    // MARK: - Rendering

    private static func render(size: CGSize = CGSize(width: 800, height: 1000), lineWidth: CGFloat = 5, draw: (CGContext) -> Void) -> UIImage {
        let format = UIGraphicsImageRendererFormat.default()
        format.opaque = true
        format.scale = 1
        let r = UIGraphicsImageRenderer(size: size, format: format)
        return r.image { ctx in
            let c = ctx.cgContext
            c.setFillColor(UIColor.white.cgColor)
            c.fill(CGRect(origin: .zero, size: size))
            c.setStrokeColor(UIColor.black.cgColor)
            c.setLineWidth(lineWidth)
            c.setLineJoin(.round)
            c.setLineCap(.round)
            draw(c)
        }
    }

    private static func strokeRect(_ c: CGContext, _ r: CGRect) {
        c.addRect(r)
        c.strokePath()
    }

    private static func strokeOval(_ c: CGContext, _ r: CGRect) {
        c.addEllipse(in: r)
        c.strokePath()
    }

    /// Plain white sheet for Free Draw (no grid, guides, or placeholder art).
    private static func renderBlankFreeDrawingPaper() -> UIImage {
        let size = CGSize(width: 800, height: 1000)
        let format = UIGraphicsImageRendererFormat.default()
        format.opaque = true
        format.scale = 1
        return UIGraphicsImageRenderer(size: size, format: format).image { ctx in
            UIColor.white.setFill()
            ctx.fill(CGRect(origin: .zero, size: size))
        }
    }

    private static func renderHouse() -> UIImage {
        render { c in
            let w: CGFloat = 800, h: CGFloat = 1000
            c.move(to: CGPoint(x: 120, y: 440))
            c.addLine(to: CGPoint(x: 400, y: 200))
            c.addLine(to: CGPoint(x: 680, y: 440))
            c.closePath()
            c.strokePath()
            strokeRect(c, CGRect(x: 120, y: 440, width: 560, height: 420))
            strokeRect(c, CGRect(x: 340, y: 600, width: 120, height: 260))
            strokeRect(c, CGRect(x: 180, y: 500, width: 130, height: 130))
            strokeRect(c, CGRect(x: 490, y: 500, width: 130, height: 130))
            let sun = CGPoint(x: w - 140, y: 160)
            strokeOval(c, CGRect(x: sun.x - 70, y: sun.y - 70, width: 140, height: 140))
            c.move(to: CGPoint(x: 40, y: h - 80))
            c.addLine(to: CGPoint(x: w - 40, y: h - 80))
            c.strokePath()
        }
    }

    private static func renderKitten() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 280, y: 320, width: 240, height: 200))
            strokeOval(c, CGRect(x: 320, y: 380, width: 36, height: 44))
            strokeOval(c, CGRect(x: 444, y: 380, width: 36, height: 44))
            c.move(to: CGPoint(x: 360, y: 470))
            c.addQuadCurve(to: CGPoint(x: 440, y: 470), control: CGPoint(x: 400, y: 510))
            c.strokePath()
            c.move(to: CGPoint(x: 280, y: 400))
            c.addLine(to: CGPoint(x: 220, y: 300))
            c.addLine(to: CGPoint(x: 260, y: 340))
            c.strokePath()
            c.move(to: CGPoint(x: 520, y: 400))
            c.addLine(to: CGPoint(x: 580, y: 300))
            c.addLine(to: CGPoint(x: 540, y: 340))
            c.strokePath()
            c.move(to: CGPoint(x: 400, y: 520))
            c.addQuadCurve(to: CGPoint(x: 400, y: 720), control: CGPoint(x: 320, y: 620))
            c.addQuadCurve(to: CGPoint(x: 400, y: 820), control: CGPoint(x: 480, y: 700))
            c.strokePath()
        }
    }

    private static func renderButterfly() -> UIImage {
        render(lineWidth: 4) { c in
            let cx: CGFloat = 400, cy: CGFloat = 480
            strokeOval(c, CGRect(x: cx - 40, y: cy - 120, width: 80, height: 240))
            strokeOval(c, CGRect(x: cx - 220, y: cy - 140, width: 180, height: 220))
            strokeOval(c, CGRect(x: cx + 40, y: cy - 140, width: 180, height: 220))
            strokeOval(c, CGRect(x: cx - 200, y: cy + 20, width: 140, height: 160))
            strokeOval(c, CGRect(x: cx + 60, y: cy + 20, width: 140, height: 160))
            for (dx, dy) in [(-30, -40), (30, -40), (-30, 40), (30, 40)] as [(CGFloat, CGFloat)] {
                strokeOval(c, CGRect(x: cx + dx - 10, y: cy + dy - 10, width: 20, height: 20))
            }
        }
    }

    private static func renderBird() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 300, y: 380, width: 200, height: 160))
            c.move(to: CGPoint(x: 500, y: 460))
            c.addLine(to: CGPoint(x: 620, y: 440))
            c.addLine(to: CGPoint(x: 500, y: 500))
            c.strokePath()
            c.move(to: CGPoint(x: 340, y: 520))
            c.addQuadCurve(to: CGPoint(x: 420, y: 720), control: CGPoint(x: 300, y: 640))
            c.strokePath()
            c.move(to: CGPoint(x: 460, y: 520))
            c.addQuadCurve(to: CGPoint(x: 380, y: 720), control: CGPoint(x: 500, y: 640))
            c.strokePath()
            strokeOval(c, CGRect(x: 360, y: 420, width: 24, height: 28))
            strokeOval(c, CGRect(x: 430, y: 420, width: 24, height: 28))
        }
    }

    private static func renderFish() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 200, y: 480))
            c.addQuadCurve(to: CGPoint(x: 520, y: 480), control: CGPoint(x: 400, y: 360))
            c.addQuadCurve(to: CGPoint(x: 200, y: 480), control: CGPoint(x: 400, y: 600))
            c.closePath()
            c.strokePath()
            c.move(to: CGPoint(x: 520, y: 480))
            c.addLine(to: CGPoint(x: 640, y: 400))
            c.addLine(to: CGPoint(x: 640, y: 560))
            c.closePath()
            c.strokePath()
            strokeOval(c, CGRect(x: 320, y: 440, width: 40, height: 40))
        }
    }

    private static func renderWaves() -> UIImage {
        render(lineWidth: 4) { c in
            for y in stride(from: CGFloat(500), through: CGFloat(720), by: 72) {
                c.move(to: CGPoint(x: 60, y: y))
                var x: CGFloat = 60
                while x < 740 {
                    c.addQuadCurve(to: CGPoint(x: x + 80, y: y), control: CGPoint(x: x + 40, y: y - 22))
                    x += 80
                }
                c.strokePath()
            }
        }
    }

    private static func renderShell() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 400, y: 780))
            c.addQuadCurve(to: CGPoint(x: 280, y: 520), control: CGPoint(x: 260, y: 680))
            c.addQuadCurve(to: CGPoint(x: 400, y: 420), control: CGPoint(x: 320, y: 460))
            c.addQuadCurve(to: CGPoint(x: 520, y: 520), control: CGPoint(x: 540, y: 680))
            c.addQuadCurve(to: CGPoint(x: 400, y: 780), control: CGPoint(x: 480, y: 720))
            c.strokePath()
            for i in 1..<6 {
                let t = CGFloat(i) / 6
                c.move(to: CGPoint(x: 400, y: 780))
                c.addLine(to: CGPoint(x: 400 + (t - 0.5) * 200, y: 520 + t * 180))
                c.strokePath()
            }
        }
    }

    private static func renderDolphin() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 200, y: 520))
            c.addQuadCurve(to: CGPoint(x: 560, y: 440), control: CGPoint(x: 420, y: 360))
            c.addQuadCurve(to: CGPoint(x: 620, y: 500), control: CGPoint(x: 600, y: 460))
            c.addQuadCurve(to: CGPoint(x: 520, y: 540), control: CGPoint(x: 580, y: 520))
            c.addQuadCurve(to: CGPoint(x: 200, y: 520), control: CGPoint(x: 320, y: 600))
            c.closePath()
            c.strokePath()
            c.move(to: CGPoint(x: 560, y: 440))
            c.addLine(to: CGPoint(x: 640, y: 400))
            c.strokePath()
        }
    }
}
