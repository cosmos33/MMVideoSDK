//
//  MDGPUImageAlbumPlayerPiplineFilterGroup.h
//  Filters
//
//  Created by sunfei on 2018/8/31.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;
@import MLFilterKit;
#import "MDGPUImageTranslationAnimationProtocol.h"
#import "MDGPUImageEffectFilterProtocol.h"

@interface MDGPUImageAlbumPlayerPiplineFilterGroup : GPUImageFilterGroup <MDGPUImageTranslationAnimationProtocol>

- (instancetype)initWithSizeInPixels:(CGSize)sizeInPixels;

@property (nonatomic, strong) NSArray<UIImage *> *images;

- (nonnull NSString *)firstAnimationItem;
- (nullable NSString *)lastAnimationItem;
- (NSArray<NSString *> *)animationItems;

@end
