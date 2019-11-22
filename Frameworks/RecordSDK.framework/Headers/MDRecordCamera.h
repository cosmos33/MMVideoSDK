//
//  BBCamera.h
//  BiBi
//
//  Created by YuAo on 3/29/16.
//  Copyright © 2016 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface MDRecordCamera : NSObject

- (id)initWithSessionPreset:(NSString *)sessionPreset cameraPosition:(AVCaptureDevicePosition)cameraPosition;

- (void)enableVideoDataOutputWithDelegate:(id<AVCaptureVideoDataOutputSampleBufferDelegate>)delegate queue:(dispatch_queue_t)queue;

- (void)enableAudioDataOutputWithDelegate:(id<AVCaptureAudioDataOutputSampleBufferDelegate>)delegate queue:(dispatch_queue_t)queue;
- (void)disableAudioDataOutput;

- (void)startRunningCaptureSession;

- (void)stopRunningCaptureSession;

- (void)removeSampleBufferDelegateAndQueue;
- (void)addVideoSampleBufferDelegate:(id<AVCaptureVideoDataOutputSampleBufferDelegate>)delegate queue:(dispatch_queue_t)queue;
- (void)addAudioSampleBufferDelegate:(id<AVCaptureAudioDataOutputSampleBufferDelegate>)delegate queue:(dispatch_queue_t)queue;

- (void)rotateCamera;

- (BOOL)changeSessionPreset:(AVCaptureSessionPreset)sessionPreset;

//camera的一些清理工作
- (void)cleanCamera;

@property (nonatomic) NSInteger videoCaptureDeviceFrameRate;

@property (nonatomic, strong, readonly) AVCaptureDevice *currentCameraDevice;
@property (nonatomic, strong, readonly) AVCaptureConnection *videoCaptureConnection;
@property (nonatomic, readonly) AVCaptureDevicePosition currentDevicePosition;
@property (nonatomic, assign) float cameraZoomFactor;

@property (nonatomic, readonly) BOOL hasVideoInput;
@property (nonatomic,strong, readonly) AVCaptureVideoDataOutput *videoDataOutput;
@property (nonatomic,strong, readonly) AVCaptureAudioDataOutput *audioDataOutput;

@property (nonatomic, readonly) BOOL hasTorch;
@property (nonatomic, readonly) BOOL hasFlash;
@property (nonatomic, assign) AVCaptureTorchMode torchMode;
@property (nonatomic, assign) AVCaptureFlashMode flashMode;

@property (nonatomic,assign) BOOL disableAutoConfigAudioSession;

- (BOOL)supportCpatureTorchMode:(AVCaptureTorchMode)mode;
- (BOOL)supportCaptureFlashMode:(AVCaptureFlashMode)mode;

- (void)enableSmoothAutoFocus:(BOOL)enable;
- (void)setCameraVideoOrientation:(AVCaptureVideoOrientation)orientation;
- (void)setCameraVideoMirrored:(BOOL)mirrored;
- (void)setPreferredVideoStabilizationMode:(AVCaptureVideoStabilizationMode)mode;

@property (nonatomic, readonly) float minExposureTargetBias;
@property (nonatomic, readonly) float maxExposureTargetBias;

- (void)updateISO:(float)ISO;
- (void)updateExposureTargetBias:(float)bias;
- (void)setFocusPoint:(CGPoint)focusPoint;
- (void)setExposurePoint:(CGPoint)exposurePoint;
- (void)focusAndExposeAtPoint:(CGPoint)pointOfInterest;
- (void)setPreferredVideoStabilizationMode:(AVCaptureVideoStabilizationMode)mode;

@end
