//
//  MDEaseFunction.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/3.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

@interface MDEaseFunction : NSObject

- (instancetype)initWithBegin:(CGFloat)begin end:(CGFloat)end duration:(CGFloat)duration;

@property (nonatomic, readonly) CGFloat b;
@property (nonatomic, readonly) CGFloat e;
@property (nonatomic, readonly) CGFloat d;

@property (nonatomic, readonly) CGFloat c;

- (CGFloat)evaluateAtTime:(CGFloat)t;

@end

NS_ASSUME_NONNULL_END
