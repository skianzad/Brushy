import AVFoundation

/// Low-volume looping background music for the whole app (foreground).
enum MagicBrushyBackgroundMusic {

    private static var player: AVAudioPlayer?
    private static var didAttemptStart = false

    /// Normal loop level (mascot speech ducks lower).
    private static let defaultPlaybackVolume: Float = 0.14
    private static let duckedDuringSpeechVolume: Float = 0.035

    /// Starts the bundled track once; safe to call multiple times.
    @MainActor
    static func startIfNeeded() {
        guard !didAttemptStart else { return }
        didAttemptStart = true
        guard let url = Bundle.main.url(forResource: "MagicBrushyBackgroundTrack", withExtension: "mp3") else {
            didAttemptStart = false
            return
        }
        do {
            let session = AVAudioSession.sharedInstance()
            try session.setCategory(.playback, mode: .default, options: [.mixWithOthers])
            try session.setActive(true)

            let p = try AVAudioPlayer(contentsOf: url)
            p.numberOfLoops = -1
            p.volume = defaultPlaybackVolume
            p.prepareToPlay()
            guard p.play() else {
                didAttemptStart = false
                return
            }
            player = p

            NotificationCenter.default.addObserver(
                forName: AVAudioSession.routeChangeNotification,
                object: nil,
                queue: .main
            ) { _ in
                Task { @MainActor in
                    guard let pl = player, !pl.isPlaying else { return }
                    pl.play()
                }
            }

            NotificationCenter.default.addObserver(
                forName: AVAudioSession.interruptionNotification,
                object: session,
                queue: .main
            ) { notification in
                guard let info = notification.userInfo,
                      let typeVal = info[AVAudioSessionInterruptionTypeKey] as? UInt,
                      let type = AVAudioSession.InterruptionType(rawValue: typeVal)
                else { return }
                switch type {
                case .began:
                    player?.pause()
                case .ended:
                    let shouldResume = (info[AVAudioSessionInterruptionOptionKey] as? UInt).map {
                        AVAudioSession.InterruptionOptions(rawValue: $0).contains(.shouldResume)
                    } ?? true
                    if shouldResume { player?.play() }
                @unknown default:
                    break
                }
            }
        } catch {
            didAttemptStart = false
        }
    }

    @MainActor
    static func pause() {
        player?.pause()
    }

    @MainActor
    static func resumeIfNeeded() {
        guard player != nil else {
            startIfNeeded()
            return
        }
        player?.play()
    }

    /// Lowers music while the mascot / coach voice plays.
    @MainActor
    static func duckForMascotSpeech() {
        player?.setVolume(duckedDuringSpeechVolume, fadeDuration: 0.22)
    }

    @MainActor
    static func restoreVolumeAfterMascotSpeech() {
        player?.setVolume(defaultPlaybackVolume, fadeDuration: 0.38)
    }
}
