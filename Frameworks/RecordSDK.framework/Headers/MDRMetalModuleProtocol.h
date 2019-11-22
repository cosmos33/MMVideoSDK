//
//  MDRMDRMetalModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MDRRenderModuleProtocol.h"
#import "MDRMetalFilterDescriptor.h"

@class FDKDecoration;
@class MDRFaceDetectorInfo;
@class CXBeautyConfiguration;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MDRMetalModuleInputType) {
    MDRMetalModuleInputTypeVideoSequence,
    MDRMetalModuleInputTypeStillImage
};

@protocol MDRMetalModuleProtocol <MDRRenderModuleProtocol>

- (void)registerEffectDescriptor:(id<MDRMetalFilterDescriptor>)descriptor;
- (void)unregisterAllEffect;

@property (nonatomic, assign) BOOL enableAIBeauty;

// 设置输入视频帧序列还是静态图
@property (nonatomic, assign) MDRMetalModuleInputType inputType;

// AI美颜时候配置初始美颜参数
- (void)setBeautyConfiguration:(CXBeautyConfiguration *)config;

@property (nonatomic, strong) id<MDRBeautyParams> beautyParams;

@end

NS_ASSUME_NONNULL_END
