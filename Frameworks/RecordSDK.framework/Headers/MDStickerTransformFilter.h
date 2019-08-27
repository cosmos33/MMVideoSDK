//
//  MDStickerTransformFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/5.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDStickerTransformFilter : GPUImageFilter

// 0 - 1
@property (nonatomic, assign) CGPoint center;

// 0 - 1
@property (nonatomic, assign) CGSize size;

// -PI - PI
@property (nonatomic, assign) CGFloat rotation;

// 0 - 1
@property (nonatomic, assign) CGFloat opacity;

// true canvese size
@property (nonatomic, assign) CGSize renderSize;

@end

NS_ASSUME_NONNULL_END
