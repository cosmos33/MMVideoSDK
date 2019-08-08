//
//  GPUImageFuzzyZoomGradualChangeFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/1.
//  Copyright © 2018 sunfei. All rights reserved.
//



@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface GPUImageFuzzyZoomGradualChangeFilter : GPUImageFilterGroup

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRenderSize:(CGSize)renderSize imageSize:(CGSize)imageSize NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
