//
//  MDRecordManager.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/2/19.
//

#import <Foundation/Foundation.h>

#ifdef Debug
#   define MDRDebugLog(fmt, ...) NSLog((@"[RecordSDK] %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define MDRDebugLog(...) do {} while (0)
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordManager : NSObject

+ (void)initSDK:(NSString *)appID;

+ (BOOL)isReady;

+ (void)fetchConfigUsingAppId;

+ (NSString *)version;

+ (NSString *)appToken;

@end

NS_ASSUME_NONNULL_END
