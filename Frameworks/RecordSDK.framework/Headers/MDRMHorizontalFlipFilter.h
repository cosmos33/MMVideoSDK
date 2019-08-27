//
//  MDRMHorizontalFlipFilter.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/8/13.
//

#import <Foundation/Foundation.h>

@import MetalPetal;

NS_ASSUME_NONNULL_BEGIN

@interface MDRMHorizontalFlipFilter : MTIUnaryImageRenderingFilter

@property (nonatomic, assign, getter=isDisable) BOOL disable;

@end

NS_ASSUME_NONNULL_END
