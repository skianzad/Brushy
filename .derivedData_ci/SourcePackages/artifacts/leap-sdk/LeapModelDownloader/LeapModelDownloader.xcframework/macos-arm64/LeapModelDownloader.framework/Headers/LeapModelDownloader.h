#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class LMDArtifactVersion, LMDAudioGenerationModelDescriptor, LMDBundleConfig, LMDBundleConfigCompanion, LMDByteArrayBase64Serializer, LMDCacheControl, LMDCacheControlPolicy, LMDChatMessage, LMDChatMessageCompanion, LMDChatMessageContent, LMDChatMessageContentAudio, LMDChatMessageContentAudioCompanion, LMDChatMessageContentAudioInputAudio, LMDChatMessageContentAudioInputAudioCompanion, LMDChatMessageContentAudioPcmF32, LMDChatMessageContentAudioPcmF32Companion, LMDChatMessageContentAudioSerializer, LMDChatMessageContentCompanion, LMDChatMessageContentImage, LMDChatMessageContentImageCompanion, LMDChatMessageContentImageImageUrl, LMDChatMessageContentImageImageUrlCompanion, LMDChatMessageContentImageSerializer, LMDChatMessageContentText, LMDChatMessageContentTextCompanion, LMDChatMessageJsonSerializer, LMDChatMessageRole, LMDChatMessageRoleCompanion, LMDConstraints, LMDConstraintsCompanion, LMDCpuThreadAdvisor, LMDDownloadProgress, LMDDownloadedModelManifest, LMDEngine, LMDEngineCompanion, LMDEngineOptions, LMDEngineOptionsCacheOptions, LMDFunctionArgCompanion, LMDFunctionArgSerializer, LMDGeneratableFactory, LMDGenerateOptions, LMDGenerationFinishReason, LMDGenerationOptions, LMDGenerationOptionsCompanion, LMDGenerationOptionsCompat, LMDGenerationOptionsCompatCompanion, LMDGenerationStats, LMDGenerationStopReason, LMDGenerationStopReasonCompanion, LMDGenerationTimeParameters, LMDGenerationTimeParametersCompanion, LMDImageToTextLoadParams, LMDImageToTextLoadParamsCompanion, LMDInferenceEngineExceptions, LMDJSONSchemaGenerator, LMDJsonElementMapSerializer, LMDKotlinAbstractCoroutineContextElement, LMDKotlinAbstractCoroutineContextKey<B, E>, LMDKotlinArray<T>, LMDKotlinByteArray, LMDKotlinByteIterator, LMDKotlinCancellationException, LMDKotlinCharArray, LMDKotlinCharIterator, LMDKotlinEnum<E>, LMDKotlinEnumCompanion, LMDKotlinException, LMDKotlinFloatArray, LMDKotlinFloatIterator, LMDKotlinIllegalStateException, LMDKotlinKTypeProjection, LMDKotlinKTypeProjectionCompanion, LMDKotlinKVariance, LMDKotlinNothing, LMDKotlinRuntimeException, LMDKotlinStringBuilder, LMDKotlinThrowable, LMDKotlinUnit, LMDKotlinx_coroutines_coreCoroutineDispatcher, LMDKotlinx_coroutines_coreCoroutineDispatcherKey, LMDKotlinx_io_bytestringByteString, LMDKotlinx_io_bytestringByteStringCompanion, LMDKotlinx_io_coreBuffer, LMDKotlinx_io_coreFileMetadata, LMDKotlinx_io_corePath, LMDKotlinx_serialization_coreSerialKind, LMDKotlinx_serialization_coreSerializersModule, LMDKotlinx_serialization_jsonClassDiscriminatorMode, LMDKotlinx_serialization_jsonJson, LMDKotlinx_serialization_jsonJsonConfiguration, LMDKotlinx_serialization_jsonJsonDefault, LMDKotlinx_serialization_jsonJsonElement, LMDKotlinx_serialization_jsonJsonElementCompanion, LMDKtor_client_coreHttpClient, LMDKtor_client_coreHttpClientCall, LMDKtor_client_coreHttpClientCallCompanion, LMDKtor_client_coreHttpClientConfig<T>, LMDKtor_client_coreHttpClientEngineConfig, LMDKtor_client_coreHttpReceivePipeline, LMDKtor_client_coreHttpReceivePipelinePhases, LMDKtor_client_coreHttpRequestBuilder, LMDKtor_client_coreHttpRequestBuilderCompanion, LMDKtor_client_coreHttpRequestData, LMDKtor_client_coreHttpRequestPipeline, LMDKtor_client_coreHttpRequestPipelinePhases, LMDKtor_client_coreHttpResponse, LMDKtor_client_coreHttpResponseContainer, LMDKtor_client_coreHttpResponseData, LMDKtor_client_coreHttpResponsePipeline, LMDKtor_client_coreHttpResponsePipelinePhases, LMDKtor_client_coreHttpSendPipeline, LMDKtor_client_coreHttpSendPipelinePhases, LMDKtor_client_coreProxyConfig, LMDKtor_eventsEventDefinition<T>, LMDKtor_eventsEvents, LMDKtor_httpContentType, LMDKtor_httpContentTypeCompanion, LMDKtor_httpHeaderValueParam, LMDKtor_httpHeaderValueWithParameters, LMDKtor_httpHeaderValueWithParametersCompanion, LMDKtor_httpHeadersBuilder, LMDKtor_httpHttpMethod, LMDKtor_httpHttpMethodCompanion, LMDKtor_httpHttpProtocolVersion, LMDKtor_httpHttpProtocolVersionCompanion, LMDKtor_httpHttpStatusCode, LMDKtor_httpHttpStatusCodeCompanion, LMDKtor_httpOutgoingContent, LMDKtor_httpURLBuilder, LMDKtor_httpURLBuilderCompanion, LMDKtor_httpURLProtocol, LMDKtor_httpURLProtocolCompanion, LMDKtor_httpUrl, LMDKtor_httpUrlCompanion, LMDKtor_utilsAttributeKey<T>, LMDKtor_utilsGMTDate, LMDKtor_utilsGMTDateCompanion, LMDKtor_utilsMonth, LMDKtor_utilsMonthCompanion, LMDKtor_utilsPipeline<TSubject, TContext>, LMDKtor_utilsPipelinePhase, LMDKtor_utilsStringValuesBuilderImpl, LMDKtor_utilsTypeInfo, LMDKtor_utilsWeekDay, LMDKtor_utilsWeekDayCompanion, LMDLeap, LMDLeapApiModel, LMDLeapApiModelCompanion, LMDLeapArr, LMDLeapArrCompanion, LMDLeapBool, LMDLeapBoolCompanion, LMDLeapClient, LMDLeapDownloaderCompanion, LMDLeapDownloaderConfig, LMDLeapDownloaderResolvedManifest, LMDLeapDownloaderResolvedResource, LMDLeapDownloaderSavedFileInfo, LMDLeapException, LMDLeapFunction, LMDLeapFunctionCall, LMDLeapFunctionCallCompanion, LMDLeapFunctionCallParser, LMDLeapFunctionCallSerializer, LMDLeapFunctionDto, LMDLeapFunctionDtoCompanion, LMDLeapFunctionParameter, LMDLeapFunctionParameterDto, LMDLeapFunctionParameterDtoCompanion, LMDLeapFunctionParameterType, LMDLeapFunctionParameterTypeDto, LMDLeapFunctionParameterTypeDtoArr, LMDLeapFunctionParameterTypeDtoArrCompanion, LMDLeapFunctionParameterTypeDtoBool, LMDLeapFunctionParameterTypeDtoBoolCompanion, LMDLeapFunctionParameterTypeDtoCompanion, LMDLeapFunctionParameterTypeDtoIntType, LMDLeapFunctionParameterTypeDtoIntTypeCompanion, LMDLeapFunctionParameterTypeDtoNullType, LMDLeapFunctionParameterTypeDtoNullTypeCompanion, LMDLeapFunctionParameterTypeDtoNum, LMDLeapFunctionParameterTypeDtoNumCompanion, LMDLeapFunctionParameterTypeDtoObj, LMDLeapFunctionParameterTypeDtoObjCompanion, LMDLeapFunctionParameterTypeDtoStr, LMDLeapFunctionParameterTypeDtoStrCompanion, LMDLeapGenerationException, LMDLeapInferenceEngine, LMDLeapManifestProcessorConfig, LMDLeapModelManifestResponse, LMDLeapModelManifestResponseCompanion, LMDLeapModelsResponse, LMDLeapModelsResponseCompanion, LMDLeapNull, LMDLeapNum, LMDLeapNumCompanion, LMDLeapNumDoubleNum, LMDLeapNumDoubleNumCompanion, LMDLeapNumIntNum, LMDLeapNumIntNumCompanion, LMDLeapNumLongNum, LMDLeapNumLongNumCompanion, LMDLeapObj, LMDLeapObjCompanion, LMDLeapSDKVersion, LMDLeapStr, LMDLeapStrCompanion, LMDLfm2AudioV1LoadParams, LMDLfm2AudioV1LoadParamsCompanion, LMDLiquidCacheOptions, LMDLiquidConversation, LMDLiquidEngine, LMDLiquidEngineCompanion, LMDLiquidEngineRunner, LMDLiquidInferenceEngineManifestOptions, LMDLiquidInferenceEngineOptions, LMDLiquidInferenceEngineRunner, LMDLiquidInferenceEngineRunnerCompanion, LMDLiquidMessageResponse, LMDLiquidMessageResponseAudioSample, LMDLiquidMessageResponseChunk, LMDLiquidMessageResponseComplete, LMDLiquidMessageResponseFunctionCall, LMDLiquidMessageResponseReasoningChunk, LMDLoadTimeParametersCompanion, LMDManifest, LMDManifestCompanion, LMDMessage, LMDMessageContent, LMDMessageResponseAudioSample, LMDMessageResponseChunk, LMDMessageResponseComplete, LMDMessageResponseFunctionCalls, LMDMessageResponseReasoningChunk, LMDModelDownloadStatusDownloadInProgress, LMDModelDownloadStatusDownloaded, LMDModelDownloadStatusNotOnLocal, LMDModelLoadingOptions, LMDModelLoadingOptionsCompanion, LMDModelSource, LMDNativeDownloadError, LMDProgressData, LMDPythonicDumper, LMDPythonicToken, LMDPythonicTokenName, LMDSamplerParams, LMDSamplingParameters, LMDSamplingParametersCompanion, LMDSchemaSerializer, LMDTextToTextLoadParams, LMDTextToTextLoadParamsCompanion, LMDTokenProcessorCompanion, NSData, NSURL, NSURLSessionConfiguration;

@protocol LMDConversation, LMDFunctionArg, LMDGenerateOptionsTokenCallback, LMDKotlinAnnotation, LMDKotlinAppendable, LMDKotlinAutoCloseable, LMDKotlinCharSequence, LMDKotlinComparable, LMDKotlinContinuation, LMDKotlinContinuationInterceptor, LMDKotlinCoroutineContext, LMDKotlinCoroutineContextElement, LMDKotlinCoroutineContextKey, LMDKotlinFunction, LMDKotlinIterable, LMDKotlinIterator, LMDKotlinKAnnotatedElement, LMDKotlinKClass, LMDKotlinKClassifier, LMDKotlinKDeclarationContainer, LMDKotlinKType, LMDKotlinMapEntry, LMDKotlinSequence, LMDKotlinSuspendFunction2, LMDKotlinx_coroutines_coreChildHandle, LMDKotlinx_coroutines_coreChildJob, LMDKotlinx_coroutines_coreCoroutineScope, LMDKotlinx_coroutines_coreDisposableHandle, LMDKotlinx_coroutines_coreFlow, LMDKotlinx_coroutines_coreFlowCollector, LMDKotlinx_coroutines_coreJob, LMDKotlinx_coroutines_coreMutex, LMDKotlinx_coroutines_coreParentJob, LMDKotlinx_coroutines_coreRunnable, LMDKotlinx_coroutines_coreSelectClause, LMDKotlinx_coroutines_coreSelectClause0, LMDKotlinx_coroutines_coreSelectClause2, LMDKotlinx_coroutines_coreSelectInstance, LMDKotlinx_io_coreFileSystem, LMDKotlinx_io_coreRawSink, LMDKotlinx_io_coreRawSource, LMDKotlinx_io_coreSink, LMDKotlinx_io_coreSource, LMDKotlinx_serialization_coreCompositeDecoder, LMDKotlinx_serialization_coreCompositeEncoder, LMDKotlinx_serialization_coreDecoder, LMDKotlinx_serialization_coreDeserializationStrategy, LMDKotlinx_serialization_coreEncoder, LMDKotlinx_serialization_coreKSerializer, LMDKotlinx_serialization_coreSerialDescriptor, LMDKotlinx_serialization_coreSerialFormat, LMDKotlinx_serialization_coreSerializationStrategy, LMDKotlinx_serialization_coreSerializersModuleCollector, LMDKotlinx_serialization_coreStringFormat, LMDKotlinx_serialization_jsonJsonNamingStrategy, LMDKtor_client_coreHttpClientEngine, LMDKtor_client_coreHttpClientEngineCapability, LMDKtor_client_coreHttpClientPlugin, LMDKtor_client_coreHttpRequest, LMDKtor_httpHeaders, LMDKtor_httpHttpMessage, LMDKtor_httpHttpMessageBuilder, LMDKtor_httpParameters, LMDKtor_httpParametersBuilder, LMDKtor_ioByteReadChannel, LMDKtor_ioCloseable, LMDKtor_ioJvmSerializable, LMDKtor_utilsAttributes, LMDKtor_utilsStringValues, LMDKtor_utilsStringValuesBuilder, LMDLoadTimeParameters, LMDMessageResponse, LMDModelDownloadStatus, LMDModelRunner, LMDModelRunnerGenerationCallback, LMDModelRunnerGenerationHandler;

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
@interface LMDBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface LMDBase (LMDBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface LMDMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface LMDMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorLMDKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface LMDNumber : NSNumber
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
@interface LMDByte : LMDNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface LMDUByte : LMDNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface LMDShort : LMDNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface LMDUShort : LMDNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface LMDInt : LMDNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface LMDUInt : LMDNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface LMDLong : LMDNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface LMDULong : LMDNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface LMDFloat : LMDNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface LMDDouble : LMDNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface LMDBoolean : LMDNumber
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
@interface LMDAudioGenerationModelDescriptor : LMDBase
- (instancetype)initWithModelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath audioDecoderPath:(NSString *)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath __attribute__((swift_name("init(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:)"))) __attribute__((objc_designated_initializer));
- (LMDAudioGenerationModelDescriptor *)doCopyModelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath audioDecoderPath:(NSString *)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath __attribute__((swift_name("doCopy(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:)")));

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
@property (readonly) NSString *audioDecoderPath __attribute__((swift_name("audioDecoderPath")));
@property (readonly) NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSString *mmprojPath __attribute__((swift_name("mmprojPath")));
@property (readonly) NSString *modelPath __attribute__((swift_name("modelPath")));
@end


/** A data instance to hold the conversation context. */
__attribute__((swift_name("Conversation")))
@protocol LMDConversation
@required

/**
 * Append a message to the history without triggering any generation.
 *
 * @param message the message to append
 */
- (void)appendToHistoryMessage:(LMDChatMessage *)message __attribute__((swift_name("appendToHistory(message:)")));

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
- (id<LMDKotlinx_coroutines_coreFlow>)generateResponseMessage:(LMDChatMessage *)message generationOptions:(LMDGenerationOptions * _Nullable)generationOptions __attribute__((swift_name("generateResponse(message:generationOptions:)")));

/**
 * Generate response with text input from the user.
 *
 * See [generateResponse] for full usage and stop semantics.
 *
 * @param userTextMessage the user's text input
 */
- (id<LMDKotlinx_coroutines_coreFlow>)generateResponseUserTextMessage:(NSString *)userTextMessage generationOptions:(LMDGenerationOptions * _Nullable)generationOptions __attribute__((swift_name("generateResponse(userTextMessage:generationOptions:)")));

/** Register a function into the conversation. */
- (void)registerFunctionFunction:(LMDLeapFunction *)function __attribute__((swift_name("registerFunction(function:)")));

/** Register a list of functions into the conversation. */
- (void)registerFunctionsFunctions:(NSArray<LMDLeapFunction *> *)functions __attribute__((swift_name("registerFunctions(functions:)")));

/**
 * Remove the last message from the history. No-ops if the history is empty.
 *
 * Used internally to clean up a dangling user message when generation is cancelled before the
 * assistant produces a [MessageResponse.Complete].
 */
- (void)removeLastMessage __attribute__((swift_name("removeLastMessage()")));

/** The registered functions for this conversation. */
@property (readonly) NSArray<LMDLeapFunction *> *functions __attribute__((swift_name("functions")));
@property (readonly) id<LMDKotlinx_coroutines_coreMutex> generatingLock __attribute__((swift_name("generatingLock")));

/** The conversation history. */
@property (readonly) NSArray<LMDChatMessage *> *history __attribute__((swift_name("history")));

/** Whether a generation is in progress */
@property (readonly) BOOL isGenerating __attribute__((swift_name("isGenerating")));
@property (readonly) id<LMDModelRunner> modelRunner __attribute__((swift_name("modelRunner")));
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
@interface LMDCpuThreadAdvisor : LMDBase
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
@property (class, readonly, getter=shared) LMDCpuThreadAdvisor *shared __attribute__((swift_name("shared")));

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
@interface LMDGenerationOptions : LMDBase
- (instancetype)initWithTemperature:(LMDFloat * _Nullable)temperature topP:(LMDFloat * _Nullable)topP minP:(LMDFloat * _Nullable)minP repetitionPenalty:(LMDFloat * _Nullable)repetitionPenalty topK:(LMDInt * _Nullable)topK rngSeed:(LMDLong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LMDLeapFunctionCallParser * _Nullable)functionCallParser injectSchemaIntoPrompt:(BOOL)injectSchemaIntoPrompt maxTokens:(LMDInt * _Nullable)maxTokens inlineThinkingTags:(BOOL)inlineThinkingTags enableThinking:(BOOL)enableThinking extras:(NSString * _Nullable)extras __attribute__((swift_name("init(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:injectSchemaIntoPrompt:maxTokens:inlineThinkingTags:enableThinking:extras:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDGenerationOptionsCompanion *companion __attribute__((swift_name("companion")));
- (LMDGenerationOptions *)doCopyTemperature:(LMDFloat * _Nullable)temperature topP:(LMDFloat * _Nullable)topP minP:(LMDFloat * _Nullable)minP repetitionPenalty:(LMDFloat * _Nullable)repetitionPenalty topK:(LMDInt * _Nullable)topK rngSeed:(LMDLong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LMDLeapFunctionCallParser * _Nullable)functionCallParser injectSchemaIntoPrompt:(BOOL)injectSchemaIntoPrompt maxTokens:(LMDInt * _Nullable)maxTokens inlineThinkingTags:(BOOL)inlineThinkingTags enableThinking:(BOOL)enableThinking extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:injectSchemaIntoPrompt:maxTokens:inlineThinkingTags:enableThinking:extras:)")));

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
@property BOOL enableThinking __attribute__((swift_name("enableThinking")));

/** Extra configuration. Internal use only. */
@property NSString * _Nullable extras __attribute__((swift_name("extras")));
@property LMDLeapFunctionCallParser * _Nullable functionCallParser __attribute__((swift_name("functionCallParser")));

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
@property BOOL injectSchemaIntoPrompt __attribute__((swift_name("injectSchemaIntoPrompt")));

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
@property BOOL inlineThinkingTags __attribute__((swift_name("inlineThinkingTags")));

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
@property NSString * _Nullable jsonSchemaConstraint __attribute__((swift_name("jsonSchemaConstraint")));

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
@property LMDInt * _Nullable maxTokens __attribute__((swift_name("maxTokens")));

/** Minimal possibility for a token to be considered in generation. */
@property LMDFloat * _Nullable minP __attribute__((swift_name("minP")));

/**
 * Repetition penalty parameter.
 *
 * A positive value will decrease the model's likelihood to repeat the same line verbatim.
 */
@property LMDFloat * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));

/**
 * Random number generator seed for reproducible generation.
 *
 * When set, the model will produce deterministic output for the same input and seed value. Useful
 * for testing and debugging. If null, a random seed is used.
 */
@property LMDLong * _Nullable rngSeed __attribute__((swift_name("rngSeed")));

/**
 * Sampling temperature parameter.
 *
 * Higher values will make the output more random, while lower values will make it more focused
 * and deterministic.
 */
@property LMDFloat * _Nullable temperature __attribute__((swift_name("temperature")));

/**
 * Top-K sampling parameter.
 *
 * Only consider the K most likely next tokens during sampling. Lower values make output more
 * focused by restricting the candidate pool, while higher values allow more diversity. A value of
 * 0 or null disables top-K filtering.
 */
@property LMDInt * _Nullable topK __attribute__((swift_name("topK")));

/**
 * Nucleus sampling parameter.
 *
 * In nucleus sampling, the model only considers the results of the tokens with top_p probability
 * mass.
 */
@property LMDFloat * _Nullable topP __attribute__((swift_name("topP")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationOptions.Companion")))
@interface LMDGenerationOptionsCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDGenerationOptionsCompanion *shared __attribute__((swift_name("shared")));

/** Create a [GenerationOptions] object with build actions. */
- (LMDGenerationOptions *)buildBuildAction:(void (^)(LMDGenerationOptions *))buildAction __attribute__((swift_name("build(buildAction:)")));
@end


/** Main entrypoint of LeapSDK */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapClient")))
@interface LMDLeapClient : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** Main entrypoint of LeapSDK */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapClient __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapClient *shared __attribute__((swift_name("shared")));

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
- (void)loadModelModel:(LMDAudioGenerationModelDescriptor *)model options:(LMDModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(model:options:completionHandler:)")));

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
- (void)loadModelModelPath:(NSString *)modelPath options:(LMDModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelPath:options:completionHandler:)")));

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
- (void)loadModelParams:(id<LMDLoadTimeParameters>)params generationParams:(LMDGenerationTimeParameters * _Nullable)generationParams options:(LMDModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(params:generationParams:options:completionHandler:)")));

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
- (void)loadModelModelPath:(NSString *)modelPath mmprojPath:(NSString *)mmprojPath options:(LMDModelLoadingOptions * _Nullable)options completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelPath:mmprojPath:options:completionHandler:)")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface LMDKotlinThrowable : LMDBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (LMDKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) LMDKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface LMDKotlinException : LMDKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Base class of all exceptions thrown from Leap SDK. */
__attribute__((swift_name("LeapException")))
@interface LMDLeapException : LMDKotlinException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/** Error in generating contents. */
__attribute__((swift_name("LeapGenerationException")))
@interface LMDLeapGenerationException : LMDLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** The specific error that the generated function call request cannot be correctly parsed. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGenerationFunctionCallParsingException")))
@interface LMDLeapGenerationFunctionCallParsingException : LMDLeapGenerationException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** The specific error that the input prompt exceeds the context length. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGenerationPromptExceedContextLengthException")))
@interface LMDLeapGenerationPromptExceedContextLengthException : LMDLeapGenerationException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Native platform implementation of LeapInferenceEngine for iOS, macOS, and Linux.
 *
 * Uses cinterop to bridge to the native C inference engine.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapInferenceEngine")))
@interface LMDLeapInferenceEngine : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Native platform implementation of LeapInferenceEngine for iOS, macOS, and Linux.
 *
 * Uses cinterop to bridge to the native C inference engine.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapInferenceEngine __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapInferenceEngine *shared __attribute__((swift_name("shared")));

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
- (void)loadModelModelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath options:(LMDModelLoadingOptions * _Nullable)options generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:options:generationTimeParameters:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelDownloadSha256MismatchException")))
@interface LMDLeapModelDownloadSha256MismatchException : LMDLeapException
- (instancetype)initWithExpectedSha256:(NSString *)expectedSha256 actualSha256:(NSString *)actualSha256 __attribute__((swift_name("init(expectedSha256:actualSha256:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelDownloadSizeMismatchException")))
@interface LMDLeapModelDownloadSizeMismatchException : LMDLeapException
- (instancetype)initWithExpectedSize:(int64_t)expectedSize actualSize:(int64_t)actualSize __attribute__((swift_name("init(expectedSize:actualSize:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * Failure in loading the model. It could be caused by a permission issue, file format issue, or
 * other underlying issues in the engine.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelLoadingException")))
@interface LMDLeapModelLoadingException : LMDLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Error in serialization or deserialization. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapSerializationException")))
@interface LMDLeapSerializationException : LMDLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Options to configure when loading a model. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelLoadingOptions")))
@interface LMDModelLoadingOptions : LMDBase
- (instancetype)initWithRandomSeed:(LMDLong * _Nullable)randomSeed cpuThreads:(int32_t)cpuThreads chatTemplate:(NSString * _Nullable)chatTemplate cacheOptions:(LMDEngineOptionsCacheOptions * _Nullable)cacheOptions contextSize:(LMDInt * _Nullable)contextSize extras:(NSString * _Nullable)extras __attribute__((swift_name("init(randomSeed:cpuThreads:chatTemplate:cacheOptions:contextSize:extras:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDModelLoadingOptionsCompanion *companion __attribute__((swift_name("companion")));
- (LMDModelLoadingOptions *)doCopyRandomSeed:(LMDLong * _Nullable)randomSeed cpuThreads:(int32_t)cpuThreads chatTemplate:(NSString * _Nullable)chatTemplate cacheOptions:(LMDEngineOptionsCacheOptions * _Nullable)cacheOptions contextSize:(LMDInt * _Nullable)contextSize extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(randomSeed:cpuThreads:chatTemplate:cacheOptions:contextSize:extras:)")));

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
@property LMDEngineOptionsCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));

/** Template to use for a chat experience */
@property NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/**
 * Maximum context size in tokens. Controls KV cache memory allocation for attention layers.
 * Larger values allow longer conversations but use more memory. Default: 8192 tokens (~96MB KV
 * cache for a typical model).
 */
@property LMDInt * _Nullable contextSize __attribute__((swift_name("contextSize")));

/** How many cpu threads to use in the generation. */
@property int32_t cpuThreads __attribute__((swift_name("cpuThreads")));

/** Extra configuration. Internal use only. */
@property NSString * _Nullable extras __attribute__((swift_name("extras")));

/**
 * The random seed for token sampling. Same random seed will result in the same outcome in the
 * generation.
 */
@property LMDLong * _Nullable randomSeed __attribute__((swift_name("randomSeed")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelLoadingOptions.Companion")))
@interface LMDModelLoadingOptionsCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDModelLoadingOptionsCompanion *shared __attribute__((swift_name("shared")));

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
- (LMDEngineOptionsCacheOptions *)cacheOptionsPath:(NSString *)path maxEntriesDisk:(int32_t)maxEntriesDisk __attribute__((swift_name("cacheOptions(path:maxEntriesDisk:)")));

/**
 * Disk cap used by the [cacheOptions] convenience helper. Mirrors the historical SDK default
 * (the pre-bounded-LRU `cacheDir = path` shape used 40 entries). This is *not* the engine's own
 * default — that's [ai.liquid.leap.inferenceengine.CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK]
 * (4096), which kicks in when `enabled = true` is set without naming a cap.
 */
@property (readonly) int32_t LEGACY_CACHE_MAX_ENTRIES_DISK __attribute__((swift_name("LEGACY_CACHE_MAX_ENTRIES_DISK")));
@end


/**
 * A running model. Any model runner implementations need to expose certain methods to allow LEAP
 * SDK to control the model.
 */
__attribute__((swift_name("ModelRunner")))
@protocol LMDModelRunner
@required

/**
 * Create a conversation object from this model runner.
 *
 * @param systemPrompt customized system prompt. A default system prompt from the model bundle
 *   will be used if it is null.
 */
- (id<LMDConversation>)createConversationSystemPrompt:(NSString * _Nullable)systemPrompt __attribute__((swift_name("createConversation(systemPrompt:)")));

/**
 * Create a conversation from chat message history.
 *
 * @param history chat history (messages) to invoke the generation
 */
- (id<LMDConversation>)createConversationFromHistoryHistory:(NSArray<LMDChatMessage *> *)history __attribute__((swift_name("createConversationFromHistory(history:)")));

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
- (void)generateFromConversationConversation:(id<LMDConversation>)conversation callback:(id<LMDModelRunnerGenerationCallback>)callback generationOptions:(LMDGenerationOptions * _Nullable)generationOptions completionHandler:(void (^)(id<LMDModelRunnerGenerationHandler> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("generateFromConversation(conversation:callback:generationOptions:completionHandler:)")));

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
- (void)getPromptTokensSizeMessages:(NSArray<LMDChatMessage *> *)messages addBosToken:(BOOL)addBosToken completionHandler:(void (^)(LMDInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPromptTokensSize(messages:addBosToken:completionHandler:)")));

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
@protocol LMDModelRunnerGenerationCallback
@required

/**
 * Callback to invoke when an exception or an error is thrown during the generation
 *
 * @param error the error throwable object
 */
- (void)onErrorError:(LMDKotlinThrowable *)error __attribute__((swift_name("onError(error:)")));

/**
 * Callback to invoke when a piece of response is available
 *
 * @param response the generated response from the model
 */
- (void)onResponseResponse:(id<LMDMessageResponse>)response __attribute__((swift_name("onResponse(response:)")));
@end


/**
 * Handler returned by [generateFromConversation] to control an in-progress generation.
 *
 * Consumers should not use this interface directly. Use [Conversation.generateResponse] instead;
 * cancelling the returned [kotlinx.coroutines.flow.Flow]'s collector automatically calls [stop]
 * via the flow's `awaitClose` block.
 */
__attribute__((swift_name("ModelRunnerGenerationHandler")))
@protocol LMDModelRunnerGenerationHandler
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
@interface LMDFloatAudioBuffer : LMDBase
- (instancetype)initWithSampleRate:(int32_t)sampleRate channelCount:(int32_t)channelCount __attribute__((swift_name("init(sampleRate:channelCount:)"))) __attribute__((objc_designated_initializer));

/**
 * Add samples to the buffer.
 *
 * @param chunk Array of float samples to append (must be aligned to channel count)
 * @throws IllegalArgumentException if chunk size is not divisible by channel count or buffer
 *   would exceed maximum size
 */
- (void)addChunk:(LMDKotlinFloatArray *)chunk __attribute__((swift_name("add(chunk:)")));

/**
 * Append samples to the buffer. Alias for [add] that matches iOS SDK naming.
 *
 * @param samples Array of float samples to append
 */
- (void)appendSamples:(LMDKotlinFloatArray *)samples __attribute__((swift_name("append(samples:)")));

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
- (LMDKotlinByteArray *)createWavBytes __attribute__((swift_name("createWavBytes()")));

/**
 * Create a [ChatMessageContent.Audio] from the buffer's samples.
 *
 * This converts the floating-point samples to WAV format (32-bit float PCM) and wraps them in a
 * ChatMessageContent suitable for use in conversations.
 *
 * @return ChatMessageContent.Audio containing WAV-encoded data
 */
- (LMDChatMessageContentAudio *)makeAudioContent __attribute__((swift_name("makeAudioContent()")));

/**
 * Create a [ChatMessageContent.AudioPcmF32] from the buffer's raw samples.
 *
 * This preserves the raw float32 samples without WAV encoding, suitable for roundtripping
 * engine-generated audio through conversation history without hash loss.
 *
 * @return ChatMessageContent.AudioPcmF32 containing raw PCM samples and sample rate
 */
- (LMDChatMessageContentAudioPcmF32 *)makePcmF32AudioContent __attribute__((swift_name("makePcmF32AudioContent()")));

/**
 * Concatenate all chunks into a single [FloatArray].
 *
 * @return A new FloatArray containing all samples in order
 */
- (LMDKotlinFloatArray *)toFloatArray __attribute__((swift_name("toFloatArray()")));
@property (readonly) int32_t channelCount __attribute__((swift_name("channelCount")));

/** Returns the total number of samples in the buffer (across all channels) */
@property (readonly) int32_t count __attribute__((swift_name("count")));

/**
 * Returns the duration of the audio in seconds.
 *
 * The duration is calculated as: (number of frames) / sample rate, where the number of frames is
 * (total samples) / channel count.
 *
 * Note: Uses floating-point arithmetic which may have minor precision issues for very long audio
 * (multiple hours).
 */
@property (readonly) double duration __attribute__((swift_name("duration")));

/** Returns true if the buffer contains no samples */
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@end


/**
 * Cache control configuration.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl`.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheControl")))
@interface LMDCacheControl : LMDBase
- (instancetype)initWithPolicy:(LMDCacheControlPolicy *)policy point:(NSString * _Nullable)point __attribute__((swift_name("init(policy:point:)"))) __attribute__((objc_designated_initializer));
- (LMDCacheControl *)doCopyPolicy:(LMDCacheControlPolicy *)policy point:(NSString * _Nullable)point __attribute__((swift_name("doCopy(policy:point:)")));

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
@property (readonly) NSString * _Nullable point __attribute__((swift_name("point")));
@property (readonly) LMDCacheControlPolicy *policy __attribute__((swift_name("policy")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol LMDKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface LMDKotlinEnum<E> : LMDBase <LMDKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end


/**
 * Cache control policy for generation caching behavior.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl.Policy`.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheControlPolicy")))
@interface LMDCacheControlPolicy : LMDKotlinEnum<LMDCacheControlPolicy *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Cache control policy for generation caching behavior.
 *
 * Compatibility with iOS SDK's `GenerationOptions.CacheControl.Policy`.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) LMDCacheControlPolicy *cache __attribute__((swift_name("cache")));
@property (class, readonly) LMDCacheControlPolicy *nocache __attribute__((swift_name("nocache")));
+ (LMDKotlinArray<LMDCacheControlPolicy *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDCacheControlPolicy *> *entries __attribute__((swift_name("entries")));
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
@interface LMDGenerationOptionsCompat : LMDBase
- (instancetype)initWithTemperature:(LMDFloat * _Nullable)temperature topP:(LMDFloat * _Nullable)topP minP:(LMDFloat * _Nullable)minP repetitionPenalty:(LMDFloat * _Nullable)repetitionPenalty topK:(LMDInt * _Nullable)topK rngSeed:(LMDULong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LMDLeapFunctionCallParser * _Nullable)functionCallParser sequenceLength:(LMDUInt * _Nullable)sequenceLength maxOutputTokens:(LMDUInt * _Nullable)maxOutputTokens enableThinking:(BOOL)enableThinking inlineThinkingTags:(BOOL)inlineThinkingTags cacheControl:(LMDCacheControl * _Nullable)cacheControl extras:(NSString * _Nullable)extras __attribute__((swift_name("init(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:sequenceLength:maxOutputTokens:enableThinking:inlineThinkingTags:cacheControl:extras:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDGenerationOptionsCompatCompanion *companion __attribute__((swift_name("companion")));
- (LMDGenerationOptionsCompat *)doCopyTemperature:(LMDFloat * _Nullable)temperature topP:(LMDFloat * _Nullable)topP minP:(LMDFloat * _Nullable)minP repetitionPenalty:(LMDFloat * _Nullable)repetitionPenalty topK:(LMDInt * _Nullable)topK rngSeed:(LMDULong * _Nullable)rngSeed jsonSchemaConstraint:(NSString * _Nullable)jsonSchemaConstraint functionCallParser:(LMDLeapFunctionCallParser * _Nullable)functionCallParser sequenceLength:(LMDUInt * _Nullable)sequenceLength maxOutputTokens:(LMDUInt * _Nullable)maxOutputTokens enableThinking:(BOOL)enableThinking inlineThinkingTags:(BOOL)inlineThinkingTags cacheControl:(LMDCacheControl * _Nullable)cacheControl extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(temperature:topP:minP:repetitionPenalty:topK:rngSeed:jsonSchemaConstraint:functionCallParser:sequenceLength:maxOutputTokens:enableThinking:inlineThinkingTags:cacheControl:extras:)")));

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
- (LMDGenerationOptions *)toKmpGenerationOptions __attribute__((swift_name("toKmpGenerationOptions()")));

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
@property LMDCacheControl * _Nullable cacheControl __attribute__((swift_name("cacheControl")));

/** When enabled, the engine surfaces reasoning tokens such as `<think>` blocks */
@property BOOL enableThinking __attribute__((swift_name("enableThinking")));

/** Additional engine-specific extensions encoded as a JSON string */
@property NSString * _Nullable extras __attribute__((swift_name("extras")));

/**
 * Function call parser. By default, LFM function call parser is used. Set to null to return
 * function calls as normal content.
 */
@property LMDLeapFunctionCallParser * _Nullable functionCallParser __attribute__((swift_name("functionCallParser")));

/**
 * When true, thinking content is emitted as regular text chunks with `<think></think>` tags
 * intact, rather than as separate reasoning chunks. Default is false.
 */
@property BOOL inlineThinkingTags __attribute__((swift_name("inlineThinkingTags")));

/** JSON schema constraint for structured output generation */
@property NSString * _Nullable jsonSchemaConstraint __attribute__((swift_name("jsonSchemaConstraint")));

/** Maximum number of tokens to generate for this request */
@property LMDUInt * _Nullable maxOutputTokens __attribute__((swift_name("maxOutputTokens")));

/** Minimal probability for a token to be considered in generation */
@property LMDFloat * _Nullable minP __attribute__((swift_name("minP")));

/** Repetition penalty parameter (positive value decreases repetition) */
@property LMDFloat * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));

/** Optional random seed for deterministic replay */
@property LMDULong * _Nullable rngSeed __attribute__((swift_name("rngSeed")));

/** Override for the context window length used by the engine */
@property LMDUInt * _Nullable sequenceLength __attribute__((swift_name("sequenceLength")));

/** Sampling temperature parameter (higher = more random, lower = more focused) */
@property LMDFloat * _Nullable temperature __attribute__((swift_name("temperature")));

/** Top-K sampling parameter — only consider the K most likely tokens (null for default) */
@property LMDInt * _Nullable topK __attribute__((swift_name("topK")));

/** Nucleus sampling parameter (top-p) */
@property LMDFloat * _Nullable topP __attribute__((swift_name("topP")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationOptionsCompat.Companion")))
@interface LMDGenerationOptionsCompatCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDGenerationOptionsCompatCompanion *shared __attribute__((swift_name("shared")));

/** Create a GenerationOptions with default values matching iOS SDK defaults. */
- (LMDGenerationOptionsCompat *)withDefaults __attribute__((swift_name("withDefaults()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Leap")))
@interface LMDLeap : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leap __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeap *shared __attribute__((swift_name("shared")));

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
- (void)loadManifestUrl:(NSURL *)manifestUrl options:(LMDLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LMDDouble *, LMDLong *))downloadProgressHandler completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(manifestUrl:options:downloadProgressHandler:completionHandler:)")));

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
- (void)loadModel:(NSString *)model quantization:(NSString *)quantization options:(LMDLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LMDDouble *, LMDLong *))downloadProgressHandler completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(model:quantization:options:downloadProgressHandler:completionHandler:)")));

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
- (void)loadUrl:(NSURL *)url options:(LMDLiquidInferenceEngineOptions * _Nullable)options generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(url:options:generationTimeParameters:autoDetectCompanionFiles:completionHandler:)")));

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
- (void)loadUrl:(NSURL *)url contextSize:(LMDUInt * _Nullable)contextSize cpuThreads:(LMDUInt * _Nullable)cpuThreads autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("load(url:contextSize:cpuThreads:autoDetectCompanionFiles:completionHandler:)")));
@end


/**
 * Leap SDK version information.
 *
 * This matches the iOS SDK's version API.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapSDKVersion")))
@interface LMDLeapSDKVersion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Leap SDK version information.
 *
 * This matches the iOS SDK's version API.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapSDKVersion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapSDKVersion *shared __attribute__((swift_name("shared")));

/** The current SDK version string */
@property (readonly) NSString *version __attribute__((swift_name("version")));
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
@interface LMDLiquidCacheOptions : LMDBase
- (instancetype)initWithPath:(NSString *)path maxEntries:(int32_t)maxEntries enabled:(BOOL)enabled maxEntriesDisk:(int32_t)maxEntriesDisk maxEntriesMemory:(int32_t)maxEntriesMemory maxBytesMemory:(int64_t)maxBytesMemory diskDisabled:(BOOL)diskDisabled __attribute__((swift_name("init(path:maxEntries:enabled:maxEntriesDisk:maxEntriesMemory:maxBytesMemory:diskDisabled:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidCacheOptions *)doCopyPath:(NSString *)path maxEntries:(int32_t)maxEntries enabled:(BOOL)enabled maxEntriesDisk:(int32_t)maxEntriesDisk maxEntriesMemory:(int32_t)maxEntriesMemory maxBytesMemory:(int64_t)maxBytesMemory diskDisabled:(BOOL)diskDisabled __attribute__((swift_name("doCopy(path:maxEntries:enabled:maxEntriesDisk:maxEntriesMemory:maxBytesMemory:diskDisabled:)")));

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
- (LMDEngineOptionsCacheOptions * _Nullable)toCacheOptions __attribute__((swift_name("toCacheOptions()")));

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
@property (readonly) BOOL diskDisabled __attribute__((swift_name("diskDisabled")));
@property (readonly) BOOL enabled __attribute__((swift_name("enabled")));
@property (readonly) int64_t maxBytesMemory __attribute__((swift_name("maxBytesMemory")));
@property (readonly) int32_t maxEntries __attribute__((swift_name("maxEntries")));
@property (readonly) int32_t maxEntriesDisk __attribute__((swift_name("maxEntriesDisk")));
@property (readonly) int32_t maxEntriesMemory __attribute__((swift_name("maxEntriesMemory")));
@property (readonly) NSString *path __attribute__((swift_name("path")));
@end


/**
 * LiquidConversation - Wrapper around Conversation with old API
 *
 * Provides generateResponse() method that returns a sealed class hierarchy designed to be
 * exhaustively switched over from Swift.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidConversation")))
@interface LMDLiquidConversation : LMDBase
- (instancetype)initWithConversation:(id<LMDConversation>)conversation __attribute__((swift_name("init(conversation:)"))) __attribute__((objc_designated_initializer));

/**
 * Generate a response for the given message
 *
 * Returns a Flow of LiquidMessageResponse instances from a sealed class hierarchy that is
 * intended to be convenient to handle with Swift switch / pattern matching.
 *
 * Matches: conversation.generateResponse(message:generationOptions:) from old iOS SDK
 */
- (id<LMDKotlinx_coroutines_coreFlow>)generateResponseMessage:(LMDChatMessage *)message generationOptions:(LMDGenerationOptionsCompat *)generationOptions __attribute__((swift_name("generateResponse(message:generationOptions:)")));
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
@interface LMDLiquidEngine : LMDBase
@property (class, readonly, getter=companion) LMDLiquidEngineCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSURL *modelURL __attribute__((swift_name("modelURL")));
@property (readonly) LMDLiquidEngineRunner *runner __attribute__((swift_name("runner")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidEngine.Companion")))
@interface LMDLiquidEngineCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLiquidEngineCompanion *shared __attribute__((swift_name("shared")));

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
- (void)invokeModelURL:(NSURL *)modelURL completionHandler:(void (^)(LMDLiquidEngine * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(modelURL:completionHandler:)")));

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
- (void)invokeModelURL:(NSURL *)modelURL model:(NSString *)model quantization:(NSString *)quantization completionHandler:(void (^)(LMDLiquidEngine * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(modelURL:model:quantization:completionHandler:)")));
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
@interface LMDLiquidEngineRunner : LMDBase
- (instancetype)initWithRunner:(LMDLiquidInferenceEngineRunner *)runner modelURL:(NSURL *)modelURL __attribute__((swift_name("init(runner:modelURL:)"))) __attribute__((objc_designated_initializer));

/**
 * Create a conversation from message history Matches:
 * runner.createConversationFromHistory(history:) from old iOS SDK
 */
- (LMDLiquidConversation *)createConversationFromHistoryHistory:(NSArray<LMDChatMessage *> *)history __attribute__((swift_name("createConversationFromHistory(history:)")));

/**
 * Get prompt tokens size for a list of messages Matches:
 * runner.getPromptTokensSize(messages:addBosToken:) from old iOS SDK
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPromptTokensSizeMessages:(NSArray<LMDChatMessage *> *)messages addBosToken:(BOOL)addBosToken completionHandler:(void (^)(LMDInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPromptTokensSize(messages:addBosToken:completionHandler:)")));

/** Unload the model from memory Matches: runner.unload() from old iOS SDK
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)unloadWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("unload(completionHandler:)")));
@property (readonly) NSURL *modelURL __attribute__((swift_name("modelURL")));
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
@interface LMDLiquidInferenceEngineManifestOptions : LMDBase
- (instancetype)initWithCacheOptions:(LMDLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LMDUInt * _Nullable)cpuThreads contextSize:(LMDUInt * _Nullable)contextSize nGpuLayers:(LMDUInt * _Nullable)nGpuLayers audioDecoderUseGpu:(BOOL)audioDecoderUseGpu chatTemplate:(NSString * _Nullable)chatTemplate extras:(NSString * _Nullable)extras __attribute__((swift_name("init(cacheOptions:cpuThreads:contextSize:nGpuLayers:audioDecoderUseGpu:chatTemplate:extras:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidInferenceEngineManifestOptions *)doCopyCacheOptions:(LMDLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LMDUInt * _Nullable)cpuThreads contextSize:(LMDUInt * _Nullable)contextSize nGpuLayers:(LMDUInt * _Nullable)nGpuLayers audioDecoderUseGpu:(BOOL)audioDecoderUseGpu chatTemplate:(NSString * _Nullable)chatTemplate extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(cacheOptions:cpuThreads:contextSize:nGpuLayers:audioDecoderUseGpu:chatTemplate:extras:)")));

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
- (LMDGenerationTimeParameters * _Nullable)toGenerationTimeParameters __attribute__((swift_name("toGenerationTimeParameters()")));

/**
 * Convert to KMP ModelLoadingOptions.
 *
 * @throws IllegalArgumentException if validation fails
 */
- (LMDModelLoadingOptions *)toModelLoadingOptions __attribute__((swift_name("toModelLoadingOptions()")));

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
@property (readonly) BOOL audioDecoderUseGpu __attribute__((swift_name("audioDecoderUseGpu")));

/** Optional cache configuration for inference engine */
@property (readonly) LMDLiquidCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));

/** Optional custom chat template override */
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/** Context window size (sequence length) */
@property (readonly) LMDUInt * _Nullable contextSize __attribute__((swift_name("contextSize")));

/** Number of CPU threads to use for inference */
@property (readonly) LMDUInt * _Nullable cpuThreads __attribute__((swift_name("cpuThreads")));

/** Additional engine-specific configuration as JSON string */
@property (readonly) NSString * _Nullable extras __attribute__((swift_name("extras")));

/** Number of GPU layers to offload (iOS/macOS typically uses Metal) */
@property (readonly) LMDUInt * _Nullable nGpuLayers __attribute__((swift_name("nGpuLayers")));
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
@interface LMDLiquidInferenceEngineOptions : LMDBase
- (instancetype)initWithBundlePath:(NSString *)bundlePath cacheOptions:(LMDLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LMDUInt * _Nullable)cpuThreads contextSize:(LMDUInt * _Nullable)contextSize nGpuLayers:(LMDUInt * _Nullable)nGpuLayers mmProjPath:(NSString * _Nullable)mmProjPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath chatTemplate:(NSString * _Nullable)chatTemplate audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath audioDecoderUseGpu:(BOOL)audioDecoderUseGpu extras:(NSString * _Nullable)extras __attribute__((swift_name("init(bundlePath:cacheOptions:cpuThreads:contextSize:nGpuLayers:mmProjPath:audioDecoderPath:chatTemplate:audioTokenizerPath:audioDecoderUseGpu:extras:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidInferenceEngineOptions *)doCopyBundlePath:(NSString *)bundlePath cacheOptions:(LMDLiquidCacheOptions * _Nullable)cacheOptions cpuThreads:(LMDUInt * _Nullable)cpuThreads contextSize:(LMDUInt * _Nullable)contextSize nGpuLayers:(LMDUInt * _Nullable)nGpuLayers mmProjPath:(NSString * _Nullable)mmProjPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath chatTemplate:(NSString * _Nullable)chatTemplate audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath audioDecoderUseGpu:(BOOL)audioDecoderUseGpu extras:(NSString * _Nullable)extras __attribute__((swift_name("doCopy(bundlePath:cacheOptions:cpuThreads:contextSize:nGpuLayers:mmProjPath:audioDecoderPath:chatTemplate:audioTokenizerPath:audioDecoderUseGpu:extras:)")));

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
- (LMDGenerationTimeParameters * _Nullable)toGenerationTimeParameters __attribute__((swift_name("toGenerationTimeParameters()")));

/**
 * Convert to KMP ModelLoadingOptions. Cache resolution lives in
 * `LiquidCacheOptions.toCacheOptions` so the iOS-shape opt-in chain stays in one place.
 */
- (LMDModelLoadingOptions *)toModelLoadingOptions __attribute__((swift_name("toModelLoadingOptions()")));

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
@property (readonly) NSString * _Nullable audioDecoderPath __attribute__((swift_name("audioDecoderPath")));

/** Whether to use GPU acceleration for audio decoder */
@property (readonly) BOOL audioDecoderUseGpu __attribute__((swift_name("audioDecoderUseGpu")));

/** Path to the audio tokenizer model */
@property (readonly) NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));

/** Path to the model bundle (the main .gguf file) */
@property (readonly) NSString *bundlePath __attribute__((swift_name("bundlePath")));

/** Optional cache configuration for inference engine */
@property (readonly) LMDLiquidCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));

/** Optional custom chat template override */
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/** Context window size (sequence length) */
@property (readonly) LMDUInt * _Nullable contextSize __attribute__((swift_name("contextSize")));

/** Number of CPU threads to use for inference */
@property (readonly) LMDUInt * _Nullable cpuThreads __attribute__((swift_name("cpuThreads")));

/** Additional engine-specific configuration as JSON string */
@property (readonly) NSString * _Nullable extras __attribute__((swift_name("extras")));

/** Path to the multimodal projection model for vision capabilities */
@property (readonly) NSString * _Nullable mmProjPath __attribute__((swift_name("mmProjPath")));

/** Number of GPU layers to offload (iOS/macOS typically uses Metal) */
@property (readonly) LMDUInt * _Nullable nGpuLayers __attribute__((swift_name("nGpuLayers")));
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
@interface LMDLiquidInferenceEngineRunner : LMDBase
@property (class, readonly, getter=companion) LMDLiquidInferenceEngineRunnerCompanion *companion __attribute__((swift_name("companion")));

/**
 * Create a new conversation with an optional system prompt.
 *
 * @param systemPrompt Optional system prompt. If null, uses the model's default system prompt.
 * @return A new Conversation instance
 */
- (id<LMDConversation>)createConversationSystemPrompt:(NSString * _Nullable)systemPrompt __attribute__((swift_name("createConversation(systemPrompt:)")));

/**
 * Create a conversation from existing chat history.
 *
 * @param history List of ChatMessage objects representing the conversation history
 * @return A new Conversation instance initialized with the given history
 */
- (id<LMDConversation>)createConversationFromHistoryHistory:(NSArray<LMDChatMessage *> *)history __attribute__((swift_name("createConversationFromHistory(history:)")));

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
- (void)getPromptTokensSizeMessages:(NSArray<LMDChatMessage *> *)messages addBosToken:(BOOL)addBosToken completionHandler:(void (^)(LMDInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPromptTokensSize(messages:addBosToken:completionHandler:)")));

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
@property (readonly) NSString *modelId __attribute__((swift_name("modelId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidInferenceEngineRunner.Companion")))
@interface LMDLiquidInferenceEngineRunnerCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLiquidInferenceEngineRunnerCompanion *shared __attribute__((swift_name("shared")));

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
- (void)createOptions:(LMDLiquidInferenceEngineOptions *)options generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters completionHandler:(void (^)(LMDLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(options:generationTimeParameters:completionHandler:)")));

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
- (void)createModel:(NSString *)model quantization:(NSString *)quantization generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters completionHandler:(void (^)(LMDLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(model:quantization:generationTimeParameters:completionHandler:)")));

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
- (void)createManifestUrl:(NSURL *)manifestUrl options:(LMDLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LMDDouble *, LMDLong *))downloadProgressHandler completionHandler:(void (^)(LMDLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(manifestUrl:options:downloadProgressHandler:completionHandler:)")));

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
- (void)createModel:(NSString *)model quantization:(NSString *)quantization options:(LMDLiquidInferenceEngineManifestOptions * _Nullable)options downloadProgressHandler:(void (^ _Nullable)(LMDDouble *, LMDLong *))downloadProgressHandler completionHandler:(void (^)(LMDLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(model:quantization:options:downloadProgressHandler:completionHandler:)")));

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
- (void)createUrl:(NSURL *)url options:(LMDLiquidInferenceEngineOptions * _Nullable)options generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters autoDetectCompanionFiles:(BOOL)autoDetectCompanionFiles completionHandler:(void (^)(LMDLiquidInferenceEngineRunner * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("create(url:options:generationTimeParameters:autoDetectCompanionFiles:completionHandler:)")));
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
@interface LMDLiquidMessageResponse : LMDBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.AudioSample")))
@interface LMDLiquidMessageResponseAudioSample : LMDLiquidMessageResponse
- (instancetype)initWithSamples:(NSArray<LMDFloat *> *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("init(samples:sampleRate:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidMessageResponseAudioSample *)doCopySamples:(NSArray<LMDFloat *> *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("doCopy(samples:sampleRate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@property (readonly) NSArray<LMDFloat *> *samples __attribute__((swift_name("samples")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.Chunk")))
@interface LMDLiquidMessageResponseChunk : LMDLiquidMessageResponse
- (instancetype)initWithDelta:(NSString *)delta __attribute__((swift_name("init(delta:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidMessageResponseChunk *)doCopyDelta:(NSString *)delta __attribute__((swift_name("doCopy(delta:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *delta __attribute__((swift_name("delta")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.Complete")))
@interface LMDLiquidMessageResponseComplete : LMDLiquidMessageResponse
- (instancetype)initWithFullMessage:(LMDChatMessage *)fullMessage finishReason:(LMDGenerationFinishReason *)finishReason stats:(LMDGenerationStats * _Nullable)stats __attribute__((swift_name("init(fullMessage:finishReason:stats:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidMessageResponseComplete *)doCopyFullMessage:(LMDChatMessage *)fullMessage finishReason:(LMDGenerationFinishReason *)finishReason stats:(LMDGenerationStats * _Nullable)stats __attribute__((swift_name("doCopy(fullMessage:finishReason:stats:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) LMDGenerationFinishReason *finishReason __attribute__((swift_name("finishReason")));
@property (readonly) LMDChatMessage *fullMessage __attribute__((swift_name("fullMessage")));
@property (readonly) LMDGenerationStats * _Nullable stats __attribute__((swift_name("stats")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.FunctionCall")))
@interface LMDLiquidMessageResponseFunctionCall : LMDLiquidMessageResponse
- (instancetype)initWithName:(NSString *)name arguments:(NSString *)arguments __attribute__((swift_name("init(name:arguments:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidMessageResponseFunctionCall *)doCopyName:(NSString *)name arguments:(NSString *)arguments __attribute__((swift_name("doCopy(name:arguments:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *arguments __attribute__((swift_name("arguments")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LiquidMessageResponse.ReasoningChunk")))
@interface LMDLiquidMessageResponseReasoningChunk : LMDLiquidMessageResponse
- (instancetype)initWithDelta:(NSString *)delta __attribute__((swift_name("init(delta:)"))) __attribute__((objc_designated_initializer));
- (LMDLiquidMessageResponseReasoningChunk *)doCopyDelta:(NSString *)delta __attribute__((swift_name("doCopy(delta:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *delta __attribute__((swift_name("delta")));
@end


/**
 * Progress information for a download operation.
 *
 * This matches the iOS SDK's progress reporting format.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DownloadProgress")))
@interface LMDDownloadProgress : LMDBase
- (instancetype)initWithFractionCompleted:(double)fractionCompleted bytesPerSecond:(int64_t)bytesPerSecond totalBytesDownloaded:(int64_t)totalBytesDownloaded totalBytesExpected:(LMDLong * _Nullable)totalBytesExpected __attribute__((swift_name("init(fractionCompleted:bytesPerSecond:totalBytesDownloaded:totalBytesExpected:)"))) __attribute__((objc_designated_initializer));
- (LMDDownloadProgress *)doCopyFractionCompleted:(double)fractionCompleted bytesPerSecond:(int64_t)bytesPerSecond totalBytesDownloaded:(int64_t)totalBytesDownloaded totalBytesExpected:(LMDLong * _Nullable)totalBytesExpected __attribute__((swift_name("doCopy(fractionCompleted:bytesPerSecond:totalBytesDownloaded:totalBytesExpected:)")));

/**
 * Progress information for a download operation.
 *
 * This matches the iOS SDK's progress reporting format.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Progress information for a download operation.
 *
 * This matches the iOS SDK's progress reporting format.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Progress information for a download operation.
 *
 * This matches the iOS SDK's progress reporting format.
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** Download speed in bytes per second */
@property (readonly) int64_t bytesPerSecond __attribute__((swift_name("bytesPerSecond")));

/** Fraction of download completed (0.0 to 1.0) */
@property (readonly) double fractionCompleted __attribute__((swift_name("fractionCompleted")));

/** Total bytes downloaded so far */
@property (readonly) int64_t totalBytesDownloaded __attribute__((swift_name("totalBytesDownloaded")));

/** Expected total bytes (null if unknown) */
@property (readonly) LMDLong * _Nullable totalBytesExpected __attribute__((swift_name("totalBytesExpected")));
@end


/**
 * Information about a downloaded model, including local file paths.
 *
 * This matches the iOS SDK's DownloadedModelManifest struct.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DownloadedModelManifest")))
@interface LMDDownloadedModelManifest : LMDBase
- (instancetype)initWithManifest:(LMDManifest *)manifest localModelPath:(NSString *)localModelPath localMultimodalProjectorPath:(NSString * _Nullable)localMultimodalProjectorPath localAudioDecoderPath:(NSString * _Nullable)localAudioDecoderPath localAudioTokenizerPath:(NSString * _Nullable)localAudioTokenizerPath chatTemplate:(NSString * _Nullable)chatTemplate __attribute__((swift_name("init(manifest:localModelPath:localMultimodalProjectorPath:localAudioDecoderPath:localAudioTokenizerPath:chatTemplate:)"))) __attribute__((objc_designated_initializer));
- (LMDDownloadedModelManifest *)doCopyManifest:(LMDManifest *)manifest localModelPath:(NSString *)localModelPath localMultimodalProjectorPath:(NSString * _Nullable)localMultimodalProjectorPath localAudioDecoderPath:(NSString * _Nullable)localAudioDecoderPath localAudioTokenizerPath:(NSString * _Nullable)localAudioTokenizerPath chatTemplate:(NSString * _Nullable)chatTemplate __attribute__((swift_name("doCopy(manifest:localModelPath:localMultimodalProjectorPath:localAudioDecoderPath:localAudioTokenizerPath:chatTemplate:)")));

/**
 * Information about a downloaded model, including local file paths.
 *
 * This matches the iOS SDK's DownloadedModelManifest struct.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Information about a downloaded model, including local file paths.
 *
 * This matches the iOS SDK's DownloadedModelManifest struct.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Information about a downloaded model, including local file paths.
 *
 * This matches the iOS SDK's DownloadedModelManifest struct.
 */
- (NSString *)description __attribute__((swift_name("description()")));

/** Chat template from the manifest */
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/** Local path to the audio decoder file (audio models) */
@property (readonly) NSString * _Nullable localAudioDecoderPath __attribute__((swift_name("localAudioDecoderPath")));

/** Local path to the audio tokenizer file (audio models) */
@property (readonly) NSString * _Nullable localAudioTokenizerPath __attribute__((swift_name("localAudioTokenizerPath")));

/** Local path to the main model file */
@property (readonly) NSString *localModelPath __attribute__((swift_name("localModelPath")));

/** Local path to the multimodal projector file (vision models) */
@property (readonly) NSString * _Nullable localMultimodalProjectorPath __attribute__((swift_name("localMultimodalProjectorPath")));

/** The parsed manifest */
@property (readonly) LMDManifest *manifest __attribute__((swift_name("manifest")));
@end


/**
 * Model downloader with full iOS API surface.
 *
 * This class provides the same API as the iOS SDK's ModelDownloader, including:
 * - Async downloads with progress reporting
 * - Fire-and-forget background downloads
 * - Status queries
 * - Model management (removal, size queries)
 *
 * Downloads use NSURLSession for true iOS background transfer support (downloads continue when app
 * is suspended/killed). Pass a background session configuration to enable this feature.
 *
 * Usage:
 * ```swift
 * // Foreground downloads (default)
 * let downloader = LeapModelDownloader()
 * let manifest = try await downloader.downloadModel(model: "lfm-40b", quantization: "q4_k_m") {
 *   fraction, bytesPerSecond in
 *   print("Progress: \(fraction * 100)%")
 * }
 *
 * // Background downloads (with background session config)
 * let config = NSURLSessionConfiguration.backgroundSessionConfiguration(
 *   withIdentifier: "com.myapp.leap.downloads"
 * )
 * let downloader = LeapModelDownloader(sessionConfiguration: config)
 * downloader.requestDownloadModel(model: "lfm-40b", quantization: "q4_k_m")
 *
 * // Query download status
 * let status = await downloader.queryStatus(model: "lfm-40b", quantization: "q4_k_m")
 * ```
 *
 * @param config LeapDownloader configuration (for manifest resolution)
 * @param sessionConfiguration Optional NSURLSessionConfiguration for file downloads. Pass
 *   `NSURLSessionConfiguration.backgroundSessionConfiguration(withIdentifier:)` for background
 *   downloads, or `nil` (default) for foreground downloads.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelDownloader")))
@interface LMDLeapModelDownloader : LMDBase
- (instancetype)initWithConfig:(LMDLeapDownloaderConfig *)config sessionConfiguration:(NSURLSessionConfiguration * _Nullable)sessionConfiguration __attribute__((swift_name("init(config:sessionConfiguration:)"))) __attribute__((objc_designated_initializer));

/**
 * Close the downloader and clean up resources.
 *
 * This method invalidates the underlying NSURLSession and cancels all pending download jobs.
 * After calling close(), this downloader instance should not be used for new operations.
 *
 * This method should be called when the LeapModelDownloader is no longer needed to prevent memory
 * leaks from the NSURLSession retain cycle.
 */
- (void)close __attribute__((swift_name("close()")));

/**
 * Download a model by name and quantization with progress reporting.
 *
 * @param model The model name (e.g., "lfm-40b")
 * @param quantization The quantization method (e.g., "q4_k_m")
 * @param downloadProgress Optional callback for download progress (fraction, bytesPerSecond)
 * @return DownloadedModelManifest containing the manifest and local file paths
 * @throws Exception if download fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)downloadModelModel:(NSString *)model quantization:(NSString *)quantization downloadProgress:(void (^ _Nullable)(LMDDouble *, LMDLong *))downloadProgress completionHandler:(void (^)(LMDDownloadedModelManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("downloadModel(model:quantization:downloadProgress:completionHandler:)")));

/**
 * Download a model from a manifest URL with progress reporting.
 *
 * @param manifestUrl The URL pointing to the manifest JSON file
 * @param downloadProgress Optional callback for download progress (fraction, bytesPerSecond)
 * @return DownloadedModelManifest containing the manifest and local file paths
 * @throws Exception if download fails
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)downloadModelFromManifestManifestUrl:(NSURL *)manifestUrl downloadProgress:(void (^ _Nullable)(LMDDouble *, LMDLong *))downloadProgress completionHandler:(void (^)(LMDDownloadedModelManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("downloadModelFromManifest(manifestUrl:downloadProgress:completionHandler:)")));

/**
 * Get available disk space in bytes.
 *
 * @return Available disk space in bytes, or null if it cannot be determined
 */
- (LMDLong * _Nullable)getAvailableDiskSpace __attribute__((swift_name("getAvailableDiskSpace()")));

/**
 * Get the total size of a model in bytes.
 *
 * If the model is downloaded, returns the actual size on disk. If not downloaded, resolves the
 * manifest and queries remote file sizes.
 *
 * @param model The model name
 * @param quantization The quantization method
 * @return The total size in bytes, or -1 if size cannot be determined
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getModelSizeModel:(NSString *)model quantization:(NSString *)quantization completionHandler:(void (^)(LMDLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getModelSize(model:quantization:completionHandler:)")));

/**
 * Handle background events for the download session.
 *
 * Call this from AppDelegate's application:handleEventsForBackgroundURLSession:completionHandler:
 * method.
 *
 * @param completionHandler The completion handler to invoke when all events are processed
 */
- (void)handleBackgroundEventsCompletionHandler:(void (^)(void))completionHandler __attribute__((swift_name("handleBackgroundEvents(completionHandler:)")));

/**
 * Query the download status of a model by manifest URL.
 *
 * @param manifestUrl The URL of the manifest JSON file
 * @return ModelDownloadStatus indicating download state
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)queryStatusManifestUrl:(NSURL *)manifestUrl completionHandler:(void (^)(id<LMDModelDownloadStatus> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("queryStatus(manifestUrl:completionHandler:)")));

/**
 * Query the download status of a model by name and quantization.
 *
 * @param model The model name
 * @param quantization The quantization method
 * @return ModelDownloadStatus indicating download state
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)queryStatusModel:(NSString *)model quantization:(NSString *)quantization completionHandler:(void (^)(id<LMDModelDownloadStatus> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("queryStatus(model:quantization:completionHandler:)")));

/**
 * Remove a downloaded model by manifest URL.
 *
 * @param manifestUrl The URL of the manifest JSON file
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeModelManifestUrl:(NSURL *)manifestUrl completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeModel(manifestUrl:completionHandler:)")));

/**
 * Remove a downloaded model from local storage.
 *
 * @param model The model name
 * @param quantization The quantization method
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeModelModel:(NSString *)model quantization:(NSString *)quantization completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeModel(model:quantization:completionHandler:)")));

/**
 * Start a download in the background without waiting for completion.
 *
 * Use queryStatus() to check download progress. The download continues even if the app is
 * backgrounded (when using a background session configuration).
 *
 * @param model The model name
 * @param quantization The quantization method
 */
- (void)requestDownloadModelModel:(NSString *)model quantization:(NSString *)quantization __attribute__((swift_name("requestDownloadModel(model:quantization:)")));

/**
 * Stop an in-progress background download.
 *
 * @param model The model name
 * @param quantization The quantization method
 */
- (void)requestStopDownloadModel:(NSString *)model quantization:(NSString *)quantization __attribute__((swift_name("requestStopDownload(model:quantization:)")));
@end


/**
 * Download status for a model.
 *
 * This matches the iOS SDK's ModelDownloadStatus enum.
 */
__attribute__((swift_name("ModelDownloadStatus")))
@protocol LMDModelDownloadStatus
@required
@end


/** Model download is in progress */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelDownloadStatusDownloadInProgress")))
@interface LMDModelDownloadStatusDownloadInProgress : LMDBase <LMDModelDownloadStatus>
- (instancetype)initWithProgress:(double)progress __attribute__((swift_name("init(progress:)"))) __attribute__((objc_designated_initializer));
- (LMDModelDownloadStatusDownloadInProgress *)doCopyProgress:(double)progress __attribute__((swift_name("doCopy(progress:)")));

/** Model download is in progress */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Model download is in progress */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Model download is in progress */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double progress __attribute__((swift_name("progress")));
@end


/** Model has been fully downloaded */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelDownloadStatusDownloaded")))
@interface LMDModelDownloadStatusDownloaded : LMDBase <LMDModelDownloadStatus>
+ (instancetype)alloc __attribute__((unavailable));

/** Model has been fully downloaded */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)downloaded __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDModelDownloadStatusDownloaded *shared __attribute__((swift_name("shared")));

/** Model has been fully downloaded */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Model has been fully downloaded */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Model has been fully downloaded */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/** Model is not present on local storage */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelDownloadStatusNotOnLocal")))
@interface LMDModelDownloadStatusNotOnLocal : LMDBase <LMDModelDownloadStatus>
+ (instancetype)alloc __attribute__((unavailable));

/** Model is not present on local storage */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)notOnLocal __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDModelDownloadStatusNotOnLocal *shared __attribute__((swift_name("shared")));

/** Model is not present on local storage */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Model is not present on local storage */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Model is not present on local storage */
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Sealed exception hierarchy for native download errors.
 *
 * Matches the iOS SDK's ModelDownloadError enum.
 */
__attribute__((swift_name("NativeDownloadError")))
@interface LMDNativeDownloadError : LMDKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * Download was cancelled by the user.
 *
 * @param message Error description
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NativeDownloadError.DownloadCancelled")))
@interface LMDNativeDownloadErrorDownloadCancelled : LMDNativeDownloadError
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Download failed due to an unspecified error.
 *
 * @param message Error description
 * @param cause Optional underlying exception
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NativeDownloadError.DownloadFailed")))
@interface LMDNativeDownloadErrorDownloadFailed : LMDNativeDownloadError
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Download failed due to a file I/O error.
 *
 * @param message Error description
 * @param cause Optional underlying exception
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NativeDownloadError.DownloadFileIOError")))
@interface LMDNativeDownloadErrorDownloadFileIOError : LMDNativeDownloadError
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Download failed due to a network error.
 *
 * @param message Error description
 * @param cause Optional underlying exception
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NativeDownloadError.DownloadNetworkError")))
@interface LMDNativeDownloadErrorDownloadNetworkError : LMDNativeDownloadError
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Native download service using NSURLSession for background-capable downloads.
 *
 * This class implements the NSURLSession delegate pattern to support:
 * - True iOS background transfers (downloads continue when app is suspended/killed)
 * - Progress tracking with exponential moving average speed calculation
 * - Download coalescing (multiple callers share one task for the same modelKey)
 * - Async/await bridge via CompletableDeferred
 *
 * Thread safety: All state mutations are protected by NSRecursiveLock since delegate callbacks are
 * synchronous and can't use coroutine Mutex (which requires suspension).
 *
 * @param sessionConfiguration NSURLSessionConfiguration to use for the session. Pass
 *   `NSURLSessionConfiguration.backgroundSessionConfigurationWithIdentifier("id")` for true
 *   background downloads, or `null` to use default foreground config.
 */
__attribute__((unavailable("Kotlin subclass of Objective-C class can't be imported")))
__attribute__((swift_name("NativeDownloadService")))
@interface LMDNativeDownloadService : NSObject
@end


/** Sealed serializable representation of function argument values.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/function/FunctionArgSerializer))
*/
__attribute__((swift_name("FunctionArg")))
@protocol LMDFunctionArg
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FunctionArgCompanion")))
@interface LMDFunctionArgCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDFunctionArgCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDFunctionArg>)fromAnyValue:(id _Nullable)value __attribute__((swift_name("fromAny(value:)")));
- (id<LMDFunctionArg>)fromJsonElementElement:(LMDKotlinx_serialization_jsonJsonElement *)element __attribute__((swift_name("fromJsonElement(element:)")));
- (NSDictionary<NSString *, id<LMDFunctionArg>> *)mapFromAnyMapMap:(NSDictionary<NSString *, id> *)map __attribute__((swift_name("mapFromAnyMap(map:)")));
- (NSDictionary<NSString *, id<LMDFunctionArg>> *)mapFromJsonObjectObj:(NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)obj __attribute__((swift_name("mapFromJsonObject(obj:)")));
- (NSDictionary<NSString *, id> *)mapToAnyMapMap:(NSDictionary<NSString *, id<LMDFunctionArg>> *)map __attribute__((swift_name("mapToAnyMap(map:)")));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)mapToJsonObjectMap:(NSDictionary<NSString *, id<LMDFunctionArg>> *)map __attribute__((swift_name("mapToJsonObject(map:)")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LMDKotlinArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
- (id _Nullable)toAnyValue:(id<LMDFunctionArg>)value __attribute__((swift_name("toAny(value:)")));
- (LMDKotlinx_serialization_jsonJsonElement *)toJsonElementValue:(id<LMDFunctionArg>)value __attribute__((swift_name("toJsonElement(value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol LMDKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol LMDKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol LMDKotlinx_serialization_coreKSerializer <LMDKotlinx_serialization_coreSerializationStrategy, LMDKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FunctionArgSerializer")))
@interface LMDFunctionArgSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)functionArgSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDFunctionArgSerializer *shared __attribute__((swift_name("shared")));
- (id<LMDFunctionArg>)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(id<LMDFunctionArg>)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * Abstract class to describe a function call parser in Leap.
 *
 * @param toolCallStartToken The token indicates the start of the function call request content
 * @param toolCallEndToken The token indicates the end of the function call request content
 */
__attribute__((swift_name("LeapFunctionCallParser")))
@interface LMDLeapFunctionCallParser : LMDBase
- (instancetype)initWithToolCallStartToken:(NSString *)toolCallStartToken toolCallEndToken:(NSString *)toolCallEndToken __attribute__((swift_name("init(toolCallStartToken:toolCallEndToken:)"))) __attribute__((objc_designated_initializer));

/** Append a chunk into the buffer of the parser. */
- (void)appendChunk:(NSString *)chunk __attribute__((swift_name("append(chunk:)")));

/** Clear the buffer of the parser. */
- (void)clear __attribute__((swift_name("clear()")));
- (NSString *)dumpFunctionCalls:(NSArray<LMDLeapFunctionCall *> *)functionCalls __attribute__((swift_name("dump(functionCalls:)")));

/** Parse the content in the buffer and clear the buffer. */
- (NSArray<LMDLeapFunctionCall *> *)parse __attribute__((swift_name("parse()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property LMDKotlinStringBuilder *buffer __attribute__((swift_name("buffer")));
@property (readonly) NSString *toolCallEndToken __attribute__((swift_name("toolCallEndToken")));
@property (readonly) NSString *toolCallStartToken __attribute__((swift_name("toolCallStartToken")));
@end


/**
 * Function call parsers for models that are using
 * [Hermes function calling format](https://github.com/NousResearch/Hermes-Function-Calling). For
 * example, Qwen3 models.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HermesFunctionCallParser")))
@interface LMDHermesFunctionCallParser : LMDLeapFunctionCallParser

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
- (NSString *)dumpFunctionCalls:(NSArray<LMDLeapFunctionCall *> *)functionCalls __attribute__((swift_name("dump(functionCalls:)")));
- (NSArray<LMDLeapFunctionCall *> *)parse __attribute__((swift_name("parse()")));
@end


/** Function call parsers for Liquid Foundation Models (LFM2). */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LFMFunctionCallParser")))
@interface LMDLFMFunctionCallParser : LMDLeapFunctionCallParser

/** Function call parsers for Liquid Foundation Models (LFM2). */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** Function call parsers for Liquid Foundation Models (LFM2). */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithToolCallStartToken:(NSString *)toolCallStartToken toolCallEndToken:(NSString *)toolCallEndToken __attribute__((swift_name("init(toolCallStartToken:toolCallEndToken:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (NSString *)dumpFunctionCalls:(NSArray<LMDLeapFunctionCall *> *)functionCalls __attribute__((swift_name("dump(functionCalls:)")));
- (NSArray<LMDLeapFunctionCall *> *)parse __attribute__((swift_name("parse()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapArr")))
@interface LMDLeapArr : LMDBase <LMDFunctionArg>
- (instancetype)initWithValue:(NSArray<id<LMDFunctionArg>> *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapArrCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapArr *)doCopyValue:(NSArray<id<LMDFunctionArg>> *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<id<LMDFunctionArg>> *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapArr.Companion")))
@interface LMDLeapArrCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapArrCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapBool")))
@interface LMDLeapBool : LMDBase <LMDFunctionArg>
- (instancetype)initWithValue:(BOOL)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapBoolCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapBool *)doCopyValue:(BOOL)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapBool.Companion")))
@interface LMDLeapBoolCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapBoolCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
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
@interface LMDLeapFunction : LMDBase
- (instancetype)initWithName:(NSString *)name functionDescription:(NSString *)functionDescription parameters:(NSArray<LMDLeapFunctionParameter *> *)parameters __attribute__((swift_name("init(name:functionDescription:parameters:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapFunction *)doCopyName:(NSString *)name functionDescription:(NSString *)functionDescription parameters:(NSArray<LMDLeapFunctionParameter *> *)parameters __attribute__((swift_name("doCopy(name:functionDescription:parameters:)")));

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
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObjectWithToolTypeWrapper:(BOOL)withToolTypeWrapper __attribute__((swift_name("toJsonObject(withToolTypeWrapper:)")));

/**
 * Describe the signature of a function that can be called by the model.
 *
 * @param name name of the function
 * @param description human-readable / LLM-readable description of the function
 * @param parameters list of parameters that accepted by the function
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSArray<LMDLeapFunctionParameter *> *parameters __attribute__((swift_name("parameters")));
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
@interface LMDLeapFunctionCall : LMDBase
- (instancetype)initWithName:(NSString *)name arguments:(NSDictionary<NSString *, id> *)arguments __attribute__((swift_name("init(name:arguments:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionCallCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionCall *)doCopyName:(NSString *)name arguments:(NSDictionary<NSString *, id> *)arguments __attribute__((swift_name("doCopy(name:arguments:)")));

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
@property (readonly) NSDictionary<NSString *, id> *arguments __attribute__((swift_name("arguments")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
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
@interface LMDLeapFunctionCallCompanion : LMDBase
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
@property (class, readonly, getter=shared) LMDLeapFunctionCallCompanion *shared __attribute__((swift_name("shared")));

/**
 * Describe a function call request generated by the model.
 *
 * Args:
 *
 * @param name the name of the function to be called
 * @param arguments the parameters of this call in a map. Values could be strings, numbers,
 *   booleans, arrays, nulls, or maps for objects.
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionCallSerializer")))
@interface LMDLeapFunctionCallSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapFunctionCallSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionCallSerializer *shared __attribute__((swift_name("shared")));
- (LMDLeapFunctionCall *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(LMDLeapFunctionCall *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
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
@interface LMDLeapFunctionDto : LMDBase
- (instancetype)initWithName:(NSString *)name description:(NSString *)description parameters:(NSArray<LMDLeapFunctionParameterDto *> *)parameters __attribute__((swift_name("init(name:description:parameters:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionDtoCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionDto *)doCopyName:(NSString *)name description:(NSString *)description parameters:(NSArray<LMDLeapFunctionParameterDto *> *)parameters __attribute__((swift_name("doCopy(name:description:parameters:)")));

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
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSArray<LMDLeapFunctionParameterDto *> *parameters __attribute__((swift_name("parameters")));
@end


/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionDto.Companion")))
@interface LMDLeapFunctionDtoCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionDtoCompanion *shared __attribute__((swift_name("shared")));

/**
 * Serializable mirror of [LeapFunction]. Used by the leap-model-service AIDL layer so client and
 * service can exchange function schemas without the [LeapFunction] sealed hierarchy being part of
 * the AIDL wire protocol directly.
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
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
@interface LMDLeapFunctionParameter : LMDBase
- (instancetype)initWithName:(NSString *)name type:(LMDLeapFunctionParameterType *)type parameterDescription:(NSString *)parameterDescription optional:(BOOL)optional __attribute__((swift_name("init(name:type:parameterDescription:optional:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapFunctionParameter *)doCopyName:(NSString *)name type:(LMDLeapFunctionParameterType *)type parameterDescription:(NSString *)parameterDescription optional:(BOOL)optional __attribute__((swift_name("doCopy(name:type:parameterDescription:optional:)")));

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
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) BOOL optional __attribute__((swift_name("optional")));
@property (readonly) LMDLeapFunctionParameterType *type __attribute__((swift_name("type")));
@end


/** Serializable mirror of [LeapFunctionParameter].
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterDto")))
@interface LMDLeapFunctionParameterDto : LMDBase
- (instancetype)initWithName:(NSString *)name type:(LMDLeapFunctionParameterTypeDto *)type description:(NSString *)description optional:(BOOL)optional __attribute__((swift_name("init(name:type:description:optional:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterDtoCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterDto *)doCopyName:(NSString *)name type:(LMDLeapFunctionParameterTypeDto *)type description:(NSString *)description optional:(BOOL)optional __attribute__((swift_name("doCopy(name:type:description:optional:)")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) BOOL optional __attribute__((swift_name("optional")));
@property (readonly) LMDLeapFunctionParameterTypeDto *type __attribute__((swift_name("type")));
@end


/** Serializable mirror of [LeapFunctionParameter]. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterDto.Companion")))
@interface LMDLeapFunctionParameterDtoCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** Serializable mirror of [LeapFunctionParameter]. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterDtoCompanion *shared __attribute__((swift_name("shared")));

/** Serializable mirror of [LeapFunctionParameter]. */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Represent a type that can be used for the parameters of Leap functions. All types declared must
 * be allowed in JSON Schema.
 *
 * @param description an optional, human-readable and LLM-readable description of this type
 */
__attribute__((swift_name("LeapFunctionParameterType")))
@interface LMDLeapFunctionParameterType : LMDBase

/** Create a JsonObject representation of this type, which will be consumed by LLM */
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@property (readonly) NSString * _Nullable typeDescription __attribute__((swift_name("typeDescription")));
@end


/** LeapArr type. `itemType` indicates the type of its element. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapArr")))
@interface LMDLeapFunctionParameterTypeLeapArr : LMDLeapFunctionParameterType
- (instancetype)initWithItemType:(LMDLeapFunctionParameterType *)itemType description:(NSString * _Nullable)description __attribute__((swift_name("init(itemType:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@property (readonly) LMDLeapFunctionParameterType *itemType __attribute__((swift_name("itemType")));
@end


/** LeapBool literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapBool")))
@interface LMDLeapFunctionParameterTypeLeapBool : LMDLeapFunctionParameterType
- (instancetype)initWithDescription:(NSString * _Nullable)description __attribute__((swift_name("init(description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapInt literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapInt")))
@interface LMDLeapFunctionParameterTypeLeapInt : LMDLeapFunctionParameterType
- (instancetype)initWithEnumValues:(NSArray<LMDInt *> * _Nullable)enumValues description:(NSString * _Nullable)description __attribute__((swift_name("init(enumValues:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@property (readonly) NSArray<LMDInt *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
@end


/** LeapNull type: only null value is accepted. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapNull")))
@interface LMDLeapFunctionParameterTypeLeapNull : LMDLeapFunctionParameterType

/** LeapNull type: only null value is accepted. */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/** LeapNull type: only null value is accepted. */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@end


/** LeapNum literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapNum")))
@interface LMDLeapFunctionParameterTypeLeapNum : LMDLeapFunctionParameterType
- (instancetype)initWithEnumValues:(NSArray<id> * _Nullable)enumValues description:(NSString * _Nullable)description __attribute__((swift_name("init(enumValues:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@property (readonly) NSArray<id> * _Nullable enumValues __attribute__((swift_name("enumValues")));
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
@interface LMDLeapFunctionParameterTypeLeapObj : LMDLeapFunctionParameterType
- (instancetype)initWithProperties:(NSDictionary<NSString *, LMDLeapFunctionParameterType *> *)properties required:(NSArray<NSString *> *)required description:(NSString * _Nullable)description __attribute__((swift_name("init(properties:required:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@property (readonly) NSDictionary<NSString *, LMDLeapFunctionParameterType *> *properties __attribute__((swift_name("properties")));
@property (readonly) NSArray<NSString *> *required __attribute__((swift_name("required")));
@end


/** LeapStr literal type. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterType.LeapStr")))
@interface LMDLeapFunctionParameterTypeLeapStr : LMDLeapFunctionParameterType
- (instancetype)initWithEnumValues:(NSArray<NSString *> * _Nullable)enumValues description:(NSString * _Nullable)description __attribute__((swift_name("init(enumValues:description:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)toJsonObject __attribute__((swift_name("toJsonObject()")));
@property (readonly) NSArray<NSString *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
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
@interface LMDLeapFunctionParameterTypeDto : LMDBase
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="arr")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Arr")))
@interface LMDLeapFunctionParameterTypeDtoArr : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description itemType:(LMDLeapFunctionParameterTypeDto *)itemType __attribute__((swift_name("init(description:itemType:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoArrCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoArr *)doCopyDescription:(NSString * _Nullable)description itemType:(LMDLeapFunctionParameterTypeDto *)itemType __attribute__((swift_name("doCopy(description:itemType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) LMDLeapFunctionParameterTypeDto *itemType __attribute__((swift_name("itemType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.ArrCompanion")))
@interface LMDLeapFunctionParameterTypeDtoArrCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoArrCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="bool")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Bool")))
@interface LMDLeapFunctionParameterTypeDtoBool : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description __attribute__((swift_name("init(description:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoBoolCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoBool *)doCopyDescription:(NSString * _Nullable)description __attribute__((swift_name("doCopy(description:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.BoolCompanion")))
@interface LMDLeapFunctionParameterTypeDtoBoolCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoBoolCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
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
@interface LMDLeapFunctionParameterTypeDtoCompanion : LMDBase
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
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoCompanion *shared __attribute__((swift_name("shared")));

/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));

/**
 * Serializable mirror of [LeapFunctionParameterType]. Used for AIDL wire transport
 * (leap-model-service) where the native SDK type hierarchy can't cross process boundaries directly.
 * Convert via [LeapFunctionParameterType.toDto] and [LeapFunctionParameterTypeDto.toDomain].
 *
 * The subclass tags (`str`, `num`, etc.) are the wire format — keep them stable.
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LMDKotlinArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="int")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.IntType")))
@interface LMDLeapFunctionParameterTypeDtoIntType : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description enumValues:(NSArray<LMDInt *> * _Nullable)enumValues __attribute__((swift_name("init(description:enumValues:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoIntTypeCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoIntType *)doCopyDescription:(NSString * _Nullable)description enumValues:(NSArray<LMDInt *> * _Nullable)enumValues __attribute__((swift_name("doCopy(description:enumValues:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSArray<LMDInt *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.IntTypeCompanion")))
@interface LMDLeapFunctionParameterTypeDtoIntTypeCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoIntTypeCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="null")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.NullType")))
@interface LMDLeapFunctionParameterTypeDtoNullType : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description __attribute__((swift_name("init(description:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoNullTypeCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoNullType *)doCopyDescription:(NSString * _Nullable)description __attribute__((swift_name("doCopy(description:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.NullTypeCompanion")))
@interface LMDLeapFunctionParameterTypeDtoNullTypeCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoNullTypeCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="num")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Num")))
@interface LMDLeapFunctionParameterTypeDtoNum : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description enumValues:(NSArray<LMDDouble *> * _Nullable)enumValues __attribute__((swift_name("init(description:enumValues:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoNumCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoNum *)doCopyDescription:(NSString * _Nullable)description enumValues:(NSArray<LMDDouble *> * _Nullable)enumValues __attribute__((swift_name("doCopy(description:enumValues:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSArray<LMDDouble *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.NumCompanion")))
@interface LMDLeapFunctionParameterTypeDtoNumCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoNumCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="obj")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Obj")))
@interface LMDLeapFunctionParameterTypeDtoObj : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description properties:(NSDictionary<NSString *, LMDLeapFunctionParameterTypeDto *> *)properties required:(NSArray<NSString *> *)required __attribute__((swift_name("init(description:properties:required:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoObjCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoObj *)doCopyDescription:(NSString * _Nullable)description properties:(NSDictionary<NSString *, LMDLeapFunctionParameterTypeDto *> *)properties required:(NSArray<NSString *> *)required __attribute__((swift_name("doCopy(description:properties:required:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSDictionary<NSString *, LMDLeapFunctionParameterTypeDto *> *properties __attribute__((swift_name("properties")));
@property (readonly) NSArray<NSString *> *required __attribute__((swift_name("required")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.ObjCompanion")))
@interface LMDLeapFunctionParameterTypeDtoObjCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoObjCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="str")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.Str")))
@interface LMDLeapFunctionParameterTypeDtoStr : LMDLeapFunctionParameterTypeDto
- (instancetype)initWithDescription:(NSString * _Nullable)description enumValues:(NSArray<NSString *> * _Nullable)enumValues __attribute__((swift_name("init(description:enumValues:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapFunctionParameterTypeDtoStrCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapFunctionParameterTypeDtoStr *)doCopyDescription:(NSString * _Nullable)description enumValues:(NSArray<NSString *> * _Nullable)enumValues __attribute__((swift_name("doCopy(description:enumValues:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));
@property (readonly) NSArray<NSString *> * _Nullable enumValues __attribute__((swift_name("enumValues")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapFunctionParameterTypeDto.StrCompanion")))
@interface LMDLeapFunctionParameterTypeDtoStrCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapFunctionParameterTypeDtoStrCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNull")))
@interface LMDLeapNull : LMDBase <LMDFunctionArg>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)leapNull __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapNull *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LMDKotlinArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("LeapNum")))
@interface LMDLeapNum : LMDBase <LMDFunctionArg>
@property (class, readonly, getter=companion) LMDLeapNumCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.Companion")))
@interface LMDLeapNumCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapNumCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LMDKotlinArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.DoubleNum")))
@interface LMDLeapNumDoubleNum : LMDLeapNum
- (instancetype)initWithValue:(double)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapNumDoubleNumCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapNumDoubleNum *)doCopyValue:(double)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.DoubleNumCompanion")))
@interface LMDLeapNumDoubleNumCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapNumDoubleNumCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.IntNum")))
@interface LMDLeapNumIntNum : LMDLeapNum
- (instancetype)initWithValue:(int32_t)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapNumIntNumCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapNumIntNum *)doCopyValue:(int32_t)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.IntNumCompanion")))
@interface LMDLeapNumIntNumCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapNumIntNumCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.LongNum")))
@interface LMDLeapNumLongNum : LMDLeapNum
- (instancetype)initWithValue:(int64_t)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapNumLongNumCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapNumLongNum *)doCopyValue:(int64_t)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapNum.LongNumCompanion")))
@interface LMDLeapNumLongNumCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapNumLongNumCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapObj")))
@interface LMDLeapObj : LMDBase <LMDFunctionArg>
- (instancetype)initWithValue:(NSDictionary<NSString *, id<LMDFunctionArg>> *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapObjCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapObj *)doCopyValue:(NSDictionary<NSString *, id<LMDFunctionArg>> *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, id<LMDFunctionArg>> *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapObj.Companion")))
@interface LMDLeapObjCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapObjCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapStr")))
@interface LMDLeapStr : LMDBase <LMDFunctionArg>
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapStrCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapStr *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapStr.Companion")))
@interface LMDLeapStrCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapStrCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicDumper")))
@interface LMDPythonicDumper : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)pythonicDumper __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDPythonicDumper *shared __attribute__((swift_name("shared")));

/**
 * Serialize the function calls into Pythnoic format. The input should be created by
 * [PythonicParser]. Otherwise, the return value could be invalid.
 */
- (NSString *)dumpFunctionCallsCalls:(NSArray<LMDLeapFunctionCall *> *)calls __attribute__((swift_name("dumpFunctionCalls(calls:)")));
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
@interface LMDPythonicParser : LMDBase
- (instancetype)initWithBuffer:(NSString *)buffer __attribute__((swift_name("init(buffer:)"))) __attribute__((objc_designated_initializer));

/**
 * Parse the Pythonic function call requests and return a list of [LeapFunctionCall] objects as
 * the result.
 *
 * This function can only be called once because it will mutate the parser internal states.
 */
- (NSArray<LMDLeapFunctionCall *> *)parsePythonicCalls __attribute__((swift_name("parsePythonicCalls()")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface LMDKotlinRuntimeException : LMDKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Errors on syntax in Pythonic function call codes, emitted by the parser */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicSyntaxError")))
@interface LMDPythonicSyntaxError : LMDKotlinRuntimeException
- (instancetype)initWithPos:(int32_t)pos reason:(NSString *)reason __attribute__((swift_name("init(pos:reason:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) int32_t pos __attribute__((swift_name("pos")));
@property (readonly) NSString *reason __attribute__((swift_name("reason")));
@end


/** Data class of a recognized token. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicToken")))
@interface LMDPythonicToken : LMDBase
- (instancetype)initWithName:(LMDPythonicTokenName *)name text:(NSString *)text __attribute__((swift_name("init(name:text:)"))) __attribute__((objc_designated_initializer));
- (LMDPythonicToken *)doCopyName:(LMDPythonicTokenName *)name text:(NSString *)text __attribute__((swift_name("doCopy(name:text:)")));

/** Data class of a recognized token. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Data class of a recognized token. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Data class of a recognized token. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) LMDPythonicTokenName *name __attribute__((swift_name("name")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
@end


/** Name/type of the token. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicTokenName")))
@interface LMDPythonicTokenName : LMDKotlinEnum<LMDPythonicTokenName *>
+ (instancetype)alloc __attribute__((unavailable));

/** Name/type of the token. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) LMDPythonicTokenName *leftSquareBracket __attribute__((swift_name("leftSquareBracket")));
@property (class, readonly) LMDPythonicTokenName *rightSquareBracket __attribute__((swift_name("rightSquareBracket")));
@property (class, readonly) LMDPythonicTokenName *leftParentheses __attribute__((swift_name("leftParentheses")));
@property (class, readonly) LMDPythonicTokenName *rightParentheses __attribute__((swift_name("rightParentheses")));
@property (class, readonly) LMDPythonicTokenName *leftCurlyBracket __attribute__((swift_name("leftCurlyBracket")));
@property (class, readonly) LMDPythonicTokenName *rightCurlyBracket __attribute__((swift_name("rightCurlyBracket")));
@property (class, readonly) LMDPythonicTokenName *colon __attribute__((swift_name("colon")));
@property (class, readonly) LMDPythonicTokenName *comma __attribute__((swift_name("comma")));
@property (class, readonly) LMDPythonicTokenName *equal __attribute__((swift_name("equal")));
@property (class, readonly) LMDPythonicTokenName *identifier __attribute__((swift_name("identifier")));
@property (class, readonly) LMDPythonicTokenName *numberLiteral __attribute__((swift_name("numberLiteral")));
@property (class, readonly) LMDPythonicTokenName *stringLiteral __attribute__((swift_name("stringLiteral")));
@property (class, readonly) LMDPythonicTokenName *space __attribute__((swift_name("space")));
+ (LMDKotlinArray<LMDPythonicTokenName *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDPythonicTokenName *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("KotlinIterable")))
@protocol LMDKotlinIterable
@required
- (id<LMDKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end


/**
 * Tokenizer to tokenize Pythonic function call code generated by the model.
 *
 * It is used by [PythonicParser] and it should not be used directly by the external code.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PythonicTokenizer")))
@interface LMDPythonicTokenizer : LMDBase <LMDKotlinIterable>
- (instancetype)initWithBuffer:(NSString *)buffer __attribute__((swift_name("init(buffer:)"))) __attribute__((objc_designated_initializer));
- (id<LMDKotlinIterator>)iterator __attribute__((swift_name("iterator()")));

/**
 * @note This method converts instances of PythonicSyntaxError to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (LMDPythonicToken * _Nullable)nextTokenAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("nextToken()"))) __attribute__((swift_error(nonnull_error)));
@property (readonly) int32_t currentPosition __attribute__((swift_name("currentPosition")));
@property (readonly) BOOL hasNextToken __attribute__((swift_name("hasNextToken")));
@end


/** Internal bundle config data representation. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BundleConfig")))
@interface LMDBundleConfig : LMDBase
- (instancetype)initWithSystemMessage:(NSString * _Nullable)systemMessage samplerParams:(LMDSamplerParams * _Nullable)samplerParams __attribute__((swift_name("init(systemMessage:samplerParams:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDBundleConfigCompanion *companion __attribute__((swift_name("companion")));
- (LMDBundleConfig *)doCopySystemMessage:(NSString * _Nullable)systemMessage samplerParams:(LMDSamplerParams * _Nullable)samplerParams __attribute__((swift_name("doCopy(systemMessage:samplerParams:)")));

/** Internal bundle config data representation. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Internal bundle config data representation. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Internal bundle config data representation. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) LMDSamplerParams * _Nullable samplerParams __attribute__((swift_name("samplerParams")));
@property (readonly) NSString * _Nullable systemMessage __attribute__((swift_name("systemMessage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BundleConfig.Companion")))
@interface LMDBundleConfigCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDBundleConfigCompanion *shared __attribute__((swift_name("shared")));

/** Parse an YAML string to create the bundle config object. */
- (id _Nullable)parseRaw:(NSString *)raw __attribute__((swift_name("parse(raw:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Constraints")))
@interface LMDConstraints : LMDBase
@property (class, readonly, getter=companion) LMDConstraintsCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *json __attribute__((swift_name("json")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Constraints.Companion")))
@interface LMDConstraintsCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDConstraintsCompanion *shared __attribute__((swift_name("shared")));
- (LMDConstraints *)fromJsonJson:(NSString *)json __attribute__((swift_name("fromJson(json:)")));
@end


/** Native implementation of Engine using C interop. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Engine")))
@interface LMDEngine : LMDBase
@property (class, readonly, getter=companion) LMDEngineCompanion *companion __attribute__((swift_name("companion")));
- (void)destroy __attribute__((swift_name("destroy()")));
- (LMDGenerationStopReason *)generateMessages:(NSArray<LMDMessage *> *)messages options:(LMDGenerateOptions *)options __attribute__((swift_name("generate(messages:options:)")));
@property (readonly) NSString * _Nullable modelId __attribute__((swift_name("modelId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Engine.Companion")))
@interface LMDEngineCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDEngineCompanion *shared __attribute__((swift_name("shared")));
- (LMDEngine *)createFromOptionsOptions:(LMDEngineOptions *)options __attribute__((swift_name("createFromOptions(options:)")));
@end


/** Native implementation of EngineOptions. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineOptions")))
@interface LMDEngineOptions : LMDBase
- (instancetype)initWithBundlePath:(NSString *)bundlePath __attribute__((swift_name("init(bundlePath:)"))) __attribute__((objc_designated_initializer));
@property NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSString *bundlePath __attribute__((swift_name("bundlePath")));
@property LMDEngineOptionsCacheOptions * _Nullable cacheOptions __attribute__((swift_name("cacheOptions")));
@property NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));
@property LMDInt * _Nullable contextSize __attribute__((swift_name("contextSize")));
@property LMDInt * _Nullable cpuThreads __attribute__((swift_name("cpuThreads")));
@property NSString * _Nullable extras __attribute__((swift_name("extras")));
@property LMDInt * _Nullable imageMaxTokens __attribute__((swift_name("imageMaxTokens")));
@property LMDInt * _Nullable imageMinTokens __attribute__((swift_name("imageMinTokens")));
@property NSString * _Nullable mmprojPath __attribute__((swift_name("mmprojPath")));
@property NSString * _Nullable modelAudioDecoderPath __attribute__((swift_name("modelAudioDecoderPath")));
@property LMDLong * _Nullable rngSeed __attribute__((swift_name("rngSeed")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineOptions.CacheOptions")))
@interface LMDEngineOptionsCacheOptions : LMDBase
- (instancetype)initWithPath:(NSString *)path maxEntries:(int32_t)maxEntries enabled:(BOOL)enabled maxEntriesDisk:(int32_t)maxEntriesDisk maxEntriesMemory:(int32_t)maxEntriesMemory maxBytesMemory:(int64_t)maxBytesMemory diskDisabled:(BOOL)diskDisabled __attribute__((swift_name("init(path:maxEntries:enabled:maxEntriesDisk:maxEntriesMemory:maxBytesMemory:diskDisabled:)"))) __attribute__((objc_designated_initializer));
@property (readonly) BOOL diskDisabled __attribute__((swift_name("diskDisabled")));
@property (readonly) BOOL enabled __attribute__((swift_name("enabled")));
@property (readonly) int64_t maxBytesMemory __attribute__((swift_name("maxBytesMemory")));
@property (readonly) int32_t maxEntries __attribute__((swift_name("maxEntries")));
@property (readonly) int32_t maxEntriesDisk __attribute__((swift_name("maxEntriesDisk")));
@property (readonly) int32_t maxEntriesMemory __attribute__((swift_name("maxEntriesMemory")));
@property (readonly) NSString *path __attribute__((swift_name("path")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerateOptions")))
@interface LMDGenerateOptions : LMDBase
- (instancetype)initWithSamplerParams:(LMDSamplerParams * _Nullable)samplerParams constraints:(LMDConstraints * _Nullable)constraints callback:(id<LMDGenerateOptionsTokenCallback> _Nullable)callback __attribute__((swift_name("init(samplerParams:constraints:callback:)"))) __attribute__((objc_designated_initializer));
@property id<LMDGenerateOptionsTokenCallback> _Nullable callback __attribute__((swift_name("callback")));
@property LMDConstraints * _Nullable constraints __attribute__((swift_name("constraints")));
@property LMDSamplerParams * _Nullable samplerParams __attribute__((swift_name("samplerParams")));
@end

__attribute__((swift_name("GenerateOptionsTokenCallback")))
@protocol LMDGenerateOptionsTokenCallback
@required
- (void)onTokenToken:(NSString * _Nullable)token isSpecial:(BOOL)isSpecial __attribute__((swift_name("onToken(token:isSpecial:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationStopReason")))
@interface LMDGenerationStopReason : LMDKotlinEnum<LMDGenerationStopReason *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDGenerationStopReasonCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LMDGenerationStopReason *finished __attribute__((swift_name("finished")));
@property (class, readonly) LMDGenerationStopReason *interrupted __attribute__((swift_name("interrupted")));
@property (class, readonly) LMDGenerationStopReason *outOfContext __attribute__((swift_name("outOfContext")));
@property (class, readonly) LMDGenerationStopReason *unknown __attribute__((swift_name("unknown")));
+ (LMDKotlinArray<LMDGenerationStopReason *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDGenerationStopReason *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationStopReason.Companion")))
@interface LMDGenerationStopReasonCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDGenerationStopReasonCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InferenceEngineConversation")))
@interface LMDInferenceEngineConversation : LMDBase <LMDConversation>
- (instancetype)initWithModelRunner:(id<LMDModelRunner>)modelRunner history:(NSArray<LMDChatMessage *> *)history __attribute__((swift_name("init(modelRunner:history:)"))) __attribute__((objc_designated_initializer));
- (void)appendToHistoryMessage:(LMDChatMessage *)message __attribute__((swift_name("appendToHistory(message:)")));
- (void)registerFunctionFunction:(LMDLeapFunction *)function __attribute__((swift_name("registerFunction(function:)")));
- (void)removeLastMessage __attribute__((swift_name("removeLastMessage()")));
@property (readonly) NSArray<LMDLeapFunction *> *functions __attribute__((swift_name("functions")));
@property (readonly) id<LMDKotlinx_coroutines_coreMutex> generatingLock __attribute__((swift_name("generatingLock")));
@property (readonly) NSArray<LMDChatMessage *> *history __attribute__((swift_name("history")));
@property (readonly) id<LMDModelRunner> modelRunner __attribute__((swift_name("modelRunner")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InferenceEngineExceptions")))
@interface LMDInferenceEngineExceptions : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)inferenceEngineExceptions __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDInferenceEngineExceptions *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InferenceEngineExceptions.PromptExceedContextLengthException")))
@interface LMDInferenceEngineExceptionsPromptExceedContextLengthException : LMDKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Message")))
@interface LMDMessage : LMDBase
- (instancetype)initWithRole:(NSString *)role contents:(NSArray<LMDMessageContent *> *)contents __attribute__((swift_name("init(role:contents:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSArray<LMDMessageContent *> *contents __attribute__((swift_name("contents")));
@property (readonly) NSString *role __attribute__((swift_name("role")));
@end

__attribute__((swift_name("MessageContent")))
@interface LMDMessageContent : LMDBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageContent.JpegContent")))
@interface LMDMessageContentJpegContent : LMDMessageContent
- (instancetype)initWithJpegByteString:(LMDKotlinx_io_bytestringByteString *)jpegByteString __attribute__((swift_name("init(jpegByteString:)"))) __attribute__((objc_designated_initializer));
@property (readonly) LMDKotlinx_io_bytestringByteString *jpegByteString __attribute__((swift_name("jpegByteString")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageContent.StringContent")))
@interface LMDMessageContentStringContent : LMDMessageContent
- (instancetype)initWithText:(NSString *)text __attribute__((swift_name("init(text:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *text __attribute__((swift_name("text")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageContent.WavContent")))
@interface LMDMessageContentWavContent : LMDMessageContent
- (instancetype)initWithWavByteString:(LMDKotlinx_io_bytestringByteString *)wavByteString __attribute__((swift_name("init(wavByteString:)"))) __attribute__((objc_designated_initializer));
@property (readonly) LMDKotlinx_io_bytestringByteString *wavByteString __attribute__((swift_name("wavByteString")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SamplerParams")))
@interface LMDSamplerParams : LMDBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property LMDFloat * _Nullable minP __attribute__((swift_name("minP")));
@property LMDLong * _Nullable randomSeed __attribute__((swift_name("randomSeed")));
@property LMDFloat * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));
@property LMDFloat * _Nullable temperature __attribute__((swift_name("temperature")));
@property LMDInt * _Nullable topK __attribute__((swift_name("topK")));
@property LMDFloat * _Nullable topP __attribute__((swift_name("topP")));
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
@interface LMDTokenProcessor : LMDBase
- (instancetype)initWithCallback:(id<LMDModelRunnerGenerationCallback>)callback functionCallParser:(LMDLeapFunctionCallParser * _Nullable)functionCallParser inlineThinking:(BOOL)inlineThinking __attribute__((swift_name("init(callback:functionCallParser:inlineThinking:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDTokenProcessorCompanion *companion __attribute__((swift_name("companion")));

/**
 * Process a single token from the inference engine.
 *
 * @param chunk The token string (null tokens are silently ignored)
 * @param isSpecial Whether the token is marked as special by the inference engine
 */
- (void)processTokenChunk:(NSString * _Nullable)chunk isSpecial:(BOOL)isSpecial __attribute__((swift_name("processToken(chunk:isSpecial:)")));
@property (readonly) LMDKotlinStringBuilder *buffer __attribute__((swift_name("buffer")));
@property (readonly) NSMutableArray<LMDLeapFunctionCall *> *functionCallBuffer __attribute__((swift_name("functionCallBuffer")));
@property (readonly) LMDKotlinStringBuilder *reasoningBuffer __attribute__((swift_name("reasoningBuffer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenProcessor.Companion")))
@interface LMDTokenProcessorCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDTokenProcessorCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *REASONING_END_TAG __attribute__((swift_name("REASONING_END_TAG")));
@property (readonly) NSString *REASONING_START_TAG __attribute__((swift_name("REASONING_START_TAG")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.0")
*/
__attribute__((swift_name("KotlinAutoCloseable")))
@protocol LMDKotlinAutoCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((swift_name("Kotlinx_io_coreRawSink")))
@protocol LMDKotlinx_io_coreRawSink <LMDKotlinAutoCloseable>
@required
- (void)flush __attribute__((swift_name("flush()")));
- (void)writeSource:(LMDKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
@end


/**
 * A RawSink implementation that consumes incoming bytes to compute a SHA-256 hash.
 *
 * This sink is a passthrough for hashing purposes only: it does not forward data to any underlying
 * sink and simply discards written bytes after updating the digest.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Sha256Sink")))
@interface LMDSha256Sink : LMDBase <LMDKotlinx_io_coreRawSink>

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
- (LMDKotlinByteArray * _Nullable)hashBytes __attribute__((swift_name("hashBytes()")));

/**
 * Returns the current SHA-256 hash of the bytes written so far as a lowercase hex string. If the
 * sink has been closed, returns the finalized hash; otherwise attempts to compute a snapshot
 * using a clone of the digest. If cloning isn't supported, the hash will be computed only after
 * [close] is called.
 */
- (NSString *)hashHex __attribute__((swift_name("hashHex()")));
- (void)writeSource:(LMDKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));

/** Total number of bytes written to this sink. */
@property (readonly) int64_t bytesWritten __attribute__((swift_name("bytesWritten")));
@end

__attribute__((swift_name("Kotlinx_io_coreRawSource")))
@protocol LMDKotlinx_io_coreRawSource <LMDKotlinAutoCloseable>
@required
- (int64_t)readAtMostToSink:(LMDKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
@end


/**
 * A RawSource wrapper that computes a SHA-256 hash of the bytes read from an underlying source.
 *
 * This source reads from [delegate], updates the digest with the read bytes and then forwards the
 * same data to the caller-provided [Buffer].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Sha256Source")))
@interface LMDSha256Source : LMDBase <LMDKotlinx_io_coreRawSource>
- (instancetype)initWithDelegate:(id<LMDKotlinx_io_coreRawSource>)delegate __attribute__((swift_name("init(delegate:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));

/**
 * Returns the current SHA-256 hash bytes. If closed, returns the finalized value; otherwise tries
 * to compute a snapshot using a copy of the digest. If not supported, returns null.
 */
- (LMDKotlinByteArray * _Nullable)hashBytes __attribute__((swift_name("hashBytes()")));

/**
 * Returns the current SHA-256 hash as a lowercase hex string. If closed, returns the finalized
 * hash; otherwise attempts to compute a snapshot using a copy of the digest.
 */
- (NSString *)hashHex __attribute__((swift_name("hashHex()")));
- (int64_t)readAtMostToSink:(LMDKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));

/** Total number of bytes read from this source. */
@property (readonly) int64_t bytesRead __attribute__((swift_name("bytesRead")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationTimeParameters")))
@interface LMDGenerationTimeParameters : LMDBase
- (instancetype)initWithSamplingParameters:(LMDSamplingParameters * _Nullable)samplingParameters numberOfDecodingThreads:(LMDInt * _Nullable)numberOfDecodingThreads __attribute__((swift_name("init(samplingParameters:numberOfDecodingThreads:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDGenerationTimeParametersCompanion *companion __attribute__((swift_name("companion")));
- (LMDGenerationTimeParameters *)doCopySamplingParameters:(LMDSamplingParameters * _Nullable)samplingParameters numberOfDecodingThreads:(LMDInt * _Nullable)numberOfDecodingThreads __attribute__((swift_name("doCopy(samplingParameters:numberOfDecodingThreads:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="number_of_decoding_threads")
*/
@property (readonly) LMDInt * _Nullable numberOfDecodingThreads __attribute__((swift_name("numberOfDecodingThreads")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="sampling_parameters")
*/
@property (readonly) LMDSamplingParameters * _Nullable samplingParameters __attribute__((swift_name("samplingParameters")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationTimeParameters.Companion")))
@interface LMDGenerationTimeParametersCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDGenerationTimeParametersCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Base type for variant-specific load time parameters.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("LoadTimeParameters")))
@protocol LMDLoadTimeParameters
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
@interface LMDImageToTextLoadParams : LMDBase <LMDLoadTimeParameters>
- (instancetype)initWithChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector __attribute__((swift_name("init(chatTemplate:model:multimodalProjector:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDImageToTextLoadParamsCompanion *companion __attribute__((swift_name("companion")));
- (LMDImageToTextLoadParams *)doCopyChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector __attribute__((swift_name("doCopy(chatTemplate:model:multimodalProjector:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="chat_template")
*/
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model")
*/
@property (readonly) NSString *model __attribute__((swift_name("model")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="multimodal_projector")
*/
@property (readonly) NSString *multimodalProjector __attribute__((swift_name("multimodalProjector")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImageToTextLoadParams.Companion")))
@interface LMDImageToTextLoadParamsCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDImageToTextLoadParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** A model available from the Leap API
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapApiModel")))
@interface LMDLeapApiModel : LMDBase
- (instancetype)initWithName:(NSString *)name modelSlug:(NSString *)modelSlug description:(NSString * _Nullable)description quantizationSlugs:(NSArray<NSString *> *)quantizationSlugs quantizationTypes:(NSArray<NSString *> *)quantizationTypes organization:(NSString * _Nullable)organization size:(NSString * _Nullable)size platform:(NSArray<NSString *> * _Nullable)platform __attribute__((swift_name("init(name:modelSlug:description:quantizationSlugs:quantizationTypes:organization:size:platform:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapApiModelCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapApiModel *)doCopyName:(NSString *)name modelSlug:(NSString *)modelSlug description:(NSString * _Nullable)description quantizationSlugs:(NSArray<NSString *> *)quantizationSlugs quantizationTypes:(NSArray<NSString *> *)quantizationTypes organization:(NSString * _Nullable)organization size:(NSString * _Nullable)size platform:(NSArray<NSString *> * _Nullable)platform __attribute__((swift_name("doCopy(name:modelSlug:description:quantizationSlugs:quantizationTypes:organization:size:platform:)")));

/** A model available from the Leap API */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** A model available from the Leap API */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** A model available from the Leap API */
- (NSString *)description __attribute__((swift_name("description()")));

/** Description of the model */
@property (readonly) NSString * _Nullable description_ __attribute__((swift_name("description_")));

/** Model identifier (e.g., "lfm2-1.2b")
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model_slug")
*/
@property (readonly) NSString *modelSlug __attribute__((swift_name("modelSlug")));

/** Display name of the model */
@property (readonly) NSString *name __attribute__((swift_name("name")));

/** Organization that published the model */
@property (readonly) NSString * _Nullable organization __attribute__((swift_name("organization")));

/** Supported platforms */
@property (readonly) NSArray<NSString *> * _Nullable platform __attribute__((swift_name("platform")));

/** List of available quantization slugs
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="quantization_slugs")
*/
@property (readonly) NSArray<NSString *> *quantizationSlugs __attribute__((swift_name("quantizationSlugs")));

/** List of quantization type names (e.g., "Q4_0", "Q8_0")
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="quantization_types")
*/
@property (readonly) NSArray<NSString *> *quantizationTypes __attribute__((swift_name("quantizationTypes")));

/** Model size (e.g., "1.2B", "700M") */
@property (readonly) NSString * _Nullable size __attribute__((swift_name("size")));
@end


/** A model available from the Leap API */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapApiModel.Companion")))
@interface LMDLeapApiModelCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** A model available from the Leap API */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapApiModelCompanion *shared __attribute__((swift_name("shared")));

/** A model available from the Leap API */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader")))
@interface LMDLeapDownloader : LMDBase
- (instancetype)initWithConfig:(LMDLeapDownloaderConfig *)config httpClient:(LMDKtor_client_coreHttpClient * _Nullable)httpClient __attribute__((swift_name("init(config:httpClient:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapDownloaderCompanion *companion __attribute__((swift_name("companion")));

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
- (void)downloadModelModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug progress:(void (^)(LMDProgressData *))progress completionHandler:(void (^)(LMDManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("downloadModel(modelName:quantizationSlug:progress:completionHandler:)")));

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
- (void)downloadModelFromManifestUrlManifestUrl:(NSString *)manifestUrl progress:(void (^)(LMDProgressData *))progress completionHandler:(void (^)(LMDManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("downloadModelFromManifestUrl(manifestUrl:progress:completionHandler:)")));
- (NSString * _Nullable)getCachedFilePathModelUrl:(NSString *)modelUrl modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("getCachedFilePath(modelUrl:modelName:quantizationSlug:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCachedManifestModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LMDManifest * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getCachedManifest(modelName:quantizationSlug:completionHandler:)")));

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
- (void)getModelSizeModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LMDLong * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getModelSize(modelName:quantizationSlug:completionHandler:)")));

/** Creates the path of the file that should be saved to disk from the url of a resource */
- (NSString *)getPathFromUrlUrl:(NSString *)url manifestUrl:(NSString *)manifestUrl modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("getPathFromUrl(url:manifestUrl:modelName:quantizationSlug:)")));
- (NSString *)getResourceFolderModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("getResourceFolder(modelName:quantizationSlug:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)loadModelModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug modelLoadingOptions:(LMDModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters forceDownload:(BOOL)forceDownload isRetry:(BOOL)isRetry progress:(void (^)(LMDProgressData *))progress completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModel(modelName:quantizationSlug:modelLoadingOptions:generationTimeParameters:forceDownload:isRetry:progress:completionHandler:)")));

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
- (void)loadModelFromManifestUrlManifestUrl:(NSString *)manifestUrl modelLoadingOptions:(LMDModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters progress:(void (^)(LMDProgressData *))progress completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadModelFromManifestUrl(manifestUrl:modelLoadingOptions:generationTimeParameters:progress:completionHandler:)")));

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
- (void)loadSimpleModelModel:(LMDModelSource *)model modelLoadingOptions:(LMDModelLoadingOptions * _Nullable)modelLoadingOptions generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters isRetry:(BOOL)isRetry progress:(void (^)(LMDProgressData *))progress completionHandler:(void (^)(id<LMDModelRunner> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("loadSimpleModel(model:modelLoadingOptions:generationTimeParameters:isRetry:progress:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resolveModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LMDManifest * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("resolve(modelName:quantizationSlug:completionHandler:)")));

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
- (void)resolveDownloadPlanModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LMDLeapDownloaderResolvedManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resolveDownloadPlan(modelName:quantizationSlug:completionHandler:)")));

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
- (void)resolveDownloadPlanFromManifestUrlManifestUrl:(NSString *)manifestUrl completionHandler:(void (^)(LMDLeapDownloaderResolvedManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resolveDownloadPlanFromManifestUrl(manifestUrl:completionHandler:)")));

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
- (void)saveManifestToDiskManifest:(LMDManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug completionHandler:(void (^)(LMDManifest * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("saveManifestToDisk(manifest:modelName:quantizationSlug:completionHandler:)")));
@property (readonly) LMDLeapDownloaderConfig *config __attribute__((swift_name("config")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader.Companion")))
@interface LMDLeapDownloaderCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapDownloaderCompanion *shared __attribute__((swift_name("shared")));
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
@interface LMDLeapDownloaderResolvedManifest : LMDBase
- (instancetype)initWithManifest:(LMDManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug resources:(NSArray<LMDLeapDownloaderResolvedResource *> *)resources __attribute__((swift_name("init(manifest:modelName:quantizationSlug:resources:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapDownloaderResolvedManifest *)doCopyManifest:(LMDManifest *)manifest modelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug resources:(NSArray<LMDLeapDownloaderResolvedResource *> *)resources __attribute__((swift_name("doCopy(manifest:modelName:quantizationSlug:resources:)")));

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
@property (readonly) LMDManifest *manifest __attribute__((swift_name("manifest")));
@property (readonly) NSString *modelName __attribute__((swift_name("modelName")));
@property (readonly) NSString *quantizationSlug __attribute__((swift_name("quantizationSlug")));
@property (readonly) NSArray<LMDLeapDownloaderResolvedResource *> *resources __attribute__((swift_name("resources")));
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
@interface LMDLeapDownloaderResolvedResource : LMDBase
- (instancetype)initWithRemoteUrl:(NSString *)remoteUrl localPath:(NSString *)localPath expectedSize:(LMDLong * _Nullable)expectedSize expectedSha256:(NSString * _Nullable)expectedSha256 isCached:(BOOL)isCached __attribute__((swift_name("init(remoteUrl:localPath:expectedSize:expectedSha256:isCached:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapDownloaderResolvedResource *)doCopyRemoteUrl:(NSString *)remoteUrl localPath:(NSString *)localPath expectedSize:(LMDLong * _Nullable)expectedSize expectedSha256:(NSString * _Nullable)expectedSha256 isCached:(BOOL)isCached __attribute__((swift_name("doCopy(remoteUrl:localPath:expectedSize:expectedSha256:isCached:)")));

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
@property (readonly) NSString * _Nullable expectedSha256 __attribute__((swift_name("expectedSha256")));
@property (readonly) LMDLong * _Nullable expectedSize __attribute__((swift_name("expectedSize")));
@property (readonly) BOOL isCached __attribute__((swift_name("isCached")));
@property (readonly) NSString *localPath __attribute__((swift_name("localPath")));
@property (readonly) NSString *remoteUrl __attribute__((swift_name("remoteUrl")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader.SavedFileInfo")))
@interface LMDLeapDownloaderSavedFileInfo : LMDBase
- (instancetype)initWithSha256:(NSString *)sha256 filepath:(LMDKotlinx_io_corePath *)filepath bytesSaved:(int64_t)bytesSaved __attribute__((swift_name("init(sha256:filepath:bytesSaved:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapDownloaderSavedFileInfo *)doCopySha256:(NSString *)sha256 filepath:(LMDKotlinx_io_corePath *)filepath bytesSaved:(int64_t)bytesSaved __attribute__((swift_name("doCopy(sha256:filepath:bytesSaved:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t bytesSaved __attribute__((swift_name("bytesSaved")));
@property (readonly) LMDKotlinx_io_corePath *filepath __attribute__((swift_name("filepath")));
@property (readonly) NSString *sha256 __attribute__((swift_name("sha256")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloaderConfig")))
@interface LMDLeapDownloaderConfig : LMDBase
- (instancetype)initWithSaveDir:(NSString *)saveDir validateSha256:(BOOL)validateSha256 disableSslValidation:(BOOL)disableSslValidation baseUrl:(NSString * _Nullable)baseUrl connectTimeoutMillis:(int64_t)connectTimeoutMillis socketTimeoutMillis:(int64_t)socketTimeoutMillis requestTimeoutMillis:(int64_t)requestTimeoutMillis __attribute__((swift_name("init(saveDir:validateSha256:disableSslValidation:baseUrl:connectTimeoutMillis:socketTimeoutMillis:requestTimeoutMillis:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapDownloaderConfig *)doCopySaveDir:(NSString *)saveDir validateSha256:(BOOL)validateSha256 disableSslValidation:(BOOL)disableSslValidation baseUrl:(NSString * _Nullable)baseUrl connectTimeoutMillis:(int64_t)connectTimeoutMillis socketTimeoutMillis:(int64_t)socketTimeoutMillis requestTimeoutMillis:(int64_t)requestTimeoutMillis __attribute__((swift_name("doCopy(saveDir:validateSha256:disableSslValidation:baseUrl:connectTimeoutMillis:socketTimeoutMillis:requestTimeoutMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Only for testing: Override the base URL for manifest API (default: https://leap.liquid.ai) */
@property (readonly) NSString * _Nullable baseUrl __attribute__((swift_name("baseUrl")));

/** HTTP connect timeout in milliseconds (default: 30 seconds) */
@property (readonly) int64_t connectTimeoutMillis __attribute__((swift_name("connectTimeoutMillis")));

/** Only for testing: Disables SSL certificate validation (useful for iOS simulator) */
@property (readonly) BOOL disableSslValidation __attribute__((swift_name("disableSslValidation")));

/** HTTP request timeout in milliseconds (default: 10 minutes) */
@property (readonly) int64_t requestTimeoutMillis __attribute__((swift_name("requestTimeoutMillis")));
@property (readonly) NSString *saveDir __attribute__((swift_name("saveDir")));

/** HTTP socket/read timeout in milliseconds (default: 60 seconds) */
@property (readonly) int64_t socketTimeoutMillis __attribute__((swift_name("socketTimeoutMillis")));
@property (readonly) BOOL validateSha256 __attribute__((swift_name("validateSha256")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapManifestProcessorConfig")))
@interface LMDLeapManifestProcessorConfig : LMDBase
- (instancetype)initWithTargetDir:(NSString *)targetDir validateSha256:(BOOL)validateSha256 offlineMode:(BOOL)offlineMode __attribute__((swift_name("init(targetDir:validateSha256:offlineMode:)"))) __attribute__((objc_designated_initializer));
- (LMDLeapManifestProcessorConfig *)doCopyTargetDir:(NSString *)targetDir validateSha256:(BOOL)validateSha256 offlineMode:(BOOL)offlineMode __attribute__((swift_name("doCopy(targetDir:validateSha256:offlineMode:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL offlineMode __attribute__((swift_name("offlineMode")));
@property (readonly) NSString *targetDir __attribute__((swift_name("targetDir")));
@property (readonly) BOOL validateSha256 __attribute__((swift_name("validateSha256")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelManifestResponse")))
@interface LMDLeapModelManifestResponse : LMDBase
- (instancetype)initWithManifest_url:(NSString *)manifest_url __attribute__((swift_name("init(manifest_url:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapModelManifestResponseCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapModelManifestResponse *)doCopyManifest_url:(NSString *)manifest_url __attribute__((swift_name("doCopy(manifest_url:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *manifest_url __attribute__((swift_name("manifest_url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelManifestResponse.Companion")))
@interface LMDLeapModelManifestResponseCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapModelManifestResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Client for fetching available models from the Leap API */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelsApi")))
@interface LMDLeapModelsApi : LMDBase <LMDKotlinAutoCloseable>
- (instancetype)initWithBaseUrl:(NSString *)baseUrl httpClient:(LMDKtor_client_coreHttpClient * _Nullable)httpClient __attribute__((swift_name("init(baseUrl:httpClient:)"))) __attribute__((objc_designated_initializer));

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
- (void)fetchAvailableModelsInferenceEngine:(NSString *)inferenceEngine completionHandler:(void (^)(NSArray<LMDLeapApiModel *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("fetchAvailableModels(inferenceEngine:completionHandler:)")));
@end


/** Response from the Leap models API
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelsResponse")))
@interface LMDLeapModelsResponse : LMDBase
- (instancetype)initWithModels:(NSArray<LMDLeapApiModel *> *)models __attribute__((swift_name("init(models:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLeapModelsResponseCompanion *companion __attribute__((swift_name("companion")));
- (LMDLeapModelsResponse *)doCopyModels:(NSArray<LMDLeapApiModel *> *)models __attribute__((swift_name("doCopy(models:)")));

/** Response from the Leap models API */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Response from the Leap models API */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Response from the Leap models API */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<LMDLeapApiModel *> *models __attribute__((swift_name("models")));
@end


/** Response from the Leap models API */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapModelsResponse.Companion")))
@interface LMDLeapModelsResponseCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** Response from the Leap models API */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLeapModelsResponseCompanion *shared __attribute__((swift_name("shared")));

/** Response from the Leap models API */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="llama.cpp/lfm2-audio-v1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Lfm2AudioV1LoadParams")))
@interface LMDLfm2AudioV1LoadParams : LMDBase <LMDLoadTimeParameters>
- (instancetype)initWithChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector audioDecoder:(NSString *)audioDecoder audioTokenizer:(NSString *)audioTokenizer __attribute__((swift_name("init(chatTemplate:model:multimodalProjector:audioDecoder:audioTokenizer:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDLfm2AudioV1LoadParamsCompanion *companion __attribute__((swift_name("companion")));
- (LMDLfm2AudioV1LoadParams *)doCopyChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model multimodalProjector:(NSString *)multimodalProjector audioDecoder:(NSString *)audioDecoder audioTokenizer:(NSString *)audioTokenizer __attribute__((swift_name("doCopy(chatTemplate:model:multimodalProjector:audioDecoder:audioTokenizer:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="audio_decoder")
*/
@property (readonly) NSString *audioDecoder __attribute__((swift_name("audioDecoder")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="audio_tokenizer")
*/
@property (readonly) NSString *audioTokenizer __attribute__((swift_name("audioTokenizer")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="chat_template")
*/
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model")
*/
@property (readonly) NSString *model __attribute__((swift_name("model")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="multimodal_projector")
*/
@property (readonly) NSString *multimodalProjector __attribute__((swift_name("multimodalProjector")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Lfm2AudioV1LoadParams.Companion")))
@interface LMDLfm2AudioV1LoadParamsCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLfm2AudioV1LoadParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Base type for variant-specific load time parameters. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LoadTimeParametersCompanion")))
@interface LMDLoadTimeParametersCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** Base type for variant-specific load time parameters. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDLoadTimeParametersCompanion *shared __attribute__((swift_name("shared")));

/** Base type for variant-specific load time parameters. */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));

/** Base type for variant-specific load time parameters. */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LMDKotlinArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
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
@interface LMDManifest : LMDBase
- (instancetype)initWithSchemaVersion:(NSString *)schemaVersion inferenceType:(NSString *)inferenceType loadTimeParameters:(id<LMDLoadTimeParameters>)loadTimeParameters generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters originalUrl:(NSString * _Nullable)originalUrl pathOnDisk:(NSString * _Nullable)pathOnDisk __attribute__((swift_name("init(schemaVersion:inferenceType:loadTimeParameters:generationTimeParameters:originalUrl:pathOnDisk:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDManifestCompanion *companion __attribute__((swift_name("companion")));
- (LMDManifest *)doCopySchemaVersion:(NSString *)schemaVersion inferenceType:(NSString *)inferenceType loadTimeParameters:(id<LMDLoadTimeParameters>)loadTimeParameters generationTimeParameters:(LMDGenerationTimeParameters * _Nullable)generationTimeParameters originalUrl:(NSString * _Nullable)originalUrl pathOnDisk:(NSString * _Nullable)pathOnDisk __attribute__((swift_name("doCopy(schemaVersion:inferenceType:loadTimeParameters:generationTimeParameters:originalUrl:pathOnDisk:)")));

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
@property (readonly) LMDGenerationTimeParameters * _Nullable generationTimeParameters __attribute__((swift_name("generationTimeParameters")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="inference_type")
*/
@property (readonly) NSString *inferenceType __attribute__((swift_name("inferenceType")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="load_time_parameters")
*/
@property (readonly) id<LMDLoadTimeParameters> loadTimeParameters __attribute__((swift_name("loadTimeParameters")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="original_url")
*/
@property (readonly) NSString * _Nullable originalUrl __attribute__((swift_name("originalUrl")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="path_on_disk")
*/
@property (readonly) NSString * _Nullable pathOnDisk __attribute__((swift_name("pathOnDisk")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="schema_version")
*/
@property (readonly) NSString *schemaVersion __attribute__((swift_name("schemaVersion")));
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
@interface LMDManifestCompanion : LMDBase
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
@property (class, readonly, getter=shared) LMDManifestCompanion *shared __attribute__((swift_name("shared")));

/**
 * Data models for deserializing the inference configuration defined by schema.json.
 *
 * Implements custom polymorphism: `load_time_parameters` is decoded based on the sibling field
 * `inference_type` (e.g. "llama.cpp/text-to-text", "llama.cpp/image-to-text",
 * "llama.cpp/lfm2-audio-v1").
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
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
@interface LMDModelSource : LMDBase
- (instancetype)initWithModelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath modelName:(NSString *)modelName quantizationId:(NSString *)quantizationId __attribute__((swift_name("init(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:modelName:quantizationId:)"))) __attribute__((objc_designated_initializer));
- (LMDModelSource *)doCopyModelPath:(NSString *)modelPath mmprojPath:(NSString * _Nullable)mmprojPath audioDecoderPath:(NSString * _Nullable)audioDecoderPath audioTokenizerPath:(NSString * _Nullable)audioTokenizerPath modelName:(NSString *)modelName quantizationId:(NSString *)quantizationId __attribute__((swift_name("doCopy(modelPath:mmprojPath:audioDecoderPath:audioTokenizerPath:modelName:quantizationId:)")));

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
@property (readonly) NSString * _Nullable audioDecoderPath __attribute__((swift_name("audioDecoderPath")));
@property (readonly) NSString * _Nullable audioTokenizerPath __attribute__((swift_name("audioTokenizerPath")));
@property (readonly) NSArray<NSString *> *downloads __attribute__((swift_name("downloads")));
@property (readonly) NSString * _Nullable mmprojPath __attribute__((swift_name("mmprojPath")));
@property (readonly) NSString *modelName __attribute__((swift_name("modelName")));
@property (readonly) NSString *modelPath __attribute__((swift_name("modelPath")));
@property (readonly) NSString *quantizationId __attribute__((swift_name("quantizationId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressData")))
@interface LMDProgressData : LMDBase
- (instancetype)initWithBytes:(int64_t)bytes total:(int64_t)total __attribute__((swift_name("init(bytes:total:)"))) __attribute__((objc_designated_initializer));
- (LMDProgressData *)doCopyBytes:(int64_t)bytes total:(int64_t)total __attribute__((swift_name("doCopy(bytes:total:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t bytes __attribute__((swift_name("bytes")));
@property (readonly) float progress __attribute__((swift_name("progress")));
@property (readonly) int64_t total __attribute__((swift_name("total")));
@end


/**
 * A RawSink wrapper that reports progress to a listener.
 *
 * @param delegate The underlying RawSink to which the data is actually written.
 * @param progressListener A lambda function that receives the total number of bytes written so far.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSink")))
@interface LMDProgressReportingSink : LMDBase <LMDKotlinx_io_coreRawSink>
- (instancetype)initWithDelegate:(id<LMDKotlinx_io_coreRawSink>)delegate progressListener:(void (^)(LMDLong *))progressListener __attribute__((swift_name("init(delegate:progressListener:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (void)flush __attribute__((swift_name("flush()")));
- (void)writeSource:(LMDKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
@end


/**
 * A RawSource wrapper that reports progress to a listener.
 *
 * @param delegate The underlying RawSource from which the data is actually read.
 * @param progressListener A lambda function that receives the total number of bytes read so far.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSource")))
@interface LMDProgressReportingSource : LMDBase <LMDKotlinx_io_coreRawSource>
- (instancetype)initWithDelegate:(id<LMDKotlinx_io_coreRawSource>)delegate progressListener:(void (^)(LMDLong *))progressListener __attribute__((swift_name("init(delegate:progressListener:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (int64_t)readAtMostToSink:(LMDKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SamplingParameters")))
@interface LMDSamplingParameters : LMDBase
- (instancetype)initWithTemperature:(LMDDouble * _Nullable)temperature topP:(LMDDouble * _Nullable)topP minP:(LMDDouble * _Nullable)minP repetitionPenalty:(LMDDouble * _Nullable)repetitionPenalty topK:(LMDInt * _Nullable)topK __attribute__((swift_name("init(temperature:topP:minP:repetitionPenalty:topK:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDSamplingParametersCompanion *companion __attribute__((swift_name("companion")));
- (LMDSamplingParameters *)doCopyTemperature:(LMDDouble * _Nullable)temperature topP:(LMDDouble * _Nullable)topP minP:(LMDDouble * _Nullable)minP repetitionPenalty:(LMDDouble * _Nullable)repetitionPenalty topK:(LMDInt * _Nullable)topK __attribute__((swift_name("doCopy(temperature:topP:minP:repetitionPenalty:topK:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="min_p")
*/
@property (readonly) LMDDouble * _Nullable minP __attribute__((swift_name("minP")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="repetition_penalty")
*/
@property (readonly) LMDDouble * _Nullable repetitionPenalty __attribute__((swift_name("repetitionPenalty")));
@property (readonly) LMDDouble * _Nullable temperature __attribute__((swift_name("temperature")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="top_k")
*/
@property (readonly) LMDInt * _Nullable topK __attribute__((swift_name("topK")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="top_p")
*/
@property (readonly) LMDDouble * _Nullable topP __attribute__((swift_name("topP")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SamplingParameters.Companion")))
@interface LMDSamplingParametersCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDSamplingParametersCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Custom serializer that inspects `inference_type` to choose the correct subtype for
 * `load_time_parameters`.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SchemaSerializer")))
@interface LMDSchemaSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Custom serializer that inspects `inference_type` to choose the correct subtype for
 * `load_time_parameters`.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)schemaSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDSchemaSerializer *shared __attribute__((swift_name("shared")));
- (LMDManifest *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(LMDManifest *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="llama.cpp/text-to-text")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextToTextLoadParams")))
@interface LMDTextToTextLoadParams : LMDBase <LMDLoadTimeParameters>
- (instancetype)initWithChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model __attribute__((swift_name("init(chatTemplate:model:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDTextToTextLoadParamsCompanion *companion __attribute__((swift_name("companion")));
- (LMDTextToTextLoadParams *)doCopyChatTemplate:(NSString * _Nullable)chatTemplate model:(NSString *)model __attribute__((swift_name("doCopy(chatTemplate:model:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="chat_template")
*/
@property (readonly) NSString * _Nullable chatTemplate __attribute__((swift_name("chatTemplate")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="model")
*/
@property (readonly) NSString *model __attribute__((swift_name("model")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TextToTextLoadParams.Companion")))
@interface LMDTextToTextLoadParamsCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDTextToTextLoadParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** A chat message in the chat history.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/message/ChatMessageJsonSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage")))
@interface LMDChatMessage : LMDBase

/**
 * Single content constructor.
 *
 * @param role the role of this message
 * @param content the message content
 */
- (instancetype)initWithRole:(LMDChatMessageRole *)role content:(LMDChatMessageContent *)content __attribute__((swift_name("init(role:content:)"))) __attribute__((objc_designated_initializer));

/**
 * Single text content constructor.
 *
 * @param role the role of this message
 * @param textContent the message text content
 */
- (instancetype)initWithRole:(LMDChatMessageRole *)role textContent:(NSString *)textContent __attribute__((swift_name("init(role:textContent:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithRole:(LMDChatMessageRole *)role content:(NSArray<LMDChatMessageContent *> *)content reasoningContent:(NSString * _Nullable)reasoningContent functionCalls:(NSArray<LMDLeapFunctionCall *> * _Nullable)functionCalls __attribute__((swift_name("init(role:content:reasoningContent:functionCalls:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageCompanion *companion __attribute__((swift_name("companion")));
- (LMDChatMessage *)doCopyRole:(LMDChatMessageRole *)role content:(NSArray<LMDChatMessageContent *> *)content reasoningContent:(NSString * _Nullable)reasoningContent functionCalls:(NSArray<LMDLeapFunctionCall *> * _Nullable)functionCalls __attribute__((swift_name("doCopy(role:content:reasoningContent:functionCalls:)")));

/** A chat message in the chat history. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** A chat message in the chat history. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** A chat message in the chat history. */
- (NSString *)description __attribute__((swift_name("description()")));

/** The list of contents of this message. */
@property (readonly) NSArray<LMDChatMessageContent *> *content __attribute__((swift_name("content")));

/**
 * Function calls requested by the model. This field is only valid for models that support tool
 * calls.
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="tool_calls")
*/
@property (readonly) NSArray<LMDLeapFunctionCall *> * _Nullable functionCalls __attribute__((swift_name("functionCalls")));

/**
 * Reasoning content of this message. Reasoning content is only valid for messages generated by
 * the models.
 *
 * @note annotations
 *   kotlinx.serialization.SerialName(value="reasoning_content")
*/
@property (readonly) NSString * _Nullable reasoningContent __attribute__((swift_name("reasoningContent")));

/** The role of this message. */
@property (readonly) LMDChatMessageRole *role __attribute__((swift_name("role")));
@end


/** A chat message in the chat history. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage.Companion")))
@interface LMDChatMessageCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** A chat message in the chat history. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageCompanion *shared __attribute__((swift_name("shared")));

/** A chat message in the chat history. */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Role of the message. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage.Role")))
@interface LMDChatMessageRole : LMDKotlinEnum<LMDChatMessageRole *>
+ (instancetype)alloc __attribute__((unavailable));

/** Role of the message. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDChatMessageRoleCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LMDChatMessageRole *system __attribute__((swift_name("system")));
@property (class, readonly) LMDChatMessageRole *user __attribute__((swift_name("user")));
@property (class, readonly) LMDChatMessageRole *assistant __attribute__((swift_name("assistant")));
@property (class, readonly) LMDChatMessageRole *tool __attribute__((swift_name("tool")));
+ (LMDKotlinArray<LMDChatMessageRole *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDChatMessageRole *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessage.RoleCompanion")))
@interface LMDChatMessageRoleCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageRoleCompanion *shared __attribute__((swift_name("shared")));

/**
 * Create a Role value from a string literal.
 *
 * @param type string literal for the role value, compatible with OpenAI API.
 * @throws LeapSerializationException if the role string literal is not supported
 */
- (LMDChatMessageRole *)fromTypeStringType:(NSString *)type __attribute__((swift_name("fromTypeString(type:)")));
@end


/** Interface for all message content classes
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((swift_name("ChatMessageContent")))
@interface LMDChatMessageContent : LMDBase
@property (class, readonly, getter=companion) LMDChatMessageContentCompanion *companion __attribute__((swift_name("companion")));
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
@interface LMDChatMessageContentAudio : LMDChatMessageContent
- (instancetype)initWithInputAudio:(LMDChatMessageContentAudioInputAudio *)inputAudio __attribute__((swift_name("init(inputAudio:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithData:(LMDKotlinByteArray *)data __attribute__((swift_name("init(data:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageContentAudioCompanion *companion __attribute__((swift_name("companion")));
- (LMDChatMessageContentAudio *)doCopyInputAudio:(LMDChatMessageContentAudioInputAudio *)inputAudio __attribute__((swift_name("doCopy(inputAudio:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) LMDKotlinByteArray *data __attribute__((swift_name("data")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="input_audio")
*/
@property (readonly) LMDChatMessageContentAudioInputAudio *inputAudio __attribute__((swift_name("inputAudio")));
@end


/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioCompanion")))
@interface LMDChatMessageContentAudioCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentAudioCompanion *shared __attribute__((swift_name("shared")));

/**
 * Audio content. The wire shape must be: { "type": "input_audio", "input_audio": { "data":
 * "<base64>", "format": "wav" } }
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioInputAudio")))
@interface LMDChatMessageContentAudioInputAudio : LMDBase
- (instancetype)initWithData:(LMDKotlinByteArray *)data format:(NSString *)format __attribute__((swift_name("init(data:format:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageContentAudioInputAudioCompanion *companion __attribute__((swift_name("companion")));
- (LMDChatMessageContentAudioInputAudio *)doCopyData:(LMDKotlinByteArray *)data format:(NSString *)format __attribute__((swift_name("doCopy(data:format:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=ai/liquid/leap/serialization/ByteArrayBase64Serializer))
*/
@property (readonly) LMDKotlinByteArray *data __attribute__((swift_name("data")));
@property (readonly) NSString *format __attribute__((swift_name("format")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.AudioInputAudioCompanion")))
@interface LMDChatMessageContentAudioInputAudioCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentAudioInputAudioCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
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
@interface LMDChatMessageContentAudioPcmF32 : LMDChatMessageContent
- (instancetype)initWithSamples:(LMDKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("init(samples:sampleRate:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageContentAudioPcmF32Companion *companion __attribute__((swift_name("companion")));
- (LMDChatMessageContentAudioPcmF32 *)doCopySamples:(LMDKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("doCopy(samples:sampleRate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Convert to the WAV-based [Audio] content type. */
- (LMDChatMessageContentAudio *)toAudio __attribute__((swift_name("toAudio()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Convert to WAV byte array for playback or file storage. */
- (LMDKotlinByteArray *)toWavBytes __attribute__((swift_name("toWavBytes()")));
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@property (readonly) LMDKotlinFloatArray *samples __attribute__((swift_name("samples")));
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
@interface LMDChatMessageContentAudioPcmF32Companion : LMDBase
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
@property (class, readonly, getter=shared) LMDChatMessageContentAudioPcmF32Companion *shared __attribute__((swift_name("shared")));

/**
 * Raw PCM float32 mono audio content. Used for engine-generated audio that needs to roundtrip
 * through conversation history without hash loss. User-provided audio (microphone recordings,
 * file uploads) should use [Audio] instead.
 *
 * @property samples Raw float32 PCM samples
 * @property sampleRate Sample rate in Hz (e.g. 24000)
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.Companion")))
@interface LMDChatMessageContentCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(LMDKotlinArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));

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
- (LMDChatMessageContentText *)textText:(NSString *)text __attribute__((swift_name("text(text:)")));
@property (readonly) NSString *JPEG_BASE64_DATA_URL_PREFIX __attribute__((swift_name("JPEG_BASE64_DATA_URL_PREFIX")));
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
@interface LMDChatMessageContentImage : LMDChatMessageContent
- (instancetype)initWithImageUrl:(LMDChatMessageContentImageImageUrl *)imageUrl __attribute__((swift_name("init(imageUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithJpegByteArray:(LMDKotlinByteArray *)jpegByteArray __attribute__((swift_name("init(jpegByteArray:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageContentImageCompanion *companion __attribute__((swift_name("companion")));
- (LMDChatMessageContentImage *)doCopyImageUrl:(LMDChatMessageContentImageImageUrl *)imageUrl __attribute__((swift_name("doCopy(imageUrl:)")));

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
@property (readonly) LMDChatMessageContentImageImageUrl *imageUrl __attribute__((swift_name("imageUrl")));
@property (readonly) LMDKotlinByteArray *jpegByteArray __attribute__((swift_name("jpegByteArray")));
@end


/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.ImageCompanion")))
@interface LMDChatMessageContentImageCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentImageCompanion *shared __attribute__((swift_name("shared")));

/**
 * Image content. The wire shape must be: { "type": "image_url", "image_url": { "url":
 * "data:image/jpeg;base64,<...>" } }
 */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.ImageImageUrl")))
@interface LMDChatMessageContentImageImageUrl : LMDBase
- (instancetype)initWithUrl:(NSString *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageContentImageImageUrlCompanion *companion __attribute__((swift_name("companion")));
- (LMDChatMessageContentImageImageUrl *)doCopyUrl:(NSString *)url __attribute__((swift_name("doCopy(url:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.ImageImageUrlCompanion")))
@interface LMDChatMessageContentImageImageUrlCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentImageImageUrlCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/** Pure text content.
 *
 * @note annotations
 *   kotlinx.serialization.Serializable
 *   kotlinx.serialization.SerialName(value="text")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.Text")))
@interface LMDChatMessageContentText : LMDChatMessageContent
- (instancetype)initWithText:(NSString *)text __attribute__((swift_name("init(text:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDChatMessageContentTextCompanion *companion __attribute__((swift_name("companion")));
- (LMDChatMessageContentText *)doCopyText:(NSString *)text __attribute__((swift_name("doCopy(text:)")));

/** Pure text content. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Pure text content. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Pure text content. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *text __attribute__((swift_name("text")));
@end


/** Pure text content. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContent.TextCompanion")))
@interface LMDChatMessageContentTextCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/** Pure text content. */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentTextCompanion *shared __attribute__((swift_name("shared")));

/** Pure text content. */
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Minimal serializer for ChatMessageContent.Audio that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContentAudioSerializer")))
@interface LMDChatMessageContentAudioSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Minimal serializer for ChatMessageContent.Audio that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageContentAudioSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentAudioSerializer *shared __attribute__((swift_name("shared")));
- (LMDChatMessageContentAudio *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(LMDChatMessageContentAudio *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * Minimal serializer for ChatMessageContent.Image that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageContentImageSerializer")))
@interface LMDChatMessageContentImageSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Minimal serializer for ChatMessageContent.Image that injects the discriminator `type` while
 * keeping standard sealed polymorphism (no base custom serializer).
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageContentImageSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageContentImageSerializer *shared __attribute__((swift_name("shared")));
- (LMDChatMessageContentImage *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(LMDChatMessageContentImage *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * Kotlinx serializer for [ChatMessage] that preserves the existing OpenAI-compatible JSON shape
 * without requiring an intermediate DTO.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChatMessageJsonSerializer")))
@interface LMDChatMessageJsonSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Kotlinx serializer for [ChatMessage] that preserves the existing OpenAI-compatible JSON shape
 * without requiring an intermediate DTO.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)chatMessageJsonSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDChatMessageJsonSerializer *shared __attribute__((swift_name("shared")));
- (LMDChatMessage *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(LMDChatMessage *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationFinishReason")))
@interface LMDGenerationFinishReason : LMDKotlinEnum<LMDGenerationFinishReason *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) LMDGenerationFinishReason *stop __attribute__((swift_name("stop")));
@property (class, readonly) LMDGenerationFinishReason *exceedContext __attribute__((swift_name("exceedContext")));
@property (class, readonly) LMDGenerationFinishReason *interrupted __attribute__((swift_name("interrupted")));
@property (class, readonly) LMDGenerationFinishReason *constraint __attribute__((swift_name("constraint")));
@property (class, readonly) LMDGenerationFinishReason *error __attribute__((swift_name("error")));
+ (LMDKotlinArray<LMDGenerationFinishReason *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDGenerationFinishReason *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenerationStats")))
@interface LMDGenerationStats : LMDBase
- (instancetype)initWithPromptTokens:(int64_t)promptTokens completionTokens:(int64_t)completionTokens totalTokens:(int64_t)totalTokens tokenPerSecond:(float)tokenPerSecond cachedPromptTokens:(int64_t)cachedPromptTokens __attribute__((swift_name("init(promptTokens:completionTokens:totalTokens:tokenPerSecond:cachedPromptTokens:)"))) __attribute__((objc_designated_initializer));
- (LMDGenerationStats *)doCopyPromptTokens:(int64_t)promptTokens completionTokens:(int64_t)completionTokens totalTokens:(int64_t)totalTokens tokenPerSecond:(float)tokenPerSecond cachedPromptTokens:(int64_t)cachedPromptTokens __attribute__((swift_name("doCopy(promptTokens:completionTokens:totalTokens:tokenPerSecond:cachedPromptTokens:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/** Number of prompt tokens restored from KV cache (not recomputed). */
@property (readonly) int64_t cachedPromptTokens __attribute__((swift_name("cachedPromptTokens")));

/** Number of tokens in the generated completion. */
@property (readonly) int64_t completionTokens __attribute__((swift_name("completionTokens")));

/** Number of prompt tokens that were computed (excludes tokens restored from KV cache). */
@property (readonly) int64_t promptTokens __attribute__((swift_name("promptTokens")));

/** Average number of generated tokens per second during the whole generation. */
@property (readonly) float tokenPerSecond __attribute__((swift_name("tokenPerSecond")));

/** Total number of tokens used in the request (prompt + completion). */
@property (readonly) int64_t totalTokens __attribute__((swift_name("totalTokens")));
@end


/** A piece of response from generation. */
__attribute__((swift_name("MessageResponse")))
@protocol LMDMessageResponse
@required
@end


/** Audio content generated by the model. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseAudioSample")))
@interface LMDMessageResponseAudioSample : LMDBase <LMDMessageResponse>
- (instancetype)initWithSamples:(LMDKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("init(samples:sampleRate:)"))) __attribute__((objc_designated_initializer));
- (LMDMessageResponseAudioSample *)doCopySamples:(LMDKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate __attribute__((swift_name("doCopy(samples:sampleRate:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t sampleRate __attribute__((swift_name("sampleRate")));
@property (readonly) LMDKotlinFloatArray *samples __attribute__((swift_name("samples")));
@end


/**
 * A chunk of generated output. The generation is still ongoing and its `text` field may contain
 * one or more tokens.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseChunk")))
@interface LMDMessageResponseChunk : LMDBase <LMDMessageResponse>
- (instancetype)initWithText:(NSString *)text __attribute__((swift_name("init(text:)"))) __attribute__((objc_designated_initializer));
- (LMDMessageResponseChunk *)doCopyText:(NSString *)text __attribute__((swift_name("doCopy(text:)")));

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
@property (readonly) NSString *text __attribute__((swift_name("text")));
@end


/** Indicates the generation is done. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseComplete")))
@interface LMDMessageResponseComplete : LMDBase <LMDMessageResponse>
- (instancetype)initWithFullMessage:(LMDChatMessage *)fullMessage finishReason:(LMDGenerationFinishReason *)finishReason stats:(LMDGenerationStats * _Nullable)stats __attribute__((swift_name("init(fullMessage:finishReason:stats:)"))) __attribute__((objc_designated_initializer));
- (LMDMessageResponseComplete *)doCopyFullMessage:(LMDChatMessage *)fullMessage finishReason:(LMDGenerationFinishReason *)finishReason stats:(LMDGenerationStats * _Nullable)stats __attribute__((swift_name("doCopy(fullMessage:finishReason:stats:)")));

/** Indicates the generation is done. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Indicates the generation is done. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Indicates the generation is done. */
- (NSString *)description __attribute__((swift_name("description()")));

/** The reason why generation finished. */
@property (readonly) LMDGenerationFinishReason *finishReason __attribute__((swift_name("finishReason")));

/** The complete message generated from this generation request. */
@property (readonly) LMDChatMessage *fullMessage __attribute__((swift_name("fullMessage")));

/** Statistics about this generation like how many prompt tokens and completion tokens. */
@property (readonly) LMDGenerationStats * _Nullable stats __attribute__((swift_name("stats")));
@end


/** Parsed function call content. Only models that support function calls can emit this chunk. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MessageResponseFunctionCalls")))
@interface LMDMessageResponseFunctionCalls : LMDBase <LMDMessageResponse>
- (instancetype)initWithFunctionCalls:(NSArray<LMDLeapFunctionCall *> *)functionCalls __attribute__((swift_name("init(functionCalls:)"))) __attribute__((objc_designated_initializer));
- (LMDMessageResponseFunctionCalls *)doCopyFunctionCalls:(NSArray<LMDLeapFunctionCall *> *)functionCalls __attribute__((swift_name("doCopy(functionCalls:)")));

/** Parsed function call content. Only models that support function calls can emit this chunk. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Parsed function call content. Only models that support function calls can emit this chunk. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Parsed function call content. Only models that support function calls can emit this chunk. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<LMDLeapFunctionCall *> *functionCalls __attribute__((swift_name("functionCalls")));
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
@interface LMDMessageResponseReasoningChunk : LMDBase <LMDMessageResponse>
- (instancetype)initWithReasoning:(NSString *)reasoning __attribute__((swift_name("init(reasoning:)"))) __attribute__((objc_designated_initializer));
- (LMDMessageResponseReasoningChunk *)doCopyReasoning:(NSString *)reasoning __attribute__((swift_name("doCopy(reasoning:)")));

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
@property (readonly) NSString *reasoning __attribute__((swift_name("reasoning")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArtifactVersion")))
@interface LMDArtifactVersion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)artifactVersion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDArtifactVersion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end


/**
 * Custom serializer for ByteArray that encodes/decodes using Base64.
 *
 * This is used for binary data like images and audio in chat messages, allowing them to be
 * transmitted as strings in JSON format.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ByteArrayBase64Serializer")))
@interface LMDByteArrayBase64Serializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Custom serializer for ByteArray that encodes/decodes using Base64.
 *
 * This is used for binary data like images and audio in chat messages, allowing them to be
 * transmitted as strings in JSON format.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)byteArrayBase64Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDByteArrayBase64Serializer *shared __attribute__((swift_name("shared")));
- (LMDKotlinByteArray *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(LMDKotlinByteArray *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * Custom serializer for Map<LeapStr, JsonElement>.
 *
 * This is used for flexible JSON arguments in function calls where the structure is not known at
 * compile time. The map can contain any JSON-compatible values.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonElementMapSerializer")))
@interface LMDJsonElementMapSerializer : LMDBase <LMDKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Custom serializer for Map<LeapStr, JsonElement>.
 *
 * This is used for flexible JSON arguments in function calls where the structure is not known at
 * compile time. The map can contain any JSON-compatible values.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jsonElementMapSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDJsonElementMapSerializer *shared __attribute__((swift_name("shared")));
- (NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)deserializeDecoder:(id<LMDKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<LMDKotlinx_serialization_coreEncoder>)encoder value:(NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<LMDKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GeneratableFactory")))
@interface LMDGeneratableFactory : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)generatableFactory __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDGeneratableFactory *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of LeapGeneratableDeserializationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (id _Nullable)createFromJsonObjectJsonObject:(NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)jsonObject error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("createFromJsonObject(jsonObject:)")));

/**
 * Create generatable object instances from JSON object.
 *
 * @param jsonObject JsonObject to be deserialized into a data class object.
 * @param serializer [KSerializer] of the data class for creating the JSONSchema.
 *
 * @note This method converts instances of LeapGeneratableDeserializationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (id _Nullable)createFromJsonObjectJsonObject:(NSDictionary<NSString *, LMDKotlinx_serialization_jsonJsonElement *> *)jsonObject serializer:(id<LMDKotlinx_serialization_coreKSerializer>)serializer error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("createFromJsonObject(jsonObject:serializer:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JSONSchemaGenerator")))
@interface LMDJSONSchemaGenerator : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jSONSchemaGenerator __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDJSONSchemaGenerator *shared __attribute__((swift_name("shared")));

/**
 * Generate a JSON Schema string from a data class [T]. This JSON Schema string can be used in
 * both the prompt and the constraint.
 *
 * @param indentSpaces intent spaces for adding indent in the generated string. `null` value will
 *   create outputs without indents
 */
- (NSString *)getJSONSchemaIndentSpaces:(LMDInt * _Nullable)indentSpaces __attribute__((swift_name("getJSONSchema(indentSpaces:)")));

/**
 * Generate a JSON Schema string from a data class serializer. This JSON Schema string can be used
 * in both the prompt and the constraint.
 *
 * @param serializer [KSerializer] of the data class for creating the JSONSchema.
 * @param indentSpaces intent spaces for adding indent in the generated string. `null` value will
 *   create outputs without indents
 */
- (NSString *)getJSONSchemaSerializer:(id<LMDKotlinx_serialization_coreKSerializer>)serializer indentSpaces:(LMDInt * _Nullable)indentSpaces __attribute__((swift_name("getJSONSchema(serializer:indentSpaces:)")));
@end


/** Exception in creating generatable objects from JSON. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGeneratableDeserializationException")))
@interface LMDLeapGeneratableDeserializationException : LMDLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/** Exception in creating the JSONSchema for a generatable data class. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapGeneratableSchematizationException")))
@interface LMDLeapGeneratableSchematizationException : LMDLeapException
- (instancetype)initWithMessage:(NSString *)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

@interface LMDLeapFunction (Extensions)
- (LMDLeapFunctionDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface LMDLeapFunctionDto (Extensions)
- (LMDLeapFunction *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface LMDLeapFunctionParameter (Extensions)
- (LMDLeapFunctionParameterDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface LMDLeapFunctionParameterDto (Extensions)
- (LMDLeapFunctionParameter *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface LMDLeapFunctionParameterType (Extensions)
- (LMDLeapFunctionParameterTypeDto *)toDto __attribute__((swift_name("toDto()")));
@end

@interface LMDLeapFunctionParameterTypeDto (Extensions)
- (LMDLeapFunctionParameterType *)toDomain __attribute__((swift_name("toDomain()")));
@end

@interface LMDEngineOptionsCacheOptions (Extensions)

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

@interface LMDGenerationTimeParameters (Extensions)
- (LMDGenerationOptions *)toGenerationOptions __attribute__((swift_name("toGenerationOptions()")));
@end

@interface LMDChatMessageContentCompanion (Extensions)

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
- (LMDChatMessageContentAudio *)audioNsData:(NSData *)nsData format:(NSString *)format __attribute__((swift_name("audio(nsData:format:)")));

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
- (LMDChatMessageContentAudio *)fromFloatSamplesSamples:(LMDKotlinFloatArray *)samples sampleRate:(int32_t)sampleRate channelCount:(int32_t)channelCount __attribute__((swift_name("fromFloatSamples(samples:sampleRate:channelCount:)")));

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
- (LMDChatMessageContentAudio *)fromFloatSamplesSamples:(NSArray<LMDFloat *> *)samples sampleRate:(int32_t)sampleRate channelCount_:(int32_t)channelCount __attribute__((swift_name("fromFloatSamples(samples:sampleRate:channelCount_:)")));

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
- (LMDChatMessageContentImage *)fromJPEGDataJpegData:(NSData *)jpegData __attribute__((swift_name("fromJPEGData(jpegData:)")));

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
- (LMDChatMessageContentAudio *)fromWAVDataWavData:(NSData *)wavData __attribute__((swift_name("fromWAVData(wavData:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArrayConversionsKt")))
@interface LMDArrayConversionsKt : LMDBase

/** Convert a [ByteArray] to [NSData] via a single bulk memcpy. */
+ (NSData *)byteArrayToNSDataArray:(LMDKotlinByteArray *)array __attribute__((swift_name("byteArrayToNSData(array:)")));

/** Convert a [FloatArray] to [NSData] (raw IEEE 754 bytes) via a single bulk memcpy. */
+ (NSData *)floatArrayToNSDataArray:(LMDKotlinFloatArray *)array __attribute__((swift_name("floatArrayToNSData(array:)")));

/** Convert [NSData] (raw IEEE 754 bytes) to a [FloatArray] via a single bulk memcpy. */
+ (LMDKotlinFloatArray *)nsDataToFloatArrayData:(NSData *)data __attribute__((swift_name("nsDataToFloatArray(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConversationExtensionsKt")))
@interface LMDConversationExtensionsKt : LMDBase

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
+ (id<LMDConversation>)ConversationModelRunner:(id<LMDModelRunner>)modelRunner history:(NSArray<LMDChatMessage *> *)history __attribute__((swift_name("Conversation(modelRunner:history:)")));

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
+ (NSString *)exportToJSON:(id<LMDConversation>)receiver __attribute__((swift_name("exportToJSON(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EngineOptionsKt")))
@interface LMDEngineOptionsKt : LMDBase
@property (class, readonly) int64_t CACHE_OPTIONS_DEFAULT_MAX_BYTES_MEMORY __attribute__((swift_name("CACHE_OPTIONS_DEFAULT_MAX_BYTES_MEMORY")));

/**
 * Engine-side defaults for the bounded-LRU `CacheOptions` size caps, shared between the `expect`
 * constructor and the resolution chain in `resolvedMaxEntriesDisk`.
 *
 * Keep these in sync with the engine-side defaults in `inference_engine`'s
 * `crates/ie-core/src/loader.rs` (`CacheOptions::default()`); the Rust side is the source of truth
 * because validation happens there.
 */
@property (class, readonly) int32_t CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK __attribute__((swift_name("CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_DISK")));
@property (class, readonly) int32_t CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_MEMORY __attribute__((swift_name("CACHE_OPTIONS_DEFAULT_MAX_ENTRIES_MEMORY")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloader_appleKt")))
@interface LMDLeapDownloader_appleKt : LMDBase
+ (LMDKtor_client_coreHttpClient *)buildHttpClientJson:(LMDKotlinx_serialization_jsonJson *)json installCache:(BOOL)installCache followRedirects:(BOOL)followRedirects expectSuccess:(BOOL)expectSuccess disableSslValidation:(BOOL)disableSslValidation connectTimeoutMillis:(int64_t)connectTimeoutMillis socketTimeoutMillis:(int64_t)socketTimeoutMillis requestTimeoutMillis:(int64_t)requestTimeoutMillis __attribute__((swift_name("buildHttpClient(json:installCache:followRedirects:expectSuccess:disableSslValidation:connectTimeoutMillis:socketTimeoutMillis:requestTimeoutMillis:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapDownloaderKt")))
@interface LMDLeapDownloaderKt : LMDBase
+ (LMDKtor_client_coreHttpClient *)defaultClientJson:(LMDKotlinx_serialization_jsonJson *)json config:(LMDLeapDownloaderConfig *)config __attribute__((swift_name("defaultClient(json:config:)")));
+ (LMDKtor_client_coreHttpClient *)defaultClientCacheJson:(LMDKotlinx_serialization_jsonJson *)json config:(LMDLeapDownloaderConfig *)config __attribute__((swift_name("defaultClientCache(json:config:)")));
+ (LMDKtor_client_coreHttpClient *)defaultNoRedirectClientJson:(LMDKotlinx_serialization_jsonJson *)json config:(LMDLeapDownloaderConfig *)config __attribute__((swift_name("defaultNoRedirectClient(json:config:)")));
+ (NSString *)manifestFilenameModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug __attribute__((swift_name("manifestFilename(modelName:quantizationSlug:)")));
+ (NSString *)manifestUrlModelName:(NSString *)modelName quantizationSlug:(NSString *)quantizationSlug baseUrl:(NSString *)baseUrl __attribute__((swift_name("manifestUrl(modelName:quantizationSlug:baseUrl:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LeapJsonKt")))
@interface LMDLeapJsonKt : LMDBase

/**
 * Shared JSON configuration for Leap SDK serialization.
 *
 * This instance is configured to:
 * - Ignore unknown fields in JSON (for forward compatibility)
 * - Not encode default/null values (reduce payload size)
 * - Coerce invalid values to defaults (defensive parsing)
 * - Not write explicit nulls in JSON output
 */
@property (class, readonly) LMDKotlinx_serialization_jsonJson *LeapJson __attribute__((swift_name("LeapJson")));

/**
 * JSON configuration with pretty printing enabled for human-readable output.
 *
 * Used for debugging, schema generation, and formatted JSON output.
 */
@property (class, readonly) LMDKotlinx_serialization_jsonJson *LeapJsonPretty __attribute__((swift_name("LeapJsonPretty")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSinkKt")))
@interface LMDProgressReportingSinkKt : LMDBase

/** Extension function to easily wrap any existing Sink with progress reporting. */
+ (id<LMDKotlinx_io_coreRawSink>)withProgressListener:(id<LMDKotlinx_io_coreRawSink>)receiver progressListener:(void (^)(LMDLong *))progressListener __attribute__((swift_name("withProgressListener(_:progressListener:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProgressReportingSourceKt")))
@interface LMDProgressReportingSourceKt : LMDBase

/** Extension function to easily wrap any existing RawSource with progress reporting. */
+ (id<LMDKotlinx_io_coreRawSource>)withProgressListener:(id<LMDKotlinx_io_coreRawSource>)receiver progressListener:(void (^)(LMDLong *))progressListener __attribute__((swift_name("withProgressListener(_:progressListener:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilsKt")))
@interface LMDUtilsKt : LMDBase

/**
 * Delete the given path, recursively if needed
 *
 * @throws kotlinx.io.files.FileNotFoundException - when [path] does not exist and [mustExist] is
 *   `true`
 * @throws kotlinx.io.IOException if there was an underlying error preventing listing the [path]'s
 *   children if it was a directory
 */
+ (void)deleteRecursively:(id<LMDKotlinx_io_coreFileSystem>)receiver path:(LMDKotlinx_io_corePath *)path mustExist:(BOOL)mustExist __attribute__((swift_name("deleteRecursively(_:path:mustExist:)")));
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

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol LMDKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<LMDKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreMutex")))
@protocol LMDKotlinx_coroutines_coreMutex
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
@property (readonly) id<LMDKotlinx_coroutines_coreSelectClause2> onLock __attribute__((swift_name("onLock"))) __attribute__((deprecated("Mutex.onLock deprecated without replacement. For additional details please refer to #2794")));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface LMDKotlinIllegalStateException : LMDKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface LMDKotlinCancellationException : LMDKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface LMDKotlinArray<T> : LMDBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(LMDInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<LMDKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinFloatArray")))
@interface LMDKotlinFloatArray : LMDBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(LMDFloat *(^)(LMDInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (float)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LMDKotlinFloatIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(float)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface LMDKotlinByteArray : LMDBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(LMDByte *(^)(LMDInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LMDKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface LMDKotlinEnumCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonElementSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement")))
@interface LMDKotlinx_serialization_jsonJsonElement : LMDBase
@property (class, readonly, getter=companion) LMDKotlinx_serialization_jsonJsonElementCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol LMDKotlinx_serialization_coreEncoder
@required
- (id<LMDKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<LMDKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<LMDKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
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
- (void)encodeNullableSerializableValueSerializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) LMDKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/serialization/SealedSerializationApi)])
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol LMDKotlinx_serialization_coreSerialDescriptor
@required
- (NSArray<id<LMDKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));
- (id<LMDKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));
@property (readonly) NSArray<id<LMDKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));
@property (readonly) LMDKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol LMDKotlinx_serialization_coreDecoder
@required
- (id<LMDKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<LMDKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
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
- (LMDKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) LMDKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinCharSequence")))
@protocol LMDKotlinCharSequence
@required
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id)subSequenceStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("subSequence(startIndex:endIndex:)")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end

__attribute__((swift_name("KotlinAppendable")))
@protocol LMDKotlinAppendable
@required

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<LMDKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<LMDKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<LMDKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinStringBuilder")))
@interface LMDKotlinStringBuilder : LMDBase <LMDKotlinCharSequence, LMDKotlinAppendable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithContent:(id)content __attribute__((swift_name("init(content:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCapacity:(int32_t)capacity __attribute__((swift_name("init(capacity:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent_:(NSString *)content __attribute__((swift_name("init(content_:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue__:(id _Nullable)value __attribute__((swift_name("append(value__:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue___:(BOOL)value __attribute__((swift_name("append(value___:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue____:(int8_t)value __attribute__((swift_name("append(value____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue_____:(LMDKotlinCharArray *)value __attribute__((swift_name("append(value_____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue______:(double)value __attribute__((swift_name("append(value______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue_______:(float)value __attribute__((swift_name("append(value_______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue________:(int32_t)value __attribute__((swift_name("append(value________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue_________:(int64_t)value __attribute__((swift_name("append(value_________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue__________:(int16_t)value __attribute__((swift_name("append(value__________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue___________:(NSString * _Nullable)value __attribute__((swift_name("append(value___________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendRangeValue:(LMDKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)appendRangeValue:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("appendRange(value:startIndex:endIndex_:)")));
- (int32_t)capacity __attribute__((swift_name("capacity()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)deleteAtIndex:(int32_t)index __attribute__((swift_name("deleteAt(index:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)deleteRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("deleteRange(startIndex:endIndex:)")));
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
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value:(id _Nullable)value __attribute__((swift_name("insert(index:value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value_:(BOOL)value __attribute__((swift_name("insert(index:value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value__:(int8_t)value __attribute__((swift_name("insert(index:value__:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value___:(unichar)value __attribute__((swift_name("insert(index:value___:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value____:(LMDKotlinCharArray *)value __attribute__((swift_name("insert(index:value____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value_____:(id _Nullable)value __attribute__((swift_name("insert(index:value_____:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value______:(double)value __attribute__((swift_name("insert(index:value______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value_______:(float)value __attribute__((swift_name("insert(index:value_______:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value________:(int32_t)value __attribute__((swift_name("insert(index:value________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value_________:(int64_t)value __attribute__((swift_name("insert(index:value_________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value__________:(int16_t)value __attribute__((swift_name("insert(index:value__________:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertIndex:(int32_t)index value___________:(NSString * _Nullable)value __attribute__((swift_name("insert(index:value___________:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(LMDKotlinCharArray *)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)insertRangeIndex:(int32_t)index value:(id)value startIndex:(int32_t)startIndex endIndex_:(int32_t)endIndex __attribute__((swift_name("insertRange(index:value:startIndex:endIndex_:)")));

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
- (LMDKotlinStringBuilder *)reverse __attribute__((swift_name("reverse()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
- (void)setLengthNewLength:(int32_t)newLength __attribute__((swift_name("setLength(newLength:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
 *   kotlin.IgnorableReturnValue
*/
- (LMDKotlinStringBuilder *)setRangeStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex value:(NSString *)value __attribute__((swift_name("setRange(startIndex:endIndex:value:)")));
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
- (void)toCharArrayDestination:(LMDKotlinCharArray *)destination destinationOffset:(int32_t)destinationOffset startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("toCharArray(destination:destinationOffset:startIndex:endIndex:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (void)trimToSize __attribute__((swift_name("trimToSize()")));
@property (readonly) int32_t length __attribute__((swift_name("length")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol LMDKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_bytestringByteString")))
@interface LMDKotlinx_io_bytestringByteString : LMDBase <LMDKotlinComparable>
- (instancetype)initWithData:(LMDKotlinByteArray *)data startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("init(data:startIndex:endIndex:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKotlinx_io_bytestringByteStringCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(LMDKotlinx_io_bytestringByteString *)other __attribute__((swift_name("compareTo(other:)")));
- (void)doCopyIntoDestination:(LMDKotlinByteArray *)destination destinationOffset:(int32_t)destinationOffset startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("doCopyInto(destination:destinationOffset:startIndex:endIndex:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (LMDKotlinx_io_bytestringByteString *)substringStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("substring(startIndex:endIndex:)")));
- (LMDKotlinByteArray *)toByteArrayStartIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("toByteArray(startIndex:endIndex:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Kotlinx_io_coreSource")))
@protocol LMDKotlinx_io_coreSource <LMDKotlinx_io_coreRawSource>
@required
- (BOOL)exhausted __attribute__((swift_name("exhausted()")));
- (id<LMDKotlinx_io_coreSource>)peek __attribute__((swift_name("peek()")));
- (int32_t)readAtMostToSink:(LMDKotlinByteArray *)sink startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("readAtMostTo(sink:startIndex:endIndex:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (int32_t)readInt __attribute__((swift_name("readInt()")));
- (int64_t)readLong __attribute__((swift_name("readLong()")));
- (int16_t)readShort __attribute__((swift_name("readShort()")));
- (void)readToSink:(id<LMDKotlinx_io_coreRawSink>)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readTo(sink:byteCount:)")));
- (BOOL)requestByteCount:(int64_t)byteCount __attribute__((swift_name("request(byteCount:)")));
- (void)requireByteCount:(int64_t)byteCount __attribute__((swift_name("require(byteCount:)")));
- (void)skipByteCount:(int64_t)byteCount __attribute__((swift_name("skip(byteCount:)")));
- (int64_t)transferToSink:(id<LMDKotlinx_io_coreRawSink>)sink __attribute__((swift_name("transferTo(sink:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) LMDKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@end

__attribute__((swift_name("Kotlinx_io_coreSink")))
@protocol LMDKotlinx_io_coreSink <LMDKotlinx_io_coreRawSink>
@required
- (void)emit __attribute__((swift_name("emit()")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
- (void)hintEmit __attribute__((swift_name("hintEmit()")));
- (int64_t)transferFromSource:(id<LMDKotlinx_io_coreRawSource>)source __attribute__((swift_name("transferFrom(source:)")));
- (void)writeSource:(id<LMDKotlinx_io_coreRawSource>)source byteCount_:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount_:)")));
- (void)writeSource:(LMDKotlinByteArray *)source startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("write(source:startIndex:endIndex:)")));
- (void)writeByteByte:(int8_t)byte __attribute__((swift_name("writeByte(byte:)")));
- (void)writeIntInt:(int32_t)int_ __attribute__((swift_name("writeInt(int:)")));
- (void)writeLongLong:(int64_t)long_ __attribute__((swift_name("writeLong(long:)")));
- (void)writeShortShort:(int16_t)short_ __attribute__((swift_name("writeShort(short:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) LMDKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_coreBuffer")))
@interface LMDKotlinx_io_coreBuffer : LMDBase <LMDKotlinx_io_coreSource, LMDKotlinx_io_coreSink>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)clear __attribute__((swift_name("clear()")));
- (void)close __attribute__((swift_name("close()")));
- (LMDKotlinx_io_coreBuffer *)doCopy __attribute__((swift_name("doCopy()")));
- (void)doCopyToOut:(LMDKotlinx_io_coreBuffer *)out startIndex:(int64_t)startIndex endIndex:(int64_t)endIndex __attribute__((swift_name("doCopyTo(out:startIndex:endIndex:)")));
- (void)emit __attribute__((swift_name("emit()")));
- (BOOL)exhausted __attribute__((swift_name("exhausted()")));
- (void)flush __attribute__((swift_name("flush()")));
- (int8_t)getPosition:(int64_t)position __attribute__((swift_name("get(position:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
- (void)hintEmit __attribute__((swift_name("hintEmit()")));
- (id<LMDKotlinx_io_coreSource>)peek __attribute__((swift_name("peek()")));
- (int64_t)readAtMostToSink:(LMDKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
- (int32_t)readAtMostToSink:(LMDKotlinByteArray *)sink startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("readAtMostTo(sink:startIndex:endIndex:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (int32_t)readInt __attribute__((swift_name("readInt()")));
- (int64_t)readLong __attribute__((swift_name("readLong()")));
- (int16_t)readShort __attribute__((swift_name("readShort()")));
- (void)readToSink:(id<LMDKotlinx_io_coreRawSink>)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readTo(sink:byteCount:)")));
- (BOOL)requestByteCount:(int64_t)byteCount __attribute__((swift_name("request(byteCount:)")));
- (void)requireByteCount:(int64_t)byteCount __attribute__((swift_name("require(byteCount:)")));
- (void)skipByteCount:(int64_t)byteCount __attribute__((swift_name("skip(byteCount:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (int64_t)transferFromSource:(id<LMDKotlinx_io_coreRawSource>)source __attribute__((swift_name("transferFrom(source:)")));
- (int64_t)transferToSink:(id<LMDKotlinx_io_coreRawSink>)sink __attribute__((swift_name("transferTo(sink:)")));
- (void)writeSource:(LMDKotlinx_io_coreBuffer *)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
- (void)writeSource:(id<LMDKotlinx_io_coreRawSource>)source byteCount_:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount_:)")));
- (void)writeSource:(LMDKotlinByteArray *)source startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("write(source:startIndex:endIndex:)")));
- (void)writeByteByte:(int8_t)byte __attribute__((swift_name("writeByte(byte:)")));
- (void)writeIntInt:(int32_t)int_ __attribute__((swift_name("writeInt(int:)")));
- (void)writeLongLong:(int64_t)long_ __attribute__((swift_name("writeLong(long:)")));
- (void)writeShortShort:(int16_t)short_ __attribute__((swift_name("writeShort(short:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) LMDKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol LMDKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<LMDKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("Ktor_ioCloseable")))
@protocol LMDKtor_ioCloseable <LMDKotlinAutoCloseable>
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
@interface LMDKtor_client_coreHttpClient : LMDBase <LMDKotlinx_coroutines_coreCoroutineScope, LMDKtor_ioCloseable>
- (instancetype)initWithEngine:(id<LMDKtor_client_coreHttpClientEngine>)engine userConfig:(LMDKtor_client_coreHttpClientConfig<LMDKtor_client_coreHttpClientEngineConfig *> *)userConfig __attribute__((swift_name("init(engine:userConfig:)"))) __attribute__((objc_designated_initializer));

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
- (LMDKtor_client_coreHttpClient *)configBlock:(void (^)(LMDKtor_client_coreHttpClientConfig<id> *))block __attribute__((swift_name("config(block:)")));

/**
 * Checks if the specified [capability] is supported by this client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.isSupported)
 */
- (BOOL)isSupportedCapability:(id<LMDKtor_client_coreHttpClientEngineCapability>)capability __attribute__((swift_name("isSupported(capability:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Typed attributes used as a lightweight container for this client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.attributes)
 */
@property (readonly) id<LMDKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) id<LMDKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<LMDKtor_client_coreHttpClientEngine> engine __attribute__((swift_name("engine")));

/**
 * Provides access to the client's engine configuration.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.engineConfig)
 */
@property (readonly) LMDKtor_client_coreHttpClientEngineConfig *engineConfig __attribute__((swift_name("engineConfig")));

/**
 * Provides access to the events of the client's lifecycle.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.monitor)
 */
@property (readonly) LMDKtor_eventsEvents *monitor __attribute__((swift_name("monitor")));

/**
 * A pipeline used for receiving a request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.receivePipeline)
 */
@property (readonly) LMDKtor_client_coreHttpReceivePipeline *receivePipeline __attribute__((swift_name("receivePipeline")));

/**
 * A pipeline used for processing all requests sent by this client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.requestPipeline)
 */
@property (readonly) LMDKtor_client_coreHttpRequestPipeline *requestPipeline __attribute__((swift_name("requestPipeline")));

/**
 * A pipeline used for processing all responses sent by the server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.responsePipeline)
 */
@property (readonly) LMDKtor_client_coreHttpResponsePipeline *responsePipeline __attribute__((swift_name("responsePipeline")));

/**
 * A pipeline used for sending a request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClient.sendPipeline)
 */
@property (readonly) LMDKtor_client_coreHttpSendPipeline *sendPipeline __attribute__((swift_name("sendPipeline")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_corePath")))
@interface LMDKotlinx_io_corePath : LMDBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isAbsolute __attribute__((swift_name("isAbsolute")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) LMDKotlinx_io_corePath * _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialFormat")))
@protocol LMDKotlinx_serialization_coreSerialFormat
@required
@property (readonly) LMDKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreStringFormat")))
@protocol LMDKotlinx_serialization_coreStringFormat <LMDKotlinx_serialization_coreSerialFormat>
@required
- (id _Nullable)decodeFromStringDeserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (NSString *)encodeToStringSerializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_jsonJson")))
@interface LMDKotlinx_serialization_jsonJson : LMDBase <LMDKotlinx_serialization_coreStringFormat>
@property (class, readonly, getter=companion) LMDKotlinx_serialization_jsonJsonDefault *companion __attribute__((swift_name("companion")));
- (id _Nullable)decodeFromJsonElementDeserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer element:(LMDKotlinx_serialization_jsonJsonElement *)element __attribute__((swift_name("decodeFromJsonElement(deserializer:element:)")));
- (id _Nullable)decodeFromStringString:(NSString *)string __attribute__((swift_name("decodeFromString(string:)")));
- (id _Nullable)decodeFromStringDeserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer string:(NSString *)string __attribute__((swift_name("decodeFromString(deserializer:string:)")));
- (LMDKotlinx_serialization_jsonJsonElement *)encodeToJsonElementSerializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToJsonElement(serializer:value:)")));
- (NSString *)encodeToStringValue:(id _Nullable)value __attribute__((swift_name("encodeToString(value:)")));
- (NSString *)encodeToStringSerializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeToString(serializer:value:)")));
- (LMDKotlinx_serialization_jsonJsonElement *)parseToJsonElementString:(NSString *)string __attribute__((swift_name("parseToJsonElement(string:)")));
@property (readonly) LMDKotlinx_serialization_jsonJsonConfiguration *configuration __attribute__((swift_name("configuration")));
@property (readonly) LMDKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_io_coreFileSystem")))
@protocol LMDKotlinx_io_coreFileSystem
@required
- (void)atomicMoveSource:(LMDKotlinx_io_corePath *)source destination:(LMDKotlinx_io_corePath *)destination __attribute__((swift_name("atomicMove(source:destination:)")));
- (void)createDirectoriesPath:(LMDKotlinx_io_corePath *)path mustCreate:(BOOL)mustCreate __attribute__((swift_name("createDirectories(path:mustCreate:)")));
- (void)deletePath:(LMDKotlinx_io_corePath *)path mustExist:(BOOL)mustExist __attribute__((swift_name("delete(path:mustExist:)")));
- (BOOL)existsPath:(LMDKotlinx_io_corePath *)path __attribute__((swift_name("exists(path:)")));
- (id)listDirectory:(LMDKotlinx_io_corePath *)directory __attribute__((swift_name("list(directory:)")));
- (LMDKotlinx_io_coreFileMetadata * _Nullable)metadataOrNullPath:(LMDKotlinx_io_corePath *)path __attribute__((swift_name("metadataOrNull(path:)")));
- (LMDKotlinx_io_corePath *)resolvePath:(LMDKotlinx_io_corePath *)path __attribute__((swift_name("resolve(path:)")));
- (id<LMDKotlinx_io_coreRawSink>)sinkPath:(LMDKotlinx_io_corePath *)path append:(BOOL)append __attribute__((swift_name("sink(path:append:)")));
- (id<LMDKotlinx_io_coreRawSource>)sourcePath:(LMDKotlinx_io_corePath *)path __attribute__((swift_name("source(path:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol LMDKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause")))
@protocol LMDKotlinx_coroutines_coreSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) LMDKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<LMDKotlinx_coroutines_coreSelectInstance>, id _Nullable, id _Nullable))(LMDKotlinThrowable *, id _Nullable, id<LMDKotlinCoroutineContext>) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<LMDKotlinx_coroutines_coreSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause2")))
@protocol LMDKotlinx_coroutines_coreSelectClause2 <LMDKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((swift_name("KotlinFloatIterator")))
@interface LMDKotlinFloatIterator : LMDBase <LMDKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (LMDFloat *)next __attribute__((swift_name("next()")));
- (float)nextFloat __attribute__((swift_name("nextFloat()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface LMDKotlinByteIterator : LMDBase <LMDKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (LMDByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement.Companion")))
@interface LMDKotlinx_serialization_jsonJsonElementCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinx_serialization_jsonJsonElementCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol LMDKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<LMDKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<LMDKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) LMDKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface LMDKotlinx_serialization_coreSerializersModule : LMDBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<LMDKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<LMDKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<LMDKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<LMDKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<LMDKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<LMDKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<LMDKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<LMDKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol LMDKotlinAnnotation
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface LMDKotlinx_serialization_coreSerialKind : LMDBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol LMDKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<LMDKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<LMDKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) LMDKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface LMDKotlinNothing : LMDBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinCharArray")))
@interface LMDKotlinCharArray : LMDBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(id (^)(LMDInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (unichar)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (LMDKotlinCharIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(unichar)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_bytestringByteString.Companion")))
@interface LMDKotlinx_io_bytestringByteStringCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinx_io_bytestringByteStringCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol LMDKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<LMDKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<LMDKotlinCoroutineContextElement> _Nullable)getKey:(id<LMDKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<LMDKotlinCoroutineContext>)minusKeyKey:(id<LMDKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<LMDKotlinCoroutineContext>)plusContext:(id<LMDKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
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
@protocol LMDKtor_client_coreHttpClientEngine <LMDKotlinx_coroutines_coreCoroutineScope, LMDKtor_ioCloseable>
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
- (void)executeData:(LMDKtor_client_coreHttpRequestData *)data completionHandler:(void (^)(LMDKtor_client_coreHttpResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(data:completionHandler:)")));

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
- (void)installClient:(LMDKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));

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
@property (readonly) LMDKtor_client_coreHttpClientEngineConfig *config __attribute__((swift_name("config")));

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
@property (readonly) LMDKotlinx_coroutines_coreCoroutineDispatcher *dispatcher __attribute__((swift_name("dispatcher")));

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
@property (readonly) NSSet<id<LMDKtor_client_coreHttpClientEngineCapability>> *supportedCapabilities __attribute__((swift_name("supportedCapabilities")));
@end


/**
 * Base configuration for [HttpClientEngine].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig)
 */
__attribute__((swift_name("Ktor_client_coreHttpClientEngineConfig")))
@interface LMDKtor_client_coreHttpClientEngineConfig : LMDBase

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
@property LMDKotlinx_coroutines_coreCoroutineDispatcher * _Nullable dispatcher __attribute__((swift_name("dispatcher")));

/**
 * Enables HTTP pipelining advice.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.pipelining)
 */
@property BOOL pipelining __attribute__((swift_name("pipelining")));

/**
 * Specifies a proxy address to use.
 * Uses a system proxy by default.
 *
 * You can learn more from [Proxy](https://ktor.io/docs/proxy.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.proxy)
 */
@property LMDKtor_client_coreProxyConfig * _Nullable proxy __attribute__((swift_name("proxy")));

/**
 * Specifies network threads count advice.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.engine.HttpClientEngineConfig.threadsCount)
 */
@property int32_t threadsCount __attribute__((swift_name("threadsCount"))) __attribute__((unavailable("The [threadsCount] property is deprecated. Consider setting [dispatcher] instead.")));
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
@interface LMDKtor_client_coreHttpClientConfig<T> : LMDBase

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
- (LMDKtor_client_coreHttpClientConfig<T> *)clone __attribute__((swift_name("clone()")));

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
- (void)installClient:(LMDKtor_client_coreHttpClient *)client __attribute__((swift_name("install(client:)")));

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
- (void)installPlugin:(id<LMDKtor_client_coreHttpClientPlugin>)plugin configure:(void (^)(id))configure __attribute__((swift_name("install(plugin:configure:)")));

/**
 * Installs an interceptor defined by [block].
 * The [key] parameter is used as a unique name, that also prevents installing duplicated interceptors.
 *
 * If the [key] is already used, the new interceptor will replace the old one.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.install)
 */
- (void)installKey:(NSString *)key block:(void (^)(LMDKtor_client_coreHttpClient *))block __attribute__((swift_name("install(key:block:)")));

/**
 * Installs the plugin from the [other] client's configuration.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.plusAssign)
 */
- (void)plusAssignOther:(LMDKtor_client_coreHttpClientConfig<T> *)other __attribute__((swift_name("plusAssign(other:)")));

/**
 * Development mode is no longer required all functionality is enabled by default. The property is safe to remove.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.developmentMode)
 */
@property BOOL developmentMode __attribute__((swift_name("developmentMode"))) __attribute__((deprecated("Development mode is no longer required. The property will be removed in the future.")));

/**
 * Terminates [HttpClient.receivePipeline] if the status code is not successful (>=300).
 * Learn more from [Response validation](https://ktor.io/docs/response-validation.html).
 *
 * For more details, see the [HttpCallValidator] documentation.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.expectSuccess)
 */
@property BOOL expectSuccess __attribute__((swift_name("expectSuccess")));

/**
 * Specifies whether the client redirects to URLs provided in the `Location` header.
 * You can disable redirections by setting this property to `false`.
 *
 * For an advanced redirection configuration, use the [HttpRedirect] plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.HttpClientConfig.followRedirects)
 */
@property BOOL followRedirects __attribute__((swift_name("followRedirects")));

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
@property BOOL useDefaultTransformers __attribute__((swift_name("useDefaultTransformers")));
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
@protocol LMDKtor_client_coreHttpClientEngineCapability
@required
@end


/**
 * Map of attributes accessible by [AttributeKey] in a typed manner
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes)
 */
__attribute__((swift_name("Ktor_utilsAttributes")))
@protocol LMDKtor_utilsAttributes
@required

/**
 * Gets a value of the attribute for the specified [key], or calls supplied [block] to compute its value
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.computeIfAbsent)
 */
- (id)computeIfAbsentKey:(LMDKtor_utilsAttributeKey<id> *)key block:(id (^)(void))block __attribute__((swift_name("computeIfAbsent(key:block:)")));

/**
 * Checks if an attribute with the specified [key] exists
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.contains)
 */
- (BOOL)containsKey:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("contains(key:)")));

/**
 * Gets a value of the attribute for the specified [key], or throws an exception if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.get)
 */
- (id)getKey_:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("get(key_:)")));

/**
 * Gets a value of the attribute for the specified [key], or return `null` if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.getOrNull)
 */
- (id _Nullable)getOrNullKey:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getOrNull(key:)")));

/**
 * Creates or changes an attribute with the specified [key] using [value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.put)
 */
- (void)putKey:(LMDKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("put(key:value:)")));

/**
 * Removes an attribute with the specified [key]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.remove)
 */
- (void)removeKey:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("remove(key:)")));

/**
 * Creates or changes an attribute with the specified [key] using [value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.set)
 */
- (void)setKey:(LMDKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("set(key:value:)")));

/**
 * Removes an attribute with the specified [key] and returns its current value, throws an exception if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.take)
 */
- (id)takeKey:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("take(key:)")));

/**
 * Removes an attribute with the specified [key] and returns its current value, returns `null` if an attribute doesn't exist
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.takeOrNull)
 */
- (id _Nullable)takeOrNullKey:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("takeOrNull(key:)")));

/**
 * Returns [List] of all [AttributeKey] instances in this map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.Attributes.allKeys)
 */
@property (readonly) NSArray<LMDKtor_utilsAttributeKey<id> *> *allKeys __attribute__((swift_name("allKeys")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_eventsEvents")))
@interface LMDKtor_eventsEvents : LMDBase
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
- (void)raiseDefinition:(LMDKtor_eventsEventDefinition<id> *)definition value:(id _Nullable)value __attribute__((swift_name("raise(definition:value:)")));

/**
 * Subscribe [handler] to an event specified by [definition]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.Events.subscribe)
 */
- (id<LMDKotlinx_coroutines_coreDisposableHandle>)subscribeDefinition:(LMDKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("subscribe(definition:handler:)")));

/**
 * Unsubscribe [handler] from an event specified by [definition]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.events.Events.unsubscribe)
 */
- (void)unsubscribeDefinition:(LMDKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("unsubscribe(definition:handler:)")));
@end


/**
 * Represents an execution pipeline for asynchronous extensible computations
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline)
 */
__attribute__((swift_name("Ktor_utilsPipeline")))
@interface LMDKtor_utilsPipeline<TSubject, TContext> : LMDBase
- (instancetype)initWithPhases:(LMDKotlinArray<LMDKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhase:(LMDKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LMDKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer));

/**
 * Adds [phase] to the end of this pipeline
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.addPhase)
 */
- (void)addPhasePhase:(LMDKtor_utilsPipelinePhase *)phase __attribute__((swift_name("addPhase(phase:)")));

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
- (void)insertPhaseAfterReference:(LMDKtor_utilsPipelinePhase *)reference phase:(LMDKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseAfter(reference:phase:)")));

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
- (void)insertPhaseBeforeReference:(LMDKtor_utilsPipelinePhase *)reference phase:(LMDKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseBefore(reference:phase:)")));

/**
 * Adds [block] to the [phase] of this pipeline
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.intercept)
 */
- (void)interceptPhase:(LMDKtor_utilsPipelinePhase *)phase block:(id<LMDKotlinSuspendFunction2>)block __attribute__((swift_name("intercept(phase:block:)")));
- (NSArray<id<LMDKotlinSuspendFunction2>> *)interceptorsForPhasePhase:(LMDKtor_utilsPipelinePhase *)phase __attribute__((swift_name("interceptorsForPhase(phase:)")));

/**
 * Merges another pipeline into this pipeline, maintaining relative phases order
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.merge)
 */
- (void)mergeFrom:(LMDKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("merge(from:)")));
- (void)mergePhasesFrom:(LMDKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("mergePhases(from:)")));

/**
 * Reset current pipeline from other.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.resetFrom)
 */
- (void)resetFromFrom:(LMDKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("resetFrom(from:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Provides common place to store pipeline attributes
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.attributes)
 */
@property (readonly) id<LMDKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));

/**
 * Indicated if debug mode is enabled. In debug mode users will get more details in the stacktrace.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.developmentMode)
 */
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));

/**
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.isEmpty)
 *
 * @return `true` if there are no interceptors installed regardless number of phases
 */
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));

/**
 * Phases of this pipeline
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.pipeline.Pipeline.items)
 */
@property (readonly) NSArray<LMDKtor_utilsPipelinePhase *> *items __attribute__((swift_name("items")));
@end


/**
 * [HttpClient] Pipeline used for receiving [HttpResponse] without any processing.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline")))
@interface LMDKtor_client_coreHttpReceivePipeline : LMDKtor_utilsPipeline<LMDKtor_client_coreHttpResponse *, LMDKotlinUnit *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LMDKotlinArray<LMDKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LMDKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LMDKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_client_coreHttpReceivePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end


/**
 * An [HttpClient]'s pipeline used for executing [HttpRequest].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline")))
@interface LMDKtor_client_coreHttpRequestPipeline : LMDKtor_utilsPipeline<id, LMDKtor_client_coreHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LMDKotlinArray<LMDKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LMDKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LMDKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_client_coreHttpRequestPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end


/**
 * [HttpClient] Pipeline used for executing [HttpResponse].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline")))
@interface LMDKtor_client_coreHttpResponsePipeline : LMDKtor_utilsPipeline<LMDKtor_client_coreHttpResponseContainer *, LMDKtor_client_coreHttpClientCall *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LMDKotlinArray<LMDKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LMDKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LMDKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_client_coreHttpResponsePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end


/**
 * An [HttpClient]'s pipeline used for sending [HttpRequest] to a remote server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline")))
@interface LMDKtor_client_coreHttpSendPipeline : LMDKtor_utilsPipeline<id, LMDKtor_client_coreHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(LMDKotlinArray<LMDKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(LMDKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<LMDKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_client_coreHttpSendPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJson.Default")))
@interface LMDKotlinx_serialization_jsonJsonDefault : LMDKotlinx_serialization_jsonJson
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)default_ __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinx_serialization_jsonJsonDefault *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonConfiguration")))
@interface LMDKotlinx_serialization_jsonJsonConfiguration : LMDBase
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL allowComments __attribute__((swift_name("allowComments")));
@property (readonly) BOOL allowSpecialFloatingPointValues __attribute__((swift_name("allowSpecialFloatingPointValues")));
@property (readonly) BOOL allowStructuredMapKeys __attribute__((swift_name("allowStructuredMapKeys")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL allowTrailingComma __attribute__((swift_name("allowTrailingComma")));
@property (readonly) NSString *classDiscriminator __attribute__((swift_name("classDiscriminator")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property LMDKotlinx_serialization_jsonClassDiscriminatorMode *classDiscriminatorMode __attribute__((swift_name("classDiscriminatorMode")));
@property (readonly) BOOL coerceInputValues __attribute__((swift_name("coerceInputValues")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL decodeEnumsCaseInsensitive __attribute__((swift_name("decodeEnumsCaseInsensitive")));
@property (readonly) BOOL encodeDefaults __attribute__((swift_name("encodeDefaults")));
@property (readonly) BOOL explicitNulls __attribute__((swift_name("explicitNulls")));
@property (readonly) BOOL ignoreUnknownKeys __attribute__((swift_name("ignoreUnknownKeys")));
@property (readonly) BOOL isLenient __attribute__((swift_name("isLenient")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) id<LMDKotlinx_serialization_jsonJsonNamingStrategy> _Nullable namingStrategy __attribute__((swift_name("namingStrategy")));
@property (readonly) BOOL prettyPrint __attribute__((swift_name("prettyPrint")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *prettyPrintIndent __attribute__((swift_name("prettyPrintIndent")));
@property (readonly) BOOL useAlternativeNames __attribute__((swift_name("useAlternativeNames")));
@property (readonly) BOOL useArrayPolymorphism __attribute__((swift_name("useArrayPolymorphism")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_coreFileMetadata")))
@interface LMDKotlinx_io_coreFileMetadata : LMDBase
- (instancetype)initWithIsRegularFile:(BOOL)isRegularFile isDirectory:(BOOL)isDirectory size:(int64_t)size __attribute__((swift_name("init(isRegularFile:isDirectory:size:)"))) __attribute__((objc_designated_initializer));
@property (readonly) BOOL isDirectory __attribute__((swift_name("isDirectory")));
@property (readonly) BOOL isRegularFile __attribute__((swift_name("isRegularFile")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface LMDKotlinUnit : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSelectInstance")))
@protocol LMDKotlinx_coroutines_coreSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<LMDKotlinx_coroutines_coreDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<LMDKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol LMDKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<LMDKotlinKClass>)kClass provider:(id<LMDKotlinx_serialization_coreKSerializer> (^)(NSArray<id<LMDKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<LMDKotlinKClass>)kClass serializer:(id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<LMDKotlinKClass>)baseClass actualClass:(id<LMDKotlinKClass>)actualClass actualSerializer:(id<LMDKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<LMDKotlinKClass>)baseClass defaultDeserializerProvider:(id<LMDKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<LMDKotlinKClass>)baseClass defaultDeserializerProvider:(id<LMDKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<LMDKotlinKClass>)baseClass defaultSerializerProvider:(id<LMDKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol LMDKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol LMDKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol LMDKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol LMDKotlinKClass <LMDKotlinKDeclarationContainer, LMDKotlinKAnnotatedElement, LMDKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

__attribute__((swift_name("KotlinCharIterator")))
@interface LMDKotlinCharIterator : LMDBase <LMDKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id)next __attribute__((swift_name("next()")));
- (unichar)nextChar __attribute__((swift_name("nextChar()")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol LMDKotlinCoroutineContextElement <LMDKotlinCoroutineContext>
@required
@property (readonly) id<LMDKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol LMDKotlinCoroutineContextKey
@required
@end


/**
 * Actual data of the [HttpRequest], including [url], [method], [headers], [body] and [executionContext].
 * Built by [HttpRequestBuilder].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestData)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestData")))
@interface LMDKtor_client_coreHttpRequestData : LMDBase
- (instancetype)initWithUrl:(LMDKtor_httpUrl *)url method:(LMDKtor_httpHttpMethod *)method headers:(id<LMDKtor_httpHeaders>)headers body:(LMDKtor_httpOutgoingContent *)body executionContext:(id<LMDKotlinx_coroutines_coreJob>)executionContext attributes:(id<LMDKtor_utilsAttributes>)attributes __attribute__((swift_name("init(url:method:headers:body:executionContext:attributes:)"))) __attribute__((objc_designated_initializer));

/**
 * Retrieve extension by its key.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestData.getCapabilityOrNull)
 */
- (id _Nullable)getCapabilityOrNullKey:(id<LMDKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<LMDKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) LMDKtor_httpOutgoingContent *body __attribute__((swift_name("body")));
@property (readonly) id<LMDKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) id<LMDKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) LMDKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) LMDKtor_httpUrl *url __attribute__((swift_name("url")));
@end


/**
 * Data prepared for [HttpResponse].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpResponseData)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponseData")))
@interface LMDKtor_client_coreHttpResponseData : LMDBase
- (instancetype)initWithStatusCode:(LMDKtor_httpHttpStatusCode *)statusCode requestTime:(LMDKtor_utilsGMTDate *)requestTime headers:(id<LMDKtor_httpHeaders>)headers version:(LMDKtor_httpHttpProtocolVersion *)version body:(id)body callContext:(id<LMDKotlinCoroutineContext>)callContext __attribute__((swift_name("init(statusCode:requestTime:headers:version:body:callContext:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id body __attribute__((swift_name("body")));
@property (readonly) id<LMDKotlinCoroutineContext> callContext __attribute__((swift_name("callContext")));
@property (readonly) id<LMDKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) LMDKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) LMDKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) LMDKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@property (readonly) LMDKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface LMDKotlinAbstractCoroutineContextElement : LMDBase <LMDKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<LMDKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<LMDKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol LMDKotlinContinuationInterceptor <LMDKotlinCoroutineContextElement>
@required
- (id<LMDKotlinContinuation>)interceptContinuationContinuation:(id<LMDKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<LMDKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface LMDKotlinx_coroutines_coreCoroutineDispatcher : LMDKotlinAbstractCoroutineContextElement <LMDKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<LMDKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<LMDKotlinCoroutineContext>)context block:(id<LMDKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)dispatchYieldContext:(id<LMDKotlinCoroutineContext>)context block:(id<LMDKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<LMDKotlinContinuation>)interceptContinuationContinuation:(id<LMDKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<LMDKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));
- (LMDKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism name:(NSString * _Nullable)name __attribute__((swift_name("limitedParallelism(parallelism:name:)")));
- (LMDKotlinx_coroutines_coreCoroutineDispatcher *)plusOther:(LMDKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<LMDKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
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
@interface LMDKtor_client_coreProxyConfig : LMDBase
- (instancetype)initWithUrl:(LMDKtor_httpUrl *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) LMDKtor_httpUrl *url __attribute__((swift_name("url")));
@end


/**
 * Base interface representing a [HttpClient] plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.plugins.HttpClientPlugin)
 */
__attribute__((swift_name("Ktor_client_coreHttpClientPlugin")))
@protocol LMDKtor_client_coreHttpClientPlugin
@required

/**
 * Installs the [plugin] class for a [HttpClient] defined at [scope].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.plugins.HttpClientPlugin.install)
 */
- (void)installPlugin:(id)plugin scope:(LMDKtor_client_coreHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));

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
@property (readonly) LMDKtor_utilsAttributeKey<id> *key __attribute__((swift_name("key")));
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
@interface LMDKtor_utilsAttributeKey<T> : LMDBase

/**
 * @note annotations
 *   kotlin.jvm.JvmOverloads
*/
- (instancetype)initWithName:(NSString *)name type:(LMDKtor_utilsTypeInfo *)type __attribute__((swift_name("init(name:type:)"))) __attribute__((objc_designated_initializer));
- (LMDKtor_utilsAttributeKey<T> *)doCopyName:(NSString *)name type:(LMDKtor_utilsTypeInfo *)type __attribute__((swift_name("doCopy(name:type:)")));

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
@property (readonly) NSString *name __attribute__((swift_name("name")));
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
@interface LMDKtor_eventsEventDefinition<T> : LMDBase

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

__attribute__((swift_name("Kotlinx_coroutines_coreDisposableHandle")))
@protocol LMDKotlinx_coroutines_coreDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
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
@interface LMDKtor_utilsPipelinePhase : LMDBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("KotlinFunction")))
@protocol LMDKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction2")))
@protocol LMDKotlinSuspendFunction2 <LMDKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpReceivePipeline.Phases")))
@interface LMDKtor_client_coreHttpReceivePipelinePhases : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_client_coreHttpReceivePipelinePhases *shared __attribute__((swift_name("shared")));

/**
 * Latest response pipeline phase
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline.Phases.After)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));

/**
 * The earliest phase that happens before any other
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline.Phases.Before)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));

/**
 * Use this phase to store request shared state
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpReceivePipeline.Phases.State)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end


/**
 * A message either from the client or the server,
 * that has [headers] associated.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessage)
 */
__attribute__((swift_name("Ktor_httpHttpMessage")))
@protocol LMDKtor_httpHttpMessage
@required

/**
 * Message [Headers]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessage.headers)
 */
@property (readonly) id<LMDKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@end


/**
 * An [HttpClient]'s response, a second part of [HttpClientCall].
 *
 * Learn more from [Receiving responses](https://ktor.io/docs/response.html).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse)
 */
__attribute__((swift_name("Ktor_client_coreHttpResponse")))
@interface LMDKtor_client_coreHttpResponse : LMDBase <LMDKtor_httpHttpMessage, LMDKotlinx_coroutines_coreCoroutineScope>

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
@property (readonly) LMDKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));

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
@property (readonly) id<LMDKtor_ioByteReadChannel> rawContent __attribute__((swift_name("rawContent")));

/**
 * [GMTDate] of the request start.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.requestTime)
 */
@property (readonly) LMDKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));

/**
 * [GMTDate] of the response start.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.responseTime)
 */
@property (readonly) LMDKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));

/**
 * The [HttpStatusCode] returned by the server. It includes both,
 * the [HttpStatusCode.description] and the [HttpStatusCode.value] (code).
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.status)
 */
@property (readonly) LMDKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));

/**
 * HTTP version. Usually [HttpProtocolVersion.HTTP_1_1] or [HttpProtocolVersion.HTTP_2_0].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponse.version)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end


/**
 * All interceptors accept payload as [subject] and try to convert it to [OutgoingContent].
 * Last phase should proceed with [HttpClientCall].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpRequestPipeline.Phases")))
@interface LMDKtor_client_coreHttpRequestPipelinePhases : LMDBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * All interceptors accept payload as [subject] and try to convert it to [OutgoingContent].
 * Last phase should proceed with [HttpClientCall].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_client_coreHttpRequestPipelinePhases *shared __attribute__((swift_name("shared")));

/**
 * The earliest phase that happens before any other.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Before)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));

/**
 * Encode a request body to [OutgoingContent].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Render)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Render __attribute__((swift_name("Render")));

/**
 * A phase for the [HttpSend] plugin.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Send)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Send __attribute__((swift_name("Send")));

/**
 * Use this phase to modify a request with a shared state.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.State)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));

/**
 * Transform a request body to supported render format.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestPipeline.Phases.Transform)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end


/**
 * A builder message either for the client or the server,
 * that has a [headers] builder associated.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessageBuilder)
 */
__attribute__((swift_name("Ktor_httpHttpMessageBuilder")))
@protocol LMDKtor_httpHttpMessageBuilder
@required

/**
 * MessageBuilder [HeadersBuilder]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMessageBuilder.headers)
 */
@property (readonly) LMDKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
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
@interface LMDKtor_client_coreHttpRequestBuilder : LMDBase <LMDKtor_httpHttpMessageBuilder>

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
@property (class, readonly, getter=companion) LMDKtor_client_coreHttpRequestBuilderCompanion *companion __attribute__((swift_name("companion")));

/**
 * Creates immutable [HttpRequestData].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.build)
 */
- (LMDKtor_client_coreHttpRequestData *)build __attribute__((swift_name("build()")));

/**
 * Retrieves capability by the key.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.getCapabilityOrNull)
 */
- (id _Nullable)getCapabilityOrNullKey:(id<LMDKtor_client_coreHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));

/**
 * Sets request-specific attributes specified by [block].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.setAttributes)
 */
- (void)setAttributesBlock:(void (^)(id<LMDKtor_utilsAttributes>))block __attribute__((swift_name("setAttributes(block:)")));

/**
 * Sets capability configuration.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.setCapability)
 */
- (void)setCapabilityKey:(id<LMDKtor_client_coreHttpClientEngineCapability>)key capability:(id)capability __attribute__((swift_name("setCapability(key:capability:)")));

/**
 * Mutates [this] by copying all the data but execution context from another [builder] using it as the base.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.takeFrom)
 */
- (LMDKtor_client_coreHttpRequestBuilder *)takeFromBuilder:(LMDKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFrom(builder:)")));

/**
 * Mutates [this] copying all the data from another [builder] using it as the base.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.takeFromWithExecutionContext)
 */
- (LMDKtor_client_coreHttpRequestBuilder *)takeFromWithExecutionContextBuilder:(LMDKtor_client_coreHttpRequestBuilder *)builder __attribute__((swift_name("takeFromWithExecutionContext(builder:)")));

/**
 * Executes a [block] that configures the [URLBuilder] associated to this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.url)
 */
- (void)urlBlock:(void (^)(LMDKtor_httpURLBuilder *, LMDKtor_httpURLBuilder *))block __attribute__((swift_name("url(block:)")));

/**
 * Provides access to attributes specific for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.attributes)
 */
@property (readonly) id<LMDKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));

/**
 * The [body] for this request. Initially [EmptyContent].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.body)
 */
@property id body __attribute__((swift_name("body")));

/**
 * The [KType] of [body] for this request. Null for default types that don't need serialization.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.bodyType)
 */
@property LMDKtor_utilsTypeInfo * _Nullable bodyType __attribute__((swift_name("bodyType")));

/**
 * A deferred used to control the execution of this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.executionContext)
 */
@property (readonly) id<LMDKotlinx_coroutines_coreJob> executionContext __attribute__((swift_name("executionContext")));

/**
 * [HeadersBuilder] to configure the headers for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.headers)
 */
@property (readonly) LMDKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));

/**
 * [HttpMethod] used by this request. [HttpMethod.Get] by default.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.method)
 */
@property LMDKtor_httpHttpMethod *method __attribute__((swift_name("method")));

/**
 * [URLBuilder] to configure the URL for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequestBuilder.url)
 */
@property (readonly) LMDKtor_httpURLBuilder *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpResponsePipeline.Phases")))
@interface LMDKtor_client_coreHttpResponsePipelinePhases : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_client_coreHttpResponsePipelinePhases *shared __attribute__((swift_name("shared")));

/**
 * Latest response pipeline phase
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.After)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));

/**
 * Decode response body
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.Parse)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Parse __attribute__((swift_name("Parse")));

/**
 * The earliest phase that happens before any other
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.Receive)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));

/**
 * Use this phase to store request shared state
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.State)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));

/**
 * Transform response body to expected format
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.statement.HttpResponsePipeline.Phases.Transform)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
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
@interface LMDKtor_client_coreHttpResponseContainer : LMDBase
- (instancetype)initWithExpectedType:(LMDKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("init(expectedType:response:)"))) __attribute__((objc_designated_initializer));
- (LMDKtor_client_coreHttpResponseContainer *)doCopyExpectedType:(LMDKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("doCopy(expectedType:response:)")));

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
@property (readonly) LMDKtor_utilsTypeInfo *expectedType __attribute__((swift_name("expectedType")));
@property (readonly) id response __attribute__((swift_name("response")));
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
@interface LMDKtor_client_coreHttpClientCall : LMDBase <LMDKotlinx_coroutines_coreCoroutineScope>
- (instancetype)initWithClient:(LMDKtor_client_coreHttpClient *)client __attribute__((swift_name("init(client:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithClient:(LMDKtor_client_coreHttpClient *)client requestData:(LMDKtor_client_coreHttpRequestData *)requestData responseData:(LMDKtor_client_coreHttpResponseData *)responseData __attribute__((swift_name("init(client:requestData:responseData:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_client_coreHttpClientCallCompanion *companion __attribute__((swift_name("companion")));

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
- (void)bodyInfo:(LMDKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("body(info:completionHandler:)")));

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
- (void)bodyNullableInfo:(LMDKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyNullable(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)getResponseContentWithCompletionHandler:(void (^)(id<LMDKtor_ioByteReadChannel> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getResponseContent(completionHandler:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) BOOL allowDoubleReceive __attribute__((swift_name("allowDoubleReceive")));

/**
 * Typed [Attributes] associated to this call serving as a lightweight container.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.attributes)
 */
@property (readonly) id<LMDKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) LMDKtor_client_coreHttpClient *client __attribute__((swift_name("client")));
@property (readonly) id<LMDKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));

/**
 * The [request] sent by the client.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.request)
 */
@property id<LMDKtor_client_coreHttpRequest> request __attribute__((swift_name("request")));

/**
 * The [response] sent by the server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.call.HttpClientCall.response)
 */
@property LMDKtor_client_coreHttpResponse *response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpSendPipeline.Phases")))
@interface LMDKtor_client_coreHttpSendPipelinePhases : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_client_coreHttpSendPipelinePhases *shared __attribute__((swift_name("shared")));

/**
 * The earliest phase that happens before any other.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Before)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));

/**
 * Send a request to a remote server.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Engine)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Engine __attribute__((swift_name("Engine")));

/**
 * Use this phase for logging and other actions that don't modify a request or shared data.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Monitoring)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Monitoring __attribute__((swift_name("Monitoring")));

/**
 * Receive a pipeline execution phase.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.Receive)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));

/**
 * Use this phase to modify request with a shared state.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpSendPipeline.Phases.State)
 */
@property (readonly) LMDKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonClassDiscriminatorMode")))
@interface LMDKotlinx_serialization_jsonClassDiscriminatorMode : LMDKotlinEnum<LMDKotlinx_serialization_jsonClassDiscriminatorMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) LMDKotlinx_serialization_jsonClassDiscriminatorMode *none __attribute__((swift_name("none")));
@property (class, readonly) LMDKotlinx_serialization_jsonClassDiscriminatorMode *allJsonObjects __attribute__((swift_name("allJsonObjects")));
@property (class, readonly) LMDKotlinx_serialization_jsonClassDiscriminatorMode *polymorphic __attribute__((swift_name("polymorphic")));
+ (LMDKotlinArray<LMDKotlinx_serialization_jsonClassDiscriminatorMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDKotlinx_serialization_jsonClassDiscriminatorMode *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonNamingStrategy")))
@protocol LMDKotlinx_serialization_jsonJsonNamingStrategy
@required
- (NSString *)serialNameForJsonDescriptor:(id<LMDKotlinx_serialization_coreSerialDescriptor>)descriptor elementIndex:(int32_t)elementIndex serialName:(NSString *)serialName __attribute__((swift_name("serialNameForJson(descriptor:elementIndex:serialName:)")));
@end

__attribute__((swift_name("Ktor_ioJvmSerializable")))
@protocol LMDKtor_ioJvmSerializable
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
@interface LMDKtor_httpUrl : LMDBase <LMDKtor_ioJvmSerializable>
@property (class, readonly, getter=companion) LMDKtor_httpUrlCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property (readonly) NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property (readonly) NSString *encodedPath __attribute__((swift_name("encodedPath")));
@property (readonly) NSString *encodedPathAndQuery __attribute__((swift_name("encodedPathAndQuery")));
@property (readonly) NSString *encodedQuery __attribute__((swift_name("encodedQuery")));
@property (readonly) NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property (readonly) NSString *fragment __attribute__((swift_name("fragment")));
@property (readonly) NSString *host __attribute__((swift_name("host")));
@property (readonly) id<LMDKtor_httpParameters> parameters __attribute__((swift_name("parameters")));
@property (readonly) NSString * _Nullable password __attribute__((swift_name("password")));

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
@property (readonly) NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments"))) __attribute__((deprecated("\n        `pathSegments` is deprecated.\n\n        This property will contain an empty path segment at the beginning for URLs with a hostname,\n        and an empty path segment at the end for the URLs with a trailing slash. If you need to keep this behaviour please\n        use [rawSegments]. If you only need to access the meaningful parts of the path, consider using [segments] instead.\n             \n        Please decide if you need [rawSegments] or [segments] explicitly.\n        ")));
@property (readonly) int32_t port __attribute__((swift_name("port")));
@property (readonly) LMDKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property (readonly) LMDKtor_httpURLProtocol * _Nullable protocolOrNull __attribute__((swift_name("protocolOrNull")));

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
@property (readonly) NSArray<NSString *> *rawSegments __attribute__((swift_name("rawSegments")));

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
@property (readonly) NSArray<NSString *> *segments __attribute__((swift_name("segments")));
@property (readonly) int32_t specifiedPort __attribute__((swift_name("specifiedPort")));
@property (readonly) BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property (readonly) NSString * _Nullable user __attribute__((swift_name("user")));
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
@interface LMDKtor_httpHttpMethod : LMDBase
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_httpHttpMethodCompanion *companion __attribute__((swift_name("companion")));
- (LMDKtor_httpHttpMethod *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));

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
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end


/**
 * Provides data structure for associating a [String] with a [List] of Strings
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.StringValues)
 */
__attribute__((swift_name("Ktor_utilsStringValues")))
@protocol LMDKtor_utilsStringValues
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
- (NSSet<id<LMDKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));

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
@protocol LMDKtor_httpHeaders <LMDKtor_utilsStringValues>
@required
@end


/**
 * Information about the content to be sent to the peer, recognized by a client or server engine
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent)
 */
__attribute__((swift_name("Ktor_httpOutgoingContent")))
@interface LMDKtor_httpOutgoingContent : LMDBase

/**
 * Gets an extension property for this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.getProperty)
 */
- (id _Nullable)getPropertyKey:(LMDKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));

/**
 * Sets an extension property for this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.setProperty)
 */
- (void)setPropertyKey:(LMDKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));

/**
 * Trailers to set when sending this content, will be ignored if request is not in HTTP2 mode
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.trailers)
 */
- (id<LMDKtor_httpHeaders> _Nullable)trailers __attribute__((swift_name("trailers()")));

/**
 * Specifies content length in bytes for this resource.
 *
 * If null, the resources will be sent as `Transfer-Encoding: chunked`
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.contentLength)
 */
@property (readonly) LMDLong * _Nullable contentLength __attribute__((swift_name("contentLength")));

/**
 * Specifies [ContentType] for this resource.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.contentType)
 */
@property (readonly) LMDKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));

/**
 * Headers to set when sending this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.headers)
 */
@property (readonly) id<LMDKtor_httpHeaders> headers __attribute__((swift_name("headers")));

/**
 * Status code to set when sending this content
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.content.OutgoingContent.status)
 */
@property (readonly) LMDKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/InternalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreJob")))
@protocol LMDKotlinx_coroutines_coreJob <LMDKotlinCoroutineContextElement>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<LMDKotlinx_coroutines_coreChildHandle>)attachChildChild:(id<LMDKotlinx_coroutines_coreChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(LMDKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (LMDKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<LMDKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionHandler:(void (^)(LMDKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<LMDKotlinx_coroutines_coreDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(LMDKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<LMDKotlinx_coroutines_coreJob>)plusOther_:(id<LMDKotlinx_coroutines_coreJob>)other __attribute__((swift_name("plus(other_:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<LMDKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<LMDKotlinx_coroutines_coreSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<LMDKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
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
@interface LMDKtor_httpHttpStatusCode : LMDBase <LMDKotlinComparable>
- (instancetype)initWithValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("init(value:description:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_httpHttpStatusCodeCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(LMDKtor_httpHttpStatusCode *)other __attribute__((swift_name("compareTo(other:)")));
- (LMDKtor_httpHttpStatusCode *)doCopyValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("doCopy(value:description:)")));

/**
 * Returns a copy of `this` code with a description changed to [value].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode.description)
 */
- (LMDKtor_httpHttpStatusCode *)descriptionValue:(NSString *)value __attribute__((swift_name("description(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
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
@interface LMDKtor_utilsGMTDate : LMDBase <LMDKotlinComparable>
- (instancetype)initWithSeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(LMDKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(LMDKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("init(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_utilsGMTDateCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(LMDKtor_utilsGMTDate *)other __attribute__((swift_name("compareTo(other:)")));
- (LMDKtor_utilsGMTDate *)doCopy __attribute__((swift_name("doCopy()")));
- (LMDKtor_utilsGMTDate *)doCopySeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(LMDKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(LMDKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("doCopy(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)")));

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
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth")));
@property (readonly) LMDKtor_utilsWeekDay *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) LMDKtor_utilsMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int64_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
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
@interface LMDKtor_httpHttpProtocolVersion : LMDBase
- (instancetype)initWithName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("init(name:major:minor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_httpHttpProtocolVersionCompanion *companion __attribute__((swift_name("companion")));
- (LMDKtor_httpHttpProtocolVersion *)doCopyName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("doCopy(name:major:minor:)")));

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
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol LMDKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<LMDKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface LMDKotlinAbstractCoroutineContextKey<B, E> : LMDBase <LMDKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<LMDKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<LMDKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface LMDKotlinx_coroutines_coreCoroutineDispatcherKey : LMDKotlinAbstractCoroutineContextKey<id<LMDKotlinContinuationInterceptor>, LMDKotlinx_coroutines_coreCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<LMDKotlinCoroutineContextKey>)baseKey safeCast:(id<LMDKotlinCoroutineContextElement> _Nullable (^)(id<LMDKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol LMDKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
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
@interface LMDKtor_utilsTypeInfo : LMDBase
- (instancetype)initWithType:(id<LMDKotlinKClass>)type kotlinType:(id<LMDKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:kotlinType:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithType:(id<LMDKotlinKClass>)type reifiedType:(id<LMDKotlinKType>)reifiedType kotlinType:(id<LMDKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:reifiedType:kotlinType:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("Use constructor without reifiedType parameter.")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<LMDKotlinKType> _Nullable kotlinType __attribute__((swift_name("kotlinType")));
@property (readonly) id<LMDKotlinKClass> type __attribute__((swift_name("type")));
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
@protocol LMDKtor_ioByteReadChannel
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
- (void)awaitContentMin:(int32_t)min completionHandler:(void (^)(LMDBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitContent(min:completionHandler:)")));
- (void)cancelCause_:(LMDKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));
@property (readonly) LMDKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForRead __attribute__((swift_name("isClosedForRead")));
@property (readonly) id<LMDKotlinx_io_coreSource> readBuffer __attribute__((swift_name("readBuffer")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilder")))
@protocol LMDKtor_utilsStringValuesBuilder
@required
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<LMDKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<LMDKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<LMDKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<LMDKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
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
@interface LMDKtor_utilsStringValuesBuilderImpl : LMDBase <LMDKtor_utilsStringValuesBuilder>
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer));
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<LMDKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<LMDKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<LMDKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<LMDKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
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
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) LMDMutableDictionary<NSString *, NSMutableArray<NSString *> *> *values __attribute__((swift_name("values")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeadersBuilder")))
@interface LMDKtor_httpHeadersBuilder : LMDKtor_utilsStringValuesBuilderImpl
- (instancetype)initWithSize:(int32_t)size __attribute__((swift_name("init(size:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (id<LMDKtor_httpHeaders>)build __attribute__((swift_name("build()")));

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
@interface LMDKtor_client_coreHttpRequestBuilderCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_client_coreHttpRequestBuilderCompanion *shared __attribute__((swift_name("shared")));
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
@interface LMDKtor_httpURLBuilder : LMDBase
- (instancetype)initWithProtocol:(LMDKtor_httpURLProtocol * _Nullable)protocol host:(NSString *)host port:(int32_t)port user:(NSString * _Nullable)user password:(NSString * _Nullable)password pathSegments:(NSArray<NSString *> *)pathSegments parameters:(id<LMDKtor_httpParameters>)parameters fragment:(NSString *)fragment trailingQuery:(BOOL)trailingQuery __attribute__((swift_name("init(protocol:host:port:user:password:pathSegments:parameters:fragment:trailingQuery:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_httpURLBuilderCompanion *companion __attribute__((swift_name("companion")));

/**
 * Build a [Url] instance (everything is copied to a new instance)
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLBuilder.build)
 */
- (LMDKtor_httpUrl *)build __attribute__((swift_name("build()")));

/**
 * Build a URL string
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLBuilder.buildString)
 */
- (NSString *)buildString __attribute__((swift_name("buildString()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property id<LMDKtor_httpParametersBuilder> encodedParameters __attribute__((swift_name("encodedParameters")));
@property NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property NSArray<NSString *> *encodedPathSegments __attribute__((swift_name("encodedPathSegments")));
@property NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property NSString *fragment __attribute__((swift_name("fragment")));
@property NSString *host __attribute__((swift_name("host")));
@property (readonly) id<LMDKtor_httpParametersBuilder> parameters __attribute__((swift_name("parameters")));
@property NSString * _Nullable password __attribute__((swift_name("password")));
@property NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property int32_t port __attribute__((swift_name("port")));
@property LMDKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property LMDKtor_httpURLProtocol * _Nullable protocolOrNull __attribute__((swift_name("protocolOrNull")));
@property BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property NSString * _Nullable user __attribute__((swift_name("user")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_client_coreHttpClientCall.Companion")))
@interface LMDKtor_client_coreHttpClientCallCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_client_coreHttpClientCallCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * A request for [HttpClient], first part of [HttpClientCall].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest)
 */
__attribute__((swift_name("Ktor_client_coreHttpRequest")))
@protocol LMDKtor_client_coreHttpRequest <LMDKtor_httpHttpMessage, LMDKotlinx_coroutines_coreCoroutineScope>
@required

/**
 * Typed [Attributes] associated to this call serving as a lightweight container.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.attributes)
 */
@property (readonly) id<LMDKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));

/**
 * The associated [HttpClientCall] containing both
 * the underlying [HttpClientCall.request] and [HttpClientCall.response].
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.call)
 */
@property (readonly) LMDKtor_client_coreHttpClientCall *call __attribute__((swift_name("call")));

/**
 * An [OutgoingContent] representing the request body
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.content)
 */
@property (readonly) LMDKtor_httpOutgoingContent *content __attribute__((swift_name("content")));

/**
 * The [HttpMethod] or HTTP VERB used for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.method)
 */
@property (readonly) LMDKtor_httpHttpMethod *method __attribute__((swift_name("method")));

/**
 * The [Url] representing the endpoint and the uri for this request.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.client.request.HttpRequest.url)
 */
@property (readonly) LMDKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl.Companion")))
@interface LMDKtor_httpUrlCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpUrlCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * Represents HTTP parameters as a map from case-insensitive names to collection of [String] values
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.Parameters)
 */
__attribute__((swift_name("Ktor_httpParameters")))
@protocol LMDKtor_httpParameters <LMDKtor_utilsStringValues>
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
@interface LMDKtor_httpURLProtocol : LMDBase <LMDKtor_ioJvmSerializable>
- (instancetype)initWithName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("init(name:defaultPort:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_httpURLProtocolCompanion *companion __attribute__((swift_name("companion")));
- (LMDKtor_httpURLProtocol *)doCopyName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("doCopy(name:defaultPort:)")));

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
@property (readonly) int32_t defaultPort __attribute__((swift_name("defaultPort")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod.Companion")))
@interface LMDKtor_httpHttpMethodCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpHttpMethodCompanion *shared __attribute__((swift_name("shared")));

/**
 * Parse HTTP method by [method] string
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod.Companion.parse)
 */
- (LMDKtor_httpHttpMethod *)parseMethod:(NSString *)method __attribute__((swift_name("parse(method:)")));

/**
 * A list of default HTTP methods
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpMethod.Companion.DefaultMethods)
 */
@property (readonly) NSArray<LMDKtor_httpHttpMethod *> *DefaultMethods __attribute__((swift_name("DefaultMethods")));
@property (readonly) LMDKtor_httpHttpMethod *Delete __attribute__((swift_name("Delete")));
@property (readonly) LMDKtor_httpHttpMethod *Get __attribute__((swift_name("Get")));
@property (readonly) LMDKtor_httpHttpMethod *Head __attribute__((swift_name("Head")));
@property (readonly) LMDKtor_httpHttpMethod *Options __attribute__((swift_name("Options")));
@property (readonly) LMDKtor_httpHttpMethod *Patch __attribute__((swift_name("Patch")));
@property (readonly) LMDKtor_httpHttpMethod *Post __attribute__((swift_name("Post")));
@property (readonly) LMDKtor_httpHttpMethod *Put __attribute__((swift_name("Put")));
@end

__attribute__((swift_name("KotlinMapEntry")))
@protocol LMDKotlinMapEntry
@required
@property (readonly) id _Nullable key __attribute__((swift_name("key")));
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
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
@interface LMDKtor_httpHeaderValueWithParameters : LMDBase
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<LMDKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKtor_httpHeaderValueWithParametersCompanion *companion __attribute__((swift_name("companion")));

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
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) NSArray<LMDKtor_httpHeaderValueParam *> *parameters __attribute__((swift_name("parameters")));
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
@interface LMDKtor_httpContentType : LMDKtor_httpHeaderValueWithParameters
- (instancetype)initWithContentType:(NSString *)contentType contentSubtype:(NSString *)contentSubtype parameters:(NSArray<LMDKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(contentType:contentSubtype:parameters:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<LMDKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_httpContentTypeCompanion *companion __attribute__((swift_name("companion")));
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
- (BOOL)matchPattern:(LMDKtor_httpContentType *)pattern __attribute__((swift_name("match(pattern:)")));

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
- (LMDKtor_httpContentType *)withParameterName:(NSString *)name value:(NSString *)value __attribute__((swift_name("withParameter(name:value:)")));

/**
 * Creates a copy of `this` type without any parameters
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.withoutParameters)
 */
- (LMDKtor_httpContentType *)withoutParameters __attribute__((swift_name("withoutParameters()")));
@property (readonly) NSString *contentSubtype __attribute__((swift_name("contentSubtype")));
@property (readonly) NSString *contentType __attribute__((swift_name("contentType")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildHandle")))
@protocol LMDKotlinx_coroutines_coreChildHandle <LMDKotlinx_coroutines_coreDisposableHandle>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BOOL)childCancelledCause:(LMDKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
@property (readonly) id<LMDKotlinx_coroutines_coreJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreChildJob")))
@protocol LMDKotlinx_coroutines_coreChildJob <LMDKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)parentCancelledParentJob:(id<LMDKotlinx_coroutines_coreParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol LMDKotlinSequence
@required
- (id<LMDKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreSelectClause0")))
@protocol LMDKotlinx_coroutines_coreSelectClause0 <LMDKotlinx_coroutines_coreSelectClause>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode.Companion")))
@interface LMDKtor_httpHttpStatusCodeCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpHttpStatusCodeCompanion *shared __attribute__((swift_name("shared")));

/**
 * Creates an instance of [HttpStatusCode] with the given numeric value.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode.Companion.fromValue)
 */
- (LMDKtor_httpHttpStatusCode *)fromValueValue:(int32_t)value __attribute__((swift_name("fromValue(value:)")));
@property (readonly) LMDKtor_httpHttpStatusCode *Accepted __attribute__((swift_name("Accepted")));
@property (readonly) LMDKtor_httpHttpStatusCode *BadGateway __attribute__((swift_name("BadGateway")));
@property (readonly) LMDKtor_httpHttpStatusCode *BadRequest __attribute__((swift_name("BadRequest")));
@property (readonly) LMDKtor_httpHttpStatusCode *Conflict __attribute__((swift_name("Conflict")));
@property (readonly) LMDKtor_httpHttpStatusCode *Continue __attribute__((swift_name("Continue")));
@property (readonly) LMDKtor_httpHttpStatusCode *Created __attribute__((swift_name("Created")));
@property (readonly) LMDKtor_httpHttpStatusCode *ExpectationFailed __attribute__((swift_name("ExpectationFailed")));
@property (readonly) LMDKtor_httpHttpStatusCode *FailedDependency __attribute__((swift_name("FailedDependency")));
@property (readonly) LMDKtor_httpHttpStatusCode *Forbidden __attribute__((swift_name("Forbidden")));
@property (readonly) LMDKtor_httpHttpStatusCode *Found __attribute__((swift_name("Found")));
@property (readonly) LMDKtor_httpHttpStatusCode *GatewayTimeout __attribute__((swift_name("GatewayTimeout")));
@property (readonly) LMDKtor_httpHttpStatusCode *Gone __attribute__((swift_name("Gone")));
@property (readonly) LMDKtor_httpHttpStatusCode *InsufficientStorage __attribute__((swift_name("InsufficientStorage")));
@property (readonly) LMDKtor_httpHttpStatusCode *InternalServerError __attribute__((swift_name("InternalServerError")));
@property (readonly) LMDKtor_httpHttpStatusCode *LengthRequired __attribute__((swift_name("LengthRequired")));
@property (readonly) LMDKtor_httpHttpStatusCode *Locked __attribute__((swift_name("Locked")));
@property (readonly) LMDKtor_httpHttpStatusCode *MethodNotAllowed __attribute__((swift_name("MethodNotAllowed")));
@property (readonly) LMDKtor_httpHttpStatusCode *MovedPermanently __attribute__((swift_name("MovedPermanently")));
@property (readonly) LMDKtor_httpHttpStatusCode *MultiStatus __attribute__((swift_name("MultiStatus")));
@property (readonly) LMDKtor_httpHttpStatusCode *MultipleChoices __attribute__((swift_name("MultipleChoices")));
@property (readonly) LMDKtor_httpHttpStatusCode *NoContent __attribute__((swift_name("NoContent")));
@property (readonly) LMDKtor_httpHttpStatusCode *NonAuthoritativeInformation __attribute__((swift_name("NonAuthoritativeInformation")));
@property (readonly) LMDKtor_httpHttpStatusCode *NotAcceptable __attribute__((swift_name("NotAcceptable")));
@property (readonly) LMDKtor_httpHttpStatusCode *NotFound __attribute__((swift_name("NotFound")));
@property (readonly) LMDKtor_httpHttpStatusCode *NotImplemented __attribute__((swift_name("NotImplemented")));
@property (readonly) LMDKtor_httpHttpStatusCode *NotModified __attribute__((swift_name("NotModified")));
@property (readonly) LMDKtor_httpHttpStatusCode *OK __attribute__((swift_name("OK")));
@property (readonly) LMDKtor_httpHttpStatusCode *PartialContent __attribute__((swift_name("PartialContent")));
@property (readonly) LMDKtor_httpHttpStatusCode *PayloadTooLarge __attribute__((swift_name("PayloadTooLarge")));
@property (readonly) LMDKtor_httpHttpStatusCode *PaymentRequired __attribute__((swift_name("PaymentRequired")));
@property (readonly) LMDKtor_httpHttpStatusCode *PermanentRedirect __attribute__((swift_name("PermanentRedirect")));
@property (readonly) LMDKtor_httpHttpStatusCode *PreconditionFailed __attribute__((swift_name("PreconditionFailed")));
@property (readonly) LMDKtor_httpHttpStatusCode *Processing __attribute__((swift_name("Processing")));
@property (readonly) LMDKtor_httpHttpStatusCode *ProxyAuthenticationRequired __attribute__((swift_name("ProxyAuthenticationRequired")));
@property (readonly) LMDKtor_httpHttpStatusCode *RequestHeaderFieldTooLarge __attribute__((swift_name("RequestHeaderFieldTooLarge")));
@property (readonly) LMDKtor_httpHttpStatusCode *RequestTimeout __attribute__((swift_name("RequestTimeout")));
@property (readonly) LMDKtor_httpHttpStatusCode *RequestURITooLong __attribute__((swift_name("RequestURITooLong")));
@property (readonly) LMDKtor_httpHttpStatusCode *RequestedRangeNotSatisfiable __attribute__((swift_name("RequestedRangeNotSatisfiable")));
@property (readonly) LMDKtor_httpHttpStatusCode *ResetContent __attribute__((swift_name("ResetContent")));
@property (readonly) LMDKtor_httpHttpStatusCode *SeeOther __attribute__((swift_name("SeeOther")));
@property (readonly) LMDKtor_httpHttpStatusCode *ServiceUnavailable __attribute__((swift_name("ServiceUnavailable")));
@property (readonly) LMDKtor_httpHttpStatusCode *SwitchProxy __attribute__((swift_name("SwitchProxy")));
@property (readonly) LMDKtor_httpHttpStatusCode *SwitchingProtocols __attribute__((swift_name("SwitchingProtocols")));
@property (readonly) LMDKtor_httpHttpStatusCode *TemporaryRedirect __attribute__((swift_name("TemporaryRedirect")));
@property (readonly) LMDKtor_httpHttpStatusCode *TooEarly __attribute__((swift_name("TooEarly")));
@property (readonly) LMDKtor_httpHttpStatusCode *TooManyRequests __attribute__((swift_name("TooManyRequests")));
@property (readonly) LMDKtor_httpHttpStatusCode *Unauthorized __attribute__((swift_name("Unauthorized")));
@property (readonly) LMDKtor_httpHttpStatusCode *UnprocessableEntity __attribute__((swift_name("UnprocessableEntity")));
@property (readonly) LMDKtor_httpHttpStatusCode *UnsupportedMediaType __attribute__((swift_name("UnsupportedMediaType")));
@property (readonly) LMDKtor_httpHttpStatusCode *UpgradeRequired __attribute__((swift_name("UpgradeRequired")));
@property (readonly) LMDKtor_httpHttpStatusCode *UseProxy __attribute__((swift_name("UseProxy")));
@property (readonly) LMDKtor_httpHttpStatusCode *VariantAlsoNegotiates __attribute__((swift_name("VariantAlsoNegotiates")));
@property (readonly) LMDKtor_httpHttpStatusCode *VersionNotSupported __attribute__((swift_name("VersionNotSupported")));

/**
 * All known status codes
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpStatusCode.Companion.allStatusCodes)
 */
@property (readonly) NSArray<LMDKtor_httpHttpStatusCode *> *allStatusCodes __attribute__((swift_name("allStatusCodes")));
@end


/**
 * Day of week
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay")))
@interface LMDKtor_utilsWeekDay : LMDKotlinEnum<LMDKtor_utilsWeekDay *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Day of week
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_utilsWeekDayCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LMDKtor_utilsWeekDay *monday __attribute__((swift_name("monday")));
@property (class, readonly) LMDKtor_utilsWeekDay *tuesday __attribute__((swift_name("tuesday")));
@property (class, readonly) LMDKtor_utilsWeekDay *wednesday __attribute__((swift_name("wednesday")));
@property (class, readonly) LMDKtor_utilsWeekDay *thursday __attribute__((swift_name("thursday")));
@property (class, readonly) LMDKtor_utilsWeekDay *friday __attribute__((swift_name("friday")));
@property (class, readonly) LMDKtor_utilsWeekDay *saturday __attribute__((swift_name("saturday")));
@property (class, readonly) LMDKtor_utilsWeekDay *sunday __attribute__((swift_name("sunday")));
+ (LMDKotlinArray<LMDKtor_utilsWeekDay *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDKtor_utilsWeekDay *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end


/**
 * Month
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month)
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth")))
@interface LMDKtor_utilsMonth : LMDKotlinEnum<LMDKtor_utilsMonth *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Month
 * [value] is 3 letter shortcut
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month)
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) LMDKtor_utilsMonthCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) LMDKtor_utilsMonth *january __attribute__((swift_name("january")));
@property (class, readonly) LMDKtor_utilsMonth *february __attribute__((swift_name("february")));
@property (class, readonly) LMDKtor_utilsMonth *march __attribute__((swift_name("march")));
@property (class, readonly) LMDKtor_utilsMonth *april __attribute__((swift_name("april")));
@property (class, readonly) LMDKtor_utilsMonth *may __attribute__((swift_name("may")));
@property (class, readonly) LMDKtor_utilsMonth *june __attribute__((swift_name("june")));
@property (class, readonly) LMDKtor_utilsMonth *july __attribute__((swift_name("july")));
@property (class, readonly) LMDKtor_utilsMonth *august __attribute__((swift_name("august")));
@property (class, readonly) LMDKtor_utilsMonth *september __attribute__((swift_name("september")));
@property (class, readonly) LMDKtor_utilsMonth *october __attribute__((swift_name("october")));
@property (class, readonly) LMDKtor_utilsMonth *november __attribute__((swift_name("november")));
@property (class, readonly) LMDKtor_utilsMonth *december __attribute__((swift_name("december")));
+ (LMDKotlinArray<LMDKtor_utilsMonth *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDKtor_utilsMonth *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate.Companion")))
@interface LMDKtor_utilsGMTDateCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_utilsGMTDateCompanion *shared __attribute__((swift_name("shared")));
- (id<LMDKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));

/**
 * An instance of [GMTDate] corresponding to the epoch beginning
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.GMTDate.Companion.START)
 */
@property (readonly) LMDKtor_utilsGMTDate *START __attribute__((swift_name("START")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion.Companion")))
@interface LMDKtor_httpHttpProtocolVersionCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpHttpProtocolVersionCompanion *shared __attribute__((swift_name("shared")));

/**
 * Creates an instance of [HttpProtocolVersion] from the given parameters.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.fromValue)
 */
- (LMDKtor_httpHttpProtocolVersion *)fromValueName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("fromValue(name:major:minor:)")));

/**
 * Create an instance of [HttpProtocolVersion] from http string representation.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.parse)
 */
- (LMDKtor_httpHttpProtocolVersion *)parseValue:(id)value __attribute__((swift_name("parse(value:)")));

/**
 * HTTP/1.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_1_0)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *HTTP_1_0 __attribute__((swift_name("HTTP_1_0")));

/**
 * HTTP/1.1 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_1_1)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *HTTP_1_1 __attribute__((swift_name("HTTP_1_1")));

/**
 * HTTP/2.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_2_0)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *HTTP_2_0 __attribute__((swift_name("HTTP_2_0")));

/**
 * HTTP/3.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.HTTP_3_0)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *HTTP_3_0 __attribute__((swift_name("HTTP_3_0")));

/**
 * QUIC/1.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.QUIC)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *QUIC __attribute__((swift_name("QUIC")));

/**
 * SPDY/3.0 version.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HttpProtocolVersion.Companion.SPDY_3)
 */
@property (readonly) LMDKtor_httpHttpProtocolVersion *SPDY_3 __attribute__((swift_name("SPDY_3")));
@end

__attribute__((swift_name("KotlinKType")))
@protocol LMDKotlinKType
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) NSArray<LMDKotlinKTypeProjection *> *arguments __attribute__((swift_name("arguments")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) id<LMDKotlinKClassifier> _Nullable classifier __attribute__((swift_name("classifier")));
@property (readonly) BOOL isMarkedNullable __attribute__((swift_name("isMarkedNullable")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder.Companion")))
@interface LMDKtor_httpURLBuilderCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpURLBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Ktor_httpParametersBuilder")))
@protocol LMDKtor_httpParametersBuilder <LMDKtor_utilsStringValuesBuilder>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol.Companion")))
@interface LMDKtor_httpURLProtocolCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpURLProtocolCompanion *shared __attribute__((swift_name("shared")));

/**
 * Create an instance by [name] or use already existing instance
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.createOrDefault)
 */
- (LMDKtor_httpURLProtocol *)createOrDefaultName:(NSString *)name __attribute__((swift_name("createOrDefault(name:)")));

/**
 * HTTP with port 80
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.HTTP)
 */
@property (readonly) LMDKtor_httpURLProtocol *HTTP __attribute__((swift_name("HTTP")));

/**
 * secure HTTPS with port 443
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.HTTPS)
 */
@property (readonly) LMDKtor_httpURLProtocol *HTTPS __attribute__((swift_name("HTTPS")));

/**
 * Socks proxy url protocol.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.SOCKS)
 */
@property (readonly) LMDKtor_httpURLProtocol *SOCKS __attribute__((swift_name("SOCKS")));

/**
 * Web socket over HTTP on port 80
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.WS)
 */
@property (readonly) LMDKtor_httpURLProtocol *WS __attribute__((swift_name("WS")));

/**
 * Web socket over secure HTTPS on port 443
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.WSS)
 */
@property (readonly) LMDKtor_httpURLProtocol *WSS __attribute__((swift_name("WSS")));

/**
 * Protocols by names map
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.URLProtocol.Companion.byName)
 */
@property (readonly) NSDictionary<NSString *, LMDKtor_httpURLProtocol *> *byName __attribute__((swift_name("byName")));
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
@interface LMDKtor_httpHeaderValueParam : LMDBase
- (instancetype)initWithName:(NSString *)name value:(NSString *)value __attribute__((swift_name("init(name:value:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("init(name:value:escapeValue:)"))) __attribute__((objc_designated_initializer));
- (LMDKtor_httpHeaderValueParam *)doCopyName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("doCopy(name:value:escapeValue:)")));
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
@property (readonly) BOOL escapeValue __attribute__((swift_name("escapeValue")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueWithParameters.Companion")))
@interface LMDKtor_httpHeaderValueWithParametersCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpHeaderValueWithParametersCompanion *shared __attribute__((swift_name("shared")));

/**
 * Parse header with parameter and pass it to [init] function to instantiate particular type
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.HeaderValueWithParameters.Companion.parse)
 */
- (id _Nullable)parseValue:(NSString *)value init:(id _Nullable (^)(NSString *, NSArray<LMDKtor_httpHeaderValueParam *> *))init __attribute__((swift_name("parse(value:init:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType.Companion")))
@interface LMDKtor_httpContentTypeCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_httpContentTypeCompanion *shared __attribute__((swift_name("shared")));

/**
 * Parses a string representing a `Content-Type` header into a [ContentType] instance.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.Companion.parse)
 */
- (LMDKtor_httpContentType *)parseValue:(NSString *)value __attribute__((swift_name("parse(value:)")));

/**
 * Represents a pattern `* / *` to match any content type.
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.http.ContentType.Companion.Any)
 */
@property (readonly) LMDKtor_httpContentType *Any __attribute__((swift_name("Any")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Kotlinx_coroutines_coreParentJob")))
@protocol LMDKotlinx_coroutines_coreParentJob <LMDKotlinx_coroutines_coreJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (LMDKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay.Companion")))
@interface LMDKtor_utilsWeekDayCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_utilsWeekDayCompanion *shared __attribute__((swift_name("shared")));

/**
 * Lookup an instance by [ordinal]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay.Companion.from)
 */
- (LMDKtor_utilsWeekDay *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));

/**
 * Lookup an instance by short week day name [WeekDay.value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.WeekDay.Companion.from)
 */
- (LMDKtor_utilsWeekDay *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth.Companion")))
@interface LMDKtor_utilsMonthCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKtor_utilsMonthCompanion *shared __attribute__((swift_name("shared")));

/**
 * Lookup an instance by [ordinal]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month.Companion.from)
 */
- (LMDKtor_utilsMonth *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));

/**
 * Lookup an instance by short month name [Month.value]
 *
 * [Report a problem](https://ktor.io/feedback/?fqname=io.ktor.util.date.Month.Companion.from)
 */
- (LMDKtor_utilsMonth *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection")))
@interface LMDKotlinKTypeProjection : LMDBase
- (instancetype)initWithVariance:(LMDKotlinKVariance * _Nullable)variance type:(id<LMDKotlinKType> _Nullable)type __attribute__((swift_name("init(variance:type:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) LMDKotlinKTypeProjectionCompanion *companion __attribute__((swift_name("companion")));
- (LMDKotlinKTypeProjection *)doCopyVariance:(LMDKotlinKVariance * _Nullable)variance type:(id<LMDKotlinKType> _Nullable)type __attribute__((swift_name("doCopy(variance:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<LMDKotlinKType> _Nullable type __attribute__((swift_name("type")));
@property (readonly) LMDKotlinKVariance * _Nullable variance __attribute__((swift_name("variance")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKVariance")))
@interface LMDKotlinKVariance : LMDKotlinEnum<LMDKotlinKVariance *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) LMDKotlinKVariance *invariant __attribute__((swift_name("invariant")));
@property (class, readonly) LMDKotlinKVariance *in __attribute__((swift_name("in")));
@property (class, readonly) LMDKotlinKVariance *out __attribute__((swift_name("out")));
+ (LMDKotlinArray<LMDKotlinKVariance *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<LMDKotlinKVariance *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection.Companion")))
@interface LMDKotlinKTypeProjectionCompanion : LMDBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) LMDKotlinKTypeProjectionCompanion *shared __attribute__((swift_name("shared")));
- (LMDKotlinKTypeProjection *)contravariantType:(id<LMDKotlinKType>)type __attribute__((swift_name("contravariant(type:)")));
- (LMDKotlinKTypeProjection *)covariantType:(id<LMDKotlinKType>)type __attribute__((swift_name("covariant(type:)")));
- (LMDKotlinKTypeProjection *)invariantType:(id<LMDKotlinKType>)type __attribute__((swift_name("invariant(type:)")));
@property (readonly) LMDKotlinKTypeProjection *STAR __attribute__((swift_name("STAR")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
