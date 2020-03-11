//
//  MDRecordManager.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/2/19.
//

#import <Foundation/Foundation.h>

@protocol MDRIRecordLogger, MDLoggerService;

extern NSString * const _Nonnull __kMMVideoSDKTag__;

#define __MDRDebugLog(level, tagStr, fmt, ...) \
do { \
id<MDLoggerService> const __logger = [MDRecordManager mdLoggerService]; \
MDLogLevel const __level = (level); \
 [__logger loggerWithLevel:__level tag:(tagStr) file:@(__FILE__) function:@(__FUNCTION__) line:__LINE__ message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]];\
} while (0)

#ifdef DEBUG
#define MDRLog(fmt, ...) autoreleasepool {} __MDRDebugLog(MDLogLevelDebug, __kMMVideoSDKTag__, fmt, ##__VA_ARGS__)
#else
#define MDRLog(fmt, ...) try {} @catch (...) {} __MDRDebugLog(MDLogLevelDebug, __kMMVideoSDKTag__, fmt, ##__VA_ARGS__)
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordManager : NSObject

+ (void)initSDK:(NSString *)appID;

+ (BOOL)isReady;

+ (void)fetchConfigUsingAppId;

+ (NSString *)version;

+ (NSString *)appToken;

+ (void)setUserId:(NSString *)userId;
+ (NSString *)userId;

+ (void)configLogger:(id<MDRIRecordLogger>)logger;
+ (id<MDRIRecordLogger>)logger;

+ (void)enableConsoleLog:(BOOL)enable;

+ (id<MDLoggerService>)mdLoggerService;

@end

NS_ASSUME_NONNULL_END
