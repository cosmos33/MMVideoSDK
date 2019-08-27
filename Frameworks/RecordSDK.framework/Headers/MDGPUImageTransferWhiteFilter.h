//
//  MDGPUImageTransferWhiteFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/6.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDGPUImageTransferWhiteFilter : GPUImageFilter

@property (nonatomic, assign) GLfloat slope;

@property (nonatomic, assign) GLfloat intercept;

@property (nonatomic, assign) GLint direction;

@end

NS_ASSUME_NONNULL_END
