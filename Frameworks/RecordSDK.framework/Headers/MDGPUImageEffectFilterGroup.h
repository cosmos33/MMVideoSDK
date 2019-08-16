//
//  MDGPUImageZoomFusionEffectFilterGroup.h
//  Filters
//
//  Created by sunfei on 2018/9/1.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;
@import MLFilterKit;
#import "MDGPUImageTranslationAnimationProtocol.h"

@interface MDGPUImageEffectFilterGroup : GPUImageFilterGroup <MDGPUImageTranslationAnimationProtocol>

- (instancetype)initWithBlendTexture:(MLFilterBlendTexture *)blendTexture sizeInPixels:(CGSize)sizeInPixels;

@end
