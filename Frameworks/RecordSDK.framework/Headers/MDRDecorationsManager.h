//
//  MDRDecorationsManager.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/6/26.
//

#import <Foundation/Foundation.h>
#import "MDRGift.h"
#import "FDKDecoration+MDRDetectorRequirements.h"
#import "MDRDetectorRequirements.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDRDecorationsManager : NSObject <MDRDetectorRequirements>

@property (nonatomic, readonly, nullable) FDKDecoration *decoration;

- (void)updateFaceDecoration:(FDKDecoration * _Nullable)decoration;

- (void)addGift:(MDRGift *)gift;
- (void)removeGift:(NSString *)giftID;

- (void)clearAllGifts;

- (void)clearAll;

@end

NS_ASSUME_NONNULL_END
