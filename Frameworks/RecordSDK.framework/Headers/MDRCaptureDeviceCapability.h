//
//  MDRCaptureDeviceCapability.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

@interface MDRCaptureDeviceCapability : NSObject

/// 是否支持自动对焦
@property (readonly) BOOL supportAutoFocus;

/// 是否支持自动曝光
@property (readonly) BOOL supportAutoExposure;

/// 最小曝光补偿系数
@property (readonly) float minExposureBias;

/// 最大曝光补偿系数
@property (readonly) float maxExposureBias;

/// 支持的最大缩放倍数
@property (readonly) float maxVideoZoomFactor;

/// 是否支持缩放
@property (readonly) BOOL supportVideoZoom;

/// 当前设置的放大倍数
@property (readonly) float currentVideoZoomFactor;

/// 是否支持闪光灯
@property (readonly) BOOL supportFlash;

/// 支持的所有闪光灯模式，参考 `MDRecordCaptureFlashMode`
@property (readonly) NSArray *supportFlashModes;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithDeviceType:(MDRCaptureDeviceType)deviceType;

- (BOOL)isSupportCaptureResoulutionType:(MDRCaptureResolutionType)resolutionType;

@end
