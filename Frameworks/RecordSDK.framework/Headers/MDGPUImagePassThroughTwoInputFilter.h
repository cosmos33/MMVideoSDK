//
//  MDGPUImagePassThroughTwoInputFilter.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/28.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;
#import "MDGPUImageTranslationAnimationProtocol.h"

@interface MDGPUImagePassThroughTwoInputFilter : GPUImageTwoInputFilter <MDGPUImageTranslationAnimationProtocol>

- (void)startAnimation;

@end
