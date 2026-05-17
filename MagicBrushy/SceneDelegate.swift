import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?

    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        guard let windowScene = scene as? UIWindowScene else { return }
        let window = UIWindow(windowScene: windowScene)
        let root = LandscapeLetterboxHostViewController(embedded: BrushiBootstrapViewController())
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
