//
//  MDRStickerProtocol.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/10/29.
//

#import <Foundation/Foundation.h>
@import FaceDecorationKitGPUImage;

NS_ASSUME_NONNULL_BEGIN

@protocol MDRStickerProtocol <NSObject>

- (instancetype)initWithDecorationURL:(NSURL *)url inputFrameSize:(CGSize)inputFrameSize;

@property (nonatomic, assign) CMTimeRange duration;

- (FDKDecorationFilter *)makeFilter;
- (void)update;

- (CGSize)stickerSize;

@end

NS_ASSUME_NONNULL_END
