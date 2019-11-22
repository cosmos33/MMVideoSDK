//
//  MDRBackgroundBlurfilter.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/10/22.
//

@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDRBackgroundBlurfilter : GPUImageTwoInputFilter

@property (nonatomic, assign) CGSize outputImageSize;

@end

NS_ASSUME_NONNULL_END
