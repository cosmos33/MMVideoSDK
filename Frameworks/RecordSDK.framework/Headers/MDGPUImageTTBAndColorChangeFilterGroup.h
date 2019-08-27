//
//  MDGPUImageTTBAndColorChangeFilterGroup.h
//  MomoChat
//
//  Created by sunfei on 2018/9/18.
//  Copyright © 2018 wemomo.com. All rights reserved.
//

@import GPUImage;
#import "MDGPUImageTranslationAnimationProtocol.h"
#import "MDGPUImageEffectFilterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDGPUImageTTBAndColorChangeFilterGroup : GPUImageFilterGroup <MDGPUImageTranslationAnimationProtocol, MDGPUImageEffectFilterProtocol>

@end

NS_ASSUME_NONNULL_END
