#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class UIImage, NSURL, NSString, NSSet<ObjectType>, NSObject, NSNumber, NSMutableSet<ObjectType>, NSMutableDictionary<KeyType, ObjectType>, NSMutableArray<ObjectType>, NSError, NSDictionary<KeyType, ObjectType>, NSData, NSArray<ObjectType>, LSDK__SkieTypeExportsKt, LSDK__SkieSuspendWrappersKt, LSDKUtilsKt, LSDKUShort, LSDKULong, LSDKUInt, LSDKUByte, LSDKTokenProcessorCompanion, LSDKTokenProcessor, LSDKTextToTextLoadParamsCompanion, LSDKTextToTextLoadParams, LSDKSkie_SuspendResultSuccess, LSDKSkie_SuspendResultError, LSDKSkie_SuspendResultCanceled, LSDKSkie_SuspendResult, LSDKSkie_SuspendHandler, LSDKSkie_CancellationHandler, LSDKSkieKotlinStateFlow<T>, LSDKSkieKotlinSharedFlow<T>, LSDKSkieKotlinOptionalStateFlow<T>, LSDKSkieKotlinOptionalSharedFlow<T>, LSDKSkieKotlinOptionalMutableStateFlow<T>, LSDKSkieKotlinOptionalMutableSharedFlow<T>, LSDKSkieKotlinOptionalFlow<T>, LSDKSkieKotlinMutableStateFlow<T>, LSDKSkieKotlinMutableSharedFlow<T>, LSDKSkieKotlinFlow<T>, LSDKSkieColdFlowIterator<E>, LSDKShort, LSDKSha256Source, LSDKSha256Sink, LSDKSchemaSerializer, LSDKSamplingParametersCompanion, LSDKSamplingParameters, LSDKSamplerParams, LSDKPythonicTokenizer, LSDKPythonicTokenName, LSDKPythonicToken, LSDKPythonicSyntaxError, LSDKPythonicParser, LSDKPythonicDumper, LSDKProgressReportingSourceKt, LSDKProgressReportingSource, LSDKProgressReportingSinkKt, LSDKProgressReportingSink, LSDKProgressData, LSDKNumber, LSDKMutableSet<ObjectType>, LSDKMutableDictionary<KeyType, ObjectType>, LSDKModelSource, LSDKModelLoadingOptionsCompanion, LSDKModelLoadingOptions, LSDKMessageResponseReasoningChunk, LSDKMessageResponseFunctionCalls, LSDKMessageResponseComplete, LSDKMessageResponseChunk, LSDKMessageResponseAudioSample, LSDKMessageContentWavContent, LSDKMessageContentStringContent, LSDKMessageContentJpegContent, LSDKMessageContent, LSDKMessage, LSDKManifestCompanion, LSDKManifest, LSDKLong, LSDKLoadTimeParametersCompanion, LSDKLiquidMessageResponseReasoningChunk, LSDKLiquidMessageResponseFunctionCall, LSDKLiquidMessageResponseComplete, LSDKLiquidMessageResponseChunk, LSDKLiquidMessageResponseAudioSample, LSDKLiquidMessageResponse, LSDKLiquidInferenceEngineRunnerCompanion, LSDKLiquidInferenceEngineRunner, LSDKLiquidInferenceEngineOptions, LSDKLiquidInferenceEngineManifestOptions, LSDKLiquidEngineRunner, LSDKLiquidEngineCompanion, LSDKLiquidEngine, LSDKLiquidConversation, LSDKLiquidCacheOptions, LSDKLfm2AudioV1LoadParamsCompanion, LSDKLfm2AudioV1LoadParams, LSDKLeapStrCompanion, LSDKLeapStr, LSDKLeapSerializationException, LSDKLeapSDKVersion, LSDKLeapObjCompanion, LSDKLeapObj, LSDKLeapNumLongNumCompanion, LSDKLeapNumLongNum, LSDKLeapNumIntNumCompanion, LSDKLeapNumIntNum, LSDKLeapNumDoubleNumCompanion, LSDKLeapNumDoubleNum, LSDKLeapNumCompanion, LSDKLeapNum, LSDKLeapNull, LSDKLeapModelsResponseCompanion, LSDKLeapModelsResponse, LSDKLeapModelsApi, LSDKLeapModelManifestResponseCompanion, LSDKLeapModelManifestResponse, LSDKLeapModelLoadingException, LSDKLeapModelDownloadSizeMismatchException, LSDKLeapModelDownloadSha256MismatchException, LSDKLeapManifestProcessorConfig, LSDKLeapJsonKt, LSDKLeapInferenceEngine, LSDKLeapGenerationPromptExceedContextLengthException, LSDKLeapGenerationFunctionCallParsingException, LSDKLeapGenerationException, LSDKLeapGeneratableSchematizationException, LSDKLeapGeneratableDeserializationException, LSDKLeapFunctionParameterTypeLeapStr, LSDKLeapFunctionParameterTypeLeapObj, LSDKLeapFunctionParameterTypeLeapNum, LSDKLeapFunctionParameterTypeLeapNull, LSDKLeapFunctionParameterTypeLeapInt, LSDKLeapFunctionParameterTypeLeapBool, LSDKLeapFunctionParameterTypeLeapArr, LSDKLeapFunctionParameterTypeDtoStrCompanion, LSDKLeapFunctionParameterTypeDtoStr, LSDKLeapFunctionParameterTypeDtoObjCompanion, LSDKLeapFunctionParameterTypeDtoObj, LSDKLeapFunctionParameterTypeDtoNumCompanion, LSDKLeapFunctionParameterTypeDtoNum, LSDKLeapFunctionParameterTypeDtoNullTypeCompanion, LSDKLeapFunctionParameterTypeDtoNullType, LSDKLeapFunctionParameterTypeDtoIntTypeCompanion, LSDKLeapFunctionParameterTypeDtoIntType, LSDKLeapFunctionParameterTypeDtoCompanion, LSDKLeapFunctionParameterTypeDtoBoolCompanion, LSDKLeapFunctionParameterTypeDtoBool, LSDKLeapFunctionParameterTypeDtoArrCompanion, LSDKLeapFunctionParameterTypeDtoArr, LSDKLeapFunctionParameterTypeDto, LSDKLeapFunctionParameterType, LSDKLeapFunctionParameterDtoCompanion, LSDKLeapFunctionParameterDto, LSDKLeapFunctionParameter, LSDKLeapFunctionDtoCompanion, LSDKLeapFunctionDto, LSDKLeapFunctionCallSerializer, LSDKLeapFunctionCallParser, LSDKLeapFunctionCallCompanion, LSDKLeapFunctionCall, LSDKLeapFunction, LSDKLeapException, LSDKLeapDownloader_appleKt, LSDKLeapDownloaderSavedFileInfo, LSDKLeapDownloaderResolvedResource, LSDKLeapDownloaderResolvedManifest, LSDKLeapDownloaderKt, LSDKLeapDownloaderConfig, LSDKLeapDownloaderCompanion, LSDKLeapDownloader, LSDKLeapClient, LSDKLeapBoolCompanion, LSDKLeapBool, LSDKLeapArrCompanion, LSDKLeapArr, LSDKLeapApiModelCompanion, LSDKLeapApiModel, LSDKLeap, LSDKLFMFunctionCallParser, LSDKKtor_utilsWeekDayCompanion, LSDKKtor_utilsWeekDay, LSDKKtor_utilsTypeInfo, LSDKKtor_utilsStringValuesBuilderImpl, LSDKKtor_utilsPipelinePhase, LSDKKtor_utilsPipeline<TSubject, TContext>, LSDKKtor_utilsMonthCompanion, LSDKKtor_utilsMonth, LSDKKtor_utilsGMTDateCompanion, LSDKKtor_utilsGMTDate, LSDKKtor_utilsAttributeKey<T>, LSDKKtor_httpUrlCompanion, LSDKKtor_httpUrl, LSDKKtor_httpURLProtocolCompanion, LSDKKtor_httpURLProtocol, LSDKKtor_httpURLBuilderCompanion, LSDKKtor_httpURLBuilder, LSDKKtor_httpOutgoingContentWriteChannelContent, LSDKKtor_httpOutgoingContentReadChannelContent, LSDKKtor_httpOutgoingContentProtocolUpgrade, LSDKKtor_httpOutgoingContentNoContent, LSDKKtor_httpOutgoingContentContentWrapper, LSDKKtor_httpOutgoingContentByteArrayContent, LSDKKtor_httpOutgoingContent, LSDKKtor_httpHttpStatusCodeCompanion, LSDKKtor_httpHttpStatusCode, LSDKKtor_httpHttpProtocolVersionCompanion, LSDKKtor_httpHttpProtocolVersion, LSDKKtor_httpHttpMethodCompanion, LSDKKtor_httpHttpMethod, LSDKKtor_httpHeadersBuilder, LSDKKtor_httpHeaderValueWithParametersCompanion, LSDKKtor_httpHeaderValueWithParameters, LSDKKtor_httpHeaderValueParam, LSDKKtor_httpContentTypeCompanion, LSDKKtor_httpContentType, LSDKKtor_eventsEvents, LSDKKtor_eventsEventDefinition<T>, LSDKKtor_client_coreProxyConfig, LSDKKtor_client_coreHttpSendPipelinePhases, LSDKKtor_client_coreHttpSendPipeline, LSDKKtor_client_coreHttpResponsePipelinePhases, LSDKKtor_client_coreHttpResponsePipeline, LSDKKtor_client_coreHttpResponseData, LSDKKtor_client_coreHttpResponseContainer, LSDKKtor_client_coreHttpResponse, LSDKKtor_client_coreHttpRequestPipelinePhases, LSDKKtor_client_coreHttpRequestPipeline, LSDKKtor_client_coreHttpRequestData, LSDKKtor_client_coreHttpRequestBuilderCompanion, LSDKKtor_client_coreHttpRequestBuilder, LSDKKtor_client_coreHttpReceivePipelinePhases, LSDKKtor_client_coreHttpReceivePipeline, LSDKKtor_client_coreHttpClientEngineConfig, LSDKKtor_client_coreHttpClientConfig<T>, LSDKKtor_client_coreHttpClientCallCompanion, LSDKKtor_client_coreHttpClientCall, LSDKKtor_client_coreHttpClient, LSDKKotlinx_serialization_jsonJsonPrimitiveCompanion, LSDKKotlinx_serialization_jsonJsonPrimitive, LSDKKotlinx_serialization_jsonJsonNull, LSDKKotlinx_serialization_jsonJsonElementCompanion, LSDKKotlinx_serialization_jsonJsonElement, LSDKKotlinx_serialization_jsonJsonDefault, LSDKKotlinx_serialization_jsonJsonConfiguration, LSDKKotlinx_serialization_jsonJson, LSDKKotlinx_serialization_jsonClassDiscriminatorMode, LSDKKotlinx_serialization_coreStructureKindOBJECT, LSDKKotlinx_serialization_coreStructureKindMAP, LSDKKotlinx_serialization_coreStructureKindLIST, LSDKKotlinx_serialization_coreStructureKindCLASS, LSDKKotlinx_serialization_coreStructureKind, LSDKKotlinx_serialization_coreSerializersModule, LSDKKotlinx_serialization_coreSerialKindENUM, LSDKKotlinx_serialization_coreSerialKindCONTEXTUAL, LSDKKotlinx_serialization_coreSerialKind, LSDKKotlinx_serialization_corePrimitiveKindSTRING, LSDKKotlinx_serialization_corePrimitiveKindSHORT, LSDKKotlinx_serialization_corePrimitiveKindLONG, LSDKKotlinx_serialization_corePrimitiveKindINT, LSDKKotlinx_serialization_corePrimitiveKindFLOAT, LSDKKotlinx_serialization_corePrimitiveKindDOUBLE, LSDKKotlinx_serialization_corePrimitiveKindCHAR, LSDKKotlinx_serialization_corePrimitiveKindBYTE, LSDKKotlinx_serialization_corePrimitiveKindBOOLEAN, LSDKKotlinx_serialization_corePrimitiveKind, LSDKKotlinx_serialization_corePolymorphicKindSEALED, LSDKKotlinx_serialization_corePolymorphicKindOPEN, LSDKKotlinx_serialization_corePolymorphicKind, LSDKKotlinx_io_corePath, LSDKKotlinx_io_coreFileMetadata, LSDKKotlinx_io_coreBuffer, LSDKKotlinx_io_bytestringByteStringCompanion, LSDKKotlinx_io_bytestringByteString, LSDKKotlinx_coroutines_coreCoroutineDispatcherKey, LSDKKotlinx_coroutines_coreCoroutineDispatcher, LSDKKotlinUnit, LSDKKotlinThrowable, LSDKKotlinStringBuilder, LSDKKotlinRuntimeException, LSDKKotlinNothing, LSDKKotlinLongRangeCompanion, LSDKKotlinLongRange, LSDKKotlinLongProgressionCompanion, LSDKKotlinLongProgression, LSDKKotlinLongIterator, LSDKKotlinKVariance, LSDKKotlinKTypeProjectionCompanion, LSDKKotlinKTypeProjection, LSDKKotlinIllegalStateException, LSDKKotlinFloatIterator, LSDKKotlinFloatArray, LSDKKotlinException, LSDKKotlinEnumCompanion, LSDKKotlinEnum<E>, LSDKKotlinCharIterator, LSDKKotlinCharArray, LSDKKotlinCancellationException, LSDKKotlinByteIterator, LSDKKotlinByteArray, LSDKKotlinArray<T>, LSDKKotlinAbstractCoroutineContextKey<B, E>, LSDKKotlinAbstractCoroutineContextElement, LSDKJsonElementMapSerializer, LSDKJSONSchemaGenerator, LSDKInt, LSDKInferenceEngineExceptionsPromptExceedContextLengthException, LSDKInferenceEngineExceptions, LSDKInferenceEngineConversation, LSDKImageToTextLoadParamsCompanion, LSDKImageToTextLoadParams, LSDKHermesFunctionCallParser, LSDKGenerationTimeParametersCompanion, LSDKGenerationTimeParameters, LSDKGenerationStopReasonCompanion, LSDKGenerationStopReason, LSDKGenerationStats, LSDKGenerationOptionsCompatCompanion, LSDKGenerationOptionsCompat, LSDKGenerationOptionsCompanion, LSDKGenerationOptions, LSDKGenerationFinishReason, LSDKGenerateOptions, LSDKGeneratableFactory, LSDKFunctionArgSerializer, LSDKFunctionArgCompanion, LSDKFloatAudioBuffer, LSDKFloat, LSDKEngineOptionsKt, LSDKEngineOptionsCacheOptions, LSDKEngineOptions, LSDKEngineCompanion, LSDKEngine, LSDKDouble, LSDKCpuThreadAdvisor, LSDKConversationExtensionsKt, LSDKConstraintsCompanion, LSDKConstraints, LSDKChatMessageRoleCompanion, LSDKChatMessageRole, LSDKChatMessageJsonSerializer, LSDKChatMessageContentTextCompanion, LSDKChatMessageContentText, LSDKChatMessageContentImageSerializer, LSDKChatMessageContentImageImageUrlCompanion, LSDKChatMessageContentImageImageUrl, LSDKChatMessageContentImageCompanion, LSDKChatMessageContentImage, LSDKChatMessageContentHelpersKt, LSDKChatMessageContentFactory, LSDKChatMessageContentCompanion, LSDKChatMessageContentAudioSerializer, LSDKChatMessageContentAudioPcmF32Companion, LSDKChatMessageContentAudioPcmF32, LSDKChatMessageContentAudioInputAudioCompanion, LSDKChatMessageContentAudioInputAudio, LSDKChatMessageContentAudioCompanion, LSDKChatMessageContentAudio, LSDKChatMessageContent, LSDKChatMessageCompanion, LSDKChatMessage, LSDKCacheControlPolicy, LSDKCacheControl, LSDKByteArrayBase64Serializer, LSDKByte, LSDKBundleConfigCompanion, LSDKBundleConfig, LSDKBoolean, LSDKBase, LSDKAudioGenerationModelDescriptor, LSDKArtifactVersion, LSDKArrayConversionsKt;

@protocol NSCopying, LSDKSkie_DispatcherDelegate, LSDKModelRunnerGenerationHandler, LSDKModelRunnerGenerationCallback, LSDKModelRunner, LSDKMessageResponse, LSDKLoadTimeParameters, LSDKKtor_utilsStringValuesBuilder, LSDKKtor_utilsStringValues, LSDKKtor_utilsAttributes, LSDKKtor_ioJvmSerializable, LSDKKtor_ioCloseable, LSDKKtor_ioByteWriteChannel, LSDKKtor_ioByteReadChannel, LSDKKtor_httpParametersBuilder, LSDKKtor_httpParameters, LSDKKtor_httpHttpMessageBuilder, LSDKKtor_httpHttpMessage, LSDKKtor_httpHeaders, LSDKKtor_client_coreHttpRequest, LSDKKtor_client_coreHttpClientPlugin, LSDKKtor_client_coreHttpClientEngineCapability, LSDKKtor_client_coreHttpClientEngine, LSDKKotlinx_serialization_jsonJsonNamingStrategy, LSDKKotlinx_serialization_coreStringFormat, LSDKKotlinx_serialization_coreSerializersModuleCollector, LSDKKotlinx_serialization_coreSerializationStrategy, LSDKKotlinx_serialization_coreSerialFormat, LSDKKotlinx_serialization_coreSerialDescriptor, LSDKKotlinx_serialization_coreKSerializer, LSDKKotlinx_serialization_coreEncoder, LSDKKotlinx_serialization_coreDeserializationStrategy, LSDKKotlinx_serialization_coreDecoder, LSDKKotlinx_serialization_coreCompositeEncoder, LSDKKotlinx_serialization_coreCompositeDecoder, LSDKKotlinx_io_coreSource, LSDKKotlinx_io_coreSink, LSDKKotlinx_io_coreRawSource, LSDKKotlinx_io_coreRawSink, LSDKKotlinx_io_coreFileSystem, LSDKKotlinx_coroutines_coreStateFlow, LSDKKotlinx_coroutines_coreSharedFlow, LSDKKotlinx_coroutines_coreSelectInstance, LSDKKotlinx_coroutines_coreSelectClause2, LSDKKotlinx_coroutines_coreSelectClause1, LSDKKotlinx_coroutines_coreSelectClause0, LSDKKotlinx_coroutines_coreSelectClause, LSDKKotlinx_coroutines_coreRunnable, LSDKKotlinx_coroutines_coreParentJob, LSDKKotlinx_coroutines_coreMutex, LSDKKotlinx_coroutines_coreMutableStateFlow, LSDKKotlinx_coroutines_coreMutableSharedFlow, LSDKKotlinx_coroutines_coreJob, LSDKKotlinx_coroutines_coreFlowCollector, LSDKKotlinx_coroutines_coreFlow, LSDKKotlinx_coroutines_coreDisposableHandle, LSDKKotlinx_coroutines_coreCoroutineScope, LSDKKotlinx_coroutines_coreChildJob, LSDKKotlinx_coroutines_coreChildHandle, LSDKKotlinSuspendFunction2, LSDKKotlinSequence, LSDKKotlinOpenEndRange, LSDKKotlinMapEntry, LSDKKotlinKType, LSDKKotlinKDeclarationContainer, LSDKKotlinKClassifier, LSDKKotlinKClass, LSDKKotlinKAnnotatedElement, LSDKKotlinIterator, LSDKKotlinIterable, LSDKKotlinFunction, LSDKKotlinCoroutineContextKey, LSDKKotlinCoroutineContextElement, LSDKKotlinCoroutineContext, LSDKKotlinContinuationInterceptor, LSDKKotlinContinuation, LSDKKotlinComparable, LSDKKotlinClosedRange, LSDKKotlinCharSequence, LSDKKotlinAutoCloseable, LSDKKotlinAppendable, LSDKKotlinAnnotation, LSDKGenerateOptionsTokenCallback, LSDKFunctionArg, LSDKConversation;

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
@interface LSDKBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface LSDKBase (LSDKBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface LSDKMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface LSDKMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorLSDKKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface LSDKNumber : NSNumber
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
@interface LSDKByte : LSDKNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface LSDKUByte : LSDKNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface LSDKShort : LSDKNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface LSDKUShort : LSDKNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface LSDKInt : LSDKNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface LSDKUInt : LSDKNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface LSDKLong : LSDKNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface LSDKULong : LSDKNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface LSDKFloat : LSDKNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface LSDKDouble : LSDKNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface LSDKBoolean : LSDKNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * Audio generation models need to have following different components:
 * - Main model
 * - Multimodal projection model
 * - Audio decoder model
 * - (Optional) Audio tokenizer model This data class contains the paths of all models for the
 *   `LeapClient` to load.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AudioGenerationModelDescriptor")))
@interface LSDKAudioGenerationModelDescriptor : LSDKBase
@property (readonly) NSString *audioDecoderPath __attribute__((swift_name("audioDecoderPath")));
@property (readonly) NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSString *mmprojPath __attribute__((swift_name("mmprojPath")));
@property (readonly) NSString *modelPath __attribute__((swift_name("modelPath")));
- (instancetype)initWithModelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath audioDecoderPath:(NSString *)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath __attribute__((swift_name("init(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:)"))) __attribute__((objc_designated_initializer));
- (LSDKAudioGenerationModelDescriptor *)doCopyModelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath audioDecoderPath:(NSString *)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath __attribute__((swift_name("doCopy(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:)")));

/**
 * Audio generation models need to have following different components:
 * - Main model
 * - Multimodal projection model
 * - Audio decoder model
 * - (Optional) Audio tokenizer model This data class contains the paths of all models for the
 *   `LeapClient` to load.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Audio generation models need to have following different components:
 * - Main model
 * - Multimodal projection model
 * - Audio decoder model
 * - (Optional) Audio tokenizer model This data class contains the paths of all models for the
 *   `LeapClient` to load.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Audio generation models need to have following different components:
 * - Main model
 * - Multimodal projection model
 * - Audio decoder model
 * - (Optional) Audio tokenizer model This data class contains the paths of all models for the
 *   `LeapClient` to load.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** A data instance to hold the conversation context. */
__attribute__((swift_name("Conversation")))
@protocol LSDKConversation
@required

/**
 * Append a message to the history without triggering any generation.
 *
 * @param message the message to append
 */
- (void)appendToHistoryMessage:(LSDKChatMessage *)message __attribute__((swift_name("appendToHistory(message:)")));

/**
 * Generate a response to [message] and return a [Flow] of [MessageResponse] events.
 *
 * The message is appended to [history] before generation starts. Each token arrives as a
 * [MessageResponse.Chunk]; when the model finishes a [MessageResponse.Complete] is emitted and
 * the flow closes normally. On error the flow closes with a [LeapGenerationException].
 *
 * ### Stopping generation
 *
 * **Cancel the collecting coroutine.** The flow is built with `callbackFlow`; when the collector
 * is cancelled (or calls a terminal operator that cancels internally, such as `first()`), the
 * flow's `awaitClose` block fires automatically, calls `handler.stop()` on the underlying engine,
 * and releases the generation lock. No additional bookkeeping is required on the caller side.
 *
 * ```kotlin
 * // Collect all tokens until done:
 * conversation.generateResponse("Hello").collect { response -> ... }
 *
 * // Stop after the first token — cancels the rest automatically:
 * val first = conversation.generateResponse("Hello").first()
 *
 * // Stop from a parent scope (e.g. when the user navigates away):
 * val job = scope.launch {
 *   conversation.generateResponse("Hello").collect { ... }
 * }
 * job.cancel() // triggers awaitClose → handler.stop()
 * ```
 *
 * Only one generation can run on a given [Conversation] at a time; concurrent calls block on an
 * internal [Mutex] until the previous generation finishes or is stopped. Use [isGenerating] to
 * check whether a generation is in progress before starting a new one.
 *
 * @param message the message to append and generate a response for.
 */
- (id<LSDKKotlinx_coroutines_coreFlow>)generateResponseMessage:(LSDKChatMessage *)message generationOptions:(LSDKGenerationOptions * _Nullable)generationOptions __attribute__((swift_name("generateResponse(message:generationOptions:)")));

/**
 * Generate response with text input from the user.
 *
 * See [generateResponse] for full usage and stop semantics.
 *
 * @param userTextMessage the user's text input
 */
- (id<LSDKKotlinx_coroutines_coreFlow>)generateResponseUserTextMessage:(NSString *)userTextMessage generationOptions:(LSDKGenerationOptions * _Nullable)generationOptions __attribute__((swift_name("generateResponse(userTextMessage:generationOptions:)")));

/** Register a function into the conversation. */
- (void)registerFunctionFunction:(LSDKLeapFunction *)function __attribute__((swift_name("registerFunction(function:)")));

/** Register a list of functions into the conversation. */
- (void)registerFunctionsFunctions:(NSArray<LSDKLeapFunction *> *)functions __attribute__((swift_name("registerFunctions(functions:)")));

/**
 * Remove the last message from the history. No-ops if the history is empty.
 *
 * Used internally to clean up a dangling user message when generation is cancelled before the
 * assistant produces a [MessageResponse.Complete].
 */
- (void)removeLastMessage __attribute__((swift_name("removeLastMessage()")));

/** The registered functions for this conversation. */
@property (readonly) NSArray<LSDKLeapFunction *> *functions __attribute__((swift_name("functions")));
@property (readonly) id<LSDKKotlinx_coroutines_coreMutex> generatingLock __attribute__((swift_name("generatingLock")));

/** The conversation history. */
@property (readonly) NSArray<LSDKChatMessage *> *history __attribute__((swift_name("history")));

/** Whether a generation is in progress */
@property (readonly) BOOL isGenerating __attribute__((swift_name("isGenerating")));
@property (readonly) id<LSDKModelRunner> modelRunner __attribute__((swift_name("modelRunner")));
@end


/**
 * Apple implementation of CpuThreadAdvisor using NSProcessInfo for CPU detection.
 *
 * This advisor detects:
 * - Active processor count via NSProcessInfo.processInfo.activeProcessorCount
 * - Falls back gracefully to FALLBACK_THREAD_COUNT if detection fails
 *
 * Thread count is determined by: min(activeProcessors, MAX_SUPPORTED_THREADS)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CpuThreadAdvisor")))
@interface LSDKCpuThreadAdvisor : LSDKBase
@property (class, readonly, getter=shared) LSDKCpuThreadAdvisor *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Apple implementation of CpuThreadAdvisor using NSProcessInfo for CPU detection.
 *
 * This advisor detects:
 * - Active processor count via NSProcessInfo.processInfo.activeProcessorCount
 * - Falls back gracefully to FALLBACK_THREAD_COUNT if detection fails
 *
 * Thread count is determined by: min(activeProcessors, MAX_SUPPORTED_THREADS)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cpuThreadAdvisor __attribute__((swift_name("init()")));

/**
 * Returns the recommended number of CPU threads for model inference.
 *
 * The recommendation considers:
 * - Active processors via NSProcessInfo.processInfo.activeProcessorCount
 * - Maximum supported threads (8)
 *
 * @return Thread count between 1 and 8
 */
- (int32_t)getRecommendedThreadCount __attribute__((swift_name("getRecommendedThreadCount()")));
@end


/**
 * Options to control the generation. For any fields setting as null, the default parameter values
 * from the model bundle will be used.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationOptions")))
@interface LSDKGenerationOptions : LSDKBase
@property (class, readonly, getter=companion) LSDKGenerationOptionsCompanion *companion __attribute__((swift_name("companion")));
@property BOOL enableThinking __attribute__((swift_name("enableThinking")));
@property NSString * _Nullable extras __attribute__((swift_name("extras")));
@property LSDKLeapFunctionCallParser * _Nullable functionCallParser __attribute__((swift_name("functionCallParser")));
@property BOOL injectSchemaIntoPrompt __attribute__((swift_name("injectSchemaIntoPrompt")));
@property BOOL inlineThinkingTags __attribute__((swift_name("inlineThinkingTags")));
@property NSString * _Nullable jsonSchemaConstraint __attribute__((swift_name("jsonSchemaConstraint")));
@property LSDKInt * _Nullable maxTokens __attribute__((swift_name("maxTokens")));
@property LSDKFloat * _Nullable minP __attribute__((swift_name("minP")));
@property LSDKFloat * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));
@property LSDKLong * _Nullable rngSeed __attribute__((swift_name("rngSeed")));
@property LSDKFloat * _Nullable temperature __attribute__((swift_name("temperature")));
@property LSDKInt * _Nullable topK __attribute__((swift_name("topK")));
@property LSDKFloat * _Nullable topP __attribute__((swift_name("topP")));
- (instancetype)initWithTemperature:(LSDKFloat * _Nullable)temperature topP:(LSDKFloat * _Nullable)topP minP:(LSDKFloat * _Nullable)minP repetitionPenalty:(LSDKFloat * _Nullable)repetitionPenalty topK:(LSDKInt * _Nullable)topK rngSeed:(LSDKLong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LSDKLeapFunctionCallParser * _Nullable)functionCallParser injectSchemaIntoPrompt:(BOOL)injectSchemaIntoPrompt maxTokens:(LSDKInt * _Nullable)maxTokens inlineThinkingTags:(BOOL)inlineThinkingTags enableThinking:(BOOL)enableThinking extras:(NSString * _Nullable)extras __attribute__((swift_name("init(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:injectSchemaIntoPrompt:maxTokens:inlineThinkingTags:enableThinking:extras:)"))) __attribute__((objc_designated_initializer));
- (LSDKGenerationOptions *)doCopyTemperature:(LSDKFloat * _Nullable)temperature topP:(LSDKFloat * _Nullable)topP minP:(LSDKFloat * _Nullable)minP repetitionPenalty:(LSDKFloat * _Nullable)repetitionPenalty topK:(LSDKInt * _Nullable)topK rngSeed:(LSDKLong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LSDKLeapFunctionCallParser * _Nullable)functionCallParser injectSchemaIntoPrompt:(BOOL)injectSchemaIntoPrompt maxTokens:(LSDKInt * _Nullable)maxTokens inlineThinkingTags:(BOOL)inlineThinkingTags enableThinking:(BOOL)enableThinking extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:injectSchemaIntoPrompt:maxTokens:inlineThinkingTags:enableThinking:extras:)")));

/**
 * Options to control the generation. For any fields setting as null, the default parameter values
 * from the model bundle will be used.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Options to control the generation. For any fields setting as null, the default parameter values
 * from the model bundle will be used.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Setting the response format to a certain data class type. The provided class type should be a
 * data class annotated with [ai.liquid.leap.structuredoutput.Generatable]
 */
- (void)setResponseFormatType __attribute__((swift_name("setResponseFormatType()")));

/**
 * Options to control the generation. For any fields setting as null, the default parameter values
 * from the model bundle will be used.
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Whether to enable thinking/reasoning mode in the inference engine.
 *
 * When true, the engine will generate reasoning tokens (e.g., `<think>` blocks) before producing
 * the final response. These are emitted as
 * [ai.liquid.leap.message.MessageResponse.ReasoningChunk] responses (or inlined if
 * [inlineThinkingTags] is also true).
 *
 * Default is false (no reasoning output).
 */

/** Extra configuration. Internal use only. */

/**
 * Whether to inject the JSON schema constraint into the system message.
 *
 * When true (default), the schema is appended to the system message to provide semantic guidance
 * to the model. When false, the schema is only applied as a structural constraint during token
 * generation (like llama-server's grammar mode).
 *
 * Set to false if you want behavior matching llama-server, or if the schema injection is
 * consuming too many prompt tokens.
 */

/**
 * Whether to inline thinking/reasoning chunks with normal text responses.
 *
 * When true, thinking content will be emitted as regular
 * [ai.liquid.leap.message.MessageResponse.Chunk] responses with <think></think> tags intact,
 * rather than as separate [ai.liquid.leap.message.MessageResponse.ReasoningChunk] responses. The
 * final [ChatMessage.reasoningContent] will still be populated separately.
 *
 * Default is false (thinking chunks are emitted separately).
 */

/**
 * A JSONSchema constraint for the generation. Recommend to use [setResponseFormatType] for
 * setting this value.
 *
 * When set, the schema is automatically injected into the system prompt (if not already present)
 * to provide semantic guidance to the model, in addition to the structural constraint applied
 * during token generation. This dual approach ensures LFM models generate responses that both
 * conform to the schema structure and contain semantically appropriate content. Set
 * [injectSchemaIntoPrompt] to false to disable the prompt injection and use only the structural
 * constraint.
 *
 * **Note on token usage**: The JSON schema is appended to the system message, which increases the
 * prompt token count. Large schemas (1KB+) will consume more of the available context window.
 * Consider this when designing your data structures for constrained generation.
 */

/**
 * Maximum number of tokens to generate.
 *
 * When set, the model will stop generating after producing this many tokens (not counting prompt
 * tokens). If null, the model generates until it produces an end-of-sequence token or reaches the
 * context window limit.
 *
 * This is useful for controlling response length and cost, especially with structured output
 * where you know the expected response size.
 */

/** Minimal possibility for a token to be considered in generation. */

/**
 * Repetition penalty parameter.
 *
 * A positive value will decrease the model's likelihood to repeat the same line verbatim.
 */

/**
 * Random number generator seed for reproducible generation.
 *
 * When set, the model will produce deterministic output for the same input and seed value. Useful
 * for testing and debugging. If null, a random seed is used.
 */

/**
 * Sampling temperature parameter.
 *
 * Higher values will make the output more random, while lower values will make it more focused
 * and deterministic.
 */

/**
 * Top-K sampling parameter.
 *
 * Only consider the K most likely next tokens during sampling. Lower values make output more
 * focused by restricting the candidate pool, while higher values allow more diversity. A value of
 * 0 or null disables top-K filtering.
 */

/**
 * Nucleus sampling parameter.
 *
 * In nucleus sampling, the model only considers the results of the tokens with top_p probability
 * mass.
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationOptions.Companion")))
@interface LSDKGenerationOptionsCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKGenerationOptionsCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Create a [GenerationOptions] object with build actions. */
- (LSDKGenerationOptions *)buildBuildAction:(void (^)(LSDKGenerationOptions *))buildAction __attribute__((swift_name("build(buildAction:)")));
@end


/** Main entrypoint of LeapSDK */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapClient")))
@interface LSDKLeapClient : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapClient *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** Main entrypoint of LeapSDK */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapClient __attribute__((swift_name("init()")));

/**
 * Load an audio generation model from the model bundle files.
 *
 * This function is safe to call from the main thread.
 *
 * @param model descriptor for audio generation model
 * @param options loading options
 * @return model runner object
 * @throws LeapModelLoadingException
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelModel:(LSDKAudioGenerationModelDescriptor *)model options:(LSDKModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(model:options:completionHandler:)")));

/**
 * Load a model from the model bundle file. The app needs to hold the model runner object returned
 * by this function until it doesn't need to interact with the model anymore. If the returned
 * model runner object is not longer alive, all conversations created from this model runner will
 * not able to do generation.
 *
 * This function is safe to call from the main thread.
 *
 * @param modelPath local path of the model bundle file
 * @param options loading options
 * @return model runner object
 * @throws LeapModelLoadingException
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelModelPath:(NSString *)modelPath options:(LSDKModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelPath:options:completionHandler:)")));

/**
 * Load an audio generation model from the model bundle files.
 *
 * This function is safe to call from the main thread.
 *
 * @param params LoadTimeParameters from the manifest
 * @param options loading options
 * @return model runner object
 * @throws LeapModelLoadingException
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelParams:(id<LSDKLoadTimeParameters>)params generationParams:(LSDKGenerationTimeParameters * _Nullable)generationParams options:(LSDKModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(params:generationParams:options:completionHandler:)")));

/**
 * Load a model from the model bundle file with a multimodal projection model.
 *
 * This function is safe to call from the main thread.
 *
 * @param modelPath local path of the model bundle file
 * @param mmprojPath multimodal projection model file
 * @param options loading options
 * @return model runner object
 * @throws LeapModelLoadingException
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelModelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath options:(LSDKModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelPath:mmprojPath:options:completionHandler:)")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface LSDKKotlinThrowable : LSDKBase
@property (readonly) LSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (LSDKKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface LSDKKotlinException : LSDKKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Base class of all exceptions thrown from Leap SDK. */
__attribute__((swift_name("LeapException")))
@interface LSDKLeapException : LSDKKotlinException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/** Error in generating contents. */
__attribute__((swift_name("LeapGenerationException")))
@interface LSDKLeapGenerationException : LSDKLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** The specific error that the generated function call request cannot be correctly parsed. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGenerationFunctionCallParsingException")))
@interface LSDKLeapGenerationFunctionCallParsingException : LSDKLeapGenerationException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** The specific error that the input prompt exceeds the context length. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGenerationPromptExceedContextLengthException")))
@interface LSDKLeapGenerationPromptExceedContextLengthException : LSDKLeapGenerationException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Native platform implementation of LeapInferenceEngine for iOS, macOS, and Linux.
 *
 * Uses cinterop to bridge to the native C inference engine.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapInferenceEngine")))
@interface LSDKLeapInferenceEngine : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapInferenceEngine *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Native platform implementation of LeapInferenceEngine for iOS, macOS, and Linux.
 *
 * Uses cinterop to bridge to the native C inference engine.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapInferenceEngine __attribute__((swift_name("init()")));

/**
 * Loads a model from the specified path using the native inference engine.
 *
 * @param modelPath Path to the GGUF model file
 * @param mmprojPath Optional path to multimodal projector weights
 * @param audioDecoderPath Optional path to audio decoder weights
 * @param audioTokenizerPath Optional path to audio tokenizer
 * @param options Model loading options (threads, cache, etc.)
 * @param generationTimeParameters Sampling parameters for text generation
 * @return ModelRunner instance for performing inference
 * @throws LeapModelLoadingException if model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelModelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath options:(LSDKModelLoadingOptions * _Nullable)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:options:generationTimeParameters:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelDownloadSha256MismatchException")))
@interface LSDKLeapModelDownloadSha256MismatchException : LSDKLeapException
- (instancetype)initWithExpectedSha256:(NSString *)expectedSha256 actualSha256:(NSString *)actualSha256 __attribute__((swift_name("init(expectedSha256:actualSha256:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelDownloadSizeMismatchException")))
@interface LSDKLeapModelDownloadSizeMismatchException : LSDKLeapException
- (instancetype)initWithExpectedSize:(int64_t)expectedSize actualSize:(int64_t)actualSize __attribute__((swift_name("init(expectedSize:actualSize:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * Failure in loading the model. It could be caused by a permission issue, file format issue, or
 * other underlying issues in the engine.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelLoadingException")))
@interface LSDKLeapModelLoadingException : LSDKLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Error in serialization or deserialization. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapSerializationException")))
@interface LSDKLeapSerializationException : LSDKLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Options to configure when loading a model. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelLoadingOptions")))
@interface LSDKModelLoadingOptions : LSDKBase
@property (class, readonly, getter=companion) LSDKModelLoadingOptionsCompanion *companion __attribute__((swift_name("companion")));
@property LSDKEngineOptionsCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));
@property NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property LSDKInt * _Nullable contextSize __attribute__((swift_name("contextSize")));
@property int32_t cpuThreads __attribute__((swift_name("cpuThreads")));
@property NSString * _Nullable extras __attribute__((swift_name("extras")));
@property LSDKLong * _Nullable randomSeed __attribute__((swift_name("randomSeed")));
- (instancetype)initWithRandomSeed:(LSDKLong * _Nullable)randomSeed cpuThreads:(int32_t)cpuThreads chatTemplate:(NSString * _Nullable)chatTemplate cacheOptions:(LSDKEngineOptionsCacheOptions * _Nullable)cacheOptions contextSize:(LSDKInt * _Nullable)contextSize extras:(NSString * _Nullable)extras __attribute__((swift_name("init(randomSeed:cpuThreads:chatTemplate:cacheOptions:contextSize:extras:)"))) __attribute__((objc_designated_initializer));
- (LSDKModelLoadingOptions *)doCopyRandomSeed:(LSDKLong * _Nullable)randomSeed cpuThreads:(int32_t)cpuThreads chatTemplate:(NSString * _Nullable)chatTemplate cacheOptions:(LSDKEngineOptionsCacheOptions * _Nullable)cacheOptions contextSize:(LSDKInt * _Nullable)contextSize extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(randomSeed:cpuThreads:chatTemplate:cacheOptions:contextSize:extras:)")));

/** Options to configure when loading a model. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Options to configure when loading a model. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Options to configure when loading a model. */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * KV cache configuration. Default `null` means "no cache." To enable, construct a
 * `cacheOptions(...)` (helper below) with at least a `path` and `enabled = true`. The
 * `EngineOptions.CacheOptions` shape is exposed directly so callers can configure all bounded-LRU
 * fields (per-tier caps, master switch) without going through a parallel compatibility surface.
 * **Breaking change vs prior versions:** the old `cacheDir: String?` field is removed; migrate
 * via the `cacheOptions(path = ...)` helper for the equivalent 40-entry-disk-budget default.
 */

/** Template to use for a chat experience */

/**
 * Maximum context size in tokens. Controls KV cache memory allocation for attention layers.
 * Larger values allow longer conversations but use more memory. Default: 8192 tokens (~96MB KV
 * cache for a typical model).
 */

/** How many cpu threads to use in the generation. */

/** Extra configuration. Internal use only. */

/**
 * The random seed for token sampling. Same random seed will result in the same outcome in the
 * generation.
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelLoadingOptions.Companion")))
@interface LSDKModelLoadingOptionsCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKModelLoadingOptionsCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int32_t LEGACY_CACHE_MAX_ENTRIES_DISK __attribute__((swift_name("LEGACY_CACHE_MAX_ENTRIES_DISK")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Convenience constructor for the bounded-LRU cache. Returns an `EngineOptions.CacheOptions`
 * with `enabled = true` and the historical 40-entry disk budget by default — the equivalent of
 * the legacy `ModelLoadingOptions(cacheDir = path, ...)` shape.
 *
 * To disable the cache, set `ModelLoadingOptions.cacheOptions = null` (the default).
 *
 * **Memory-only mode** (`diskDisabled = true`): not exposed by this helper. Construct
 * `EngineOptions.CacheOptions(path = ..., enabled = true, diskDisabled = true)` directly when
 * you want the in-memory cache tier without the disk-backed tier (useful for benchmarking or
 * for callers who don't need cross-restart persistence). See
 * `EngineOptions.CacheOptions.diskDisabled` for the full contract.
 */
- (LSDKEngineOptionsCacheOptions *)cacheOptionsPath:(NSString *)path maxEntriesDisk:(int32_t)maxEntriesDisk __attribute__((swift_name("cacheOptions(path:maxEntriesDisk:)")));

/**
 * Disk cap used by the [cacheOptions] convenience helper. Mirrors the historical SDK default
 * (the pre-bounded-LRU `cacheDir = path` shape used 40 entries). This is *not* the engine's own
 * default — that's [ai.liquid.leap.inferenceengine.CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK]
 * (4096), which kicks in when `enabled = true` is set without naming a cap.
 */
@end


/**
 * A running model. Any model runner implementations need to expose certain methods to allow LEAP
 * SDK to control the model.
 */
__attribute__((swift_name("ModelRunner")))
@protocol LSDKModelRunner
@required

/**
 * Create a conversation object from this model runner.
 *
 * @param systemPrompt customized system prompt. A default system prompt from the model bundle
 *   will be used if it is null.
 */
- (id<LSDKConversation>)createConversationSystemPrompt:(NSString * _Nullable)systemPrompt __attribute__((swift_name("createConversation(systemPrompt:)")));

/**
 * Create a conversation from chat message history.
 *
 * @param history chat history (messages) to invoke the generation
 */
- (id<LSDKConversation>)createConversationFromHistoryHistory:(NSArray<LSDKChatMessage *> *)history __attribute__((swift_name("createConversationFromHistory(history:)")));

/**
 * Start generating a response for [conversation] and return a [GenerationHandler] immediately.
 *
 * **Prefer [Conversation.generateResponse]** over calling this method directly. This method is
 * low-level: callers are responsible for thread safety and for calling [GenerationHandler.stop]
 * when the generation should be cancelled.
 *
 * ### Contract for implementors
 * - **Must be non-blocking**: return the [GenerationHandler] before any [callback] fires. All
 *   platforms achieve this by starting inference on a background thread or Worker and returning
 *   immediately (Android/JVM via `scope.launch`; native via a background coroutine; wasmJs via a
 *   Web Worker message).
 * - Callbacks may be invoked from a thread other than the caller's thread.
 * - [GenerationCallback.onResponse] is called for every [MessageResponse.Chunk] and once for the
 *   terminal [MessageResponse.Complete].
 * - [GenerationCallback.onError] is called instead of `onResponse(Complete)` when the engine
 *   encounters an unrecoverable error.
 *
 * @param conversation the conversation whose history is used as the prompt.
 * @param callback receives streaming chunks and the terminal complete/error event.
 * @return a [GenerationHandler] that can stop the in-progress generation.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)generateFromConversationConversation:(id<LSDKConversation>)conversation callback:(id<LSDKModelRunnerGenerationCallback>)callback generationOptions:(LSDKGenerationOptions * _Nullable)generationOptions completionHandler:(void (^)(id<LSDKModelRunnerGenerationHandler> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("generateFromConversation(conversation:callback:generationOptions:completionHandler:)")));

/**
 * Get the prompt tokens size for a list of messages.
 *
 * @param messages the chat history to count tokens for
 * @param addBosToken whether to add the beginning-of-sequence token
 * @return the number of tokens in the prompt
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPromptTokensSizeMessages:(NSArray<LSDKChatMessage *> *)messages addBosToken:(BOOL)addBosToken completionHandler:(void (^)(LSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPromptTokensSize(messages:addBosToken:completionHandler:)")));

/**
 * Unload the model from the memory. The model runner and conversations created from this model
 * runner cannot be used anymore after invoking this method.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)unloadWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("unload(completionHandler:)")));

/** A string to identify the model. */
@property (readonly) NSString *modelId __attribute__((swift_name("modelId")));
@end


/** Callbacks to be called when chunks/data is generated */
__attribute__((swift_name("ModelRunnerGenerationCallback")))
@protocol LSDKModelRunnerGenerationCallback
@required

/**
 * Callback to invoke when an exception or an error is thrown during the generation
 *
 * @param error the error throwable object
 */
- (void)onErrorError:(LSDKKotlinThrowable *)error __attribute__((swift_name("onError(error:)")));

/**
 * Callback to invoke when a piece of response is available
 *
 * @param response the generated response from the model
 */
- (void)onResponseResponse:(id<LSDKMessageResponse>)response __attribute__((swift_name("onResponse(response:)")));
@end


/**
 * Handler returned by [generateFromConversation] to control an in-progress generation.
 *
 * Consumers should not use this interface directly. Use [Conversation.generateResponse] instead;
 * cancelling the returned [kotlinx.coroutines.flow.Flow]'s collector automatically calls [stop]
 * via the flow's `awaitClose` block.
 */
__attribute__((swift_name("ModelRunnerGenerationHandler")))
@protocol LSDKModelRunnerGenerationHandler
@required

/**
 * Signal the engine to stop generating tokens.
 *
 * The call is best-effort: at least one more token may be delivered before generation halts.
 * The exact threading behaviour depends on the platform:
 * - **Android / JVM**: synchronous — calls `engine.stop()` directly; the JNI layer sets an
 *   atomic flag (`SeqCst`) that is thread-safe and disjoint from generation state.
 * - **iOS / macOS (native)**: synchronous — calls `liquid_inference_engine_stop()` directly;
 *   the native layer is thread-safe so this is safe from any thread.
 * - **wasmJs (Worker-backed)**: non-blocking — sets a shared-memory stop flag or posts a `stop`
 *   message to the Web Worker; the Worker checks the flag between tokens.
 */
- (void)stop __attribute__((swift_name("stop()")));
@end


/**
 * A buffer for accumulating floating-point audio samples and converting them to WAV format.
 *
 * This class generates 32-bit float PCM WAV files (IEEE 754 format). The samples are stored as raw
 * floating-point values and converted to WAV format with proper headers when needed.
 *
 * **Breaking Change (v0.9.7)**: The constructor now accepts an optional `channelCount` parameter
 * for multi-channel audio support. Existing code using `FloatAudioBuffer(sampleRate)` will continue
 * to work (defaults to mono), but any subclasses that override the constructor may need updates.
 *
 * **Memory Considerations**: This buffer can accumulate unlimited samples, which may lead to
 * out-of-memory errors for very long audio recordings. Consider periodically processing and
 * clearing the buffer for streaming scenarios, or use the buffer size limits if needed.
 *
 * **Duration Precision**: The duration calculation uses floating-point arithmetic, which may
 * accumulate small rounding errors for extremely long audio files (multiple hours). This is not a
 * practical concern for typical use cases.
 *
 * @property sampleRate The audio sample rate in Hz (e.g., 16000, 44100)
 * @property channelCount The number of audio channels (1 = mono, 2 = stereo)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FloatAudioBuffer")))
@interface LSDKFloatAudioBuffer : LSDKBase
@property (readonly) int32_t channelCount __attribute__((swift_name("channelCount")));
@property (readonly) int32_t count __attribute__((swift_name("count")));
@property (readonly) double duration __attribute__((swift_name("duration")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
- (instancetype)initWithSampleRate:(int32_t)sampleRate channelCount:(int32_t)channelCount __attribute__((swift_name("init(sampleRate:channelCount:)"))) __attribute__((objc_designated_initializer));

/**
 * Add samples to the buffer.
 *
 * @param chunk Array of float samples to append (must be aligned to channel count)
 * @throws IllegalArgumentException if chunk size is not divisible by channel count or buffer
 *   would exceed maximum size
 */
- (void)addChunk:(LSDKKotlinFloatArray *)chunk __attribute__((swift_name("add(chunk:)")));

/**
 * Append samples to the buffer. Alias for [add] that matches iOS SDK naming.
 *
 * @param samples Array of float samples to append
 */
- (void)appendSamples:(LSDKKotlinFloatArray *)samples __attribute__((swift_name("append(samples:)")));

/** Remove all samples from the buffer */
- (void)clear __attribute__((swift_name("clear()")));

/**
 * Convert the buffer to WAV-encoded bytes (32-bit float PCM format, IEEE 754).
 *
 * The generated WAV file uses:
 * - Format: IEEE 754 32-bit float PCM
 * - Bits per sample: 32
 * - Byte order: Little-endian
 * - Header size: 44 bytes
 *
 * @return ByteArray containing a complete WAV file with header
 * @throws IllegalArgumentException if buffer is too large to fit in a WAV file
 */
- (LSDKKotlinByteArray *)createWavBytes __attribute__((swift_name("createWavBytes()")));

/**
 * Create a [ChatMessageContent.Audio] from the buffer's samples.
 *
 * This converts the floating-point samples to WAV format (32-bit float PCM) and wraps them in a
 * ChatMessageContent suitable for use in conversations.
 *
 * @return ChatMessageContent.Audio containing WAV-encoded data
 */
- (LSDKChatMessageContentAudio *)makeAudioContent __attribute__((swift_name("makeAudioContent()")));

/**
 * Create a [ChatMessageContent.AudioPcmF32] from the buffer's raw samples.
 *
 * This preserves the raw float32 samples without WAV encoding, suitable for roundtripping
 * engine-generated audio through conversation history without hash loss.
 *
 * @return ChatMessageContent.AudioPcmF32 containing raw PCM samples and sample rate
 */
- (LSDKChatMessageContentAudioPcmF32 *)makePcmF32AudioContent __attribute__((swift_name("makePcmF32AudioContent()")));

/**
 * Concatenate all chunks into a single [FloatArray].
 *
 * @return A new FloatArray containing all samples in order
 */
- (LSDKKotlinFloatArray *)toFloatArray __attribute__((swift_name("toFloatArray()")));

/** Returns the total number of samples in the buffer (across all channels) */

/**
 * Returns the duration of the audio in seconds.
 *
 * The duration is calculated as: (number of frames) / sample rate, where the number of frames is
 * (total samples) / channel count.
 *
 * Note: Uses floating-point arithmetic which may have minor precision issues for very long audio
 * (multiple hours).
 */

/** Returns true if the buffer contains no samples */
@end


/**
 * Cache control configuration.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl`.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheControl")))
@interface LSDKCacheControl : LSDKBase
@property (readonly) NSString * _Nullable point __attribute__((swift_name("point")));
@property (readonly) LSDKCacheControlPolicy *policy __attribute__((swift_name("policy")));
- (instancetype)initWithPolicy:(LSDKCacheControlPolicy *)policy point:(NSString * _Nullable)point __attribute__((swift_name("init(policy:point:)"))) __attribute__((objc_designated_initializer));
- (LSDKCacheControl *)doCopyPolicy:(LSDKCacheControlPolicy *)policy point:(NSString * _Nullable)point __attribute__((swift_name("doCopy(policy:point:)")));

/**
 * Cache control configuration.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl`.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Cache control configuration.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl`.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Cache control configuration.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl`.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol LSDKKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface LSDKKotlinEnum<E> : LSDKBase <LSDKKotlinComparable>
@property (class, readonly, getter=companion) LSDKKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Cache control policy for generation caching behavior.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl.Policy`.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheControlPolicy")))
@interface LSDKCacheControlPolicy : LSDKKotlinEnum<LSDKCacheControlPolicy *>
@property (class, readonly) LSDKCacheControlPolicy *cache __attribute__((swift_name("cache")));
@property (class, readonly) LSDKCacheControlPolicy *nocache __attribute__((swift_name("nocache")));
@property (class, readonly) NSArray<LSDKCacheControlPolicy *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Cache control policy for generation caching behavior.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl.Policy`.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKCacheControlPolicy *> *)values __attribute__((swift_name("values()")));
@end


/**
 * Factory object for creating ChatMessageContent instances with iOS SDK-compatible API.
 *
 * This object exports to Swift and allows the syntax:
 * ```swift
 * let text = ChatMessageContentFactory.text("Hello")
 * let image = try ChatMessageContentFactory.fromUIImage(uiImage)
 * ```
 *
 * SKIE will also create extensions that allow the original syntax:
 * ```swift
 * let text = ChatMessageContent.text("Hello")
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContentFactory")))
@interface LSDKChatMessageContentFactory : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentFactory *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Factory object for creating ChatMessageContent instances with iOS SDK-compatible API.
 *
 * This object exports to Swift and allows the syntax:
 * ```swift
 * let text = ChatMessageContentFactory.text("Hello")
 * let image = try ChatMessageContentFactory.fromUIImage(uiImage)
 * ```
 *
 * SKIE will also create extensions that allow the original syntax:
 * ```swift
 * let text = ChatMessageContent.text("Hello")
 * ```
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageContentFactory __attribute__((swift_name("init()")));

/** Create an Image content from a UIImage. */
- (LSDKChatMessageContentImage *)fromUIImageImage:(UIImage *)image __attribute__((swift_name("fromUIImage(image:)")));

/** Create a Text content from a string. */
- (LSDKChatMessageContentText *)textText:(NSString *)text __attribute__((swift_name("text(text:)")));
@end


/**
 * Generation options that match the iOS SDK's `GenerationOptions` API.
 *
 * This provides a drop-in replacement for code migrating from the native iOS SDK. All fields match
 * the iOS SDK structure while internally mapping to the KMP SDK.
 *
 * **Note on callbacks**: The `onStats` and `onAudioSamples` callbacks are not yet supported in the
 * current KMP SDK implementation. These fields are reserved for future compatibility but will not
 * be invoked. Use the streaming response mechanisms in [Conversation] instead.
 *
 * Usage:
 * ```swift
 * let options = GenerationOptions(
 *     temperature: 0.7,
 *     maxOutputTokens: 1024,
 *     enableThinking: true
 * )
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationOptionsCompat")))
@interface LSDKGenerationOptionsCompat : LSDKBase
@property (class, readonly, getter=companion) LSDKGenerationOptionsCompatCompanion *companion __attribute__((swift_name("companion")));
@property LSDKCacheControl * _Nullable cacheControl __attribute__((swift_name("cacheControl")));
@property BOOL enableThinking __attribute__((swift_name("enableThinking")));
@property NSString * _Nullable extras __attribute__((swift_name("extras")));
@property LSDKLeapFunctionCallParser * _Nullable functionCallParser __attribute__((swift_name("functionCallParser")));
@property BOOL inlineThinkingTags __attribute__((swift_name("inlineThinkingTags")));
@property NSString * _Nullable jsonSchemaConstraint __attribute__((swift_name("jsonSchemaConstraint")));
@property LSDKUInt * _Nullable maxOutputTokens __attribute__((swift_name("maxOutputTokens")));
@property LSDKFloat * _Nullable minP __attribute__((swift_name("minP")));
@property LSDKFloat * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));
@property LSDKULong * _Nullable rngSeed __attribute__((swift_name("rngSeed")));
@property LSDKUInt * _Nullable sequenceLength __attribute__((swift_name("sequenceLength")));
@property LSDKFloat * _Nullable temperature __attribute__((swift_name("temperature")));
@property LSDKInt * _Nullable topK __attribute__((swift_name("topK")));
@property LSDKFloat * _Nullable topP __attribute__((swift_name("topP")));
- (instancetype)initWithTemperature:(LSDKFloat * _Nullable)temperature topP:(LSDKFloat * _Nullable)topP minP:(LSDKFloat * _Nullable)minP repetitionPenalty:(LSDKFloat * _Nullable)repetitionPenalty topK:(LSDKInt * _Nullable)topK rngSeed:(LSDKULong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LSDKLeapFunctionCallParser * _Nullable)functionCallParser sequenceLength:(LSDKUInt * _Nullable)sequenceLength maxOutputTokens:(LSDKUInt * _Nullable)maxOutputTokens enableThinking:(BOOL)enableThinking inlineThinkingTags:(BOOL)inlineThinkingTags cacheControl:(LSDKCacheControl * _Nullable)cacheControl extras:(NSString * _Nullable)extras __attribute__((swift_name("init(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:sequenceLength:maxOutputTokens:enableThinking:inlineThinkingTags:cacheControl:extras:)"))) __attribute__((objc_designated_initializer));
- (LSDKGenerationOptionsCompat *)doCopyTemperature:(LSDKFloat * _Nullable)temperature topP:(LSDKFloat * _Nullable)topP minP:(LSDKFloat * _Nullable)minP repetitionPenalty:(LSDKFloat * _Nullable)repetitionPenalty topK:(LSDKInt * _Nullable)topK rngSeed:(LSDKULong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LSDKLeapFunctionCallParser * _Nullable)functionCallParser sequenceLength:(LSDKUInt * _Nullable)sequenceLength maxOutputTokens:(LSDKUInt * _Nullable)maxOutputTokens enableThinking:(BOOL)enableThinking inlineThinkingTags:(BOOL)inlineThinkingTags cacheControl:(LSDKCacheControl * _Nullable)cacheControl extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:sequenceLength:maxOutputTokens:enableThinking:inlineThinkingTags:cacheControl:extras:)")));

/**
 * Generation options that match the iOS SDK's `GenerationOptions` API.
 *
 * This provides a drop-in replacement for code migrating from the native iOS SDK. All fields match
 * the iOS SDK structure while internally mapping to the KMP SDK.
 *
 * **Note on callbacks**: The `onStats` and `onAudioSamples` callbacks are not yet supported in the
 * current KMP SDK implementation. These fields are reserved for future compatibility but will not
 * be invoked. Use the streaming response mechanisms in [Conversation] instead.
 *
 * Usage:
 * ```swift
 * let options = GenerationOptions(
 *     temperature: 0.7,
 *     maxOutputTokens: 1024,
 *     enableThinking: true
 * )
 * ```
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Generation options that match the iOS SDK's `GenerationOptions` API.
 *
 * This provides a drop-in replacement for code migrating from the native iOS SDK. All fields match
 * the iOS SDK structure while internally mapping to the KMP SDK.
 *
 * **Note on callbacks**: The `onStats` and `onAudioSamples` callbacks are not yet supported in the
 * current KMP SDK implementation. These fields are reserved for future compatibility but will not
 * be invoked. Use the streaming response mechanisms in [Conversation] instead.
 *
 * Usage:
 * ```swift
 * let options = GenerationOptions(
 *     temperature: 0.7,
 *     maxOutputTokens: 1024,
 *     enableThinking: true
 * )
 * ```
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Set the JSON schema constraint for structured output generation.
 *
 * This method provides a Swift-friendly way to set the response format using a JSON schema
 * string. The schema should be a valid JSON string that defines the expected output structure.
 *
 * Usage from Swift:
 * ```swift
 * let schema = SchemaBuilder()
 *   .object(description: "User profile")
 *   .property("name", type: .string, description: "User name", required: true)
 *   .property("age", type: .integer, description: "User age", required: false)
 *   .build()
 *
 * let options = GenerationOptionsCompat()
 * options.setResponseFormat(jsonSchema: schema)
 * ```
 *
 * @param jsonSchema A JSON schema string defining the expected output structure
 * @throws IllegalArgumentException if the schema is blank or not valid JSON
 */
- (void)setResponseFormatJsonSchema:(NSString *)jsonSchema __attribute__((swift_name("setResponseFormat(jsonSchema:)")));

/**
 * Convert to KMP GenerationOptions.
 *
 * Note: Some iOS SDK fields (resetHistory, callbacks) are handled at the conversation level in
 * the KMP SDK and are not directly mapped here.
 */
- (LSDKGenerationOptions *)toKmpGenerationOptions __attribute__((swift_name("toKmpGenerationOptions()")));

/**
 * Generation options that match the iOS SDK's `GenerationOptions` API.
 *
 * This provides a drop-in replacement for code migrating from the native iOS SDK. All fields match
 * the iOS SDK structure while internally mapping to the KMP SDK.
 *
 * **Note on callbacks**: The `onStats` and `onAudioSamples` callbacks are not yet supported in the
 * current KMP SDK implementation. These fields are reserved for future compatibility but will not
 * be invoked. Use the streaming response mechanisms in [Conversation] instead.
 *
 * Usage:
 * ```swift
 * let options = GenerationOptions(
 *     temperature: 0.7,
 *     maxOutputTokens: 1024,
 *     enableThinking: true
 * )
 * ```
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** Optional cache control directives passed to the engine */

/** When enabled, the engine surfaces reasoning tokens such as `<think>` blocks */

/** Additional engine-specific extensions encoded as a JSON string */

/**
 * Function call parser. By default, LFM function call parser is used. Set to null to return
 * function calls as normal content.
 */

/**
 * When true, thinking content is emitted as regular text chunks with `<think></think>` tags
 * intact, rather than as separate reasoning chunks. Default is false.
 */

/** JSON schema constraint for structured output generation */

/** Maximum number of tokens to generate for this request */

/** Minimal probability for a token to be considered in generation */

/** Repetition penalty parameter (positive value decreases repetition) */

/** Optional random seed for deterministic replay */

/** Override for the context window length used by the engine */

/** Sampling temperature parameter (higher = more random, lower = more focused) */

/** Top-K sampling parameter — only consider the K most likely tokens (null for default) */

/** Nucleus sampling parameter (top-p) */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationOptionsCompat.Companion")))
@interface LSDKGenerationOptionsCompatCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKGenerationOptionsCompatCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Create a GenerationOptions with default values matching iOS SDK defaults. */
- (LSDKGenerationOptionsCompat *)withDefaults __attribute__((swift_name("withDefaults()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Leap")))
@interface LSDKLeap : LSDKBase
@property (class, readonly, getter=shared) LSDKLeap *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leap __attribute__((swift_name("init()")));

/**
 * Load a model from a manifest URL with optional configuration and download progress.
 *
 * Downloads the manifest, then downloads all required model files and loads the model. This
 * method matches the iOS SDK's load(manifestUrl:options:downloadProgressHandler:) API.
 *
 * @param manifestUrl The URL pointing to the manifest JSON file
 * @param options Optional configuration for model loading (LiquidInferenceEngineManifestOptions)
 * @param downloadProgressHandler Optional callback for download progress (fraction,
 *   bytesPerSecond)
 * @return A ModelRunner instance ready for inference
 * @throws Exception if download or model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadManifestUrl:(NSURL *)manifestUrl options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(manifestUrl:options:downloadProgressHandler:completionHandler:)")));

/**
 * Load a model by name and quantization with optional configuration and download progress.
 *
 * Downloads the model from the Leap model registry and loads it. This method matches the iOS
 * SDK's load(model:quantization:options:downloadProgressHandler:) API.
 *
 * @param model The model name (e.g., "lfm-40b")
 * @param quantization The quantization method (e.g., "q4_k_m")
 * @param options Optional configuration for model loading (LiquidInferenceEngineManifestOptions)
 * @param downloadProgressHandler Optional callback for download progress (fraction,
 *   bytesPerSecond)
 * @return A ModelRunner instance ready for inference
 * @throws Exception if download or model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModel:(NSString *)model quantization:(NSString *)quantization options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(model:quantization:options:downloadProgressHandler:completionHandler:)")));

/**
 * Load a model from a file URL with optional configuration.
 *
 * This method automatically discovers companion files (mmproj, audio decoder) in the same
 * directory as the model file if they are not explicitly provided in options and auto-detection
 * is enabled (default).
 *
 * **Note on concurrent file access**: The auto-detection feature reads directory contents, which
 * may race with concurrent filesystem modifications. For production use in multi-threaded
 * environments, consider explicitly providing companion file paths in the options.
 *
 * @param url The file URL pointing to the model file (.gguf)
 * @param options Optional configuration for model loading (LiquidInferenceEngineOptions)
 * @param generationTimeParameters Optional generation-time parameters (caller should get from
 *   manifest)
 * @param autoDetectCompanionFiles Whether to auto-detect mmproj and audio decoder files (default:
 *   true)
 * @return A ModelRunner instance ready for inference
 * @throws IllegalArgumentException if URL is invalid
 * @throws Exception if model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadUrl:(NSURL *)url options:(LSDKLiquidInferenceEngineOptions * _Nullable)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(url:options:generationTimeParameters:autoDetectCompanionFiles:completionHandler:)")));

/**
 * Load a model from a file URL with simple parameters (backward compatibility).
 *
 * This overload provides a simpler API matching the old iOS SDK where contextSize could be passed
 * directly.
 *
 * Usage from Swift:
 * ```swift
 * let runner = try await Leap.load(
 *     url: URL(fileURLWithPath: "/path/to/model.gguf"),
 *     contextSize: 4096
 * )
 * ```
 *
 * @param url The file URL pointing to the model file (.gguf)
 * @param contextSize Context window size (defaults to model's default if not specified)
 * @param cpuThreads Number of CPU threads (defaults to system default if not specified)
 * @param autoDetectCompanionFiles Whether to auto-detect mmproj and audio decoder files (default:
 *   true)
 * @return A ModelRunner instance ready for inference
 * @throws IllegalArgumentException if URL is invalid or parameters are out of range
 * @throws Exception if model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadUrl:(NSURL *)url contextSize:(LSDKUInt * _Nullable)contextSize cpuThreads:(LSDKUInt * _Nullable)cpuThreads autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(url:contextSize:cpuThreads:autoDetectCompanionFiles:completionHandler:)")));
@end


/**
 * Leap SDK version information.
 *
 * This matches the iOS SDK's version API.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapSDKVersion")))
@interface LSDKLeapSDKVersion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapSDKVersion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *version __attribute__((swift_name("version")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Leap SDK version information.
 *
 * This matches the iOS SDK's version API.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapSDKVersion __attribute__((swift_name("init()")));

/** The current SDK version string */
@end


/**
 * Cache options for the inference engine.
 *
 * Compatibility layer matching the iOS SDK's `LiquidCacheOptions`. Extended with the bounded-LRU KV
 * cache fields (`enabled`, `maxEntriesDisk`, `maxEntriesMemory`, `maxBytesMemory`); legacy
 * `maxEntries` preserved as the disk-cap alias when callers pre-date the extension. See KMP
 * `EngineOptions.CacheOptions` for full semantics — `maxEntriesDisk` defaults to 0 so the
 * resolution chain (`maxEntriesDisk` → legacy `maxEntries` →
 * `CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK`) stays reachable; `toModelLoadingOptions` expands 0 →
 * 4096 at the boundary.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidCacheOptions")))
@interface LSDKLiquidCacheOptions : LSDKBase
@property (readonly) BOOL diskDisabled __attribute__((swift_name("diskDisabled")));
@property (readonly) BOOL enabled __attribute__((swift_name("enabled")));
@property (readonly) int64_t maxBytesMemory __attribute__((swift_name("maxBytesMemory")));
@property (readonly) int32_t maxEntries __attribute__((swift_name("maxEntries")));
@property (readonly) int32_t maxEntriesDisk __attribute__((swift_name("maxEntriesDisk")));
@property (readonly) int32_t maxEntriesMemory __attribute__((swift_name("maxEntriesMemory")));
@property (readonly) NSString *path __attribute__((swift_name("path")));
- (instancetype)initWithPath:(NSString *)path maxEntries:(int32_t)maxEntries enabled:(BOOL)enabled maxEntriesDisk:(int32_t)maxEntriesDisk maxEntriesMemory:(int32_t)maxEntriesMemory maxBytesMemory:(int64_t)maxBytesMemory diskDisabled:(BOOL)diskDisabled __attribute__((swift_name("init(path:maxEntries:enabled:maxEntriesDisk:maxEntriesMemory:maxBytesMemory:diskDisabled:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidCacheOptions *)doCopyPath:(NSString *)path maxEntries:(int32_t)maxEntries enabled:(BOOL)enabled maxEntriesDisk:(int32_t)maxEntriesDisk maxEntriesMemory:(int32_t)maxEntriesMemory maxBytesMemory:(int64_t)maxBytesMemory diskDisabled:(BOOL)diskDisabled __attribute__((swift_name("doCopy(path:maxEntries:enabled:maxEntriesDisk:maxEntriesMemory:maxBytesMemory:diskDisabled:)")));

/**
 * Cache options for the inference engine.
 *
 * Compatibility layer matching the iOS SDK's `LiquidCacheOptions`. Extended with the bounded-LRU KV
 * cache fields (`enabled`, `maxEntriesDisk`, `maxEntriesMemory`, `maxBytesMemory`); legacy
 * `maxEntries` preserved as the disk-cap alias when callers pre-date the extension. See KMP
 * `EngineOptions.CacheOptions` for full semantics — `maxEntriesDisk` defaults to 0 so the
 * resolution chain (`maxEntriesDisk` → legacy `maxEntries` →
 * `CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK`) stays reachable; `toModelLoadingOptions` expands 0 →
 * 4096 at the boundary.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Cache options for the inference engine.
 *
 * Compatibility layer matching the iOS SDK's `LiquidCacheOptions`. Extended with the bounded-LRU KV
 * cache fields (`enabled`, `maxEntriesDisk`, `maxEntriesMemory`, `maxBytesMemory`); legacy
 * `maxEntries` preserved as the disk-cap alias when callers pre-date the extension. See KMP
 * `EngineOptions.CacheOptions` for full semantics — `maxEntriesDisk` defaults to 0 so the
 * resolution chain (`maxEntriesDisk` → legacy `maxEntries` →
 * `CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK`) stays reachable; `toModelLoadingOptions` expands 0 →
 * 4096 at the boundary.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Convert this iOS-shape config to the KMP `EngineOptions.CacheOptions` consumed by
 * `ModelLoadingOptions`. Returns `null` when this `LiquidCacheOptions` has `enabled = false`,
 * matching the iOS shape "no cache" semantic. When `enabled = true`, the returned KMP
 * `CacheOptions` always has `enabled = true` (so the engine sees opt-in), with the disk cap
 * resolving through the shared `resolvedMaxEntriesDisk()` chain at the binding boundary.
 */
- (LSDKEngineOptionsCacheOptions * _Nullable)toCacheOptions __attribute__((swift_name("toCacheOptions()")));

/**
 * Cache options for the inference engine.
 *
 * Compatibility layer matching the iOS SDK's `LiquidCacheOptions`. Extended with the bounded-LRU KV
 * cache fields (`enabled`, `maxEntriesDisk`, `maxEntriesMemory`, `maxBytesMemory`); legacy
 * `maxEntries` preserved as the disk-cap alias when callers pre-date the extension. See KMP
 * `EngineOptions.CacheOptions` for full semantics — `maxEntriesDisk` defaults to 0 so the
 * resolution chain (`maxEntriesDisk` → legacy `maxEntries` →
 * `CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK`) stays reachable; `toModelLoadingOptions` expands 0 →
 * 4096 at the boundary.
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Memory-only mode: when `true`, the engine constructs only the in-memory cache tier and skips
 * `KvDiskCache` entirely. Default `false` preserves existing iOS SDK behavior. Ignored when
 * `enabled = false`. See KMP `EngineOptions.CacheOptions.diskDisabled` for the full contract.
 */
@end


/**
 * LiquidConversation - Wrapper around Conversation with old API
 *
 * Provides generateResponse() method that returns a sealed class hierarchy designed to be
 * exhaustively switched over from Swift.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidConversation")))
@interface LSDKLiquidConversation : LSDKBase
- (instancetype)initWithConversation:(id<LSDKConversation>)conversation __attribute__((swift_name("init(conversation:)"))) __attribute__((objc_designated_initializer));

/**
 * Generate a response for the given message
 *
 * Returns a Flow of LiquidMessageResponse instances from a sealed class hierarchy that is
 * intended to be convenient to handle with Swift switch / pattern matching.
 *
 * Matches: conversation.generateResponse(message:generationOptions:) from old iOS SDK
 */
- (id<LSDKKotlinx_coroutines_coreFlow>)generateResponseMessage:(LSDKChatMessage *)message generationOptions:(LSDKGenerationOptionsCompat *)generationOptions __attribute__((swift_name("generateResponse(message:generationOptions:)")));
@end


/**
 * LiquidEngine - Drop-in replacement for the old iOS SDK's LiquidEngine class
 *
 * This class provides backward compatibility with the old native iOS SDK API, making migration
 * seamless without requiring code changes in client apps.
 *
 * Usage:
 * ```swift
 * // Old iOS SDK API - works exactly the same
 * let engine = try await LiquidEngine(modelURL: url)
 * let conversation = engine.runner.createConversationFromHistory(history: messages)
 * let stream = conversation.generateResponse(message: userMessage, generationOptions: options)
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidEngine")))
@interface LSDKLiquidEngine : LSDKBase
@property (class, readonly, getter=companion) LSDKLiquidEngineCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSURL *modelURL __attribute__((swift_name("modelURL")));
@property (readonly) LSDKLiquidEngineRunner *runner __attribute__((swift_name("runner")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidEngine.Companion")))
@interface LSDKLiquidEngineCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLiquidEngineCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Initialize LiquidEngine from a model file URL Matches: LiquidEngine(modelURL:) from old iOS
 * SDK
 *
 * @param modelURL Must be a file URL with a non-null path pointing to the model bundle
 * @throws IllegalArgumentException if modelURL is not a file:// URL or has no path
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeModelURL:(NSURL *)modelURL completionHandler:(void (^)(LSDKLiquidEngine * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(modelURL:completionHandler:)")));

/**
 * Initialize LiquidEngine with model name and quantization type Matches:
 * LiquidEngine(modelURL:model:quantization:) from old iOS SDK
 *
 * @param modelURL Must be a file URL with a non-null path pointing to the model bundle
 * @param model Model name used to extract context size (e.g., "LFM-1B-2K")
 * @param quantization Accepted for backward compatibility but currently ignored
 * @throws IllegalArgumentException if modelURL is not a file:// URL or has no path
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeModelURL:(NSURL *)modelURL model:(NSString *)model quantization:(NSString *)quantization completionHandler:(void (^)(LSDKLiquidEngine * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(modelURL:model:quantization:completionHandler:)")));
@end


/**
 * LiquidEngineRunner - Wrapper around LiquidInferenceEngineRunner with old API
 *
 * Provides the exact same API as the old iOS SDK's runner, including:
 * - createConversationFromHistory()
 * - getPromptTokensSize()
 * - unload()
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidEngineRunner")))
@interface LSDKLiquidEngineRunner : LSDKBase
@property (readonly) NSURL *modelURL __attribute__((swift_name("modelURL")));
- (instancetype)initWithRunner:(LSDKLiquidInferenceEngineRunner *)runner modelURL:(NSURL *)modelURL __attribute__((swift_name("init(runner:modelURL:)"))) __attribute__((objc_designated_initializer));

/**
 * Create a conversation from message history Matches:
 * runner.createConversationFromHistory(history:) from old iOS SDK
 */
- (LSDKLiquidConversation *)createConversationFromHistoryHistory:(NSArray<LSDKChatMessage *> *)history __attribute__((swift_name("createConversationFromHistory(history:)")));

/**
 * Get prompt tokens size for a list of messages Matches:
 * runner.getPromptTokensSize(messages:addBosToken:) from old iOS SDK
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPromptTokensSizeMessages:(NSArray<LSDKChatMessage *> *)messages addBosToken:(BOOL)addBosToken completionHandler:(void (^)(LSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPromptTokensSize(messages:addBosToken:completionHandler:)")));

/** Unload the model from memory Matches: runner.unload() from old iOS SDK
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)unloadWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("unload(completionHandler:)")));
@end


/**
 * Options for creating and configuring the inference engine when loading from a manifest URL.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineManifestOptions`.
 * It provides the same API surface as LiquidInferenceEngineOptions but without the bundlePath
 * field, since the model path is resolved from the manifest.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineManifestOptions(
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     nGpuLayers: 100
 * )
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidInferenceEngineManifestOptions")))
@interface LSDKLiquidInferenceEngineManifestOptions : LSDKBase
@property (readonly) BOOL audioDecoderUseGpu __attribute__((swift_name("audioDecoderUseGpu")));
@property (readonly) LSDKLiquidCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property (readonly) LSDKUInt * _Nullable contextSize __attribute__((swift_name("contextSize")));
@property (readonly) LSDKUInt * _Nullable cpuThreads __attribute__((swift_name("cpuThreads")));
@property (readonly) NSString * _Nullable extras __attribute__((swift_name("extras")));
@property (readonly) LSDKUInt * _Nullable nGpuLayers __attribute__((swift_name("nGpuLayers")));
- (instancetype)initWithCacheOptions:(LSDKLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LSDKUInt * _Nullable)cpuThreads contextSize:(LSDKUInt * _Nullable)contextSize nGpuLayers:(LSDKUInt * _Nullable)nGpuLayers audioDecoderUseGpu:(BOOL)audioDecoderUseGpu chatTemplate:(NSString * _Nullable)chatTemplate extras:(NSString * _Nullable)extras __attribute__((swift_name("init(cacheOptions:cpuThreads:contextSize:nGpuLayers:audioDecoderUseGpu:chatTemplate:extras:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidInferenceEngineManifestOptions *)doCopyCacheOptions:(LSDKLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LSDKUInt * _Nullable)cpuThreads contextSize:(LSDKUInt * _Nullable)contextSize nGpuLayers:(LSDKUInt * _Nullable)nGpuLayers audioDecoderUseGpu:(BOOL)audioDecoderUseGpu chatTemplate:(NSString * _Nullable)chatTemplate extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(cacheOptions:cpuThreads:contextSize:nGpuLayers:audioDecoderUseGpu:chatTemplate:extras:)")));

/**
 * Options for creating and configuring the inference engine when loading from a manifest URL.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineManifestOptions`.
 * It provides the same API surface as LiquidInferenceEngineOptions but without the bundlePath
 * field, since the model path is resolved from the manifest.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineManifestOptions(
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     nGpuLayers: 100
 * )
 * ```
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Options for creating and configuring the inference engine when loading from a manifest URL.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineManifestOptions`.
 * It provides the same API surface as LiquidInferenceEngineOptions but without the bundlePath
 * field, since the model path is resolved from the manifest.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineManifestOptions(
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     nGpuLayers: 100
 * )
 * ```
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Convert extras to GenerationTimeParameters if provided. */
- (LSDKGenerationTimeParameters * _Nullable)toGenerationTimeParameters __attribute__((swift_name("toGenerationTimeParameters()")));

/**
 * Convert to KMP ModelLoadingOptions.
 *
 * @throws IllegalArgumentException if validation fails
 */
- (LSDKModelLoadingOptions *)toModelLoadingOptions __attribute__((swift_name("toModelLoadingOptions()")));

/**
 * Options for creating and configuring the inference engine when loading from a manifest URL.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineManifestOptions`.
 * It provides the same API surface as LiquidInferenceEngineOptions but without the bundlePath
 * field, since the model path is resolved from the manifest.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineManifestOptions(
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     nGpuLayers: 100
 * )
 * ```
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** Whether to use GPU acceleration for audio decoder */

/** Optional cache configuration for inference engine */

/** Optional custom chat template override */

/** Context window size (sequence length) */

/** Number of CPU threads to use for inference */

/** Additional engine-specific configuration as JSON string */

/** Number of GPU layers to offload (iOS/macOS typically uses Metal) */
@end


/**
 * Options for creating and configuring the inference engine.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineOptions`. It
 * provides the same API surface for easy migration from the native iOS SDK.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineOptions(
 *     bundlePath: "/path/to/model.gguf",
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     mmProjPath: "/path/to/mmproj.gguf"
 * )
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidInferenceEngineOptions")))
@interface LSDKLiquidInferenceEngineOptions : LSDKBase
@property (readonly) NSString * _Nullable audioDecoderPath __attribute__((swift_name("audioDecoderPath")));
@property (readonly) BOOL audioDecoderUseGpu __attribute__((swift_name("audioDecoderUseGpu")));
@property (readonly) NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSString *bundlePath __attribute__((swift_name("bundlePath")));
@property (readonly) LSDKLiquidCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property (readonly) LSDKUInt * _Nullable contextSize __attribute__((swift_name("contextSize")));
@property (readonly) LSDKUInt * _Nullable cpuThreads __attribute__((swift_name("cpuThreads")));
@property (readonly) NSString * _Nullable extras __attribute__((swift_name("extras")));
@property (readonly) NSString * _Nullable mmProjPath __attribute__((swift_name("mmProjPath")));
@property (readonly) LSDKUInt * _Nullable nGpuLayers __attribute__((swift_name("nGpuLayers")));
- (instancetype)initWithBundlePath:(NSString *)bundlePath cacheOptions:(LSDKLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LSDKUInt * _Nullable)cpuThreads contextSize:(LSDKUInt * _Nullable)contextSize nGpuLayers:(LSDKUInt * _Nullable)nGpuLayers mmProjPath:(NSString * _Nullable)mmProjPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath chatTemplate:(NSString * _Nullable)chatTemplate audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath audioDecoderUseGpu:(BOOL)audioDecoderUseGpu extras:(NSString * _Nullable)extras __attribute__((swift_name("init(bundlePath:cacheOptions:cpuThreads:contextSize:nGpuLayers:mmProjPath:audioDecoderPath:chatTemplate:audioTokenizerPath:audioDecoderUseGpu:extras:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidInferenceEngineOptions *)doCopyBundlePath:(NSString *)bundlePath cacheOptions:(LSDKLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LSDKUInt * _Nullable)cpuThreads contextSize:(LSDKUInt * _Nullable)contextSize nGpuLayers:(LSDKUInt * _Nullable)nGpuLayers mmProjPath:(NSString * _Nullable)mmProjPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath chatTemplate:(NSString * _Nullable)chatTemplate audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath audioDecoderUseGpu:(BOOL)audioDecoderUseGpu extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(bundlePath:cacheOptions:cpuThreads:contextSize:nGpuLayers:mmProjPath:audioDecoderPath:chatTemplate:audioTokenizerPath:audioDecoderUseGpu:extras:)")));

/**
 * Options for creating and configuring the inference engine.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineOptions`. It
 * provides the same API surface for easy migration from the native iOS SDK.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineOptions(
 *     bundlePath: "/path/to/model.gguf",
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     mmProjPath: "/path/to/mmproj.gguf"
 * )
 * ```
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Options for creating and configuring the inference engine.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineOptions`. It
 * provides the same API surface for easy migration from the native iOS SDK.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineOptions(
 *     bundlePath: "/path/to/model.gguf",
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     mmProjPath: "/path/to/mmproj.gguf"
 * )
 * ```
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Convert extras to GenerationTimeParameters if provided. */
- (LSDKGenerationTimeParameters * _Nullable)toGenerationTimeParameters __attribute__((swift_name("toGenerationTimeParameters()")));

/**
 * Convert to KMP ModelLoadingOptions. Cache resolution lives in
 * `LiquidCacheOptions.toCacheOptions` so the iOS-shape opt-in chain stays in one place.
 */
- (LSDKModelLoadingOptions *)toModelLoadingOptions __attribute__((swift_name("toModelLoadingOptions()")));

/**
 * Options for creating and configuring the inference engine.
 *
 * This is a compatibility layer that matches the iOS SDK's `LiquidInferenceEngineOptions`. It
 * provides the same API surface for easy migration from the native iOS SDK.
 *
 * Usage:
 * ```swift
 * let options = LiquidInferenceEngineOptions(
 *     bundlePath: "/path/to/model.gguf",
 *     cpuThreads: 4,
 *     contextSize: 2048,
 *     mmProjPath: "/path/to/mmproj.gguf"
 * )
 * ```
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** Path to the audio decoder model for audio capabilities */

/** Whether to use GPU acceleration for audio decoder */

/** Path to the audio tokenizer model */

/** Path to the model bundle (the main .gguf file) */

/** Optional cache configuration for inference engine */

/** Optional custom chat template override */

/** Context window size (sequence length) */

/** Number of CPU threads to use for inference */

/** Additional engine-specific configuration as JSON string */

/** Path to the multimodal projection model for vision capabilities */

/** Number of GPU layers to offload (iOS/macOS typically uses Metal) */
@end


/**
 * Compatibility layer that mimics the iOS SDK's `LiquidInferenceEngineRunner` API.
 *
 * This class provides a drop-in replacement for code migrating from the native iOS SDK to the KMP
 * SDK.
 *
 * Usage:
 * ```swift
 * // From URL with options
 * let runner = try await LiquidInferenceEngineRunner.create(
 *     options: LiquidInferenceEngineOptions(bundlePath: "/path/to/model.gguf")
 * )
 *
 * // From model slug (downloads if needed)
 * let runner = try await LiquidInferenceEngineRunner.create(
 *     model: "Liquid-1.3B-Instruct",
 *     quantization: "Q4_K_M"
 * )
 * ```
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidInferenceEngineRunner")))
@interface LSDKLiquidInferenceEngineRunner : LSDKBase
@property (class, readonly, getter=companion) LSDKLiquidInferenceEngineRunnerCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *modelId __attribute__((swift_name("modelId")));

/**
 * Create a new conversation with an optional system prompt.
 *
 * @param systemPrompt Optional system prompt. If null, uses the model's default system prompt.
 * @return A new Conversation instance
 */
- (id<LSDKConversation>)createConversationSystemPrompt:(NSString * _Nullable)systemPrompt __attribute__((swift_name("createConversation(systemPrompt:)")));

/**
 * Create a conversation from existing chat history.
 *
 * @param history List of ChatMessage objects representing the conversation history
 * @return A new Conversation instance initialized with the given history
 */
- (id<LSDKConversation>)createConversationFromHistoryHistory:(NSArray<LSDKChatMessage *> *)history __attribute__((swift_name("createConversationFromHistory(history:)")));

/**
 * Get the number of tokens in a prompt.
 *
 * @param messages List of ChatMessage objects representing the prompt
 * @param addBosToken Whether to add the beginning-of-sequence token (default: true)
 * @return The number of tokens in the prompt
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPromptTokensSizeMessages:(NSArray<LSDKChatMessage *> *)messages addBosToken:(BOOL)addBosToken completionHandler:(void (^)(LSDKInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPromptTokensSize(messages:addBosToken:completionHandler:)")));

/**
 * Unload the model from memory.
 *
 * After calling this method, the runner and any conversations created from it cannot be used
 * anymore.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)unloadWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("unload(completionHandler:)")));

/** The model ID string. */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidInferenceEngineRunner.Companion")))
@interface LSDKLiquidInferenceEngineRunnerCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLiquidInferenceEngineRunnerCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Create a LiquidInferenceEngineRunner from options.
 *
 * @param options Configuration for model loading
 * @param generationTimeParameters Optional generation-time parameters (caller should get from
 *   manifest)
 * @return A LiquidInferenceEngineRunner instance ready for inference
 * @throws Exception if model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)createOptions:(LSDKLiquidInferenceEngineOptions *)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters completionHandler:(void (^)(LSDKLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(options:generationTimeParameters:completionHandler:)")));

/**
 * Create a LiquidInferenceEngineRunner by downloading a model from the Liquid AI model
 * registry.
 *
 * @param model The model slug (e.g., "Liquid-1.3B-Instruct")
 * @param quantization The quantization type (e.g., "Q4_K_M")
 * @param generationTimeParameters Optional generation-time parameters (defaults to manifest
 *   values)
 * @return A LiquidInferenceEngineRunner instance ready for inference
 * @throws Exception if model download or loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)createModel:(NSString *)model quantization:(NSString *)quantization generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters completionHandler:(void (^)(LSDKLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(model:quantization:generationTimeParameters:completionHandler:)")));

/**
 * Create a LiquidInferenceEngineRunner from a manifest URL with optional configuration and
 * download progress.
 *
 * @param manifestUrl The URL pointing to the manifest JSON file
 * @param options Optional configuration for model loading
 * @param downloadProgressHandler Optional callback for download progress (fraction,
 *   bytesPerSecond)
 * @return A LiquidInferenceEngineRunner instance ready for inference
 * @throws Exception if download or model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)createManifestUrl:(NSURL *)manifestUrl options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler completionHandler:(void (^)(LSDKLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(manifestUrl:options:downloadProgressHandler:completionHandler:)")));

/**
 * Create a LiquidInferenceEngineRunner by downloading a model from the Liquid AI model
 * registry, with download progress reporting.
 *
 * @param model The model slug (e.g., "Liquid-1.3B-Instruct")
 * @param quantization The quantization type (e.g., "Q4_K_M")
 * @param options Optional configuration for model loading
 * @param downloadProgressHandler Optional callback for download progress (fraction,
 *   bytesPerSecond)
 * @return A LiquidInferenceEngineRunner instance ready for inference
 * @throws Exception if model download or loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)createModel:(NSString *)model quantization:(NSString *)quantization options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler completionHandler:(void (^)(LSDKLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(model:quantization:options:downloadProgressHandler:completionHandler:)")));

/**
 * Create a LiquidInferenceEngineRunner from a file URL with optional configuration.
 *
 * This method automatically discovers companion files (mmproj, audio decoder) in the same
 * directory as the model file if they are not explicitly provided in options and auto-detection
 * is enabled (default).
 *
 * @param url The file URL pointing to the model file (.gguf)
 * @param options Optional configuration for model loading
 * @param generationTimeParameters Optional generation-time parameters (caller should get from
 *   manifest)
 * @param autoDetectCompanionFiles Whether to auto-detect companion files (default: true)
 * @return A LiquidInferenceEngineRunner instance ready for inference
 * @throws Exception if model loading fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)createUrl:(NSURL *)url options:(LSDKLiquidInferenceEngineOptions * _Nullable)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles completionHandler:(void (^)(LSDKLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(url:options:generationTimeParameters:autoDetectCompanionFiles:completionHandler:)")));
@end


/**
 * LiquidMessageResponse - Sealed class hierarchy for Swift switch statements
 *
 * This sealed class hierarchy exports to Swift as a class hierarchy that can be exhaustively
 * switched over, providing type-safe pattern matching for message responses.
 *
 * Usage in Swift:
 * ```swift
 * for try await event in stream {
 *     switch event {
 *     case let chunk as LiquidMessageResponse.Chunk:
 *         print(chunk.delta)
 *     case let reasoning as LiquidMessageResponse.ReasoningChunk:
 *         print(reasoning.delta)
 *     case let audio as LiquidMessageResponse.AudioSample:
 *         playAudio(audio.samples, audio.sampleRate)
 *     case is LiquidMessageResponse.FunctionCall:
 *         break
 *     case is LiquidMessageResponse.Complete:
 *         print("Done")
 *     default:
 *         break
 *     }
 * }
 * ```
 */
__attribute__((swift_name("LiquidMessageResponse")))
@interface LSDKLiquidMessageResponse : LSDKBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.AudioSample")))
@interface LSDKLiquidMessageResponseAudioSample : LSDKLiquidMessageResponse
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@property (readonly) NSArray<LSDKFloat *> *samples __attribute__((swift_name("samples")));
- (instancetype)initWithSamples:(NSArray<LSDKFloat *> *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("init(samples:sampleRate:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidMessageResponseAudioSample *)doCopySamples:(NSArray<LSDKFloat *> *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("doCopy(samples:sampleRate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.Chunk")))
@interface LSDKLiquidMessageResponseChunk : LSDKLiquidMessageResponse
@property (readonly) NSString *delta __attribute__((swift_name("delta")));
- (instancetype)initWithDelta:(NSString *)delta __attribute__((swift_name("init(delta:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidMessageResponseChunk *)doCopyDelta:(NSString *)delta __attribute__((swift_name("doCopy(delta:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.Complete")))
@interface LSDKLiquidMessageResponseComplete : LSDKLiquidMessageResponse
@property (readonly) LSDKGenerationFinishReason *finishReason __attribute__((swift_name("finishReason")));
@property (readonly) LSDKChatMessage *fullMessage __attribute__((swift_name("fullMessage")));
@property (readonly) LSDKGenerationStats * _Nullable stats __attribute__((swift_name("stats")));
- (instancetype)initWithFullMessage:(LSDKChatMessage *)fullMessage finishReason:(LSDKGenerationFinishReason *)finishReason stats:(LSDKGenerationStats * _Nullable)stats __attribute__((swift_name("init(fullMessage:finishReason:stats:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidMessageResponseComplete *)doCopyFullMessage:(LSDKChatMessage *)fullMessage finishReason:(LSDKGenerationFinishReason *)finishReason stats:(LSDKGenerationStats * _Nullable)stats __attribute__((swift_name("doCopy(fullMessage:finishReason:stats:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.FunctionCall")))
@interface LSDKLiquidMessageResponseFunctionCall : LSDKLiquidMessageResponse
@property (readonly) NSString *arguments __attribute__((swift_name("arguments")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
- (instancetype)initWithName:(NSString *)name arguments:(NSString *)arguments __attribute__((swift_name("init(name:arguments:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidMessageResponseFunctionCall *)doCopyName:(NSString *)name arguments:(NSString *)arguments __attribute__((swift_name("doCopy(name:arguments:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.ReasoningChunk")))
@interface LSDKLiquidMessageResponseReasoningChunk : LSDKLiquidMessageResponse
@property (readonly) NSString *delta __attribute__((swift_name("delta")));
- (instancetype)initWithDelta:(NSString *)delta __attribute__((swift_name("init(delta:)"))) __attribute__((objc_designated_initializer));
- (LSDKLiquidMessageResponseReasoningChunk *)doCopyDelta:(NSString *)delta __attribute__((swift_name("doCopy(delta:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Sealed serializable representation of function argument values.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/function/FunctionArgSerializer))
*/
__attribute__((swift_name("FunctionArg")))
@protocol LSDKFunctionArg
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FunctionArgCompanion")))
@interface LSDKFunctionArgCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKFunctionArgCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKFunctionArg>)fromAnyValue:(id _Nullable)value __attribute__((swift_name("fromAny(value:)")));
- (id<LSDKFunctionArg>)fromJsonElementElement:(LSDKKotlinx_serialization_jsonJsonElement *)element __attribute__((swift_name("fromJsonElement(element:)")));
- (NSDictionary<NSString *, id<LSDKFunctionArg>> *)mapFromAnyMapMap:(NSDictionary<NSString *, id> *)map __attribute__((swift_name("mapFromAnyMap(map:)")));
- (NSDictionary<NSString *, id<LSDKFunctionArg>> *)mapFromJsonObjectObj:(NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)obj __attribute__((swift_name("mapFromJsonObject(obj:)")));
- (NSDictionary<NSString *, id> *)mapToAnyMapMap:(NSDictionary<NSString *, id<LSDKFunctionArg>> *)map __attribute__((swift_name("mapToAnyMap(map:)")));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)mapToJsonObjectMap:(NSDictionary<NSString *, id<LSDKFunctionArg>> *)map __attribute__((swift_name("mapToJsonObject(map:)")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
- (id _Nullable)toAnyValue:(id<LSDKFunctionArg>)value __attribute__((swift_name("toAny(value:)")));
- (LSDKKotlinx_serialization_jsonJsonElement *)toJsonElementValue:(id<LSDKFunctionArg>)value __attribute__((swift_name("toJsonElement(value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol LSDKKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol LSDKKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol LSDKKotlinx_serialization_coreKSerializer <LSDKKotlinx_serialization_coreSerializationStrategy, LSDKKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FunctionArgSerializer")))
@interface LSDKFunctionArgSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKFunctionArgSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)functionArgSerializer __attribute__((swift_name("init()")));
- (id<LSDKFunctionArg>)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(id<LSDKFunctionArg>)value __attribute__((swift_name("serialize(encoder:value:)")));
@end


/**
 * Abstract class to describe a function call parser in Leap.
 *
 * @param toolCallStartToken The token indicates the start of the function call request content
 * @param toolCallEndToken The token indicates the end of the function call request content
 */
__attribute__((swift_name("LeapFunctionCallParser")))
@interface LSDKLeapFunctionCallParser : LSDKBase
@property LSDKKotlinStringBuilder *buffer __attribute__((swift_name("buffer")));
@property (readonly) NSString *toolCallEndToken __attribute__((swift_name("toolCallEndToken")));
@property (readonly) NSString *toolCallStartToken __attribute__((swift_name("toolCallStartToken")));
- (instancetype)initWithToolCallStartToken:(NSString *)toolCallStartToken toolCallEndToken:(NSString *)toolCallEndToken __attribute__((swift_name("init(toolCallStartToken:toolCallEndToken:)"))) __attribute__((objc_designated_initializer));

/** Append a chunk into the buffer of the parser. */
- (void)appendChunk:(NSString *)chunk __attribute__((swift_name("append(chunk:)")));

/** Clear the buffer of the parser. */
- (void)clear __attribute__((swift_name("clear()")));
- (NSString *)dumpFunctionCalls:(NSArray<LSDKLeapFunctionCall *> *)functionCalls __attribute__((swift_name("dump(functionCalls:)")));

/** Parse the content in the buffer and clear the buffer. */
- (NSArray<LSDKLeapFunctionCall *> *)parse __attribute__((swift_name("parse()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@end


/**
 * Function call parsers for models that are using
 * [Hermes function calling format](https://github.com/NousResearch/Hermes-Function-Calling). For
 * example, Qwen3 models.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HermesFunctionCallParser")))
@interface LSDKHermesFunctionCallParser : LSDKLeapFunctionCallParser

/**
 * Function call parsers for models that are using
 * [Hermes function calling format](https://github.com/NousResearch/Hermes-Function-Calling). For
 * example, Qwen3 models.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Function call parsers for models that are using
 * [Hermes function calling format](https://github.com/NousResearch/Hermes-Function-Calling). For
 * example, Qwen3 models.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithToolCallStartToken:(NSString *)toolCallStartToken toolCallEndToken:(NSString *)toolCallEndToken __attribute__((swift_name("init(toolCallStartToken:toolCallEndToken:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (NSString *)dumpFunctionCalls:(NSArray<LSDKLeapFunctionCall *> *)functionCalls __attribute__((swift_name("dump(functionCalls:)")));
- (NSArray<LSDKLeapFunctionCall *> *)parse __attribute__((swift_name("parse()")));
@end


/** Function call parsers for Liquid Foundation Models (LFM2). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LFMFunctionCallParser")))
@interface LSDKLFMFunctionCallParser : LSDKLeapFunctionCallParser

/** Function call parsers for Liquid Foundation Models (LFM2). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Function call parsers for Liquid Foundation Models (LFM2). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithToolCallStartToken:(NSString *)toolCallStartToken toolCallEndToken:(NSString *)toolCallEndToken __attribute__((swift_name("init(toolCallStartToken:toolCallEndToken:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (NSString *)dumpFunctionCalls:(NSArray<LSDKLeapFunctionCall *> *)functionCalls __attribute__((swift_name("dump(functionCalls:)")));
- (NSArray<LSDKLeapFunctionCall *> *)parse __attribute__((swift_name("parse()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapArr")))
@interface LSDKLeapArr : LSDKBase <LSDKFunctionArg>
@property (class, readonly, getter=companion) LSDKLeapArrCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSArray<id<LSDKFunctionArg>> *value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(NSArray<id<LSDKFunctionArg>> *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapArr *)doCopyValue:(NSArray<id<LSDKFunctionArg>> *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapArr.Companion")))
@interface LSDKLeapArrCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapArrCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapBool")))
@interface LSDKLeapBool : LSDKBase <LSDKFunctionArg>
@property (class, readonly, getter=companion) LSDKLeapBoolCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(BOOL)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapBool *)doCopyValue:(BOOL)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapBool.Companion")))
@interface LSDKLeapBoolCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapBoolCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Describe the signature of a function that can be called by the model.
 *
 * @param name name of the function
 * @param description human-readable / LLM-readable description of the function
 * @param parameters list of parameters that accepted by the function
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunction")))
@interface LSDKLeapFunction : LSDKBase
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSArray<LSDKLeapFunctionParameter *> *parameters __attribute__((swift_name("parameters")));
- (instancetype)initWithName:(NSString *)name functionDescription:(NSString *)functionDescription parameters:(NSArray<LSDKLeapFunctionParameter *> *)parameters __attribute__((swift_name("init(name:functionDescription:parameters:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunction *)doCopyName:(NSString *)name functionDescription:(NSString *)functionDescription parameters:(NSArray<LSDKLeapFunctionParameter *> *)parameters __attribute__((swift_name("doCopy(name:functionDescription:parameters:)")));

/**
 * Describe the signature of a function that can be called by the model.
 *
 * @param name name of the function
 * @param description human-readable / LLM-readable description of the function
 * @param parameters list of parameters that accepted by the function
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Describe the signature of a function that can be called by the model.
 *
 * @param name name of the function
 * @param description human-readable / LLM-readable description of the function
 * @param parameters list of parameters that accepted by the function
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Create a JsonObject representation of this function.
 *
 * Args: `withToolTypeWrapper`: whether to wrap the function with a type declaration for common
 * tool calling APIs
 */
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObjectWithToolTypeWrapper:(BOOL)withToolTypeWrapper __attribute__((swift_name("toJsonObject(withToolTypeWrapper:)")));

/**
 * Describe the signature of a function that can be called by the model.
 *
 * @param name name of the function
 * @param description human-readable / LLM-readable description of the function
 * @param parameters list of parameters that accepted by the function
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/function/LeapFunctionCallSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionCall")))
@interface LSDKLeapFunctionCall : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapFunctionCallCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSDictionary<NSString *, id> *arguments __attribute__((swift_name("arguments")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
- (instancetype)initWithName:(NSString *)name arguments:(NSDictionary<NSString *, id> *)arguments __attribute__((swift_name("init(name:arguments:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionCall *)doCopyName:(NSString *)name arguments:(NSDictionary<NSString *, id> *)arguments __attribute__((swift_name("doCopy(name:arguments:)")));

/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionCall.Companion")))
@interface LSDKLeapFunctionCallCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionCallCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionCallSerializer")))
@interface LSDKLeapFunctionCallSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKLeapFunctionCallSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapFunctionCallSerializer __attribute__((swift_name("init()")));
- (LSDKLeapFunctionCall *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(LSDKLeapFunctionCall *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end


/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionDto")))
@interface LSDKLeapFunctionDto : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapFunctionDtoCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSArray<LSDKLeapFunctionParameterDto *> *parameters __attribute__((swift_name("parameters")));
- (instancetype)initWithName:(NSString *)name description:(NSString *)description parameters:(NSArray<LSDKLeapFunctionParameterDto *> *)parameters __attribute__((swift_name("init(name:description:parameters:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionDto *)doCopyName:(NSString *)name description:(NSString *)description parameters:(NSArray<LSDKLeapFunctionParameterDto *> *)parameters __attribute__((swift_name("doCopy(name:description:parameters:)")));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionDto.Companion")))
@interface LSDKLeapFunctionDtoCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionDtoCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Describe the signature of a parameter that can be called by the model.
 *
 * @param name name of the parameter
 * @param type data type of the parameter
 * @param description human-readable / LLM-readable description of the function
 * @param optional whether the parameter is optional
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameter")))
@interface LSDKLeapFunctionParameter : LSDKBase
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) BOOL optional __attribute__((swift_name("optional")));
@property (readonly) LSDKLeapFunctionParameterType *type __attribute__((swift_name("type")));
- (instancetype)initWithName:(NSString *)name type:(LSDKLeapFunctionParameterType *)type parameterDescription:(NSString *)parameterDescription optional:(BOOL)optional __attribute__((swift_name("init(name:type:parameterDescription:optional:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameter *)doCopyName:(NSString *)name type:(LSDKLeapFunctionParameterType *)type parameterDescription:(NSString *)parameterDescription optional:(BOOL)optional __attribute__((swift_name("doCopy(name:type:parameterDescription:optional:)")));

/**
 * Describe the signature of a parameter that can be called by the model.
 *
 * @param name name of the parameter
 * @param type data type of the parameter
 * @param description human-readable / LLM-readable description of the function
 * @param optional whether the parameter is optional
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Describe the signature of a parameter that can be called by the model.
 *
 * @param name name of the parameter
 * @param type data type of the parameter
 * @param description human-readable / LLM-readable description of the function
 * @param optional whether the parameter is optional
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Describe the signature of a parameter that can be called by the model.
 *
 * @param name name of the parameter
 * @param type data type of the parameter
 * @param description human-readable / LLM-readable description of the function
 * @param optional whether the parameter is optional
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Serializable mirror of [LeapFunctionParameter].
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterDto")))
@interface LSDKLeapFunctionParameterDto : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterDtoCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) BOOL optional __attribute__((swift_name("optional")));
@property (readonly) LSDKLeapFunctionParameterTypeDto *type __attribute__((swift_name("type")));
- (instancetype)initWithName:(NSString *)name type:(LSDKLeapFunctionParameterTypeDto *)type description:(NSString *)description optional:(BOOL)optional __attribute__((swift_name("init(name:type:description:optional:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterDto *)doCopyName:(NSString *)name type:(LSDKLeapFunctionParameterTypeDto *)type description:(NSString *)description optional:(BOOL)optional __attribute__((swift_name("doCopy(name:type:description:optional:)")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Serializable mirror of [LeapFunctionParameter]. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterDto.Companion")))
@interface LSDKLeapFunctionParameterDtoCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterDtoCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** Serializable mirror of [LeapFunctionParameter]. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Represent a type that can be used for the parameters of Leap functions. All types declared must
 * be allowed in JSON Schema.
 *
 * @param description an optional, human-readable and LLM-readable description of this type
 */
__attribute__((swift_name("LeapFunctionParameterType")))
@interface LSDKLeapFunctionParameterType : LSDKBase
@property (readonly) NSString * _Nullable typeDescription __attribute__((swift_name("typeDescription")));

/** Create a JsonObject representation of this type, which will be consumed by LLM */
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapArr type. `itemType` indicates the type of its element. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapArr")))
@interface LSDKLeapFunctionParameterTypeLeapArr : LSDKLeapFunctionParameterType
@property (readonly) LSDKLeapFunctionParameterType *itemType __attribute__((swift_name("itemType")));
- (instancetype)initWithItemType:(LSDKLeapFunctionParameterType *)itemType description:(NSString * _Nullable)description __attribute__((swift_name("init(itemType:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapBool literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapBool")))
@interface LSDKLeapFunctionParameterTypeLeapBool : LSDKLeapFunctionParameterType
- (instancetype)initWithDescription:(NSString * _Nullable)description __attribute__((swift_name("init(description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapInt literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapInt")))
@interface LSDKLeapFunctionParameterTypeLeapInt : LSDKLeapFunctionParameterType
@property (readonly) NSArray<LSDKInt *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
- (instancetype)initWithEnumValues:(NSArray<LSDKInt *> * _Nullable)enumValues description:(NSString * _Nullable)description __attribute__((swift_name("init(enumValues:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapNull type: only null value is accepted. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapNull")))
@interface LSDKLeapFunctionParameterTypeLeapNull : LSDKLeapFunctionParameterType

/** LeapNull type: only null value is accepted. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** LeapNull type: only null value is accepted. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapNum literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapNum")))
@interface LSDKLeapFunctionParameterTypeLeapNum : LSDKLeapFunctionParameterType
@property (readonly) NSArray<id> * _Nullable enumValues __attribute__((swift_name("enumValues")));
- (instancetype)initWithEnumValues:(NSArray<id> * _Nullable)enumValues description:(NSString * _Nullable)description __attribute__((swift_name("init(enumValues:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/**
 * LeapObj type.
 *
 * @param properties map of property names to their types
 * @param required list of required property names
 * @param description optional description text for LLM to understand the effect of this parameter
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapObj")))
@interface LSDKLeapFunctionParameterTypeLeapObj : LSDKLeapFunctionParameterType
@property (readonly) NSDictionary<NSString *, LSDKLeapFunctionParameterType *> *properties __attribute__((swift_name("properties")));
@property (readonly) NSArray<NSString *> *required __attribute__((swift_name("required")));
- (instancetype)initWithProperties:(NSDictionary<NSString *, LSDKLeapFunctionParameterType *> *)properties required:(NSArray<NSString *> *)required description:(NSString * _Nullable)description __attribute__((swift_name("init(properties:required:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapStr literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapStr")))
@interface LSDKLeapFunctionParameterTypeLeapStr : LSDKLeapFunctionParameterType
@property (readonly) NSArray<NSString *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
- (instancetype)initWithEnumValues:(NSArray<NSString *> * _Nullable)enumValues description:(NSString * _Nullable)description __attribute__((swift_name("init(enumValues:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("LeapFunctionParameterTypeDto")))
@interface LSDKLeapFunctionParameterTypeDto : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="arr")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Arr")))
@interface LSDKLeapFunctionParameterTypeDtoArr : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoArrCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) LSDKLeapFunctionParameterTypeDto *itemType __attribute__((swift_name("itemType")));
- (instancetype)initWithDescription:(NSString * _Nullable)description itemType:(LSDKLeapFunctionParameterTypeDto *)itemType __attribute__((swift_name("init(description:itemType:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoArr *)doCopyDescription:(NSString * _Nullable)description itemType:(LSDKLeapFunctionParameterTypeDto *)itemType __attribute__((swift_name("doCopy(description:itemType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.ArrCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoArrCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoArrCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="bool")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Bool")))
@interface LSDKLeapFunctionParameterTypeDtoBool : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoBoolCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
- (instancetype)initWithDescription:(NSString * _Nullable)description __attribute__((swift_name("init(description:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoBool *)doCopyDescription:(NSString * _Nullable)description __attribute__((swift_name("doCopy(description:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.BoolCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoBoolCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoBoolCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Companion")))
@interface LSDKLeapFunctionParameterTypeDtoCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));

/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="int")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.IntType")))
@interface LSDKLeapFunctionParameterTypeDtoIntType : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoIntTypeCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSArray<LSDKInt *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
- (instancetype)initWithDescription:(NSString * _Nullable)description enumValues:(NSArray<LSDKInt *> * _Nullable)enumValues __attribute__((swift_name("init(description:enumValues:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoIntType *)doCopyDescription:(NSString * _Nullable)description enumValues:(NSArray<LSDKInt *> * _Nullable)enumValues __attribute__((swift_name("doCopy(description:enumValues:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.IntTypeCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoIntTypeCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoIntTypeCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="null")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.NullType")))
@interface LSDKLeapFunctionParameterTypeDtoNullType : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoNullTypeCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
- (instancetype)initWithDescription:(NSString * _Nullable)description __attribute__((swift_name("init(description:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoNullType *)doCopyDescription:(NSString * _Nullable)description __attribute__((swift_name("doCopy(description:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.NullTypeCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoNullTypeCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoNullTypeCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="num")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Num")))
@interface LSDKLeapFunctionParameterTypeDtoNum : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoNumCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSArray<LSDKDouble *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
- (instancetype)initWithDescription:(NSString * _Nullable)description enumValues:(NSArray<LSDKDouble *> * _Nullable)enumValues __attribute__((swift_name("init(description:enumValues:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoNum *)doCopyDescription:(NSString * _Nullable)description enumValues:(NSArray<LSDKDouble *> * _Nullable)enumValues __attribute__((swift_name("doCopy(description:enumValues:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.NumCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoNumCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoNumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="obj")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Obj")))
@interface LSDKLeapFunctionParameterTypeDtoObj : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoObjCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSDictionary<NSString *, LSDKLeapFunctionParameterTypeDto *> *properties __attribute__((swift_name("properties")));
@property (readonly) NSArray<NSString *> *required __attribute__((swift_name("required")));
- (instancetype)initWithDescription:(NSString * _Nullable)description properties:(NSDictionary<NSString *, LSDKLeapFunctionParameterTypeDto *> *)properties required:(NSArray<NSString *> *)required __attribute__((swift_name("init(description:properties:required:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoObj *)doCopyDescription:(NSString * _Nullable)description properties:(NSDictionary<NSString *, LSDKLeapFunctionParameterTypeDto *> *)properties required:(NSArray<NSString *> *)required __attribute__((swift_name("doCopy(description:properties:required:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.ObjCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoObjCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoObjCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="str")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Str")))
@interface LSDKLeapFunctionParameterTypeDtoStr : LSDKLeapFunctionParameterTypeDto
@property (class, readonly, getter=companion) LSDKLeapFunctionParameterTypeDtoStrCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSArray<NSString *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
- (instancetype)initWithDescription:(NSString * _Nullable)description enumValues:(NSArray<NSString *> * _Nullable)enumValues __attribute__((swift_name("init(description:enumValues:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapFunctionParameterTypeDtoStr *)doCopyDescription:(NSString * _Nullable)description enumValues:(NSArray<NSString *> * _Nullable)enumValues __attribute__((swift_name("doCopy(description:enumValues:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.StrCompanion")))
@interface LSDKLeapFunctionParameterTypeDtoStrCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapFunctionParameterTypeDtoStrCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNull")))
@interface LSDKLeapNull : LSDKBase <LSDKFunctionArg>
@property (class, readonly, getter=shared) LSDKLeapNull *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapNull __attribute__((swift_name("init()")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("LeapNum")))
@interface LSDKLeapNum : LSDKBase <LSDKFunctionArg>
@property (class, readonly, getter=companion) LSDKLeapNumCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.Companion")))
@interface LSDKLeapNumCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapNumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.DoubleNum")))
@interface LSDKLeapNumDoubleNum : LSDKLeapNum
@property (class, readonly, getter=companion) LSDKLeapNumDoubleNumCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) double value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(double)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapNumDoubleNum *)doCopyValue:(double)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.DoubleNumCompanion")))
@interface LSDKLeapNumDoubleNumCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapNumDoubleNumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.IntNum")))
@interface LSDKLeapNumIntNum : LSDKLeapNum
@property (class, readonly, getter=companion) LSDKLeapNumIntNumCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(int32_t)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapNumIntNum *)doCopyValue:(int32_t)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.IntNumCompanion")))
@interface LSDKLeapNumIntNumCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapNumIntNumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.LongNum")))
@interface LSDKLeapNumLongNum : LSDKLeapNum
@property (class, readonly, getter=companion) LSDKLeapNumLongNumCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int64_t value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(int64_t)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapNumLongNum *)doCopyValue:(int64_t)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.LongNumCompanion")))
@interface LSDKLeapNumLongNumCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapNumLongNumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapObj")))
@interface LSDKLeapObj : LSDKBase <LSDKFunctionArg>
@property (class, readonly, getter=companion) LSDKLeapObjCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSDictionary<NSString *, id<LSDKFunctionArg>> *value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(NSDictionary<NSString *, id<LSDKFunctionArg>> *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapObj *)doCopyValue:(NSDictionary<NSString *, id<LSDKFunctionArg>> *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapObj.Companion")))
@interface LSDKLeapObjCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapObjCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapStr")))
@interface LSDKLeapStr : LSDKBase <LSDKFunctionArg>
@property (class, readonly, getter=companion) LSDKLeapStrCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapStr *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapStr.Companion")))
@interface LSDKLeapStrCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapStrCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicDumper")))
@interface LSDKPythonicDumper : LSDKBase
@property (class, readonly, getter=shared) LSDKPythonicDumper *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pythonicDumper __attribute__((swift_name("init()")));

/**
 * Serialize the function calls into Pythnoic format. The input should be created by
 * [PythonicParser]. Otherwise, the return value could be invalid.
 */
- (NSString *)dumpFunctionCallsCalls:(NSArray<LSDKLeapFunctionCall *> *)calls __attribute__((swift_name("dumpFunctionCalls(calls:)")));
@end


/**
 * Parser for Pythonic tool call requests generated by the models. Details of the Pythonic tool call
 * format can be found at
 * https://docs.vllm.ai/en/latest/features/tool_calling.html#models-with-pythonic-tool-calls-pythonic
 *
 * Supported features are:
 * 1. A list of function call
 * 2. Named parameters
 * 3. LeapStr, number (int and double), boolean and null as primitive types
 * 4. Nested lists and objects of any types as parameters
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicParser")))
@interface LSDKPythonicParser : LSDKBase
- (instancetype)initWithBuffer:(NSString *)buffer __attribute__((swift_name("init(buffer:)"))) __attribute__((objc_designated_initializer));

/**
 * Parse the Pythonic function call requests and return a list of [LeapFunctionCall] objects as
 * the result.
 *
 * This function can only be called once because it will mutate the parser internal states.
 */
- (NSArray<LSDKLeapFunctionCall *> *)parsePythonicCalls __attribute__((swift_name("parsePythonicCalls()")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface LSDKKotlinRuntimeException : LSDKKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Errors on syntax in Pythonic function call codes, emitted by the parser */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicSyntaxError")))
@interface LSDKPythonicSyntaxError : LSDKKotlinRuntimeException
@property (readonly) int32_t pos __attribute__((swift_name("pos")));
@property (readonly) NSString *reason __attribute__((swift_name("reason")));
- (instancetype)initWithPos:(int32_t)pos reason:(NSString *)reason __attribute__((swift_name("init(pos:reason:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/** Data class of a recognized token. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicToken")))
@interface LSDKPythonicToken : LSDKBase
@property (readonly) LSDKPythonicTokenName *name __attribute__((swift_name("name")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
- (instancetype)initWithName:(LSDKPythonicTokenName *)name text:(NSString *)text __attribute__((swift_name("init(name:text:)"))) __attribute__((objc_designated_initializer));
- (LSDKPythonicToken *)doCopyName:(LSDKPythonicTokenName *)name text:(NSString *)text __attribute__((swift_name("doCopy(name:text:)")));

/** Data class of a recognized token. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Data class of a recognized token. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Data class of a recognized token. */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Name/type of the token. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicTokenName")))
@interface LSDKPythonicTokenName : LSDKKotlinEnum<LSDKPythonicTokenName *>
@property (class, readonly) LSDKPythonicTokenName *leftSquareBracket __attribute__((swift_name("leftSquareBracket")));
@property (class, readonly) LSDKPythonicTokenName *rightSquareBracket __attribute__((swift_name("rightSquareBracket")));
@property (class, readonly) LSDKPythonicTokenName *leftParentheses __attribute__((swift_name("leftParentheses")));
@property (class, readonly) LSDKPythonicTokenName *rightParentheses __attribute__((swift_name("rightParentheses")));
@property (class, readonly) LSDKPythonicTokenName *leftCurlyBracket __attribute__((swift_name("leftCurlyBracket")));
@property (class, readonly) LSDKPythonicTokenName *rightCurlyBracket __attribute__((swift_name("rightCurlyBracket")));
@property (class, readonly) LSDKPythonicTokenName *colon __attribute__((swift_name("colon")));
@property (class, readonly) LSDKPythonicTokenName *comma __attribute__((swift_name("comma")));
@property (class, readonly) LSDKPythonicTokenName *equal __attribute__((swift_name("equal")));
@property (class, readonly) LSDKPythonicTokenName *identifier __attribute__((swift_name("identifier")));
@property (class, readonly) LSDKPythonicTokenName *numberLiteral __attribute__((swift_name("numberLiteral")));
@property (class, readonly) LSDKPythonicTokenName *stringLiteral __attribute__((swift_name("stringLiteral")));
@property (class, readonly) LSDKPythonicTokenName *space __attribute__((swift_name("space")));
@property (class, readonly) NSArray<LSDKPythonicTokenName *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));

/** Name/type of the token. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKPythonicTokenName *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((swift_name("KotlinIterable")))
@protocol LSDKKotlinIterable
@required
- (id<LSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end


/**
 * Tokenizer to tokenize Pythonic function call code generated by the model.
 *
 * It is used by [PythonicParser] and it should not be used directly by the external code.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicTokenizer")))
@interface LSDKPythonicTokenizer : LSDKBase <LSDKKotlinIterable>
@property (readonly) int32_t currentPosition __attribute__((swift_name("currentPosition")));
@property (readonly) BOOL hasNextToken __attribute__((swift_name("hasNextToken")));
- (instancetype)initWithBuffer:(NSString *)buffer __attribute__((swift_name("init(buffer:)"))) __attribute__((objc_designated_initializer));
- (id<LSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));

/**
 * @note This method converts instances of PythonicSyntaxError to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (LSDKPythonicToken * _Nullable)nextTokenAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("nextToken()"))) __attribute__((swift_error(nonnull_error)));
@end


/** Internal bundle config data representation. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BundleConfig")))
@interface LSDKBundleConfig : LSDKBase
@property (class, readonly, getter=companion) LSDKBundleConfigCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKSamplerParams * _Nullable samplerParams __attribute__((swift_name("samplerParams")));
@property (readonly) NSString * _Nullable systemMessage __attribute__((swift_name("systemMessage")));
- (instancetype)initWithSystemMessage:(NSString * _Nullable)systemMessage samplerParams:(LSDKSamplerParams * _Nullable)samplerParams __attribute__((swift_name("init(systemMessage:samplerParams:)"))) __attribute__((objc_designated_initializer));
- (LSDKBundleConfig *)doCopySystemMessage:(NSString * _Nullable)systemMessage samplerParams:(LSDKSamplerParams * _Nullable)samplerParams __attribute__((swift_name("doCopy(systemMessage:samplerParams:)")));

/** Internal bundle config data representation. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Internal bundle config data representation. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Internal bundle config data representation. */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BundleConfig.Companion")))
@interface LSDKBundleConfigCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKBundleConfigCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Parse an YAML string to create the bundle config object. */
- (id _Nullable)parseRaw:(NSString *)raw __attribute__((swift_name("parse(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Constraints")))
@interface LSDKConstraints : LSDKBase
@property (class, readonly, getter=companion) LSDKConstraintsCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *json __attribute__((swift_name("json")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Constraints.Companion")))
@interface LSDKConstraintsCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKConstraintsCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (LSDKConstraints *)fromJsonJson:(NSString *)json __attribute__((swift_name("fromJson(json:)")));
@end


/** Native implementation of Engine using C interop. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Engine")))
@interface LSDKEngine : LSDKBase
@property (class, readonly, getter=companion) LSDKEngineCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable modelId __attribute__((swift_name("modelId")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (LSDKGenerationStopReason *)generateMessages:(NSArray<LSDKMessage *> *)messages options:(LSDKGenerateOptions *)options __attribute__((swift_name("generate(messages:options:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Engine.Companion")))
@interface LSDKEngineCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKEngineCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (LSDKEngine *)createFromOptionsOptions:(LSDKEngineOptions *)options __attribute__((swift_name("createFromOptions(options:)")));
@end


/** Native implementation of EngineOptions. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineOptions")))
@interface LSDKEngineOptions : LSDKBase
@property NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSString *bundlePath __attribute__((swift_name("bundlePath")));
@property LSDKEngineOptionsCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));
@property NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property LSDKInt * _Nullable contextSize __attribute__((swift_name("contextSize")));
@property LSDKInt * _Nullable cpuThreads __attribute__((swift_name("cpuThreads")));
@property NSString * _Nullable extras __attribute__((swift_name("extras")));
@property LSDKInt * _Nullable imageMaxTokens __attribute__((swift_name("imageMaxTokens")));
@property LSDKInt * _Nullable imageMinTokens __attribute__((swift_name("imageMinTokens")));
@property NSString * _Nullable mmprojPath __attribute__((swift_name("mmprojPath")));
@property NSString * _Nullable modelAudioDecoderPath __attribute__((swift_name("modelAudioDecoderPath")));
@property LSDKLong * _Nullable rngSeed __attribute__((swift_name("rngSeed")));
- (instancetype)initWithBundlePath:(NSString *)bundlePath __attribute__((swift_name("init(bundlePath:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineOptions.CacheOptions")))
@interface LSDKEngineOptionsCacheOptions : LSDKBase
@property (readonly) BOOL diskDisabled __attribute__((swift_name("diskDisabled")));
@property (readonly) BOOL enabled __attribute__((swift_name("enabled")));
@property (readonly) int64_t maxBytesMemory __attribute__((swift_name("maxBytesMemory")));
@property (readonly) int32_t maxEntries __attribute__((swift_name("maxEntries")));
@property (readonly) int32_t maxEntriesDisk __attribute__((swift_name("maxEntriesDisk")));
@property (readonly) int32_t maxEntriesMemory __attribute__((swift_name("maxEntriesMemory")));
@property (readonly) NSString *path __attribute__((swift_name("path")));
- (instancetype)initWithPath:(NSString *)path maxEntries:(int32_t)maxEntries enabled:(BOOL)enabled maxEntriesDisk:(int32_t)maxEntriesDisk maxEntriesMemory:(int32_t)maxEntriesMemory maxBytesMemory:(int64_t)maxBytesMemory diskDisabled:(BOOL)diskDisabled __attribute__((swift_name("init(path:maxEntries:enabled:maxEntriesDisk:maxEntriesMemory:maxBytesMemory:diskDisabled:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerateOptions")))
@interface LSDKGenerateOptions : LSDKBase
@property id<LSDKGenerateOptionsTokenCallback> _Nullable callback __attribute__((swift_name("callback")));
@property LSDKConstraints * _Nullable constraints __attribute__((swift_name("constraints")));
@property LSDKSamplerParams * _Nullable samplerParams __attribute__((swift_name("samplerParams")));
- (instancetype)initWithSamplerParams:(LSDKSamplerParams * _Nullable)samplerParams constraints:(LSDKConstraints * _Nullable)constraints callback:(id<LSDKGenerateOptionsTokenCallback> _Nullable)callback __attribute__((swift_name("init(samplerParams:constraints:callback:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("GenerateOptionsTokenCallback")))
@protocol LSDKGenerateOptionsTokenCallback
@required
- (void)onTokenToken:(NSString * _Nullable)token isSpecial:(BOOL)isSpecial __attribute__((swift_name("onToken(token:isSpecial:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationStopReason")))
@interface LSDKGenerationStopReason : LSDKKotlinEnum<LSDKGenerationStopReason *>
@property (class, readonly, getter=companion) LSDKGenerationStopReasonCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LSDKGenerationStopReason *finished __attribute__((swift_name("finished")));
@property (class, readonly) LSDKGenerationStopReason *interrupted __attribute__((swift_name("interrupted")));
@property (class, readonly) LSDKGenerationStopReason *outOfContext __attribute__((swift_name("outOfContext")));
@property (class, readonly) LSDKGenerationStopReason *unknown __attribute__((swift_name("unknown")));
@property (class, readonly) NSArray<LSDKGenerationStopReason *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKGenerationStopReason *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationStopReason.Companion")))
@interface LSDKGenerationStopReasonCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKGenerationStopReasonCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InferenceEngineConversation")))
@interface LSDKInferenceEngineConversation : LSDKBase <LSDKConversation>
@property (readonly) NSArray<LSDKLeapFunction *> *functions __attribute__((swift_name("functions")));
@property (readonly) id<LSDKKotlinx_coroutines_coreMutex> generatingLock __attribute__((swift_name("generatingLock")));
@property (readonly) NSArray<LSDKChatMessage *> *history __attribute__((swift_name("history")));
@property (readonly) id<LSDKModelRunner> modelRunner __attribute__((swift_name("modelRunner")));
- (instancetype)initWithModelRunner:(id<LSDKModelRunner>)modelRunner history:(NSArray<LSDKChatMessage *> *)history __attribute__((swift_name("init(modelRunner:history:)"))) __attribute__((objc_designated_initializer));
- (void)appendToHistoryMessage:(LSDKChatMessage *)message __attribute__((swift_name("appendToHistory(message:)")));
- (void)registerFunctionFunction:(LSDKLeapFunction *)function __attribute__((swift_name("registerFunction(function:)")));
- (void)removeLastMessage __attribute__((swift_name("removeLastMessage()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InferenceEngineExceptions")))
@interface LSDKInferenceEngineExceptions : LSDKBase
@property (class, readonly, getter=shared) LSDKInferenceEngineExceptions *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)inferenceEngineExceptions __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InferenceEngineExceptions.PromptExceedContextLengthException")))
@interface LSDKInferenceEngineExceptionsPromptExceedContextLengthException : LSDKKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Message")))
@interface LSDKMessage : LSDKBase
@property (readonly) NSArray<LSDKMessageContent *> *contents __attribute__((swift_name("contents")));
@property (readonly) NSString *role __attribute__((swift_name("role")));
- (instancetype)initWithRole:(NSString *)role contents:(NSArray<LSDKMessageContent *> *)contents __attribute__((swift_name("init(role:contents:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("MessageContent")))
@interface LSDKMessageContent : LSDKBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageContent.JpegContent")))
@interface LSDKMessageContentJpegContent : LSDKMessageContent
@property (readonly) LSDKKotlinx_io_bytestringByteString *jpegByteString __attribute__((swift_name("jpegByteString")));
- (instancetype)initWithJpegByteString:(LSDKKotlinx_io_bytestringByteString *)jpegByteString __attribute__((swift_name("init(jpegByteString:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageContent.StringContent")))
@interface LSDKMessageContentStringContent : LSDKMessageContent
@property (readonly) NSString *text __attribute__((swift_name("text")));
- (instancetype)initWithText:(NSString *)text __attribute__((swift_name("init(text:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageContent.WavContent")))
@interface LSDKMessageContentWavContent : LSDKMessageContent
@property (readonly) LSDKKotlinx_io_bytestringByteString *wavByteString __attribute__((swift_name("wavByteString")));
- (instancetype)initWithWavByteString:(LSDKKotlinx_io_bytestringByteString *)wavByteString __attribute__((swift_name("init(wavByteString:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SamplerParams")))
@interface LSDKSamplerParams : LSDKBase
@property LSDKFloat * _Nullable minP __attribute__((swift_name("minP")));
@property LSDKLong * _Nullable randomSeed __attribute__((swift_name("randomSeed")));
@property LSDKFloat * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));
@property LSDKFloat * _Nullable temperature __attribute__((swift_name("temperature")));
@property LSDKInt * _Nullable topK __attribute__((swift_name("topK")));
@property LSDKFloat * _Nullable topP __attribute__((swift_name("topP")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end


/**
 * Processes tokens from the inference engine and routes them to appropriate handlers.
 *
 * This class encapsulates the logic for:
 * - Filtering special tokens (tokens marked with isSpecial flag)
 * - Routing reasoning content (<think> / </think> tags)
 * - Routing function call tokens (start/end tokens from parser)
 * - Emitting regular text as MessageResponse.Chunk
 * - Supporting inline thinking mode
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenProcessor")))
@interface LSDKTokenProcessor : LSDKBase
@property (class, readonly, getter=companion) LSDKTokenProcessorCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKKotlinStringBuilder *buffer __attribute__((swift_name("buffer")));
@property (readonly) NSMutableArray<LSDKLeapFunctionCall *> *functionCallBuffer __attribute__((swift_name("functionCallBuffer")));
@property (readonly) LSDKKotlinStringBuilder *reasoningBuffer __attribute__((swift_name("reasoningBuffer")));
- (instancetype)initWithCallback:(id<LSDKModelRunnerGenerationCallback>)callback functionCallParser:(LSDKLeapFunctionCallParser * _Nullable)functionCallParser inlineThinking:(BOOL)inlineThinking __attribute__((swift_name("init(callback:functionCallParser:inlineThinking:)"))) __attribute__((objc_designated_initializer));

/**
 * Process a single token from the inference engine.
 *
 * @param chunk The token string (null tokens are silently ignored)
 * @param isSpecial Whether the token is marked as special by the inference engine
 */
- (void)processTokenChunk:(NSString * _Nullable)chunk isSpecial:(BOOL)isSpecial __attribute__((swift_name("processToken(chunk:isSpecial:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenProcessor.Companion")))
@interface LSDKTokenProcessorCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKTokenProcessorCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *REASONING_END_TAG __attribute__((swift_name("REASONING_END_TAG")));
@property (readonly) NSString *REASONING_START_TAG __attribute__((swift_name("REASONING_START_TAG")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.0")
*/
__attribute__((swift_name("KotlinAutoCloseable")))
@protocol LSDKKotlinAutoCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((swift_name("Kotlinx_io_coreRawSink")))
@protocol LSDKKotlinx_io_coreRawSink <LSDKKotlinAutoCloseable>
@required
- (void)flush __attribute__((swift_name("flush()")));
- (void)writeSource:(LSDKKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
@end


/**
 * A RawSink implementation that consumes incoming bytes to compute a SHA-256 hash.
 *
 * This sink is a passthrough for hashing purposes only: it does not forward data to any underlying
 * sink and simply discards written bytes after updating the digest.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Sha256Sink")))
@interface LSDKSha256Sink : LSDKBase <LSDKKotlinx_io_coreRawSink>
@property (readonly) int64_t bytesWritten __attribute__((swift_name("bytesWritten")));

/**
 * A RawSink implementation that consumes incoming bytes to compute a SHA-256 hash.
 *
 * This sink is a passthrough for hashing purposes only: it does not forward data to any underlying
 * sink and simply discards written bytes after updating the digest.
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * A RawSink implementation that consumes incoming bytes to compute a SHA-256 hash.
 *
 * This sink is a passthrough for hashing purposes only: it does not forward data to any underlying
 * sink and simply discards written bytes after updating the digest.
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)close __attribute__((swift_name("close()")));
- (void)flush __attribute__((swift_name("flush()")));

/**
 * Returns the current SHA-256 hash bytes of the data written so far. If the sink is closed,
 * returns the finalized hash. If not closed, tries to clone the digest to produce a snapshot
 * without finalizing; if cloning isn't supported, returns null.
 */
- (LSDKKotlinByteArray * _Nullable)hashBytes __attribute__((swift_name("hashBytes()")));

/**
 * Returns the current SHA-256 hash of the bytes written so far as a lowercase hex string. If the
 * sink has been closed, returns the finalized hash; otherwise attempts to compute a snapshot
 * using a clone of the digest. If cloning isn't supported, the hash will be computed only after
 * [close] is called.
 */
- (NSString *)hashHex __attribute__((swift_name("hashHex()")));
- (void)writeSource:(LSDKKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));

/** Total number of bytes written to this sink. */
@end

__attribute__((swift_name("Kotlinx_io_coreRawSource")))
@protocol LSDKKotlinx_io_coreRawSource <LSDKKotlinAutoCloseable>
@required
- (int64_t)readAtMostToSink:(LSDKKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
@end


/**
 * A RawSource wrapper that computes a SHA-256 hash of the bytes read from an underlying source.
 *
 * This source reads from [delegate], updates the digest with the read bytes and then forwards the
 * same data to the caller-provided [Buffer].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Sha256Source")))
@interface LSDKSha256Source : LSDKBase <LSDKKotlinx_io_coreRawSource>
@property (readonly) int64_t bytesRead __attribute__((swift_name("bytesRead")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_io_coreRawSource>)delegate __attribute__((swift_name("init(delegate:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));

/**
 * Returns the current SHA-256 hash bytes. If closed, returns the finalized value; otherwise tries
 * to compute a snapshot using a copy of the digest. If not supported, returns null.
 */
- (LSDKKotlinByteArray * _Nullable)hashBytes __attribute__((swift_name("hashBytes()")));

/**
 * Returns the current SHA-256 hash as a lowercase hex string. If closed, returns the finalized
 * hash; otherwise attempts to compute a snapshot using a copy of the digest.
 */
- (NSString *)hashHex __attribute__((swift_name("hashHex()")));
- (int64_t)readAtMostToSink:(LSDKKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));

/** Total number of bytes read from this source. */
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationTimeParameters")))
@interface LSDKGenerationTimeParameters : LSDKBase
@property (class, readonly, getter=companion) LSDKGenerationTimeParametersCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKInt * _Nullable numberOfDecodingThreads __attribute__((swift_name("numberOfDecodingThreads")));
@property (readonly) LSDKSamplingParameters * _Nullable samplingParameters __attribute__((swift_name("samplingParameters")));
- (instancetype)initWithSamplingParameters:(LSDKSamplingParameters * _Nullable)samplingParameters numberOfDecodingThreads:(LSDKInt * _Nullable)numberOfDecodingThreads __attribute__((swift_name("init(samplingParameters:numberOfDecodingThreads:)"))) __attribute__((objc_designated_initializer));
- (LSDKGenerationTimeParameters *)doCopySamplingParameters:(LSDKSamplingParameters * _Nullable)samplingParameters numberOfDecodingThreads:(LSDKInt * _Nullable)numberOfDecodingThreads __attribute__((swift_name("doCopy(samplingParameters:numberOfDecodingThreads:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="number_of_decoding_threads")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="sampling_parameters")
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationTimeParameters.Companion")))
@interface LSDKGenerationTimeParametersCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKGenerationTimeParametersCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Base type for variant-specific load time parameters.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("LoadTimeParameters")))
@protocol LSDKLoadTimeParameters
@required
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property (readonly) NSString *model __attribute__((swift_name("model")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="llama.cpp/image-to-text")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImageToTextLoadParams")))
@interface LSDKImageToTextLoadParams : LSDKBase <LSDKLoadTimeParameters>
@property (class, readonly, getter=companion) LSDKImageToTextLoadParamsCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property (readonly) NSString *model __attribute__((swift_name("model")));
@property (readonly) NSString *multimodalProjector __attribute__((swift_name("multimodalProjector")));
- (instancetype)initWithChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector __attribute__((swift_name("init(chatTemplate:model:multimodalProjector:)"))) __attribute__((objc_designated_initializer));
- (LSDKImageToTextLoadParams *)doCopyChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector __attribute__((swift_name("doCopy(chatTemplate:model:multimodalProjector:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="chat_template")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="multimodal_projector")
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImageToTextLoadParams.Companion")))
@interface LSDKImageToTextLoadParamsCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKImageToTextLoadParamsCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** A model available from the Leap API
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapApiModel")))
@interface LSDKLeapApiModel : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapApiModelCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *modelSlug __attribute__((swift_name("modelSlug")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString * _Nullable organization __attribute__((swift_name("organization")));
@property (readonly) NSArray<NSString *> * _Nullable platform __attribute__((swift_name("platform")));
@property (readonly) NSArray<NSString *> *quantizationSlugs __attribute__((swift_name("quantizationSlugs")));
@property (readonly) NSArray<NSString *> *quantizationTypes __attribute__((swift_name("quantizationTypes")));
@property (readonly) NSString * _Nullable size __attribute__((swift_name("size")));
- (instancetype)initWithName:(NSString *)name modelSlug:(NSString *)modelSlug description:(NSString * _Nullable)description quantizationSlugs:(NSArray<NSString *> *)quantizationSlugs quantizationTypes:(NSArray<NSString *> *)quantizationTypes organization:(NSString * _Nullable)organization size:(NSString * _Nullable)size platform:(NSArray<NSString *> * _Nullable)platform __attribute__((swift_name("init(name:modelSlug:description:quantizationSlugs:quantizationTypes:organization:size:platform:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapApiModel *)doCopyName:(NSString *)name modelSlug:(NSString *)modelSlug description:(NSString * _Nullable)description quantizationSlugs:(NSArray<NSString *> *)quantizationSlugs quantizationTypes:(NSArray<NSString *> *)quantizationTypes organization:(NSString * _Nullable)organization size:(NSString * _Nullable)size platform:(NSArray<NSString *> * _Nullable)platform __attribute__((swift_name("doCopy(name:modelSlug:description:quantizationSlugs:quantizationTypes:organization:size:platform:)")));

/** A model available from the Leap API */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** A model available from the Leap API */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** A model available from the Leap API */
- (NSString *)description __attribute__((swift_name("description()")));

/** Description of the model */

/** Model identifier (e.g., "lfm2-1.2b")
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model_slug")
*/

/** Display name of the model */

/** Organization that published the model */

/** Supported platforms */

/** List of available quantization slugs
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="quantization_slugs")
*/

/** List of quantization type names (e.g., "Q4_0", "Q8_0")
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="quantization_types")
*/

/** Model size (e.g., "1.2B", "700M") */
@end


/** A model available from the Leap API */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapApiModel.Companion")))
@interface LSDKLeapApiModelCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapApiModelCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** A model available from the Leap API */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** A model available from the Leap API */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader")))
@interface LSDKLeapDownloader : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapDownloaderCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKLeapDownloaderConfig *config __attribute__((swift_name("config")));
- (instancetype)initWithConfig:(LSDKLeapDownloaderConfig *)config httpClient:(LSDKKtor_client_coreHttpClient * _Nullable)httpClient __attribute__((swift_name("init(config:httpClient:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteModelFileModelUrl:(NSString *)modelUrl modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("deleteModelFile(modelUrl:modelName:quantizationSlug:completionHandler:)")));

/**
 * Deletes a model downloaded from a manifest URL.
 *
 * @param manifestUrl The URL of the manifest JSON file
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteModelFromManifestUrlManifestUrl:(NSString *)manifestUrl completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("deleteModelFromManifestUrl(manifestUrl:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteModelResourcesModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("deleteModelResources(modelName:quantizationSlug:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)downloadModelModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug progress:(void (^)(LSDKProgressData *))progress completionHandler:(void (^)(LSDKManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("downloadModel(modelName:quantizationSlug:progress:completionHandler:)")));

/**
 * Downloads a model from a manifest URL.
 *
 * Fetches the manifest JSON from the given URL, parses it into a Manifest, extracts resource URLs
 * and downloads them to the local cache.
 *
 * @param manifestUrl The URL of the manifest JSON file
 * @param progress Callback for download progress updates
 * @return The manifest with pathOnDisk set to the local manifest file
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)downloadModelFromManifestUrlManifestUrl:(NSString *)manifestUrl progress:(void (^)(LSDKProgressData *))progress completionHandler:(void (^)(LSDKManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("downloadModelFromManifestUrl(manifestUrl:progress:completionHandler:)")));
- (NSString * _Nullable)getCachedFilePathModelUrl:(NSString *)modelUrl modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("getCachedFilePath(modelUrl:modelName:quantizationSlug:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCachedManifestModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LSDKManifest * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getCachedManifest(modelName:quantizationSlug:completionHandler:)")));

/**
 * Get the total size in bytes of a model.
 *
 * If the model is downloaded, this accumulates all file sizes on disk. If the model is not
 * downloaded, this resolves the manifest and makes HEAD requests to determine file sizes.
 *
 * @param modelName the model name
 * @param quantizationSlug the quantization slug
 * @return the total size in bytes, or -1 if the size cannot be determined
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getModelSizeModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LSDKLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getModelSize(modelName:quantizationSlug:completionHandler:)")));

/** Creates the path of the file that should be saved to disk from the url of a resource */
- (NSString *)getPathFromUrlUrl:(NSString *)url manifestUrl:(NSString *)manifestUrl modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("getPathFromUrl(url:manifestUrl:modelName:quantizationSlug:)")));
- (NSString *)getResourceFolderModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("getResourceFolder(modelName:quantizationSlug:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug modelLoadingOptions:(LSDKModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters forceDownload:(BOOL)forceDownload isRetry:(BOOL)isRetry progress:(void (^)(LSDKProgressData *))progress completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelName:quantizationSlug:modelLoadingOptions:generationTimeParameters:forceDownload:isRetry:progress:completionHandler:)")));

/**
 * Downloads and loads a model from a manifest URL.
 *
 * @param manifestUrl The URL of the manifest JSON file
 * @param modelLoadingOptions Optional model loading configuration
 * @param generationTimeParameters Optional generation-time parameters
 * @param progress Callback for download progress updates
 * @return A loaded ModelRunner instance
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelFromManifestUrlManifestUrl:(NSString *)manifestUrl modelLoadingOptions:(LSDKModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters progress:(void (^)(LSDKProgressData *))progress completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModelFromManifestUrl(manifestUrl:modelLoadingOptions:generationTimeParameters:progress:completionHandler:)")));

/**
 * Loads a model from individual resource URLs without requiring a manifest file.
 *
 * Downloads and caches the model and any additional resource files (mmproj, audio decoder, audio
 * tokenizer) if they are not already present locally.
 *
 * @param model The source paths/URLs for the model and optional resource files
 * @param modelLoadingOptions Optional model loading configuration. Set `modelId` to control the
 *   folder name used for caching files.
 * @param generationTimeParameters Optional generation-time parameters
 * @param progress Callback for download progress updates
 * @return A loaded ModelRunner instance
 * @throws LeapModelLoadingException if the model file cannot be downloaded or found
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadSimpleModelModel:(LSDKModelSource *)model modelLoadingOptions:(LSDKModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters isRetry:(BOOL)isRetry progress:(void (^)(LSDKProgressData *))progress completionHandler:(void (^)(id<LSDKModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadSimpleModel(model:modelLoadingOptions:generationTimeParameters:isRetry:progress:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resolveModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LSDKManifest * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("resolve(modelName:quantizationSlug:completionHandler:)")));

/**
 * Resolve a download plan for a model by name and quantization.
 *
 * This resolves the manifest and determines which resources need to be downloaded, without
 * actually downloading them. Use this to separate manifest resolution from file downloading.
 *
 * @param modelName The model name
 * @param quantizationSlug The quantization method
 * @return ResolvedManifest with download plan
 * @throws LeapModelLoadingException if manifest resolution fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resolveDownloadPlanModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LSDKLeapDownloaderResolvedManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resolveDownloadPlan(modelName:quantizationSlug:completionHandler:)")));

/**
 * Resolve a download plan from a manifest URL.
 *
 * This fetches and parses the manifest, then determines which resources need to be downloaded,
 * without actually downloading them.
 *
 * @param manifestUrl The URL of the manifest JSON file
 * @return ResolvedManifest with download plan
 * @throws LeapModelLoadingException if manifest resolution fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resolveDownloadPlanFromManifestUrlManifestUrl:(NSString *)manifestUrl completionHandler:(void (^)(LSDKLeapDownloaderResolvedManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resolveDownloadPlanFromManifestUrl(manifestUrl:completionHandler:)")));

/**
 * Save a manifest to disk.
 *
 * This writes the manifest JSON file to the appropriate location in the cache directory. The
 * manifest's loadTimeParameters will be updated to use relative filenames instead of URLs.
 *
 * @param manifest The manifest to save
 * @param modelName The model name (used for cache directory naming)
 * @param quantizationSlug The quantization slug (used for cache directory naming)
 * @return The updated manifest with loadTimeParameters containing filenames instead of URLs
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveManifestToDiskManifest:(LSDKManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LSDKManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("saveManifestToDisk(manifest:modelName:quantizationSlug:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader.Companion")))
@interface LSDKLeapDownloaderCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapDownloaderCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/**
 * Resolved manifest with download plan.
 *
 * @param manifest The manifest
 * @param modelName The model name used for caching
 * @param quantizationSlug The quantization slug used for caching
 * @param resources List of resources to download
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader.ResolvedManifest")))
@interface LSDKLeapDownloaderResolvedManifest : LSDKBase
@property (readonly) LSDKManifest *manifest __attribute__((swift_name("manifest")));
@property (readonly) NSString *modelName __attribute__((swift_name("modelName")));
@property (readonly) NSString *quantizationSlug __attribute__((swift_name("quantizationSlug")));
@property (readonly) NSArray<LSDKLeapDownloaderResolvedResource *> *resources __attribute__((swift_name("resources")));
- (instancetype)initWithManifest:(LSDKManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug resources:(NSArray<LSDKLeapDownloaderResolvedResource *> *)resources __attribute__((swift_name("init(manifest:modelName:quantizationSlug:resources:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapDownloaderResolvedManifest *)doCopyManifest:(LSDKManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug resources:(NSArray<LSDKLeapDownloaderResolvedResource *> *)resources __attribute__((swift_name("doCopy(manifest:modelName:quantizationSlug:resources:)")));

/**
 * Resolved manifest with download plan.
 *
 * @param manifest The manifest
 * @param modelName The model name used for caching
 * @param quantizationSlug The quantization slug used for caching
 * @param resources List of resources to download
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Resolved manifest with download plan.
 *
 * @param manifest The manifest
 * @param modelName The model name used for caching
 * @param quantizationSlug The quantization slug used for caching
 * @param resources List of resources to download
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Resolved manifest with download plan.
 *
 * @param manifest The manifest
 * @param modelName The model name used for caching
 * @param quantizationSlug The quantization slug used for caching
 * @param resources List of resources to download
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Resolved resource information for a downloadable file.
 *
 * @param remoteUrl The remote URL to download from
 * @param localPath The local file path where the resource will be saved
 * @param expectedSize The expected file size in bytes (null if unknown)
 * @param expectedSha256 The expected SHA256 hash (null if unknown)
 * @param isCached Whether the file already exists locally with matching size
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader.ResolvedResource")))
@interface LSDKLeapDownloaderResolvedResource : LSDKBase
@property (readonly) NSString * _Nullable expectedSha256 __attribute__((swift_name("expectedSha256")));
@property (readonly) LSDKLong * _Nullable expectedSize __attribute__((swift_name("expectedSize")));
@property (readonly) BOOL isCached __attribute__((swift_name("isCached")));
@property (readonly) NSString *localPath __attribute__((swift_name("localPath")));
@property (readonly) NSString *remoteUrl __attribute__((swift_name("remoteUrl")));
- (instancetype)initWithRemoteUrl:(NSString *)remoteUrl localPath:(NSString *)localPath expectedSize:(LSDKLong * _Nullable)expectedSize expectedSha256:(NSString * _Nullable)expectedSha256 isCached:(BOOL)isCached __attribute__((swift_name("init(remoteUrl:localPath:expectedSize:expectedSha256:isCached:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapDownloaderResolvedResource *)doCopyRemoteUrl:(NSString *)remoteUrl localPath:(NSString *)localPath expectedSize:(LSDKLong * _Nullable)expectedSize expectedSha256:(NSString * _Nullable)expectedSha256 isCached:(BOOL)isCached __attribute__((swift_name("doCopy(remoteUrl:localPath:expectedSize:expectedSha256:isCached:)")));

/**
 * Resolved resource information for a downloadable file.
 *
 * @param remoteUrl The remote URL to download from
 * @param localPath The local file path where the resource will be saved
 * @param expectedSize The expected file size in bytes (null if unknown)
 * @param expectedSha256 The expected SHA256 hash (null if unknown)
 * @param isCached Whether the file already exists locally with matching size
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Resolved resource information for a downloadable file.
 *
 * @param remoteUrl The remote URL to download from
 * @param localPath The local file path where the resource will be saved
 * @param expectedSize The expected file size in bytes (null if unknown)
 * @param expectedSha256 The expected SHA256 hash (null if unknown)
 * @param isCached Whether the file already exists locally with matching size
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Resolved resource information for a downloadable file.
 *
 * @param remoteUrl The remote URL to download from
 * @param localPath The local file path where the resource will be saved
 * @param expectedSize The expected file size in bytes (null if unknown)
 * @param expectedSha256 The expected SHA256 hash (null if unknown)
 * @param isCached Whether the file already exists locally with matching size
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader.SavedFileInfo")))
@interface LSDKLeapDownloaderSavedFileInfo : LSDKBase
@property (readonly) int64_t bytesSaved __attribute__((swift_name("bytesSaved")));
@property (readonly) LSDKKotlinx_io_corePath *filepath __attribute__((swift_name("filepath")));
@property (readonly) NSString *sha256 __attribute__((swift_name("sha256")));
- (instancetype)initWithSha256:(NSString *)sha256 filepath:(LSDKKotlinx_io_corePath *)filepath bytesSaved:(int64_t)bytesSaved __attribute__((swift_name("init(sha256:filepath:bytesSaved:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapDownloaderSavedFileInfo *)doCopySha256:(NSString *)sha256 filepath:(LSDKKotlinx_io_corePath *)filepath bytesSaved:(int64_t)bytesSaved __attribute__((swift_name("doCopy(sha256:filepath:bytesSaved:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloaderConfig")))
@interface LSDKLeapDownloaderConfig : LSDKBase
@property (readonly) NSString * _Nullable baseUrl __attribute__((swift_name("baseUrl")));
@property (readonly) int64_t connectTimeoutMillis __attribute__((swift_name("connectTimeoutMillis")));
@property (readonly) BOOL disableSslValidation __attribute__((swift_name("disableSslValidation")));
@property (readonly) int64_t requestTimeoutMillis __attribute__((swift_name("requestTimeoutMillis")));
@property (readonly) NSString *saveDir __attribute__((swift_name("saveDir")));
@property (readonly) int64_t socketTimeoutMillis __attribute__((swift_name("socketTimeoutMillis")));
@property (readonly) BOOL validateSha256 __attribute__((swift_name("validateSha256")));
- (instancetype)initWithSaveDir:(NSString *)saveDir validateSha256:(BOOL)validateSha256 disableSslValidation:(BOOL)disableSslValidation baseUrl:(NSString * _Nullable)baseUrl connectTimeoutMillis:(int64_t)connectTimeoutMillis socketTimeoutMillis:(int64_t)socketTimeoutMillis requestTimeoutMillis:(int64_t)requestTimeoutMillis __attribute__((swift_name("init(saveDir:validateSha256:disableSslValidation:baseUrl:connectTimeoutMillis:socketTimeoutMillis:requestTimeoutMillis:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapDownloaderConfig *)doCopySaveDir:(NSString *)saveDir validateSha256:(BOOL)validateSha256 disableSslValidation:(BOOL)disableSslValidation baseUrl:(NSString * _Nullable)baseUrl connectTimeoutMillis:(int64_t)connectTimeoutMillis socketTimeoutMillis:(int64_t)socketTimeoutMillis requestTimeoutMillis:(int64_t)requestTimeoutMillis __attribute__((swift_name("doCopy(saveDir:validateSha256:disableSslValidation:baseUrl:connectTimeoutMillis:socketTimeoutMillis:requestTimeoutMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Only for testing: Override the base URL for manifest API (default: https://leap.liquid.ai) */

/** HTTP connect timeout in milliseconds (default: 30 seconds) */

/** Only for testing: Disables SSL certificate validation (useful for iOS simulator) */

/** HTTP request timeout in milliseconds (default: 10 minutes) */

/** HTTP socket/read timeout in milliseconds (default: 60 seconds) */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapManifestProcessorConfig")))
@interface LSDKLeapManifestProcessorConfig : LSDKBase
@property (readonly) BOOL offlineMode __attribute__((swift_name("offlineMode")));
@property (readonly) NSString *targetDir __attribute__((swift_name("targetDir")));
@property (readonly) BOOL validateSha256 __attribute__((swift_name("validateSha256")));
- (instancetype)initWithTargetDir:(NSString *)targetDir validateSha256:(BOOL)validateSha256 offlineMode:(BOOL)offlineMode __attribute__((swift_name("init(targetDir:validateSha256:offlineMode:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapManifestProcessorConfig *)doCopyTargetDir:(NSString *)targetDir validateSha256:(BOOL)validateSha256 offlineMode:(BOOL)offlineMode __attribute__((swift_name("doCopy(targetDir:validateSha256:offlineMode:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelManifestResponse")))
@interface LSDKLeapModelManifestResponse : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapModelManifestResponseCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *manifest_url __attribute__((swift_name("manifest_url")));
- (instancetype)initWithManifest_url:(NSString *)manifest_url __attribute__((swift_name("init(manifest_url:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapModelManifestResponse *)doCopyManifest_url:(NSString *)manifest_url __attribute__((swift_name("doCopy(manifest_url:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelManifestResponse.Companion")))
@interface LSDKLeapModelManifestResponseCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapModelManifestResponseCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Client for fetching available models from the Leap API */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelsApi")))
@interface LSDKLeapModelsApi : LSDKBase <LSDKKotlinAutoCloseable>
- (instancetype)initWithBaseUrl:(NSString *)baseUrl httpClient:(LSDKKtor_client_coreHttpClient * _Nullable)httpClient __attribute__((swift_name("init(baseUrl:httpClient:)"))) __attribute__((objc_designated_initializer));

/** Close the HTTP client when done */
- (void)close __attribute__((swift_name("close()")));

/**
 * Fetch the list of available models from the Leap API.
 *
 * This function is safe to call from the main thread as it automatically switches to the IO
 * dispatcher for network operations.
 *
 * @param inferenceEngine Filter by inference engine (default: "LLAMACPP")
 * @return List of available models with their quantization options
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)fetchAvailableModelsInferenceEngine:(NSString *)inferenceEngine completionHandler:(void (^)(NSArray<LSDKLeapApiModel *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("fetchAvailableModels(inferenceEngine:completionHandler:)")));
@end


/** Response from the Leap models API
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelsResponse")))
@interface LSDKLeapModelsResponse : LSDKBase
@property (class, readonly, getter=companion) LSDKLeapModelsResponseCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSArray<LSDKLeapApiModel *> *models __attribute__((swift_name("models")));
- (instancetype)initWithModels:(NSArray<LSDKLeapApiModel *> *)models __attribute__((swift_name("init(models:)"))) __attribute__((objc_designated_initializer));
- (LSDKLeapModelsResponse *)doCopyModels:(NSArray<LSDKLeapApiModel *> *)models __attribute__((swift_name("doCopy(models:)")));

/** Response from the Leap models API */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Response from the Leap models API */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Response from the Leap models API */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Response from the Leap models API */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelsResponse.Companion")))
@interface LSDKLeapModelsResponseCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLeapModelsResponseCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** Response from the Leap models API */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Response from the Leap models API */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="llama.cpp/lfm2-audio-v1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Lfm2AudioV1LoadParams")))
@interface LSDKLfm2AudioV1LoadParams : LSDKBase <LSDKLoadTimeParameters>
@property (class, readonly, getter=companion) LSDKLfm2AudioV1LoadParamsCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *audioDecoder __attribute__((swift_name("audioDecoder")));
@property (readonly) NSString *audioTokenizer __attribute__((swift_name("audioTokenizer")));
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property (readonly) NSString *model __attribute__((swift_name("model")));
@property (readonly) NSString *multimodalProjector __attribute__((swift_name("multimodalProjector")));
- (instancetype)initWithChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector audioDecoder:(NSString *)audioDecoder audioTokenizer:(NSString *)audioTokenizer __attribute__((swift_name("init(chatTemplate:model:multimodalProjector:audioDecoder:audioTokenizer:)"))) __attribute__((objc_designated_initializer));
- (LSDKLfm2AudioV1LoadParams *)doCopyChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector audioDecoder:(NSString *)audioDecoder audioTokenizer:(NSString *)audioTokenizer __attribute__((swift_name("doCopy(chatTemplate:model:multimodalProjector:audioDecoder:audioTokenizer:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="audio_decoder")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="audio_tokenizer")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="chat_template")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="multimodal_projector")
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Lfm2AudioV1LoadParams.Companion")))
@interface LSDKLfm2AudioV1LoadParamsCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLfm2AudioV1LoadParamsCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Base type for variant-specific load time parameters. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadTimeParametersCompanion")))
@interface LSDKLoadTimeParametersCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKLoadTimeParametersCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** Base type for variant-specific load time parameters. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Base type for variant-specific load time parameters. */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));

/** Base type for variant-specific load time parameters. */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/manifest/SchemaSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Manifest")))
@interface LSDKManifest : LSDKBase
@property (class, readonly, getter=companion) LSDKManifestCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKGenerationTimeParameters * _Nullable generationTimeParameters __attribute__((swift_name("generationTimeParameters")));
@property (readonly) NSString *inferenceType __attribute__((swift_name("inferenceType")));
@property (readonly) id<LSDKLoadTimeParameters> loadTimeParameters __attribute__((swift_name("loadTimeParameters")));
@property (readonly) NSString * _Nullable originalUrl __attribute__((swift_name("originalUrl")));
@property (readonly) NSString * _Nullable pathOnDisk __attribute__((swift_name("pathOnDisk")));
@property (readonly) NSString *schemaVersion __attribute__((swift_name("schemaVersion")));
- (instancetype)initWithSchemaVersion:(NSString *)schemaVersion inferenceType:(NSString *)inferenceType loadTimeParameters:(id<LSDKLoadTimeParameters>)loadTimeParameters generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters originalUrl:(NSString * _Nullable)originalUrl pathOnDisk:(NSString * _Nullable)pathOnDisk __attribute__((swift_name("init(schemaVersion:inferenceType:loadTimeParameters:generationTimeParameters:originalUrl:pathOnDisk:)"))) __attribute__((objc_designated_initializer));
- (LSDKManifest *)doCopySchemaVersion:(NSString *)schemaVersion inferenceType:(NSString *)inferenceType loadTimeParameters:(id<LSDKLoadTimeParameters>)loadTimeParameters generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters originalUrl:(NSString * _Nullable)originalUrl pathOnDisk:(NSString * _Nullable)pathOnDisk __attribute__((swift_name("doCopy(schemaVersion:inferenceType:loadTimeParameters:generationTimeParameters:originalUrl:pathOnDisk:)")));

/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="generation_time_parameters")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="inference_type")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="load_time_parameters")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="original_url")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="path_on_disk")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="schema_version")
*/
@end


/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Manifest.Companion")))
@interface LSDKManifestCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKManifestCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Represents a source model configuration with details about the model files and related
 * information necessary for its usage.
 *
 * @property modelPath The absolute or relative path to the primary model file.
 * @property mmprojPath Optional path to the mmproj file.
 * @property audioDecoderPath Optional path to the audio decoder file.
 * @property audioTokenizerPath Optional path to the audio tokenizer file.
 * @property modelName The model name used for API calls and storage (e.g., "LFM2.5-Audio-1.5B").
 * @property quantizationId Identifier indicating the quantization type.
 * @property downloads A derived property that returns a list of non-null file paths required for
 *   the model, combining all relevant paths such as the model, mmproj, audio decoder, and audio
 *   tokenizer files.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelSource")))
@interface LSDKModelSource : LSDKBase
@property (readonly) NSString * _Nullable audioDecoderPath __attribute__((swift_name("audioDecoderPath")));
@property (readonly) NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSArray<NSString *> *downloads __attribute__((swift_name("downloads")));
@property (readonly) NSString * _Nullable mmprojPath __attribute__((swift_name("mmprojPath")));
@property (readonly) NSString *modelName __attribute__((swift_name("modelName")));
@property (readonly) NSString *modelPath __attribute__((swift_name("modelPath")));
@property (readonly) NSString *quantizationId __attribute__((swift_name("quantizationId")));
- (instancetype)initWithModelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath modelName:(NSString *)modelName quantizationId:(NSString *)quantizationId __attribute__((swift_name("init(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:modelName:quantizationId:)"))) __attribute__((objc_designated_initializer));
- (LSDKModelSource *)doCopyModelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath modelName:(NSString *)modelName quantizationId:(NSString *)quantizationId __attribute__((swift_name("doCopy(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:modelName:quantizationId:)")));

/**
 * Represents a source model configuration with details about the model files and related
 * information necessary for its usage.
 *
 * @property modelPath The absolute or relative path to the primary model file.
 * @property mmprojPath Optional path to the mmproj file.
 * @property audioDecoderPath Optional path to the audio decoder file.
 * @property audioTokenizerPath Optional path to the audio tokenizer file.
 * @property modelName The model name used for API calls and storage (e.g., "LFM2.5-Audio-1.5B").
 * @property quantizationId Identifier indicating the quantization type.
 * @property downloads A derived property that returns a list of non-null file paths required for
 *   the model, combining all relevant paths such as the model, mmproj, audio decoder, and audio
 *   tokenizer files.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents a source model configuration with details about the model files and related
 * information necessary for its usage.
 *
 * @property modelPath The absolute or relative path to the primary model file.
 * @property mmprojPath Optional path to the mmproj file.
 * @property audioDecoderPath Optional path to the audio decoder file.
 * @property audioTokenizerPath Optional path to the audio tokenizer file.
 * @property modelName The model name used for API calls and storage (e.g., "LFM2.5-Audio-1.5B").
 * @property quantizationId Identifier indicating the quantization type.
 * @property downloads A derived property that returns a list of non-null file paths required for
 *   the model, combining all relevant paths such as the model, mmproj, audio decoder, and audio
 *   tokenizer files.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents a source model configuration with details about the model files and related
 * information necessary for its usage.
 *
 * @property modelPath The absolute or relative path to the primary model file.
 * @property mmprojPath Optional path to the mmproj file.
 * @property audioDecoderPath Optional path to the audio decoder file.
 * @property audioTokenizerPath Optional path to the audio tokenizer file.
 * @property modelName The model name used for API calls and storage (e.g., "LFM2.5-Audio-1.5B").
 * @property quantizationId Identifier indicating the quantization type.
 * @property downloads A derived property that returns a list of non-null file paths required for
 *   the model, combining all relevant paths such as the model, mmproj, audio decoder, and audio
 *   tokenizer files.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressData")))
@interface LSDKProgressData : LSDKBase
@property (readonly) int64_t bytes __attribute__((swift_name("bytes")));
@property (readonly) float progress __attribute__((swift_name("progress")));
@property (readonly) int64_t total __attribute__((swift_name("total")));
- (instancetype)initWithBytes:(int64_t)bytes total:(int64_t)total __attribute__((swift_name("init(bytes:total:)"))) __attribute__((objc_designated_initializer));
- (LSDKProgressData *)doCopyBytes:(int64_t)bytes total:(int64_t)total __attribute__((swift_name("doCopy(bytes:total:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * A RawSink wrapper that reports progress to a listener.
 *
 * @param delegate The underlying RawSink to which the data is actually written.
 * @param progressListener A lambda function that receives the total number of bytes written so far.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSink")))
@interface LSDKProgressReportingSink : LSDKBase <LSDKKotlinx_io_coreRawSink>
- (instancetype)initWithDelegate:(id<LSDKKotlinx_io_coreRawSink>)delegate progressListener:(void (^)(LSDKLong *))progressListener __attribute__((swift_name("init(delegate:progressListener:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (void)flush __attribute__((swift_name("flush()")));
- (void)writeSource:(LSDKKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
@end


/**
 * A RawSource wrapper that reports progress to a listener.
 *
 * @param delegate The underlying RawSource from which the data is actually read.
 * @param progressListener A lambda function that receives the total number of bytes read so far.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSource")))
@interface LSDKProgressReportingSource : LSDKBase <LSDKKotlinx_io_coreRawSource>
- (instancetype)initWithDelegate:(id<LSDKKotlinx_io_coreRawSource>)delegate progressListener:(void (^)(LSDKLong *))progressListener __attribute__((swift_name("init(delegate:progressListener:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (int64_t)readAtMostToSink:(LSDKKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SamplingParameters")))
@interface LSDKSamplingParameters : LSDKBase
@property (class, readonly, getter=companion) LSDKSamplingParametersCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKDouble * _Nullable minP __attribute__((swift_name("minP")));
@property (readonly) LSDKDouble * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));
@property (readonly) LSDKDouble * _Nullable temperature __attribute__((swift_name("temperature")));
@property (readonly) LSDKInt * _Nullable topK __attribute__((swift_name("topK")));
@property (readonly) LSDKDouble * _Nullable topP __attribute__((swift_name("topP")));
- (instancetype)initWithTemperature:(LSDKDouble * _Nullable)temperature topP:(LSDKDouble * _Nullable)topP minP:(LSDKDouble * _Nullable)minP repetitionPenalty:(LSDKDouble * _Nullable)repetitionPenalty topK:(LSDKInt * _Nullable)topK __attribute__((swift_name("init(temperature:topP:minP:repetitionPenalty:topK:)"))) __attribute__((objc_designated_initializer));
- (LSDKSamplingParameters *)doCopyTemperature:(LSDKDouble * _Nullable)temperature topP:(LSDKDouble * _Nullable)topP minP:(LSDKDouble * _Nullable)minP repetitionPenalty:(LSDKDouble * _Nullable)repetitionPenalty topK:(LSDKInt * _Nullable)topK __attribute__((swift_name("doCopy(temperature:topP:minP:repetitionPenalty:topK:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="min_p")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="repetition_penalty")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="top_k")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="top_p")
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SamplingParameters.Companion")))
@interface LSDKSamplingParametersCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKSamplingParametersCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Custom serializer that inspects `inference_type` to choose the correct subtype for
 * `load_time_parameters`.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SchemaSerializer")))
@interface LSDKSchemaSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKSchemaSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Custom serializer that inspects `inference_type` to choose the correct subtype for
 * `load_time_parameters`.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)schemaSerializer __attribute__((swift_name("init()")));
- (LSDKManifest *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(LSDKManifest *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="llama.cpp/text-to-text")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextToTextLoadParams")))
@interface LSDKTextToTextLoadParams : LSDKBase <LSDKLoadTimeParameters>
@property (class, readonly, getter=companion) LSDKTextToTextLoadParamsCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property (readonly) NSString *model __attribute__((swift_name("model")));
- (instancetype)initWithChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model __attribute__((swift_name("init(chatTemplate:model:)"))) __attribute__((objc_designated_initializer));
- (LSDKTextToTextLoadParams *)doCopyChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model __attribute__((swift_name("doCopy(chatTemplate:model:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="chat_template")
*/

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model")
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextToTextLoadParams.Companion")))
@interface LSDKTextToTextLoadParamsCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKTextToTextLoadParamsCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** A chat message in the chat history.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/message/ChatMessageJsonSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage")))
@interface LSDKChatMessage : LSDKBase
@property (class, readonly, getter=companion) LSDKChatMessageCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSArray<LSDKChatMessageContent *> *content __attribute__((swift_name("content")));
@property (readonly) NSArray<LSDKLeapFunctionCall *> * _Nullable functionCalls __attribute__((swift_name("functionCalls")));
@property (readonly) NSString * _Nullable reasoningContent __attribute__((swift_name("reasoningContent")));
@property (readonly) LSDKChatMessageRole *role __attribute__((swift_name("role")));

/**
 * Single content constructor.
 *
 * @param role the role of this message
 * @param content the message content
 */
- (instancetype)initWithRole:(LSDKChatMessageRole *)role content:(LSDKChatMessageContent *)content __attribute__((swift_name("init(role:content:)"))) __attribute__((objc_designated_initializer));

/**
 * Single text content constructor.
 *
 * @param role the role of this message
 * @param textContent the message text content
 */
- (instancetype)initWithRole:(LSDKChatMessageRole *)role textContent:(NSString *)textContent __attribute__((swift_name("init(role:textContent:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithRole:(LSDKChatMessageRole *)role content:(NSArray<LSDKChatMessageContent *> *)content reasoningContent:(NSString * _Nullable)reasoningContent functionCalls:(NSArray<LSDKLeapFunctionCall *> * _Nullable)functionCalls __attribute__((swift_name("init(role:content:reasoningContent:functionCalls:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessage *)doCopyRole:(LSDKChatMessageRole *)role content:(NSArray<LSDKChatMessageContent *> *)content reasoningContent:(NSString * _Nullable)reasoningContent functionCalls:(NSArray<LSDKLeapFunctionCall *> * _Nullable)functionCalls __attribute__((swift_name("doCopy(role:content:reasoningContent:functionCalls:)")));

/** A chat message in the chat history. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** A chat message in the chat history. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** A chat message in the chat history. */
- (NSString *)description __attribute__((swift_name("description()")));

/** The list of contents of this message. */

/**
 * Function calls requested by the model. This field is only valid for models that support tool
 * calls.
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="tool_calls")
*/

/**
 * Reasoning content of this message. Reasoning content is only valid for messages generated by
 * the models.
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="reasoning_content")
*/

/** The role of this message. */
@end


/** A chat message in the chat history. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage.Companion")))
@interface LSDKChatMessageCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** A chat message in the chat history. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** A chat message in the chat history. */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Role of the message. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage.Role")))
@interface LSDKChatMessageRole : LSDKKotlinEnum<LSDKChatMessageRole *>
@property (class, readonly, getter=companion) LSDKChatMessageRoleCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LSDKChatMessageRole *system __attribute__((swift_name("system")));
@property (class, readonly) LSDKChatMessageRole *user __attribute__((swift_name("user")));
@property (class, readonly) LSDKChatMessageRole *assistant __attribute__((swift_name("assistant")));
@property (class, readonly) LSDKChatMessageRole *tool __attribute__((swift_name("tool")));
@property (class, readonly) NSArray<LSDKChatMessageRole *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
+ (instancetype)alloc __attribute__((unavailable));

/** Role of the message. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKChatMessageRole *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage.RoleCompanion")))
@interface LSDKChatMessageRoleCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageRoleCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Create a Role value from a string literal.
 *
 * @param type string literal for the role value, compatible with OpenAI API.
 * @throws LeapSerializationException if the role string literal is not supported
 */
- (LSDKChatMessageRole *)fromTypeStringType:(NSString *)type __attribute__((swift_name("fromTypeString(type:)")));
@end


/** Interface for all message content classes
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("ChatMessageContent")))
@interface LSDKChatMessageContent : LSDKBase
@property (class, readonly, getter=companion) LSDKChatMessageContentCompanion *companion __attribute__((swift_name("companion")));
@end


/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="input_audio")
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/message/ChatMessageContentAudioSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.Audio")))
@interface LSDKChatMessageContentAudio : LSDKChatMessageContent
@property (class, readonly, getter=companion) LSDKChatMessageContentAudioCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKKotlinByteArray *data __attribute__((swift_name("data")));
@property (readonly) LSDKChatMessageContentAudioInputAudio *inputAudio __attribute__((swift_name("inputAudio")));
- (instancetype)initWithInputAudio:(LSDKChatMessageContentAudioInputAudio *)inputAudio __attribute__((swift_name("init(inputAudio:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithData:(LSDKKotlinByteArray *)data __attribute__((swift_name("init(data:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessageContentAudio *)doCopyInputAudio:(LSDKChatMessageContentAudioInputAudio *)inputAudio __attribute__((swift_name("doCopy(inputAudio:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="input_audio")
*/
@end


/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioCompanion")))
@interface LSDKChatMessageContentAudioCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentAudioCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioInputAudio")))
@interface LSDKChatMessageContentAudioInputAudio : LSDKBase
@property (class, readonly, getter=companion) LSDKChatMessageContentAudioInputAudioCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKKotlinByteArray *data __attribute__((swift_name("data")));
@property (readonly) NSString *format __attribute__((swift_name("format")));
- (instancetype)initWithData:(LSDKKotlinByteArray *)data format:(NSString *)format __attribute__((swift_name("init(data:format:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessageContentAudioInputAudio *)doCopyData:(LSDKKotlinByteArray *)data format:(NSString *)format __attribute__((swift_name("doCopy(data:format:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/serialization/ByteArrayBase64Serializer))
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioInputAudioCompanion")))
@interface LSDKChatMessageContentAudioInputAudioCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentAudioInputAudioCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Raw PCM float32 mono audio content. Used for engine-generated audio that needs to roundtrip
 * through conversation history without hash loss. User-provided audio (microphone recordings,
 * file uploads) should use [Audio] instead.
 *
 * @property samples Raw float32 PCM samples
 * @property sampleRate Sample rate in Hz (e.g. 24000)
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="audio_pcm_f32")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioPcmF32")))
@interface LSDKChatMessageContentAudioPcmF32 : LSDKChatMessageContent
@property (class, readonly, getter=companion) LSDKChatMessageContentAudioPcmF32Companion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@property (readonly) LSDKKotlinFloatArray *samples __attribute__((swift_name("samples")));
- (instancetype)initWithSamples:(LSDKKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("init(samples:sampleRate:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessageContentAudioPcmF32 *)doCopySamples:(LSDKKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("doCopy(samples:sampleRate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Convert to the WAV-based [Audio] content type. */
- (LSDKChatMessageContentAudio *)toAudio __attribute__((swift_name("toAudio()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Convert to WAV byte array for playback or file storage. */
- (LSDKKotlinByteArray *)toWavBytes __attribute__((swift_name("toWavBytes()")));
@end


/**
 * Raw PCM float32 mono audio content. Used for engine-generated audio that needs to roundtrip
 * through conversation history without hash loss. User-provided audio (microphone recordings,
 * file uploads) should use [Audio] instead.
 *
 * @property samples Raw float32 PCM samples
 * @property sampleRate Sample rate in Hz (e.g. 24000)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioPcmF32Companion")))
@interface LSDKChatMessageContentAudioPcmF32Companion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentAudioPcmF32Companion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Raw PCM float32 mono audio content. Used for engine-generated audio that needs to roundtrip
 * through conversation history without hash loss. User-provided audio (microphone recordings,
 * file uploads) should use [Audio] instead.
 *
 * @property samples Raw float32 PCM samples
 * @property sampleRate Sample rate in Hz (e.g. 24000)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Raw PCM float32 mono audio content. Used for engine-generated audio that needs to roundtrip
 * through conversation history without hash loss. User-provided audio (microphone recordings,
 * file uploads) should use [Audio] instead.
 *
 * @property samples Raw float32 PCM samples
 * @property sampleRate Sample rate in Hz (e.g. 24000)
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.Companion")))
@interface LSDKChatMessageContentCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *JPEG_BASE64_DATA_URL_PREFIX __attribute__((swift_name("JPEG_BASE64_DATA_URL_PREFIX")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));

/**
 * Factory method for creating Text content.
 *
 * This provides a convenient factory method that works across all platforms.
 *
 * Usage:
 * ```kotlin
 * val content = ChatMessageContent.text("Hello")
 * ```
 */
- (LSDKChatMessageContentText *)textText:(NSString *)text __attribute__((swift_name("text(text:)")));
@end


/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="image_url")
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/message/ChatMessageContentImageSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.Image")))
@interface LSDKChatMessageContentImage : LSDKChatMessageContent
@property (class, readonly, getter=companion) LSDKChatMessageContentImageCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKChatMessageContentImageImageUrl *imageUrl __attribute__((swift_name("imageUrl")));
@property (readonly) LSDKKotlinByteArray *jpegByteArray __attribute__((swift_name("jpegByteArray")));
- (instancetype)initWithImageUrl:(LSDKChatMessageContentImageImageUrl *)imageUrl __attribute__((swift_name("init(imageUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithJpegByteArray:(LSDKKotlinByteArray *)jpegByteArray __attribute__((swift_name("init(jpegByteArray:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessageContentImage *)doCopyImageUrl:(LSDKChatMessageContentImageImageUrl *)imageUrl __attribute__((swift_name("doCopy(imageUrl:)")));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="image_url")
*/
@end


/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.ImageCompanion")))
@interface LSDKChatMessageContentImageCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentImageCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.ImageImageUrl")))
@interface LSDKChatMessageContentImageImageUrl : LSDKBase
@property (class, readonly, getter=companion) LSDKChatMessageContentImageImageUrlCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *url __attribute__((swift_name("url")));
- (instancetype)initWithUrl:(NSString *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessageContentImageImageUrl *)doCopyUrl:(NSString *)url __attribute__((swift_name("doCopy(url:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.ImageImageUrlCompanion")))
@interface LSDKChatMessageContentImageImageUrlCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentImageImageUrlCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Pure text content.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="text")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.Text")))
@interface LSDKChatMessageContentText : LSDKChatMessageContent
@property (class, readonly, getter=companion) LSDKChatMessageContentTextCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
- (instancetype)initWithText:(NSString *)text __attribute__((swift_name("init(text:)"))) __attribute__((objc_designated_initializer));
- (LSDKChatMessageContentText *)doCopyText:(NSString *)text __attribute__((swift_name("doCopy(text:)")));

/** Pure text content. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Pure text content. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Pure text content. */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Pure text content. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.TextCompanion")))
@interface LSDKChatMessageContentTextCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKChatMessageContentTextCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));

/** Pure text content. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/** Pure text content. */
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Minimal serializer for ChatMessageContent.Audio that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContentAudioSerializer")))
@interface LSDKChatMessageContentAudioSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKChatMessageContentAudioSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Minimal serializer for ChatMessageContent.Audio that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageContentAudioSerializer __attribute__((swift_name("init()")));
- (LSDKChatMessageContentAudio *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(LSDKChatMessageContentAudio *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end


/**
 * Minimal serializer for ChatMessageContent.Image that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContentImageSerializer")))
@interface LSDKChatMessageContentImageSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKChatMessageContentImageSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Minimal serializer for ChatMessageContent.Image that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageContentImageSerializer __attribute__((swift_name("init()")));
- (LSDKChatMessageContentImage *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(LSDKChatMessageContentImage *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end


/**
 * Kotlinx serializer for [ChatMessage] that preserves the existing OpenAI-compatible JSON shape
 * without requiring an intermediate DTO.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageJsonSerializer")))
@interface LSDKChatMessageJsonSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKChatMessageJsonSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Kotlinx serializer for [ChatMessage] that preserves the existing OpenAI-compatible JSON shape
 * without requiring an intermediate DTO.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageJsonSerializer __attribute__((swift_name("init()")));
- (LSDKChatMessage *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(LSDKChatMessage *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationFinishReason")))
@interface LSDKGenerationFinishReason : LSDKKotlinEnum<LSDKGenerationFinishReason *>
@property (class, readonly) LSDKGenerationFinishReason *stop __attribute__((swift_name("stop")));
@property (class, readonly) LSDKGenerationFinishReason *exceedContext __attribute__((swift_name("exceedContext")));
@property (class, readonly) LSDKGenerationFinishReason *interrupted __attribute__((swift_name("interrupted")));
@property (class, readonly) LSDKGenerationFinishReason *constraint __attribute__((swift_name("constraint")));
@property (class, readonly) LSDKGenerationFinishReason *error __attribute__((swift_name("error")));
@property (class, readonly) NSArray<LSDKGenerationFinishReason *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKGenerationFinishReason *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationStats")))
@interface LSDKGenerationStats : LSDKBase
@property (readonly) int64_t cachedPromptTokens __attribute__((swift_name("cachedPromptTokens")));
@property (readonly) int64_t completionTokens __attribute__((swift_name("completionTokens")));
@property (readonly) int64_t promptTokens __attribute__((swift_name("promptTokens")));
@property (readonly) float tokenPerSecond __attribute__((swift_name("tokenPerSecond")));
@property (readonly) int64_t totalTokens __attribute__((swift_name("totalTokens")));
- (instancetype)initWithPromptTokens:(int64_t)promptTokens completionTokens:(int64_t)completionTokens totalTokens:(int64_t)totalTokens tokenPerSecond:(float)tokenPerSecond cachedPromptTokens:(int64_t)cachedPromptTokens __attribute__((swift_name("init(promptTokens:completionTokens:totalTokens:tokenPerSecond:cachedPromptTokens:)"))) __attribute__((objc_designated_initializer));
- (LSDKGenerationStats *)doCopyPromptTokens:(int64_t)promptTokens completionTokens:(int64_t)completionTokens totalTokens:(int64_t)totalTokens tokenPerSecond:(float)tokenPerSecond cachedPromptTokens:(int64_t)cachedPromptTokens __attribute__((swift_name("doCopy(promptTokens:completionTokens:totalTokens:tokenPerSecond:cachedPromptTokens:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Number of prompt tokens restored from KV cache (not recomputed). */

/** Number of tokens in the generated completion. */

/** Number of prompt tokens that were computed (excludes tokens restored from KV cache). */

/** Average number of generated tokens per second during the whole generation. */

/** Total number of tokens used in the request (prompt + completion). */
@end


/** A piece of response from generation. */
__attribute__((swift_name("MessageResponse")))
@protocol LSDKMessageResponse
@required
@end


/** Audio content generated by the model. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseAudioSample")))
@interface LSDKMessageResponseAudioSample : LSDKBase <LSDKMessageResponse>
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@property (readonly) LSDKKotlinFloatArray *samples __attribute__((swift_name("samples")));
- (instancetype)initWithSamples:(LSDKKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("init(samples:sampleRate:)"))) __attribute__((objc_designated_initializer));
- (LSDKMessageResponseAudioSample *)doCopySamples:(LSDKKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("doCopy(samples:sampleRate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * A chunk of generated output. The generation is still ongoing and its `text` field may contain
 * one or more tokens.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseChunk")))
@interface LSDKMessageResponseChunk : LSDKBase <LSDKMessageResponse>
@property (readonly) NSString *text __attribute__((swift_name("text")));
- (instancetype)initWithText:(NSString *)text __attribute__((swift_name("init(text:)"))) __attribute__((objc_designated_initializer));
- (LSDKMessageResponseChunk *)doCopyText:(NSString *)text __attribute__((swift_name("doCopy(text:)")));

/**
 * A chunk of generated output. The generation is still ongoing and its `text` field may contain
 * one or more tokens.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * A chunk of generated output. The generation is still ongoing and its `text` field may contain
 * one or more tokens.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * A chunk of generated output. The generation is still ongoing and its `text` field may contain
 * one or more tokens.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Indicates the generation is done. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseComplete")))
@interface LSDKMessageResponseComplete : LSDKBase <LSDKMessageResponse>
@property (readonly) LSDKGenerationFinishReason *finishReason __attribute__((swift_name("finishReason")));
@property (readonly) LSDKChatMessage *fullMessage __attribute__((swift_name("fullMessage")));
@property (readonly) LSDKGenerationStats * _Nullable stats __attribute__((swift_name("stats")));
- (instancetype)initWithFullMessage:(LSDKChatMessage *)fullMessage finishReason:(LSDKGenerationFinishReason *)finishReason stats:(LSDKGenerationStats * _Nullable)stats __attribute__((swift_name("init(fullMessage:finishReason:stats:)"))) __attribute__((objc_designated_initializer));
- (LSDKMessageResponseComplete *)doCopyFullMessage:(LSDKChatMessage *)fullMessage finishReason:(LSDKGenerationFinishReason *)finishReason stats:(LSDKGenerationStats * _Nullable)stats __attribute__((swift_name("doCopy(fullMessage:finishReason:stats:)")));

/** Indicates the generation is done. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Indicates the generation is done. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Indicates the generation is done. */
- (NSString *)description __attribute__((swift_name("description()")));

/** The reason why generation finished. */

/** The complete message generated from this generation request. */

/** Statistics about this generation like how many prompt tokens and completion tokens. */
@end


/** Parsed function call content. Only models that support function calls can emit this chunk. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseFunctionCalls")))
@interface LSDKMessageResponseFunctionCalls : LSDKBase <LSDKMessageResponse>
@property (readonly) NSArray<LSDKLeapFunctionCall *> *functionCalls __attribute__((swift_name("functionCalls")));
- (instancetype)initWithFunctionCalls:(NSArray<LSDKLeapFunctionCall *> *)functionCalls __attribute__((swift_name("init(functionCalls:)"))) __attribute__((objc_designated_initializer));
- (LSDKMessageResponseFunctionCalls *)doCopyFunctionCalls:(NSArray<LSDKLeapFunctionCall *> *)functionCalls __attribute__((swift_name("doCopy(functionCalls:)")));

/** Parsed function call content. Only models that support function calls can emit this chunk. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Parsed function call content. Only models that support function calls can emit this chunk. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Parsed function call content. Only models that support function calls can emit this chunk. */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * A chunk of generated reasoning content. The generation is still ongoing and its `reasoning`
 * field may contain one or more tokens. Reasoning content should not be considered as part of the
 * history, and it should be displayed separately.
 *
 * Only reasoning models should emit this chunk.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseReasoningChunk")))
@interface LSDKMessageResponseReasoningChunk : LSDKBase <LSDKMessageResponse>
@property (readonly) NSString *reasoning __attribute__((swift_name("reasoning")));
- (instancetype)initWithReasoning:(NSString *)reasoning __attribute__((swift_name("init(reasoning:)"))) __attribute__((objc_designated_initializer));
- (LSDKMessageResponseReasoningChunk *)doCopyReasoning:(NSString *)reasoning __attribute__((swift_name("doCopy(reasoning:)")));

/**
 * A chunk of generated reasoning content. The generation is still ongoing and its `reasoning`
 * field may contain one or more tokens. Reasoning content should not be considered as part of the
 * history, and it should be displayed separately.
 *
 * Only reasoning models should emit this chunk.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * A chunk of generated reasoning content. The generation is still ongoing and its `reasoning`
 * field may contain one or more tokens. Reasoning content should not be considered as part of the
 * history, and it should be displayed separately.
 *
 * Only reasoning models should emit this chunk.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * A chunk of generated reasoning content. The generation is still ongoing and its `reasoning`
 * field may contain one or more tokens. Reasoning content should not be considered as part of the
 * history, and it should be displayed separately.
 *
 * Only reasoning models should emit this chunk.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArtifactVersion")))
@interface LSDKArtifactVersion : LSDKBase
@property (class, readonly, getter=shared) LSDKArtifactVersion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)artifactVersion __attribute__((swift_name("init()")));
@end


/**
 * Custom serializer for ByteArray that encodes/decodes using Base64.
 *
 * This is used for binary data like images and audio in chat messages, allowing them to be
 * transmitted as strings in JSON format.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ByteArrayBase64Serializer")))
@interface LSDKByteArrayBase64Serializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKByteArrayBase64Serializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Custom serializer for ByteArray that encodes/decodes using Base64.
 *
 * This is used for binary data like images and audio in chat messages, allowing them to be
 * transmitted as strings in JSON format.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)byteArrayBase64Serializer __attribute__((swift_name("init()")));
- (LSDKKotlinByteArray *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(LSDKKotlinByteArray *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end


/**
 * Custom serializer for Map<LeapStr, JsonElement>.
 *
 * This is used for flexible JSON arguments in function calls where the structure is not known at
 * compile time. The map can contain any JSON-compatible values.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonElementMapSerializer")))
@interface LSDKJsonElementMapSerializer : LSDKBase <LSDKKotlinx_serialization_coreKSerializer>
@property (class, readonly, getter=shared) LSDKJsonElementMapSerializer *shared __attribute__((swift_name("shared")));
@property (readonly) id<LSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Custom serializer for Map<LeapStr, JsonElement>.
 *
 * This is used for flexible JSON arguments in function calls where the structure is not known at
 * compile time. The map can contain any JSON-compatible values.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jsonElementMapSerializer __attribute__((swift_name("init()")));
- (NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)deserializeDecoder:(id<LSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LSDKKotlinx_serialization_coreEncoder>)encoder value:(NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)value __attribute__((swift_name("serialize(encoder:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GeneratableFactory")))
@interface LSDKGeneratableFactory : LSDKBase
@property (class, readonly, getter=shared) LSDKGeneratableFactory *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)generatableFactory __attribute__((swift_name("init()")));

/**
 * @note This method converts instances of LeapGeneratableDeserializationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (id _Nullable)createFromJsonObjectJsonObject:(NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)jsonObject error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("createFromJsonObject(jsonObject:)")));

/**
 * Create generatable object instances from JSON object.
 *
 * @param jsonObject JsonObject to be deserialized into a data class object.
 * @param serializer [KSerializer] of the data class for creating the JSONSchema.
 *
 * @note This method converts instances of LeapGeneratableDeserializationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (id _Nullable)createFromJsonObjectJsonObject:(NSDictionary<NSString *, LSDKKotlinx_serialization_jsonJsonElement *> *)jsonObject serializer:(id<LSDKKotlinx_serialization_coreKSerializer>)serializer error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("createFromJsonObject(jsonObject:serializer:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JSONSchemaGenerator")))
@interface LSDKJSONSchemaGenerator : LSDKBase
@property (class, readonly, getter=shared) LSDKJSONSchemaGenerator *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jSONSchemaGenerator __attribute__((swift_name("init()")));

/**
 * Generate a JSON Schema string from a data class [T]. This JSON Schema string can be used in
 * both the prompt and the constraint.
 *
 * @param indentSpaces intent spaces for adding indent in the generated string. `null` value will
 *   create outputs without indents
 */
- (NSString *)getJSONSchemaIndentSpaces:(LSDKInt * _Nullable)indentSpaces __attribute__((swift_name("getJSONSchema(indentSpaces:)")));

/**
 * Generate a JSON Schema string from a data class serializer. This JSON Schema string can be used
 * in both the prompt and the constraint.
 *
 * @param serializer [KSerializer] of the data class for creating the JSONSchema.
 * @param indentSpaces intent spaces for adding indent in the generated string. `null` value will
 *   create outputs without indents
 */
- (NSString *)getJSONSchemaSerializer:(id<LSDKKotlinx_serialization_coreKSerializer>)serializer indentSpaces:(LSDKInt * _Nullable)indentSpaces __attribute__((swift_name("getJSONSchema(serializer:indentSpaces:)")));
@end


/** Exception in creating generatable objects from JSON. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGeneratableDeserializationException")))
@interface LSDKLeapGeneratableDeserializationException : LSDKLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Exception in creating the JSONSchema for a generatable data class. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGeneratableSchematizationException")))
@interface LSDKLeapGeneratableSchematizationException : LSDKLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieColdFlowIterator")))
@interface LSDKSkieColdFlowIterator<E> : LSDKBase
- (instancetype)initWithFlow:(id<LSDKKotlinx_coroutines_coreFlow>)flow __attribute__((swift_name("init(flow:)"))) __attribute__((objc_designated_initializer));
- (void)cancel __attribute__((swift_name("cancel()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)hasNextWithCompletionHandler:(void (^)(LSDKBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("hasNext(completionHandler:)")));
- (E _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol LSDKKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinFlow")))
@interface LSDKSkieKotlinFlow<__covariant T> : LSDKBase <LSDKKotlinx_coroutines_coreFlow>
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol LSDKKotlinx_coroutines_coreSharedFlow <LSDKKotlinx_coroutines_coreFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol LSDKKotlinx_coroutines_coreFlowCollector
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
@protocol LSDKKotlinx_coroutines_coreMutableSharedFlow <LSDKKotlinx_coroutines_coreSharedFlow, LSDKKotlinx_coroutines_coreFlowCollector>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(id _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@property (readonly) id<LSDKKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinMutableSharedFlow")))
@interface LSDKSkieKotlinMutableSharedFlow<T> : LSDKBase <LSDKKotlinx_coroutines_coreMutableSharedFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LSDKKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreMutableSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));

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
@protocol LSDKKotlinx_coroutines_coreStateFlow <LSDKKotlinx_coroutines_coreSharedFlow>
@required
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreMutableStateFlow")))
@protocol LSDKKotlinx_coroutines_coreMutableStateFlow <LSDKKotlinx_coroutines_coreStateFlow, LSDKKotlinx_coroutines_coreMutableSharedFlow>
@required
- (void)setValue:(id _Nullable)value __attribute__((swift_name("setValue(_:)")));
- (BOOL)compareAndSetExpect:(id _Nullable)expect update:(id _Nullable)update __attribute__((swift_name("compareAndSet(expect:update:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinMutableStateFlow")))
@interface LSDKSkieKotlinMutableStateFlow<T> : LSDKBase <LSDKKotlinx_coroutines_coreMutableStateFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LSDKKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@property T value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreMutableStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
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
@interface LSDKSkieKotlinOptionalFlow<__covariant T> : LSDKBase <LSDKKotlinx_coroutines_coreFlow>
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalMutableSharedFlow")))
@interface LSDKSkieKotlinOptionalMutableSharedFlow<T> : LSDKBase <LSDKKotlinx_coroutines_coreMutableSharedFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LSDKKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreMutableSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));

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
@interface LSDKSkieKotlinOptionalMutableStateFlow<T> : LSDKBase <LSDKKotlinx_coroutines_coreMutableStateFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) id<LSDKKotlinx_coroutines_coreStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@property T _Nullable value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreMutableStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
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
@interface LSDKSkieKotlinOptionalSharedFlow<__covariant T> : LSDKBase <LSDKKotlinx_coroutines_coreSharedFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinOptionalStateFlow")))
@interface LSDKSkieKotlinOptionalStateFlow<__covariant T> : LSDKBase <LSDKKotlinx_coroutines_coreStateFlow>
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) T _Nullable value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinSharedFlow")))
@interface LSDKSkieKotlinSharedFlow<__covariant T> : LSDKBase <LSDKKotlinx_coroutines_coreSharedFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreSharedFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SkieKotlinStateFlow")))
@interface LSDKSkieKotlinStateFlow<__covariant T> : LSDKBase <LSDKKotlinx_coroutines_coreStateFlow>
@property (readonly) NSArray<T> *replayCache __attribute__((swift_name("replayCache")));
@property (readonly) T value __attribute__((swift_name("value")));
- (instancetype)initWithDelegate:(id<LSDKKotlinx_coroutines_coreStateFlow>)delegate __attribute__((swift_name("init(_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_CancellationHandler")))
@interface LSDKSkie_CancellationHandler : LSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)cancel __attribute__((swift_name("cancel()")));
@end

__attribute__((swift_name("Skie_DispatcherDelegate")))
@protocol LSDKSkie_DispatcherDelegate
@required
- (void)dispatchBlock:(id<LSDKKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendHandler")))
@interface LSDKSkie_SuspendHandler : LSDKBase
- (instancetype)initWithCancellationHandler:(LSDKSkie_CancellationHandler *)cancellationHandler dispatcherDelegate:(id<LSDKSkie_DispatcherDelegate>)dispatcherDelegate onResult:(void (^)(LSDKSkie_SuspendResult *))onResult __attribute__((swift_name("init(cancellationHandler:dispatcherDelegate:onResult:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Skie_SuspendResult")))
@interface LSDKSkie_SuspendResult : LSDKBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendResult.Canceled")))
@interface LSDKSkie_SuspendResultCanceled : LSDKSkie_SuspendResult
@property (class, readonly, getter=shared) LSDKSkie_SuspendResultCanceled *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)canceled __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendResult.Error")))
@interface LSDKSkie_SuspendResultError : LSDKSkie_SuspendResult
@property (readonly) NSError *error __attribute__((swift_name("error")));
- (instancetype)initWithError:(NSError *)error __attribute__((swift_name("init(error:)"))) __attribute__((objc_designated_initializer));
- (LSDKSkie_SuspendResultError *)doCopyError:(NSError *)error __attribute__((swift_name("doCopy(error:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Skie_SuspendResult.Success")))
@interface LSDKSkie_SuspendResultSuccess : LSDKSkie_SuspendResult
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(id _Nullable)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKSkie_SuspendResultSuccess *)doCopyValue:(id _Nullable)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

@interface LSDKLeapFunction (Extensions)
- (LSDKLeapFunctionDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface LSDKLeapFunctionDto (Extensions)
- (LSDKLeapFunction *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface LSDKLeapFunctionParameter (Extensions)
- (LSDKLeapFunctionParameterDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface LSDKLeapFunctionParameterDto (Extensions)
- (LSDKLeapFunctionParameter *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface LSDKLeapFunctionParameterType (Extensions)
- (LSDKLeapFunctionParameterTypeDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface LSDKLeapFunctionParameterTypeDto (Extensions)
- (LSDKLeapFunctionParameterType *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface LSDKEngineOptionsCacheOptions (Extensions)

/**
 * Resolve the disk-cap to send to the engine. The chain is:
 * 1. Cache off (returns 0) when `enabled = false`.
 * 2. `maxEntriesDisk` if explicitly set (> 0).
 * 3. Legacy `maxEntries` if it's the only positive cap (callers that pre-date per-tier API).
 * 4. [CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK] (4096) — ergonomic fallback for the
 *    `CacheOptions(path, enabled = true)` shape. Required because the Rust engine validates
 *    `enabled = true && maxEntriesDisk == 0` as illegal.
 *
 * Used by every binding (`jvmMain`/`androidMain` `toJni`, `nativeMain` cinterop, Apple compat) so
 * the resolution stays in one place.
 */
- (int32_t)resolvedMaxEntriesDisk __attribute__((swift_name("resolvedMaxEntriesDisk()")));
@end

@interface LSDKGenerationTimeParameters (Extensions)
- (LSDKGenerationOptions *)toGenerationOptions __attribute__((swift_name("toGenerationOptions()")));
@end

@interface LSDKChatMessageContentCompanion (Extensions)

/**
 * Create an Audio content object from raw bytes with an explicit format string.
 *
 * Unlike [fromWAVData], this method performs no format validation on the provided bytes. Use it
 * when you already know the format and want to skip validation overhead.
 *
 * Usage from Swift:
 * ```swift
 * let content = ChatMessageContent.companion.audio(nsData: data as NSData, format: "wav")
 * ```
 *
 * @param nsData Raw audio bytes (e.g. WAV file contents).
 * @param format Audio format identifier; defaults to `"wav"`.
 * @return ChatMessageContent.Audio containing the provided bytes.
 */
- (LSDKChatMessageContentAudio *)audioNsData:(NSData *)nsData format:(NSString *)format __attribute__((swift_name("audio(nsData:format:)")));

/**
 * Create an Audio content object from floating-point samples (FloatArray variant).
 *
 * This is a more efficient overload that avoids copying the array.
 *
 * @param samples Interleaved PCM float samples (expected range: [-1.0, 1.0])
 * @param sampleRate The audio sample rate in Hz (must be positive)
 * @param channelCount The number of interleaved channels (defaults to mono, must be positive)
 * @return ChatMessageContent.Audio containing WAV-encoded data
 * @throws IllegalArgumentException if parameters are invalid or samples are out of range
 */
- (LSDKChatMessageContentAudio *)fromFloatSamplesSamples:(LSDKKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate channelCount:(int32_t)channelCount __attribute__((swift_name("fromFloatSamples(samples:sampleRate:channelCount:)")));

/**
 * Create an Audio content object from floating-point samples.
 *
 * The samples are expected to be normalized in the range [-1, 1]. This method creates a
 * FloatAudioBuffer, populates it with the samples, and converts it to WAV format (32-bit float
 * PCM).
 *
 * Usage from Swift:
 * ```swift
 * let samples: [Float] = [0.1, 0.2, -0.1, ...]
 * let content = ChatMessageContent.Companion.fromFloatSamples(
 *     samples: samples,
 *     sampleRate: 16000,
 *     channelCount: 1
 * )
 * ```
 *
 * @param samples Interleaved PCM float samples (expected range: [-1.0, 1.0])
 * @param sampleRate The audio sample rate in Hz (must be positive)
 * @param channelCount The number of interleaved channels (defaults to mono, must be positive)
 * @return ChatMessageContent.Audio containing WAV-encoded data
 * @throws IllegalArgumentException if parameters are invalid or samples are out of range
 */
- (LSDKChatMessageContentAudio *)fromFloatSamplesSamples:(NSArray<LSDKFloat *> *)samples sampleRate:(int32_t)sampleRate channelCount_:(int32_t)channelCount __attribute__((swift_name("fromFloatSamples(samples:sampleRate:channelCount_:)")));

/**
 * Create an Image content object from JPEG data.
 *
 * This is the foundational method for creating image content. Platform-specific image types
 * (UIImage, NSImage) should be converted to JPEG NSData before calling this method.
 *
 * The JPEG data is validated to ensure it contains valid JPEG markers (SOI and EOI).
 *
 * Usage from Swift:
 * ```swift
 * let jpegData = image.jpegData(compressionQuality: 0.85)
 * let content = ChatMessageContent.Companion.fromJPEGData(jpegData: jpegData!)
 * ```
 *
 * @param jpegData The JPEG-encoded image data as NSData
 * @return ChatMessageContent.Image with the provided JPEG data
 * @throws IllegalArgumentException if data is empty, too small, or lacks valid JPEG markers
 */
- (LSDKChatMessageContentImage *)fromJPEGDataJpegData:(NSData *)jpegData __attribute__((swift_name("fromJPEGData(jpegData:)")));

/**
 * Create an Image content object from a UIImage (iOS only).
 *
 * This provides backward compatibility with the old iOS SDK API. The UIImage is converted to JPEG
 * format with 85% quality before being wrapped as ChatMessageContent.Image.
 *
 * Usage from Swift:
 * ```swift
 * let content = try ChatMessageContent.fromUIImage(image)
 * ```
 *
 * @param image The UIImage to convert
 * @return ChatMessageContent.Image with JPEG-encoded image data
 * @throws IllegalArgumentException if image cannot be converted to JPEG
 */
- (LSDKChatMessageContentImage *)fromUIImageImage:(UIImage *)image __attribute__((swift_name("fromUIImage(image:)")));

/**
 * Create an Audio content object from WAV data.
 *
 * The WAV data is validated to ensure it contains proper RIFF/WAVE headers and required chunks.
 *
 * Usage from Swift:
 * ```swift
 * let content = ChatMessageContent.Companion.fromWAVData(wavData: wavData)
 * ```
 *
 * @param wavData The WAV-encoded audio data as NSData
 * @return ChatMessageContent.Audio with the provided audio data
 * @throws IllegalArgumentException if data is invalid or missing required WAV structure
 */
- (LSDKChatMessageContentAudio *)fromWAVDataWavData:(NSData *)wavData __attribute__((swift_name("fromWAVData(wavData:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArrayConversionsKt")))
@interface LSDKArrayConversionsKt : LSDKBase

/** Convert a [ByteArray] to [NSData] via a single bulk memcpy. */
+ (NSData *)byteArrayToNSDataArray:(LSDKKotlinByteArray *)array __attribute__((swift_name("byteArrayToNSData(array:)")));

/** Convert a [FloatArray] to [NSData] (raw IEEE 754 bytes) via a single bulk memcpy. */
+ (NSData *)floatArrayToNSDataArray:(LSDKKotlinFloatArray *)array __attribute__((swift_name("floatArrayToNSData(array:)")));

/** Convert [NSData] (raw IEEE 754 bytes) to a [FloatArray] via a single bulk memcpy. */
+ (LSDKKotlinFloatArray *)nsDataToFloatArrayData:(NSData *)data __attribute__((swift_name("nsDataToFloatArray(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContentHelpersKt")))
@interface LSDKChatMessageContentHelpersKt : LSDKBase

/**
 * Create a ChatMessageContent from a UIImage.
 *
 * Usage from Swift:
 * ```swift
 * let content = try ChatMessageContent_fromUIImage(image)
 * ```
 */
+ (LSDKChatMessageContent *)ChatMessageContent_fromUIImageImage:(UIImage *)image __attribute__((swift_name("ChatMessageContent_fromUIImage(image:)")));

/**
 * Create a ChatMessageContent from text.
 *
 * Usage from Swift:
 * ```swift
 * let content = ChatMessageContent_text("Hello")
 * ```
 */
+ (LSDKChatMessageContent *)ChatMessageContent_textText:(NSString *)text __attribute__((swift_name("ChatMessageContent_text(text:)")));

/**
 * Create a ChatMessage with content array (for Swift compatibility).
 *
 * This overload accepts an array of ChatMessageContent, matching the old iOS SDK.
 *
 * Usage from Swift:
 * ```swift
 * let message = ChatMessage_withArray(role: .user, content: messageContent)
 * ```
 */
+ (LSDKChatMessage *)ChatMessage_withArrayRole:(LSDKChatMessageRole *)role content:(NSArray<LSDKChatMessageContent *> *)content __attribute__((swift_name("ChatMessage_withArray(role:content:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConversationExtensionsKt")))
@interface LSDKConversationExtensionsKt : LSDKBase

/**
 * Create a new Conversation with a ModelRunner and optional initial history.
 *
 * This provides backward compatibility with the old iOS SDK API where Conversation could be
 * directly constructed.
 *
 * Usage from Swift:
 * ```swift
 * let conversation = Conversation(modelRunner: runner, history: [])
 * ```
 *
 * @param modelRunner The ModelRunner to use for inference
 * @param history Initial conversation history (defaults to empty list)
 * @return A new Conversation instance
 */
+ (id<LSDKConversation>)ConversationModelRunner:(id<LSDKModelRunner>)modelRunner history:(NSArray<LSDKChatMessage *> *)history __attribute__((swift_name("Conversation(modelRunner:history:)")));

/**
 * Export the conversation history to JSON format.
 *
 * This method serializes the conversation's message history to a JSON string that can be used for
 * persistence, debugging, or transferring the conversation state.
 *
 * @return A JSON string representation of the conversation history
 *
 * Example:
 * ```swift
 * let conversation = runner.createConversation()
 * // ... add messages and generate responses ...
 * let jsonHistory = conversation.exportToJSON()
 * // Save or transmit jsonHistory
 * ```
 */
+ (NSString *)exportToJSON:(id<LSDKConversation>)receiver __attribute__((swift_name("exportToJSON(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineOptionsKt")))
@interface LSDKEngineOptionsKt : LSDKBase
@property (class, readonly) int64_t CACHE_OPTIONS_DEFAULT_MAX_BYTES_MEMORY __attribute__((swift_name("CACHE_OPTIONS_DEFAULT_MAX_BYTES_MEMORY")));
@property (class, readonly) int32_t CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK __attribute__((swift_name("CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK")));
@property (class, readonly) int32_t CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_MEMORY __attribute__((swift_name("CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_MEMORY")));

/**
 * Engine-side defaults for the bounded-LRU `CacheOptions` size caps, shared between the `expect`
 * constructor and the resolution chain in `resolvedMaxEntriesDisk`.
 *
 * Keep these in sync with the engine-side defaults in `inference_engine`'s
 * `crates/ie-core/src/loader.rs` (`CacheOptions::default()`); the Rust side is the source of truth
 * because validation happens there.
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader_appleKt")))
@interface LSDKLeapDownloader_appleKt : LSDKBase
+ (LSDKKtor_client_coreHttpClient *)buildHttpClientJson:(LSDKKotlinx_serialization_jsonJson *)json installCache:(BOOL)installCache followRedirects:(BOOL)followRedirects expectSuccess:(BOOL)expectSuccess disableSslValidation:(BOOL)disableSslValidation connectTimeoutMillis:(int64_t)connectTimeoutMillis socketTimeoutMillis:(int64_t)socketTimeoutMillis requestTimeoutMillis:(int64_t)requestTimeoutMillis __attribute__((swift_name("buildHttpClient(json:installCache:followRedirects:expectSuccess:disableSslValidation:connectTimeoutMillis:socketTimeoutMillis:requestTimeoutMillis:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloaderKt")))
@interface LSDKLeapDownloaderKt : LSDKBase
+ (LSDKKtor_client_coreHttpClient *)defaultClientJson:(LSDKKotlinx_serialization_jsonJson *)json config:(LSDKLeapDownloaderConfig *)config __attribute__((swift_name("defaultClient(json:config:)")));
+ (LSDKKtor_client_coreHttpClient *)defaultClientCacheJson:(LSDKKotlinx_serialization_jsonJson *)json config:(LSDKLeapDownloaderConfig *)config __attribute__((swift_name("defaultClientCache(json:config:)")));
+ (LSDKKtor_client_coreHttpClient *)defaultNoRedirectClientJson:(LSDKKotlinx_serialization_jsonJson *)json config:(LSDKLeapDownloaderConfig *)config __attribute__((swift_name("defaultNoRedirectClient(json:config:)")));
+ (NSString *)manifestFilenameModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("manifestFilename(modelName:quantizationSlug:)")));
+ (NSString *)manifestUrlModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug baseUrl:(NSString *)baseUrl __attribute__((swift_name("manifestUrl(modelName:quantizationSlug:baseUrl:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapJsonKt")))
@interface LSDKLeapJsonKt : LSDKBase
@property (class, readonly) LSDKKotlinx_serialization_jsonJson *LeapJson __attribute__((swift_name("LeapJson")));
@property (class, readonly) LSDKKotlinx_serialization_jsonJson *LeapJsonPretty __attribute__((swift_name("LeapJsonPretty")));

/**
 * Shared JSON configuration for Leap SDK serialization.
 *
 * This instance is configured to:
 * - Ignore unknown fields in JSON (for forward compatibility)
 * - Not encode default/null values (reduce payload size)
 * - Coerce invalid values to defaults (defensive parsing)
 * - Not write explicit nulls in JSON output
 */

/**
 * JSON configuration with pretty printing enabled for human-readable output.
 *
 * Used for debugging, schema generation, and formatted JSON output.
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSinkKt")))
@interface LSDKProgressReportingSinkKt : LSDKBase

/** Extension function to easily wrap any existing Sink with progress reporting. */
+ (id<LSDKKotlinx_io_coreRawSink>)withProgressListener:(id<LSDKKotlinx_io_coreRawSink>)receiver progressListener:(void (^)(LSDKLong *))progressListener __attribute__((swift_name("withProgressListener(_:progressListener:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSourceKt")))
@interface LSDKProgressReportingSourceKt : LSDKBase

/** Extension function to easily wrap any existing RawSource with progress reporting. */
+ (id<LSDKKotlinx_io_coreRawSource>)withProgressListener:(id<LSDKKotlinx_io_coreRawSource>)receiver progressListener:(void (^)(LSDKLong *))progressListener __attribute__((swift_name("withProgressListener(_:progressListener:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilsKt")))
@interface LSDKUtilsKt : LSDKBase

/**
 * Delete the given path, recursively if needed
 *
 * @throws kotlinx.io.files.FileNotFoundException - when [path] does not exist and [mustExist] is
 *   `true`
 * @throws kotlinx.io.IOException if there was an underlying error preventing listing the [path]'s
 *   children if it was a directory
 */
+ (void)deleteRecursively:(id<LSDKKotlinx_io_coreFileSystem>)receiver path:(LSDKKotlinx_io_corePath *)path mustExist:(BOOL)mustExist __attribute__((swift_name("deleteRecursively(_:path:mustExist:)")));
+ (NSString *)extractBaseUrl:(NSString *)receiver __attribute__((swift_name("extractBaseUrl(_:)")));
+ (NSString *)extractFilename:(NSString *)receiver __attribute__((swift_name("extractFilename(_:)")));

/**
 * Extract a compact model name from a Hugging Face URL.
 *
 * Example: https://huggingface.co/LiquidAI/LFM2-1.2B-GGUF/resolve/main/leap/Q4_K_M.json ->
 * LFM2-1.2B-GGUF-leap-Q4_K_M
 *
 * Convention: If the URL contains ".../<repo>/resolve/<branch>/<subpaths...>/<filename>", the model
 * name is: <repo>-<subpaths-joined-with-dashes>-<filenameWithoutExtension>. If there are no
 * subpaths after the branch, it falls back to: <repo>-<filenameWithoutExtension>.
 */
+ (NSString *)extractHfFileName:(NSString *)receiver keepExtension:(BOOL)keepExtension __attribute__((swift_name("extractHfFileName(_:keepExtension:)")));
+ (NSString *)fixRelativeUrl:(NSString *)receiver sourceUrl:(NSString *)sourceUrl __attribute__((swift_name("fixRelativeUrl(_:sourceUrl:)")));
+ (NSString *)getResourceFolder:(NSString *)receiver manifestUrl:(NSString *)manifestUrl __attribute__((swift_name("getResourceFolder(_:manifestUrl:)")));
+ (NSString *)removeQuotes:(NSString *)receiver __attribute__((swift_name("removeQuotes(_:)")));

/**
 * Same as [runCatching], but does not catch [CancellationException], throwing it instead, making it
 * safe to use with coroutines.
 */
+ (id _Nullable)runCatchingCancellableBlock:(id _Nullable (^)(void))block __attribute__((swift_name("runCatchingCancellable(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("__SkieSuspendWrappersKt")))
@interface LSDK__SkieSuspendWrappersKt : LSDKBase
+ (void)Skie_Suspend__0__hasNextDispatchReceiver:(LSDKSkieColdFlowIterator<id> *)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__0__hasNext(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__10__loadModelDispatchReceiver:(LSDKLeapClient *)dispatchReceiver params:(id<LSDKLoadTimeParameters>)params generationParams:(LSDKGenerationTimeParameters * _Nullable)generationParams options:(LSDKModelLoadingOptions * _Nullable)options suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__10__loadModel(dispatchReceiver:params:generationParams:options:suspendHandler:)")));
+ (void)Skie_Suspend__11__loadModelDispatchReceiver:(LSDKLeapInferenceEngine *)dispatchReceiver modelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath options:(LSDKModelLoadingOptions * _Nullable)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__11__loadModel(dispatchReceiver:modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:options:generationTimeParameters:suspendHandler:)")));
+ (void)Skie_Suspend__12__loadDispatchReceiver:(LSDKLeap *)dispatchReceiver url:(NSURL *)url contextSize:(LSDKUInt * _Nullable)contextSize cpuThreads:(LSDKUInt * _Nullable)cpuThreads autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__12__load(dispatchReceiver:url:contextSize:cpuThreads:autoDetectCompanionFiles:suspendHandler:)")));
+ (void)Skie_Suspend__13__loadDispatchReceiver:(LSDKLeap *)dispatchReceiver url:(NSURL *)url options:(LSDKLiquidInferenceEngineOptions * _Nullable)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__13__load(dispatchReceiver:url:options:generationTimeParameters:autoDetectCompanionFiles:suspendHandler:)")));
+ (void)Skie_Suspend__14__loadDispatchReceiver:(LSDKLeap *)dispatchReceiver manifestUrl:(NSURL *)manifestUrl options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__14__load(dispatchReceiver:manifestUrl:options:downloadProgressHandler:suspendHandler:)")));
+ (void)Skie_Suspend__15__loadDispatchReceiver:(LSDKLeap *)dispatchReceiver model:(NSString *)model quantization:(NSString *)quantization options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__15__load(dispatchReceiver:model:quantization:options:downloadProgressHandler:suspendHandler:)")));
+ (void)Skie_Suspend__16__getPromptTokensSizeDispatchReceiver:(LSDKLiquidEngineRunner *)dispatchReceiver messages:(NSArray<LSDKChatMessage *> *)messages addBosToken:(BOOL)addBosToken suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__16__getPromptTokensSize(dispatchReceiver:messages:addBosToken:suspendHandler:)")));
+ (void)Skie_Suspend__17__unloadDispatchReceiver:(LSDKLiquidEngineRunner *)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__17__unload(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__18__getPromptTokensSizeDispatchReceiver:(LSDKLiquidInferenceEngineRunner *)dispatchReceiver messages:(NSArray<LSDKChatMessage *> *)messages addBosToken:(BOOL)addBosToken suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__18__getPromptTokensSize(dispatchReceiver:messages:addBosToken:suspendHandler:)")));
+ (void)Skie_Suspend__19__unloadDispatchReceiver:(LSDKLiquidInferenceEngineRunner *)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__19__unload(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__1__collectDispatchReceiver:(id<LSDKKotlinx_coroutines_coreFlow>)dispatchReceiver collector:(id<LSDKKotlinx_coroutines_coreFlowCollector>)collector suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__1__collect(dispatchReceiver:collector:suspendHandler:)")));
+ (void)Skie_Suspend__20__createDispatchReceiver:(LSDKLiquidInferenceEngineRunnerCompanion *)dispatchReceiver url:(NSURL *)url options:(LSDKLiquidInferenceEngineOptions * _Nullable)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__20__create(dispatchReceiver:url:options:generationTimeParameters:autoDetectCompanionFiles:suspendHandler:)")));
+ (void)Skie_Suspend__21__createDispatchReceiver:(LSDKLiquidInferenceEngineRunnerCompanion *)dispatchReceiver options:(LSDKLiquidInferenceEngineOptions *)options generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__21__create(dispatchReceiver:options:generationTimeParameters:suspendHandler:)")));
+ (void)Skie_Suspend__22__createDispatchReceiver:(LSDKLiquidInferenceEngineRunnerCompanion *)dispatchReceiver model:(NSString *)model quantization:(NSString *)quantization generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__22__create(dispatchReceiver:model:quantization:generationTimeParameters:suspendHandler:)")));
+ (void)Skie_Suspend__23__createDispatchReceiver:(LSDKLiquidInferenceEngineRunnerCompanion *)dispatchReceiver model:(NSString *)model quantization:(NSString *)quantization options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__23__create(dispatchReceiver:model:quantization:options:downloadProgressHandler:suspendHandler:)")));
+ (void)Skie_Suspend__24__createDispatchReceiver:(LSDKLiquidInferenceEngineRunnerCompanion *)dispatchReceiver manifestUrl:(NSURL *)manifestUrl options:(LSDKLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LSDKDouble *, LSDKLong *))downloadProgressHandler suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__24__create(dispatchReceiver:manifestUrl:options:downloadProgressHandler:suspendHandler:)")));
+ (void)Skie_Suspend__25__invokeDispatchReceiver:(LSDKLiquidEngineCompanion *)dispatchReceiver modelURL:(NSURL *)modelURL suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__25__invoke(dispatchReceiver:modelURL:suspendHandler:)")));
+ (void)Skie_Suspend__26__invokeDispatchReceiver:(LSDKLiquidEngineCompanion *)dispatchReceiver modelURL:(NSURL *)modelURL model:(NSString *)model quantization:(NSString *)quantization suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__26__invoke(dispatchReceiver:modelURL:model:quantization:suspendHandler:)")));
+ (void)Skie_Suspend__27__joinDispatchReceiver:(id<LSDKKotlinx_coroutines_coreJob>)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__27__join(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__28__executeDispatchReceiver:(LSDKKtor_utilsPipeline<id, id> *)dispatchReceiver context:(id)context subject:(id)subject suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__28__execute(dispatchReceiver:context:subject:suspendHandler:)")));
+ (void)Skie_Suspend__29__invokeDispatchReceiver:(id<LSDKKotlinSuspendFunction2>)dispatchReceiver p1:(id _Nullable)p1 p2:(id _Nullable)p2 suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__29__invoke(dispatchReceiver:p1:p2:suspendHandler:)")));
+ (void)Skie_Suspend__2__emitDispatchReceiver:(id<LSDKKotlinx_coroutines_coreFlowCollector>)dispatchReceiver value:(id _Nullable)value suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__2__emit(dispatchReceiver:value:suspendHandler:)")));
+ (void)Skie_Suspend__30__bodyDispatchReceiver:(LSDKKtor_client_coreHttpClientCall *)dispatchReceiver info:(LSDKKtor_utilsTypeInfo *)info suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__30__body(dispatchReceiver:info:suspendHandler:)")));
+ (void)Skie_Suspend__31__bodyNullableDispatchReceiver:(LSDKKtor_client_coreHttpClientCall *)dispatchReceiver info:(LSDKKtor_utilsTypeInfo *)info suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__31__bodyNullable(dispatchReceiver:info:suspendHandler:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
+ (void)Skie_Suspend__32__getResponseContentDispatchReceiver:(LSDKKtor_client_coreHttpClientCall *)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__32__getResponseContent(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__33__awaitContentDispatchReceiver:(id<LSDKKtor_ioByteReadChannel>)dispatchReceiver min:(int32_t)min suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__33__awaitContent(dispatchReceiver:min:suspendHandler:)")));
+ (void)Skie_Suspend__34__executeDispatchReceiver:(id<LSDKKtor_client_coreHttpClientEngine>)dispatchReceiver data:(LSDKKtor_client_coreHttpRequestData *)data suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__34__execute(dispatchReceiver:data:suspendHandler:)")));
+ (void)Skie_Suspend__35__deleteModelFileDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelUrl:(NSString *)modelUrl modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__35__deleteModelFile(dispatchReceiver:modelUrl:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__36__deleteModelFromManifestUrlDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver manifestUrl:(NSString *)manifestUrl suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__36__deleteModelFromManifestUrl(dispatchReceiver:manifestUrl:suspendHandler:)")));
+ (void)Skie_Suspend__37__deleteModelResourcesDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__37__deleteModelResources(dispatchReceiver:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__38__downloadModelDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug progress:(void (^)(LSDKProgressData *))progress suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__38__downloadModel(dispatchReceiver:modelName:quantizationSlug:progress:suspendHandler:)")));
+ (void)Skie_Suspend__39__downloadModelFromManifestUrlDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver manifestUrl:(NSString *)manifestUrl progress:(void (^)(LSDKProgressData *))progress suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__39__downloadModelFromManifestUrl(dispatchReceiver:manifestUrl:progress:suspendHandler:)")));
+ (void)Skie_Suspend__3__generateFromConversationDispatchReceiver:(id<LSDKModelRunner>)dispatchReceiver conversation:(id<LSDKConversation>)conversation callback:(id<LSDKModelRunnerGenerationCallback>)callback generationOptions:(LSDKGenerationOptions * _Nullable)generationOptions suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__3__generateFromConversation(dispatchReceiver:conversation:callback:generationOptions:suspendHandler:)")));
+ (void)Skie_Suspend__40__getCachedManifestDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__40__getCachedManifest(dispatchReceiver:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__41__getModelSizeDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__41__getModelSize(dispatchReceiver:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__42__loadModelDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug modelLoadingOptions:(LSDKModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters forceDownload:(BOOL)forceDownload isRetry:(BOOL)isRetry progress:(void (^)(LSDKProgressData *))progress suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__42__loadModel(dispatchReceiver:modelName:quantizationSlug:modelLoadingOptions:generationTimeParameters:forceDownload:isRetry:progress:suspendHandler:)")));
+ (void)Skie_Suspend__43__loadModelFromManifestUrlDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver manifestUrl:(NSString *)manifestUrl modelLoadingOptions:(LSDKModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters progress:(void (^)(LSDKProgressData *))progress suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__43__loadModelFromManifestUrl(dispatchReceiver:manifestUrl:modelLoadingOptions:generationTimeParameters:progress:suspendHandler:)")));
+ (void)Skie_Suspend__44__loadSimpleModelDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver model:(LSDKModelSource *)model modelLoadingOptions:(LSDKModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LSDKGenerationTimeParameters * _Nullable)generationTimeParameters isRetry:(BOOL)isRetry progress:(void (^)(LSDKProgressData *))progress suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__44__loadSimpleModel(dispatchReceiver:model:modelLoadingOptions:generationTimeParameters:isRetry:progress:suspendHandler:)")));
+ (void)Skie_Suspend__45__resolveDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__45__resolve(dispatchReceiver:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__46__resolveDownloadPlanDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__46__resolveDownloadPlan(dispatchReceiver:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__47__resolveDownloadPlanFromManifestUrlDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver manifestUrl:(NSString *)manifestUrl suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__47__resolveDownloadPlanFromManifestUrl(dispatchReceiver:manifestUrl:suspendHandler:)")));
+ (void)Skie_Suspend__48__saveManifestToDiskDispatchReceiver:(LSDKLeapDownloader *)dispatchReceiver manifest:(LSDKManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__48__saveManifestToDisk(dispatchReceiver:manifest:modelName:quantizationSlug:suspendHandler:)")));
+ (void)Skie_Suspend__49__fetchAvailableModelsDispatchReceiver:(LSDKLeapModelsApi *)dispatchReceiver inferenceEngine:(NSString *)inferenceEngine suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__49__fetchAvailableModels(dispatchReceiver:inferenceEngine:suspendHandler:)")));
+ (void)Skie_Suspend__4__getPromptTokensSizeDispatchReceiver:(id<LSDKModelRunner>)dispatchReceiver messages:(NSArray<LSDKChatMessage *> *)messages addBosToken:(BOOL)addBosToken suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__4__getPromptTokensSize(dispatchReceiver:messages:addBosToken:suspendHandler:)")));
+ (void)Skie_Suspend__50__upgradeDispatchReceiver:(LSDKKtor_httpOutgoingContentProtocolUpgrade *)dispatchReceiver input:(id<LSDKKtor_ioByteReadChannel>)input output:(id<LSDKKtor_ioByteWriteChannel>)output engineContext:(id<LSDKKotlinCoroutineContext>)engineContext userContext:(id<LSDKKotlinCoroutineContext>)userContext suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__50__upgrade(dispatchReceiver:input:output:engineContext:userContext:suspendHandler:)")));
+ (void)Skie_Suspend__51__flushDispatchReceiver:(id<LSDKKtor_ioByteWriteChannel>)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__51__flush(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__52__flushAndCloseDispatchReceiver:(id<LSDKKtor_ioByteWriteChannel>)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__52__flushAndClose(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__53__writeToDispatchReceiver:(LSDKKtor_httpOutgoingContentWriteChannelContent *)dispatchReceiver channel:(id<LSDKKtor_ioByteWriteChannel>)channel suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__53__writeTo(dispatchReceiver:channel:suspendHandler:)")));
+ (void)Skie_Suspend__5__unloadDispatchReceiver:(id<LSDKModelRunner>)dispatchReceiver suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__5__unload(dispatchReceiver:suspendHandler:)")));
+ (void)Skie_Suspend__6__lockDispatchReceiver:(id<LSDKKotlinx_coroutines_coreMutex>)dispatchReceiver owner:(id _Nullable)owner suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__6__lock(dispatchReceiver:owner:suspendHandler:)")));
+ (void)Skie_Suspend__7__loadModelDispatchReceiver:(LSDKLeapClient *)dispatchReceiver modelPath:(NSString *)modelPath options:(LSDKModelLoadingOptions * _Nullable)options suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__7__loadModel(dispatchReceiver:modelPath:options:suspendHandler:)")));
+ (void)Skie_Suspend__8__loadModelDispatchReceiver:(LSDKLeapClient *)dispatchReceiver modelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath options:(LSDKModelLoadingOptions * _Nullable)options suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__8__loadModel(dispatchReceiver:modelPath:mmprojPath:options:suspendHandler:)")));
+ (void)Skie_Suspend__9__loadModelDispatchReceiver:(LSDKLeapClient *)dispatchReceiver model:(LSDKAudioGenerationModelDescriptor *)model options:(LSDKModelLoadingOptions * _Nullable)options suspendHandler:(LSDKSkie_SuspendHandler *)suspendHandler __attribute__((swift_name("Skie_Suspend__9__loadModel(dispatchReceiver:model:options:suspendHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("__SkieTypeExportsKt")))
@interface LSDK__SkieTypeExportsKt : LSDKBase
+ (void)skieTypeExports_0P0:(LSDKKtor_httpOutgoingContentByteArrayContent *)p0 p1:(LSDKKtor_httpOutgoingContentContentWrapper *)p1 p2:(LSDKKtor_httpOutgoingContentNoContent *)p2 p3:(LSDKKtor_httpOutgoingContentProtocolUpgrade *)p3 p4:(LSDKKtor_httpOutgoingContentReadChannelContent *)p4 p5:(LSDKKtor_httpOutgoingContentWriteChannelContent *)p5 p6:(id<LSDKKotlinx_coroutines_coreSelectClause1>)p6 p7:(LSDKKotlinx_serialization_corePolymorphicKind *)p7 p8:(LSDKKotlinx_serialization_corePolymorphicKindOPEN *)p8 p9:(LSDKKotlinx_serialization_corePolymorphicKindSEALED *)p9 p10:(LSDKKotlinx_serialization_corePrimitiveKind *)p10 p11:(LSDKKotlinx_serialization_corePrimitiveKindBOOLEAN *)p11 p12:(LSDKKotlinx_serialization_corePrimitiveKindBYTE *)p12 p13:(LSDKKotlinx_serialization_corePrimitiveKindCHAR *)p13 p14:(LSDKKotlinx_serialization_corePrimitiveKindDOUBLE *)p14 p15:(LSDKKotlinx_serialization_corePrimitiveKindFLOAT *)p15 p16:(LSDKKotlinx_serialization_corePrimitiveKindINT *)p16 p17:(LSDKKotlinx_serialization_corePrimitiveKindLONG *)p17 p18:(LSDKKotlinx_serialization_corePrimitiveKindSHORT *)p18 p19:(LSDKKotlinx_serialization_corePrimitiveKindSTRING *)p19 p20:(LSDKKotlinx_serialization_coreSerialKindCONTEXTUAL *)p20 p21:(LSDKKotlinx_serialization_coreSerialKindENUM *)p21 p22:(LSDKKotlinx_serialization_coreStructureKind *)p22 p23:(LSDKKotlinx_serialization_coreStructureKindCLASS *)p23 p24:(LSDKKotlinx_serialization_coreStructureKindLIST *)p24 p25:(LSDKKotlinx_serialization_coreStructureKindMAP *)p25 p26:(LSDKKotlinx_serialization_coreStructureKindOBJECT *)p26 p27:(LSDKKotlinx_serialization_jsonJsonNull *)p27 p28:(LSDKKotlinx_serialization_jsonJsonPrimitive *)p28 __attribute__((swift_name("skieTypeExports_0(p0:p1:p2:p3:p4:p5:p6:p7:p8:p9:p10:p11:p12:p13:p14:p15:p16:p17:p18:p19:p20:p21:p22:p23:p24:p25:p26:p27:p28:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutex")))
@protocol LSDKKotlinx_coroutines_coreMutex
@required
- (BOOL)holdsLockOwner:(id)owner __attribute__((swift_name("holdsLock(owner:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lockOwner:(id _Nullable)owner completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("lock(owner:completionHandler:)")));
- (BOOL)tryLockOwner:(id _Nullable)owner __attribute__((swift_name("tryLock(owner:)")));
- (void)unlockOwner:(id _Nullable)owner __attribute__((swift_name("unlock(owner:)")));
@property (readonly) BOOL isLocked __attribute__((swift_name("isLocked")));
@property (readonly) id<LSDKKotlinx_coroutines_coreSelectClause2> onLock __attribute__((swift_name("onLock"))) __attribute__((deprecated("Mutex.onLock deprecated without replacement. For additional details please refer to #2794")));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface LSDKKotlinIllegalStateException : LSDKKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface LSDKKotlinCancellationException : LSDKKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface LSDKKotlinArray<T> : LSDKBase
@property (readonly) int32_t size __attribute__((swift_name("size")));
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(LSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<LSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinFloatArray")))
@interface LSDKKotlinFloatArray : LSDKBase
@property (readonly) int32_t size __attribute__((swift_name("size")));
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(LSDKFloat *(^)(LSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (float)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LSDKKotlinFloatIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(float)value __attribute__((swift_name("set(index:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface LSDKKotlinByteArray : LSDKBase
@property (readonly) int32_t size __attribute__((swift_name("size")));
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(LSDKByte *(^)(LSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LSDKKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface LSDKKotlinEnumCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonElementSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement")))
@interface LSDKKotlinx_serialization_jsonJsonElement : LSDKBase
@property (class, readonly, getter=companion) LSDKKotlinx_serialization_jsonJsonElementCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol LSDKKotlinx_serialization_coreEncoder
@required
- (id<LSDKKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<LSDKKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<LSDKKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) LSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/serialization/SealedSerializationApi)])
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol LSDKKotlinx_serialization_coreSerialDescriptor
@required
- (NSArray<id<LSDKKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));
- (id<LSDKKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));
@property (readonly) NSArray<id<LSDKKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));
@property (readonly) LSDKKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol LSDKKotlinx_serialization_coreDecoder
@required
- (id<LSDKKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<LSDKKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (LSDKKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) LSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinCharSequence")))
@protocol LSDKKotlinCharSequence
@required
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end

__attribute__((swift_name("KotlinAppendable")))
@protocol LSDKKotlinAppendable
@required

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<LSDKKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<LSDKKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<LSDKKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinStringBuilder")))
@interface LSDKKotlinStringBuilder : LSDKBase <LSDKKotlinCharSequence, LSDKKotlinAppendable>
@property (readonly) int32_t length __attribute__((swift_name("length")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithContent:(id)content __attribute__((swift_name("init(content:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCapacity:(int32_t)capacity __attribute__((swift_name("init(capacity:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent_:(NSString *)content __attribute__((swift_name("init(content_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue__:(id _Nullable)value __attribute__((swift_name("append(value__:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue___:(BOOL)value __attribute__((swift_name("append(value___:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue____:(int8_t)value __attribute__((swift_name("append(value____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue_____:(LSDKKotlinCharArray *)value __attribute__((swift_name("append(value_____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue______:(double)value __attribute__((swift_name("append(value______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue_______:(float)value __attribute__((swift_name("append(value_______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue________:(int32_t)value __attribute__((swift_name("append(value________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue_________:(int64_t)value __attribute__((swift_name("append(value_________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue__________:(int16_t)value __attribute__((swift_name("append(value__________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue___________:(NSString * _Nullable)value __attribute__((swift_name("append(value___________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendRangeValue:(LSDKKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)appendRangeValue:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex_:)")));
- (int32_t)capacity __attribute__((swift_name("capacity()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)deleteAtIndex:(int32_t)index __attribute__((swift_name("deleteAt(index:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)deleteRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("deleteRange(startIndex:endIndex:)")));
- (void)ensureCapacityMinimumCapacity:(int32_t)minimumCapacity __attribute__((swift_name("ensureCapacity(minimumCapacity:)")));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)indexOfString:(NSString *)string __attribute__((swift_name("indexOf(string:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)indexOfString:(NSString *)string startIndex:(int32_t)startIndex __attribute__((swift_name("indexOf(string:startIndex:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value:(id _Nullable)value __attribute__((swift_name("insert(index:value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value_:(BOOL)value __attribute__((swift_name("insert(index:value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value__:(int8_t)value __attribute__((swift_name("insert(index:value__:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value___:(unichar)value __attribute__((swift_name("insert(index:value___:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value____:(LSDKKotlinCharArray *)value __attribute__((swift_name("insert(index:value____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value_____:(id _Nullable)value __attribute__((swift_name("insert(index:value_____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value______:(double)value __attribute__((swift_name("insert(index:value______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value_______:(float)value __attribute__((swift_name("insert(index:value_______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value________:(int32_t)value __attribute__((swift_name("insert(index:value________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value_________:(int64_t)value __attribute__((swift_name("insert(index:value_________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value__________:(int16_t)value __attribute__((swift_name("insert(index:value__________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertIndex:(int32_t)index value___________:(NSString * _Nullable)value __attribute__((swift_name("insert(index:value___________:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(LSDKKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex_:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)lastIndexOfString:(NSString *)string __attribute__((swift_name("lastIndexOf(string:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (int32_t)lastIndexOfString:(NSString *)string startIndex:(int32_t)startIndex __attribute__((swift_name("lastIndexOf(string:startIndex:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)reverse __attribute__((swift_name("reverse()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
- (void)setLengthNewLength:(int32_t)newLength __attribute__((swift_name("setLength(newLength:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LSDKKotlinStringBuilder *)setRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex value:(NSString *)value __attribute__((swift_name("setRange(startIndex:endIndex:value:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (NSString *)substringStartIndex:(int32_t)startIndex __attribute__((swift_name("substring(startIndex:)")));
- (NSString *)substringStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("substring(startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
- (void)toCharArrayDestination:(LSDKKotlinCharArray *)destination destinationOffset:(int32_t)destinationOffset startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("toCharArray(destination:destinationOffset:startIndex:endIndex:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (void)trimToSize __attribute__((swift_name("trimToSize()")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol LSDKKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_bytestringByteString")))
@interface LSDKKotlinx_io_bytestringByteString : LSDKBase <LSDKKotlinComparable>
@property (class, readonly, getter=companion) LSDKKotlinx_io_bytestringByteStringCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
- (instancetype)initWithData:(LSDKKotlinByteArray *)data startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("init(data:startIndex:endIndex:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(LSDKKotlinx_io_bytestringByteString *)other __attribute__((swift_name("compareTo(other:)")));
- (void)doCopyIntoDestination:(LSDKKotlinByteArray *)destination destinationOffset:(int32_t)destinationOffset startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("doCopyInto(destination:destinationOffset:startIndex:endIndex:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (LSDKKotlinx_io_bytestringByteString *)substringStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("substring(startIndex:endIndex:)")));
- (LSDKKotlinByteArray *)toByteArrayStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("toByteArray(startIndex:endIndex:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_io_coreSource")))
@protocol LSDKKotlinx_io_coreSource <LSDKKotlinx_io_coreRawSource>
@required
- (BOOL)exhausted __attribute__((swift_name("exhausted()")));
- (id<LSDKKotlinx_io_coreSource>)peek __attribute__((swift_name("peek()")));
- (int32_t)readAtMostToSink:(LSDKKotlinByteArray *)sink startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("readAtMostTo(sink:startIndex:endIndex:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (int32_t)readInt __attribute__((swift_name("readInt()")));
- (int64_t)readLong __attribute__((swift_name("readLong()")));
- (int16_t)readShort __attribute__((swift_name("readShort()")));
- (void)readToSink:(id<LSDKKotlinx_io_coreRawSink>)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readTo(sink:byteCount:)")));
- (BOOL)requestByteCount:(int64_t)byteCount __attribute__((swift_name("request(byteCount:)")));
- (void)requireByteCount:(int64_t)byteCount __attribute__((swift_name("require(byteCount:)")));
- (void)skipByteCount:(int64_t)byteCount __attribute__((swift_name("skip(byteCount:)")));
- (int64_t)transferToSink:(id<LSDKKotlinx_io_coreRawSink>)sink __attribute__((swift_name("transferTo(sink:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) LSDKKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@end

__attribute__((swift_name("Kotlinx_io_coreSink")))
@protocol LSDKKotlinx_io_coreSink <LSDKKotlinx_io_coreRawSink>
@required
- (void)emit __attribute__((swift_name("emit()")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
- (void)hintEmit __attribute__((swift_name("hintEmit()")));
- (int64_t)transferFromSource:(id<LSDKKotlinx_io_coreRawSource>)source __attribute__((swift_name("transferFrom(source:)")));
- (void)writeSource:(id<LSDKKotlinx_io_coreRawSource>)source byteCount_:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount_:)")));
- (void)writeSource:(LSDKKotlinByteArray *)source startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("write(source:startIndex:endIndex:)")));
- (void)writeByteByte:(int8_t)byte __attribute__((swift_name("writeByte(byte:)")));
- (void)writeIntInt:(int32_t)int_ __attribute__((swift_name("writeInt(int:)")));
- (void)writeLongLong:(int64_t)long_ __attribute__((swift_name("writeLong(long:)")));
- (void)writeShortShort:(int16_t)short_ __attribute__((swift_name("writeShort(short:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) LSDKKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_coreBuffer")))
@interface LSDKKotlinx_io_coreBuffer : LSDKBase <LSDKKotlinx_io_coreSource, LSDKKotlinx_io_coreSink>
@property (readonly) LSDKKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)clear __attribute__((swift_name("clear()")));
- (void)close __attribute__((swift_name("close()")));
- (LSDKKotlinx_io_coreBuffer *)doCopy __attribute__((swift_name("doCopy()")));
- (void)doCopyToOut:(LSDKKotlinx_io_coreBuffer *)out startIndex:(int64_t)startIndex endIndex:(int64_t)endIndex __attribute__((swift_name("doCopyTo(out:startIndex:endIndex:)")));
- (void)emit __attribute__((swift_name("emit()")));
- (BOOL)exhausted __attribute__((swift_name("exhausted()")));
- (void)flush __attribute__((swift_name("flush()")));
- (int8_t)getPosition:(int64_t)position __attribute__((swift_name("get(position:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
- (void)hintEmit __attribute__((swift_name("hintEmit()")));
- (id<LSDKKotlinx_io_coreSource>)peek __attribute__((swift_name("peek()")));
- (int64_t)readAtMostToSink:(LSDKKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
- (int32_t)readAtMostToSink:(LSDKKotlinByteArray *)sink startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("readAtMostTo(sink:startIndex:endIndex:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (int32_t)readInt __attribute__((swift_name("readInt()")));
- (int64_t)readLong __attribute__((swift_name("readLong()")));
- (int16_t)readShort __attribute__((swift_name("readShort()")));
- (void)readToSink:(id<LSDKKotlinx_io_coreRawSink>)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readTo(sink:byteCount:)")));
- (BOOL)requestByteCount:(int64_t)byteCount __attribute__((swift_name("request(byteCount:)")));
- (void)requireByteCount:(int64_t)byteCount __attribute__((swift_name("require(byteCount:)")));
- (void)skipByteCount:(int64_t)byteCount __attribute__((swift_name("skip(byteCount:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (int64_t)transferFromSource:(id<LSDKKotlinx_io_coreRawSource>)source __attribute__((swift_name("transferFrom(source:)")));
- (int64_t)transferToSink:(id<LSDKKotlinx_io_coreRawSink>)sink __attribute__((swift_name("transferTo(sink:)")));
- (void)writeSource:(LSDKKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
- (void)writeSource:(id<LSDKKotlinx_io_coreRawSource>)source byteCount_:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount_:)")));
- (void)writeSource:(LSDKKotlinByteArray *)source startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("write(source:startIndex:endIndex:)")));
- (void)writeByteByte:(int8_t)byte __attribute__((swift_name("writeByte(byte:)")));
- (void)writeIntInt:(int32_t)int_ __attribute__((swift_name("writeInt(int:)")));
- (void)writeLongLong:(int64_t)long_ __attribute__((swift_name("writeLong(long:)")));
- (void)writeShortShort:(int16_t)short_ __attribute__((swift_name("writeShort(short:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol LSDKKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<LSDKKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("Ktor_ioCloseable")))
@protocol LSDKKtor_ioCloseable <LSDKKotlinAutoCloseable>
@required
@end


/**
 * A multiplatform asynchronous HTTP client that allows you to make requests, handle responses,
 * and extend its functionality with plugins such as authentication, JSON serialization, and more.
 *
 * # Creating client
 * To create a new client, you can call:
 * ```kotlin
 * val client = HttpClient()
 * ```
 * You can create as many clients as you need.
 *
 * If you no longer need the client, please consider closing it to release resources:
 * ```
 * client.close()
 * ```
 *
 * To learn more on how to create and configure an [HttpClient] see the tutorial page:
 * [Creating and configuring a client](https://ktor.io/docs/create-client.html).
 *
 * # Making API Requests
 * For every HTTP method (GET, POST, PUT, etc.), there is a corresponding function:
 * ```kotlin
 * val response: HttpResponse = client.get("https://ktor.io/")
 * val body = response.bodyAsText()
 * ```
 * See [Making HTTP requests](https://ktor.io/docs/client-requests.html) for more details.
 *
 * # Query Parameters
 * Add query parameters to your request using the `parameter` function:
 * ```kotlin
 * val response = client.get("https://google.com/search") {
 *     url {
 *         parameter("q", "REST API with Ktor")
 *     }
 * }
 * ```
 * For more information, refer to [Passing request parameters](https://ktor.io/docs/client-requests.html#parameters).
 *
 * # Adding Headers
 * Include headers in your request using the `headers` builder or the `header` function:
 * ```kotlin
 * val response = client.get("https://httpbin.org/bearer") {
 *     headers {
 *         append("Authorization", "Bearer your_token_here")
 *         append("Accept", "application/json")
 *     }
 * }
 * ```
 * Learn more at [Adding headers to a request](https://ktor.io/docs/client-requests.html#headers).
 *
 * # JSON Serialization
 * Add dependencies:
 * - io.ktor:ktor-client-content-negotiation:3.+
 * - io.ktor:ktor-serialization-kotlinx-json:3.+
 * Add Gradle plugin:
 * ```
 * plugins {
 *     kotlin("plugin.serialization")
 * }
 * ```
 *
 * Send and receive JSON data by installing the `ContentNegotiation` plugin with `kotlinx.serialization`:
 * ```kotlin
 * val client = HttpClient {
 *     install(ContentNegotiation) {
 *         json()
 *     }
 * }
 *
 * @Serializable
 * data class MyRequestType(val someData: String)
 *
 * @Serializable
 * data class MyResponseType(val someResponseData: String)
 *
 * val response: MyResponseType = client.post("https://api.example.com/data") {
 *     contentType(ContentType.Application.Json)
 *     setBody(MyRequestType(someData = "value"))
 * }.body()
 * ```
 * See [Serializing JSON data](https://ktor.io/docs/client-serialization.html) for maven configuration and other details.
 *
 * # Submitting Forms
 * Submit form data using `FormDataContent` or the `submitForm` function:
 * ```kotlin
 * // Using FormDataContent
 * val response = client.post("https://example.com/submit") {
 *     setBody(FormDataContent(Parameters.build {
 *         append("username", "user")
 *         append("password", "pass")
 *     }))
 * }
 *
 * // Or using submitForm
 * val response = client.submitForm(
 *     url = "https://example.com/submit",
 *     formParameters = Parameters.build {
 *         append("username", "user")
 *         append("password", "pass")
 *     }
 * )
 * ```
 * More information is available at [Submitting form parameters](https://ktor.io/docs/client-requests.html#form_parameters).
 *
 * # Handling Authentication
 * Add dependency: io.ktor:ktor-client-auth:3.+
 *
 * Use the `Auth` plugin to handle various authentication schemes like Basic or Bearer token authentication:
 * ```kotlin
 * val client = HttpClient {
 *     install(Auth) {
 *         bearer {
 *             loadTokens {
 *                 BearerTokens(accessToken = "your_access_token", refreshToken = "your_refresh_token")
 *             }
 *         }
 *     }
 * }
 *
 * val response = client.get("https://api.example.com/protected")
 * ```
 * Refer to [Client authentication](https://ktor.io/docs/client-auth.html) for more details.
 *
 * # Setting Timeouts and Retries
 * Configure timeouts and implement retry logic for your requests:
 * ```kotlin
 * val client = HttpClient {
 *     install(HttpTimeout) {
 *         requestTimeoutMillis = 10000
 *         connectTimeoutMillis = 5000
 *         socketTimeoutMillis = 15000
 *     }
 * }
 * ```
 *
 * For the request timeout:
 * ```kotlin
 * client.get("") {
 *     timeout {
 *         requestTimeoutMillis = 1000
 *     }
 * }
 * ```
 * See [Timeout](https://ktor.io/docs/client-timeout.html) for more information.
 *
 * # Handling Cookies
 *
 * Manage cookies automatically by installing the `HttpCookies` plugin:
 * ```kotlin
 * val client = HttpClient {
 *     install(HttpCookies) {
 *         storage = AcceptAllCookiesStorage()
 *     }
 * }
 *
 * // Accessing cookies
 * val cookies: List<Cookie> = client.cookies("https://example.com")
 * ```
 * Learn more at [Cookies](https://ktor.io/docs/client-cookies.html).
 *
 * # Uploading Files
 * Upload files using multipart/form-data requests:
 * ```kotlin
 * client.submitFormWithBinaryData(
 *      url = "https://example.com/upload",
 *      formData = formData {
 *          append("description", "File upload example")
 *          append("file", {
 *              File("path/to/file.txt").readChannel()
 *          })
 *      }
 *  )
 *
 * See [Uploading data](https://ktor.io/docs/client-requests.html#upload_file) for details.
 *
 * # Using WebSockets
 *
 * Communicate over WebSockets using the `webSocket` function:
 * ```kotlin
 * client.webSocket("wss://echo.websocket.org") {
 *     send(Frame.Text("Hello, WebSocket!"))
 *     val frame = incoming.receive()
 *     if (frame is Frame.Text) {
 *         println("Received: ${frame.readText()}")
 *     }
 * }
 * ```
 * Learn more at [Client WebSockets](https://ktor.io/docs/client-websockets.html).
 *
 * # Error Handling
 * Handle exceptions and HTTP error responses gracefully:
 * val client = HttpClient {
 *     HttpResponseValidator {
 *         validateResponse { response ->
 *             val statusCode = response.status.value
 *             when (statusCode) {
 *                 in 300..399 -> error("Redirects are not allowed")
 *             }
 *         }
 *     }
 * }
 * See [Error handling](https://ktor.io/docs/client-response-validation.html) for more information.
 *
 * # Configuring SSL/TLS
 *
 * Customize SSL/TLS settings for secure connections is engine-specific. Please refer to the following page for
 * the details: [Client SSL/TLS](https://ktor.io/docs/client-ssl.html).
 *
 * # Using Proxies
 * Route requests through an HTTP or SOCKS proxy:
 * ```kotlin
 * val client = HttpClient() {
 *     engine {
 *         proxy = ProxyBuilder.http("http://proxy.example.com:8080")
 *         // For a SOCKS proxy:
 *         // proxy = ProxyBuilder.socks(host = "proxy.example.com", port = 1080)
 *     }
 * }
 * ```
 * See [Using a proxy](https://ktor.io/docs/client-proxy.html) for details.
 *
 * # Streaming Data
 *
 * Stream large data efficiently without loading it entirely into memory.
 *
 * Stream request:
 * ```kotlin
 * val response = client.post("https://example.com/upload") {
 *      setBody(object: OutgoingContent.WriteChannelContent() {
 *          override suspend fun writeTo(channel: ByteWriteChannel) {
 *              repeat(1000) {
 *                  channel.writeString("Hello!")
 *              }
 *          }
 *      })
 * }
 * ```
 *
 * Stream response:
 * ```kotlin
 * client.prepareGet("https://example.com/largefile.zip").execute { response ->
 *     val channel: ByteReadChannel = response.bodyAsChannel()
 *
 *     while (!channel.exhausted()) {
 *         val chunk = channel.readBuffer()
 *         // ...
 *     }
 * }
 * ```
 * Learn more at [Streaming data](https://ktor.io/docs/client-responses.html#streaming).
 *
 * # Using SSE
 * Server-Sent Events (SSE) is a technology that allows a server to continuously push events to a client over an HTTP
 * connection. It's particularly useful in cases where the server needs to send event-based updates without requiring
 * the client to repeatedly poll the server.
 *
 * Install the plugin:
 * ```kotlin
 * val client = HttpClient(CIO) {
 *     install(SSE)
 * }
 * ```
 *
 * ```
 * client.sse(host = "0.0.0.0", port = 8080, path = "/events") {
 *     while (true) {
 *         for (event in incoming) {
 *             println("Event from server:")
 *             println(event)
 *         }
 *     }
 * }
 * ```
 *
 * Visit [Using SSE](https://ktor.io/docs/client-server-sent-events.html#install_plugin) to learn more.
 *
 * # Customizing a client with plugins
 * To extend out-of-the-box functionality, you can install plugins for a Ktor client:
 * ```kotlin
 * val client = HttpClient {
 *     install(ContentNegotiation) {
 *         json()
 *     }
 * }
 * ```
 *
 * There are many plugins available out of the box, and you can write your own. See
 * [Create custom client plugins](https://ktor.io/docs/client-custom-plugins.html) to learn more.
 *
 * # Service Loader and Default Engine
 * On JVM, calling `HttpClient()` without specifying an engine uses a service loader mechanism to
 * determine the appropriate default engine. This can introduce a performance overhead, especially on
 * slower devices, such as Android.
 *
 * **Performance Note**: If you are targeting platforms where initialization speed is critical,
 * consider explicitly specifying an engine to avoid the service loader lookup.
 *
 * Example with manual engine specification:
 * ```
 * val client = HttpClient(Apache) // Explicitly uses Apache engine, bypassing service loader
 * ```
 *
 * By directly setting the engine (e.g., `Apache`, `OkHttp`), you can optimize startup performance
 * by preventing the default service loader mechanism.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClient")))
@interface LSDKKtor_client_coreHttpClient : LSDKBase <LSDKKotlinx_coroutines_coreCoroutineScope, LSDKKtor_ioCloseable>
@property (readonly) id<LSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) id<LSDKKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<LSDKKtor_client_coreHttpClientEngine> engine __attribute__((swift_name("engine")));
@property (readonly) LSDKKtor_client_coreHttpClientEngineConfig *engineConfig __attribute__((swift_name("engineConfig")));
@property (readonly) LSDKKtor_eventsEvents *monitor __attribute__((swift_name("monitor")));
@property (readonly) LSDKKtor_client_coreHttpReceivePipeline *receivePipeline __attribute__((swift_name("receivePipeline")));
@property (readonly) LSDKKtor_client_coreHttpRequestPipeline *requestPipeline __attribute__((swift_name("requestPipeline")));
@property (readonly) LSDKKtor_client_coreHttpResponsePipeline *responsePipeline __attribute__((swift_name("responsePipeline")));
@property (readonly) LSDKKtor_client_coreHttpSendPipeline *sendPipeline __attribute__((swift_name("sendPipeline")));
- (instancetype)initWithEngine:(id<LSDKKtor_client_coreHttpClientEngine>)engine userConfig:(LSDKKtor_client_coreHttpClientConfig<LSDKKtor_client_coreHttpClientEngineConfig *> *)userConfig __attribute__((swift_name("init(engine:userConfig:)"))) __attribute__((objc_designated_initializer));

/**
 * Initiates the shutdown process for the `HttpClient`. This is a non-blocking call, which
 * means it returns immediately and begins the client closure in the background.
 *
 * ## Usage
 * ```
 * val client = HttpClient()
 * client.close()
 * client.coroutineContext.job.join() // Waits for complete termination if necessary
 * ```
 *
 * ## Important Notes
 * - **Non-blocking**: `close()` only starts the closing process and does not wait for it to complete.
 * - **Coroutine Context**: To wait for all client resources to be freed, use `client.coroutineContext.job.join()`
 *   or `client.coroutineContext.cancel()` to terminate ongoing tasks.
 * - **Manual Engine Management**: If a custom `engine` was manually created, it must be closed explicitly
 *   after calling `client.close()` to release all resources.
 *
 * Example with custom engine management:
 * ```
 * val engine = HttpClientEngine() // Custom engine instance
 * val client = HttpClient(engine)
 *
 * client.close()
 * engine.close() // Ensure manually created engine is also closed
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.close)
 */
- (void)close __attribute__((swift_name("close()")));

/**
 * Returns a new [HttpClient] by copying this client's configuration
 * and additionally configured by the [block] parameter.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.config)
 */
- (LSDKKtor_client_coreHttpClient *)configBlock:(void (^)(LSDKKtor_client_coreHttpClientConfig<id> *))block __attribute__((swift_name("config(block:)")));

/**
 * Checks if the specified [capability] is supported by this client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.isSupported)
 */
- (BOOL)isSupportedCapability:(id<LSDKKtor_client_coreHttpClientEngineCapability>)capability __attribute__((swift_name("isSupported(capability:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Typed attributes used as a lightweight container for this client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.attributes)
 */

/**
 * Provides access to the client's engine configuration.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.engineConfig)
 */

/**
 * Provides access to the events of the client's lifecycle.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.monitor)
 */

/**
 * A pipeline used for receiving a request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.receivePipeline)
 */

/**
 * A pipeline used for processing all requests sent by this client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.requestPipeline)
 */

/**
 * A pipeline used for processing all responses sent by the server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.responsePipeline)
 */

/**
 * A pipeline used for sending a request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.sendPipeline)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_corePath")))
@interface LSDKKotlinx_io_corePath : LSDKBase
@property (readonly) BOOL isAbsolute __attribute__((swift_name("isAbsolute")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) LSDKKotlinx_io_corePath * _Nullable parent __attribute__((swift_name("parent")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol LSDKKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialFormat")))
@protocol LSDKKotlinx_serialization_coreSerialFormat
@required
@property (readonly) LSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreStringFormat")))
@protocol LSDKKotlinx_serialization_coreStringFormat <LSDKKotlinx_serialization_coreSerialFormat>
@required
- (id _Nullable)decodeFromStringDeserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (NSString *)encodeToStringSerializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_jsonJson")))
@interface LSDKKotlinx_serialization_jsonJson : LSDKBase <LSDKKotlinx_serialization_coreStringFormat>
@property (class, readonly, getter=companion) LSDKKotlinx_serialization_jsonJsonDefault *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKKotlinx_serialization_jsonJsonConfiguration *configuration __attribute__((swift_name("configuration")));
@property (readonly) LSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
- (id _Nullable)decodeFromJsonElementDeserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer element:(LSDKKotlinx_serialization_jsonJsonElement *)element __attribute__((swift_name("decodeFromJsonElement(deserializer:element:)")));
- (id _Nullable)decodeFromStringString:(NSString *)string __attribute__((swift_name("decodeFromString(string:)")));
- (id _Nullable)decodeFromStringDeserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (LSDKKotlinx_serialization_jsonJsonElement *)encodeToJsonElementSerializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToJsonElement(serializer:value:)")));
- (NSString *)encodeToStringValue:(id _Nullable)value __attribute__((swift_name("encodeToString(value:)")));
- (NSString *)encodeToStringSerializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
- (LSDKKotlinx_serialization_jsonJsonElement *)parseToJsonElementString:(NSString *)string __attribute__((swift_name("parseToJsonElement(string:)")));
@end

__attribute__((swift_name("Kotlinx_io_coreFileSystem")))
@protocol LSDKKotlinx_io_coreFileSystem
@required
- (void)atomicMoveSource:(LSDKKotlinx_io_corePath *)source destination:(LSDKKotlinx_io_corePath *)destination __attribute__((swift_name("atomicMove(source:destination:)")));
- (void)createDirectoriesPath:(LSDKKotlinx_io_corePath *)path mustCreate:(BOOL)mustCreate __attribute__((swift_name("createDirectories(path:mustCreate:)")));
- (void)deletePath:(LSDKKotlinx_io_corePath *)path mustExist:(BOOL)mustExist __attribute__((swift_name("delete(path:mustExist:)")));
- (BOOL)existsPath:(LSDKKotlinx_io_corePath *)path __attribute__((swift_name("exists(path:)")));
- (id)listDirectory:(LSDKKotlinx_io_corePath *)directory __attribute__((swift_name("list(directory:)")));
- (LSDKKotlinx_io_coreFileMetadata * _Nullable)metadataOrNullPath:(LSDKKotlinx_io_corePath *)path __attribute__((swift_name("metadataOrNull(path:)")));
- (LSDKKotlinx_io_corePath *)resolvePath:(LSDKKotlinx_io_corePath *)path __attribute__((swift_name("resolve(path:)")));
- (id<LSDKKotlinx_io_coreRawSink>)sinkPath:(LSDKKotlinx_io_corePath *)path append:(BOOL)append __attribute__((swift_name("sink(path:append:)")));
- (id<LSDKKotlinx_io_coreRawSource>)sourcePath:(LSDKKotlinx_io_corePath *)path __attribute__((swift_name("source(path:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol LSDKKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<LSDKKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<LSDKKotlinCoroutineContextElement> _Nullable)getKey:(id<LSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<LSDKKotlinCoroutineContext>)minusKeyKey:(id<LSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<LSDKKotlinCoroutineContext>)plusContext:(id<LSDKKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol LSDKKotlinCoroutineContextElement <LSDKKotlinCoroutineContext>
@required
@property (readonly) id<LSDKKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/InternalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreJob")))
@protocol LSDKKotlinx_coroutines_coreJob <LSDKKotlinCoroutineContextElement>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<LSDKKotlinx_coroutines_coreChildHandle>)attachChildChild:(id<LSDKKotlinx_coroutines_coreChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(LSDKKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (LSDKKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<LSDKKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionHandler:(void (^)(LSDKKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<LSDKKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(LSDKKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<LSDKKotlinx_coroutines_coreJob>)plusOther:(id<LSDKKotlinx_coroutines_coreJob>)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<LSDKKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<LSDKKotlinx_coroutines_coreSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<LSDKKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * Represents an execution pipeline for asynchronous extensible computations
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline)
 */
__attribute__((swift_name("Ktor_utilsPipeline")))
@interface LSDKKtor_utilsPipeline<TSubject, TContext> : LSDKBase
@property (readonly) id<LSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) NSArray<LSDKKtor_utilsPipelinePhase *> *items __attribute__((swift_name("items")));
- (instancetype)initWithPhases:(LSDKKotlinArray<LSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhase:(LSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer));

/**
 * Adds [phase] to the end of this pipeline
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.addPhase)
 */
- (void)addPhasePhase:(LSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("addPhase(phase:)")));

/**
 * Invoked after an interceptor has been installed
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.afterIntercepted)
 */
- (void)afterIntercepted __attribute__((swift_name("afterIntercepted()")));

/**
 * Executes this pipeline in the given [context] and with the given [subject]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.execute)
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeContext:(TContext)context subject:(TSubject)subject completionHandler:(void (^)(TSubject _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(context:subject:completionHandler:)")));

/**
 * Inserts [phase] after the [reference] phase. If there are other phases inserted after [reference], then [phase]
 * will be inserted after them.
 * Example:
 * ```
 * val pipeline = Pipeline<String, String>(a)
 * pipeline.insertPhaseAfter(a, b)
 * pipeline.insertPhaseAfter(a, c)
 * assertEquals(listOf(a, b, c), pipeline.items)
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.insertPhaseAfter)
 */
- (void)insertPhaseAfterReference:(LSDKKtor_utilsPipelinePhase *)reference phase:(LSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseAfter(reference:phase:)")));

/**
 * Inserts [phase] before the [reference] phase.
 * Example:
 * ```
 * val pipeline = Pipeline<String, String>(c)
 * pipeline.insertPhaseBefore(c, a)
 * pipeline.insertPhaseBefore(c, b)
 * assertEquals(listOf(a, b, c), pipeline.items)
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.insertPhaseBefore)
 */
- (void)insertPhaseBeforeReference:(LSDKKtor_utilsPipelinePhase *)reference phase:(LSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseBefore(reference:phase:)")));

/**
 * Adds [block] to the [phase] of this pipeline
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.intercept)
 */
- (void)interceptPhase:(LSDKKtor_utilsPipelinePhase *)phase block:(id<LSDKKotlinSuspendFunction2>)block __attribute__((swift_name("intercept(phase:block:)")));
- (NSArray<id<LSDKKotlinSuspendFunction2>> *)interceptorsForPhasePhase:(LSDKKtor_utilsPipelinePhase *)phase __attribute__((swift_name("interceptorsForPhase(phase:)")));

/**
 * Merges another pipeline into this pipeline, maintaining relative phases order
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.merge)
 */
- (void)mergeFrom:(LSDKKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("merge(from:)")));
- (void)mergePhasesFrom:(LSDKKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("mergePhases(from:)")));

/**
 * Reset current pipeline from other.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.resetFrom)
 */
- (void)resetFromFrom:(LSDKKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("resetFrom(from:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Provides common place to store pipeline attributes
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.attributes)
 */

/**
 * Indicated if debug mode is enabled. In debug mode users will get more details in the stacktrace.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.developmentMode)
 */

/**
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.isEmpty)
 *
 * @return `true` if there are no interceptors installed regardless number of phases
 */

/**
 * Phases of this pipeline
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.items)
 */
@end

__attribute__((swift_name("KotlinFunction")))
@protocol LSDKKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction2")))
@protocol LSDKKotlinSuspendFunction2 <LSDKKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:completionHandler:)")));
@end


/**
 * A pair of a [request] and [response] for a specific [HttpClient].
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall)
 *
 * @property client the client that executed the call.
 */
__attribute__((swift_name("Ktor_client_coreHttpClientCall")))
@interface LSDKKtor_client_coreHttpClientCall : LSDKBase <LSDKKotlinx_coroutines_coreCoroutineScope>
@property (class, readonly, getter=companion) LSDKKtor_client_coreHttpClientCallCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL allowDoubleReceive __attribute__((swift_name("allowDoubleReceive")));
@property (readonly) id<LSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) LSDKKtor_client_coreHttpClient *client __attribute__((swift_name("client")));
@property (readonly) id<LSDKKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property id<LSDKKtor_client_coreHttpRequest> request __attribute__((swift_name("request")));
@property LSDKKtor_client_coreHttpResponse *response __attribute__((swift_name("response")));
- (instancetype)initWithClient:(LSDKKtor_client_coreHttpClient *)client __attribute__((swift_name("init(client:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithClient:(LSDKKtor_client_coreHttpClient *)client requestData:(LSDKKtor_client_coreHttpRequestData *)requestData responseData:(LSDKKtor_client_coreHttpResponseData *)responseData __attribute__((swift_name("init(client:requestData:responseData:)"))) __attribute__((objc_designated_initializer));

/**
 * Tries to receive the payload of the [response] as a specific expected type provided in [info].
 * Returns [response] if [info] corresponds to [HttpResponse].
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.body)
 *
 * @throws NoTransformationFoundException If no transformation is found for the type [info].
 * @throws DoubleReceiveException If already called [body].
 * @throws NullPointerException If content is `null`.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyInfo:(LSDKKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("body(info:completionHandler:)")));

/**
 * Tries to receive the payload of the [response] as a specific expected type provided in [info].
 * Returns [response] if [info] corresponds to [HttpResponse].
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.bodyNullable)
 *
 * @throws NoTransformationFoundException If no transformation is found for the type [info].
 * @throws DoubleReceiveException If already called [body].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyNullableInfo:(LSDKKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyNullable(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)getResponseContentWithCompletionHandler:(void (^)(id<LSDKKtor_ioByteReadChannel> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getResponseContent(completionHandler:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/

/**
 * Typed [Attributes] associated to this call serving as a lightweight container.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.attributes)
 */

/**
 * The [request] sent by the client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.request)
 */

/**
 * The [response] sent by the server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.response)
 */
@end


/**
 * Ktor type information.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.reflect.TypeInfo)
 *
 * @property type Source KClass<*>
 * @property kotlinType Kotlin reified type with all generic type parameters.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsTypeInfo")))
@interface LSDKKtor_utilsTypeInfo : LSDKBase
@property (readonly) id<LSDKKotlinKType> _Nullable kotlinType __attribute__((swift_name("kotlinType")));
@property (readonly) id<LSDKKotlinKClass> type __attribute__((swift_name("type")));
- (instancetype)initWithType:(id<LSDKKotlinKClass>)type kotlinType:(id<LSDKKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:kotlinType:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithType:(id<LSDKKotlinKClass>)type reifiedType:(id<LSDKKotlinKType>)reifiedType kotlinType:(id<LSDKKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:reifiedType:kotlinType:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("Use constructor without reifiedType parameter.")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Channel for asynchronous reading of sequences of bytes.
 * This is a **single-reader channel**.
 *
 * Operations on this channel cannot be invoked concurrently.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.utils.io.ByteReadChannel)
 */
__attribute__((swift_name("Ktor_ioByteReadChannel")))
@protocol LSDKKtor_ioByteReadChannel
@required

/**
 * Suspend the channel until it has [min] bytes or gets closed. Throws exception if the channel was closed with an
 * error. If there are bytes available in the channel, this function returns immediately.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.utils.io.ByteReadChannel.awaitContent)
 *
 * @return return `false` eof is reached, otherwise `true`.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)awaitContentMin:(int32_t)min completionHandler:(void (^)(LSDKBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitContent(min:completionHandler:)")));
- (void)cancelCause_:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));
@property (readonly) LSDKKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForRead __attribute__((swift_name("isClosedForRead")));
@property (readonly) id<LSDKKotlinx_io_coreSource> readBuffer __attribute__((swift_name("readBuffer")));
@end


/**
 * Serves as the base interface for an [HttpClient]'s engine.
 *
 * An `HttpClientEngine` represents the underlying network implementation that
 * performs HTTP requests and handles responses.
 * Developers can implement this interface to create custom engines for use with [HttpClient].
 *
 * This interface provides a set of properties and methods that define the
 * contract for configuring, executing, and managing HTTP requests within the engine.
 *
 * For a base implementation that handles common engine functionality, see [HttpClientEngineBase].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngine)
 */
__attribute__((swift_name("Ktor_client_coreHttpClientEngine")))
@protocol LSDKKtor_client_coreHttpClientEngine <LSDKKotlinx_coroutines_coreCoroutineScope, LSDKKtor_ioCloseable>
@required

/**
 * Executes an HTTP request and produces an HTTP response.
 *
 * This function takes [HttpRequestData], which contains all details of the HTTP request,
 * and returns [HttpResponseData] with the server's response, including headers, status code, and body.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngine.execute)
 *
 * @param data The [HttpRequestData] representing the request to be executed.
 * @return An [HttpResponseData] object containing the server's response.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeData:(LSDKKtor_client_coreHttpRequestData *)data completionHandler:(void (^)(LSDKKtor_client_coreHttpResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(data:completionHandler:)")));

/**
 * Installs the engine into an [HttpClient].
 *
 * This method is called when the engine is being set up within an `HttpClient`.
 * Use it to register interceptors, validate configuration, or prepare the engine
 * for use with the client.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngine.install)
 *
 * @param client The [HttpClient] instance to which the engine is being installed.
 */
- (void)installClient:(LSDKKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));

/**
 * Provides access to the engine's configuration via [HttpClientEngineConfig].
 *
 * The [config] object stores user-defined parameters or settings that control
 * how the engine operates. When creating a custom engine, this property
 * should return the specific configuration implementation.
 *
 * Example:
 * ```kotlin
 * override val config: HttpClientEngineConfig = CustomEngineConfig()
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngine.config)
 */
@property (readonly) LSDKKtor_client_coreHttpClientEngineConfig *config __attribute__((swift_name("config")));

/**
 * Specifies the [CoroutineDispatcher] for I/O operations in the engine.
 *
 * This dispatcher is used for all network-related operations, such as
 * sending requests and receiving responses.
 * By default, it should be optimized for I/O tasks.
 *
 * Example:
 * ```kotlin
 * override val dispatcher: CoroutineDispatcher = Dispatchers.IO
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngine.dispatcher)
 */
@property (readonly) LSDKKotlinx_coroutines_coreCoroutineDispatcher *dispatcher __attribute__((swift_name("dispatcher")));

/**
 * Specifies the set of capabilities supported by this HTTP client engine.
 *
 * Capabilities provide a mechanism for plugins and other components to
 * determine whether the engine supports specific features such as timeouts,
 * WebSocket communication, HTTP/2, HTTP/3, or other advanced networking
 * capabilities. This allows seamless integration of features based on the
 * engine's functionality.
 *
 * Each capability is represented as an instance of [HttpClientEngineCapability],
 * which can carry additional metadata or configurations for the capability.
 *
 * Example:
 * ```kotlin
 * override val supportedCapabilities: Set<HttpClientEngineCapability<*>> = setOf(
 *     WebSocketCapability,
 *     Http2Capability,
 *     TimeoutCapability
 * )
 * ```
 *
 * **Usage in Plugins**:
 * Plugins can check if the engine supports a specific capability before
 * applying behavior:
 * ```kotlin
 * if (engine.supportedCapabilities.contains(WebSocketCapability)) {
 *     // Configure WebSocket-specific settings
 * }
 * ```
 *
 * When implementing a custom engine, ensure this property accurately reflects
 * the engine's abilities to avoid unexpected plugin behavior or runtime errors.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngine.supportedCapabilities)
 */
@property (readonly) NSSet<id<LSDKKtor_client_coreHttpClientEngineCapability>> *supportedCapabilities __attribute__((swift_name("supportedCapabilities")));
@end


/**
 * Actual data of the [HttpRequest], including [url], [method], [headers], [body] and [executionContext].
 * Built by [HttpRequestBuilder].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestData)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestData")))
@interface LSDKKtor_client_coreHttpRequestData : LSDKBase
@property (readonly) id<LSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) LSDKKtor_httpOutgoingContent *body __attribute__((swift_name("body")));
@property (readonly) id<LSDKKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) id<LSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) LSDKKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) LSDKKtor_httpUrl *url __attribute__((swift_name("url")));
- (instancetype)initWithUrl:(LSDKKtor_httpUrl *)url method:(LSDKKtor_httpHttpMethod *)method headers:(id<LSDKKtor_httpHeaders>)headers body:(LSDKKtor_httpOutgoingContent *)body executionContext:(id<LSDKKotlinx_coroutines_coreJob>)executionContext attributes:(id<LSDKKtor_utilsAttributes>)attributes __attribute__((swift_name("init(url:method:headers:body:executionContext:attributes:)"))) __attribute__((objc_designated_initializer));

/**
 * Retrieve extension by its key.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestData.getCapabilityOrNull)
 */
- (id _Nullable)getCapabilityOrNullKey:(id<LSDKKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Information about the content to be sent to the peer, recognized by a client or server engine
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent")))
@interface LSDKKtor_httpOutgoingContent : LSDKBase
@property (readonly) LSDKLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) LSDKKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly) id<LSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) LSDKKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));

/**
 * Gets an extension property for this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.getProperty)
 */
- (id _Nullable)getPropertyKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));

/**
 * Sets an extension property for this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.setProperty)
 */
- (void)setPropertyKey:(LSDKKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));

/**
 * Trailers to set when sending this content, will be ignored if request is not in HTTP2 mode
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.trailers)
 */
- (id<LSDKKtor_httpHeaders> _Nullable)trailers __attribute__((swift_name("trailers()")));

/**
 * Specifies content length in bytes for this resource.
 *
 * If null, the resources will be sent as `Transfer-Encoding: chunked`
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.contentLength)
 */

/**
 * Specifies [ContentType] for this resource.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.contentType)
 */

/**
 * Headers to set when sending this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.headers)
 */

/**
 * Status code to set when sending this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.status)
 */
@end


/**
 * Variant of a [OutgoingContent] for upgrading an HTTP connection
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ProtocolUpgrade)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent.ProtocolUpgrade")))
@interface LSDKKtor_httpOutgoingContentProtocolUpgrade : LSDKKtor_httpOutgoingContent
@property (readonly) LSDKKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));

/**
 * Variant of a [OutgoingContent] for upgrading an HTTP connection
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ProtocolUpgrade)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Variant of a [OutgoingContent] for upgrading an HTTP connection
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ProtocolUpgrade)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Upgrades an HTTP connection
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ProtocolUpgrade.upgrade)
 *
 * @param input is a [ByteReadChannel] for an upgraded connection
 * @param output is a [ByteWriteChannel] for an upgraded connection
 * @param engineContext is a [CoroutineContext] to execute non-blocking code, such as parsing or processing
 * @param userContext is a [CoroutineContext] to execute user-provided callbacks or code potentially blocking
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)upgradeInput:(id<LSDKKtor_ioByteReadChannel>)input output:(id<LSDKKtor_ioByteWriteChannel>)output engineContext:(id<LSDKKotlinCoroutineContext>)engineContext userContext:(id<LSDKKotlinCoroutineContext>)userContext completionHandler:(void (^)(id<LSDKKotlinx_coroutines_coreJob> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("upgrade(input:output:engineContext:userContext:completionHandler:)")));
@end


/**
 * Channel for asynchronous writing of sequences of bytes.
 * This is a **single-writer channel**.
 *
 * Operations on this channel cannot be invoked concurrently, unless explicitly specified otherwise
 * in the description. Exceptions are [close] and [flush].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.utils.io.ByteWriteChannel)
 */
__attribute__((swift_name("Ktor_ioByteWriteChannel")))
@protocol LSDKKtor_ioByteWriteChannel
@required
- (void)cancelCause_:(LSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)flushWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("flush(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)flushAndCloseWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("flushAndClose(completionHandler:)")));
@property (readonly) BOOL autoFlush __attribute__((swift_name("autoFlush")));
@property (readonly) LSDKKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForWrite __attribute__((swift_name("isClosedForWrite")));
@property (readonly) id<LSDKKotlinx_io_coreSink> writeBuffer __attribute__((swift_name("writeBuffer")));
@end


/**
 * Variant of a [OutgoingContent] with payload written to [ByteWriteChannel]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.WriteChannelContent)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent.WriteChannelContent")))
@interface LSDKKtor_httpOutgoingContentWriteChannelContent : LSDKKtor_httpOutgoingContent

/**
 * Variant of a [OutgoingContent] with payload written to [ByteWriteChannel]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.WriteChannelContent)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Variant of a [OutgoingContent] with payload written to [ByteWriteChannel]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.WriteChannelContent)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Receives [channel] provided by the engine and writes all data to it
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.WriteChannelContent.writeTo)
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)writeToChannel:(id<LSDKKtor_ioByteWriteChannel>)channel completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("writeTo(channel:completionHandler:)")));
@end


/**
 * Variant of a [OutgoingContent] with payload represented as [ByteArray]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ByteArrayContent)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent.ByteArrayContent")))
@interface LSDKKtor_httpOutgoingContentByteArrayContent : LSDKKtor_httpOutgoingContent

/**
 * Variant of a [OutgoingContent] with payload represented as [ByteArray]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ByteArrayContent)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Variant of a [OutgoingContent] with payload represented as [ByteArray]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ByteArrayContent)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Provides [ByteArray] which engine will send to peer
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ByteArrayContent.bytes)
 */
- (LSDKKotlinByteArray *)bytes __attribute__((swift_name("bytes()")));
@end


/**
 * Variant of an [OutgoingContent] which delegates to provided [OutgoingContent]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ContentWrapper)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent.ContentWrapper")))
@interface LSDKKtor_httpOutgoingContentContentWrapper : LSDKKtor_httpOutgoingContent
@property (readonly) LSDKLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) LSDKKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly) id<LSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) LSDKKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));
- (instancetype)initWithDelegate:(LSDKKtor_httpOutgoingContent *)delegate __attribute__((swift_name("init(delegate:)"))) __attribute__((objc_designated_initializer));

/**
 * Returns a copy of this implementation of [ContentWrapper] with provided [OutgoingContent]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ContentWrapper.copy)
 */
- (LSDKKtor_httpOutgoingContentContentWrapper *)doCopyDelegate:(LSDKKtor_httpOutgoingContent *)delegate __attribute__((swift_name("doCopy(delegate:)")));
- (LSDKKtor_httpOutgoingContent *)delegate __attribute__((swift_name("delegate()")));
- (id _Nullable)getPropertyKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));
- (void)setPropertyKey:(LSDKKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));
@end


/**
 * Variant of a [OutgoingContent] without a payload
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.NoContent)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent.NoContent")))
@interface LSDKKtor_httpOutgoingContentNoContent : LSDKKtor_httpOutgoingContent

/**
 * Variant of a [OutgoingContent] without a payload
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.NoContent)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Variant of a [OutgoingContent] without a payload
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.NoContent)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end


/**
 * Variant of a [OutgoingContent] with payload read from [ByteReadChannel]
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ReadChannelContent)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent.ReadChannelContent")))
@interface LSDKKtor_httpOutgoingContentReadChannelContent : LSDKKtor_httpOutgoingContent

/**
 * Variant of a [OutgoingContent] with payload read from [ByteReadChannel]
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ReadChannelContent)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Variant of a [OutgoingContent] with payload read from [ByteReadChannel]
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ReadChannelContent)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Provides [ByteReadChannel] for the content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ReadChannelContent.readFrom)
 */
- (id<LSDKKtor_ioByteReadChannel>)readFrom __attribute__((swift_name("readFrom()")));

/**
 * Provides [ByteReadChannel] for the given range of the content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.ReadChannelContent.readFrom)
 */
- (id<LSDKKtor_ioByteReadChannel>)readFromRange:(LSDKKotlinLongRange *)range __attribute__((swift_name("readFrom(range:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause")))
@protocol LSDKKotlinx_coroutines_coreSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) LSDKKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<LSDKKotlinx_coroutines_coreSelectInstance>, id _Nullable, id _Nullable))(LSDKKotlinThrowable *, id _Nullable, id<LSDKKotlinCoroutineContext>) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<LSDKKotlinx_coroutines_coreSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause1")))
@protocol LSDKKotlinx_coroutines_coreSelectClause1 <LSDKKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface LSDKKotlinx_serialization_coreSerialKind : LSDKBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_corePolymorphicKind")))
@interface LSDKKotlinx_serialization_corePolymorphicKind : LSDKKotlinx_serialization_coreSerialKind
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePolymorphicKind.OPEN")))
@interface LSDKKotlinx_serialization_corePolymorphicKindOPEN : LSDKKotlinx_serialization_corePolymorphicKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePolymorphicKindOPEN *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oPEN __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePolymorphicKind.SEALED")))
@interface LSDKKotlinx_serialization_corePolymorphicKindSEALED : LSDKKotlinx_serialization_corePolymorphicKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePolymorphicKindSEALED *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sEALED __attribute__((swift_name("init()")));
@end

__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind")))
@interface LSDKKotlinx_serialization_corePrimitiveKind : LSDKKotlinx_serialization_coreSerialKind
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.BOOLEAN")))
@interface LSDKKotlinx_serialization_corePrimitiveKindBOOLEAN : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindBOOLEAN *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)bOOLEAN __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.BYTE")))
@interface LSDKKotlinx_serialization_corePrimitiveKindBYTE : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindBYTE *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)bYTE __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.CHAR")))
@interface LSDKKotlinx_serialization_corePrimitiveKindCHAR : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindCHAR *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cHAR __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.DOUBLE")))
@interface LSDKKotlinx_serialization_corePrimitiveKindDOUBLE : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindDOUBLE *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dOUBLE __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.FLOAT")))
@interface LSDKKotlinx_serialization_corePrimitiveKindFLOAT : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindFLOAT *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)fLOAT __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.INT")))
@interface LSDKKotlinx_serialization_corePrimitiveKindINT : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindINT *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)iNT __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.LONG")))
@interface LSDKKotlinx_serialization_corePrimitiveKindLONG : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindLONG *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)lONG __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.SHORT")))
@interface LSDKKotlinx_serialization_corePrimitiveKindSHORT : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindSHORT *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sHORT __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_corePrimitiveKind.STRING")))
@interface LSDKKotlinx_serialization_corePrimitiveKindSTRING : LSDKKotlinx_serialization_corePrimitiveKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_corePrimitiveKindSTRING *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sTRING __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind.CONTEXTUAL")))
@interface LSDKKotlinx_serialization_coreSerialKindCONTEXTUAL : LSDKKotlinx_serialization_coreSerialKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_coreSerialKindCONTEXTUAL *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cONTEXTUAL __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind.ENUM")))
@interface LSDKKotlinx_serialization_coreSerialKindENUM : LSDKKotlinx_serialization_coreSerialKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_coreSerialKindENUM *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)eNUM __attribute__((swift_name("init()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreStructureKind")))
@interface LSDKKotlinx_serialization_coreStructureKind : LSDKKotlinx_serialization_coreSerialKind
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_coreStructureKind.CLASS")))
@interface LSDKKotlinx_serialization_coreStructureKindCLASS : LSDKKotlinx_serialization_coreStructureKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_coreStructureKindCLASS *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cLASS __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_coreStructureKind.LIST")))
@interface LSDKKotlinx_serialization_coreStructureKindLIST : LSDKKotlinx_serialization_coreStructureKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_coreStructureKindLIST *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)lIST __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_coreStructureKind.MAP")))
@interface LSDKKotlinx_serialization_coreStructureKindMAP : LSDKKotlinx_serialization_coreStructureKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_coreStructureKindMAP *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)mAP __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_coreStructureKind.OBJECT")))
@interface LSDKKotlinx_serialization_coreStructureKindOBJECT : LSDKKotlinx_serialization_coreStructureKind
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_coreStructureKindOBJECT *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)oBJECT __attribute__((swift_name("init()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonPrimitiveSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonPrimitive")))
@interface LSDKKotlinx_serialization_jsonJsonPrimitive : LSDKKotlinx_serialization_jsonJsonElement
@property (class, readonly, getter=companion) LSDKKotlinx_serialization_jsonJsonPrimitiveCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) BOOL isString __attribute__((swift_name("isString")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonNullSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonNull")))
@interface LSDKKotlinx_serialization_jsonJsonNull : LSDKKotlinx_serialization_jsonJsonPrimitive
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_jsonJsonNull *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) BOOL isString __attribute__((swift_name("isString")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jsonNull __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LSDKKotlinArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause2")))
@protocol LSDKKotlinx_coroutines_coreSelectClause2 <LSDKKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("KotlinFloatIterator")))
@interface LSDKKotlinFloatIterator : LSDKBase <LSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (LSDKFloat *)next __attribute__((swift_name("next()")));
- (float)nextFloat __attribute__((swift_name("nextFloat()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface LSDKKotlinByteIterator : LSDKBase <LSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (LSDKByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement.Companion")))
@interface LSDKKotlinx_serialization_jsonJsonElementCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_jsonJsonElementCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol LSDKKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<LSDKKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<LSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) LSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface LSDKKotlinx_serialization_coreSerializersModule : LSDKBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<LSDKKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<LSDKKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<LSDKKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<LSDKKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<LSDKKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<LSDKKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<LSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<LSDKKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol LSDKKotlinAnnotation
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol LSDKKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<LSDKKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<LSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) LSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface LSDKKotlinNothing : LSDKBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinCharArray")))
@interface LSDKKotlinCharArray : LSDKBase
@property (readonly) int32_t size __attribute__((swift_name("size")));
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(id (^)(LSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LSDKKotlinCharIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_bytestringByteString.Companion")))
@interface LSDKKotlinx_io_bytestringByteStringCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinx_io_bytestringByteStringCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/**
 * Base configuration for [HttpClientEngine].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig)
 */
__attribute__((swift_name("Ktor_client_coreHttpClientEngineConfig")))
@interface LSDKKtor_client_coreHttpClientEngineConfig : LSDKBase
@property LSDKKotlinx_coroutines_coreCoroutineDispatcher * _Nullable dispatcher __attribute__((swift_name("dispatcher")));
@property BOOL pipelining __attribute__((swift_name("pipelining")));
@property LSDKKtor_client_coreProxyConfig * _Nullable proxy __attribute__((swift_name("proxy")));
@property int32_t threadsCount __attribute__((swift_name("threadsCount"))) __attribute__((unavailable("The [threadsCount] property is deprecated. Consider setting [dispatcher] instead.")));

/**
 * Base configuration for [HttpClientEngine].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Base configuration for [HttpClientEngine].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Allow specifying the coroutine dispatcher to use for IO operations.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.dispatcher)
 */

/**
 * Enables HTTP pipelining advice.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.pipelining)
 */

/**
 * Specifies a proxy address to use.
 * Uses a system proxy by default.
 *
 * You can learn more from [Proxy](https://ktor.io/docs/proxy.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.proxy)
 */

/**
 * Specifies network threads count advice.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.threadsCount)
 */
@end


/**
 * A mutable [HttpClient] configuration used to adjust settings, install plugins and interceptors.
 *
 * This configuration can be provided as a lambda in the [HttpClient] constructor or the [HttpClient.config] builder:
 * ```kotlin
 * val client = HttpClient { // HttpClientConfig<Engine>()
 *     // Configure engine settings
 *     engine { // HttpClientEngineConfig
 *         threadsCount = 4
 *         pipelining = true
 *     }
 *
 *     // Install and configure plugins
 *     install(ContentNegotiation) {
 *         json()
 *     }
 *
 *     // Configure default request parameters
 *     defaultRequest {
 *         url("https://api.example.com")
 *         header("X-Custom-Header", "value")
 *     }
 *
 *     // Configure client-wide settings
 *     expectSuccess = true
 *     followRedirects = true
 * }
 * ```
 * ## Configuring [HttpClientEngine]
 *
 * If the engine is specified explicitly, engine-specific properties will be available in the `engine` block:
 * ```kotlin
 * val client = HttpClient(CIO) { // HttpClientConfig<CIOEngineConfig>.() -> Unit
 *     engine { // CIOEngineConfig.() -> Unit
 *         // engine specific properties
 *     }
 * }
 * ```
 *
 * Learn more about the client's configuration from
 * [Creating and configuring a client](https://ktor.io/docs/create-client.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientConfig")))
@interface LSDKKtor_client_coreHttpClientConfig<T> : LSDKBase
@property BOOL developmentMode __attribute__((swift_name("developmentMode"))) __attribute__((deprecated("Development mode is no longer required. The property will be removed in the future.")));
@property BOOL expectSuccess __attribute__((swift_name("expectSuccess")));
@property BOOL followRedirects __attribute__((swift_name("followRedirects")));
@property BOOL useDefaultTransformers __attribute__((swift_name("useDefaultTransformers")));

/**
 * A mutable [HttpClient] configuration used to adjust settings, install plugins and interceptors.
 *
 * This configuration can be provided as a lambda in the [HttpClient] constructor or the [HttpClient.config] builder:
 * ```kotlin
 * val client = HttpClient { // HttpClientConfig<Engine>()
 *     // Configure engine settings
 *     engine { // HttpClientEngineConfig
 *         threadsCount = 4
 *         pipelining = true
 *     }
 *
 *     // Install and configure plugins
 *     install(ContentNegotiation) {
 *         json()
 *     }
 *
 *     // Configure default request parameters
 *     defaultRequest {
 *         url("https://api.example.com")
 *         header("X-Custom-Header", "value")
 *     }
 *
 *     // Configure client-wide settings
 *     expectSuccess = true
 *     followRedirects = true
 * }
 * ```
 * ## Configuring [HttpClientEngine]
 *
 * If the engine is specified explicitly, engine-specific properties will be available in the `engine` block:
 * ```kotlin
 * val client = HttpClient(CIO) { // HttpClientConfig<CIOEngineConfig>.() -> Unit
 *     engine { // CIOEngineConfig.() -> Unit
 *         // engine specific properties
 *     }
 * }
 * ```
 *
 * Learn more about the client's configuration from
 * [Creating and configuring a client](https://ktor.io/docs/create-client.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * A mutable [HttpClient] configuration used to adjust settings, install plugins and interceptors.
 *
 * This configuration can be provided as a lambda in the [HttpClient] constructor or the [HttpClient.config] builder:
 * ```kotlin
 * val client = HttpClient { // HttpClientConfig<Engine>()
 *     // Configure engine settings
 *     engine { // HttpClientEngineConfig
 *         threadsCount = 4
 *         pipelining = true
 *     }
 *
 *     // Install and configure plugins
 *     install(ContentNegotiation) {
 *         json()
 *     }
 *
 *     // Configure default request parameters
 *     defaultRequest {
 *         url("https://api.example.com")
 *         header("X-Custom-Header", "value")
 *     }
 *
 *     // Configure client-wide settings
 *     expectSuccess = true
 *     followRedirects = true
 * }
 * ```
 * ## Configuring [HttpClientEngine]
 *
 * If the engine is specified explicitly, engine-specific properties will be available in the `engine` block:
 * ```kotlin
 * val client = HttpClient(CIO) { // HttpClientConfig<CIOEngineConfig>.() -> Unit
 *     engine { // CIOEngineConfig.() -> Unit
 *         // engine specific properties
 *     }
 * }
 * ```
 *
 * Learn more about the client's configuration from
 * [Creating and configuring a client](https://ktor.io/docs/create-client.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Clones this [HttpClientConfig] by duplicating all the [plugins] and [customInterceptors].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.clone)
 */
- (LSDKKtor_client_coreHttpClientConfig<T> *)clone __attribute__((swift_name("clone()")));

/**
 * A builder for configuring engine-specific settings in [HttpClientEngineConfig],
 * such as dispatcher, thread count, proxy, and more.
 *
 * ```kotlin
 * val client = HttpClient(CIO) { // HttpClientConfig<CIOEngineConfig>
 *     engine { // CIOEngineConfig.() -> Unit
 *         proxy = ProxyBuilder.http("proxy.example.com", 8080)
 *     }
 * ```
 *
 * You can learn more from [Engines](https://ktor.io/docs/http-client-engines.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.engine)
 */
- (void)engineBlock:(void (^)(T))block __attribute__((swift_name("engine(block:)")));

/**
 * Applies all the installed [plugins] and [customInterceptors] from this configuration
 * into the specified [client].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.install)
 */
- (void)installClient:(LSDKKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));

/**
 * Installs the specified [plugin] and optionally configures it using the [configure] block.
 *
 * ```kotlin
 * val client = HttpClient {
 *     install(ContentNegotiation) {
 *         // configuration block
 *         json()
 *     }
 * }
 * ```
 *
 * If the plugin is already installed, the configuration block will be applied to the existing configuration class.
 *
 * Learn more from [Plugins](https://ktor.io/docs/http-client-plugins.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.install)
 */
- (void)installPlugin:(id<LSDKKtor_client_coreHttpClientPlugin>)plugin configure:(void (^)(id))configure __attribute__((swift_name("install(plugin:configure:)")));

/**
 * Installs an interceptor defined by [block].
 * The [key] parameter is used as a unique name, that also prevents installing duplicated interceptors.
 *
 * If the [key] is already used, the new interceptor will replace the old one.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.install)
 */
- (void)installKey:(NSString *)key block:(void (^)(LSDKKtor_client_coreHttpClient *))block __attribute__((swift_name("install(key:block:)")));

/**
 * Installs the plugin from the [other] client's configuration.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.plusAssign)
 */
- (void)plusAssignOther:(LSDKKtor_client_coreHttpClientConfig<T> *)other __attribute__((swift_name("plusAssign(other:)")));

/**
 * Development mode is no longer required all functionality is enabled by default. The property is safe to remove.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.developmentMode)
 */

/**
 * Terminates [HttpClient.receivePipeline] if the status code is not successful (>=300).
 * Learn more from [Response validation](https://ktor.io/docs/response-validation.html).
 *
 * For more details, see the [HttpCallValidator] documentation.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.expectSuccess)
 */

/**
 * Specifies whether the client redirects to URLs provided in the `Location` header.
 * You can disable redirections by setting this property to `false`.
 *
 * For an advanced redirection configuration, use the [HttpRedirect] plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.followRedirects)
 */

/**
 * Enables body transformations for many common types like [String], [ByteArray], [ByteReadChannel], etc.
 * These transformations are applied to the request and response bodies.
 *
 * The transformers will be used when the response body is received with a type:
 * ```kotlin
 * val client = HttpClient()
 * val bytes = client.get("https://ktor.io")
 *                   .body<ByteArray>()
 * ```
 *
 * This flag is enabled by default.
 * You might want to disable it if you want to write your own transformers or handle body manually.
 *
 * For more details, see the [defaultTransformers] documentation.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.useDefaultTransformers)
 */
@end


/**
 * Represents a capability that an [HttpClientEngine] can support, with [T] representing the type
 * of configuration or metadata associated with the capability.
 *
 * Capabilities are used to declare optional features or behaviors that an engine may support,
 * such as WebSocket communication, HTTP/2, or custom timeouts. They enable plugins and request
 * builders to configure engine-specific functionality by associating a capability with a
 * specific configuration.
 *
 * Capabilities can be set on a per-request basis using the `HttpRequestBuilder.setCapability` method,
 * allowing users to configure engine-specific behavior for individual requests.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineCapability)
 *
 * @param T The type of the configuration or metadata associated with this capability.
 *
 * Example:
 * Suppose you have a custom capability for WebSocket support that requires a specific configuration:
 * ```kotlin
 * object WebSocketCapability : HttpClientEngineCapability<WebSocketConfig>
 *
 * data class WebSocketConfig(val maxFrameSize: Int, val pingIntervalMillis: Long)
 * ```
 *
 * Setting a capability in a request:
 * ```kotlin
 * client.request {
 *     setCapability(WebSocketCapability, WebSocketConfig(
 *         maxFrameSize = 65536,
 *         pingIntervalMillis = 30000
 *     ))
 * }
 * ```
 *
 * Engine Example:
 * A custom engine implementation can declare support for specific capabilities in its `supportedCapabilities` property:
 * ```kotlin
 * override val supportedCapabilities: Set<HttpClientEngineCapability<*>> = setOf(WebSocketCapability)
 * ```
 *
 * Plugin Integration Example:
 * Plugins use capabilities to interact with engine-specific features. For example:
 * ```kotlin
 * if (engine.supportedCapabilities.contains(WebSocketCapability)) {
 *     // Configure WebSocket behavior if supported by the engine
 * }
 * ```
 *
 * When creating a custom capability:
 * - Define a singleton object implementing `HttpClientEngineCapability`.
 * - Use the type parameter [T] to provide the associated configuration type or metadata.
 * - Ensure that engines supporting the capability handle the associated configuration properly.
 */
__attribute__((swift_name("Ktor_client_coreHttpClientEngineCapability")))
@protocol LSDKKtor_client_coreHttpClientEngineCapability
@required
@end


/**
 * Map of attributes accessible by [AttributeKey] in a typed manner
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes)
 */
__attribute__((swift_name("Ktor_utilsAttributes")))
@protocol LSDKKtor_utilsAttributes
@required

/**
 * Gets a value of the attribute for the specified [key], or calls supplied [block] to compute its value
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.computeIfAbsent)
 */
- (id)computeIfAbsentKey:(LSDKKtor_utilsAttributeKey<id> *)key block:(id (^)(void))block __attribute__((swift_name("computeIfAbsent(key:block:)")));

/**
 * Checks if an attribute with the specified [key] exists
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.contains)
 */
- (BOOL)containsKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("contains(key:)")));

/**
 * Gets a value of the attribute for the specified [key], or throws an exception if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.get)
 */
- (id)getKey_:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("get(key_:)")));

/**
 * Gets a value of the attribute for the specified [key], or return `null` if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.getOrNull)
 */
- (id _Nullable)getOrNullKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getOrNull(key:)")));

/**
 * Creates or changes an attribute with the specified [key] using [value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.put)
 */
- (void)putKey:(LSDKKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("put(key:value:)")));

/**
 * Removes an attribute with the specified [key]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.remove)
 */
- (void)removeKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("remove(key:)")));

/**
 * Creates or changes an attribute with the specified [key] using [value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.set)
 */
- (void)setKey:(LSDKKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("set(key:value:)")));

/**
 * Removes an attribute with the specified [key] and returns its current value, throws an exception if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.take)
 */
- (id)takeKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("take(key:)")));

/**
 * Removes an attribute with the specified [key] and returns its current value, returns `null` if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.takeOrNull)
 */
- (id _Nullable)takeOrNullKey:(LSDKKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("takeOrNull(key:)")));

/**
 * Returns [List] of all [AttributeKey] instances in this map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.allKeys)
 */
@property (readonly) NSArray<LSDKKtor_utilsAttributeKey<id> *> *allKeys __attribute__((swift_name("allKeys")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_eventsEvents")))
@interface LSDKKtor_eventsEvents : LSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Raises the event specified by [definition] with the [value] and calls all handlers.
 *
 * Handlers are called in order of subscriptions.
 * If some handler throws an exception, all remaining handlers will still run. The exception will eventually be re-thrown.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.Events.raise)
 */
- (void)raiseDefinition:(LSDKKtor_eventsEventDefinition<id> *)definition value:(id _Nullable)value __attribute__((swift_name("raise(definition:value:)")));

/**
 * Subscribe [handler] to an event specified by [definition]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.Events.subscribe)
 */
- (id<LSDKKotlinx_coroutines_coreDisposableHandle>)subscribeDefinition:(LSDKKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("subscribe(definition:handler:)")));

/**
 * Unsubscribe [handler] from an event specified by [definition]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.Events.unsubscribe)
 */
- (void)unsubscribeDefinition:(LSDKKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("unsubscribe(definition:handler:)")));
@end


/**
 * [HttpClient] Pipeline used for receiving [HttpResponse] without any processing.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline")))
@interface LSDKKtor_client_coreHttpReceivePipeline : LSDKKtor_utilsPipeline<LSDKKtor_client_coreHttpResponse *, LSDKKotlinUnit *>
@property (class, readonly, getter=companion) LSDKKtor_client_coreHttpReceivePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LSDKKotlinArray<LSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * An [HttpClient]'s pipeline used for executing [HttpRequest].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline")))
@interface LSDKKtor_client_coreHttpRequestPipeline : LSDKKtor_utilsPipeline<id, LSDKKtor_client_coreHttpRequestBuilder *>
@property (class, readonly, getter=companion) LSDKKtor_client_coreHttpRequestPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LSDKKotlinArray<LSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * [HttpClient] Pipeline used for executing [HttpResponse].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline")))
@interface LSDKKtor_client_coreHttpResponsePipeline : LSDKKtor_utilsPipeline<LSDKKtor_client_coreHttpResponseContainer *, LSDKKtor_client_coreHttpClientCall *>
@property (class, readonly, getter=companion) LSDKKtor_client_coreHttpResponsePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LSDKKotlinArray<LSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * An [HttpClient]'s pipeline used for sending [HttpRequest] to a remote server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline")))
@interface LSDKKtor_client_coreHttpSendPipeline : LSDKKtor_utilsPipeline<id, LSDKKtor_client_coreHttpRequestBuilder *>
@property (class, readonly, getter=companion) LSDKKtor_client_coreHttpSendPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LSDKKotlinArray<LSDKKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LSDKKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LSDKKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJson.Default")))
@interface LSDKKotlinx_serialization_jsonJsonDefault : LSDKKotlinx_serialization_jsonJson
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_jsonJsonDefault *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)default_ __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonConfiguration")))
@interface LSDKKotlinx_serialization_jsonJsonConfiguration : LSDKBase
@property (readonly) BOOL allowComments __attribute__((swift_name("allowComments")));
@property (readonly) BOOL allowSpecialFloatingPointValues __attribute__((swift_name("allowSpecialFloatingPointValues")));
@property (readonly) BOOL allowStructuredMapKeys __attribute__((swift_name("allowStructuredMapKeys")));
@property (readonly) BOOL allowTrailingComma __attribute__((swift_name("allowTrailingComma")));
@property (readonly) NSString *classDiscriminator __attribute__((swift_name("classDiscriminator")));
@property LSDKKotlinx_serialization_jsonClassDiscriminatorMode *classDiscriminatorMode __attribute__((swift_name("classDiscriminatorMode")));
@property (readonly) BOOL coerceInputValues __attribute__((swift_name("coerceInputValues")));
@property (readonly) BOOL decodeEnumsCaseInsensitive __attribute__((swift_name("decodeEnumsCaseInsensitive")));
@property (readonly) BOOL encodeDefaults __attribute__((swift_name("encodeDefaults")));
@property (readonly) BOOL explicitNulls __attribute__((swift_name("explicitNulls")));
@property (readonly) BOOL ignoreUnknownKeys __attribute__((swift_name("ignoreUnknownKeys")));
@property (readonly) BOOL isLenient __attribute__((swift_name("isLenient")));
@property (readonly) id<LSDKKotlinx_serialization_jsonJsonNamingStrategy> _Nullable namingStrategy __attribute__((swift_name("namingStrategy")));
@property (readonly) BOOL prettyPrint __attribute__((swift_name("prettyPrint")));
@property (readonly) NSString *prettyPrintIndent __attribute__((swift_name("prettyPrintIndent")));
@property (readonly) BOOL useAlternativeNames __attribute__((swift_name("useAlternativeNames")));
@property (readonly) BOOL useArrayPolymorphism __attribute__((swift_name("useArrayPolymorphism")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_coreFileMetadata")))
@interface LSDKKotlinx_io_coreFileMetadata : LSDKBase
@property (readonly) BOOL isDirectory __attribute__((swift_name("isDirectory")));
@property (readonly) BOOL isRegularFile __attribute__((swift_name("isRegularFile")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
- (instancetype)initWithIsRegularFile:(BOOL)isRegularFile isDirectory:(BOOL)isDirectory size:(int64_t)size __attribute__((swift_name("init(isRegularFile:isDirectory:size:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreDisposableHandle")))
@protocol LSDKKotlinx_coroutines_coreDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildHandle")))
@protocol LSDKKotlinx_coroutines_coreChildHandle <LSDKKotlinx_coroutines_coreDisposableHandle>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BOOL)childCancelledCause:(LSDKKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
@property (readonly) id<LSDKKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildJob")))
@protocol LSDKKotlinx_coroutines_coreChildJob <LSDKKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)parentCancelledParentJob:(id<LSDKKotlinx_coroutines_coreParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol LSDKKotlinSequence
@required
- (id<LSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause0")))
@protocol LSDKKotlinx_coroutines_coreSelectClause0 <LSDKKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol LSDKKotlinCoroutineContextKey
@required
@end


/**
 * Represents a phase in a pipeline
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.PipelinePhase)
 *
 * @param name a name for this phase
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsPipelinePhase")))
@interface LSDKKtor_utilsPipelinePhase : LSDKBase
@property (readonly) NSString *name __attribute__((swift_name("name")));
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Data prepared for [HttpResponse].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpResponseData)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseData")))
@interface LSDKKtor_client_coreHttpResponseData : LSDKBase
@property (readonly) id body __attribute__((swift_name("body")));
@property (readonly) id<LSDKKotlinCoroutineContext> callContext __attribute__((swift_name("callContext")));
@property (readonly) id<LSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) LSDKKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) LSDKKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) LSDKKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
- (instancetype)initWithStatusCode:(LSDKKtor_httpHttpStatusCode *)statusCode requestTime:(LSDKKtor_utilsGMTDate *)requestTime headers:(id<LSDKKtor_httpHeaders>)headers version:(LSDKKtor_httpHttpProtocolVersion *)version body:(id)body callContext:(id<LSDKKotlinCoroutineContext>)callContext __attribute__((swift_name("init(statusCode:requestTime:headers:version:body:callContext:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientCall.Companion")))
@interface LSDKKtor_client_coreHttpClientCallCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_client_coreHttpClientCallCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/**
 * A message either from the client or the server,
 * that has [headers] associated.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessage)
 */
__attribute__((swift_name("Ktor_httpHttpMessage")))
@protocol LSDKKtor_httpHttpMessage
@required

/**
 * Message [Headers]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessage.headers)
 */
@property (readonly) id<LSDKKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@end


/**
 * A request for [HttpClient], first part of [HttpClientCall].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest)
 */
__attribute__((swift_name("Ktor_client_coreHttpRequest")))
@protocol LSDKKtor_client_coreHttpRequest <LSDKKtor_httpHttpMessage, LSDKKotlinx_coroutines_coreCoroutineScope>
@required

/**
 * Typed [Attributes] associated to this call serving as a lightweight container.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.attributes)
 */
@property (readonly) id<LSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));

/**
 * The associated [HttpClientCall] containing both
 * the underlying [HttpClientCall.request] and [HttpClientCall.response].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.call)
 */
@property (readonly) LSDKKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));

/**
 * An [OutgoingContent] representing the request body
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.content)
 */
@property (readonly) LSDKKtor_httpOutgoingContent *content __attribute__((swift_name("content")));

/**
 * The [HttpMethod] or HTTP VERB used for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.method)
 */
@property (readonly) LSDKKtor_httpHttpMethod *method __attribute__((swift_name("method")));

/**
 * The [Url] representing the endpoint and the uri for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.url)
 */
@property (readonly) LSDKKtor_httpUrl *url __attribute__((swift_name("url")));
@end


/**
 * An [HttpClient]'s response, a second part of [HttpClientCall].
 *
 * Learn more from [Receiving responses](https://ktor.io/docs/response.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse)
 */
__attribute__((swift_name("Ktor_client_coreHttpResponse")))
@interface LSDKKtor_client_coreHttpResponse : LSDKBase <LSDKKtor_httpHttpMessage, LSDKKotlinx_coroutines_coreCoroutineScope>
@property (readonly) LSDKKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<LSDKKtor_ioByteReadChannel> rawContent __attribute__((swift_name("rawContent")));
@property (readonly) LSDKKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) LSDKKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) LSDKKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));

/**
 * An [HttpClient]'s response, a second part of [HttpClientCall].
 *
 * Learn more from [Receiving responses](https://ktor.io/docs/response.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * An [HttpClient]'s response, a second part of [HttpClientCall].
 *
 * Learn more from [Receiving responses](https://ktor.io/docs/response.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The associated [HttpClientCall] containing both
 * the underlying [HttpClientCall.request] and [HttpClientCall.response].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.call)
 */

/**
 * Provides a raw [ByteReadChannel] to the response content as it is read from the network.
 * This content can be still compressed or encoded.
 *
 * This content doesn't go through any interceptors from [HttpResponsePipeline].
 *
 * If you need to read the content as decoded bytes, use the [bodyAsChannel] method instead.
 *
 * This property produces a new channel every time it's accessed.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.rawContent)
 */

/**
 * [GMTDate] of the request start.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.requestTime)
 */

/**
 * [GMTDate] of the response start.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.responseTime)
 */

/**
 * The [HttpStatusCode] returned by the server. It includes both,
 * the [HttpStatusCode.description] and the [HttpStatusCode.value] (code).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.status)
 */

/**
 * HTTP version. Usually [HttpProtocolVersion.HTTP_1_1] or [HttpProtocolVersion.HTTP_2_0].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.version)
 */
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol LSDKKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol LSDKKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol LSDKKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol LSDKKotlinKClass <LSDKKotlinKDeclarationContainer, LSDKKotlinKAnnotatedElement, LSDKKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

__attribute__((swift_name("KotlinKType")))
@protocol LSDKKotlinKType
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) NSArray<LSDKKotlinKTypeProjection *> *arguments __attribute__((swift_name("arguments")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) id<LSDKKotlinKClassifier> _Nullable classifier __attribute__((swift_name("classifier")));
@property (readonly) BOOL isMarkedNullable __attribute__((swift_name("isMarkedNullable")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface LSDKKotlinAbstractCoroutineContextElement : LSDKBase <LSDKKotlinCoroutineContextElement>
@property (readonly) id<LSDKKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
- (instancetype)initWithKey:(id<LSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol LSDKKotlinContinuationInterceptor <LSDKKotlinCoroutineContextElement>
@required
- (id<LSDKKotlinContinuation>)interceptContinuationContinuation:(id<LSDKKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<LSDKKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface LSDKKotlinx_coroutines_coreCoroutineDispatcher : LSDKKotlinAbstractCoroutineContextElement <LSDKKotlinContinuationInterceptor>
@property (class, readonly, getter=companion) LSDKKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<LSDKKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)dispatchContext:(id<LSDKKotlinCoroutineContext>)context block:(id<LSDKKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)dispatchYieldContext:(id<LSDKKotlinCoroutineContext>)context block:(id<LSDKKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<LSDKKotlinContinuation>)interceptContinuationContinuation:(id<LSDKKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<LSDKKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));
- (LSDKKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism name:(NSString * _Nullable)name __attribute__((swift_name("limitedParallelism(parallelism:name:)")));
- (LSDKKotlinx_coroutines_coreCoroutineDispatcher *)plusOther_:(LSDKKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other_:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<LSDKKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Ktor_ioJvmSerializable")))
@protocol LSDKKtor_ioJvmSerializable
@required
@end


/**
 * Represents an immutable URL
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Url)
 *
 * @property protocol
 * @property host name without port (domain)
 * @property port the specified port or protocol default port
 * @property specifiedPort port number that was specified to override protocol's default
 * @property encodedPath encoded path without query string
 * @property parameters URL query parameters
 * @property fragment URL fragment (anchor name)
 * @property user username part of URL
 * @property password password part of URL
 * @property trailingQuery keep trailing question character even if there are no query parameters
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=io/ktor/http/UrlSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl")))
@interface LSDKKtor_httpUrl : LSDKBase <LSDKKtor_ioJvmSerializable>
@property (class, readonly, getter=companion) LSDKKtor_httpUrlCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property (readonly) NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property (readonly) NSString *encodedPath __attribute__((swift_name("encodedPath")));
@property (readonly) NSString *encodedPathAndQuery __attribute__((swift_name("encodedPathAndQuery")));
@property (readonly) NSString *encodedQuery __attribute__((swift_name("encodedQuery")));
@property (readonly) NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property (readonly) NSString *fragment __attribute__((swift_name("fragment")));
@property (readonly) NSString *host __attribute__((swift_name("host")));
@property (readonly) id<LSDKKtor_httpParameters> parameters __attribute__((swift_name("parameters")));
@property (readonly) NSString * _Nullable password __attribute__((swift_name("password")));
@property (readonly) NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments"))) __attribute__((deprecated("\n        `pathSegments` is deprecated.\n\n        This property will contain an empty path segment at the beginning for URLs with a hostname,\n        and an empty path segment at the end for the URLs with a trailing slash. If you need to keep this behaviour please\n        use [rawSegments]. If you only need to access the meaningful parts of the path, consider using [segments] instead.\n             \n        Please decide if you need [rawSegments] or [segments] explicitly.\n        ")));
@property (readonly) int32_t port __attribute__((swift_name("port")));
@property (readonly) LSDKKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property (readonly) LSDKKtor_httpURLProtocol * _Nullable protocolOrNull __attribute__((swift_name("protocolOrNull")));
@property (readonly) NSArray<NSString *> *rawSegments __attribute__((swift_name("rawSegments")));
@property (readonly) NSArray<NSString *> *segments __attribute__((swift_name("segments")));
@property (readonly) int32_t specifiedPort __attribute__((swift_name("specifiedPort")));
@property (readonly) BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property (readonly) NSString * _Nullable user __attribute__((swift_name("user")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * A list containing the segments of the URL path.
 *
 * This property was designed to distinguish between absolute and relative paths,
 * so it will have an empty segment at the beginning for URLs with a hostname
 * and an empty segment at the end for URLs with a trailing slash.
 *
 * ```kotlin
 * val fullUrl = Url("http://ktor.io/docs/")
 * fullUrl.pathSegments == listOf("", "docs", "")
 *
 * val absolute = Url("/docs/")
 * absolute.pathSegments == listOf("", "docs", "")
 *
 * val relative = Url("docs")
 * relative.pathSegments == listOf("docs")
 * ```
 *
 * This behaviour may not be ideal if you're working only with full URLs.
 * If you don't require the specific handling of empty segments, consider using the [segments] property instead:
 *
 * ```kotlin
 * val fullUrl = Url("http://ktor.io/docs/")
 * fullUrl.segments == listOf("docs")
 *
 * val absolute = Url("/docs/")
 * absolute.segments == listOf("docs")
 *
 * val relative = Url("docs")
 * relative.segments == listOf("docs")
 * ```
 *
 * To address this issue, the current [pathSegments] property will be renamed to [rawSegments].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Url.pathSegments)
 */

/**
 * A list containing the segments of the URL path.
 *
 * This property is designed to distinguish between absolute and relative paths,
 * so it will have an empty segment at the beginning for URLs with a hostname
 * and an empty segment at the end for URLs with a trailing slash.
 *
 * ```kotlin
 * val fullUrl = Url("http://ktor.io/docs/")
 * fullUrl.rawSegments == listOf("", "docs", "")
 *
 * val absolute = Url("/docs/")
 * absolute.rawSegments == listOf("", "docs", "")
 *
 * val relative = Url("docs")
 * relative.rawSegments == listOf("docs")
 * ```
 *
 * This behaviour may not be ideal if you're working only with full URLs.
 * If you don't require the specific handling of empty segments, consider using the [segments] property instead:
 *
 * ```kotlin
 * val fullUrl = Url("http://ktor.io/docs/")
 * fullUrl.segments == listOf("docs")
 *
 * val absolute = Url("/docs/")
 * absolute.segments == listOf("docs")
 *
 * val relative = Url("docs")
 * relative.segments == listOf("docs")
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Url.rawSegments)
 */

/**
 * A list of path segments derived from the URL, excluding any leading
 * and trailing empty segments.
 *
 * ```kotlin
 * val fullUrl = Url("http://ktor.io/docs/")
 * fullUrl.segments == listOf("docs")
 *
 * val absolute = Url("/docs/")
 * absolute.segments == listOf("docs")
 * val relative = Url("docs")
 * relative.segments == listOf("docs")
 * ```
 *
 * If you need to check for trailing slash and relative/absolute paths, please check the [rawSegments] property.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Url.segments)
 **/
@end


/**
 * Represents an HTTP method (verb)
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod)
 *
 * @property value contains method name
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod")))
@interface LSDKKtor_httpHttpMethod : LSDKBase
@property (class, readonly, getter=companion) LSDKKtor_httpHttpMethodCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
- (LSDKKtor_httpHttpMethod *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));

/**
 * Represents an HTTP method (verb)
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod)
 *
 * @property value contains method name
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents an HTTP method (verb)
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod)
 *
 * @property value contains method name
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Provides data structure for associating a [String] with a [List] of Strings
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues)
 */
__attribute__((swift_name("Ktor_utilsStringValues")))
@protocol LSDKKtor_utilsStringValues
@required

/**
 * Checks if the given [name] exists in the map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.contains)
 */
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));

/**
 * Checks if the given [name] and [value] pair exists in the map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.contains)
 */
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));

/**
 * Gets all entries from the map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.entries)
 */
- (NSSet<id<LSDKKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));

/**
 * Iterates over all entries in this map and calls [body] for each pair
 *
 * Can be optimized in implementations
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.forEach)
 */
- (void)forEachBody:(void (^)(NSString *, NSArray<NSString *> *))body __attribute__((swift_name("forEach(body:)")));

/**
 * Gets first value from the list of values associated with a [name], or null if the name is not present
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.get)
 */
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));

/**
 * Gets all values associated with the [name], or null if the name is not present
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.getAll)
 */
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));

/**
 * Checks if this map is empty
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.isEmpty)
 */
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));

/**
 * Gets all names from the map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.names)
 */
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));

/**
 * Specifies if map has case-sensitive or case-insensitive names
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues.caseInsensitiveName)
 */
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end


/**
 * Represents HTTP headers as a map from case-insensitive names to collection of [String] values
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Headers)
 */
__attribute__((swift_name("Ktor_httpHeaders")))
@protocol LSDKKtor_httpHeaders <LSDKKtor_utilsStringValues>
@required
@end


/**
 * Specifies a key for an attribute in [Attributes]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.AttributeKey)
 *
 * @param T is a type of the value stored in the attribute
 * @property name is a name of the attribute for diagnostic purposes. Can't be blank
 * @property type the recorded kotlin type of T
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsAttributeKey")))
@interface LSDKKtor_utilsAttributeKey<T> : LSDKBase
@property (readonly) NSString *name __attribute__((swift_name("name")));

/**
 * @note annotations
 *   kotlin.jvm.JvmOverloads
*/
- (instancetype)initWithName:(NSString *)name type:(LSDKKtor_utilsTypeInfo *)type __attribute__((swift_name("init(name:type:)"))) __attribute__((objc_designated_initializer));
- (LSDKKtor_utilsAttributeKey<T> *)doCopyName:(NSString *)name type:(LSDKKtor_utilsTypeInfo *)type __attribute__((swift_name("doCopy(name:type:)")));

/**
 * Specifies a key for an attribute in [Attributes]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.AttributeKey)
 *
 * @param T is a type of the value stored in the attribute
 * @property name is a name of the attribute for diagnostic purposes. Can't be blank
 * @property type the recorded kotlin type of T
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Specifies a key for an attribute in [Attributes]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.AttributeKey)
 *
 * @param T is a type of the value stored in the attribute
 * @property name is a name of the attribute for diagnostic purposes. Can't be blank
 * @property type the recorded kotlin type of T
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents a header value that consist of [content] followed by [parameters].
 * Useful for headers such as `Content-Type`, `Content-Disposition` and so on.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HeaderValueWithParameters)
 *
 * @property content header's content without parameters
 * @property parameters
 */
__attribute__((swift_name("Ktor_httpHeaderValueWithParameters")))
@interface LSDKKtor_httpHeaderValueWithParameters : LSDKBase
@property (class, readonly, getter=companion) LSDKKtor_httpHeaderValueWithParametersCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) NSArray<LSDKKtor_httpHeaderValueParam *> *parameters __attribute__((swift_name("parameters")));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<LSDKKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer));

/**
 * The first value for the parameter with [name] comparing case-insensitively or `null` if no such parameters found
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HeaderValueWithParameters.parameter)
 */
- (NSString * _Nullable)parameterName:(NSString *)name __attribute__((swift_name("parameter(name:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@end


/**
 * Represents a value for a `Content-Type` header.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType)
 *
 * @property contentType represents a type part of the media type.
 * @property contentSubtype represents a subtype part of the media type.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType")))
@interface LSDKKtor_httpContentType : LSDKKtor_httpHeaderValueWithParameters
@property (class, readonly, getter=companion) LSDKKtor_httpContentTypeCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *contentSubtype __attribute__((swift_name("contentSubtype")));
@property (readonly) NSString *contentType __attribute__((swift_name("contentType")));
- (instancetype)initWithContentType:(NSString *)contentType contentSubtype:(NSString *)contentSubtype parameters:(NSArray<LSDKKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(contentType:contentSubtype:parameters:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<LSDKKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Checks if `this` type matches a [pattern] type taking into account placeholder symbols `*` and parameters.
 * The `this` type must be a more specific type than the [pattern] type. In other words:
 *
 * ```kotlin
 * ContentType("a", "b").match(ContentType("a", "b").withParameter("foo", "bar")) === false
 * ContentType("a", "b").withParameter("foo", "bar").match(ContentType("a", "b")) === true
 * ContentType("a", "*").match(ContentType("a", "b")) === false
 * ContentType("a", "b").match(ContentType("a", "*")) === true
 * ```
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.match)
 */
- (BOOL)matchPattern:(LSDKKtor_httpContentType *)pattern __attribute__((swift_name("match(pattern:)")));

/**
 * Checks if `this` type matches a [pattern] type taking into account placeholder symbols `*` and parameters.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.match)
 */
- (BOOL)matchPattern_:(NSString *)pattern __attribute__((swift_name("match(pattern_:)")));

/**
 * Creates a copy of `this` type with the added parameter with the [name] and [value].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.withParameter)
 */
- (LSDKKtor_httpContentType *)withParameterName:(NSString *)name value:(NSString *)value __attribute__((swift_name("withParameter(name:value:)")));

/**
 * Creates a copy of `this` type without any parameters
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.withoutParameters)
 */
- (LSDKKtor_httpContentType *)withoutParameters __attribute__((swift_name("withoutParameters()")));
@end


/**
 * Represents an HTTP status code and description.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode)
 *
 * @param value is a numeric code.
 * @param description is free form description of a status.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode")))
@interface LSDKKtor_httpHttpStatusCode : LSDKBase <LSDKKotlinComparable>
@property (class, readonly, getter=companion) LSDKKtor_httpHttpStatusCodeCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
- (instancetype)initWithValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("init(value:description:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(LSDKKtor_httpHttpStatusCode *)other __attribute__((swift_name("compareTo(other:)")));
- (LSDKKtor_httpHttpStatusCode *)doCopyValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("doCopy(value:description:)")));

/**
 * Returns a copy of `this` code with a description changed to [value].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode.description)
 */
- (LSDKKtor_httpHttpStatusCode *)descriptionValue:(NSString *)value __attribute__((swift_name("description(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("KotlinLongProgression")))
@interface LSDKKotlinLongProgression : LSDKBase <LSDKKotlinIterable>
@property (class, readonly, getter=companion) LSDKKotlinLongProgressionCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int64_t first __attribute__((swift_name("first")));
@property (readonly) int64_t last __attribute__((swift_name("last")));
@property (readonly) int64_t step __attribute__((swift_name("step")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (LSDKKotlinLongIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("KotlinClosedRange")))
@protocol LSDKKotlinClosedRange
@required
- (BOOL)containsValue:(id)value __attribute__((swift_name("contains(value:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
@property (readonly) id endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) id start __attribute__((swift_name("start")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinOpenEndRange")))
@protocol LSDKKotlinOpenEndRange
@required
- (BOOL)containsValue_:(id)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
@property (readonly) id endExclusive __attribute__((swift_name("endExclusive")));
@property (readonly, getter=start_) id start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongRange")))
@interface LSDKKotlinLongRange : LSDKKotlinLongProgression <LSDKKotlinClosedRange, LSDKKotlinOpenEndRange>
@property (class, readonly, getter=companion) LSDKKotlinLongRangeCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) LSDKLong *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Long type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) LSDKLong *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) LSDKLong *start __attribute__((swift_name("start")));
- (instancetype)initWithStart:(int64_t)start endInclusive:(int64_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
- (BOOL)containsValue:(LSDKLong *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(LSDKLong *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface LSDKKotlinUnit : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinUnit *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectInstance")))
@protocol LSDKKotlinx_coroutines_coreSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<LSDKKotlinx_coroutines_coreDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<LSDKKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonPrimitive.Companion")))
@interface LSDKKotlinx_serialization_jsonJsonPrimitiveCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinx_serialization_jsonJsonPrimitiveCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol LSDKKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<LSDKKotlinKClass>)kClass provider:(id<LSDKKotlinx_serialization_coreKSerializer> (^)(NSArray<id<LSDKKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<LSDKKotlinKClass>)kClass serializer:(id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<LSDKKotlinKClass>)baseClass actualClass:(id<LSDKKotlinKClass>)actualClass actualSerializer:(id<LSDKKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<LSDKKotlinKClass>)baseClass defaultDeserializerProvider:(id<LSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<LSDKKotlinKClass>)baseClass defaultDeserializerProvider:(id<LSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<LSDKKotlinKClass>)baseClass defaultSerializerProvider:(id<LSDKKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinCharIterator")))
@interface LSDKKotlinCharIterator : LSDKBase <LSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id)next __attribute__((swift_name("next()")));
- (unichar)nextChar __attribute__((swift_name("nextChar()")));
@end


/**
 * Proxy configuration.
 *
 * See [ProxyBuilder] to create proxy.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.ProxyConfig)
 *
 * @param url: proxy url address.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreProxyConfig")))
@interface LSDKKtor_client_coreProxyConfig : LSDKBase
@property (readonly) LSDKKtor_httpUrl *url __attribute__((swift_name("url")));
- (instancetype)initWithUrl:(LSDKKtor_httpUrl *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Base interface representing a [HttpClient] plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.plugins.HttpClientPlugin)
 */
__attribute__((swift_name("Ktor_client_coreHttpClientPlugin")))
@protocol LSDKKtor_client_coreHttpClientPlugin
@required

/**
 * Installs the [plugin] class for a [HttpClient] defined at [scope].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.plugins.HttpClientPlugin.install)
 */
- (void)installPlugin:(id)plugin scope:(LSDKKtor_client_coreHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));

/**
 * Builds a [TPlugin] by calling the [block] with a [TConfig] config instance as receiver.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.plugins.HttpClientPlugin.prepare)
 */
- (id)prepareBlock:(void (^)(id))block __attribute__((swift_name("prepare(block:)")));

/**
 * The [AttributeKey] for this plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.plugins.HttpClientPlugin.key)
 */
@property (readonly) LSDKKtor_utilsAttributeKey<id> *key __attribute__((swift_name("key")));
@end


/**
 * Definition of an event.
 * Event is used as a key so both [hashCode] and [equals] need to be implemented properly.
 * Inheriting of this class is an experimental feature.
 * Instantiate directly if inheritance not necessary.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.EventDefinition)
 *
 * @param T specifies what is a type of value passed to the event
 */
__attribute__((swift_name("Ktor_eventsEventDefinition")))
@interface LSDKKtor_eventsEventDefinition<T> : LSDKBase

/**
 * Definition of an event.
 * Event is used as a key so both [hashCode] and [equals] need to be implemented properly.
 * Inheriting of this class is an experimental feature.
 * Instantiate directly if inheritance not necessary.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.EventDefinition)
 *
 * @param T specifies what is a type of value passed to the event
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Definition of an event.
 * Event is used as a key so both [hashCode] and [equals] need to be implemented properly.
 * Inheriting of this class is an experimental feature.
 * Instantiate directly if inheritance not necessary.
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.EventDefinition)
 *
 * @param T specifies what is a type of value passed to the event
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline.Phases")))
@interface LSDKKtor_client_coreHttpReceivePipelinePhases : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_client_coreHttpReceivePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) LSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));

/**
 * Latest response pipeline phase
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline.Phases.After)
 */

/**
 * The earliest phase that happens before any other
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline.Phases.Before)
 */

/**
 * Use this phase to store request shared state
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline.Phases.State)
 */
@end


/**
 * All interceptors accept payload as [subject] and try to convert it to [OutgoingContent].
 * Last phase should proceed with [HttpClientCall].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline.Phases")))
@interface LSDKKtor_client_coreHttpRequestPipelinePhases : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_client_coreHttpRequestPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Render __attribute__((swift_name("Render")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Send __attribute__((swift_name("Send")));
@property (readonly) LSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * All interceptors accept payload as [subject] and try to convert it to [OutgoingContent].
 * Last phase should proceed with [HttpClientCall].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));

/**
 * The earliest phase that happens before any other.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Before)
 */

/**
 * Encode a request body to [OutgoingContent].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Render)
 */

/**
 * A phase for the [HttpSend] plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Send)
 */

/**
 * Use this phase to modify a request with a shared state.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.State)
 */

/**
 * Transform a request body to supported render format.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Transform)
 */
@end


/**
 * A builder message either for the client or the server,
 * that has a [headers] builder associated.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessageBuilder)
 */
__attribute__((swift_name("Ktor_httpHttpMessageBuilder")))
@protocol LSDKKtor_httpHttpMessageBuilder
@required

/**
 * MessageBuilder [HeadersBuilder]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessageBuilder.headers)
 */
@property (readonly) LSDKKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@end


/**
 * Contains parameters used to make an HTTP request.
 *
 * Learn more from [Making requests](https://ktor.io/docs/request.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestBuilder")))
@interface LSDKKtor_client_coreHttpRequestBuilder : LSDKBase <LSDKKtor_httpHttpMessageBuilder>
@property (class, readonly, getter=companion) LSDKKtor_client_coreHttpRequestBuilderCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) id<LSDKKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property id body __attribute__((swift_name("body")));
@property LSDKKtor_utilsTypeInfo * _Nullable bodyType __attribute__((swift_name("bodyType")));
@property (readonly) id<LSDKKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) LSDKKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@property LSDKKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) LSDKKtor_httpURLBuilder *url __attribute__((swift_name("url")));

/**
 * Contains parameters used to make an HTTP request.
 *
 * Learn more from [Making requests](https://ktor.io/docs/request.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder)
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * Contains parameters used to make an HTTP request.
 *
 * Learn more from [Making requests](https://ktor.io/docs/request.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder)
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * Creates immutable [HttpRequestData].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.build)
 */
- (LSDKKtor_client_coreHttpRequestData *)build __attribute__((swift_name("build()")));

/**
 * Retrieves capability by the key.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.getCapabilityOrNull)
 */
- (id _Nullable)getCapabilityOrNullKey:(id<LSDKKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));

/**
 * Sets request-specific attributes specified by [block].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.setAttributes)
 */
- (void)setAttributesBlock:(void (^)(id<LSDKKtor_utilsAttributes>))block __attribute__((swift_name("setAttributes(block:)")));

/**
 * Sets capability configuration.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.setCapability)
 */
- (void)setCapabilityKey:(id<LSDKKtor_client_coreHttpClientEngineCapability>)key capability:(id)capability __attribute__((swift_name("setCapability(key:capability:)")));

/**
 * Mutates [this] by copying all the data but execution context from another [builder] using it as the base.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.takeFrom)
 */
- (LSDKKtor_client_coreHttpRequestBuilder *)takeFromBuilder:(LSDKKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFrom(builder:)")));

/**
 * Mutates [this] copying all the data from another [builder] using it as the base.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.takeFromWithExecutionContext)
 */
- (LSDKKtor_client_coreHttpRequestBuilder *)takeFromWithExecutionContextBuilder:(LSDKKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFromWithExecutionContext(builder:)")));

/**
 * Executes a [block] that configures the [URLBuilder] associated to this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.url)
 */
- (void)urlBlock:(void (^)(LSDKKtor_httpURLBuilder *, LSDKKtor_httpURLBuilder *))block __attribute__((swift_name("url(block:)")));

/**
 * Provides access to attributes specific for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.attributes)
 */

/**
 * The [body] for this request. Initially [EmptyContent].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.body)
 */

/**
 * The [KType] of [body] for this request. Null for default types that don't need serialization.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.bodyType)
 */

/**
 * A deferred used to control the execution of this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.executionContext)
 */

/**
 * [HeadersBuilder] to configure the headers for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.headers)
 */

/**
 * [HttpMethod] used by this request. [HttpMethod.Get] by default.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.method)
 */

/**
 * [URLBuilder] to configure the URL for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.url)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline.Phases")))
@interface LSDKKtor_client_coreHttpResponsePipelinePhases : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_client_coreHttpResponsePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Parse __attribute__((swift_name("Parse")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) LSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));

/**
 * Latest response pipeline phase
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.After)
 */

/**
 * Decode response body
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.Parse)
 */

/**
 * The earliest phase that happens before any other
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.Receive)
 */

/**
 * Use this phase to store request shared state
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.State)
 */

/**
 * Transform response body to expected format
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.Transform)
 */
@end


/**
 * Class representing a typed [response] with an attached [expectedType].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponseContainer)
 *
 * @param expectedType: information about expected type.
 * @param response: current response state.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseContainer")))
@interface LSDKKtor_client_coreHttpResponseContainer : LSDKBase
@property (readonly) LSDKKtor_utilsTypeInfo *expectedType __attribute__((swift_name("expectedType")));
@property (readonly) id response __attribute__((swift_name("response")));
- (instancetype)initWithExpectedType:(LSDKKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("init(expectedType:response:)"))) __attribute__((objc_designated_initializer));
- (LSDKKtor_client_coreHttpResponseContainer *)doCopyExpectedType:(LSDKKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("doCopy(expectedType:response:)")));

/**
 * Class representing a typed [response] with an attached [expectedType].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponseContainer)
 *
 * @param expectedType: information about expected type.
 * @param response: current response state.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Class representing a typed [response] with an attached [expectedType].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponseContainer)
 *
 * @param expectedType: information about expected type.
 * @param response: current response state.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Class representing a typed [response] with an attached [expectedType].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponseContainer)
 *
 * @param expectedType: information about expected type.
 * @param response: current response state.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline.Phases")))
@interface LSDKKtor_client_coreHttpSendPipelinePhases : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_client_coreHttpSendPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Engine __attribute__((swift_name("Engine")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Monitoring __attribute__((swift_name("Monitoring")));
@property (readonly) LSDKKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) LSDKKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));

/**
 * The earliest phase that happens before any other.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Before)
 */

/**
 * Send a request to a remote server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Engine)
 */

/**
 * Use this phase for logging and other actions that don't modify a request or shared data.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Monitoring)
 */

/**
 * Receive a pipeline execution phase.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Receive)
 */

/**
 * Use this phase to modify request with a shared state.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.State)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonClassDiscriminatorMode")))
@interface LSDKKotlinx_serialization_jsonClassDiscriminatorMode : LSDKKotlinEnum<LSDKKotlinx_serialization_jsonClassDiscriminatorMode *>
@property (class, readonly) LSDKKotlinx_serialization_jsonClassDiscriminatorMode *none __attribute__((swift_name("none")));
@property (class, readonly) LSDKKotlinx_serialization_jsonClassDiscriminatorMode *allJsonObjects __attribute__((swift_name("allJsonObjects")));
@property (class, readonly) LSDKKotlinx_serialization_jsonClassDiscriminatorMode *polymorphic __attribute__((swift_name("polymorphic")));
@property (class, readonly) NSArray<LSDKKotlinx_serialization_jsonClassDiscriminatorMode *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKKotlinx_serialization_jsonClassDiscriminatorMode *> *)values __attribute__((swift_name("values()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonNamingStrategy")))
@protocol LSDKKotlinx_serialization_jsonJsonNamingStrategy
@required
- (NSString *)serialNameForJsonDescriptor:(id<LSDKKotlinx_serialization_coreSerialDescriptor>)descriptor elementIndex:(int32_t)elementIndex serialName:(NSString *)serialName __attribute__((swift_name("serialNameForJson(descriptor:elementIndex:serialName:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreParentJob")))
@protocol LSDKKotlinx_coroutines_coreParentJob <LSDKKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (LSDKKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end


/**
 * Date in GMT timezone
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.GMTDate)
 *
 * @property seconds: seconds from 0 to 60(last is for leap second)
 * @property minutes: minutes from 0 to 59
 * @property hours: hours from 0 to 23
 * @property dayOfWeek an instance of the corresponding day of week
 * @property dayOfMonth: day of month from 1 to 31
 * @property dayOfYear: day of year from 1 to 366
 * @property month an instance of the corresponding month
 * @property year: year in common era(CE: https://en.wikipedia.org/wiki/Common_Era)
 *
 * @property timestamp is a number of epoch milliseconds
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate")))
@interface LSDKKtor_utilsGMTDate : LSDKBase <LSDKKotlinComparable>
@property (class, readonly, getter=companion) LSDKKtor_utilsGMTDateCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth")));
@property (readonly) LSDKKtor_utilsWeekDay *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) LSDKKtor_utilsMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int64_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
- (instancetype)initWithSeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(LSDKKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(LSDKKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("init(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(LSDKKtor_utilsGMTDate *)other __attribute__((swift_name("compareTo(other:)")));
- (LSDKKtor_utilsGMTDate *)doCopy __attribute__((swift_name("doCopy()")));
- (LSDKKtor_utilsGMTDate *)doCopySeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(LSDKKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(LSDKKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("doCopy(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)")));

/**
 * Date in GMT timezone
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.GMTDate)
 *
 * @property seconds: seconds from 0 to 60(last is for leap second)
 * @property minutes: minutes from 0 to 59
 * @property hours: hours from 0 to 23
 * @property dayOfWeek an instance of the corresponding day of week
 * @property dayOfMonth: day of month from 1 to 31
 * @property dayOfYear: day of year from 1 to 366
 * @property month an instance of the corresponding month
 * @property year: year in common era(CE: https://en.wikipedia.org/wiki/Common_Era)
 *
 * @property timestamp is a number of epoch milliseconds
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Date in GMT timezone
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.GMTDate)
 *
 * @property seconds: seconds from 0 to 60(last is for leap second)
 * @property minutes: minutes from 0 to 59
 * @property hours: hours from 0 to 23
 * @property dayOfWeek an instance of the corresponding day of week
 * @property dayOfMonth: day of month from 1 to 31
 * @property dayOfYear: day of year from 1 to 366
 * @property month an instance of the corresponding month
 * @property year: year in common era(CE: https://en.wikipedia.org/wiki/Common_Era)
 *
 * @property timestamp is a number of epoch milliseconds
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Date in GMT timezone
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.GMTDate)
 *
 * @property seconds: seconds from 0 to 60(last is for leap second)
 * @property minutes: minutes from 0 to 59
 * @property hours: hours from 0 to 23
 * @property dayOfWeek an instance of the corresponding day of week
 * @property dayOfMonth: day of month from 1 to 31
 * @property dayOfYear: day of year from 1 to 366
 * @property month an instance of the corresponding month
 * @property year: year in common era(CE: https://en.wikipedia.org/wiki/Common_Era)
 *
 * @property timestamp is a number of epoch milliseconds
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents an HTTP protocol version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion)
 *
 * @property name specifies name of the protocol, e.g. "HTTP".
 * @property major specifies protocol major version.
 * @property minor specifies protocol minor version.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion")))
@interface LSDKKtor_httpHttpProtocolVersion : LSDKBase
@property (class, readonly, getter=companion) LSDKKtor_httpHttpProtocolVersionCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
- (instancetype)initWithName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("init(name:major:minor:)"))) __attribute__((objc_designated_initializer));
- (LSDKKtor_httpHttpProtocolVersion *)doCopyName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("doCopy(name:major:minor:)")));

/**
 * Represents an HTTP protocol version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion)
 *
 * @property name specifies name of the protocol, e.g. "HTTP".
 * @property major specifies protocol major version.
 * @property minor specifies protocol minor version.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents an HTTP protocol version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion)
 *
 * @property name specifies name of the protocol, e.g. "HTTP".
 * @property major specifies protocol major version.
 * @property minor specifies protocol minor version.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection")))
@interface LSDKKotlinKTypeProjection : LSDKBase
@property (class, readonly, getter=companion) LSDKKotlinKTypeProjectionCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) id<LSDKKotlinKType> _Nullable type __attribute__((swift_name("type")));
@property (readonly) LSDKKotlinKVariance * _Nullable variance __attribute__((swift_name("variance")));
- (instancetype)initWithVariance:(LSDKKotlinKVariance * _Nullable)variance type:(id<LSDKKotlinKType> _Nullable)type __attribute__((swift_name("init(variance:type:)"))) __attribute__((objc_designated_initializer));
- (LSDKKotlinKTypeProjection *)doCopyVariance:(LSDKKotlinKVariance * _Nullable)variance type:(id<LSDKKotlinKType> _Nullable)type __attribute__((swift_name("doCopy(variance:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol LSDKKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<LSDKKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface LSDKKotlinAbstractCoroutineContextKey<B, E> : LSDKBase <LSDKKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<LSDKKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<LSDKKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface LSDKKotlinx_coroutines_coreCoroutineDispatcherKey : LSDKKotlinAbstractCoroutineContextKey<id<LSDKKotlinContinuationInterceptor>, LSDKKotlinx_coroutines_coreCoroutineDispatcher *>
@property (class, readonly, getter=shared) LSDKKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<LSDKKotlinCoroutineContextKey>)baseKey safeCast:(id<LSDKKotlinCoroutineContextElement> _Nullable (^)(id<LSDKKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl.Companion")))
@interface LSDKKtor_httpUrlCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpUrlCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Represents HTTP parameters as a map from case-insensitive names to collection of [String] values
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Parameters)
 */
__attribute__((swift_name("Ktor_httpParameters")))
@protocol LSDKKtor_httpParameters <LSDKKtor_utilsStringValues>
@required
@end


/**
 * Represents URL protocol
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol)
 *
 * @property name of protocol (schema)
 * @property defaultPort default port for protocol or `-1` if not known
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol")))
@interface LSDKKtor_httpURLProtocol : LSDKBase <LSDKKtor_ioJvmSerializable>
@property (class, readonly, getter=companion) LSDKKtor_httpURLProtocolCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t defaultPort __attribute__((swift_name("defaultPort")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
- (instancetype)initWithName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("init(name:defaultPort:)"))) __attribute__((objc_designated_initializer));
- (LSDKKtor_httpURLProtocol *)doCopyName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("doCopy(name:defaultPort:)")));

/**
 * Represents URL protocol
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol)
 *
 * @property name of protocol (schema)
 * @property defaultPort default port for protocol or `-1` if not known
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents URL protocol
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol)
 *
 * @property name of protocol (schema)
 * @property defaultPort default port for protocol or `-1` if not known
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents URL protocol
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol)
 *
 * @property name of protocol (schema)
 * @property defaultPort default port for protocol or `-1` if not known
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod.Companion")))
@interface LSDKKtor_httpHttpMethodCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpHttpMethodCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSArray<LSDKKtor_httpHttpMethod *> *DefaultMethods __attribute__((swift_name("DefaultMethods")));
@property (readonly) LSDKKtor_httpHttpMethod *Delete __attribute__((swift_name("Delete")));
@property (readonly) LSDKKtor_httpHttpMethod *Get __attribute__((swift_name("Get")));
@property (readonly) LSDKKtor_httpHttpMethod *Head __attribute__((swift_name("Head")));
@property (readonly) LSDKKtor_httpHttpMethod *Options __attribute__((swift_name("Options")));
@property (readonly) LSDKKtor_httpHttpMethod *Patch __attribute__((swift_name("Patch")));
@property (readonly) LSDKKtor_httpHttpMethod *Post __attribute__((swift_name("Post")));
@property (readonly) LSDKKtor_httpHttpMethod *Put __attribute__((swift_name("Put")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Parse HTTP method by [method] string
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod.Companion.parse)
 */
- (LSDKKtor_httpHttpMethod *)parseMethod:(NSString *)method __attribute__((swift_name("parse(method:)")));

/**
 * A list of default HTTP methods
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod.Companion.DefaultMethods)
 */
@end

__attribute__((swift_name("KotlinMapEntry")))
@protocol LSDKKotlinMapEntry
@required
@property (readonly) id _Nullable key __attribute__((swift_name("key")));
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end


/**
 * Represents a single value parameter
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HeaderValueParam)
 *
 * @property name of parameter
 * @property value of parameter
 * @property escapeValue specifies if the value should be escaped
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueParam")))
@interface LSDKKtor_httpHeaderValueParam : LSDKBase
@property (readonly) BOOL escapeValue __attribute__((swift_name("escapeValue")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
- (instancetype)initWithName:(NSString *)name value:(NSString *)value __attribute__((swift_name("init(name:value:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("init(name:value:escapeValue:)"))) __attribute__((objc_designated_initializer));
- (LSDKKtor_httpHeaderValueParam *)doCopyName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("doCopy(name:value:escapeValue:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents a single value parameter
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HeaderValueParam)
 *
 * @property name of parameter
 * @property value of parameter
 * @property escapeValue specifies if the value should be escaped
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueWithParameters.Companion")))
@interface LSDKKtor_httpHeaderValueWithParametersCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpHeaderValueWithParametersCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Parse header with parameter and pass it to [init] function to instantiate particular type
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HeaderValueWithParameters.Companion.parse)
 */
- (id _Nullable)parseValue:(NSString *)value init:(id _Nullable (^)(NSString *, NSArray<LSDKKtor_httpHeaderValueParam *> *))init __attribute__((swift_name("parse(value:init:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType.Companion")))
@interface LSDKKtor_httpContentTypeCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpContentTypeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_httpContentType *Any __attribute__((swift_name("Any")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Parses a string representing a `Content-Type` header into a [ContentType] instance.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.Companion.parse)
 */
- (LSDKKtor_httpContentType *)parseValue:(NSString *)value __attribute__((swift_name("parse(value:)")));

/**
 * Represents a pattern `* / *` to match any content type.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.Companion.Any)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode.Companion")))
@interface LSDKKtor_httpHttpStatusCodeCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpHttpStatusCodeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Accepted __attribute__((swift_name("Accepted")));
@property (readonly) LSDKKtor_httpHttpStatusCode *BadGateway __attribute__((swift_name("BadGateway")));
@property (readonly) LSDKKtor_httpHttpStatusCode *BadRequest __attribute__((swift_name("BadRequest")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Conflict __attribute__((swift_name("Conflict")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Continue __attribute__((swift_name("Continue")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Created __attribute__((swift_name("Created")));
@property (readonly) LSDKKtor_httpHttpStatusCode *ExpectationFailed __attribute__((swift_name("ExpectationFailed")));
@property (readonly) LSDKKtor_httpHttpStatusCode *FailedDependency __attribute__((swift_name("FailedDependency")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Forbidden __attribute__((swift_name("Forbidden")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Found __attribute__((swift_name("Found")));
@property (readonly) LSDKKtor_httpHttpStatusCode *GatewayTimeout __attribute__((swift_name("GatewayTimeout")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Gone __attribute__((swift_name("Gone")));
@property (readonly) LSDKKtor_httpHttpStatusCode *InsufficientStorage __attribute__((swift_name("InsufficientStorage")));
@property (readonly) LSDKKtor_httpHttpStatusCode *InternalServerError __attribute__((swift_name("InternalServerError")));
@property (readonly) LSDKKtor_httpHttpStatusCode *LengthRequired __attribute__((swift_name("LengthRequired")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Locked __attribute__((swift_name("Locked")));
@property (readonly) LSDKKtor_httpHttpStatusCode *MethodNotAllowed __attribute__((swift_name("MethodNotAllowed")));
@property (readonly) LSDKKtor_httpHttpStatusCode *MovedPermanently __attribute__((swift_name("MovedPermanently")));
@property (readonly) LSDKKtor_httpHttpStatusCode *MultiStatus __attribute__((swift_name("MultiStatus")));
@property (readonly) LSDKKtor_httpHttpStatusCode *MultipleChoices __attribute__((swift_name("MultipleChoices")));
@property (readonly) LSDKKtor_httpHttpStatusCode *NoContent __attribute__((swift_name("NoContent")));
@property (readonly) LSDKKtor_httpHttpStatusCode *NonAuthoritativeInformation __attribute__((swift_name("NonAuthoritativeInformation")));
@property (readonly) LSDKKtor_httpHttpStatusCode *NotAcceptable __attribute__((swift_name("NotAcceptable")));
@property (readonly) LSDKKtor_httpHttpStatusCode *NotFound __attribute__((swift_name("NotFound")));
@property (readonly) LSDKKtor_httpHttpStatusCode *NotImplemented __attribute__((swift_name("NotImplemented")));
@property (readonly) LSDKKtor_httpHttpStatusCode *NotModified __attribute__((swift_name("NotModified")));
@property (readonly) LSDKKtor_httpHttpStatusCode *OK __attribute__((swift_name("OK")));
@property (readonly) LSDKKtor_httpHttpStatusCode *PartialContent __attribute__((swift_name("PartialContent")));
@property (readonly) LSDKKtor_httpHttpStatusCode *PayloadTooLarge __attribute__((swift_name("PayloadTooLarge")));
@property (readonly) LSDKKtor_httpHttpStatusCode *PaymentRequired __attribute__((swift_name("PaymentRequired")));
@property (readonly) LSDKKtor_httpHttpStatusCode *PermanentRedirect __attribute__((swift_name("PermanentRedirect")));
@property (readonly) LSDKKtor_httpHttpStatusCode *PreconditionFailed __attribute__((swift_name("PreconditionFailed")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Processing __attribute__((swift_name("Processing")));
@property (readonly) LSDKKtor_httpHttpStatusCode *ProxyAuthenticationRequired __attribute__((swift_name("ProxyAuthenticationRequired")));
@property (readonly) LSDKKtor_httpHttpStatusCode *RequestHeaderFieldTooLarge __attribute__((swift_name("RequestHeaderFieldTooLarge")));
@property (readonly) LSDKKtor_httpHttpStatusCode *RequestTimeout __attribute__((swift_name("RequestTimeout")));
@property (readonly) LSDKKtor_httpHttpStatusCode *RequestURITooLong __attribute__((swift_name("RequestURITooLong")));
@property (readonly) LSDKKtor_httpHttpStatusCode *RequestedRangeNotSatisfiable __attribute__((swift_name("RequestedRangeNotSatisfiable")));
@property (readonly) LSDKKtor_httpHttpStatusCode *ResetContent __attribute__((swift_name("ResetContent")));
@property (readonly) LSDKKtor_httpHttpStatusCode *SeeOther __attribute__((swift_name("SeeOther")));
@property (readonly) LSDKKtor_httpHttpStatusCode *ServiceUnavailable __attribute__((swift_name("ServiceUnavailable")));
@property (readonly) LSDKKtor_httpHttpStatusCode *SwitchProxy __attribute__((swift_name("SwitchProxy")));
@property (readonly) LSDKKtor_httpHttpStatusCode *SwitchingProtocols __attribute__((swift_name("SwitchingProtocols")));
@property (readonly) LSDKKtor_httpHttpStatusCode *TemporaryRedirect __attribute__((swift_name("TemporaryRedirect")));
@property (readonly) LSDKKtor_httpHttpStatusCode *TooEarly __attribute__((swift_name("TooEarly")));
@property (readonly) LSDKKtor_httpHttpStatusCode *TooManyRequests __attribute__((swift_name("TooManyRequests")));
@property (readonly) LSDKKtor_httpHttpStatusCode *Unauthorized __attribute__((swift_name("Unauthorized")));
@property (readonly) LSDKKtor_httpHttpStatusCode *UnprocessableEntity __attribute__((swift_name("UnprocessableEntity")));
@property (readonly) LSDKKtor_httpHttpStatusCode *UnsupportedMediaType __attribute__((swift_name("UnsupportedMediaType")));
@property (readonly) LSDKKtor_httpHttpStatusCode *UpgradeRequired __attribute__((swift_name("UpgradeRequired")));
@property (readonly) LSDKKtor_httpHttpStatusCode *UseProxy __attribute__((swift_name("UseProxy")));
@property (readonly) LSDKKtor_httpHttpStatusCode *VariantAlsoNegotiates __attribute__((swift_name("VariantAlsoNegotiates")));
@property (readonly) LSDKKtor_httpHttpStatusCode *VersionNotSupported __attribute__((swift_name("VersionNotSupported")));
@property (readonly) NSArray<LSDKKtor_httpHttpStatusCode *> *allStatusCodes __attribute__((swift_name("allStatusCodes")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Creates an instance of [HttpStatusCode] with the given numeric value.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode.Companion.fromValue)
 */
- (LSDKKtor_httpHttpStatusCode *)fromValueValue:(int32_t)value __attribute__((swift_name("fromValue(value:)")));

/**
 * All known status codes
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode.Companion.allStatusCodes)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongProgression.Companion")))
@interface LSDKKotlinLongProgressionCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinLongProgressionCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (LSDKKotlinLongProgression *)fromClosedRangeRangeStart:(int64_t)rangeStart rangeEnd:(int64_t)rangeEnd step:(int64_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((swift_name("KotlinLongIterator")))
@interface LSDKKotlinLongIterator : LSDKBase <LSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (LSDKLong *)next __attribute__((swift_name("next()")));
- (int64_t)nextLong __attribute__((swift_name("nextLong()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongRange.Companion")))
@interface LSDKKotlinLongRangeCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinLongRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKotlinLongRange *EMPTY __attribute__((swift_name("EMPTY")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilder")))
@protocol LSDKKtor_utilsStringValuesBuilder
@required
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<LSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<LSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<LSDKKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<LSDKKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilderImpl")))
@interface LSDKKtor_utilsStringValuesBuilderImpl : LSDKBase <LSDKKtor_utilsStringValuesBuilder>
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@property (readonly) LSDKMutableDictionary<NSString *, NSMutableArray<NSString *> *> *values __attribute__((swift_name("values")));
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer));
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<LSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<LSDKKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<LSDKKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<LSDKKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeadersBuilder")))
@interface LSDKKtor_httpHeadersBuilder : LSDKKtor_utilsStringValuesBuilderImpl
- (instancetype)initWithSize:(int32_t)size __attribute__((swift_name("init(size:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (id<LSDKKtor_httpHeaders>)build __attribute__((swift_name("build()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestBuilder.Companion")))
@interface LSDKKtor_client_coreHttpRequestBuilderCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_client_coreHttpRequestBuilderCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end


/**
 * A URL builder with all mutable components
 *
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLBuilder)
 *
 * @property protocol URL protocol (scheme)
 * @property host name without port (domain)
 * @property port port number
 * @property user username part (optional)
 * @property password password part (optional)
 * @property pathSegments URL path without query
 * @property parameters URL query parameters
 * @property fragment URL fragment (anchor name)
 * @property trailingQuery keep a trailing question character even if there are no query parameters
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder")))
@interface LSDKKtor_httpURLBuilder : LSDKBase
@property (class, readonly, getter=companion) LSDKKtor_httpURLBuilderCompanion *companion __attribute__((swift_name("companion")));
@property NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property id<LSDKKtor_httpParametersBuilder> encodedParameters __attribute__((swift_name("encodedParameters")));
@property NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property NSArray<NSString *> *encodedPathSegments __attribute__((swift_name("encodedPathSegments")));
@property NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property NSString *fragment __attribute__((swift_name("fragment")));
@property NSString *host __attribute__((swift_name("host")));
@property (readonly) id<LSDKKtor_httpParametersBuilder> parameters __attribute__((swift_name("parameters")));
@property NSString * _Nullable password __attribute__((swift_name("password")));
@property NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property int32_t port __attribute__((swift_name("port")));
@property LSDKKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property LSDKKtor_httpURLProtocol * _Nullable protocolOrNull __attribute__((swift_name("protocolOrNull")));
@property BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property NSString * _Nullable user __attribute__((swift_name("user")));
- (instancetype)initWithProtocol:(LSDKKtor_httpURLProtocol * _Nullable)protocol host:(NSString *)host port:(int32_t)port user:(NSString * _Nullable)user password:(NSString * _Nullable)password pathSegments:(NSArray<NSString *> *)pathSegments parameters:(id<LSDKKtor_httpParameters>)parameters fragment:(NSString *)fragment trailingQuery:(BOOL)trailingQuery __attribute__((swift_name("init(protocol:host:port:user:password:pathSegments:parameters:fragment:trailingQuery:)"))) __attribute__((objc_designated_initializer));

/**
 * Build a [Url] instance (everything is copied to a new instance)
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLBuilder.build)
 */
- (LSDKKtor_httpUrl *)build __attribute__((swift_name("build()")));

/**
 * Build a URL string
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLBuilder.buildString)
 */
- (NSString *)buildString __attribute__((swift_name("buildString()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Day of week
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay")))
@interface LSDKKtor_utilsWeekDay : LSDKKotlinEnum<LSDKKtor_utilsWeekDay *>
@property (class, readonly, getter=companion) LSDKKtor_utilsWeekDayCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LSDKKtor_utilsWeekDay *monday __attribute__((swift_name("monday")));
@property (class, readonly) LSDKKtor_utilsWeekDay *tuesday __attribute__((swift_name("tuesday")));
@property (class, readonly) LSDKKtor_utilsWeekDay *wednesday __attribute__((swift_name("wednesday")));
@property (class, readonly) LSDKKtor_utilsWeekDay *thursday __attribute__((swift_name("thursday")));
@property (class, readonly) LSDKKtor_utilsWeekDay *friday __attribute__((swift_name("friday")));
@property (class, readonly) LSDKKtor_utilsWeekDay *saturday __attribute__((swift_name("saturday")));
@property (class, readonly) LSDKKtor_utilsWeekDay *sunday __attribute__((swift_name("sunday")));
@property (class, readonly) NSArray<LSDKKtor_utilsWeekDay *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Day of week
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKKtor_utilsWeekDay *> *)values __attribute__((swift_name("values()")));
@end


/**
 * Month
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth")))
@interface LSDKKtor_utilsMonth : LSDKKotlinEnum<LSDKKtor_utilsMonth *>
@property (class, readonly, getter=companion) LSDKKtor_utilsMonthCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LSDKKtor_utilsMonth *january __attribute__((swift_name("january")));
@property (class, readonly) LSDKKtor_utilsMonth *february __attribute__((swift_name("february")));
@property (class, readonly) LSDKKtor_utilsMonth *march __attribute__((swift_name("march")));
@property (class, readonly) LSDKKtor_utilsMonth *april __attribute__((swift_name("april")));
@property (class, readonly) LSDKKtor_utilsMonth *may __attribute__((swift_name("may")));
@property (class, readonly) LSDKKtor_utilsMonth *june __attribute__((swift_name("june")));
@property (class, readonly) LSDKKtor_utilsMonth *july __attribute__((swift_name("july")));
@property (class, readonly) LSDKKtor_utilsMonth *august __attribute__((swift_name("august")));
@property (class, readonly) LSDKKtor_utilsMonth *september __attribute__((swift_name("september")));
@property (class, readonly) LSDKKtor_utilsMonth *october __attribute__((swift_name("october")));
@property (class, readonly) LSDKKtor_utilsMonth *november __attribute__((swift_name("november")));
@property (class, readonly) LSDKKtor_utilsMonth *december __attribute__((swift_name("december")));
@property (class, readonly) NSArray<LSDKKtor_utilsMonth *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Month
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKKtor_utilsMonth *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate.Companion")))
@interface LSDKKtor_utilsGMTDateCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_utilsGMTDateCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_utilsGMTDate *START __attribute__((swift_name("START")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (id<LSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));

/**
 * An instance of [GMTDate] corresponding to the epoch beginning
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.GMTDate.Companion.START)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion.Companion")))
@interface LSDKKtor_httpHttpProtocolVersionCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpHttpProtocolVersionCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *HTTP_1_0 __attribute__((swift_name("HTTP_1_0")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *HTTP_1_1 __attribute__((swift_name("HTTP_1_1")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *HTTP_2_0 __attribute__((swift_name("HTTP_2_0")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *HTTP_3_0 __attribute__((swift_name("HTTP_3_0")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *QUIC __attribute__((swift_name("QUIC")));
@property (readonly) LSDKKtor_httpHttpProtocolVersion *SPDY_3 __attribute__((swift_name("SPDY_3")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Creates an instance of [HttpProtocolVersion] from the given parameters.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.fromValue)
 */
- (LSDKKtor_httpHttpProtocolVersion *)fromValueName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("fromValue(name:major:minor:)")));

/**
 * Create an instance of [HttpProtocolVersion] from http string representation.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.parse)
 */
- (LSDKKtor_httpHttpProtocolVersion *)parseValue:(id)value __attribute__((swift_name("parse(value:)")));

/**
 * HTTP/1.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_1_0)
 */

/**
 * HTTP/1.1 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_1_1)
 */

/**
 * HTTP/2.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_2_0)
 */

/**
 * HTTP/3.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_3_0)
 */

/**
 * QUIC/1.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.QUIC)
 */

/**
 * SPDY/3.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.SPDY_3)
 */
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKVariance")))
@interface LSDKKotlinKVariance : LSDKKotlinEnum<LSDKKotlinKVariance *>
@property (class, readonly) LSDKKotlinKVariance *invariant __attribute__((swift_name("invariant")));
@property (class, readonly) LSDKKotlinKVariance *in __attribute__((swift_name("in")));
@property (class, readonly) LSDKKotlinKVariance *out __attribute__((swift_name("out")));
@property (class, readonly) NSArray<LSDKKotlinKVariance *> *entries __attribute__((swift_name("entries")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (LSDKKotlinArray<LSDKKotlinKVariance *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection.Companion")))
@interface LSDKKotlinKTypeProjectionCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKotlinKTypeProjectionCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKotlinKTypeProjection *STAR __attribute__((swift_name("STAR")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (LSDKKotlinKTypeProjection *)contravariantType:(id<LSDKKotlinKType>)type __attribute__((swift_name("contravariant(type:)")));
- (LSDKKotlinKTypeProjection *)covariantType:(id<LSDKKotlinKType>)type __attribute__((swift_name("covariant(type:)")));
- (LSDKKotlinKTypeProjection *)invariantType:(id<LSDKKotlinKType>)type __attribute__((swift_name("invariant(type:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol.Companion")))
@interface LSDKKtor_httpURLProtocolCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpURLProtocolCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) LSDKKtor_httpURLProtocol *HTTP __attribute__((swift_name("HTTP")));
@property (readonly) LSDKKtor_httpURLProtocol *HTTPS __attribute__((swift_name("HTTPS")));
@property (readonly) LSDKKtor_httpURLProtocol *SOCKS __attribute__((swift_name("SOCKS")));
@property (readonly) LSDKKtor_httpURLProtocol *WS __attribute__((swift_name("WS")));
@property (readonly) LSDKKtor_httpURLProtocol *WSS __attribute__((swift_name("WSS")));
@property (readonly) NSDictionary<NSString *, LSDKKtor_httpURLProtocol *> *byName __attribute__((swift_name("byName")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Create an instance by [name] or use already existing instance
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.createOrDefault)
 */
- (LSDKKtor_httpURLProtocol *)createOrDefaultName:(NSString *)name __attribute__((swift_name("createOrDefault(name:)")));

/**
 * HTTP with port 80
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.HTTP)
 */

/**
 * secure HTTPS with port 443
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.HTTPS)
 */

/**
 * Socks proxy url protocol.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.SOCKS)
 */

/**
 * Web socket over HTTP on port 80
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.WS)
 */

/**
 * Web socket over secure HTTPS on port 443
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.WSS)
 */

/**
 * Protocols by names map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.byName)
 */
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder.Companion")))
@interface LSDKKtor_httpURLBuilderCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_httpURLBuilderCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end

__attribute__((swift_name("Ktor_httpParametersBuilder")))
@protocol LSDKKtor_httpParametersBuilder <LSDKKtor_utilsStringValuesBuilder>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay.Companion")))
@interface LSDKKtor_utilsWeekDayCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_utilsWeekDayCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Lookup an instance by [ordinal]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay.Companion.from)
 */
- (LSDKKtor_utilsWeekDay *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));

/**
 * Lookup an instance by short week day name [WeekDay.value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay.Companion.from)
 */
- (LSDKKtor_utilsWeekDay *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth.Companion")))
@interface LSDKKtor_utilsMonthCompanion : LSDKBase
@property (class, readonly, getter=shared) LSDKKtor_utilsMonthCompanion *shared __attribute__((swift_name("shared")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));

/**
 * Lookup an instance by [ordinal]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month.Companion.from)
 */
- (LSDKKtor_utilsMonth *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));

/**
 * Lookup an instance by short month name [Month.value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month.Companion.from)
 */
- (LSDKKtor_utilsMonth *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
