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

    static let primaryOrange = UIColor(red: 1, green: 137 / 255, blue: 3 / 255, alpha: 1)
    static let primaryOrangeBorder = UIColor(red: 220 / 255, green: 103 / 255, blue: 39 / 255, alpha: 1)
    static let actionBlue = UIColor(red: 60 / 255, green: 152 / 255, blue: 239 / 255, alpha: 1)
    static let actionBlueBorder = UIColor(red: 32 / 255, green: 109 / 255, blue: 180 / 255, alpha: 1)

    static let skyBlue = UIColor(red: 160 / 255, green: 232 / 255, blue: 251 / 255, alpha: 1)
    static let canvasBorder = UIColor(red: 0, green: 98 / 255, blue: 1, alpha: 1)
    static let canvasFill = UIColor.white

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
