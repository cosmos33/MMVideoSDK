//
//  MDTransferEffectZoomDarkGradualChangeFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/1.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

#import "MDEaseConstantString.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDTransferEffectZoomDarkGradualChangeFilter : GPUImageFilterGroup

@property (nonatomic, assign) CGFloat zoomBeginValue;
@property (nonatomic, assign) CGFloat zoomEndValue;
@property (nonatomic, assign) CGFloat zoomBeginTime;
@property (nonatomic, assign) CGFloat zoomDurationTime;
@property (nonatomic, copy) MDEaseFunctionKey zoomFunctionKey;

@property (nonatomic, assign) CGFloat brightnessBeginValue;
@property (nonatomic, assign) CGFloat brightnessEndValue;
@property (nonatomic, assign) CGFloat brightnessBeginTime;
@property (nonatomic, assign) CGFloat brightnessDurationTime;
@property (nonatomic, copy) MDEaseFunctionKey brightnessFunctionKey;

@end

NS_ASSUME_NONNULL_END
