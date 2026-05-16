import AVFoundation

/// Low-volume looping background music for the whole app (foreground).
enum MagicBrushyBackgroundMusic {

    private static var player: AVAudioPlayer?
    private static var didAttemptStart = false
    /// When true, `resumeIfNeeded()` is a no-op so scene-active / other callers do not restart music during coach mute.
    private static var coachMuteSilencesMusic = false
    /// While mascot/coach TTS is playing, volume tracks the ducked reference × user scale.
    private static var isSpeechDucked = false

    private static let userDefaultsVolumeScaleKey = "MagicBrushy.backgroundMusicVolumeScale"

    /// Reference loop level at user scale 1 (mascot speech ducks lower).
    private static let referenceNormalVolume: Float = 0.084
    private static let referenceDuckedVolume: Float = 0.021

    /// 0…1 multiplier from UserDefaults (default 1). Applied to reference normal / ducked levels.
    static func storedUserVolumeScale() -> Float {
        if let v = UserDefaults.standard.object(forKey: userDefaultsVolumeScaleKey) as? Float {
            return max(0, min(1, v))
        }
        return 1
    }

    /// Persists scale and updates the live player volume (call from main thread, e.g. settings slider).
    @MainActor
    static func setUserVolumeScale(_ scale: Float) {
        let c = max(0, min(1, scale))
        UserDefaults.standard.set(c, forKey: userDefaultsVolumeScaleKey)
        applyCurrentVolumeToPlayer()
    }

    private static func effectiveNormalVolume() -> Float {
        referenceNormalVolume * storedUserVolumeScale()
    }

    private static func effectiveDuckedVolume() -> Float {
        referenceDuckedVolume * storedUserVolumeScale()
    }

    @MainActor
    private static func applyCurrentVolumeToPlayer() {
        guard let p = player else { return }
        let v = isSpeechDucked ? effectiveDuckedVolume() : effectiveNormalVolume()
        p.setVolume(v, fadeDuration: 0.12)
    }

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
            isSpeechDucked = false
            p.volume = effectiveNormalVolume()
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
        applyCurrentVolumeToPlayer()
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
        isSpeechDucked = true
        player?.setVolume(effectiveDuckedVolume(), fadeDuration: 0.22)
    }

    @MainActor
    static func restoreVolumeAfterMascotSpeech() {
        isSpeechDucked = false
        player?.setVolume(effectiveNormalVolume(), fadeDuration: 0.38)
    }
}
