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
                Page(title: "Fish", image: renderFish()),
                Page(title: "Turtle", image: renderTurtle()),
                Page(title: "Waves", image: renderWaves()),
                Page(title: "Shell", image: renderShell()),
                Page(title: "Dolphin", image: renderDolphin()),
            ]),
            CategoryPack(id: "magic", title: "Magic", symbolName: "wand.and.stars", pages: [
                Page(title: "Castle", image: renderCastle()),
                Page(title: "Magic Wand", image: renderMagicWand()),
                Page(title: "Rainbow", image: renderRainbow()),
                Page(title: "Unicorn", image: renderUnicorn()),
                Page(title: "Dragon", image: renderDragon()),
            ]),
            CategoryPack(id: "animals", title: "Animals", symbolName: "pawprint.fill", pages: [
                Page(title: "House", image: renderHouse()),
                Page(title: "Kitten", image: renderKitten()),
                Page(title: "Butterfly", image: renderButterfly()),
                Page(title: "Bird", image: renderBird()),
                Page(title: "Fish", image: renderFish()),
            ]),
            CategoryPack(id: "dinosaurs", title: "Dinosaurs", symbolName: "lizard.fill", pages: [
                Page(title: "T-Rex", image: renderTRex()),
                Page(title: "Long Neck", image: renderLongNeck()),
                Page(title: "Dino Egg", image: renderDinoEgg()),
                Page(title: "Volcano", image: renderVolcano()),
                Page(title: "Footprints", image: renderFootprints()),
            ]),
            CategoryPack(id: "famous_art", title: "Famous Art", symbolName: "paintpalette.fill", pages: [
                Page(title: "Frame", image: renderPictureFrame()),
                Page(title: "Sunflowers", image: renderSunflowers()),
                Page(title: "Smile Portrait", image: renderSmilePortrait()),
                Page(title: "Swirls", image: renderSwirlArt()),
                Page(title: "Still Life", image: renderStillLife()),
            ]),
            CategoryPack(id: "fantasy", title: "Fantasy", symbolName: "sparkles", pages: [
                Page(title: "Castle", image: renderCastle()),
                Page(title: "Magic Wand", image: renderMagicWand()),
                Page(title: "Dragon", image: renderDragon()),
                Page(title: "Rainbow", image: renderRainbow()),
                Page(title: "Unicorn", image: renderUnicorn()),
            ]),
            CategoryPack(id: "food", title: "Food", symbolName: "fork.knife", pages: [
                Page(title: "Cupcake", image: renderCupcake()),
                Page(title: "Pizza", image: renderPizza()),
                Page(title: "Apple", image: renderApple()),
                Page(title: "Ice Cream", image: renderIceCream()),
                Page(title: "Donut", image: renderDonut()),
            ]),
            CategoryPack(id: "fun_stuff", title: "Fun Stuff", symbolName: "gamecontroller.fill", pages: [
                Page(title: "Rocket", image: renderRocket()),
                Page(title: "Controller", image: renderGameController()),
                Page(title: "Ball", image: renderBall()),
                Page(title: "Kite", image: renderKite()),
                Page(title: "Blocks", image: renderBlocks()),
            ]),
            CategoryPack(id: "nature", title: "Nature", symbolName: "leaf.fill", pages: [
                Page(title: "Garden", image: renderGarden()),
                Page(title: "Tree", image: renderTree()),
                Page(title: "Mountain", image: renderMountain()),
                Page(title: "Cloudy Sky", image: renderCloudySky()),
                Page(title: "Turtle", image: renderTurtle()),
            ]),
            CategoryPack(id: "nature_plants", title: "Nature & Plants", symbolName: "leaf.circle.fill", pages: [
                pageFromAsset("NaturePlants_01", fallbackTitle: "Nature & Plants"),
            ]),
            CategoryPack(id: "rooms_scenes", title: "Rooms & Scenes", symbolName: "house.lodge.fill", pages: [
                pageFromAsset("RoomsScenes_01", fallbackTitle: "Rooms & Scenes 1"),
                pageFromAsset("RoomsScenes_02", fallbackTitle: "Rooms & Scenes 2"),
            ]),
            CategoryPack(id: "sports", title: "Sports", symbolName: "sportscourt.fill", pages: [
                pageFromAsset("Sports_01", fallbackTitle: "Sports 1"),
                pageFromAsset("Sports_02", fallbackTitle: "Sports 2"),
            ]),
            CategoryPack(id: "transportation", title: "Transportation", symbolName: "car.fill", pages: [
                pageFromAsset("Transportation_01", fallbackTitle: "Transportation 1"),
                pageFromAsset("Transportation_02", fallbackTitle: "Transportation 2"),
                pageFromAsset("Transportation_03", fallbackTitle: "Transportation 3"),
                pageFromAsset("Transportation_04", fallbackTitle: "Transportation 4"),
                pageFromAsset("Transportation_05", fallbackTitle: "Transportation 5"),
                pageFromAsset("Transportation_06", fallbackTitle: "Transportation 6"),
            ]),
            CategoryPack(id: "winter_sports", title: "Winter Sports", symbolName: "snowflake", pages: [
                pageFromAsset("WinterSports_01", fallbackTitle: "Winter Sports 1"),
                pageFromAsset("WinterSports_02", fallbackTitle: "Winter Sports 2"),
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

    private static func renderRocket() -> UIImage {
        render { c in
            let cx: CGFloat = 400
            let topY: CGFloat = 180
            c.move(to: CGPoint(x: cx, y: topY))
            c.addQuadCurve(to: CGPoint(x: cx + 120, y: 620), control: CGPoint(x: cx + 200, y: 380))
            c.addLine(to: CGPoint(x: cx + 140, y: 720))
            c.addQuadCurve(to: CGPoint(x: cx + 70, y: 900), control: CGPoint(x: cx + 130, y: 820))
            c.addLine(to: CGPoint(x: cx - 70, y: 900))
            c.addQuadCurve(to: CGPoint(x: cx - 140, y: 720), control: CGPoint(x: cx - 130, y: 820))
            c.addLine(to: CGPoint(x: cx - 120, y: 620))
            c.addQuadCurve(to: CGPoint(x: cx, y: topY), control: CGPoint(x: cx - 200, y: 380))
            c.closePath()
            c.strokePath()
            strokeOval(c, CGRect(x: cx - 55, y: 360, width: 110, height: 110))
            c.move(to: CGPoint(x: cx - 45, y: 820))
            c.addLine(to: CGPoint(x: cx, y: 950))
            c.addLine(to: CGPoint(x: cx + 45, y: 820))
            c.strokePath()
            for p in [(100, 200), (650, 250), (700, 120), (90, 100)] as [(CGFloat, CGFloat)] {
                c.addRect(CGRect(x: p.0, y: p.1, width: 36, height: 36))
                c.strokePath()
            }
        }
    }

    private static func renderGarden() -> UIImage {
        render { c in
            c.setLineWidth(6)
            c.move(to: CGPoint(x: 200, y: 880))
            c.addQuadCurve(to: CGPoint(x: 220, y: 450), control: CGPoint(x: 140, y: 600))
            c.strokePath()
            c.move(to: CGPoint(x: 400, y: 900))
            c.addQuadCurve(to: CGPoint(x: 410, y: 480), control: CGPoint(x: 480, y: 650))
            c.strokePath()
            c.move(to: CGPoint(x: 600, y: 890))
            c.addQuadCurve(to: CGPoint(x: 570, y: 470), control: CGPoint(x: 640, y: 600))
            c.strokePath()
            strokeOval(c, CGRect(x: 160, y: 360, width: 120, height: 120))
            strokeOval(c, CGRect(x: 340, y: 380, width: 130, height: 130))
            strokeOval(c, CGRect(x: 510, y: 350, width: 120, height: 120))
            c.setLineWidth(5)
            strokeOval(c, CGRect(x: 640, y: 220, width: 70, height: 50))
            strokeRect(c, CGRect(x: 150, y: 180, width: 460, height: 6))
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

    private static func renderTRex() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 260, y: 280, width: 200, height: 220))
            strokeRect(c, CGRect(x: 420, y: 360, width: 180, height: 60))
            c.move(to: CGPoint(x: 600, y: 420))
            c.addLine(to: CGPoint(x: 680, y: 400))
            c.strokePath()
            c.move(to: CGPoint(x: 320, y: 500))
            c.addLine(to: CGPoint(x: 300, y: 720))
            c.addLine(to: CGPoint(x: 340, y: 720))
            c.strokePath()
            c.move(to: CGPoint(x: 400, y: 500))
            c.addLine(to: CGPoint(x: 420, y: 720))
            c.addLine(to: CGPoint(x: 380, y: 720))
            c.strokePath()
            c.move(to: CGPoint(x: 360, y: 720))
            c.addLine(to: CGPoint(x: 360, y: 860))
            c.strokePath()
            c.move(to: CGPoint(x: 420, y: 720))
            c.addLine(to: CGPoint(x: 420, y: 860))
            c.strokePath()
        }
    }

    private static func renderLongNeck() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 320, y: 200, width: 160, height: 140))
            strokeRect(c, CGRect(x: 380, y: 320, width: 80, height: 420))
            strokeOval(c, CGRect(x: 340, y: 720, width: 180, height: 120))
            c.move(to: CGPoint(x: 420, y: 740))
            c.addLine(to: CGPoint(x: 420, y: 900))
            c.strokePath()
            c.move(to: CGPoint(x: 480, y: 760))
            c.addLine(to: CGPoint(x: 500, y: 900))
            c.strokePath()
        }
    }

    private static func renderDinoEgg() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 280, y: 320, width: 240, height: 320))
            for (cx, cy) in [(360, 420), (440, 500), (340, 540), (480, 400)] as [(CGFloat, CGFloat)] {
                strokeOval(c, CGRect(x: cx - 22, y: cy - 18, width: 44, height: 36))
            }
        }
    }

    private static func renderVolcano() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 160, y: 780))
            c.addLine(to: CGPoint(x: 360, y: 420))
            c.addLine(to: CGPoint(x: 440, y: 420))
            c.addLine(to: CGPoint(x: 640, y: 780))
            c.closePath()
            c.strokePath()
            c.move(to: CGPoint(x: 380, y: 400))
            c.addLine(to: CGPoint(x: 400, y: 260))
            c.addLine(to: CGPoint(x: 420, y: 400))
            c.strokePath()
            for i in 0..<5 {
                let x: CGFloat = 340 + CGFloat(i) * 30
                c.move(to: CGPoint(x: x, y: 280))
                c.addLine(to: CGPoint(x: x + 10, y: 220))
                c.strokePath()
            }
        }
    }

    private static func renderFootprints() -> UIImage {
        render(lineWidth: 4) { c in
            for i in 0..<4 {
                let ox: CGFloat = 280 + CGFloat(i) * 90
                let oy: CGFloat = 400 + CGFloat(i % 2) * 70
                strokeOval(c, CGRect(x: ox, y: oy, width: 70, height: 90))
                strokeOval(c, CGRect(x: ox + 50, y: oy + 20, width: 50, height: 70))
            }
        }
    }

    private static func renderPictureFrame() -> UIImage {
        render(lineWidth: 4) { c in
            strokeRect(c, CGRect(x: 120, y: 200, width: 560, height: 640))
            strokeRect(c, CGRect(x: 200, y: 280, width: 400, height: 480))
            c.move(to: CGPoint(x: 400, y: 140))
            c.addLine(to: CGPoint(x: 400, y: 200))
            c.strokePath()
        }
    }

    private static func renderSunflowers() -> UIImage {
        render(lineWidth: 4) { c in
            for (cx, cy) in [(280, 420), (520, 380), (400, 620)] as [(CGFloat, CGFloat)] {
                strokeOval(c, CGRect(x: cx - 30, y: cy - 30, width: 60, height: 60))
            for a in stride(from: CGFloat(0), to: CGFloat.pi * 2, by: CGFloat.pi / 5) {
                let ox = cx + cos(a) * 70 - 20
                let oy = cy + sin(a) * 70 - 25
                strokeOval(c, CGRect(x: ox, y: oy, width: 40, height: 50))
            }
            }
        }
    }

    private static func renderSmilePortrait() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 220, y: 260, width: 360, height: 460))
            strokeOval(c, CGRect(x: 320, y: 380, width: 40, height: 50))
            strokeOval(c, CGRect(x: 440, y: 380, width: 40, height: 50))
            c.move(to: CGPoint(x: 320, y: 560))
            c.addQuadCurve(to: CGPoint(x: 480, y: 560), control: CGPoint(x: 400, y: 640))
            c.strokePath()
        }
    }

    private static func renderSwirlArt() -> UIImage {
        render(lineWidth: 4) { c in
            for r in stride(from: CGFloat(40), to: CGFloat(320), by: 36) {
                strokeOval(c, CGRect(x: 400 - r, y: 500 - r, width: r * 2, height: r * 2))
            }
        }
    }

    private static func renderStillLife() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 280, y: 520, width: 240, height: 80))
            strokeOval(c, CGRect(x: 340, y: 360, width: 120, height: 180))
            c.move(to: CGPoint(x: 520, y: 440))
            c.addLine(to: CGPoint(x: 560, y: 560))
            c.addLine(to: CGPoint(x: 480, y: 560))
            c.closePath()
            c.strokePath()
            strokeOval(c, CGRect(x: 200, y: 400, width: 100, height: 100))
        }
    }

    private static func renderCastle() -> UIImage {
        render(lineWidth: 4) { c in
            strokeRect(c, CGRect(x: 260, y: 400, width: 280, height: 320))
            for x in [260, 340, 420, 500] as [CGFloat] {
                strokeRect(c, CGRect(x: x, y: 320, width: 60, height: 100))
            }
            strokeRect(c, CGRect(x: 360, y: 260, width: 80, height: 80))
            c.move(to: CGPoint(x: 400, y: 260))
            c.addLine(to: CGPoint(x: 400, y: 200))
            c.strokePath()
        }
    }

    private static func renderMagicWand() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 200, y: 760))
            c.addLine(to: CGPoint(x: 560, y: 280))
            c.strokePath()
            strokeOval(c, CGRect(x: 520, y: 220, width: 120, height: 120))
            for i in 0..<6 {
                let a = CGFloat(i) / 6 * (.pi * 2)
                c.move(to: CGPoint(x: 580, y: 280))
                c.addLine(to: CGPoint(x: 580 + cos(a) * 40, y: 280 + sin(a) * 40))
                c.strokePath()
            }
        }
    }

    private static func renderDragon() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 280, y: 360, width: 200, height: 160))
            c.move(to: CGPoint(x: 480, y: 440))
            c.addLine(to: CGPoint(x: 620, y: 400))
            c.addLine(to: CGPoint(x: 520, y: 500))
            c.strokePath()
            c.move(to: CGPoint(x: 300, y: 500))
            c.addQuadCurve(to: CGPoint(x: 520, y: 640), control: CGPoint(x: 360, y: 620))
            c.addQuadCurve(to: CGPoint(x: 600, y: 520), control: CGPoint(x: 580, y: 600))
            c.strokePath()
            strokeOval(c, CGRect(x: 360, y: 400, width: 28, height: 32))
        }
    }

    private static func renderRainbow() -> UIImage {
        render(lineWidth: 4) { c in
            let cx: CGFloat = 400
            for i in 0..<5 {
                let r: CGFloat = 120 + CGFloat(i) * 50
                c.addArc(center: CGPoint(x: cx, y: 780), radius: r, startAngle: CGFloat.pi, endAngle: 0, clockwise: false)
                c.strokePath()
            }
        }
    }

    private static func renderUnicorn() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 260, y: 400, width: 220, height: 180))
            c.move(to: CGPoint(x: 260, y: 480))
            c.addLine(to: CGPoint(x: 200, y: 320))
            c.addLine(to: CGPoint(x: 240, y: 420))
            c.strokePath()
            strokeOval(c, CGRect(x: 500, y: 420, width: 140, height: 100))
            c.move(to: CGPoint(x: 360, y: 560))
            c.addQuadCurve(to: CGPoint(x: 420, y: 780), control: CGPoint(x: 320, y: 680))
            c.strokePath()
            c.move(to: CGPoint(x: 440, y: 560))
            c.addQuadCurve(to: CGPoint(x: 400, y: 780), control: CGPoint(x: 480, y: 680))
            c.strokePath()
        }
    }

    private static func renderCupcake() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 260, y: 620))
            c.addLine(to: CGPoint(x: 300, y: 520))
            c.addLine(to: CGPoint(x: 500, y: 520))
            c.addLine(to: CGPoint(x: 540, y: 620))
            c.closePath()
            c.strokePath()
            strokeOval(c, CGRect(x: 280, y: 440, width: 240, height: 100))
            for i in 0..<6 {
                let x: CGFloat = 300 + CGFloat(i) * 40
                c.move(to: CGPoint(x: x, y: 440))
                c.addQuadCurve(to: CGPoint(x: x + 20, y: 320), control: CGPoint(x: x + 30, y: 380))
                c.strokePath()
            }
        }
    }

    private static func renderPizza() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 400, y: 260))
            c.addLine(to: CGPoint(x: 640, y: 720))
            c.addLine(to: CGPoint(x: 160, y: 720))
            c.closePath()
            c.strokePath()
            for (px, py) in [(380, 520), (460, 580), (340, 620), (500, 640)] as [(CGFloat, CGFloat)] {
                strokeOval(c, CGRect(x: px - 12, y: py - 12, width: 24, height: 24))
            }
        }
    }

    private static func renderApple() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 400, y: 280))
            c.addQuadCurve(to: CGPoint(x: 280, y: 520), control: CGPoint(x: 260, y: 380))
            c.addQuadCurve(to: CGPoint(x: 400, y: 640), control: CGPoint(x: 320, y: 600))
            c.addQuadCurve(to: CGPoint(x: 520, y: 520), control: CGPoint(x: 540, y: 380))
            c.addQuadCurve(to: CGPoint(x: 400, y: 280), control: CGPoint(x: 480, y: 320))
            c.closePath()
            c.strokePath()
            c.move(to: CGPoint(x: 400, y: 280))
            c.addLine(to: CGPoint(x: 400, y: 220))
            c.strokePath()
        }
    }

    private static func renderIceCream() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 320, y: 320, width: 160, height: 160))
            c.move(to: CGPoint(x: 340, y: 460))
            c.addLine(to: CGPoint(x: 380, y: 720))
            c.addLine(to: CGPoint(x: 420, y: 720))
            c.addLine(to: CGPoint(x: 460, y: 460))
            c.closePath()
            c.strokePath()
        }
    }

    private static func renderDonut() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 220, y: 400, width: 360, height: 360))
            strokeOval(c, CGRect(x: 340, y: 520, width: 120, height: 120))
            for a in stride(from: CGFloat(0), to: CGFloat.pi * 2, by: CGFloat.pi / 4) {
                let cx = 400 + cos(a) * 150
                let cy = 580 + sin(a) * 150
                c.move(to: CGPoint(x: cx - sin(a) * 16, y: cy + cos(a) * 16))
                c.addLine(to: CGPoint(x: cx + sin(a) * 16, y: cy - cos(a) * 16))
                c.strokePath()
            }
        }
    }

    private static func renderGameController() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 200, y: 440, width: 400, height: 200))
            strokeOval(c, CGRect(x: 260, y: 500, width: 80, height: 80))
            strokeOval(c, CGRect(x: 460, y: 500, width: 50, height: 50))
            strokeOval(c, CGRect(x: 530, y: 500, width: 50, height: 50))
            c.move(to: CGPoint(x: 560, y: 520))
            c.addLine(to: CGPoint(x: 600, y: 520))
            c.strokePath()
        }
    }

    private static func renderBall() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 240, y: 360, width: 320, height: 320))
            c.move(to: CGPoint(x: 240, y: 520))
            c.addLine(to: CGPoint(x: 560, y: 520))
            c.strokePath()
            c.move(to: CGPoint(x: 400, y: 360))
            c.addLine(to: CGPoint(x: 400, y: 680))
            c.strokePath()
        }
    }

    private static func renderKite() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 400, y: 260))
            c.addLine(to: CGPoint(x: 560, y: 520))
            c.addLine(to: CGPoint(x: 400, y: 460))
            c.addLine(to: CGPoint(x: 240, y: 520))
            c.closePath()
            c.strokePath()
            c.move(to: CGPoint(x: 400, y: 460))
            c.addLine(to: CGPoint(x: 400, y: 820))
            c.strokePath()
        }
    }

    private static func renderBlocks() -> UIImage {
        render(lineWidth: 4) { c in
            strokeRect(c, CGRect(x: 280, y: 520, width: 120, height: 120))
            strokeRect(c, CGRect(x: 420, y: 480, width: 120, height: 120))
            strokeRect(c, CGRect(x: 340, y: 360, width: 120, height: 120))
        }
    }

    private static func renderTree() -> UIImage {
        render(lineWidth: 4) { c in
            strokeRect(c, CGRect(x: 370, y: 520, width: 60, height: 220))
            c.move(to: CGPoint(x: 400, y: 520))
            c.addLine(to: CGPoint(x: 260, y: 380))
            c.addLine(to: CGPoint(x: 320, y: 380))
            c.addLine(to: CGPoint(x: 400, y: 280))
            c.addLine(to: CGPoint(x: 480, y: 380))
            c.addLine(to: CGPoint(x: 540, y: 380))
            c.closePath()
            c.strokePath()
        }
    }

    private static func renderMountain() -> UIImage {
        render(lineWidth: 4) { c in
            c.move(to: CGPoint(x: 80, y: 720))
            c.addLine(to: CGPoint(x: 280, y: 380))
            c.addLine(to: CGPoint(x: 400, y: 520))
            c.addLine(to: CGPoint(x: 520, y: 320))
            c.addLine(to: CGPoint(x: 720, y: 720))
            c.strokePath()
            strokeOval(c, CGRect(x: 580, y: 200, width: 120, height: 120))
        }
    }

    private static func renderCloudySky() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 120, y: 280, width: 200, height: 120))
            strokeOval(c, CGRect(x: 260, y: 300, width: 220, height: 130))
            strokeOval(c, CGRect(x: 480, y: 260, width: 200, height: 110))
            c.move(to: CGPoint(x: 80, y: 680))
            c.addLine(to: CGPoint(x: 720, y: 680))
            c.strokePath()
            for i in 0..<4 {
                strokeOval(c, CGRect(x: 160 + CGFloat(i) * 140, y: 720, width: 40, height: 24))
            }
        }
    }

    private static func renderTurtle() -> UIImage {
        render(lineWidth: 4) { c in
            strokeOval(c, CGRect(x: 260, y: 460, width: 280, height: 200))
            strokeOval(c, CGRect(x: 220, y: 500, width: 80, height: 60))
            strokeOval(c, CGRect(x: 500, y: 500, width: 80, height: 60))
            strokeOval(c, CGRect(x: 320, y: 380, width: 160, height: 140))
            for (dx, dy) in [(-40, 40), (0, 50), (40, 40), (-20, 70), (20, 70)] as [(CGFloat, CGFloat)] {
                c.move(to: CGPoint(x: 400 + dx, y: 520 + dy))
                c.addLine(to: CGPoint(x: 400 + dx * 1.4, y: 600 + dy))
                c.strokePath()
            }
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
