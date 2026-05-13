import UIKit

/// Root container: landscape-only; on iPad, portrait-shaped windows get black mattes around the scaled landscape canvas.
final class LandscapeLetterboxHostViewController: UIViewController {

    private let embedded: UIViewController

    init(embedded: UIViewController) {
        self.embedded = embedded
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .black
        addChild(embedded)
        view.addSubview(embedded.view)
        embedded.didMove(toParent: self)
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        layoutEmbedded()
    }

    private func layoutEmbedded() {
        let b = view.bounds
        let pad = traitCollection.userInterfaceIdiom == .pad
        let portraitShapedWindow = b.height > b.width

        guard pad, portraitShapedWindow else {
            embedded.view.transform = .identity
            embedded.view.bounds = CGRect(origin: .zero, size: b.size)
            embedded.view.center = CGPoint(x: b.midX, y: b.midY)
            return
        }

        let lw = max(b.width, b.height)
        let lh = min(b.width, b.height)
        let scale = min(b.width / lw, b.height / lh)

        embedded.view.transform = .identity
        embedded.view.bounds = CGRect(x: 0, y: 0, width: lw, height: lh)
        embedded.view.center = CGPoint(x: b.midX, y: b.midY)
        embedded.view.transform = CGAffineTransform(scaleX: scale, y: scale)
    }

    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        [.landscapeLeft, .landscapeRight]
    }

    override var shouldAutorotate: Bool { true }

    override var preferredInterfaceOrientationForPresentation: UIInterfaceOrientation {
        .landscapeLeft
    }

    override var childForStatusBarStyle: UIViewController? { embedded }
    override var childForHomeIndicatorAutoHidden: UIViewController? { embedded }
}
