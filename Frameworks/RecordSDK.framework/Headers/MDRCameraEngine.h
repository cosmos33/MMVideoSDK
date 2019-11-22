//
//  MDRCameraEngine.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"
#import "MDRCameraEngineDelegate.h"

#import <AVFoundation/AVFoundation.h>
#import "MDRecordFilter.h"
#import "MDBBGPUImageSlidingFilter.h"
#import "MDRGift.h"

@class CXBeautyConfiguration;
@class MDGPUImageMediaFiltersAttachment;
@class MDRCaptureDeviceCapability;
@class MDRCapturePreviewConfig;
@class MDRMediaSegmentInfo;
@class MMFaceFeature;
@class MMBodyFeature;
@class FDKDecoration;

@protocol MLPixelBufferDisplay;

NS_ASSUME_NONNULL_BEGIN

@interface MDRCameraEngine : NSObject

/// 拍摄器的预览视图
@property (nonatomic, strong, readonly) UIView<MLPixelBufferDisplay> *previewView;

/// 录制最大时长 (总时长，非单段），单位 秒 default: 60s
@property (nonatomic, assign) NSTimeInterval recordMaxDuration;

/// 单段录制最短时长，单位 秒  default: 1s
@property (nonatomic, assign) NSTimeInterval segmentMinDuration;

/// 是否存在变速片段
@property (nonatomic, assign, readonly) BOOL hasPerSpeedEffect;

/// 取值范围0.2 - 4.0 默认值为1, 只影响即将录制的片段
@property (nonatomic, assign) CGFloat speedVaryFactor;

/// 采样帧率，默认30FPS，导出帧率默认和采样帧率一致
@property (nonatomic, assign) NSInteger captureFrameRate;

/// 当前采集设备类型
@property (nonatomic, assign, readonly) MDRCaptureDeviceType currentDeviceType;

/// 当前的设备能力描述
@property (nonatomic, strong, readonly) MDRCaptureDeviceCapability *currentDeviceCapability;

/// 当前放大的倍数
@property (nonatomic, assign, readonly) CGFloat currentVideoZoomFactor;

/// 当前的采集源类型
@property (nonatomic, assign, readonly) MDRecordCameraSourceType currentCameraSourceType;

/// 引擎状态
@property (nonatomic, assign, readonly) MDRCameraEngineState engineState;

/// 录制片段数组
@property (nonatomic, assign, readonly) NSArray<MDRMediaSegmentInfo *> *segmentInfos;

/// 当前录制的总时长
@property (nonatomic, assign, readonly) NSTimeInterval currentRecordingDuration;

/// 变速后实际展示总时长
@property (nonatomic, assign, readonly) NSTimeInterval currentRecordingPresentDuration;

/// 闪光灯
@property (nonatomic, assign) MDRecordCaptureFlashMode flashMode;

/// 设置背景音乐
@property (nonatomic, strong, nullable) AVAsset *backgroundAudio;

///  是否准备开始播放配乐
@property (nonatomic, assign, readonly) BOOL isReadyToPlayMusic;

/// 屏幕旋转方向
@property (nonatomic, assign) UIDeviceOrientation outputOrientation;

/// 控制是否屏蔽自动配置audioSession，如果屏蔽会影响声音的采集。
/// fix ： 主要是为了修复在录制过程中采集外放音频的音量过小的问题，建议在startCapture前调用
@property (nonatomic, assign) BOOL autoConfigAudioSessionDisable;

- (instancetype)initWithDelegate:(id<MDRCameraEngineDelegate> _Nullable)delegate;

/// 开始预览
/// @param resolutionType 视频预览分辨率
/// @param deviceType 视频信号采集设备
- (BOOL)startCaptureWithResolution:(MDRCaptureResolutionType)resolutionType
                        deviceType:(MDRCaptureDeviceType)deviceType;

/// 开始预览
/// @param resolutionType 视频预览分辨率
/// @param deviceType 视频信号采集设备
/// @param flag 预览选项
- (BOOL)startCaptureWithResolution:(MDRCaptureResolutionType)resolutionType
                        deviceType:(MDRCaptureDeviceType)deviceType
                              flag:(MDRCaptureFlagOption)flag;

/// 开始预览
/// @param resolutionType 视频采集分辨率
/// @param deviceType 视频信号采集设备
/// @param flag 采集选项
/// @param aspectRatio 预览缩放宽高比例，以宽为基准算高，
/// 以720P为例，720就是宽，算出来的宽高默认是导出的分辨率, 传MDRRatioZero，以分辨率比例为准
- (BOOL)startCaptureWithResolution:(MDRCaptureResolutionType)resolutionType
                        deviceType:(MDRCaptureDeviceType)deviceType
                              flag:(MDRCaptureFlagOption)flag
                      aspectRatio:(MDRRatio)aspectRatio;


/// 开始预览
/// @param config 采集预览配置
- (BOOL)startCaptureWithPreviewConfig:(MDRCapturePreviewConfig * _Nullable)config;

/// 暂停捕获画面
- (void)pauseCapturing;

/// 停止捕获画面
- (void)stopCapturing;

/// 获取采集设备的能力描述
/// @param deviceType 设备类型
/// @return 设备能力描述，建议：在使用曝光补偿、视频放大等设备功能时，
/// 先通过MDRCaptureDeviceCapability判断设备是否支持
- (MDRCaptureDeviceCapability * _Nullable)deviceCapabilityWithDeviceType:(MDRCaptureDeviceType)deviceType;

/// 设置焦点
/// @param pointInCamera 需要对焦的屏幕坐标，非（0, 1)
- (void)focusCameraInPoint:(CGPoint)pointInCamera;

/// 设置曝光点
/// @param pointInCamera 需要曝光的屏幕坐标，非（0, 1)
- (void)expposureInPoint:(CGPoint)pointInCamera;

/// 更新曝光补偿
/// @param bias 曝光补偿值
- (void)updateExposureTargetBias:(float)bias;

/// 调整视频的放大倍数,可通过currentDeviceCapability获取当前设备支持的最大放大倍数
/// @param factor 放大倍数
- (void)setVideoZoomFactor:(CGFloat)factor;

/// 切换采集设备
/// @param desDeviceType 目标采集设备
- (BOOL)switchCaptureDeviceType:(MDRCaptureDeviceType)desDeviceType;

/// 切换前后置
- (BOOL)switchCameraPosition;

/// 普通拍摄和AR拍摄切换
/// @param cameraSourceType 采集源类型
- (BOOL)switchToCameraSourceType:(MDRecordCameraSourceType)cameraSourceType;

/// 是否有视频输入源
/// @return YES 有， NO 无
- (BOOL)hasVideoInput;

/// 开始录制
/// 1.默认视频编码配置：
/// 视频编码类型，default: MDRVideoEncodeType_H264
/// 视频编码分辨率，default: {720, 1280}
/// 视频码率，单位bit，default: 5 * 1000 * 1000 bit
/// 视频编码裁剪模式，default:MDRVideoEncodeScaleMode_ResizeAspectFill
/// 视频编码帧率，default:和采集帧率保持一致
/// 2.默认音频编码配置：
/// 音频编码类型，default: MDRAudioEncodeType_AAC
/// 音频采样信息，default: {sampleRate: 44100, sampleFormat: MDRAudioSampleFormatType_S16, channelCount: 1}
/// 音频码率，单位bit，default: 256 * 1000 bit
- (BOOL)startRecording;

///  开始录制
/// @param flag  录制选项
- (BOOL)startRecordingWithFlag:(MDRRecordingFlagOption)flag;

///  开始录制
/// @param flag  录制选项
/// @param params 编码参数配置
/// 例如：
/// NSMutableDictionary *encodeParams = [[NSMutableDictionary alloc] init];
/// encodeParams[MDRVideoEncodeFrameRateKey] = @15;      //15FPS
/// encodeParams[MDRVideoEncodeBitRateKey] = @5000000;    //5M bps
/// encodeParams[MDRVideoEncodeScaleModeKey] = @(MDRVideoEncodeScaleMode_Fit);
- (BOOL)startRecordingWithFlag:(MDRRecordingFlagOption)flag
              andEncodeParams:(NSDictionary * _Nullable)encodeParams;

/// 开始录制
/// @param flag 录制选项
/// @param speedVaryFactor 变速因子 取值范围0.2 - 4.0 默认值为1
/// @param encodeParams 编码参数配置
- (BOOL)startRecordingWithFlag:(MDRRecordingFlagOption)flag
              speedVaryFactor:(CGFloat)speedVaryFactor
              andEncodeParams:(NSDictionary * _Nullable)encodeParams;

/// 暂停录制，单段录制完成
- (void)pauseRecording;

/// 取消单段录制
- (void)cancelRecording;

/// 是否能开始录制
/// @return YES： 可以开始录制， NO：1.已经达到了最大时长 2.还未获取到第一帧buffer
- (BOOL)canStartRecording;

/// 导出视频，该接口做了多段合并的操作，导出的分辨率默认用的首段视频的分辨率，
/// 导出的格式为mp4，后面会开放更多配置
/// @param completionHandler 导出视频的回调
- (void)exportVideoWithCompletionHandler:(void (^)(NSURL * _Nullable videoFileURL, NSError * _Nullable error))completionHandler;

/// 删除最新录制的一段，多次调用，直到删除所有已录制的视频
- (void)deleteLastSavedSegment;

/// 删除所有录制片段
- (void)deleteAllSegments;

/// 1.如果正在录制（MDRCameraEngineState_Recording），会取消录制
/// 2.如果正在导出（MDRCameraEngineState_Exporting), 会取消导出
/// 3.调用该方法会重置引擎状态为MDRCameraEngineState_Preview，并移除所有已经录制的所有片段
- (void)resetRecorder;

/// 删除临时视频文件
- (void)cleanStashFile DEPRECATED_ATTRIBUTE;

/// 拍照
/// @param completionHandler 图片生成回调
- (void)takePhotoWithCompletionHandler:(void (^)(UIImage *image, NSDictionary *metaInfo, NSError *error))completionHandler;

@end

@interface MDRCameraEngine (Effect)

/// 设置滤镜切换动画方向(横向或者纵向), 需要在 setupRecorder 之前调用
/// @param mode  MDRGPUImageSlidingFilterModeHorizontal :水平方向
///             MDRGPUImageSlidingFilterModeVertical :竖直方向
- (void)configSlidingFilterMode:(MDRGPUImageSlidingFilterMode)mode;

/// 设置滤镜
/// @param filter 滤镜对象
- (void)configCurrentFilter:(MDRecordFilter *)filter;

/// 切换滤镜（用于左右/上下滑动滤镜时使用）
/// @param filterA  滤镜a
/// @param filterB 滤镜b
/// @param offset 所占百分比
- (void)configFilterA:(MDRecordFilter *)filterA configFilterB:(MDRecordFilter *)filterB offset:(float)offset;


/// 滤镜链插槽，canUseAIBeautySetting 为 false 有效。每次配置FDKDecoration后调用一次，不可重复调用。
/// 待完善：xxx版本以后可用
/// @param filtersAttachment filtersAttachment
- (void)configDecorationFilterAttachment:(MDGPUImageMediaFiltersAttachment *)filtersAttachment;

/// 切换美颜/滤镜贴纸。     待完善：如果decoration里有美颜，和默认的美颜之间的设置逻辑
/// @param decoration FDKDecoration对象
- (void)updateDecoration:(FDKDecoration *)decoration;

/// 移除美颜/滤镜贴纸
- (void)removeDecoration;

/// 调整贴纸自带音效音量
/// @param volume 待完善：取值范围以及具体释义
- (void)adjustStikcerVolume:(float)volume;

/// 添加礼物，可多张叠加。     待完善： 使用建议：不要多余多少个，影响性能
/// @param gift 礼物对象
- (void)addGift:(MDRGift *)gift;

/// 移除礼物
/// @param gift 礼物对象
- (void)removeGift:(MDRGift *)gift;

/// 通过ID移除礼物对象
/// @param giftID 礼物id
- (void)removeGiftWithGiftID:(NSString *)giftID;

/// 清空所有礼物
- (void)clearAllGifts;

/// 是否开启光膀子检测
/// @param enable rue 开启  false 不开启
- (void)activateBarenessDetectorEnable:(BOOL)enable;

/// 视频帧，脸部，身体数据回调
@property (nonatomic, copy) void(^ _Nullable faceFeatureHandler)(CVPixelBufferRef _Nonnull pixelbuffer, NSArray<MMFaceFeature *> * _Nullable faceFeatures, NSArray<MMBodyFeature *> * _Nullable bodyFeatures)
DEPRECATED_MSG_ATTRIBUTE("use didOutputFaceFeatureInfo");


/**
 是否使用AI美颜功能   待完善:  建议iOS 10以上开启，还是只能iOS10以上开启？
 
 x.x.x版本以后可用      2.2.9版本建议使用useAIBigEyeThinFace
                      useAISkinWhiten  useAISkinSmooth 代替
 */

/// 是否使用AI美颜功能   待完善:  建议iOS 10以上开启，还是只能iOS10以上开启？
///  2.2.9版本建议使用useAIBigEyeThinFace useAISkinWhiten  useAISkinSmooth 代替
@property (nonatomic, assign) BOOL canUseAIBeautySetting;

/// 是否启用瘦身长腿功能
@property (nonatomic, assign) BOOL canUseBodyThinSetting;

/// 是否检测到人脸
@property (nonatomic, readonly) BOOL isFaceCaptured;

/// 清除贴纸缓存 ？？ 待完善
- (void)clean;

/// 清除检测器状态 ？？  待完善
- (void)resetState;

@end


@interface MDRCameraEngine (BeautySetting)

/// 待完善    CXBeautyConfiguration
///此对象+ (nullable instancetype)beautyConfigurationFromJSONObject:(id)JSONObject error:(NSError **)error;JSONObject？？？
/// @param config
- (void)setBeautyConfiguration:(CXBeautyConfiguration *)config;

/// 设置美白值    如果使用了AI美颜，建议取值范围设置到0-0.8
/// @param value 取值范围0-1，默认：待完善
- (void)setSkinWhitenValue:(float)value;

/// 设置磨皮值    如果使用了AI美颜，建议取值范围设置到0-0.8
/// @param value 取值范围0-1，默认：待完善
- (void)setSkinSmoothValue:(float)value;

/// 设置大眼值    如果使用了AI美颜，建议取值范围设置到0-0.8
/// @param value 取值范围0-1，默认：待完善
- (void)setBeautyBigEyeValue:(float)value;

/// 设置瘦脸值    如果使用了AI美颜，建议取值范围设置到0-0.8
/// @param value 取值范围0-1，默认：待完善
- (void)setBeautyThinFaceValue:(float)value;

/// 设置瘦身值    如果使用了AI美颜，建议取值范围设置到0-0.8
/// @param value 取值范围0-1，默认：待完善
- (void)setBeautyThinBodyValue:(float)value;

/// 设置长腿值    如果使用了AI美颜，建议取值范围设置到0-0.8
/// @param value 取值范围0-1，默认：待完善
- (void)setBeautyLenghLegValue:(float)value;

@end

@interface MDRCameraEngine (XESEngin)

/// 启动3D引擎
/// @param path 但完善：参数释义
- (void)runXESEngineWithDecorationRootPath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
