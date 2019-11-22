//
//  MDCXBeautyKitModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <MetalPetal/MetalPetal.h>
#import "MDRFaceDetectorInfo.h"

@class MDRFaceDetectorInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol MDCXBeautyKitModuleFaceInfo <NSObject>

// 关键点信息
@property (nonatomic, strong, nullable) MDRFaceDetectorInfo *faceInfo;

@end

@protocol MDCXBeautyKitModuleProtocol <MTIUnaryFilter>

@end

NS_ASSUME_NONNULL_END
