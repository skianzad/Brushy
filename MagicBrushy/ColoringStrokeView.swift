import UIKit

/// Finger / Pencil strokes drawn above the template image.
final class ColoringStrokeView: UIView {

    private struct Stroke {
        var points: [CGPoint]
        var color: UIColor
        var width: CGFloat
    }

    private var strokes: [Stroke] = []
    private var current: Stroke?
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
        guard let p = touches.first?.location(in: self) else { return }
        onPaintingBegan?()
        current = Stroke(points: [p], color: strokeColor, width: scaledWidth(for: touches.first))
        setNeedsDisplay()
    }

    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let t = touches.first else { return }
        var pts: [CGPoint] = []
        if let coalesced = event?.coalescedTouches(for: t) {
            for ct in coalesced {
                pts.append(ct.location(in: self))
            }
        } else {
            pts.append(t.location(in: self))
        }
        current?.points.append(contentsOf: pts)
        current?.width = scaledWidth(for: t)
        setNeedsDisplay()
    }

    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        finalizeCurrentStroke(with: touches.first)
    }

    override func touchesCancelled(_ touches: Set<UITouch>, with event: UIEvent?) {
        finalizeCurrentStroke(with: touches.first)
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
        finishedStrokeColors.append(s.color)
        if finishedStrokeColors.count > 48 {
            finishedStrokeColors.removeFirst(finishedStrokeColors.count - 48)
        }
        bakeOldStrokesIfNeeded()
        onCommittedStrokeEnded?()
        setNeedsDisplay()
    }

    /// Flatten strokes older than the live window into a bitmap so the strokes array stays small.
    private func bakeOldStrokesIfNeeded() {
        let window = Self.liveStrokeWindow
        guard strokes.count > window else { return }
        let toBake = Array(strokes.prefix(strokes.count - window))
        strokes = Array(strokes.suffix(window))
        let sz = bounds.size
        guard sz.width > 1, sz.height > 1 else { return }
        let format = UIGraphicsImageRendererFormat.default()
        format.opaque = false
        format.scale = 1
        bakedLayer = UIGraphicsImageRenderer(size: sz, format: format).image { ctx in
            bakedLayer?.draw(in: CGRect(origin: .zero, size: sz))
            let c = ctx.cgContext
            for s in toBake { paintStroke(s, in: c) }
        }
    }

    private func paintStroke(_ stroke: Stroke, in ctx: CGContext) {
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

    func undoLastStroke() {
        if !strokes.isEmpty {
            strokes.removeLast()
            if !finishedStrokeColors.isEmpty { finishedStrokeColors.removeLast() }
        } else if bakedLayer != nil {
            // All live strokes already undone — drop the whole baked layer
            bakedLayer = nil
            finishedStrokeColors.removeAll()
        }
        setNeedsDisplay()
    }

    func clearStrokes() {
        strokes.removeAll()
        finishedStrokeColors.removeAll()
        bakedLayer = nil
        current = nil
        setNeedsDisplay()
    }

    func snapshotComposite(underneath template: UIImage?, in bounds: CGRect) -> UIImage {
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
            if let img = template { img.draw(in: rect) }
            // Baked historical strokes (drawn as a flat image, scales to pixelSize).
            if let baked = bakedLayer { baked.draw(in: rect) }
            guard let ctx = UIGraphicsGetCurrentContext() else { return }
            // Live strokes are stored in view-space points; scale context so they align
            // with the downscaled snapshot size.
            ctx.saveGState()
            ctx.scaleBy(x: scale, y: scale)
            for s in strokes { paintStroke(s, in: ctx) }
            if let cur = current { paintStroke(cur, in: ctx) }
            ctx.restoreGState()
        }
    }

    /// Colors used on each finished brush stroke, oldest first — up to recent cap.
    var chronologicalStrokeColors: [UIColor] {
        finishedStrokeColors
    }

    override func draw(_ rect: CGRect) {
        guard let ctx = UIGraphicsGetCurrentContext() else { return }
        // Draw baked historical strokes first (single image draw, very cheap).
        if let baked = bakedLayer {
            baked.draw(in: bounds)
        }
        // Draw live (undoable) strokes + active stroke on top.
        for s in strokes { paintStroke(s, in: ctx) }
        if let cur = current { paintStroke(cur, in: ctx) }
    }
}

private extension Comparable {
    func clamped(to range: ClosedRange<Self>) -> Self {
        min(max(self, range.lowerBound), range.upperBound)
    }
}
