#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class UIViewController, NSString, NSSet<ObjectType>, NSObject, NSNumber, NSMutableSet<ObjectType>, NSMutableDictionary<KeyType, ObjectType>, NSMutableArray<ObjectType>, NSError, NSDictionary<KeyType, ObjectType>, NSData, NSArray<ObjectType>, LeapUi__SkieSuspendWrappersKt, LeapUiVoiceWidgetMode, LeapUiVoiceWidgetLabels, LeapUiVoiceWidgetColorsCompanion, LeapUiVoiceWidgetColors, LeapUiVoiceAssistantViewControllerKt, LeapUiVoiceAssistantStoreState, LeapUiVoiceAssistantStore, LeapUiVoiceAssistantStateHolder, LeapUiVoiceAssistantState, LeapUiVoiceAssistantIntentStopRecording, LeapUiVoiceAssistantIntentStartRecording, LeapUiVoiceAssistantIntentCancelGeneration, LeapUiUShort, LeapUiULong, LeapUiUInt, LeapUiUByte, LeapUiStatusType, LeapUiSkie_SuspendResultSuccess, LeapUiSkie_SuspendResultError, LeapUiSkie_SuspendResultCanceled, LeapUiSkie_SuspendResult, LeapUiSkie_SuspendHandler, LeapUiSkie_CancellationHandler, LeapUiSkieKotlinStateFlow<T>, LeapUiSkieKotlinSharedFlow<T>, LeapUiSkieKotlinOptionalStateFlow<T>, LeapUiSkieKotlinOptionalSharedFlow<T>, LeapUiSkieKotlinOptionalMutableStateFlow<T>, LeapUiSkieKotlinOptionalMutableSharedFlow<T>, LeapUiSkieKotlinOptionalFlow<T>, LeapUiSkieKotlinMutableStateFlow<T>, LeapUiSkieKotlinMutableSharedFlow<T>, LeapUiSkieKotlinFlow<T>, LeapUiSkieColdFlowIterator<E>, LeapUiShort, LeapUiNumber, LeapUiMutableSet<ObjectType>, LeapUiMutableDictionary<KeyType, ObjectType>, LeapUiLong, LeapUiLeap_sdkGenerationStats, LeapUiKotlinThrowable, LeapUiKotlinRuntimeException, LeapUiKotlinIllegalStateException, LeapUiKotlinFloatIterator, LeapUiKotlinFloatArray, LeapUiKotlinException, LeapUiKotlinEnumCompanion, LeapUiKotlinEnum<E>, LeapUiKotlinCancellationException, LeapUiKotlinArray<T>, LeapUiInt, LeapUiHalftoneEffect_skikoKt, LeapUiFrameTimer, LeapUiFloat, LeapUiDouble, LeapUiByte, LeapUiBoolean, LeapUiBase, LeapUiArrayConversionsKt, LeapUiAppleCoroutineScopeKt, LeapUiAmplitudeSmoother;

@protocol NSCopying, LeapUiVoiceConversation, LeapUiVoiceAudioRecorder, LeapUiVoiceAudioPlayer, LeapUiVoiceAssistantIntent, LeapUiUiModifierElement, LeapUiUiModifier, LeapUiSkie_DispatcherDelegate, LeapUiKotlinx_coroutines_coreStateFlow, LeapUiKotlinx_coroutines_coreSharedFlow, LeapUiKotlinx_coroutines_coreRunnable, LeapUiKotlinx_coroutines_coreMutableStateFlow, LeapUiKotlinx_coroutines_coreMutableSharedFlow, LeapUiKotlinx_coroutines_coreFlowCollector, LeapUiKotlinx_coroutines_coreFlow, LeapUiKotlinx_coroutines_coreCoroutineScope, LeapUiKotlinIterator, LeapUiKotlinCoroutineContextKey, LeapUiKotlinCoroutineContextElement, LeapUiKotlinCoroutineContext, LeapUiKotlinComparable;

// Due to an Obj-C/Swift interop limitation, SKIE cannot generate Swift types with a lambda type argument.
// Example of such type is: A<() -> Unit> where A<T> is a generic class.
// To avoid compilation errors SKIE replaces these type arguments with __SkieLambdaErrorType, resulting in A<__SkieLambdaErrorType>.
// Generated declarations that reference __SkieLambdaErrorType cannot be called in any way and the __SkieLambdaErrorType class cannot be used.
// The original declarations can still be used in the same way as other declarations hidden by SKIE (and with the same limitations as without SKIE).
@interface __SkieLambdaErrorType : NSObject
- (instancetype _Nonnull)init __attribute__((unavailable));
+ (instancetype _Nonnull)new __attribute__((unavailable));
@end

// Due to an Obj-C/Swift interop limitation, SKIE cannot generate Swift code that uses external Obj-C types for which SKIE doesn't know a fully qualified name.
// This problem occurs when custom Cinterop bindings are used because those do not contain the name of the Framework that provides implementation for those binding.
// The name can be configured manually using the SKIE Gradle configuration key 'ClassInterop.CInteropFrameworkName' in the same way as other SKIE features.
// To avoid compilation errors SKIE replaces types with unknown Framework name with __SkieUnknownCInteropFrameworkErrorType.
// Generated declarations that reference __SkieUnknownCInteropFrameworkErrorType cannot be called in any way and the __SkieUnknownCInteropFrameworkErrorType class cannot be used.
@interface __SkieUnknownCInteropFrameworkErrorType : NSObject
- (instancetype _Nonnull)init __attribute__((unavailable));
+ (instancetype _Nonnull)new __attribute__((unavailable));
@end


NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface LeapUiBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface LeapUiBase (LeapUiBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface LeapUiMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface LeapUiMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorLeapUiKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface LeapUiNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface LeapUiByte : LeapUiNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface LeapUiUByte : LeapUiNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface LeapUiShort : LeapUiNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface LeapUiUShort : LeapUiNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface LeapUiInt : LeapUiNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface LeapUiUInt : LeapUiNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface LeapUiLong : LeapUiNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface LeapUiULong : LeapUiNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface LeapUiFloat : LeapUiNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface LeapUiDouble : LeapUiNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface LeapUiBoolean : LeapUiNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * Exponential moving average for smooth amplitude transitions in the orb animation.
 *
 * Apply [update] with each new raw amplitude sample (e.g., RMS from an audio buffer). The returned
 * value is suitable for direct assignment to [VoiceAssistantState.amplitude].
 *
 * Supports asymmetric attack/release: [alpha] controls how quickly the value rises toward a louder
 * input; [releaseAlpha] controls how quickly it falls toward a quieter input. Using a higher
 * [alpha] than [releaseAlpha] produces a fast attack (each syllable registers immediately) and a
 * slower release (the orb contracts visibly between syllables), creating a natural pulsing feel.
 * When [releaseAlpha] is omitted it defaults to [alpha], giving symmetric (standard EMA) behaviour.
 *
 * @param alpha Attack smoothing factor in 0–1. Applied when the raw input is higher than the
 *   current [value]. Higher values track rising inputs more quickly. Defaults to 0.3.
 * @param releaseAlpha Release smoothing factor in 0–1. Applied when the raw input is lower than the
 *   current [value]. Defaults to [alpha] (symmetric EMA).
 *
 * Example (Kotlin — symmetric):
 * ```kotlin
 * val smoother = AmplitudeSmoother(alpha = 0.5f)
 * state = state.copy(amplitude = smoother.update(rawRms))
 * ```
 *
 * Example (Kotlin — asymmetric, fast attack / slower release):
 * ```kotlin
 * val smoother = AmplitudeSmoother(alpha = 0.9f, releaseAlpha = 0.4f)
 * state = state.copy(amplitude = smoother.update(rawRms))
 * ```
 *
 * Example (Swift):
 * ```swift
 * let smoother = AmplitudeSmoother(alpha: 0.9, releaseAlpha: 0.7)
 * holder.update { VoiceAssistantState(mode: $0.mode, amplitude: smoother.update(raw: rawRms)) }
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AmplitudeSmoother")))
@interface LeapUiAmplitudeSmoother : LeapUiBase
@property (readonly) float value __attribute__((swift_name("value")));
- (instancetype)initWithAlpha:(float)alpha releaseAlpha:(float)releaseAlpha __attribute__((swift_name("init(alpha:releaseAlpha:)"))) __attribute__((objc_designated_initializer));

/** Resets [value] to 0. */
- (void)reset __attribute__((swift_name("reset()")));

/**
 * Applies one asymmetric EMA step to [raw] and returns the updated [value].
 *
 * Uses [alpha] when [raw] exceeds [value] (attack) and [releaseAlpha] otherwise (release).
 *
 * Must be called on the main thread if [value] drives a Compose recomposition via
 * [VoiceAssistantStateHolder].
 */
- (float)updateRaw:(float)raw __attribute__((swift_name("update(raw:)")));

/** Current smoothed amplitude value (0–1). */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FrameTimer")))
@interface LeapUiFrameTimer : LeapUiBase
- (instancetype)initWithCallback:(void (^)(void))callback __attribute__((swift_name("init(callback:)"))) __attribute__((objc_designated_initializer));
- (void)start __attribute__((swift_name("start()")));
- (void)stop __attribute__((swift_name("stop()")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol LeapUiKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface LeapUiKotlinEnum<E> : LeapUiBase <LeapUiKotlinComparable>
@property (class, readonly, getter=companion) LeapUiKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Status category of the voice assistant, used to colour-code status text in the UI. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StatusType")))
@interface LeapUiStatusType : LeapUiKotlinEnum<LeapUiStatusType *>
@property (class, readonly) LeapUiStatusType *loading __attribute__((swift_name("loading")));
@property (class, readonly) LeapUiStatusType *ready __attribute__((swift_name("ready")));
@property (class, readonly) LeapUiStatusType *error __attribute__((swift_name("error")));
@property (class, readonly) NSArray<LeapUiStatusType *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));

/** Status category of the voice assistant, used to colour-code status text in the UI. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LeapUiKotlinArray<LeapUiStatusType *> *)values __attribute__((swift_name("values()")));
@end


/** User interaction intents dispatched by [VoiceAssistantWidget] via its `onIntent` callback. */
__attribute__((swift_name("VoiceAssistantIntent")))
@protocol LeapUiVoiceAssistantIntent
@required
@end


/**
 * The user pressed the mic button while in [VoiceWidgetMode.RESPONDING] mode. Always followed
 * immediately by [StartRecording] (interrupt-to-speak pattern).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantIntentCancelGeneration")))
@interface LeapUiVoiceAssistantIntentCancelGeneration : LeapUiBase <LeapUiVoiceAssistantIntent>
@property (class, readonly, getter=shared) LeapUiVoiceAssistantIntentCancelGeneration *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * The user pressed the mic button while in [VoiceWidgetMode.RESPONDING] mode. Always followed
 * immediately by [StartRecording] (interrupt-to-speak pattern).
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cancelGeneration __attribute__((swift_name("init()")));

/**
 * The user pressed the mic button while in [VoiceWidgetMode.RESPONDING] mode. Always followed
 * immediately by [StartRecording] (interrupt-to-speak pattern).
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * The user pressed the mic button while in [VoiceWidgetMode.RESPONDING] mode. Always followed
 * immediately by [StartRecording] (interrupt-to-speak pattern).
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * The user pressed the mic button while in [VoiceWidgetMode.RESPONDING] mode. Always followed
 * immediately by [StartRecording] (interrupt-to-speak pattern).
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** The user pressed the mic button while in [VoiceWidgetMode.IDLE] mode. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantIntentStartRecording")))
@interface LeapUiVoiceAssistantIntentStartRecording : LeapUiBase <LeapUiVoiceAssistantIntent>
@property (class, readonly, getter=shared) LeapUiVoiceAssistantIntentStartRecording *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** The user pressed the mic button while in [VoiceWidgetMode.IDLE] mode. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)startRecording __attribute__((swift_name("init()")));

/** The user pressed the mic button while in [VoiceWidgetMode.IDLE] mode. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** The user pressed the mic button while in [VoiceWidgetMode.IDLE] mode. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** The user pressed the mic button while in [VoiceWidgetMode.IDLE] mode. */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * The user released the mic button after recording. Only dispatched when the press originated
 * from [VoiceWidgetMode.IDLE] or [VoiceWidgetMode.RESPONDING].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantIntentStopRecording")))
@interface LeapUiVoiceAssistantIntentStopRecording : LeapUiBase <LeapUiVoiceAssistantIntent>
@property (class, readonly, getter=shared) LeapUiVoiceAssistantIntentStopRecording *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * The user released the mic button after recording. Only dispatched when the press originated
 * from [VoiceWidgetMode.IDLE] or [VoiceWidgetMode.RESPONDING].
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)stopRecording __attribute__((swift_name("init()")));

/**
 * The user released the mic button after recording. Only dispatched when the press originated
 * from [VoiceWidgetMode.IDLE] or [VoiceWidgetMode.RESPONDING].
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * The user released the mic button after recording. Only dispatched when the press originated
 * from [VoiceWidgetMode.IDLE] or [VoiceWidgetMode.RESPONDING].
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * The user released the mic button after recording. Only dispatched when the press originated
 * from [VoiceWidgetMode.IDLE] or [VoiceWidgetMode.RESPONDING].
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Immutable state snapshot for [VoiceAssistantWidget].
 *
 * Intended for Kotlin/Compose callers. Hold it in a `mutableStateOf` and use `copy()` to produce
 * updated snapshots — Compose will recompose the widget whenever the reference changes.
 *
 * Example:
 * ```kotlin
 * var state by remember { mutableStateOf(VoiceAssistantState()) }
 *
 * LaunchedEffect(Unit) {
 *   state = state.copy(mode = VoiceWidgetMode.LISTENING)
 * }
 *
 * VoiceAssistantWidget(
 *   state = state,
 *   onStartRecording = { state = state.copy(mode = VoiceWidgetMode.LISTENING) },
 *   onStopRecording  = { state = state.copy(mode = VoiceWidgetMode.RESPONDING) },
 *   onCancelGeneration = { state = state.copy(mode = VoiceWidgetMode.IDLE) },
 * )
 * ```
 *
 * For Swift/ObjC callers embedding the widget via a `UIViewController` or `NSViewController`, use
 * [VoiceAssistantStateHolder] instead — hold one instance and assign a new [VoiceAssistantState] to
 * [VoiceAssistantStateHolder.state] to drive recomposition.
 *
 * @param mode Current operational mode of the widget.
 * @param amplitude Normalised audio amplitude in 0.0..1.0; drives orb scale animation.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantState")))
@interface LeapUiVoiceAssistantState : LeapUiBase
@property (readonly) float amplitude __attribute__((swift_name("amplitude")));
@property (readonly) LeapUiVoiceWidgetMode *mode __attribute__((swift_name("mode")));
- (instancetype)initWithMode:(LeapUiVoiceWidgetMode *)mode amplitude:(float)amplitude __attribute__((swift_name("init(mode:amplitude:)"))) __attribute__((objc_designated_initializer));
- (LeapUiVoiceAssistantState *)doCopyMode:(LeapUiVoiceWidgetMode *)mode amplitude:(float)amplitude __attribute__((swift_name("doCopy(mode:amplitude:)")));

/**
 * Immutable state snapshot for [VoiceAssistantWidget].
 *
 * Intended for Kotlin/Compose callers. Hold it in a `mutableStateOf` and use `copy()` to produce
 * updated snapshots — Compose will recompose the widget whenever the reference changes.
 *
 * Example:
 * ```kotlin
 * var state by remember { mutableStateOf(VoiceAssistantState()) }
 *
 * LaunchedEffect(Unit) {
 *   state = state.copy(mode = VoiceWidgetMode.LISTENING)
 * }
 *
 * VoiceAssistantWidget(
 *   state = state,
 *   onStartRecording = { state = state.copy(mode = VoiceWidgetMode.LISTENING) },
 *   onStopRecording  = { state = state.copy(mode = VoiceWidgetMode.RESPONDING) },
 *   onCancelGeneration = { state = state.copy(mode = VoiceWidgetMode.IDLE) },
 * )
 * ```
 *
 * For Swift/ObjC callers embedding the widget via a `UIViewController` or `NSViewController`, use
 * [VoiceAssistantStateHolder] instead — hold one instance and assign a new [VoiceAssistantState] to
 * [VoiceAssistantStateHolder.state] to drive recomposition.
 *
 * @param mode Current operational mode of the widget.
 * @param amplitude Normalised audio amplitude in 0.0..1.0; drives orb scale animation.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Immutable state snapshot for [VoiceAssistantWidget].
 *
 * Intended for Kotlin/Compose callers. Hold it in a `mutableStateOf` and use `copy()` to produce
 * updated snapshots — Compose will recompose the widget whenever the reference changes.
 *
 * Example:
 * ```kotlin
 * var state by remember { mutableStateOf(VoiceAssistantState()) }
 *
 * LaunchedEffect(Unit) {
 *   state = state.copy(mode = VoiceWidgetMode.LISTENING)
 * }
 *
 * VoiceAssistantWidget(
 *   state = state,
 *   onStartRecording = { state = state.copy(mode = VoiceWidgetMode.LISTENING) },
 *   onStopRecording  = { state = state.copy(mode = VoiceWidgetMode.RESPONDING) },
 *   onCancelGeneration = { state = state.copy(mode = VoiceWidgetMode.IDLE) },
 * )
 * ```
 *
 * For Swift/ObjC callers embedding the widget via a `UIViewController` or `NSViewController`, use
 * [VoiceAssistantStateHolder] instead — hold one instance and assign a new [VoiceAssistantState] to
 * [VoiceAssistantStateHolder.state] to drive recomposition.
 *
 * @param mode Current operational mode of the widget.
 * @param amplitude Normalised audio amplitude in 0.0..1.0; drives orb scale animation.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Immutable state snapshot for [VoiceAssistantWidget].
 *
 * Intended for Kotlin/Compose callers. Hold it in a `mutableStateOf` and use `copy()` to produce
 * updated snapshots — Compose will recompose the widget whenever the reference changes.
 *
 * Example:
 * ```kotlin
 * var state by remember { mutableStateOf(VoiceAssistantState()) }
 *
 * LaunchedEffect(Unit) {
 *   state = state.copy(mode = VoiceWidgetMode.LISTENING)
 * }
 *
 * VoiceAssistantWidget(
 *   state = state,
 *   onStartRecording = { state = state.copy(mode = VoiceWidgetMode.LISTENING) },
 *   onStopRecording  = { state = state.copy(mode = VoiceWidgetMode.RESPONDING) },
 *   onCancelGeneration = { state = state.copy(mode = VoiceWidgetMode.IDLE) },
 * )
 * ```
 *
 * For Swift/ObjC callers embedding the widget via a `UIViewController` or `NSViewController`, use
 * [VoiceAssistantStateHolder] instead — hold one instance and assign a new [VoiceAssistantState] to
 * [VoiceAssistantStateHolder.state] to drive recomposition.
 *
 * @param mode Current operational mode of the widget.
 * @param amplitude Normalised audio amplitude in 0.0..1.0; drives orb scale animation.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Observable bridge between Swift/ObjC callers and Compose snapshot state.
 *
 * Hold one instance and assign a new [VoiceAssistantState] to [state] whenever mode or amplitude
 * changes — Compose observes the assignment and recomposes the widget automatically. The view
 * controller does not need to be recreated.
 *
 * **Thread safety:** [state] must be assigned on the **main thread**. Compose snapshot state
 * batches writes but expects UI-driving mutations on the main thread; mutations from a background
 * thread (e.g., an audio buffer callback) will produce undefined behaviour.
 *
 * Example (Swift — `UIViewControllerRepresentable`):
 * ```swift
 * struct VoiceAssistantView: UIViewControllerRepresentable {
 *   // Plain stored property — SwiftUI does not need to observe VoiceAssistantStateHolder;
 *   // Compose observes it directly via snapshot state.
 *   let holder = VoiceAssistantStateHolder(initial: VoiceAssistantState(mode: .idle, amplitude: 0))
 *
 *   func makeUIViewController(context: Context) -> UIViewController {
 *     VoiceAssistantViewControllerKt.VoiceAssistantViewController(
 *       state: holder,
 *       onStartRecording: { holder.state = VoiceAssistantState(mode: .listening, amplitude: 0) },
 *       onStopRecording:  { holder.state = VoiceAssistantState(mode: .responding, amplitude: 0) },
 *       onCancelGeneration: { holder.state = VoiceAssistantState(mode: .idle, amplitude: 0) },
 *       labels: ..., colors: ...)
 *   }
 *   func updateUIViewController(_ vc: UIViewController, context: Context) {}
 * }
 * // Assign a new state from the main thread — triggers Compose recomposition automatically:
 * holder.state = VoiceAssistantState(mode: .listening, amplitude: 0.8)
 * ```
 *
 * For Kotlin/Compose callers, use [VoiceAssistantState] with `mutableStateOf` directly — no holder
 * is needed:
 * ```kotlin
 * var state by remember { mutableStateOf(VoiceAssistantState()) }
 * state = state.copy(mode = VoiceWidgetMode.LISTENING)
 * ```
 *
 * @param initial Starting state; defaults to [VoiceAssistantState] defaults (IDLE, amplitude 0).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantStateHolder")))
@interface LeapUiVoiceAssistantStateHolder : LeapUiBase
@property LeapUiVoiceAssistantState *state __attribute__((swift_name("state")));
- (instancetype)initWithInitial:(LeapUiVoiceAssistantState *)initial __attribute__((swift_name("init(initial:)"))) __attribute__((objc_designated_initializer));

/**
 * Applies [transform] to [state] and assigns the result.
 *
 * Use this to perform partial updates — only the fields changed inside [transform] via
 * [VoiceAssistantState.copy] are modified; the rest are preserved from the current [state].
 *
 * Example (Kotlin):
 * ```kotlin
 * holder.update { it.copy(mode = VoiceWidgetMode.LISTENING) }
 * ```
 *
 * Example (Swift — `doCopy` requires all params in ObjC interop, so use the constructor):
 * ```swift
 * holder.update { VoiceAssistantState(mode: .listening, amplitude: $0.amplitude) }
 * ```
 */
- (void)updateTransform:(LeapUiVoiceAssistantState *(^)(LeapUiVoiceAssistantState *))transform __attribute__((swift_name("update(transform:)")));

/**
 * Current widget state. Assigning a new value triggers Compose recomposition automatically. Must
 * be assigned on the main thread.
 */
@end


/**
 * Centralised state machine and orchestrator for a voice assistant session.
 *
 * Manages the full lifecycle of a push-to-talk interaction:
 * - State transitions: IDLE → LISTENING → RESPONDING → IDLE
 * - Amplitude frame tick for orb animation (via [FrameTimer])
 * - Generation flow: stop recording → call [VoiceConversation.generateResponse] → play audio
 *   (conversation is kept alive for multi-turn context)
 * - Cancellation: cancel generation job, stop recorder, stop player, reset state
 *
 * Platform code instantiates the store with platform-specific [VoiceAudioRecorder] and
 * [VoiceAudioPlayer] implementations, provides a [CoroutineScope] (e.g. `viewModelScope` on Android
 * or a `MainScope()` on Apple), then calls [setConversation] after the model loads.
 *
 * Observe state:
 * - **Kotlin/Compose**: `store.state.collectAsState()` or `store.widgetStateHolder.state`
 * - **Swift**: `for await state in store.state` (SKIE maps `StateFlow` to `AsyncSequence`)
 *
 * Wire to the widget: `onIntent = store::processIntent`
 *
 * @param recorder Platform audio recorder.
 * @param player Platform audio player.
 * @param scope Coroutine scope for launching internal jobs. Must be on the main dispatcher so that
 *   [widgetStateHolder] writes happen on the main thread.
 * @param smoothingAlpha EMA alpha for [AmplitudeSmoother]; higher values = faster tracking.
 * @param playbackTimeoutMs Maximum time in milliseconds to wait for audio playback to finish after
 *   generation completes. 0 (the default) means wait indefinitely. Useful on platforms where
 *   `waitForPlayback()` can hang (e.g. macOS with certain audio configurations).
 * @param ownedScope Optional scope that this store owns and will cancel in [close]. When the store
 *   creates its own scope (e.g. via `makeForApple()`), pass it here so that [close] can cancel it.
 *   When the caller manages the scope lifecycle (e.g. Android `viewModelScope`), leave this `null`.
 * @param interruptToSpeak When `true` (default), pressing during RESPONDING cancels the current
 *   generation and immediately starts a new recording (interrupt-to-speak). When `false`, pressing
 *   during RESPONDING only cancels — the user must press again to start a new recording.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantStore")))
@interface LeapUiVoiceAssistantStore : LeapUiBase
@property (readonly) id<LeapUiKotlinx_coroutines_coreStateFlow> state __attribute__((swift_name("state")));
@property (readonly) LeapUiVoiceAssistantStateHolder *widgetStateHolder __attribute__((swift_name("widgetStateHolder")));
- (instancetype)initWithRecorder:(id<LeapUiVoiceAudioRecorder>)recorder player:(id<LeapUiVoiceAudioPlayer>)player scope:(id<LeapUiKotlinx_coroutines_coreCoroutineScope>)scope smoothingAlpha:(float)smoothingAlpha playbackTimeoutMs:(int64_t)playbackTimeoutMs ownedScope:(id<LeapUiKotlinx_coroutines_coreCoroutineScope> _Nullable)ownedScope interruptToSpeak:(BOOL)interruptToSpeak __attribute__((swift_name("init(recorder:player:scope:smoothingAlpha:playbackTimeoutMs:ownedScope:interruptToSpeak:)"))) __attribute__((objc_designated_initializer));

/**
 * Stops the frame timer, cancels any in-progress jobs, and stops the player. This is a
 * **terminal** operation — after calling this, all public methods are no-ops. Call from
 * `ViewModel.onCleared()` (Android) or `deinit` (Swift). Do **not** call from `onDisappear` if
 * the view model may be reused on a subsequent `onAppear`. If an [ownedScope] was provided at
 * construction, it is cancelled here.
 */
- (void)close __attribute__((swift_name("close()")));

/**
 * Dispatches [intent] from the widget. Wire as `onIntent = store::processIntent` in
 * [VoiceAssistantWidget] or the intent switch block in a SwiftUI `NSViewControllerRepresentable`.
 * No-ops after [close] has been called.
 */
- (void)processIntentIntent:(id<LeapUiVoiceAssistantIntent>)intent __attribute__((swift_name("processIntent(intent:)")));

/**
 * Transitions the store to [StatusType.READY] and stores [conv] for use when the user speaks.
 * Call this after the model finishes loading. No-ops after [close] has been called.
 */
- (void)setConversationConv:(id<LeapUiVoiceConversation>)conv __attribute__((swift_name("setConversation(conv:)")));

/** Transitions the store to [StatusType.ERROR] with [message] as the status text. */
- (void)setModelErrorMessage:(NSString *)message __attribute__((swift_name("setModelError(message:)")));

/**
 * Updates the status text during model download / load. [fraction] is in 0..1 (unused in the
 * current UI but available for progress bars); [message] is displayed as the status text.
 */
- (void)setModelProgressFraction:(float)fraction message:(NSString *)message __attribute__((swift_name("setModelProgress(fraction:message:)")));

/** Full observable store state. Collect as `StateFlow` (Kotlin) or `AsyncSequence` (Swift). */

/**
 * Compose snapshot-state bridge for the widget. Always kept in sync with [state].widgetState.
 * Pass to [VoiceAssistantWidget] (Kotlin) or `VoiceAssistantViewController` /
 * `VoiceAssistantNSViewController` (Swift/ObjC).
 */
@end


/**
 * Full observable state emitted by [VoiceAssistantStore].
 *
 * Observe [VoiceAssistantStore.state] as a `StateFlow` on Kotlin/Compose platforms, or as a Swift
 * `AsyncSequence` via SKIE on Apple platforms.
 *
 * @param widgetState Current [VoiceAssistantState] for the [VoiceAssistantWidget].
 * @param statusText Human-readable status message (loading progress, ready prompt, or error).
 * @param statusType Category of [statusText], used to drive colour-coding in the UI.
 * @param statsText Optional post-generation performance stats string, or `null` if no generation
 *   has completed yet or the model did not report stats.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantStoreState")))
@interface LeapUiVoiceAssistantStoreState : LeapUiBase
@property (readonly) NSString * _Nullable statsText __attribute__((swift_name("statsText")));
@property (readonly) NSString *statusText __attribute__((swift_name("statusText")));
@property (readonly) LeapUiStatusType *statusType __attribute__((swift_name("statusType")));
@property (readonly) LeapUiVoiceAssistantState *widgetState __attribute__((swift_name("widgetState")));
- (instancetype)initWithWidgetState:(LeapUiVoiceAssistantState *)widgetState statusText:(NSString *)statusText statusType:(LeapUiStatusType *)statusType statsText:(NSString * _Nullable)statsText __attribute__((swift_name("init(widgetState:statusText:statusType:statsText:)"))) __attribute__((objc_designated_initializer));
- (LeapUiVoiceAssistantStoreState *)doCopyWidgetState:(LeapUiVoiceAssistantState *)widgetState statusText:(NSString *)statusText statusType:(LeapUiStatusType *)statusType statsText:(NSString * _Nullable)statsText __attribute__((swift_name("doCopy(widgetState:statusText:statusType:statsText:)")));

/**
 * Full observable state emitted by [VoiceAssistantStore].
 *
 * Observe [VoiceAssistantStore.state] as a `StateFlow` on Kotlin/Compose platforms, or as a Swift
 * `AsyncSequence` via SKIE on Apple platforms.
 *
 * @param widgetState Current [VoiceAssistantState] for the [VoiceAssistantWidget].
 * @param statusText Human-readable status message (loading progress, ready prompt, or error).
 * @param statusType Category of [statusText], used to drive colour-coding in the UI.
 * @param statsText Optional post-generation performance stats string, or `null` if no generation
 *   has completed yet or the model did not report stats.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Full observable state emitted by [VoiceAssistantStore].
 *
 * Observe [VoiceAssistantStore.state] as a `StateFlow` on Kotlin/Compose platforms, or as a Swift
 * `AsyncSequence` via SKIE on Apple platforms.
 *
 * @param widgetState Current [VoiceAssistantState] for the [VoiceAssistantWidget].
 * @param statusText Human-readable status message (loading progress, ready prompt, or error).
 * @param statusType Category of [statusText], used to drive colour-coding in the UI.
 * @param statsText Optional post-generation performance stats string, or `null` if no generation
 *   has completed yet or the model did not report stats.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Full observable state emitted by [VoiceAssistantStore].
 *
 * Observe [VoiceAssistantStore.state] as a `StateFlow` on Kotlin/Compose platforms, or as a Swift
 * `AsyncSequence` via SKIE on Apple platforms.
 *
 * @param widgetState Current [VoiceAssistantState] for the [VoiceAssistantWidget].
 * @param statusText Human-readable status message (loading progress, ready prompt, or error).
 * @param statusType Category of [statusText], used to drive colour-coding in the UI.
 * @param statsText Optional post-generation performance stats string, or `null` if no generation
 *   has completed yet or the model did not report stats.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Contract for streaming audio playback in a voice assistant session.
 *
 * Implementations are platform-specific. Typical usage:
 * ```kotlin
 * val player: VoiceAudioPlayer = platformPlayer()
 *
 * // During generation: enqueue each AudioSample chunk as it arrives
 * player.enqueue(response.samples, response.sampleRate)
 *
 * // After generation ends: wait for all audio to finish playing
 * player.waitForPlayback()
 * player.stop()
 * ```
 */
__attribute__((swift_name("VoiceAudioPlayer")))
@protocol LeapUiVoiceAudioPlayer
@required

/**
 * Enqueues [samples] at [sampleRate] Hz for streaming playback.
 *
 * May be called multiple times before playback starts; implementations should buffer and play
 * chunks gaplessly.
 */
- (void)enqueueSamples:(LeapUiKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("enqueue(samples:sampleRate:)")));

/**
 * Stops playback immediately and releases hardware resources.
 *
 * Any pending [waitForPlayback] callers are unblocked. Safe to call from any thread.
 */
- (void)stop __attribute__((swift_name("stop()")));

/**
 * Suspends until all enqueued audio buffers have been played back by the hardware.
 *
 * Returns immediately if no audio is enqueued. Use this before [stop] to avoid cutting off the
 * tail of the audio:
 * ```kotlin
 * if (!cancelled) player.waitForPlayback()
 * player.stop()
 * ```
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)waitForPlaybackWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("waitForPlayback(completionHandler:)")));

/**
 * Real-time RMS amplitude (0–1) of audio currently playing back.
 *
 * Feed this value into [AmplitudeSmoother.update] and assign the result to
 * [VoiceAssistantState.amplitude] for smooth orb animation during playback.
 */
@property (readonly) float amplitude __attribute__((swift_name("amplitude")));
@end


/**
 * Contract for microphone recording in a voice assistant session.
 *
 * Implementations are platform-specific (Android, iOS, macOS, …) but share this interface so that
 * [VoiceAssistantStateHolder] consumers can be written against a stable, platform-agnostic API.
 *
 * Typical usage with [VoiceAssistantStateHolder]:
 * ```kotlin
 * val recorder: VoiceAudioRecorder = platformRecorder()
 *
 * // Start recording (on intent from VoiceAssistantWidget)
 * recorder.start()
 *
 * // 60-fps frame tick: feed smoothed amplitude into the state holder
 * val smoother = AmplitudeSmoother()
 * holder.update { it.copy(amplitude = smoother.update(recorder.amplitude)) }
 *
 * // Stop and retrieve samples
 * val samples = recorder.stop()
 * val sampleRate = recorder.nativeSampleRate
 * ```
 */
__attribute__((swift_name("VoiceAudioRecorder")))
@protocol LeapUiVoiceAudioRecorder
@required

/** Stops recording immediately and discards all captured audio.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)cancelWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("cancel(completionHandler:)")));

/**
 * Starts microphone recording.
 *
 * Returns `true` on success, `false` if the hardware is unavailable or permission is denied. Call
 * [stop] or [cancel] to end the session.
 */
- (BOOL)start __attribute__((swift_name("start()")));

/**
 * Stops recording and returns the captured audio as raw float PCM samples in the range −1..1.
 *
 * The caller is responsible for encoding and sending the samples to the model, e.g.:
 * ```kotlin
 * // Kotlin / Android — encode as WAV before passing to the SDK:
 * val wavBytes = encodePcm16Wav(recorder.stop(), recorder.nativeSampleRate)
 * ChatMessageContent.Audio(wavBytes)
 *
 * // Swift / iOS / macOS — use the LeapSDK extension:
 * ChatMessageContent.fromFloatSamples(recorder.stop(), sampleRate: recorder.nativeSampleRate)
 * ```
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)stopWithCompletionHandler:(void (^)(LeapUiKotlinFloatArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("stop(completionHandler:)")));

/**
 * Real-time RMS amplitude (0–1) of the most recently processed audio buffer.
 *
 * Feed this value into [AmplitudeSmoother.update] and assign the result to
 * [VoiceAssistantState.amplitude] for smooth orb animation during recording.
 */
@property (readonly) float amplitude __attribute__((swift_name("amplitude")));

/**
 * Sample rate (Hz) of the current or most recent recording session. Available after [start] is
 * called.
 */
@property (readonly) int32_t nativeSampleRate __attribute__((swift_name("nativeSampleRate")));
@end


/**
 * Decouples [VoiceAssistantStore] from any specific inference SDK.
 *
 * Implement this interface to integrate any voice model with the store. Each platform provides its
 * own adapter:
 * - **Kotlin (Android/Web)**: Wrap the `leap-sdk` `Conversation.generateResponse` Flow, collect
 *   each response, call [generateResponse]'s `onAudioChunk` for each audio sample, and return
 *   [GenerationStats] from the `Complete` response event.
 * - **Swift (iOS/macOS)**: Implement the `VoiceConversation` protocol. SKIE maps the `suspend`
 *   function to `async throws`, so the Swift implementation iterates the SDK's `AsyncSequence` and
 *   calls `onAudioChunk` for each audio sample.
 *
 * The suspend + callback design is critical for multi-platform conformance: SKIE maps `suspend` to
 * Swift `async`, allowing Swift implementations to conform to this interface as a native protocol
 * without any bridge modules.
 *
 * @see GenerationStats
 * @see VoiceAssistantStore
 */
__attribute__((swift_name("VoiceConversation")))
@protocol LeapUiVoiceConversation
@required

/**
 * Generates a voice response for the given audio input.
 *
 * Suspends until generation is complete. For each audio output chunk, [onAudioChunk] is called
 * (the implementation must not re-enter this interface from within the callback). Returns
 * [GenerationStats] if the model reports them, or `null` otherwise.
 *
 * Implementations should propagate [kotlinx.coroutines.CancellationException] from the underlying
 * flow collection so that the store's generation job cancels cleanly.
 *
 * @param audioSamples Raw float PCM samples in the range −1..1.
 * @param sampleRate Sample rate of [audioSamples] in Hz.
 * @param onAudioChunk Called for each audio response chunk as it arrives. [samples] are float PCM
 *   in −1..1; [sampleRate] is the rate for that chunk.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)generateResponseAudioSamples:(LeapUiKotlinFloatArray *)audioSamples sampleRate:(int32_t)sampleRate onAudioChunk:(void (^)(LeapUiKotlinFloatArray *, LeapUiInt *))onAudioChunk completionHandler:(void (^)(LeapUiLeap_sdkGenerationStats * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("generateResponse(audioSamples:sampleRate:onAudioChunk:completionHandler:)")));

/**
 * Resets the conversation context, returning a fresh [VoiceConversation] ready for the next turn.
 * The original instance should be discarded after calling this.
 */
- (id<LeapUiVoiceConversation>)reset __attribute__((swift_name("reset()")));
@end


/**
 * Color scheme for the voice assistant orb.
 *
 * Default values are matched to `OrbView.swift` (authoritative iOS design reference).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceWidgetColors")))
@interface LeapUiVoiceWidgetColors : LeapUiBase
@property (class, readonly, getter=companion) LeapUiVoiceWidgetColorsCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) uint64_t label __attribute__((swift_name("label")));
@property (readonly) uint64_t listeningPrimary __attribute__((swift_name("listeningPrimary")));
@property (readonly) uint64_t listeningSecondary __attribute__((swift_name("listeningSecondary")));
@property (readonly) uint64_t listeningTertiary __attribute__((swift_name("listeningTertiary")));
@property (readonly) uint64_t respondingPrimary __attribute__((swift_name("respondingPrimary")));
@property (readonly) uint64_t respondingSecondary __attribute__((swift_name("respondingSecondary")));
@property (readonly) uint64_t respondingTertiary __attribute__((swift_name("respondingTertiary")));
- (instancetype)initWithListeningPrimary:(uint64_t)listeningPrimary listeningSecondary:(uint64_t)listeningSecondary listeningTertiary:(uint64_t)listeningTertiary respondingPrimary:(uint64_t)respondingPrimary respondingSecondary:(uint64_t)respondingSecondary respondingTertiary:(uint64_t)respondingTertiary label:(uint64_t)label __attribute__((swift_name("init(listeningPrimary:listeningSecondary:listeningTertiary:respondingPrimary:respondingSecondary:respondingTertiary:label:)"))) __attribute__((objc_designated_initializer));
- (LeapUiVoiceWidgetColors *)doCopyListeningPrimary:(uint64_t)listeningPrimary listeningSecondary:(uint64_t)listeningSecondary listeningTertiary:(uint64_t)listeningTertiary respondingPrimary:(uint64_t)respondingPrimary respondingSecondary:(uint64_t)respondingSecondary respondingTertiary:(uint64_t)respondingTertiary label:(uint64_t)label __attribute__((swift_name("doCopy(listeningPrimary:listeningSecondary:listeningTertiary:respondingPrimary:respondingSecondary:respondingTertiary:label:)")));

/**
 * Color scheme for the voice assistant orb.
 *
 * Default values are matched to `OrbView.swift` (authoritative iOS design reference).
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Color scheme for the voice assistant orb.
 *
 * Default values are matched to `OrbView.swift` (authoritative iOS design reference).
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Color scheme for the voice assistant orb.
 *
 * Default values are matched to `OrbView.swift` (authoritative iOS design reference).
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceWidgetColors.Companion")))
@interface LeapUiVoiceWidgetColorsCompanion : LeapUiBase
@property (class, readonly, getter=shared) LeapUiVoiceWidgetColorsCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LeapUiVoiceWidgetColors *Default __attribute__((swift_name("Default")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/** User-facing strings for the voice widget — status labels and accessibility descriptions. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceWidgetLabels")))
@interface LeapUiVoiceWidgetLabels : LeapUiBase
@property (readonly) NSString *idle __attribute__((swift_name("idle")));
@property (readonly) NSString *listening __attribute__((swift_name("listening")));
@property (readonly) NSString *micCancelDescription __attribute__((swift_name("micCancelDescription")));
@property (readonly) NSString *micStartDescription __attribute__((swift_name("micStartDescription")));
@property (readonly) NSString *micStopDescription __attribute__((swift_name("micStopDescription")));
@property (readonly) NSString *responding __attribute__((swift_name("responding")));
- (instancetype)initWithIdle:(NSString *)idle listening:(NSString *)listening responding:(NSString *)responding micStartDescription:(NSString *)micStartDescription micStopDescription:(NSString *)micStopDescription micCancelDescription:(NSString *)micCancelDescription __attribute__((swift_name("init(idle:listening:responding:micStartDescription:micStopDescription:micCancelDescription:)"))) __attribute__((objc_designated_initializer));
- (LeapUiVoiceWidgetLabels *)doCopyIdle:(NSString *)idle listening:(NSString *)listening responding:(NSString *)responding micStartDescription:(NSString *)micStartDescription micStopDescription:(NSString *)micStopDescription micCancelDescription:(NSString *)micCancelDescription __attribute__((swift_name("doCopy(idle:listening:responding:micStartDescription:micStopDescription:micCancelDescription:)")));

/** User-facing strings for the voice widget — status labels and accessibility descriptions. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** User-facing strings for the voice widget — status labels and accessibility descriptions. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** User-facing strings for the voice widget — status labels and accessibility descriptions. */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** The operational state of the voice assistant widget. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceWidgetMode")))
@interface LeapUiVoiceWidgetMode : LeapUiKotlinEnum<LeapUiVoiceWidgetMode *>
@property (class, readonly) LeapUiVoiceWidgetMode *idle __attribute__((swift_name("idle")));
@property (class, readonly) LeapUiVoiceWidgetMode *listening __attribute__((swift_name("listening")));
@property (class, readonly) LeapUiVoiceWidgetMode *responding __attribute__((swift_name("responding")));
@property (class, readonly) NSArray<LeapUiVoiceWidgetMode *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));

/** The operational state of the voice assistant widget. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LeapUiKotlinArray<LeapUiVoiceWidgetMode *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieColdFlowIterator")))
@interface LeapUiSkieColdFlowIterator<E> : LeapUiBase
- (instancetype)initWithFlow:(id<LeapUiKotlinx_coroutines_coreFlow>)flow __attribute__((swift_name("init(flow:)"))) __attribute__((objc_designated_initializer));
- (void)cancel __attribute__((swift_name("cancel()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)hasNextWithCompletionHandler:(void (^)(LeapUiBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("hasNext(completionHandler:)")));
- (E _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol LeapUiKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinFlow")))
@interface LeapUiSkieKotlinFlow<__covariant T> : LeapUiBase <LeapUiKotlinx_coroutines_coreFlow>
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol LeapUiKotlinx_coroutines_coreSharedFlow <LeapUiKotlinx_coroutines_coreFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol LeapUiKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreMutableSharedFlow")))
@protocol LeapUiKotlinx_coroutines_coreMutableSharedFlow <LeapUiKotlinx_coroutines_coreSharedFlow, LeapUiKotlinx_coroutines_coreFlowCollector>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(id _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@property (readonly) id<LeapUiKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinMutableSharedFlow")))
@interface LeapUiSkieKotlinMutableSharedFlow<T> : LeapUiBase <LeapUiKotlinx_coroutines_coreMutableSharedFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LeapUiKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreMutableSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(T)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(T)value __attribute__((swift_name("tryEmit(value:)")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreStateFlow")))
@protocol LeapUiKotlinx_coroutines_coreStateFlow <LeapUiKotlinx_coroutines_coreSharedFlow>
@required
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreMutableStateFlow")))
@protocol LeapUiKotlinx_coroutines_coreMutableStateFlow <LeapUiKotlinx_coroutines_coreStateFlow, LeapUiKotlinx_coroutines_coreMutableSharedFlow>
@required
- (void)setValue:(id _Nullable)value __attribute__((swift_name("setValue(_:)")));
- (BOOL)compareAndSetExpect:(id _Nullable)expect update:(id _Nullable)update __attribute__((swift_name("compareAndSet(expect:update:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinMutableStateFlow")))
@interface LeapUiSkieKotlinMutableStateFlow<T> : LeapUiBase <LeapUiKotlinx_coroutines_coreMutableStateFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LeapUiKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@property T value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreMutableStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
- (BOOL)compareAndSetExpect:(T)expect update:(T)update __attribute__((swift_name("compareAndSet(expect:update:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(T)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(T)value __attribute__((swift_name("tryEmit(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalFlow")))
@interface LeapUiSkieKotlinOptionalFlow<__covariant T> : LeapUiBase <LeapUiKotlinx_coroutines_coreFlow>
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalMutableSharedFlow")))
@interface LeapUiSkieKotlinOptionalMutableSharedFlow<T> : LeapUiBase <LeapUiKotlinx_coroutines_coreMutableSharedFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LeapUiKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreMutableSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(T _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(T _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalMutableStateFlow")))
@interface LeapUiSkieKotlinOptionalMutableStateFlow<T> : LeapUiBase <LeapUiKotlinx_coroutines_coreMutableStateFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LeapUiKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@property T _Nullable value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreMutableStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
- (BOOL)compareAndSetExpect:(T _Nullable)expect update:(T _Nullable)update __attribute__((swift_name("compareAndSet(expect:update:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(T _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(T _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalSharedFlow")))
@interface LeapUiSkieKotlinOptionalSharedFlow<__covariant T> : LeapUiBase <LeapUiKotlinx_coroutines_coreSharedFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalStateFlow")))
@interface LeapUiSkieKotlinOptionalStateFlow<__covariant T> : LeapUiBase <LeapUiKotlinx_coroutines_coreStateFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) T _Nullable value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinSharedFlow")))
@interface LeapUiSkieKotlinSharedFlow<__covariant T> : LeapUiBase <LeapUiKotlinx_coroutines_coreSharedFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinStateFlow")))
@interface LeapUiSkieKotlinStateFlow<__covariant T> : LeapUiBase <LeapUiKotlinx_coroutines_coreStateFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) T value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LeapUiKotlinx_coroutines_coreStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_CancellationHandler")))
@interface LeapUiSkie_CancellationHandler : LeapUiBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)cancel __attribute__((swift_name("cancel()")));
@end

__attribute__((swift_name("Skie_DispatcherDelegate")))
@protocol LeapUiSkie_DispatcherDelegate
@required
- (void)dispatchBlock:(id<LeapUiKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendHandler")))
@interface LeapUiSkie_SuspendHandler : LeapUiBase
- (instancetype)initWithCancellationHandler:(LeapUiSkie_CancellationHandler *)cancellationHandler dispatcherDelegate:(id<LeapUiSkie_DispatcherDelegate>)dispatcherDelegate onResult:(void (^)(LeapUiSkie_SuspendResult *))onResult __attribute__((swift_name("init(cancellationHandler:dispatcherDelegate:onResult:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Skie_SuspendResult")))
@interface LeapUiSkie_SuspendResult : LeapUiBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendResult.Canceled")))
@interface LeapUiSkie_SuspendResultCanceled : LeapUiSkie_SuspendResult
@property (class, readonly, getter=shared) LeapUiSkie_SuspendResultCanceled *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)canceled __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendResult.Error")))
@interface LeapUiSkie_SuspendResultError : LeapUiSkie_SuspendResult
@property (readonly) NSError *error __attribute__((swift_name("error")));
- (instancetype)initWithError:(NSError *)error __attribute__((swift_name("init(error:)"))) __attribute__((objc_designated_initializer));
- (LeapUiSkie_SuspendResultError *)doCopyError:(NSError *)error __attribute__((swift_name("doCopy(error:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendResult.Success")))
@interface LeapUiSkie_SuspendResultSuccess : LeapUiSkie_SuspendResult
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(id _Nullable)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LeapUiSkie_SuspendResultSuccess *)doCopyValue:(id _Nullable)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AppleCoroutineScopeKt")))
@interface LeapUiAppleCoroutineScopeKt : LeapUiBase

/**
 * Creates a [CoroutineScope] tied to the main dispatcher.
 *
 * Convenience wrapper for Swift callers that avoids referencing the mangled ObjC name of
 * `kotlinx.coroutines.MainScope()`. Used by `VoiceAssistantStore.makeForApple()`.
 */
+ (id<LeapUiKotlinx_coroutines_coreCoroutineScope>)createMainScope __attribute__((swift_name("createMainScope()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArrayConversionsKt")))
@interface LeapUiArrayConversionsKt : LeapUiBase

/** Convert a [FloatArray] to [NSData] (raw IEEE 754 bytes) via a single bulk memcpy. */
+ (NSData *)floatArrayToNSDataArray:(LeapUiKotlinFloatArray *)array __attribute__((swift_name("floatArrayToNSData(array:)")));

/** Convert [NSData] (raw IEEE 754 bytes) to a [FloatArray] via a single bulk memcpy. */
+ (LeapUiKotlinFloatArray *)nsDataToFloatArrayData:(NSData *)data __attribute__((swift_name("nsDataToFloatArray(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HalftoneEffect_skikoKt")))
@interface LeapUiHalftoneEffect_skikoKt : LeapUiBase
+ (id<LeapUiUiModifier>)halftoneEffect:(id<LeapUiUiModifier>)receiver isDarkMode:(BOOL)isDarkMode __attribute__((swift_name("halftoneEffect(_:isDarkMode:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VoiceAssistantViewControllerKt")))
@interface LeapUiVoiceAssistantViewControllerKt : LeapUiBase

/**
 * Creates a [UIViewController] hosting [VoiceAssistantWidget] for use from SwiftUI.
 *
 * Retain [state] and assign a new [VoiceAssistantState] to [VoiceAssistantStateHolder.state] from
 * Swift to drive recomposition. The view controller does not need to be recreated when state
 * changes.
 *
 * Example (SwiftUI):
 * ```swift
 * import LeapUi
 *
 * struct VoiceAssistantView: UIViewControllerRepresentable {
 *   let state = VoiceAssistantStateHolder(initial: VoiceAssistantState(mode: .idle, amplitude: 0))
 *   var onIntent: (VoiceAssistantIntent) -> Void
 *
 *   func makeUIViewController(context: Context) -> UIViewController {
 *     VoiceAssistantViewControllerKt.VoiceAssistantViewController(
 *       state: state,
 *       onIntent: onIntent
 *     )
 *   }
 *
 *   func updateUIViewController(_ uiViewController: UIViewController, context: Context) {}
 * }
 * // Assign from the main thread — triggers Compose recomposition automatically:
 * state.state = VoiceAssistantState(mode: .listening, amplitude: 0)
 * ```
 *
 * @param state Observable state holder; assign a new [VoiceAssistantState] from Swift to update.
 *   Assignments must happen on the main thread.
 * @param onIntent Called for each user gesture with the corresponding [VoiceAssistantIntent].
 * @param labels Status label strings displayed for each mode.
 * @param colors Orb colour palette.
 * @param showPoweredBy Whether to show the "powered by Leap" badge. Defaults to `true`.
 */
+ (UIViewController *)VoiceAssistantViewControllerState:(LeapUiVoiceAssistantStateHolder *)state onIntent:(void (^)(id<LeapUiVoiceAssistantIntent>))onIntent labels:(LeapUiVoiceWidgetLabels *)labels colors:(LeapUiVoiceWidgetColors *)colors showPoweredBy:(BOOL)showPoweredBy __attribute__((swift_name("VoiceAssistantViewController(state:onIntent:labels:colors:showPoweredBy:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("__SkieSuspendWrappersKt")))
@interface LeapUi__SkieSuspendWrappersKt : LeapUiBase
+ (void)Skie_Suspend__0__hasNextDispatchReceiver:(LeapUiSkieColdFlowIterator<id> *)dispatchReceiver suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__0__hasNext(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__1__collectDispatchReceiver:(id<LeapUiKotlinx_coroutines_coreFlow>)dispatchReceiver collector:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)collector suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__1__collect(dispatchReceiver:collector:suspendHandler:)")));
+ (void)Skie_Suspend__2__emitDispatchReceiver:(id<LeapUiKotlinx_coroutines_coreFlowCollector>)dispatchReceiver value:(id _Nullable)value suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__2__emit(dispatchReceiver:value:suspendHandler:)")));
+ (void)Skie_Suspend__3__cancelDispatchReceiver:(id<LeapUiVoiceAudioRecorder>)dispatchReceiver suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__3__cancel(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__4__stopDispatchReceiver:(id<LeapUiVoiceAudioRecorder>)dispatchReceiver suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__4__stop(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__5__waitForPlaybackDispatchReceiver:(id<LeapUiVoiceAudioPlayer>)dispatchReceiver suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__5__waitForPlayback(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__6__generateResponseDispatchReceiver:(id<LeapUiVoiceConversation>)dispatchReceiver audioSamples:(LeapUiKotlinFloatArray *)audioSamples sampleRate:(int32_t)sampleRate onAudioChunk:(void (^)(LeapUiKotlinFloatArray *, LeapUiInt *))onAudioChunk suspendHandler:(LeapUiSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__6__generateResponse(dispatchReceiver:audioSamples:sampleRate:onAudioChunk:suspendHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface LeapUiKotlinEnumCompanion : LeapUiBase
@property (class, readonly, getter=shared) LeapUiKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface LeapUiKotlinArray<T> : LeapUiBase
@property (readonly) int32_t size __attribute__((swift_name("size")));
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(LeapUiInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<LeapUiKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol LeapUiKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<LeapUiKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface LeapUiKotlinThrowable : LeapUiBase
@property (readonly) LeapUiKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (LeapUiKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface LeapUiKotlinException : LeapUiKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface LeapUiKotlinRuntimeException : LeapUiKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface LeapUiKotlinIllegalStateException : LeapUiKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface LeapUiKotlinCancellationException : LeapUiKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LeapUiKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinFloatArray")))
@interface LeapUiKotlinFloatArray : LeapUiBase
@property (readonly) int32_t size __attribute__((swift_name("size")));
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(LeapUiFloat *(^)(LeapUiInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (float)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LeapUiKotlinFloatIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(float)value __attribute__((swift_name("set(index:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Leap_sdkGenerationStats")))
@interface LeapUiLeap_sdkGenerationStats : LeapUiBase
@property (readonly) int64_t cachedPromptTokens __attribute__((swift_name("cachedPromptTokens")));
@property (readonly) int64_t completionTokens __attribute__((swift_name("completionTokens")));
@property (readonly) int64_t promptTokens __attribute__((swift_name("promptTokens")));
@property (readonly) float tokenPerSecond __attribute__((swift_name("tokenPerSecond")));
@property (readonly) int64_t totalTokens __attribute__((swift_name("totalTokens")));
- (instancetype)initWithPromptTokens:(int64_t)promptTokens completionTokens:(int64_t)completionTokens totalTokens:(int64_t)totalTokens tokenPerSecond:(float)tokenPerSecond cachedPromptTokens:(int64_t)cachedPromptTokens __attribute__((swift_name("init(promptTokens:completionTokens:totalTokens:tokenPerSecond:cachedPromptTokens:)"))) __attribute__((objc_designated_initializer));
- (LeapUiLeap_sdkGenerationStats *)doCopyPromptTokens:(int64_t)promptTokens completionTokens:(int64_t)completionTokens totalTokens:(int64_t)totalTokens tokenPerSecond:(float)tokenPerSecond cachedPromptTokens:(int64_t)cachedPromptTokens __attribute__((swift_name("doCopy(promptTokens:completionTokens:totalTokens:tokenPerSecond:cachedPromptTokens:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Number of prompt tokens restored from KV cache (not recomputed). */

/** Number of tokens in the generated completion. */

/** Number of prompt tokens that were computed (excludes tokens restored from KV cache). */

/** Average number of generated tokens per second during the whole generation. */

/** Total number of tokens used in the request (prompt + completion). */
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol LeapUiKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end


/**
 * An ordered, immutable collection of [modifier elements][Modifier.Element] that decorate or add
 * behavior to Compose UI elements. For example, backgrounds, padding and click event listeners
 * decorate or add behavior to rows, text or buttons.
 *
 * @sample androidx.compose.ui.samples.ModifierUsageSample
 *
 * Modifier implementations should offer a fluent factory extension function on [Modifier] for
 * creating combined modifiers by starting from existing modifiers:
 *
 * @sample androidx.compose.ui.samples.ModifierFactorySample
 *
 * Modifier elements may be combined using [then]. Order is significant; modifier elements that
 * appear first will be applied first.
 *
 * Composables that accept a [Modifier] as a parameter to be applied to the whole component
 * represented by the composable function should name the parameter `modifier` and assign the
 * parameter a default value of [Modifier]. It should appear as the first optional parameter in the
 * parameter list; after all required parameters (except for trailing lambda parameters) but before
 * any other parameters with default values. Any default modifiers desired by a composable function
 * should come after the `modifier` parameter's value in the composable function's implementation,
 * keeping [Modifier] as the default parameter value. For example:
 *
 * @sample androidx.compose.ui.samples.ModifierParameterSample
 *
 * The pattern above allows default modifiers to still be applied as part of the chain if a caller
 * also supplies unrelated modifiers.
 *
 * Composables that accept modifiers to be applied to a specific subcomponent `foo` should name the
 * parameter `fooModifier` and follow the same guidelines above for default values and behavior.
 * Subcomponent modifiers should be grouped together and follow the parent composable's modifier.
 * For example:
 *
 * @sample androidx.compose.ui.samples.SubcomponentModifierSample
 *
 * @note annotations
 *   androidx.compose.runtime.Stable
*/
__attribute__((swift_name("UiModifier")))
@protocol LeapUiUiModifier
@required

/**
 * Returns `true` if [predicate] returns true for all [Element]s in this [Modifier] or if this
 * [Modifier] contains no [Element]s.
 */
- (BOOL)allPredicate:(LeapUiBoolean *(^)(id<LeapUiUiModifierElement>))predicate __attribute__((swift_name("all(predicate:)")));

/** Returns `true` if [predicate] returns true for any [Element] in this [Modifier]. */
- (BOOL)anyPredicate:(LeapUiBoolean *(^)(id<LeapUiUiModifierElement>))predicate __attribute__((swift_name("any(predicate:)")));

/**
 * Accumulates a value starting with [initial] and applying [operation] to the current value and
 * each element from outside in.
 *
 * Elements wrap one another in a chain from left to right; an [Element] that appears to the
 * left of another in a `+` expression or in [operation]'s parameter order affects all of the
 * elements that appear after it. [foldIn] may be used to accumulate a value starting from the
 * parent or head of the modifier chain to the final wrapped child.
 */
- (id _Nullable)foldInInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<LeapUiUiModifierElement>))operation __attribute__((swift_name("foldIn(initial:operation:)")));

/**
 * Accumulates a value starting with [initial] and applying [operation] to the current value and
 * each element from inside out.
 *
 * Elements wrap one another in a chain from left to right; an [Element] that appears to the
 * left of another in a `+` expression or in [operation]'s parameter order affects all of the
 * elements that appear after it. [foldOut] may be used to accumulate a value starting from the
 * child or tail of the modifier chain up to the parent or head of the chain.
 */
- (id _Nullable)foldOutInitial:(id _Nullable)initial operation:(id _Nullable (^)(id<LeapUiUiModifierElement>, id _Nullable))operation __attribute__((swift_name("foldOut(initial:operation:)")));

/**
 * Concatenates this modifier with another.
 *
 * Returns a [Modifier] representing this modifier followed by [other] in sequence.
 */
- (id<LeapUiUiModifier>)thenOther:(id<LeapUiUiModifier>)other __attribute__((swift_name("then(other:)")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol LeapUiKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol LeapUiKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<LeapUiKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<LeapUiKotlinCoroutineContextElement> _Nullable)getKey:(id<LeapUiKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<LeapUiKotlinCoroutineContext>)minusKeyKey:(id<LeapUiKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<LeapUiKotlinCoroutineContext>)plusContext:(id<LeapUiKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinFloatIterator")))
@interface LeapUiKotlinFloatIterator : LeapUiBase <LeapUiKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (LeapUiFloat *)next __attribute__((swift_name("next()")));
- (float)nextFloat __attribute__((swift_name("nextFloat()")));
@end


/** A single element contained within a [Modifier] chain. */
__attribute__((swift_name("UiModifierElement")))
@protocol LeapUiUiModifierElement <LeapUiUiModifier>
@required
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol LeapUiKotlinCoroutineContextElement <LeapUiKotlinCoroutineContext>
@required
@property (readonly) id<LeapUiKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol LeapUiKotlinCoroutineContextKey
@required
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
