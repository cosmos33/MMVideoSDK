//
//  MDGPUImageColorChangeFilterGroup.h
//  Filters
//
//  Created by sunfei on 2018/9/3.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;
@import MLFilterKit;
#import "MDGPUImageTranslationAnimationProtocol.h"
#import "MDGPUImageEffectFilterProtocol.h"

@interface MDGPUImageColorChangeFilterGroup : GPUImageFilterGroup <MDGPUImageTranslationAnimationProtocol, MDGPUImageEffectFilterProtocol>

@end
