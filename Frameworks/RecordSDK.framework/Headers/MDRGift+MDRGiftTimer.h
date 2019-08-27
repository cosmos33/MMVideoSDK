//
//  MDRGift+MDRGiftTimer.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/6/27.
//

#import "MDRGift.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDRGift ()

// 接入方不要手动调用这两个方法
- (void)startTimer;
@property (nonatomic, copy) void(^timeIsOver)(MDRGift *gift);

@end

NS_ASSUME_NONNULL_END
