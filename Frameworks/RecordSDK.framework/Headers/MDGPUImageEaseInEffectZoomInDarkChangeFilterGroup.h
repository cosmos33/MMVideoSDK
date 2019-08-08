//
//  MDGPUImageEaseInEffectZoomInDarkChangeFilterGroup.h
//  MomoChat
//
//  Created by sunfei on 2018/11/6.
//  Copyright © 2018 wemomo.com. All rights reserved.
//

@import GPUImage;
#import "MDGPUImageTranslationAnimationProtocol.h"
#import "MDGPUImageEffectFilterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDGPUImageEaseInEffectZoomInDarkChangeFilterGroup : GPUImageFilterGroup <MDGPUImageTranslationAnimationProtocol, MDGPUImageEffectFilterProtocol>

- (instancetype)initWithImage:(UIImage *)image sizeInPixels:(CGSize)sizeInPixels;

@end

NS_ASSUME_NONNULL_END
