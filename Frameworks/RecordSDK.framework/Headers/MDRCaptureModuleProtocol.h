//
//  MDRCaptureModuleProtocol.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "MDRCommonDefine.h"
#import "MLPixelBufferDisplay.h"

@class MDRCapturePreviewConfig;
@class MDRCaptureDeviceCapability;
@protocol MDRCaptureModuleProtocol;

typedef struct {
    NSInteger   faceTrackingIdentifier;
    NSInteger   faceTrackingCount;
    CGRect      faceRect;
    BOOL        manualFocus;
} MDRRecordAutoFocusCameraFaceTracking;

NS_ASSUME_NONNULL_BEGIN

@protocol MDRCaptureModuleDelegate <NSObject>

- (void)captureModule:(id<MDRCaptureModuleProtocol>)captureModule didOutputVideoPixelBuffer:(CVPixelBufferRef)pixelBuffer timinginfo:(CMSampleTimingInfo)timingInfo metaInfo:(NSDictionary *)metaInfo;

- (void)captureModule:(id<MDRCaptureModuleProtocol>)captureModule
didOutputAudioSampleBuffer:(CMSampleBufferRef)audioSampleBuffer;

- (MLPixelBufferDisplayScalingMode)scalingModeOfPreviewView;
- (UIView *)pixelBufferDisplayView;

- (BOOL)isRecording;

@end

@protocol MDRCaptureModuleProtocol <NSObject>

- (void)bindDelegate:(id<MDRCaptureModuleDelegate> _Nullable)delegate;

/// 开始预览，内部会初始化captureSession
- (BOOL)startCaptureWithConfig:(MDRCapturePreviewConfig *)config;

/// 暂停预览，内部会移除接收音视频buffer的queue
- (void)pauseCapture;

/// 停止预览
- (void)stopCapture;

/// 获取设备的能力描述实体
- (MDRCaptureDeviceCapability * _Nullable)deviceCapabilityWithDeviceType:(MDRCaptureDeviceType)deviceType;

- (void)focusCameraInPoint:(CGPoint)pointInCamera;

- (void)expposureInPoint:(CGPoint)pointInCamera;

- (void)updateExposureTargetBias:(float)bias;

- (void)setVideoZoomFactor:(CGFloat)factor;

- (void)setCameraFlashMode:(MDRecordCaptureFlashMode)flashMode;

/// 根据人脸信息更新自动对焦
- (void)updateAutoFocusCameraFaceTracking:(MDRRecordAutoFocusCameraFaceTracking)face;

/// 屏蔽自动配置aduioSession的配置，可能会影响音频采集
- (void)autoConfigAudioSessionDisable:(BOOL)disable;

- (BOOL)hasVideoInput;

@end

NS_ASSUME_NONNULL_END
