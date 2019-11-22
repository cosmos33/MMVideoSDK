//
//  MDCXBeautyKitModule.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import "MDCXBeautyKitModuleProtocol.h"
@import CXBeautyKit;

@protocol MDRBeautyParams;

NS_ASSUME_NONNULL_BEGIN

@interface MDCXBeautyKitModule : NSObject <MDCXBeautyKitModuleProtocol, MDRBeautyParams, MDCXBeautyKitModuleFaceInfo>


/// 创建BeautyKit渲染
/// @param context Metal运行的上下文
/// @param beautyConfiguration 配置文件
- (instancetype)initWithContext:(MTIContext *)context configuration:(CXBeautyConfiguration *)beautyConfiguration;

// pixelbuffer meta info
@property (nonatomic, strong, nullable) CXAutoLevelInfo *autoLevelInfo;

// video sequence or still image
@property (nonatomic, assign) CXFilterInputType inputType;


@end

NS_ASSUME_NONNULL_END
