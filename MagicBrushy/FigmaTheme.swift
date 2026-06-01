import UIKit

/// Colors and typography distilled from the MagicBrushy Figma file (Final page).
enum FigmaTheme {

    static let creamText = UIColor(red: 1, green: 249 / 255, blue: 245 / 255, alpha: 1)
    static let titleStroke = UIColor(red: 1, green: 137 / 255, blue: 3 / 255, alpha: 1)
    static let cardShadow = UIColor(red: 163 / 255, green: 70 / 255, blue: 70 / 255, alpha: 1)

    static let animalsAccent = UIColor(red: 218 / 255, green: 31 / 255, blue: 1, alpha: 1)
    static let oceanAccent = UIColor(red: 11 / 255, green: 178 / 255, blue: 1, alpha: 1)
    static let foodAccent = UIColor(red: 1, green: 134 / 255, blue: 12 / 255, alpha: 1)
    static let magicAccent = UIColor(red: 0, green: 186 / 255, blue: 56 / 255, alpha: 1)

    /// Extra home tiles (distinct from the four original Figma swatches).
    static let dinosaursAccent = UIColor(red: 34 / 255, green: 139 / 255, blue: 34 / 255, alpha: 1)
    static let fallAccent = UIColor(red: 198 / 255, green: 93 / 255, blue: 24 / 255, alpha: 1)
    static let musicAccent = UIColor(red: 175 / 255, green: 82 / 255, blue: 222 / 255, alpha: 1)
    static let schoolAccent = UIColor(red: 66 / 255, green: 133 / 255, blue: 244 / 255, alpha: 1)
    static let famousArtAccent = UIColor(red: 138 / 255, green: 43 / 255, blue: 226 / 255, alpha: 1)
    /// Kept for older call sites; prefer `magicAccent`.
    static let fantasyAccent = magicAccent
    static let funStuffAccent = UIColor(red: 255 / 255, green: 149 / 255, blue: 0, alpha: 1)
    static let natureAccent = UIColor(red: 52 / 255, green: 120 / 255, blue: 72 / 255, alpha: 1)
    static let roomsScenesAccent = UIColor(red: 169 / 255, green: 113 / 255, blue: 66 / 255, alpha: 1)
    static let sportsAccent = UIColor(red: 10 / 255, green: 132 / 255, blue: 255 / 255, alpha: 1)
    static let vehiclesAccent = UIColor(red: 97 / 255, green: 97 / 255, blue: 97 / 255, alpha: 1)
    static let winterSportsAccent = UIColor(red: 88 / 255, green: 86 / 255, blue: 214 / 255, alpha: 1)
    static let historyCultureAccent = UIColor(red: 139 / 255, green: 90 / 255, blue: 43 / 255, alpha: 1)
    static let landmarksAccent = UIColor(red: 46 / 255, green: 125 / 255, blue: 168 / 255, alpha: 1)

    /// App icon + orange chrome buttons — Figma `122:593` (`#FF8903`).
    static let primaryOrange = UIColor(red: 1, green: 137 / 255, blue: 3 / 255, alpha: 1)
    static let primaryOrangeBorder = UIColor(red: 220 / 255, green: 103 / 255, blue: 39 / 255, alpha: 1)
    static let actionBlue = Brand.skyBlue
    static let actionBlueBorder = UIColor(red: 24 / 255, green: 110 / 255, blue: 200 / 255, alpha: 1)

    /// Home mode picker — softer mint (less neon than legacy Figma export).
    static let freeDrawModeFill = UIColor(red: 198 / 255, green: 1, blue: 228 / 255, alpha: 1)
    static let freeDrawModeBorder = UIColor(red: 48 / 255, green: 168 / 255, blue: 108 / 255, alpha: 1)
    /// Home mode picker — Figma `122:989` Coloring card.
    static let coloringModeFill = UIColor(red: 102 / 255, green: 222 / 255, blue: 1, alpha: 1)
    static let coloringModeBorder = UIColor(red: 1 / 255, green: 174 / 255, blue: 1, alpha: 1)

    static let skyBlue = UIColor(red: 160 / 255, green: 232 / 255, blue: 251 / 255, alpha: 1)

    /// Product palette (Tier 1–3) — crayons, canvas, chrome.
    enum Brand {
        static let skyBlue = UIColor(red: 30 / 255, green: 144 / 255, blue: 255 / 255, alpha: 1)           // #1E90FF
        /// Light cyan wax — clearly lighter than `skyBlue` / royal blue.
        static let lightSkyBlue = UIColor(red: 125 / 255, green: 211 / 255, blue: 252 / 255, alpha: 1)      // #7DD3FC
        static let royalBlue = UIColor(red: 0 / 255, green: 82 / 255, blue: 204 / 255, alpha: 1)           // #0052CC
        static let successGreen = UIColor(red: 60 / 255, green: 179 / 255, blue: 113 / 255, alpha: 1)    // #3CB371
        static let rewardYellow = UIColor(red: 1, green: 215 / 255, blue: 0, alpha: 1)                    // #FFD700
        static let warmWhite = UIColor(red: 1, green: 253 / 255, blue: 245 / 255, alpha: 1)              // #FFFDF5
        static let softBlack = UIColor(red: 44 / 255, green: 44 / 255, blue: 42 / 255, alpha: 1)         // #2C2C2A
        static let playOrange = UIColor(red: 1, green: 140 / 255, blue: 0, alpha: 1)                     // #FF8C00
        static let imaginationPurple = UIColor(red: 218 / 255, green: 112 / 255, blue: 214 / 255, alpha: 1) // #DA70D6
        static let warningRed = UIColor(red: 1, green: 79 / 255, blue: 79 / 255, alpha: 1)               // #FF4F4F
        static let mascotPink = UIColor(red: 1, green: 105 / 255, blue: 180 / 255, alpha: 1)             // #FF69B4
    }

    /// Bootstrap / download screen (Figma export).
    static let bootstrapSky = UIColor(red: 0.627, green: 0.91, blue: 0.984, alpha: 1)
    static let bootstrapProgressBorder = UIColor(red: 0.002, green: 0.684, blue: 1, alpha: 1)
    static let bootstrapProgressTrack = UIColor(red: 0.4, green: 0.87, blue: 1, alpha: 1)
    static let canvasBorder = UIColor(red: 0, green: 98 / 255, blue: 1, alpha: 1)
    static let canvasFill = Brand.warmWhite

    /// Home category grid panel (Figma wood fill behind tiles).
    static let categoryPanelWoodFallback = UIColor(red: 0.35, green: 0.72, blue: 0.95, alpha: 1)

    /// Browse grid (category chips + soft page background), inspired by coastal coloring sites.
    static let coastBackground = UIColor(red: 186 / 255, green: 228 / 255, blue: 248 / 255, alpha: 1)
    static let coastTitle = UIColor(red: 12 / 255, green: 58 / 255, blue: 118 / 255, alpha: 1)
    static let coastChip = UIColor(red: 18 / 255, green: 72 / 255, blue: 138 / 255, alpha: 1)
    static let coastChipSelected = UIColor(red: 8 / 255, green: 48 / 255, blue: 98 / 255, alpha: 1)

    static func titleFont(size: CGFloat) -> UIFont {
        let base = UIFont.systemFont(ofSize: size, weight: .heavy)
        if let d = base.fontDescriptor.withDesign(.rounded) {
            return UIFont(descriptor: d, size: size)
        }
        return base
    }

    static func bodyFont(size: CGFloat, weight: UIFont.Weight = .semibold) -> UIFont {
        let base = UIFont.systemFont(ofSize: size, weight: weight)
        if let d = base.fontDescriptor.withDesign(.rounded) {
            return UIFont(descriptor: d, size: size)
        }
        return base
    }

    static func applyCardShadow(to layer: CALayer, path: CGPath? = nil) {
        layer.shadowColor = cardShadow.cgColor
        layer.shadowOpacity = 1
        layer.shadowRadius = 6
        layer.shadowOffset = .zero
        layer.shadowPath = path
    }

    /// Softer elevation for browse tiles and paper sheets.
    static func applySoftCardShadow(to layer: CALayer) {
        layer.shadowColor = UIColor(red: 12 / 255, green: 58 / 255, blue: 118 / 255, alpha: 1).cgColor
        layer.shadowOpacity = 0.14
        layer.shadowRadius = 10
        layer.shadowOffset = CGSize(width: 0, height: 4)
    }

    /// Category browser + free-draw shelf.
    enum BrowseShelf {
        static let cardFill = Brand.warmWhite
        static let cardBorder = UIColor(red: 12 / 255, green: 58 / 255, blue: 118 / 255, alpha: 0.12)
        static let cardImageWell = UIColor(red: 245 / 255, green: 250 / 255, blue: 1, alpha: 1)
        static let cardTitle = coastTitle
        static let newDrawingAccent = freeDrawModeBorder
    }
}

// MARK: - Top chrome (iPhone vs iPad)

enum MagicBrushyChromeMetrics {

    static func isPhone(_ traitCollection: UITraitCollection) -> Bool {
        traitCollection.userInterfaceIdiom == .phone
    }

    static func chromeButtonSide(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 38 : 52
    }

    static func chromeSymbolPointSize(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 16 : 20
    }

    static func chromeCornerRadius(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 11 : 14
    }

    static func chromeBorderWidth(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 3 : 4
    }

    static let navChromeContentInsets = UIEdgeInsets(top: 6, left: 6, bottom: 6, right: 6)

    static func chromeNavHomeImage() -> UIImage? {
        UIImage(named: "ChromeNavHome")?.withRenderingMode(.alwaysOriginal)
    }

    static func chromeNavSettingsImage() -> UIImage? {
        UIImage(named: "ChromeNavSettings")?.withRenderingMode(.alwaysOriginal)
    }

    /// Orange chrome for home / settings; icon scaled to sit inside the square like camera / undo.
    static func applyHomeNavChrome(
        to button: UIButton,
        image: UIImage?,
        traitCollection: UITraitCollection
    ) {
        let corner = chromeCornerRadius(traitCollection)
        let borderW = chromeBorderWidth(traitCollection)
        let pad = navChromeContentInsets

        button.backgroundColor = .clear
        button.layer.cornerRadius = corner
        button.layer.borderWidth = 0
        button.clipsToBounds = false
        button.layer.shadowColor = UIColor.black.cgColor
        button.layer.shadowOpacity = 0.18
        button.layer.shadowRadius = 4
        button.layer.shadowOffset = CGSize(width: 0, height: 2)
        if #available(iOS 13.0, *) {
            button.layer.cornerCurve = .continuous
        }

        var cfg = button.configuration ?? .plain()
        cfg.image = scaledNavChromeImage(image, traitCollection: traitCollection)
        cfg.baseForegroundColor = .white
        cfg.background.backgroundColor = FigmaTheme.primaryOrange
        cfg.background.strokeColor = FigmaTheme.primaryOrangeBorder
        cfg.background.strokeWidth = borderW
        cfg.background.cornerRadius = corner
        cfg.cornerStyle = .fixed
        cfg.contentInsets = NSDirectionalEdgeInsets(
            top: pad.top,
            leading: pad.left,
            bottom: pad.bottom,
            trailing: pad.right
        )
        button.configuration = cfg
        button.setImage(nil, for: .normal)
        button.contentEdgeInsets = .zero
    }

    private static func scaledNavChromeImage(_ image: UIImage?, traitCollection: UITraitCollection) -> UIImage? {
        guard let image else { return nil }
        let side = chromeButtonSide(traitCollection)
        let pad = navChromeContentInsets
        let innerSide = max(14, side - pad.top - pad.bottom)
        return image.scaledNavChromeIcon(to: innerSide)?.withRenderingMode(.alwaysOriginal)
    }

    /// Rounded-square chrome shared by settings, camera, home, undo, and tool toggles.
    static func applySquareChrome(
        to button: UIButton,
        fill: UIColor,
        border: UIColor,
        traitCollection: UITraitCollection,
        contentInsets: UIEdgeInsets = navChromeContentInsets
    ) {
        button.viewWithTag(910_190)?.removeFromSuperview()

        let corner = chromeCornerRadius(traitCollection)
        let borderW = chromeBorderWidth(traitCollection)

        button.backgroundColor = fill
        button.layer.cornerRadius = corner
        button.layer.borderWidth = borderW
        button.layer.borderColor = border.cgColor
        button.tintColor = .white
        button.contentEdgeInsets = contentInsets
        button.clipsToBounds = false
        button.layer.shadowColor = UIColor.black.cgColor
        button.layer.shadowOpacity = 0.18
        button.layer.shadowRadius = 4
        button.layer.shadowOffset = CGSize(width: 0, height: 2)
        if #available(iOS 13.0, *) {
            button.layer.cornerCurve = .continuous
        }

        // `UIButton.Configuration` draws its own background — sync it so home/settings match camera.
        if var cfg = button.configuration {
            cfg.baseForegroundColor = .white
            cfg.background.backgroundColor = fill
            cfg.background.strokeColor = border
            cfg.background.strokeWidth = borderW
            cfg.background.cornerRadius = corner
            cfg.cornerStyle = .fixed
            cfg.contentInsets = NSDirectionalEdgeInsets(
                top: contentInsets.top,
                leading: contentInsets.left,
                bottom: contentInsets.bottom,
                trailing: contentInsets.right
            )
            button.configuration = cfg
        }
    }

    static let diamondStrokeSizeDelta: CGFloat = 5.04
    static let diamondBackFillColor = UIColor(red: 1, green: 0.539, blue: 0.012, alpha: 1)

    static func diamondBackSide(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 64 : 90.9
    }

    /// Matches `HomeViewController` back placement on the safe area.
    static let backButtonLeadingInset: CGFloat = 12
    static let backButtonTopInset: CGFloat = 4
    static let settingsTrailingInset: CGFloat = 16

    /// Leading space through the rotated diamond corners (inset + visual width).
    static func diamondBackOccupiedLeadingWidth(_ traitCollection: UITraitCollection) -> CGFloat {
        let side = diamondBackSide(traitCollection)
        return backButtonLeadingInset + side * CGFloat(2).squareRoot()
    }

    static func diamondSquareSide(for backSide: CGFloat) -> CGFloat {
        backSide / 2.0.squareRoot()
    }

    static func diamondChevronPointSize(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 18 : 26
    }

    static func unlockMinHeight(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 36 : 44
    }

    static func unlockTitleFontSize(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 13 : 15
    }

    static func unlockSymbolPointSize(_ traitCollection: UITraitCollection) -> CGFloat {
        isPhone(traitCollection) ? 14 : 17
    }

    static func unlockContentInsets(_ traitCollection: UITraitCollection) -> NSDirectionalEdgeInsets {
        isPhone(traitCollection)
            ? NSDirectionalEdgeInsets(top: 6, leading: 10, bottom: 6, trailing: 10)
            : NSDirectionalEdgeInsets(top: 10, leading: 16, bottom: 10, trailing: 16)
    }
}

// MARK: - Brushi mascot (mode picker, home, coloring)

enum BrushiMascotLayout {

    static let mascotScale: CGFloat = 1.25
    /// iPhone home / mode-picker — larger than the legacy compact rail size.
    static let homePhoneMascotMultiplier: CGFloat = 1.58
    /// iPad home / mode-picker: fill the mascot column (≈2× the fixed rail width).
    static let homePadMascotMultiplier: CGFloat = 2.0
    /// Extra scale for Brushi above the crayon rail on the coloring screen.
    static let coloringRailMascotMultiplier: CGFloat = 1.5
    /// Applied on the coloring screen so the crayon rail can show a partial 5th swatch.
    static let coloringMascotViewportScale: CGFloat = 0.95
    /// Coloring-screen mascot display scale (95% of the rail-fit size).
    static let coloringMascotSizeScale: CGFloat = 0.95
    // `MascotStateSleepy` artwork used to need a smaller visual scale (609/742) when the PNG filled more of its square.
    // static let coloringSleepyVisualScale: CGFloat = 609.0 / 742.0
    private static let maxHeightBase: CGFloat = 300

    /// Coloring right-rail width (also drives mascot size on home screens).
    static func rightRailWidth(for traitCollection: UITraitCollection) -> CGFloat {
        MagicBrushyChromeMetrics.isPhone(traitCollection) ? 150 : 210
    }

    static func layoutWidth(for traitCollection: UITraitCollection) -> CGFloat {
        rightRailWidth(for: traitCollection) * mascotScale
    }

    static func maxLayoutHeight(for traitCollection: UITraitCollection) -> CGFloat {
        maxHeightBase * mascotScale
    }

    /// iPhone home screens: enlarged fixed size. iPad: use column fill in layout (see `homePadMascotMultiplier`).
    static func homeDisplaySize(for traitCollection: UITraitCollection, image: UIImage?) -> CGSize {
        let mult = MagicBrushyChromeMetrics.isPhone(traitCollection)
            ? homePhoneMascotMultiplier
            : homePadMascotMultiplier
        let w = layoutWidth(for: traitCollection) * mult
        let aspect = (image?.size.height ?? 1) / max(image?.size.width ?? 1, 1)
        let h = min(w * aspect, maxLayoutHeight(for: traitCollection) * mult)
        return CGSize(width: w, height: h)
    }

    /// Width + height for the mascot `UIImageView` (aspect-fit, capped).
    static func displaySize(for traitCollection: UITraitCollection, image: UIImage?) -> CGSize {
        let w = layoutWidth(for: traitCollection)
        let aspect = (image?.size.height ?? 1) / max(image?.size.width ?? 1, 1)
        let h = min(w * aspect, maxLayoutHeight(for: traitCollection))
        return CGSize(width: w, height: h)
    }

    /// Mascot atop the crayon palette on `ColoringViewController` (1.5× base, viewport + size scales).
    static func coloringRailDisplaySize(for traitCollection: UITraitCollection, image: UIImage?) -> CGSize {
        let base = displaySize(for: traitCollection, image: image)
        let scale = coloringRailMascotMultiplier * coloringMascotViewportScale * coloringMascotSizeScale
        let w = base.width * scale
        let h = min(base.height * scale, maxLayoutHeight(for: traitCollection) * scale)
        return CGSize(width: w, height: h)
    }
}

private extension UIImage {
    /// Scale so the larger dimension fits `maxSide` (points); keeps icons inside nav chrome squares.
    func scaledNavChromeIcon(to maxSide: CGFloat) -> UIImage? {
        let maxDim = max(size.width, size.height)
        guard maxDim > 0.5, maxSide > 0.5 else { return self }
        guard maxDim > maxSide else { return self }
        let scale = maxSide / maxDim
        let newSize = CGSize(width: size.width * scale, height: size.height * scale)
        guard newSize.width > 1, newSize.height > 1 else { return self }
        let format = UIGraphicsImageRendererFormat()
        format.scale = UIScreen.main.scale
        format.opaque = false
        return UIGraphicsImageRenderer(size: newSize, format: format).image { _ in
            draw(in: CGRect(origin: .zero, size: newSize))
        }
    }
}
