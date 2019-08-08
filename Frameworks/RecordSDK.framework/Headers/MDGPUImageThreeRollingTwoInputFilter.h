//
//  MDGPUImageThreeRollingTwoInputFilter.h
//  Filters
//
//  Created by sunfei on 2018/8/31.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;
#import "MDGPUImageTranslationAnimationProtocol.h"

@interface MDGPUImageThreeRollingTwoInputFilter : GPUImageTwoInputFilter <MDGPUImageTranslationAnimationProtocol>

- (void)startAnimation;

@end
