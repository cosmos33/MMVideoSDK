//
//  MDRCapturePreviewConfig.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

@interface MDRCapturePreviewConfig : NSObject<NSCopying>

/// 视频采样分辨率, default: MDRCaptureResolutionType_720P
@property (nonatomic,assign) MDRCaptureResolutionType resolutionType;

/// 采样帧率，default: 30
@property (nonatomic,assign) NSInteger frameRate;

/// 采集选项 default: MDRCaptureFlagOption_None
@property (nonatomic,assign) MDRCaptureFlagOption flags;

/// 设备类型 default: MDRCaptureDeviceType_Front
@property (nonatomic,assign) MDRCaptureDeviceType deviceType;

/// 采集类型 default: MDRecordCameraSourceType_CaptureSession
@property (nonatomic,assign) MDRecordCameraSourceType cameraSourceType;

/// 缩放比列，预览缩放比例，以最短边为基准算长边， default: MDRRatioZero, 以分辨率的比例为准
@property (nonatomic, assign) MDRRatio aspectRatio;

/// 实际的采集分辨率大小， resolutionType(对应的分辨率值) * aspectRatio
@property (nonatomic, assign, readonly) MDRVideoResolution captureResolutionValue;

@end
