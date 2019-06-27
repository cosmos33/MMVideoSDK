//
//  MDRecordManager.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/2/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordManager : NSObject

+ (void)initSDK:(NSString *)appID;

+ (BOOL)isReady;

+ (void)fetchConfigUsingAppId;

+ (NSString *)version;

+ (NSString *)appToken;

@end

NS_ASSUME_NONNULL_END
