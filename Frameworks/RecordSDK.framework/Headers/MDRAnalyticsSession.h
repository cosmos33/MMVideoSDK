//
//  MDRAnalyticsSession.h
//  Pods
//
//  Created by sunfei on 2019/7/5.
//

#import <Foundation/Foundation.h>
#import "MDRAnalytics.h"
#import "MDError.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDRAnalyticsSession : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithType:(MDRAnalyticsType)type forKey:(NSString *)key NS_DESIGNATED_INITIALIZER;

+ (instancetype)beginWithType:(MDRAnalyticsType)type forKey:(NSString *)key;

- (void)apppendParams:(NSDictionary *)params;

- (void)markSuccess;

- (void)abort;

- (void)markFailureWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
