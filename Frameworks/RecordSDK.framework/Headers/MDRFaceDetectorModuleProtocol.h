//
//  MDRFaceDetectorModuleProtocol.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class MDRFaceDetectorInfo;
@class FDKDecoration;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, MDRFaceDetectorModuleOptions) {
    // detector to enable
    MDRFaceDetectorModuleFace = 1 << 0,              // 人脸检测器
    MDRFaceDetectorModuleBody = 1 << 1,              // 躯体动作检测器
    MDRFaceDetectorModuleAnimoji = 1 << 2,           // animoji检测器
    MDRFaceDetectorModuleImageSegment = 1 << 3,      // 分割器
    MDRFaceDetectorModuleObject = 1 << 4,            // 肢体检测器
    MDRFaceDetectorModuleHandGesture = 1 << 5,       // 手势检测器
    MDRFaceDetectorModuleBareness = 1 << 6,          // 光膀子检测器
    
    MDRFaceDetectorModuleAll = MDRFaceDetectorModuleFace | MDRFaceDetectorModuleBody | MDRFaceDetectorModuleAnimoji | MDRFaceDetectorModuleImageSegment | MDRFaceDetectorModuleObject | MDRFaceDetectorModuleHandGesture | MDRFaceDetectorModuleBareness,
};

@protocol MDRFaceDetectorModuleProtocol <NSObject>

/// 加载模型
/// @param options 需要加载的模型
- (void)loadWithOptions:(MDRFaceDetectorModuleOptions)options;

/// 关键点检测
/// @param pixelBuffer 需要检测的图像数据
/// @param orientation 设备旋转方向
/// @param position 相机位置
- (MDRFaceDetectorInfo * _Nullable)detectorInfoWithPixelBuffer:(CVPixelBufferRef)pixelBuffer
                                                   orientation:(UIDeviceOrientation)orientation
                                         captureDevicePosition:(AVCaptureDevicePosition)position;

/// 重置关键点检测器
/// @param options 需要重置的检测器
- (void)resetWithOptions:(MDRFaceDetectorModuleOptions)options;

/// 人脸检测防抖属性
@property (nonatomic, assign) BOOL advancedStabilizationModeEnabled;

/// 是否支持多人脸切换
@property (nonatomic, assign) BOOL enableMutiFace;

/// 手势检测类型
@property (nonatomic, assign) NSUInteger handGestureType;

@end

NS_ASSUME_NONNULL_END
