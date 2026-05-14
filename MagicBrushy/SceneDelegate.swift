import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?

    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        guard let windowScene = scene as? UIWindowScene else { return }
        let window = UIWindow(windowScene: windowScene)
        let nav = UINavigationController(rootViewController: HomeViewController())
        let root = LandscapeLetterboxHostViewController(embedded: nav)
        let barAppearance = UINavigationBarAppearance()
        barAppearance.configureWithTransparentBackground()
        barAppearance.shadowColor = .clear
        barAppearance.shadowImage = UIImage()
        nav.navigationBar.standardAppearance = barAppearance
        nav.navigationBar.scrollEdgeAppearance = barAppearance
        nav.navigationBar.compactAppearance = barAppearance
        if #available(iOS 15.0, *) {
            nav.navigationBar.compactScrollEdgeAppearance = barAppearance
        }
        nav.navigationBar.isTranslucent = true
        nav.navigationBar.setBackgroundImage(UIImage(), for: .default)
        nav.navigationBar.shadowImage = UIImage()
        nav.navigationBar.isHidden = true
        window.rootViewController = root
        window.makeKeyAndVisible()
        self.window = window

        Task { @MainActor in
            MagicBrushyBackgroundMusic.startIfNeeded()
        }
    }

    func sceneDidBecomeActive(_ scene: UIScene) {
        Task { @MainActor in
            MagicBrushyBackgroundMusic.resumeIfNeeded()
        }
    }

    func sceneWillResignActive(_ scene: UIScene) {
        Task { @MainActor in
            MagicBrushyBackgroundMusic.pause()
        }
    }
}
