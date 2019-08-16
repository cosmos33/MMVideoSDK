//
//  MDDateStickerFilter.h
//  GPUImageTest
//
//  Created by sunfei on 2018/11/5.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDTextStickerFilter : GPUImageFilterGroup

- (instancetype)init NS_UNAVAILABLE; 
- (instancetype)initWithText:(NSString *)stickerText;
- (instancetype)initWithAttributedString:(NSAttributedString *)attributedString;

@property (nonatomic, assign) CGFloat beginTime;

@end

NS_ASSUME_NONNULL_END
