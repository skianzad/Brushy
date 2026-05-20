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
    static let famousArtAccent = UIColor(red: 138 / 255, green: 43 / 255, blue: 226 / 255, alpha: 1)
    static let fantasyAccent = UIColor(red: 147 / 255, green: 112 / 255, blue: 219 / 255, alpha: 1)
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
    static let actionBlue = UIColor(red: 60 / 255, green: 152 / 255, blue: 239 / 255, alpha: 1)
    static let actionBlueBorder = UIColor(red: 32 / 255, green: 109 / 255, blue: 180 / 255, alpha: 1)

    /// Home mode picker — Figma `122:824` Free Draw card.
    static let freeDrawModeFill = UIColor(red: 153 / 255, green: 1, blue: 102 / 255, alpha: 1)
    static let freeDrawModeBorder = UIColor(red: 36 / 255, green: 160 / 255, blue: 2 / 255, alpha: 1)
    /// Home mode picker — Figma `122:989` Coloring card.
    static let coloringModeFill = UIColor(red: 102 / 255, green: 222 / 255, blue: 1, alpha: 1)
    static let coloringModeBorder = UIColor(red: 1 / 255, green: 174 / 255, blue: 1, alpha: 1)

    static let skyBlue = UIColor(red: 160 / 255, green: 232 / 255, blue: 251 / 255, alpha: 1)

    /// Bootstrap / download screen (Figma export).
    static let bootstrapSky = UIColor(red: 0.627, green: 0.91, blue: 0.984, alpha: 1)
    static let bootstrapProgressBorder = UIColor(red: 0.002, green: 0.684, blue: 1, alpha: 1)
    static let bootstrapProgressTrack = UIColor(red: 0.4, green: 0.87, blue: 1, alpha: 1)
    static let canvasBorder = UIColor(red: 0, green: 98 / 255, blue: 1, alpha: 1)
    static let canvasFill = UIColor.white

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

    /// Rounded-square chrome shared by settings, camera, home, undo, and tool toggles.
    static func applySquareChrome(
        to button: UIButton,
        fill: UIColor,
        border: UIColor,
        traitCollection: UITraitCollection,
        contentInsets: UIEdgeInsets = navChromeContentInsets
    ) {
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
    /// iPad home / mode-picker: fill the mascot column (≈2× the fixed rail width).
    static let homePadMascotMultiplier: CGFloat = 2.0
    /// Extra scale for Brushi above the crayon rail on the coloring screen.
    static let coloringRailMascotMultiplier: CGFloat = 1.5
    /// Applied on the coloring screen so the crayon rail can show a partial 5th swatch.
    static let coloringMascotViewportScale: CGFloat = 0.95
    /// `MascotStateSleepy` artwork fills more of its square — scale the image, not the layout slot (keeps crayons/tools from jumping).
    static let coloringSleepyVisualScale: CGFloat = 609.0 / 742.0
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

    /// iPhone home screens: compact fixed size. iPad: use column fill in layout (see `homePadMascotMultiplier`).
    static func homeDisplaySize(for traitCollection: UITraitCollection, image: UIImage?) -> CGSize {
        let mult = MagicBrushyChromeMetrics.isPhone(traitCollection) ? 1.0 : homePadMascotMultiplier
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

    /// Mascot atop the crayon palette on `ColoringViewController` (1.5× base, then `coloringMascotViewportScale`).
    static func coloringRailDisplaySize(for traitCollection: UITraitCollection, image: UIImage?) -> CGSize {
        let base = displaySize(for: traitCollection, image: image)
        let scale = coloringRailMascotMultiplier * coloringMascotViewportScale
        let w = base.width * scale
        let h = min(base.height * scale, maxLayoutHeight(for: traitCollection) * scale)
        return CGSize(width: w, height: h)
    }
}
