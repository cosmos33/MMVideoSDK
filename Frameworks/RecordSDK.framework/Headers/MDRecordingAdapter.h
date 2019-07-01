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

- (instancetype)initWithToken:(NSString *)token;

@property (nonatomic, strong, readonly) UIView<MLPixelBufferDisplay> *previewView;

@end

@interface MDRecordingAdapter (Capture)

- (void)setMaxRecordDuration:(NSTimeInterval)duration;
- (void)setMinRecordDuration:(NSTimeInterval)duration;

- (void)setVideoCodecKey:(NSString *)codeckey;
- (void)setVideoBitRate:(float)bitrate;
- (void)setVideoFrameRate:(NSInteger)frameRate;

- (void)setVideoResolution:(CGSize)resolution;
- (void)setVideoScaleMode:(NSString *)scaleMode;

- (void)setCameraPreset:(AVCaptureSessionPreset)preset;
- (void)setCameraPosition:(AVCaptureDevicePosition)position;
- (void)setCameraFrameRate:(NSInteger)frameRate;

- (void)setupRecorder;
    
- (void)setVideoZoomFactor:(CGFloat)factor;
- (CGFloat)videoZoomFactor;

- (NSTimeInterval)recordDuration;

// 是否支持闪光灯
- (BOOL)hasFlash;

// 闪光灯模式
- (NSArray *)supportFlashModes;

// 设置闪光灯模式
@property (nonatomic, assign) MDRecordCaptureFlashMode flashMode;

- (BOOL)hasVideoInput;

@property (nonatomic, assign, readonly) AVCaptureDevicePosition cameraPosition;

- (void)switchCameraPosition;
- (void)focusCameraInPoint:(CGPoint)pointInCamera;
- (void)expposureInPoint:(CGPoint)pointInCamera;
- (void)startCapturing;
- (void)pauseCapturing;
- (void)stopCapturing;

- (void)enableAudioRecording:(BOOL)enable;

@property (nonatomic, assign) BOOL shouldRecordAudio;

- (void)switchToCameraSourceType:(MDRecordCameraSourceType)cameraSourceType;
- (MDRecordCameraSourceType)cameraSourceType;

- (void)takePhoto;
// 即将开始拍照
@property (nonatomic, copy) void (^captureStillImageWillHandler)(void);
// 拍照结果回调
@property (nonatomic, copy) void (^captureStillImageHandler)(UIImage *image, NSDictionary *metaInfo);

@property (nonatomic, assign)           UIDeviceOrientation     outputOrientation;

@property (nonatomic, copy, nullable) void(^cameraDidOutputVideoSampleBuffer)(CMSampleBufferRef sampleBuffer);
@property (nonatomic, copy, nullable) void(^cameraDidOutputAudioSampleBuffer)(CMSampleBufferRef sampleBuffer);

@end

@interface MDRecordingAdapter (Recording)

- (BOOL)canStartRecording;
- (void)startRecording;
- (void)pauseRecording;
- (void)cancelRecording;
- (void)stopVideoCaptureWithOutputURL:(NSURL *)URL
                    completionHandler:(void (^)(NSURL *videoFileURL, NSError *error))completionHandler;
- (NSInteger)savedSegmentCount;

- (void)deleteLastSavedSegment;
- (void)resetRecorder;

- (void)cleanStashFile;

@property (nonatomic, readonly) BOOL isRecording;
@property (nonatomic, readonly) NSTimeInterval currentRecordingDuration;
@property (nonatomic, readonly) NSTimeInterval currentRecordingPresentDuration;
@property (nonatomic, assign, readonly) BOOL                    stopMerge;
@property (nonatomic, strong, readonly) id                      periodicTimeObserver;//配乐播放开始观察者

@property (nonatomic, copy) void (^recordProgressChangedHandler)(double progress);
@property (nonatomic, copy) void (^recordDurationReachedHandler)(void);
@property (nonatomic, copy) void (^completeProgressUpdateHandler)(double progress);
@property (nonatomic,copy) void (^recordSegmentsChangedHandler)(NSArray *durations, NSArray *presentDurations, BOOL valid);

@end

@interface MDRecordingAdapter (Effect)

- (void)configSlidingFilterMode:(MDRGPUImageSlidingFilterMode)mode; // need be called before setupRecorder;
- (void)configCurrentFilter:(MDRecordFilter *)filter;
- (void)configFilterA:(MDRecordFilter *)filterA configFilterB:(MDRecordFilter *)filterB offset:(float)offset;
- (void)configDecorationFilterAttachment:(MDGPUImageMediaFiltersAttachment *)filtersAttachment;     //滤镜链插槽，canUseAIBeautySetting 为 false 有效。每次配置decoration后调用一次，不可重复调用

- (void)updateDecoration:(FDKDecoration *)decoration;
- (void)removeDecoration;
- (void)adjustStikcerVolume:(float)volume;

- (void)addGift:(MDRGift *)gift;
- (void)removeGift:(MDRGift *)gift;
- (void)removeGiftWithGiftID:(NSString *)giftID;
- (void)clearAllGifts;

- (void)activateBarenessDetectorEnable:(BOOL)enable;
- (BOOL)hasDetectorBareness;
- (void)setDetectBareness:(void (^)(void))detectBareness;

@property (nonatomic, copy) void(^ _Nullable detectFace)(BOOL tracking);

@property (nonatomic, copy)  MDVideoDetectorBlock faceFeatureHandler;   //视频帧，脸部，身体数据回调

@property (nonatomic, assign) BOOL canUseAIBeautySetting;
@property (nonatomic, assign) BOOL canUseBodyThinSetting;
@property (nonatomic, readonly) BOOL isFaceCaptured;

- (void)clean;
- (void)resetState;

// add custom filter
- (void)addCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;
- (void)removeCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;

@end

@interface MDRecordingAdapter (Music)

// 音乐资源
@property (nonatomic, strong, nullable) AVAsset *backgroundAudio;

@end

@interface MDRecordingAdapter (BeautySetting)

- (void)setBeautyConfiguration:(CXBeautyConfiguration *)config;

- (void)setSkinWhitenValue:(float)value;
- (void)setSkinSmoothValue:(float)value;
- (void)setBeautyBigEyeValue:(float)value;
- (void)setBeautyThinFaceValue:(float)value;
- (void)setBeautyThinBodyValue:(float)value;
- (void)setBeautyLenghLegValue:(float)value;

@end

@interface MDRecordingAdapter (XESEngin)

- (void)runXESEngineWithDecorationRootPath:(NSString *)path;


@end

@interface MDRecordingAdapter (SpeedVary)

- (void)setNextRecordSegmentSpeedVaryFactor:(CGFloat)factor;
- (CGFloat)nextRecordSegmentSpeedVaryFactor;
- (void)speedVaryShouldAllow:(BOOL)isAllow;
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
