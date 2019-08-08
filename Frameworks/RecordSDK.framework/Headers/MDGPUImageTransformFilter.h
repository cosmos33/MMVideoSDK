//
//  MDGPUImageTransformFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/6.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDGPUImageTransformFilter : GPUImageTransformFilter

@property (nonatomic, assign) CGFloat scaleBegin;
@property (nonatomic, assign) CGFloat scaleEnd;
@property (nonatomic, assign) CGFloat scaleDuration;
@property (nonatomic, assign) CGFloat scaleTimeBegin;

@property (nonatomic, assign) CGPoint translationBegin;
@property (nonatomic, assign) CGPoint translationEnd;
@property (nonatomic, assign) CGFloat translationDuration;
@property (nonatomic, assign) CGFloat translationTimeBegin;

@end

NS_ASSUME_NONNULL_END
