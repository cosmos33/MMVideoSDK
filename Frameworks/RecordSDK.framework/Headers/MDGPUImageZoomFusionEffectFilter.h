//
//  MDGPUImageZoomFusionEffectFilter.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/27.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;
#import "MDGPUImageTranslationAnimationProtocol.h"

@interface MDGPUImageZoomFusionEffectFilter : GPUImageTwoInputFilter <MDGPUImageTranslationAnimationProtocol>

- (void)startAnimation;

@end
