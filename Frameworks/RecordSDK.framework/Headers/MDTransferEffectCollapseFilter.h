//
//  MDTransferEffectCollapseFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/2.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDTransferEffectCollapseFilter : GPUImageFilter

@property (nonatomic, assign) CGPoint pointA;
@property (nonatomic, assign) CGPoint pointB;

@property (nonatomic, assign) CGPoint pointC;
@property (nonatomic, assign) CGPoint pointD;

@end

NS_ASSUME_NONNULL_END
