//
//  MDRecordManager.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/2/19.
//

#import <Foundation/Foundation.h>

@protocol MDRIRecordLogger;

extern NSString * const _Nonnull __kMMVideoSDKTag__;

#ifdef DEBUG
#define MDRLog(fmt, ...) autoreleasepool {} 
#else
#define MDRLog(fmt, ...) try {} @catch (...) {} 
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordManager : NSObject

+ (void)initSDK:(NSString *)appID;

+ (BOOL)isReady;

+ (void)fetchConfigUsingAppId;

+ (NSString *)version;

+ (NSString *)appToken;

+ (void)configLogger:(id<MDRIRecordLogger> _Nullable)logger;
+ (id<MDRIRecordLogger> _Nullable)logger;

+ (void)enableConsoleLog:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
