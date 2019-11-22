//
//  MDRCameraUtil.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/29.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MDRCommonDefine.h"
#import "NSObject+MDRDictionaryAdapter.h"
#import "MDRecordLoggerKey.h"
#import "MDRAnalytics.h"
#import "MDRecordManager.h"
#import "MDError.h"
#import "MDLog/MDlog.h"
#import "MDRCameraException.h"

FOUNDATION_EXPORT void MDRDispatchAsynchronouslyOnMainQueue(void (^action)(void));

NS_INLINE BOOL MDRIsFloatEqual(float value1, float value2) {
    return fabsf(value1 - value2) <= 0.00001f;
}

//机型等级
typedef NS_ENUM(NSInteger, MDRPhoneLevel) {
    MDRPhoneLevelLow = 0,
    MDRPhoneLevelMedium,
    MDRPhoneLevelHigh
};

@interface MDRCameraUtil : NSObject

///MDRCaptureResolutionType -> AVCaptureSessionPreset
+ (AVCaptureSessionPreset)sessionPresetWithResolutionType:(MDRCaptureResolutionType)resolutionType;

///deviceType -> AVCaptureDevicePosition
+ (AVCaptureDevicePosition)devicePositionWithDeviceType:(MDRCaptureDeviceType)deviceType;

///MDRCaptureResolutionType -> MDRVideoResolution
+ (MDRVideoResolution)videoResolutionValueWithResolutionType:(MDRCaptureResolutionType)resolutionType;

///MDRVideoEncodeScaleMode -> AVVideoScalingModeKey
+ (NSString *)avVideoScalingModeKeyWithScalingMode:(MDRVideoEncodeScaleMode)scalingMode;

///如果sourceAsset的duration小于totalDuration，则会循环插入sourceAsset，直到大于totalDuration；
/// 如果大于totalDuration，直接插入sourceAsset
+ (AVAsset *)fillAssetWithSourceAsset:(AVAsset *)sourceAsset andTotalDuration:(CGFloat)totalDuration;

///当前系统时间戳生成的唯一URL
+ (NSURL *)generateMovieTempURL;

///获取机型等级
+ (MDRPhoneLevel)currentPhoneLevel;

@end
