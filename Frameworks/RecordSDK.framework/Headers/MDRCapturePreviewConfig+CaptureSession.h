//
//  MDRCapturePreviewConfig+CaptureSession.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/29.
//

#import "MDRCapturePreviewConfig.h"
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MDRCapturePreviewConfig (CaptureSession)

@property (nonatomic, assign, readonly) AVCaptureSessionPreset sessionPreset;
@property (nonatomic, assign, readonly) AVCaptureDevicePosition devicePosition;

@end

NS_ASSUME_NONNULL_END
