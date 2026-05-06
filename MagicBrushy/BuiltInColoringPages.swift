import UIKit

enum BuiltInColoringPages {

    struct Page {
        let title: String
        let image: UIImage
    }

    static let all: [Page] = [
        Page(title: "House", image: renderHouse()),
        Page(title: "Rocket", image: renderRocket()),
        Page(title: "Garden", image: renderGarden()),
    ]

    private static func render(size: CGSize = CGSize(width: 800, height: 1000), draw: (CGContext) -> Void) -> UIImage {
        let format = UIGraphicsImageRendererFormat.default()
        format.opaque = true
        // Fixed scale — avoid UIScreen/trait lookups during nib/storyboard VC property init timing.
        format.scale = 1
        let r = UIGraphicsImageRenderer(size: size, format: format)
        return r.image { ctx in
            let c = ctx.cgContext
            c.setFillColor(UIColor.white.cgColor)
            c.fill(CGRect(origin: .zero, size: size))
            c.setStrokeColor(UIColor.black.cgColor)
            c.setLineWidth(5)
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
            // Roof
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
            // Ground
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
            // Flames outline
            c.move(to: CGPoint(x: cx - 45, y: 820))
            c.addLine(to: CGPoint(x: cx, y: 950))
            c.addLine(to: CGPoint(x: cx + 45, y: 820))
            c.strokePath()
            // Stars
            for p in [(100, 200), (650, 250), (700, 120), (90, 100)] as [(CGFloat, CGFloat)] {
                c.addRect(CGRect(x: p.0, y: p.1, width: 36, height: 36))
                c.strokePath()
            }
        }
    }

    private static func renderGarden() -> UIImage {
        render { c in
            // Flower stems
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
}
