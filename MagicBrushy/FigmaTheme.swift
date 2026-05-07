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

    static let primaryOrange = UIColor(red: 1, green: 137 / 255, blue: 3 / 255, alpha: 1)
    static let primaryOrangeBorder = UIColor(red: 220 / 255, green: 103 / 255, blue: 39 / 255, alpha: 1)
    static let actionBlue = UIColor(red: 60 / 255, green: 152 / 255, blue: 239 / 255, alpha: 1)
    static let actionBlueBorder = UIColor(red: 32 / 255, green: 109 / 255, blue: 180 / 255, alpha: 1)

    static let skyBlue = UIColor(red: 160 / 255, green: 232 / 255, blue: 251 / 255, alpha: 1)
    static let canvasBorder = UIColor(red: 0, green: 98 / 255, blue: 1, alpha: 1)
    static let canvasFill = UIColor.white

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
