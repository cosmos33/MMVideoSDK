//
//  MDRRenderModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MDRFaceDetectorInfo;
@class FDKDecoration;

@protocol MDRBeautyParams <NSObject>

// 美颜信息 (0 - 1)
@property (nonatomic) float bigEyeFactor;  // 大眼
@property (nonatomic) float thinFaceFactor;  // 瘦脸
@property (nonatomic) float skinSmoothingFactor; // 磨皮
@property (nonatomic) float skinWhitenFactor; // 美白

//瘦身美腿相关 (0 - 1)
@property (nonatomic) float bodyWidthFactor;  // 瘦身
@property (nonatomic) float legsLenghtFactor; // 长腿

@end

@protocol MDRRenderModuleProtocol <NSObject>

/// 渲染处理输入的pixelBuffer
/// @param inputPixelBuffer 原始pixelBuffer
/// @param frameTime 帧时间
/// @param faceDetectorInfo 人脸特征信息，辅助渲染
/// @param finishCallback 渲染完成回调
- (void)renderInputPixelBuffer:(CVPixelBufferRef)inputPixelBuffer
                        atTime:(CMTime)frameTime
              faceDetectorInfo:(MDRFaceDetectorInfo * _Nullable)faceDetectorInfo
          renderFinishCallback:(void(^ _Nonnull)(CVPixelBufferRef _Nullable outputPixelBuffer, NSError * _Nullable error))callback;

@end

@protocol MDRRenderModuleInput <NSObject>

@property (atomic, assign) BOOL enable3D;
@property (nonatomic, assign) BOOL enableAIBeauty;

@end

NS_ASSUME_NONNULL_END
