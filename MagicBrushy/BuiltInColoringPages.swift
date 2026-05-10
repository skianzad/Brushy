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

    /// All shelves, in the order they appear in the horizontal category bar (matches home tiles + extras).
    static let library: [CategoryPack] = {
        [
            CategoryPack(id: "ocean", title: "Ocean", symbolName: "water.waves", pages: [
                pageFromAsset("Ocean_01", fallbackTitle: "Ocean 1"),
                pageFromAsset("Ocean_02", fallbackTitle: "Ocean 2"),
                pageFromAsset("Ocean_03", fallbackTitle: "Ocean 3"),
                pageFromAsset("Ocean_04", fallbackTitle: "Ocean 4"),
                pageFromAsset("Ocean_05", fallbackTitle: "Ocean 5"),
                pageFromAsset("Ocean_06", fallbackTitle: "Ocean 6"),
                pageFromAsset("Ocean_07", fallbackTitle: "Ocean 7"),
                pageFromAsset("Ocean_08", fallbackTitle: "Ocean 8"),
                pageFromAsset("Ocean_09", fallbackTitle: "Ocean 9"),
                pageFromAsset("Ocean_10", fallbackTitle: "Ocean 10"),
            ]),
            CategoryPack(id: "animals", title: "Animals", symbolName: "pawprint.fill", pages: [
                pageFromAsset("Animals_01", fallbackTitle: "Animals 1"),
                pageFromAsset("Animals_02", fallbackTitle: "Animals 2"),
                pageFromAsset("Animals_03", fallbackTitle: "Animals 3"),
                pageFromAsset("Animals_04", fallbackTitle: "Animals 4"),
                pageFromAsset("Animals_05", fallbackTitle: "Animals 5"),
                pageFromAsset("Animals_06", fallbackTitle: "Animals 6"),
                pageFromAsset("Animals_07", fallbackTitle: "Animals 7"),
                pageFromAsset("Animals_08", fallbackTitle: "Animals 8"),
                pageFromAsset("Animals_09", fallbackTitle: "Animals 9"),
                pageFromAsset("Animals_10", fallbackTitle: "Animals 10"),
            ]),
            CategoryPack(id: "dinosaurs", title: "Dinosaurs", symbolName: "lizard.fill", pages: [
                pageFromAsset("Dinosaurs_01", fallbackTitle: "Dinosaurs 1"),
                pageFromAsset("Dinosaurs_02", fallbackTitle: "Dinosaurs 2"),
                pageFromAsset("Dinosaurs_03", fallbackTitle: "Dinosaurs 3"),
                pageFromAsset("Dinosaurs_04", fallbackTitle: "Dinosaurs 4"),
                pageFromAsset("Dinosaurs_05", fallbackTitle: "Dinosaurs 5"),
                pageFromAsset("Dinosaurs_06", fallbackTitle: "Dinosaurs 6"),
                pageFromAsset("Dinosaurs_07", fallbackTitle: "Dinosaurs 7"),
                pageFromAsset("Dinosaurs_08", fallbackTitle: "Dinosaurs 8"),
                pageFromAsset("Dinosaurs_09", fallbackTitle: "Dinosaurs 9"),
                pageFromAsset("Dinosaurs_10", fallbackTitle: "Dinosaurs 10"),
            ]),
            CategoryPack(id: "famous_art", title: "Famous Art", symbolName: "paintpalette.fill", pages: [
                pageFromAsset("FamousArt_01", fallbackTitle: "Famous Art 1"),
                pageFromAsset("FamousArt_02", fallbackTitle: "Famous Art 2"),
                pageFromAsset("FamousArt_03", fallbackTitle: "Famous Art 3"),
                pageFromAsset("FamousArt_04", fallbackTitle: "Famous Art 4"),
                pageFromAsset("FamousArt_05", fallbackTitle: "Famous Art 5"),
                pageFromAsset("FamousArt_06", fallbackTitle: "Famous Art 6"),
                pageFromAsset("FamousArt_07", fallbackTitle: "Famous Art 7"),
                pageFromAsset("FamousArt_08", fallbackTitle: "Famous Art 8"),
                pageFromAsset("FamousArt_09", fallbackTitle: "Famous Art 9"),
                pageFromAsset("FamousArt_10", fallbackTitle: "Famous Art 10"),
            ]),
            CategoryPack(id: "fantasy_and_magic", title: "Fantasy & Magic", symbolName: "moon.stars.fill", pages: [
                pageFromAsset("FantasyMagic_01", fallbackTitle: "Fantasy & Magic 1"),
                pageFromAsset("FantasyMagic_02", fallbackTitle: "Fantasy & Magic 2"),
                pageFromAsset("FantasyMagic_03", fallbackTitle: "Fantasy & Magic 3"),
                pageFromAsset("FantasyMagic_04", fallbackTitle: "Fantasy & Magic 4"),
                pageFromAsset("FantasyMagic_05", fallbackTitle: "Fantasy & Magic 5"),
                pageFromAsset("FantasyMagic_06", fallbackTitle: "Fantasy & Magic 6"),
                pageFromAsset("FantasyMagic_07", fallbackTitle: "Fantasy & Magic 7"),
                pageFromAsset("FantasyMagic_08", fallbackTitle: "Fantasy & Magic 8"),
                pageFromAsset("FantasyMagic_09", fallbackTitle: "Fantasy & Magic 9"),
                pageFromAsset("FantasyMagic_10", fallbackTitle: "Fantasy & Magic 10"),
                pageFromAsset("FantasyMagic_11", fallbackTitle: "Fantasy & Magic 11"),
                pageFromAsset("FantasyMagic_12", fallbackTitle: "Fantasy & Magic 12"),
            ]),
            CategoryPack(id: "food", title: "Food", symbolName: "fork.knife", pages: [
                pageFromAsset("Food_01", fallbackTitle: "Food 1"),
                pageFromAsset("Food_02", fallbackTitle: "Food 2"),
                pageFromAsset("Food_03", fallbackTitle: "Food 3"),
                pageFromAsset("Food_04", fallbackTitle: "Food 4"),
                pageFromAsset("Food_05", fallbackTitle: "Food 5"),
                pageFromAsset("Food_06", fallbackTitle: "Food 6"),
                pageFromAsset("Food_07", fallbackTitle: "Food 7"),
                pageFromAsset("Food_08", fallbackTitle: "Food 8"),
                pageFromAsset("Food_09", fallbackTitle: "Food 9"),
                pageFromAsset("Food_10", fallbackTitle: "Food 10"),
            ]),
            CategoryPack(id: "nature_plants", title: "Nature & Plants", symbolName: "leaf.circle.fill", pages: [
                pageFromAsset("NaturePlants_01", fallbackTitle: "Nature & Plants 1"),
                pageFromAsset("NaturePlants_02", fallbackTitle: "Nature & Plants 2"),
                pageFromAsset("NaturePlants_03", fallbackTitle: "Nature & Plants 3"),
                pageFromAsset("NaturePlants_04", fallbackTitle: "Nature & Plants 4"),
                pageFromAsset("NaturePlants_05", fallbackTitle: "Nature & Plants 5"),
                pageFromAsset("NaturePlants_06", fallbackTitle: "Nature & Plants 6"),
                pageFromAsset("NaturePlants_07", fallbackTitle: "Nature & Plants 7"),
                pageFromAsset("NaturePlants_08", fallbackTitle: "Nature & Plants 8"),
                pageFromAsset("NaturePlants_09", fallbackTitle: "Nature & Plants 9"),
                pageFromAsset("NaturePlants_10", fallbackTitle: "Nature & Plants 10"),
            ]),
            CategoryPack(id: "sports", title: "Sports", symbolName: "sportscourt.fill", pages: [
                pageFromAsset("Sports_01", fallbackTitle: "Sports 1"),
                pageFromAsset("Sports_02", fallbackTitle: "Sports 2"),
                pageFromAsset("Sports_03", fallbackTitle: "Sports 3"),
                pageFromAsset("Sports_04", fallbackTitle: "Sports 4"),
                pageFromAsset("Sports_05", fallbackTitle: "Sports 5"),
                pageFromAsset("Sports_06", fallbackTitle: "Sports 6"),
                pageFromAsset("Sports_07", fallbackTitle: "Sports 7"),
                pageFromAsset("Sports_08", fallbackTitle: "Sports 8"),
                pageFromAsset("Sports_09", fallbackTitle: "Sports 9"),
                pageFromAsset("Sports_10", fallbackTitle: "Sports 10"),
            ]),
            CategoryPack(id: "vehicles", title: "Vehicles", symbolName: "car.fill", pages: [
                pageFromAsset("Vehicles_01", fallbackTitle: "Camper Van"),
                pageFromAsset("Vehicles_02", fallbackTitle: "Steam Train"),
                pageFromAsset("Vehicles_03", fallbackTitle: "Cargo Ship"),
                pageFromAsset("Vehicles_04", fallbackTitle: "Biplane"),
                pageFromAsset("Vehicles_05", fallbackTitle: "Sports Car"),
                pageFromAsset("Vehicles_06", fallbackTitle: "Passenger Jet"),
                pageFromAsset("Vehicles_07", fallbackTitle: "School Bus"),
                pageFromAsset("Vehicles_08", fallbackTitle: "Fire Truck"),
                pageFromAsset("Vehicles_09", fallbackTitle: "Helicopter"),
                pageFromAsset("Vehicles_10", fallbackTitle: "Tractor"),
            ]),
            CategoryPack(id: "winter_sports", title: "Winter Sports", symbolName: "snowflake", pages: [
                pageFromAsset("WinterSports_01", fallbackTitle: "Winter Sports 1"),
                pageFromAsset("WinterSports_02", fallbackTitle: "Winter Sports 2"),
                pageFromAsset("WinterSports_03", fallbackTitle: "Winter Sports 3"),
                pageFromAsset("WinterSports_04", fallbackTitle: "Winter Sports 4"),
                pageFromAsset("WinterSports_05", fallbackTitle: "Winter Sports 5"),
                pageFromAsset("WinterSports_06", fallbackTitle: "Winter Sports 6"),
                pageFromAsset("WinterSports_07", fallbackTitle: "Winter Sports 7"),
                pageFromAsset("WinterSports_08", fallbackTitle: "Winter Sports 8"),
                pageFromAsset("WinterSports_09", fallbackTitle: "Winter Sports 9"),
                pageFromAsset("WinterSports_10", fallbackTitle: "Winter Sports 10"),
            ]),
        ]
    }()

    private static func pageFromAsset(_ assetName: String, fallbackTitle: String) -> Page {
        Page(title: fallbackTitle, image: UIImage(named: assetName) ?? renderHouse())
    }

    /// Flattened pages (Animals pack) for legacy call sites that expect a single list.
    static var all: [Page] { library.first(where: { $0.id == "animals" })?.pages ?? library.first?.pages ?? [] }

    /// First thumbnail for a home / browse tile.
    static func previewImage(packId: String) -> UIImage? {
        library.first(where: { $0.id == packId })?.pages.first?.image
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
