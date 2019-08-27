//
//  MDRecordingAdapter.h
//  MDRecordSDK
//
//  Created by sunfei on 2019/2/27.
//  Copyright © 2019 sunfei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MDRecordFilter.h"
#import "MDCameraDetectorPipline.h"
#import "MDRecordCameraAdapter.h"
#import "MDBBGPUImageSlidingFilter.h"
#import "MDRGift.h"
#import "MDGlobalDefine.h"

@import CXBeautyKit;

@class CXBeautyConfiguration, MDGPUImageMediaFiltersAttachment;
@protocol MLPixelBufferDisplay;

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordingAdapter : NSObject

- (instancetype)init NS_UNAVAILABLE;


/**
 待完善

 @param token 授权码, 由Cosmos服务方下发
 @return adapter对象
 */
- (instancetype)initWithToken:(NSString *)token;
/**
 拍摄器的预览视图
 */
@property (nonatomic, strong, readonly) UIView<MLPixelBufferDisplay> *previewView;

@end

@interface MDRecordingAdapter (Capture)

/**
 设置录制的最大时长    需要在setupRecorder之前调用

 @param duration 最大时长(即总时长)
 */
- (void)setMaxRecordDuration:(NSTimeInterval)duration;

/**
 设置分段录制的最小时长   需要在setupRecorder之前调用

 @param duration 最小录制时长，应小于最大时长
 */
- (void)setMinRecordDuration:(NSTimeInterval)duration;


/**
 设置生成视频的编码格式    需要在setupRecorder之前调用

 @param codeckey 参考AVFoundation类型，默认为AVVideoCodecH264
 */
- (void)setVideoCodecKey:(AVVideoCodecType)codeckey;

/**
 设置生成视频码率    需要在setupRecorder之前调用

 @param bitrate 默认为 5.0 * 1024 * 1024，即5M/s
 */
- (void)setVideoBitRate:(float)bitrate;


/**
 设置生成视频帧率   需要在setupRecorder之前调用

 @param frameRate 默认为30
 */
- (void)setVideoFrameRate:(NSInteger)frameRate;


/**
 设置生成视频的分辨率   需要在setupRecorder之前调用

 @param resolution 默认为(720, 1280)
 */
- (void)setVideoResolution:(CGSize)resolution;


/**
 设置生成视频填充模式(等比适应/等比填充/拉伸)，参数参考 AVVideoScalingModeKey, 需要在setupRecorder之前调用

 @param scaleMode 默认为AVVideoScalingModeResizeAspectFill
 */
- (void)setVideoScaleMode:(NSString *)scaleMode;


/**
 设置摄像头采样分辨率, 参考 AVCaptureSessionPreset, 需要在setupRecorder之前调用

 @param preset 默认为 AVCaptureSessionPreset1280x720
 */
- (void)setCameraPreset:(AVCaptureSessionPreset)preset;


/**
 置摄像头初始位置, 需要在setupRecorder之前调用

 @param position 默认为 AVCaptureDevicePositionFront，即前置摄像头
 */
- (void)setCameraPosition:(AVCaptureDevicePosition)position;


/**
 设置摄像头采样帧率 (iPhone 6 默认为15, iphone 6s及以上默认为30). 需要在 setupRecorder 之前调用 (2.2.3 新增)

 @param frameRate 设置摄像头帧率
 
 
 2.2.3版本可用
 */
- (void)setCameraFrameRate:(NSInteger)frameRate;



/**
 初始化相机
 */
- (void)setupRecorder;


/**
 调整视频的放大倍数 factor 在 1 - 6 之取值，最大支持6倍放大
 场景：捏合手势，放大的效果

 @param factor 1默认，6为放大6倍
 */
- (void)setVideoZoomFactor:(CGFloat)factor;


/**
 获取当前的焦距

 @return 当前放大的倍数
 */
- (CGFloat)videoZoomFactor;



/**
 获取录制最大时长

 @return 最大时长
 */
- (NSTimeInterval)recordDuration;


/**
 当前摄像头位置是否支持闪光灯

 @return true为支持，false为不支持
 */
- (BOOL)hasFlash;

/**
 获取支持的模式

 @return 当前机型支持的闪光灯模式，参考 `MDRecordCaptureFlashMode`
 */
- (NSArray *)supportFlashModes;


/**
 设置闪光灯模式
 
 MDRecordCaptureFlashModeOff   关闭,
 MDRecordCaptureFlashModeOn    打开,
 MDRecordCaptureFlashModeAuto  自动,
 */
@property (nonatomic, assign) MDRecordCaptureFlashMode flashMode;


/**
 是否有视频输入源

 @return YES 有， NO 无
 */
- (BOOL)hasVideoInput;


/**
 获取当前摄像头位置
 */
@property (nonatomic, assign, readonly) AVCaptureDevicePosition cameraPosition;



/**
 切换前后置摄像头
 */
- (void)switchCameraPosition;

/**
 设置焦点

 @param pointInCamera 具体细节   待完善，如：检测到人脸会失效？
 */
- (void)focusCameraInPoint:(CGPoint)pointInCamera;


/**
 待完善

 @param pointInCamera
 */
- (void)expposureInPoint:(CGPoint)pointInCamera;


/**
 开始捕获摄像头画面，显示在preview上   注意事项/建议：待完善（如：在viewdidappear里调用）
 */
- (void)startCapturing;

/**
 暂停捕获画面      注意事项/建议：待完善（如：在viewdiddisappear里调用）
 */
- (void)pauseCapturing;


/**
 停止捕获画面
 */
- (void)stopCapturing;



/**
 麦克风启动/禁用

 @param enable  true启用，false禁用。待确认
 
 2.2.2版本及以后可用
 */
- (void)enableAudioRecording:(BOOL)enable;



/**
 麦克风初始是否启用/禁用. (需要在 setupRecorder 之前调用)   默认值：待完善
 
 2.2.2版本及以后可用
 
 */
@property (nonatomic, assign) BOOL shouldRecordAudio;




/**
 待完善

 @param cameraSourceType
 */
- (void)switchToCameraSourceType:(MDRecordCameraSourceType)cameraSourceType;


/**
 待完善

 @return
 */
- (MDRecordCameraSourceType)cameraSourceType;



/**
 拍照，配合2个block回调使用captureStillImageWillHandler，captureStillImageHandler
 */
- (void)takePhoto;

/**
 即将开始拍照的回调
 */
@property (nonatomic, copy) void (^captureStillImageWillHandler)(void);


/**
 拍照结束的回调
 */
@property (nonatomic, copy) void (^captureStillImageHandler)(UIImage *image, NSDictionary *metaInfo);


/**
 设置设备方向      待完善？？用途
 */
@property (nonatomic, assign)           UIDeviceOrientation     outputOrientation;


/**
 获取水平镜像输出流
 @param enable  ture 输出水平镜像数据流，false返回非水平镜像数据流
 2.2.10版本及以后可用
 */
- (void)enableReverseVideoSampleBuffer:(BOOL)enable;



/**
 实时获取视频流      待完善：原始buffer还是处理以后的buffer
 2.2.2版本及以后可用
 */

@property (nonatomic, copy, nullable) void(^cameraDidOutputVideoSampleBuffer)(CMSampleBufferRef sampleBuffer);


/**
 实时获取音频流
 2.2.0版本及以后可用
 */
@property (nonatomic, copy, nullable) void(^cameraDidOutputAudioSampleBuffer)(CMSampleBufferRef sampleBuffer);

@end

@interface MDRecordingAdapter (Recording)


/**
待完善
 */
@property (nonatomic, assign) BOOL saveOrigin;


/**
 待完善

 @return
 */
- (BOOL)canStartRecording;


/**
 开始录制视频
 */
- (void)startRecording;

/**
 暂停录制
 */
- (void)pauseRecording;

/**
 取消当前段的录制。   待完善：多次调用问题？
 */
- (void)cancelRecording;

/**
结束录制

 @param URL 文件的地址
 @param completionHandler error导出是否出错，不为空时，
 videoFileURL即为录制的视频路径
 */
- (void)stopVideoCaptureWithOutputURL:(NSURL *)URL
                    completionHandler:(void (^)(NSURL *videoFileURL, NSError *error))completionHandler;


/**
 分段录制

 @return 当前有多少段
 */
- (NSInteger)savedSegmentCount;


/**
 删除最新录制的一段，多次调用，直到删除所有已录制的视频
 */
- (void)deleteLastSavedSegment;


/**
 删除已录制的所有片段
 */
- (void)resetRecorder;


/**
 清空暂存文件     待完善：删除本次录制的所有暂存，
 还是历史所有的暂存文件？ 如果调用stop导出视频文件，是否需要调用
 */
- (void)cleanStashFile;


/**
 是否正在录制
 */
@property (nonatomic, readonly) BOOL isRecording;


/**
 获取当前录制的时长
 */
@property (nonatomic, readonly) NSTimeInterval currentRecordingDuration;


/**
    获取变速后实际展示时长
 */
@property (nonatomic, readonly) NSTimeInterval currentRecordingPresentDuration;


/**
 是否正在合成视频
 */
@property (nonatomic, assign, readonly) BOOL                    stopMerge;


/**
 待完善
 */
@property (nonatomic, strong, readonly) id                      periodicTimeObserver;//配乐播放开始观察者



/**
 录制进度的回调      待完善： 是否会受变速影响
 */
@property (nonatomic, copy) void (^recordProgressChangedHandler)(double progress);


/**
 到达最大录制时长的回调
 */
@property (nonatomic, copy) void (^recordDurationReachedHandler)(void);


/**
 导出视频时的进度回调
 */
@property (nonatomic, copy) void (^completeProgressUpdateHandler)(double progress);


/**
 分段录制，增加/删除时的回调。   durations：待完善：（类型，单位） presentDurations：
 */
@property (nonatomic,copy) void (^recordSegmentsChangedHandler)(NSArray *durations, NSArray *presentDurations, BOOL valid);

@end

@interface MDRecordingAdapter (Effect)



/**
 设置滤镜切换动画方向(横向或者纵向), 需要在 setupRecorder 之前调用

 @param mode MDRGPUImageSlidingFilterModeHorizontal :水平方向
               MDRGPUImageSlidingFilterModeVertical :竖直方向
 */
- (void)configSlidingFilterMode:(MDRGPUImageSlidingFilterMode)mode;



/**
 设置滤镜

 @param filter 滤镜对象
 */
- (void)configCurrentFilter:(MDRecordFilter *)filter;


/**
 切换滤镜（用于左右/上下滑动滤镜时使用）

 @param filterA 滤镜a
 @param filterB 滤镜b
 @param offset 所占百分比
 */
- (void)configFilterA:(MDRecordFilter *)filterA configFilterB:(MDRecordFilter *)filterB offset:(float)offset;



/**
 滤镜链插槽，canUseAIBeautySetting 为 false 有效。每次配置FDKDecoration后调用一次，不可重复调用。

 @param filtersAttachment
 
 待完善：xxx版本以后可用
 */
- (void)configDecorationFilterAttachment:(MDGPUImageMediaFiltersAttachment *)filtersAttachment;     //



/**
 切换美颜/滤镜贴纸。     待完善：如果decoration里有美颜，和默认的美颜之间的设置逻辑

 @param decoration FDKDecoration对象
 */
- (void)updateDecoration:(FDKDecoration *)decoration;


/**
 移除美颜/滤镜贴纸
 */
- (void)removeDecoration;


/**
 调整贴纸自带音效音量


 @param volume volume 待完善：取值范围以及具体释义
 */
- (void)adjustStikcerVolume:(float)volume;


/**
 添加礼物，可多张叠加。     待完善： 使用建议：不要多余多少个，影响性能

 @param gift 礼物对象
 */
- (void)addGift:(MDRGift *)gift;


/**
 移除礼物

 @param gift 礼物对象
 */
- (void)removeGift:(MDRGift *)gift;


/**
 通过ID移除礼物对象

 @param giftID 礼物id
 */
- (void)removeGiftWithGiftID:(NSString *)giftID;


/**
 清空所有礼物
 */
- (void)clearAllGifts;

/**
 是否开启光膀子检测，和- (void)setDetectBareness:
 (void (^)(void))detectBareness配合使用

 @param enable true 开启  false 不开启
 */
- (void)activateBarenessDetectorEnable:(BOOL)enable;


/**
 是否存在光膀子     待完善：是否需要和activateBarenessDetectorEnable配合使用？

 @return ture 存在  false 不存在
 */
- (BOOL)hasDetectorBareness;


/**
 发现光膀子时候的回调

 @param detectBareness 回调block
 */
- (void)setDetectBareness:(void (^)(void))detectBareness;


/**
 待完善
 */
@property (nonatomic, copy) void(^ _Nullable detectFace)(BOOL tracking);


/**
 待完善
 */
@property (nonatomic, copy)  MDVideoDetectorBlock faceFeatureHandler;   //视频帧，脸部，身体数据回调


/**
 是否使用AI美颜功能   待完善:  建议iOS 10以上开启，还是只能iOS10以上开启？
 
 x.x.x版本以后可用      2.2.9版本建议使用useAIBigEyeThinFace
                      useAISkinWhiten  useAISkinSmooth 代替
 */
@property (nonatomic, assign) BOOL canUseAIBeautySetting;


/**
 是否启用瘦身长腿功能
 */
@property (nonatomic, assign) BOOL canUseBodyThinSetting;



/**
 是否检测到人脸
 */
@property (nonatomic, readonly) BOOL isFaceCaptured;

/** 是否开启ai 美白 默认关闭*/
@property (nonatomic, assign) BOOL useAISkinWhiten;

/** 是否开启ai 磨皮 默认关闭 */
@property (nonatomic, assign) BOOL useAISkinSmooth;

/** 是否开启ai 大眼 瘦脸 默认关闭 */
@property (nonatomic, assign) BOOL useAIBigEyeThinFace;

/**
 清除贴纸缓存 ？？ 待完善
 */
- (void)clean;


/**
 清除检测器状态 ？？  待完善
 */
- (void)resetState;

// add custom filter
- (void)addCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;
- (void)removeCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;

@end

@interface MDRecordingAdapter (Music)


/**
 设置背景音乐
 */
@property (nonatomic, strong, nullable) AVAsset *backgroundAudio;

@end

@interface MDRecordingAdapter (BeautySetting)


/**
 待完善    CXBeautyConfiguration 此对象+ (nullable instancetype)beautyConfigurationFromJSONObject:(id)JSONObject error:(NSError **)error;
JSONObject？？？

 @param config
 */
- (void)setBeautyConfiguration:(CXBeautyConfiguration *)config;


/**
 设置美白值    如果使用了AI美颜，建议取值范围设置到0-0.8

 @param value 取值范围0-1，默认：待完善
 */
- (void)setSkinWhitenValue:(float)value;

/**
 设置磨皮值    如果使用了AI美颜，建议取值范围设置到0-0.8
 
 @param value 取值范围0-1，默认：待完善
 */
- (void)setSkinSmoothValue:(float)value;

/**
 设置大眼值    如果使用了AI美颜，建议取值范围设置到0-0.8
 
 @param value 取值范围0-1，默认：待完善
 */
- (void)setBeautyBigEyeValue:(float)value;

/**
 设置瘦脸值    如果使用了AI美颜，建议取值范围设置到0-0.8
 
 @param value 取值范围0-1，默认：待完善
 */
- (void)setBeautyThinFaceValue:(float)value;

/**
 设置瘦身值    如果使用了AI美颜，建议取值范围设置到0-0.8
 
 @param value 取值范围0-1，默认：待完善
 */
- (void)setBeautyThinBodyValue:(float)value;

/**
 设置长腿值    如果使用了AI美颜，建议取值范围设置到0-0.8
 
 @param value 取值范围0-1，默认：待完善
 */
- (void)setBeautyLenghLegValue:(float)value;

@end

@interface MDRecordingAdapter (XESEngin)


/**
 启动3D引擎

 @param path path: 但完善：参数释义
 */
- (void)runXESEngineWithDecorationRootPath:(NSString *)path;


@end

@interface MDRecordingAdapter (SpeedVary)


/**
 设置变速   待完善：设置一次，所有分段生效?还是录制一段以后重置为1

 @param factor 取值范围0.2 - 4.0 默认值为1  待完善：释义，0.2？？ 4.0？？
 */
- (void)setNextRecordSegmentSpeedVaryFactor:(CGFloat)factor;


/**
 获取设置的变速值

 @return 变速值
 */
- (CGFloat)nextRecordSegmentSpeedVaryFactor;


/**
 当前段是否允许变速 待完善：设置一次，所有分段生效?还是录制一段以后重置为false

 @param isAllow  true允许  false不允许  默认值：待完善
 */
- (void)speedVaryShouldAllow:(BOOL)isAllow;


/**
 当前段是否存在变速效果，即与speedVaryShouldAllow设置的相对应

 @return ture 存在   false 不存在
 */
- (BOOL)hasPerSpeedEffect;

@end

@interface MDRecordingAdapter (MDRMakeUp)

/**
 启用美妆功能

 @param enable YES启用，NO禁用
 */
- (void)enableMakeup:(BOOL)enable;

/**
 增加美妆效果

 @param resouceURL 资源文件路径
 @return 该效果identifier
 */
- (NSString *)addMakeUpEffectWithResourceURL:(NSURL *)resouceURL;

/**
 根据identifier移除美妆效果

 @param identifiter 要移除的美妆效果的identifier
 */
- (void)removeMakeUpEffectWithIdentifier:(NSString *)identifiter;

/**
 移除所有的美妆效果
 */
- (void)removeAllMakeUpEffect;

/**
 调整美妆效果程度

 @param intensity 程度(0-1)
 @param identifier 美妆效果
 */
- (void)setIntensity:(CGFloat)intensity forIdentifiler:(NSString *)identifier;

@end

@interface MDRecordingAdapter (MDRBackgroundBlur)

/**
 是否启用背景模糊

 @param enable YES启用，NO禁用
 */
- (void)enableBackgroundBlur:(BOOL)enable;

/**
 设置背景模糊效果

 @param mode 背景模糊样式
 */
- (void)setBackgroundBlurMode:(CXBackgroundBlurMode)mode;

// 背景模糊程度(0-1)
- (void)setBackgroundBlurIntensity:(CGFloat)intensity;

@end

NS_ASSUME_NONNULL_END
