//
//  MDGPUImageResizeFilter.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/24.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

@interface MDGPUImageResizeFilter : GPUImageFilter

// set scaling to consider retina display
@property (nonatomic, assign) CGSize sizeInPixels;
@property (nonatomic, assign) GPUImageFillModeType fillMode;

// debug
@property (nonatomic, assign) BOOL passthrough;
- (UIImage *)showCurrentBufferImage;

@end
