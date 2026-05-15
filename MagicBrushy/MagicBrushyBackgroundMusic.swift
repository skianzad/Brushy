import AVFoundation

/// Low-volume looping background music for the whole app (foreground).
enum MagicBrushyBackgroundMusic {

    private static var player: AVAudioPlayer?
    private static var didAttemptStart = false
    /// When true, `resumeIfNeeded()` is a no-op so scene-active / other callers do not restart music during coach mute.
    private static var coachMuteSilencesMusic = false

    /// Normal loop level (mascot speech ducks lower).
    private static let defaultPlaybackVolume: Float = 0.084
    private static let duckedDuringSpeechVolume: Float = 0.021

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
                    guard !coachMuteSilencesMusic else { return }
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
                    if shouldResume {
                        Task { @MainActor in
                            guard !coachMuteSilencesMusic else { return }
                            player?.play()
                        }
                    }
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
        guard !coachMuteSilencesMusic else { return }
        guard player != nil else {
            startIfNeeded()
            return
        }
        player?.play()
    }

    /// Pauses loop while the user has muted coach feedback (speaker); cleared by `resumeAfterCoachMuteSilence`.
    @MainActor
    static func pauseForCoachMuteSilence() {
        coachMuteSilencesMusic = true
        pause()
    }

    /// Call when coach mute ends (user or timer) so music can play again.
    @MainActor
    static func resumeAfterCoachMuteSilence() {
        coachMuteSilencesMusic = false
        resumeIfNeeded()
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
