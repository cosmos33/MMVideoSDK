//
//  MDRXEngineModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class MDRFaceDetectorInfo;

@protocol MDRXEngineModuleProtocol <NSObject>

/// 开启引擎
/// @param path 资源路径
- (void)runEngineWithResourcePath:(NSString *)path;

/// 关闭引擎
- (void)stopEngine;

/// 旋转相机事件
/// @param position 前置/后置相机
- (void)rotateCamera:(MDRCaptureDeviceType)position;

/// 开启/关闭录制事件
/// @param enable 开启/关闭
- (void)enableRecording:(BOOL)enable;

/// 更新引擎关键点信息
/// @param detectorInfo 关键点信息
/// @param thinFaceFactor 瘦脸参数，如果需要引擎实现大眼瘦脸，需要传入瘦脸参数进行关键点运算
- (void)updateEngineWithDetectorInfo:(MDRFaceDetectorInfo * _Nullable)detectorInfo
                      thinFaceFactor:(float)thinFaceFactor;

/// 引擎是否正在运行
- (BOOL)isEngineRuning;

@end

NS_ASSUME_NONNULL_END
