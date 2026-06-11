import UIKit

/// Finger / Pencil strokes drawn above the template image.
final class ColoringStrokeView: UIView {

    private struct Stroke {
        var points: [CGPoint]
        var color: UIColor
        var width: CGFloat
        var isRainbowGlitter: Bool = false
        /// Random 0…1 phase shift so each new rainbow stroke starts at a different hue.
        var rainbowPhaseOffset: CGFloat = 0
        /// Eraser stroke (paper-colored paint); omitted from VLM color history.
        var isEraserStroke: Bool = false
    }

    private var strokes: [Stroke] = []
    private var current: Stroke?
    /// Strokes removed by undo, restored by redo (newest at end).
    private var redoStack: [Stroke] = []
    /// Set when undo drops the baked bitmap so redo can bring it back.
    private var redoBakedLayer: UIImage?
    private var redoFinishedColors: [UIColor]?
    /// Strokes older than the live window are flattened into this bitmap to bound memory.
    private var bakedLayer: UIImage?
    /// Number of live (un-baked) strokes kept so the most recent ones remain undoable.
    private static let liveStrokeWindow = 20
    /// One entry per finished stroke (chronological) for feedback prompts — capped to avoid huge histories.
    private var finishedStrokeColors: [UIColor] = []

    /// New stroke began — cancel deferred auto-feedback (SmartDraw-style).
    var onPaintingBegan: (() -> Void)?
    /// Finger / pencil lifted and a stroke was committed to the canvas.
    var onCommittedStrokeEnded: (() -> Void)?

    var strokeColor: UIColor = .systemRed
    var strokeWidth: CGFloat = 22
    /// When true, strokes cycle rainbow hues (crayon `20-default.png`).
    var usesRainbowGlitterStroke = false
    /// When true, strokes paint `strokeColor` (paper) to cover live and saved underlay art.
    var usesEraserStroke = false

    // MARK: - Live rainbow bitmap cache
    // Accumulates the in-progress rainbow stroke incrementally so draw() only blits one image
    // instead of issuing O(n) per-segment strokePath() calls every frame.
    private var rainbowLiveBitmap: UIImage?
    /// Number of points already rendered into rainbowLiveBitmap.
    private var rainbowBitmapPtCount: Int = 0

    override init(frame: CGRect) {
        super.init(frame: frame)
        backgroundColor = .clear
        isMultipleTouchEnabled = false
        isOpaque = false
        contentMode = .redraw
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        backgroundColor = .clear
        isOpaque = false
        contentMode = .redraw
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let touch = touches.first else { return }
        beginStroke(at: touch.location(in: self), touch: touch)
    }

    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let t = touches.first else { return }
        appendStrokePoints(coalescedPoints(for: t, event: event), touch: t)
    }

    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        finalizeCurrentStroke(with: touches.first)
    }

    override func touchesCancelled(_ touches: Set<UITouch>, with event: UIEvent?) {
        cancelInProgressStroke()
    }

    private func coalescedPoints(for touch: UITouch, event: UIEvent?, fallback: CGPoint? = nil) -> [CGPoint] {
        var pts: [CGPoint] = []
        if let coalesced = event?.coalescedTouches(for: touch) {
            for ct in coalesced {
                pts.append(ct.location(in: self))
            }
        } else if let fallback {
            pts.append(fallback)
        } else {
            pts.append(touch.location(in: self))
        }
        return pts
    }

    private func beginStroke(at point: CGPoint, touch: UITouch?) {
        onPaintingBegan?()
        current = Stroke(
            points: [point],
            color: strokeColor,
            width: scaledWidth(for: touch),
            isRainbowGlitter: usesRainbowGlitterStroke,
            rainbowPhaseOffset: usesRainbowGlitterStroke ? CGFloat.random(in: 0..<1) : 0,
            isEraserStroke: usesEraserStroke
        )
        rainbowLiveBitmap = nil
        rainbowBitmapPtCount = 0
        setNeedsDisplay()
    }

    private func appendStrokePoints(_ points: [CGPoint], touch: UITouch?) {
        guard !points.isEmpty else { return }
        current?.points.append(contentsOf: points)
        current?.width = scaledWidth(for: touch)
        if current?.isRainbowGlitter == true { growRainbowBitmap() }
        setNeedsDisplay()
    }

    /// Drops the live stroke without committing (e.g. when a pinch takes over the first finger).
    func cancelInProgressStroke() {
        current = nil
        rainbowLiveBitmap = nil
        rainbowBitmapPtCount = 0
        setNeedsDisplay()
    }

    private func finalizeCurrentStroke(with touch: UITouch?) {
        defer { current = nil }
        guard var s = current, s.points.count >= 1 else {
            setNeedsDisplay()
            return
        }
        if let touch {
            s.width = scaledWidth(for: touch)
        }
        strokes.append(s)
        if !s.isEraserStroke {
            finishedStrokeColors.append(
                s.isRainbowGlitter ? MagicBrushyRainbowGlitterStroke.historyTagColor : s.color
            )
        }
        rainbowLiveBitmap = nil
        rainbowBitmapPtCount = 0
        if finishedStrokeColors.count > 48 {
            finishedStrokeColors.removeFirst(finishedStrokeColors.count - 48)
        }
        clearRedoHistory()
        bakeOldStrokesIfNeeded()
        onCommittedStrokeEnded?()
        setNeedsDisplay()
    }

    /// Flatten strokes older than the live window into a bitmap so the strokes array stays small.
    private func bakeOldStrokesIfNeeded() {
        let liveWindow = Self.liveStrokeWindow
        guard strokes.count > liveWindow else { return }
        let toBake = Array(strokes.prefix(strokes.count - liveWindow))
        strokes = Array(strokes.suffix(liveWindow))
        let sz = bounds.size
        guard sz.width > 1, sz.height > 1 else { return }
        let format = UIGraphicsImageRendererFormat.default()
        format.opaque = false
        format.scale = self.window?.screen.scale ?? contentScaleFactor
        bakedLayer = UIGraphicsImageRenderer(size: sz, format: format).image { ctx in
            bakedLayer?.draw(in: CGRect(origin: .zero, size: sz))
            let c = ctx.cgContext
            for s in toBake { paintStroke(s, in: c) }
        }
    }

    private func paintStroke(_ stroke: Stroke, in ctx: CGContext) {
        if stroke.isRainbowGlitter {
            MagicBrushyRainbowGlitterStroke.paint(
                points: stroke.points,
                width: stroke.width,
                canvasWidth: bounds.width,
                phaseOffset: stroke.rainbowPhaseOffset,
                in: ctx
            )
            return
        }
        paintStrokeGeometry(stroke, in: ctx)
    }

    private func paintStrokeGeometry(_ stroke: Stroke, in ctx: CGContext) {
        guard stroke.points.count >= 2 else {
            ctx.setFillColor(stroke.color.cgColor)
            let r = stroke.width * 0.55
            if let q = stroke.points.first {
                ctx.fillEllipse(in: CGRect(x: q.x - r, y: q.y - r, width: r * 2, height: r * 2))
            }
            return
        }
        ctx.setStrokeColor(stroke.color.cgColor)
        ctx.setLineWidth(stroke.width)
        ctx.setLineCap(.round)
        ctx.setLineJoin(.round)
        ctx.beginPath()
        ctx.move(to: stroke.points[0])
        for i in 1..<stroke.points.count { ctx.addLine(to: stroke.points[i]) }
        ctx.strokePath()
    }

    private func scaledWidth(for touch: UITouch?) -> CGFloat {
        guard let touch else { return strokeWidth }
        if touch.type == .pencil, touch.maximumPossibleForce > 0 {
            let n = CGFloat(touch.force / touch.maximumPossibleForce).clamped(to: 0.15...1)
            return strokeWidth * (0.45 + 0.55 * n)
        }
        return strokeWidth
    }

    /// Sampled points in the most recently **finished** stroke (0 if none). Used to decide whether we pass a palette hint to the vision model.
    var lastFinishedStrokePointCount: Int {
        strokes.last?.points.count ?? 0
    }

    /// Where the newest finished stroke sits on the canvas (UIKit coords, origin top-left), for steering the coach VLM toward the last painted area.
    func lastFinishedStrokeSpatialHint() -> String? {
        guard let stroke = strokes.last, !stroke.points.isEmpty else { return nil }
        let w = bounds.width
        let h = bounds.height
        guard w > 4, h > 4 else { return nil }
        var minX = CGFloat.greatestFiniteMagnitude
        var maxX = -CGFloat.greatestFiniteMagnitude
        var minY = CGFloat.greatestFiniteMagnitude
        var maxY = -CGFloat.greatestFiniteMagnitude
        for p in stroke.points {
            minX = min(minX, p.x)
            maxX = max(maxX, p.x)
            minY = min(minY, p.y)
            maxY = max(maxY, p.y)
        }
        let pad = max(stroke.width, 8)
        minX = max(0, minX - pad)
        maxX = min(w, maxX + pad)
        minY = max(0, minY - pad)
        maxY = min(h, maxY + pad)
        let cx = ((minX + maxX) * 0.5) / w
        let cy = ((minY + maxY) * 0.5) / h
        let horiz: String
        if cx < 0.34 { horiz = "left" } else if cx > 0.66 { horiz = "right" } else { horiz = "center" }
        let vert: String
        if cy < 0.34 { vert = "upper" } else if cy > 0.66 { vert = "lower" } else { vert = "middle" }
        return "Their newest brush stroke is centered roughly in the \(horiz)-\(vert) part of the picture (inside the coloring area)."
    }

    @discardableResult
    func undoLastStroke() -> Bool {
        if !strokes.isEmpty {
            redoStack.append(strokes.removeLast())
            if !finishedStrokeColors.isEmpty { finishedStrokeColors.removeLast() }
            setNeedsDisplay()
            return true
        }
        if bakedLayer != nil {
            redoBakedLayer = bakedLayer
            redoFinishedColors = finishedStrokeColors
            bakedLayer = nil
            finishedStrokeColors.removeAll()
            setNeedsDisplay()
            return true
        }
        return false
    }

    var canRedo: Bool {
        !redoStack.isEmpty || redoBakedLayer != nil
    }

    @discardableResult
    func redoLastStroke() -> Bool {
        if !redoStack.isEmpty {
            let restored = redoStack.removeLast()
            strokes.append(restored)
            if !restored.isEraserStroke {
                finishedStrokeColors.append(
                    restored.isRainbowGlitter ? MagicBrushyRainbowGlitterStroke.historyTagColor : restored.color
                )
            }
            if finishedStrokeColors.count > 48 {
                finishedStrokeColors.removeFirst(finishedStrokeColors.count - 48)
            }
            bakeOldStrokesIfNeeded()
            setNeedsDisplay()
            return true
        }
        if let baked = redoBakedLayer {
            bakedLayer = baked
            if let colors = redoFinishedColors {
                finishedStrokeColors = colors
            }
            redoBakedLayer = nil
            redoFinishedColors = nil
            setNeedsDisplay()
            return true
        }
        return false
    }

    func clearStrokes() {
        strokes.removeAll()
        finishedStrokeColors.removeAll()
        bakedLayer = nil
        current = nil
        clearRedoHistory()
        setNeedsDisplay()
    }

    private func clearRedoHistory() {
        redoStack.removeAll()
        redoBakedLayer = nil
        redoFinishedColors = nil
    }

    /// Whether the user has placed any paint (including fully baked strokes).
    var hasUserPaint: Bool {
        current != nil || !strokes.isEmpty || bakedLayer != nil
    }

    /// Axis-aligned bounds of a stroke including line width (view coordinates).
    private func tightBounds(of stroke: Stroke) -> CGRect {
        guard let p0 = stroke.points.first else { return .zero }
        if stroke.points.count == 1 {
            let r = stroke.width * 0.55
            return CGRect(x: p0.x - r, y: p0.y - r, width: r * 2, height: r * 2)
        }
        var minX = p0.x, maxX = p0.x, minY = p0.y, maxY = p0.y
        for p in stroke.points {
            minX = min(minX, p.x)
            maxX = max(maxX, p.x)
            minY = min(minY, p.y)
            maxY = max(maxY, p.y)
        }
        let half = stroke.width * 0.5
        return CGRect(
            x: minX - half,
            y: minY - half,
            width: (maxX - minX) + stroke.width,
            height: (maxY - minY) + stroke.width
        )
    }

    /// Rect around the **last finished** stroke, padded, then grown so width and height are each at least `minCanvasFraction` of the canvas. Used to crop the image sent to the VLM.
    func vlmCropRectAroundLastFinishedStroke(minCanvasFraction: CGFloat = 0.5) -> CGRect? {
        guard let last = strokes.last else { return nil }
        let b = tightBounds(of: last)
        let bw = max(b.width, 8)
        let bh = max(b.height, 8)
        let padX = bw * 0.5
        let padY = bh * 0.5
        let expanded = b.insetBy(dx: -padX, dy: -padY)
        let r = expanded.intersection(bounds)
        guard r.width > 1, r.height > 1 else { return nil }

        let fraction = min(1, max(0.1, minCanvasFraction))
        let minW = max(8, bounds.width * fraction)
        let minH = max(8, bounds.height * fraction)
        var w = max(r.width, minW)
        var h = max(r.height, minH)
        w = min(w, bounds.width)
        h = min(h, bounds.height)

        let cx = r.midX
        let cy = r.midY
        var x = cx - w * 0.5
        var y = cy - h * 0.5
        x = max(bounds.minX, min(x, bounds.maxX - w))
        y = max(bounds.minY, min(y, bounds.maxY - h))

        let out = CGRect(x: x, y: y, width: w, height: h)
        guard out.width > 8, out.height > 8 else { return nil }
        return out
    }

    /// Transparent-backed image of baked + live strokes only (for compositing on top of template or resume underlay).
    func strokesOnlyImage(displayScale: CGFloat) -> UIImage? {
        guard current != nil || !strokes.isEmpty || bakedLayer != nil else { return nil }
        let sz = bounds.size
        guard sz.width > 1, sz.height > 1 else { return nil }
        let format = UIGraphicsImageRendererFormat.default()
        format.scale = max(1, displayScale)
        format.opaque = false
        let r = CGRect(origin: .zero, size: sz)
        return UIGraphicsImageRenderer(size: sz, format: format).image { _ in
            if let baked = bakedLayer {
                baked.draw(in: r)
            }
            guard let ctx = UIGraphicsGetCurrentContext() else { return }
            for s in strokes { paintStroke(s, in: ctx) }
            if let cur = current { paintStroke(cur, in: ctx) }
        }
    }

    func snapshotComposite(
        underneath template: UIImage?,
        lineOverlay: UIImage?,
        in bounds: CGRect
    ) -> UIImage {
        let w = bounds.width.rounded(.down)
        let h = bounds.height.rounded(.down)
        guard w > 0.5, h > 0.5 else {
            let safe = CGSize(width: 8, height: 8)
            let r = UIGraphicsImageRenderer(size: safe)
            return r.image { _ in
                UIColor.white.setFill()
                UIBezierPath(rect: CGRect(origin: .zero, size: safe)).fill()
            }
        }
        // Cap snapshot at 512 px — the VLM never needs more, so rendering at 2× display
        // scale wastes 4× the memory for zero quality gain.
        let maxEdge: CGFloat = 512
        let scale = min(maxEdge / w, maxEdge / h, 1.0)
        let pixelSize = CGSize(width: max(8, (w * scale).rounded()),
                               height: max(8, (h * scale).rounded()))
        let rect = CGRect(origin: .zero, size: pixelSize)

        let format = UIGraphicsImageRendererFormat.default()
        format.opaque = true
        format.scale = 1   // already in physical pixels
        let renderer = UIGraphicsImageRenderer(size: pixelSize, format: format)
        return renderer.image { _ in
            UIColor.white.setFill()
            UIBezierPath(rect: rect).fill()
            if let img = template { img.draw(in: Self.aspectFitRect(for: img, in: rect)) }
            if let baked = bakedLayer { baked.draw(in: rect) }
            guard let ctx = UIGraphicsGetCurrentContext() else { return }
            ctx.saveGState()
            ctx.scaleBy(x: scale, y: scale)
            for s in strokes { paintStroke(s, in: ctx) }
            if let cur = current { paintStroke(cur, in: ctx) }
            ctx.restoreGState()
            if let line = lineOverlay { line.draw(in: Self.aspectFitRect(for: line, in: rect)) }
        }
    }

    private static func aspectFitRect(for image: UIImage, in bounds: CGRect) -> CGRect {
        let sz = image.size
        guard sz.width > 0.5, sz.height > 0.5, bounds.width > 0.5, bounds.height > 0.5 else { return bounds }
        let s = min(bounds.width / sz.width, bounds.height / sz.height)
        let w = sz.width * s
        let h = sz.height * s
        return CGRect(x: bounds.midX - w * 0.5, y: bounds.midY - h * 0.5, width: w, height: h)
    }

    /// Colors used on each finished brush stroke, oldest first — up to recent cap.
    var chronologicalStrokeColors: [UIColor] {
        finishedStrokeColors
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext() else { return }
        if let baked = bakedLayer { baked.draw(in: bounds) }
        for s in strokes { paintStroke(s, in: ctx) }
        if let cur = current {
            if cur.isRainbowGlitter, let bmp = rainbowLiveBitmap {
                // O(1): just blit the pre-rendered bitmap — no per-segment draw calls.
                bmp.draw(in: bounds)
            } else {
                paintStroke(cur, in: ctx)
            }
        }
    }

    // MARK: - Incremental rainbow bitmap

    private func growRainbowBitmap() {
        guard let s = current, s.isRainbowGlitter else { return }
        let pts = s.points
        guard pts.count >= 2 else { return }

        // Overlap by one point so round-joins knit seamlessly.
        let fromIdx = max(0, rainbowBitmapPtCount - 1)
        guard fromIdx < pts.count - 1 else { return }

        let sz = bounds.size
        guard sz.width > 1, sz.height > 1 else { return }

        let slice = Array(pts[fromIdx...])
        let existing = rainbowLiveBitmap
        let fmt = UIGraphicsImageRendererFormat.default()
        fmt.opaque = false
        fmt.scale = contentScaleFactor
        rainbowLiveBitmap = UIGraphicsImageRenderer(size: sz, format: fmt).image { _ in
            existing?.draw(in: CGRect(origin: .zero, size: sz))
            guard let ctx = UIGraphicsGetCurrentContext() else { return }
            MagicBrushyRainbowGlitterStroke.paintTail(
                points: slice,
                canvasWidth: sz.width,
                phaseOffset: s.rainbowPhaseOffset,
                width: s.width,
                in: ctx
            )
        }

        rainbowBitmapPtCount = pts.count
    }
}

// MARK: - Rainbow glitter stroke (`colors 2/17.png`)

enum MagicBrushyRainbowGlitterStroke {
    /// Fill for brush-size dots when the rainbow crayon is active.
    static let uiAccentColor = UIColor(red: 0.18, green: 0.42, blue: 1.00, alpha: 1)

    /// Stored in stroke history so VLM / kid-name hints can identify rainbow paint.
    static let historyTagColor = UIColor(red: 0.501, green: 0.001, blue: 0.999, alpha: 1)

    /// Horizontal rainbow on the crayon asset: cyan → blue → purple → magenta → red → orange → yellow.
    private static let bandColors: [UIColor] = [
        UIColor(red: 0.00, green: 0.88, blue: 0.96, alpha: 1),
        UIColor(red: 0.18, green: 0.42, blue: 1.00, alpha: 1),
        UIColor(red: 0.52, green: 0.18, blue: 0.96, alpha: 1),
        UIColor(red: 0.94, green: 0.20, blue: 0.72, alpha: 1),
        UIColor(red: 1.00, green: 0.22, blue: 0.28, alpha: 1),
        UIColor(red: 1.00, green: 0.52, blue: 0.08, alpha: 1),
        UIColor(red: 1.00, green: 0.88, blue: 0.12, alpha: 1),
    ]

    /// Pre-extracted components — avoids repeated getRed/getGreen calls in the hot path.
    private static let bandRGBA: [(r: CGFloat, g: CGFloat, b: CGFloat)] = {
        bandColors.map { c in
            var r: CGFloat = 0, g: CGFloat = 0, b: CGFloat = 0, a: CGFloat = 0
            c.getRed(&r, green: &g, blue: &b, alpha: &a)
            return (r, g, b)
        }
    }()

    /// One full rainbow sweep every this many points of horizontal travel (shorter = faster color shifts).
    private static let xCycleWidth: CGFloat = 120

    /// Rainbow hue from horizontal position; `phaseOffset` randomizes the starting color per stroke.
    static func colorAt(x: CGFloat, canvasWidth: CGFloat, phaseOffset: CGFloat) -> CGColor {
        guard canvasWidth > 0.5 else { return colorAtNormalized(phaseOffset) }
        var t = (x / xCycleWidth + phaseOffset).truncatingRemainder(dividingBy: 1)
        if t < 0 { t += 1 }
        return colorAtNormalized(t)
    }

    private static func colorAtNormalized(_ t: CGFloat) -> CGColor {
        let clamped = max(0, min(1, t))
        let band = bandRGBA
        let scaled = clamped * CGFloat(band.count - 1)
        let idx = min(Int(scaled), band.count - 2)
        let frac = scaled - CGFloat(idx)
        let c0 = band[idx], c1 = band[idx + 1]
        return UIColor(
            red:   c0.r + (c1.r - c0.r) * frac,
            green: c0.g + (c1.g - c0.g) * frac,
            blue:  c0.b + (c1.b - c0.b) * frac,
            alpha: 1
        ).cgColor
    }

    // MARK: - Incremental tail renderer (used for the live stroke bitmap)

    /// Paint only the segments in `points[0…]`; each segment color follows its midpoint x.
    static func paintTail(
        points: [CGPoint],
        canvasWidth: CGFloat,
        phaseOffset: CGFloat,
        width: CGFloat,
        in ctx: CGContext
    ) {
        guard points.count >= 2 else {
            if let p = points.first {
                ctx.setFillColor(colorAt(x: p.x, canvasWidth: canvasWidth, phaseOffset: phaseOffset))
                let r = width * 0.55
                ctx.fillEllipse(in: CGRect(x: p.x - r, y: p.y - r, width: r * 2, height: r * 2))
            }
            return
        }
        ctx.setLineCap(.round)
        ctx.setLineJoin(.round)
        ctx.setLineWidth(width)
        for i in 1..<points.count {
            let midX = (points[i - 1].x + points[i].x) * 0.5
            ctx.setStrokeColor(colorAt(x: midX, canvasWidth: canvasWidth, phaseOffset: phaseOffset))
            ctx.beginPath()
            ctx.move(to: points[i - 1])
            ctx.addLine(to: points[i])
            ctx.strokePath()
        }
    }

    // MARK: - Finalised stroke renderer (bitmap is gone; draw full path)

    static func paint(
        points: [CGPoint],
        width: CGFloat,
        canvasWidth: CGFloat,
        phaseOffset: CGFloat,
        in ctx: CGContext
    ) {
        paintTail(points: points, canvasWidth: canvasWidth, phaseOffset: phaseOffset, width: width, in: ctx)
    }

    private static func paintDot(at center: CGPoint, width: CGFloat, color: UIColor, in ctx: CGContext) {
        ctx.setFillColor(color.cgColor)
        let r = width * 0.55
        ctx.fillEllipse(in: CGRect(x: center.x - r, y: center.y - r, width: r * 2, height: r * 2))
    }
}

private extension Comparable {
    func clamped(to range: ClosedRange<Self>) -> Self {
        min(max(self, range.lowerBound), range.upperBound)
    }
}

private enum MagicBrushyLineArtCache {
    static let store = NSCache<AnyObject, UIImage>()
    /// Bump when outline tuning changes so stale overlays are not reused across app runs.
    static let version = 4

    /// Pointer-identity key — unique per distinct CGImage object, never collides on same-size assets.
    static func key(for cg: CGImage) -> AnyObject {
        Unmanaged.passUnretained(cg).toOpaque() as AnyObject
    }
}

/// Tuning for template outlines (see `magicBrushyLineArtOverlay`).
private enum MagicBrushyLineArtStyle {
    /// Pixels brighter than this are treated as paper (transparent).
    static let paperLum: Double = 220
    /// Pixels darker than this are full-strength ink; raising this thins the lines.
    static let inkLum: Double = 115
    /// Ink color (0 = black, 255 = white).
    static let inkGray: Double = 0
    /// Peak opacity for the darkest ink (255 = fully opaque outlines).
    static let inkAlphaMax: Double = 255
}

extension UIImage {

    /// Full-resolution PNGs in the 1× asset slot report `scale == 1` with huge point sizes; normalize for Retina layout.
    func magicBrushyNormalizedAssetScale() -> UIImage {
        guard scale == 1, let cg = cgImage else { return self }
        let pxW = CGFloat(cg.width)
        let pxH = CGFloat(cg.height)
        guard pxW > 600 || pxH > 600 else { return self }
        let displayScale = UIScreen.main.scale
        return UIImage(cgImage: cg, scale: displayScale, orientation: imageOrientation)
    }

    /// Grid / home thumbnails: composite transparent line art onto warm paper so previews are not a black rectangle.
    func magicBrushyCompositedOnPaper(fill: UIColor = FigmaTheme.canvasFill) -> UIImage {
        let drawRect = CGRect(origin: .zero, size: size)
        let format = UIGraphicsImageRendererFormat()
        format.scale = scale
        format.opaque = true
        return UIGraphicsImageRenderer(size: size, format: format).image { _ in
            fill.setFill()
            UIBezierPath(rect: drawRect).fill()
            draw(in: drawRect)
        }
    }

    /// Line art on a transparent background so it can sit above user paint (including white eraser).
    /// Light paper drops out; dark strokes become crisp near-black outlines with soft anti-aliased edges.
    /// Figma exports (`Mask group`, numbered PNGs) are already black ink on transparency — keep their alpha as-is.
    func magicBrushyLineArtOverlay() -> UIImage {
        guard let cgKey = cgImage else { return self }
        if let cached = MagicBrushyLineArtCache.store.object(forKey: MagicBrushyLineArtCache.key(for: cgKey)) {
            return cached
        }

        let format = UIGraphicsImageRendererFormat()
        format.scale = scale
        format.opaque = false
        let sampled = UIGraphicsImageRenderer(size: size, format: format).image { _ in
            draw(in: CGRect(origin: .zero, size: size))
        }
        guard let cg = sampled.cgImage else { return self }

        if magicBrushyLooksLikeTransparentLineArt(cg: cg) {
            let out = magicBrushyTransparentInkOverlay(from: cg)
            MagicBrushyLineArtCache.store.setObject(out, forKey: MagicBrushyLineArtCache.key(for: cgKey))
            return out
        }

        let out = magicBrushyLuminanceLineArtOverlay(from: cg)
        MagicBrushyLineArtCache.store.setObject(out, forKey: MagicBrushyLineArtCache.key(for: cgKey))
        return out
    }

    /// True when most pixels are fully transparent — typical Figma line-art export.
    private func magicBrushyLooksLikeTransparentLineArt(cg: CGImage) -> Bool {
        let sampleW = min(96, cg.width)
        let sampleH = min(96, cg.height)
        guard sampleW > 0, sampleH > 0 else { return false }

        let rowBytes = sampleW * 4
        guard let data = NSMutableData(length: rowBytes * sampleH) else { return false }
        let ptr = data.mutableBytes.assumingMemoryBound(to: UInt8.self)
        let bitmapInfo = CGImageAlphaInfo.premultipliedFirst.rawValue | CGBitmapInfo.byteOrder32Little.rawValue
        guard let ctx = CGContext(
            data: ptr,
            width: sampleW,
            height: sampleH,
            bitsPerComponent: 8,
            bytesPerRow: rowBytes,
            space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: bitmapInfo
        ) else { return false }

        ctx.interpolationQuality = .medium
        ctx.draw(cg, in: CGRect(x: 0, y: 0, width: sampleW, height: sampleH))

        var transparentCount = 0
        let total = sampleW * sampleH
        for y in 0..<sampleH {
            var o = y * rowBytes
            for _ in 0..<sampleW {
                if ptr[o + 3] < 12 { transparentCount += 1 }
                o += 4
            }
        }
        return Double(transparentCount) / Double(total) > 0.45
    }

    /// Preserve source alpha; force ink to near-black (already exported from Figma).
    private func magicBrushyTransparentInkOverlay(from cg: CGImage) -> UIImage {
        let w = cg.width
        let h = cg.height
        let rowBytes = w * 4
        guard let data = NSMutableData(length: rowBytes * h) else { return self }
        let ptr = data.mutableBytes.assumingMemoryBound(to: UInt8.self)
        let bitmapInfo = CGImageAlphaInfo.premultipliedFirst.rawValue | CGBitmapInfo.byteOrder32Little.rawValue
        guard let ctx = CGContext(
            data: ptr,
            width: w,
            height: h,
            bitsPerComponent: 8,
            bytesPerRow: rowBytes,
            space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: bitmapInfo
        ) else { return self }

        ctx.draw(cg, in: CGRect(x: 0, y: 0, width: w, height: h))

        for y in 0..<h {
            var o = y * rowBytes
            for _ in 0..<w {
                let aIn = ptr[o + 3]
                if aIn < 6 {
                    ptr[o] = 0
                    ptr[o + 1] = 0
                    ptr[o + 2] = 0
                    ptr[o + 3] = 0
                } else {
                    ptr[o] = 0
                    ptr[o + 1] = 0
                    ptr[o + 2] = 0
                    ptr[o + 3] = aIn
                }
                o += 4
            }
        }

        guard let outCg = ctx.makeImage() else { return self }
        return UIImage(cgImage: outCg, scale: scale, orientation: imageOrientation)
    }

    /// Legacy white-paper templates: derive ink from luminance and drop bright paper.
    private func magicBrushyLuminanceLineArtOverlay(from cg: CGImage) -> UIImage {
        let w = cg.width
        let h = cg.height
        let rowBytes = w * 4
        guard let data = NSMutableData(length: rowBytes * h) else { return self }
        let ptr = data.mutableBytes.assumingMemoryBound(to: UInt8.self)

        let bitmapInfo = CGImageAlphaInfo.premultipliedFirst.rawValue | CGBitmapInfo.byteOrder32Little.rawValue
        guard let ctx = CGContext(
            data: ptr,
            width: w,
            height: h,
            bitsPerComponent: 8,
            bytesPerRow: rowBytes,
            space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: bitmapInfo
        ) else { return self }

        ctx.draw(cg, in: CGRect(x: 0, y: 0, width: w, height: h))

        let paperLum = MagicBrushyLineArtStyle.paperLum
        let inkLum = MagicBrushyLineArtStyle.inkLum
        let inkGray = MagicBrushyLineArtStyle.inkGray
        let inkAlphaMax = MagicBrushyLineArtStyle.inkAlphaMax
        let lumSpan = max(1, paperLum - inkLum)

        for y in 0..<h {
            var o = y * rowBytes
            for _ in 0..<w {
                let b = Double(ptr[o])
                let g = Double(ptr[o + 1])
                let r = Double(ptr[o + 2])
                let aIn = Double(ptr[o + 3])
                if aIn < 2 {
                    ptr[o] = 0
                    ptr[o + 1] = 0
                    ptr[o + 2] = 0
                    ptr[o + 3] = 0
                } else {
                    let lum = 0.299 * r + 0.587 * g + 0.114 * b
                    let strength: Double
                    if lum >= paperLum {
                        strength = 0
                    } else if lum <= inkLum {
                        strength = min(1, (inkLum - lum) / inkLum)
                    } else {
                        strength = 1 - (lum - inkLum) / lumSpan
                    }

                    if strength <= 0.02 {
                        ptr[o] = 0
                        ptr[o + 1] = 0
                        ptr[o + 2] = 0
                        ptr[o + 3] = 0
                    } else {
                        let a = UInt8((inkAlphaMax * strength).rounded())
                        if a < 6 {
                            ptr[o] = 0
                            ptr[o + 1] = 0
                            ptr[o + 2] = 0
                            ptr[o + 3] = 0
                        } else {
                            let premult = UInt8((inkGray * Double(a) / 255).rounded())
                            ptr[o] = premult
                            ptr[o + 1] = premult
                            ptr[o + 2] = premult
                            ptr[o + 3] = a
                        }
                    }
                }
                o += 4
            }
        }

        guard let outCg = ctx.makeImage() else { return self }
        return UIImage(cgImage: outCg, scale: scale, orientation: imageOrientation)
    }
}
