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
            finishedStrokeColors.append(restored.color)
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

    /// Rect around the **last finished** stroke, expanded by half its width on the left and right and half its height above and below, then grown so width and height are each at least **half the canvas**, clamped to `bounds`. Used to crop the image sent to the VLM.
    func vlmCropRectAroundLastFinishedStroke() -> CGRect? {
        guard let last = strokes.last else { return nil }
        let b = tightBounds(of: last)
        let bw = max(b.width, 8)
        let bh = max(b.height, 8)
        let padX = bw * 0.5
        let padY = bh * 0.5
        let expanded = b.insetBy(dx: -padX, dy: -padY)
        let r = expanded.intersection(bounds)
        guard r.width > 1, r.height > 1 else { return nil }

        let minW = max(8, bounds.width * 0.5)
        let minH = max(8, bounds.height * 0.5)
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

private enum MagicBrushyLineArtCache {
    static let store = NSCache<AnyObject, UIImage>()
}

extension UIImage {
    /// Black line art on a transparent background so it can sit above user paint (including white eraser).
    /// Light paper and bright template fills drop out; dark strokes stay opaque with soft edges for anti-aliasing.
    func magicBrushyLineArtOverlay() -> UIImage {
        guard let cgKey = cgImage else { return self }
        if let cached = MagicBrushyLineArtCache.store.object(forKey: cgKey as AnyObject) {
            return cached
        }

        let format = UIGraphicsImageRendererFormat()
        format.scale = scale
        format.opaque = false
        let sampled = UIGraphicsImageRenderer(size: size, format: format).image { _ in
            draw(in: CGRect(origin: .zero, size: size))
        }
        guard let cg = sampled.cgImage else { return self }

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

        let paperLum: Double = 216
        let inkLum: Double = 88

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
                    if lum >= paperLum {
                        ptr[o] = 0
                        ptr[o + 1] = 0
                        ptr[o + 2] = 0
                        ptr[o + 3] = 0
                    } else if lum <= inkLum {
                        ptr[o] = 0
                        ptr[o + 1] = 0
                        ptr[o + 2] = 0
                        ptr[o + 3] = 255
                    } else {
                        let t = (lum - inkLum) / (paperLum - inkLum)
                        let alpha = UInt8((255 * (1 - t)).rounded())
                        ptr[o] = 0
                        ptr[o + 1] = 0
                        ptr[o + 2] = 0
                        ptr[o + 3] = alpha < 6 ? 0 : alpha
                    }
                }
                o += 4
            }
        }

        guard let outCg = ctx.makeImage() else { return self }
        let out = UIImage(cgImage: outCg, scale: scale, orientation: imageOrientation)
        MagicBrushyLineArtCache.store.setObject(out, forKey: cgKey as AnyObject)
        return out
    }
}
