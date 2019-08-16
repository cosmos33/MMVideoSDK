//
//  MDGPUImageFuzzyFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/1.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

// 使用minmap来得到模糊效果，因此传入的target必须生成了minmap

@interface MDGPUImageFuzzyFilter : GPUImageFilter

@property (nonatomic, assign) CGFloat level;

@end

NS_ASSUME_NONNULL_END
