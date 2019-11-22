//
//  MDRStaticSticker.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/10/29.
//

#import <Foundation/Foundation.h>
#import "MDRStickerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDRStaticSticker : NSObject <MDRStickerProtocol, NSCopying>

// 图片名称前缀，可为空
@property (nonatomic, copy, nullable) NSString *resourceName;

// 图像位置 0 - 1
@property (nonatomic, assign) CGPoint center;
// 图像大小 0 - 1
@property (nonatomic, assign) CGSize stickerSize;

@end

NS_ASSUME_NONNULL_END
