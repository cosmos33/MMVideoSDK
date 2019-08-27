//
//  MDGPUImageTransformEffectGroup.h
//  MomoChat
//
//  Created by sunfei on 2018/11/6.
//  Copyright © 2018 wemomo.com. All rights reserved.
//

@import GPUImage;
#import "MDGPUImageTranslationAnimationProtocol.h"
#import "MDGPUImageEffectFilterProtocol.h"
#import "MDGPUImageTransformFilter.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDGPUImageTransformEffectGroup : GPUImageFilterGroup <MDGPUImageTranslationAnimationProtocol, MDGPUImageEffectFilterProtocol>

- (void)configEffectFilter:(MDGPUImageTransformFilter *)effectFilter;
- (GPUImageOutput<GPUImageInput> *)otherFilter;

@property (nonatomic, assign) CGFloat mix;

@end

NS_ASSUME_NONNULL_END
