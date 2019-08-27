//
//  MDRAnalytics.h
//  Pods
//
//  Created by sunfei on 2019/7/5.
//

#import <Foundation/Foundation.h>
#import "MDRecordLoggerKey.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MDRAnalyticsType) {
    MDRAnalyticsTypeUnknow,
    MDRAnalyticsTypeRecord,
    MDRAnalyticsTypeVideo,
    MDRAnalyticsTypePicture,
};

@interface MDRAnalytics : NSObject

- (instancetype)init NS_UNAVAILABLE;

// log event
+ (void)logEvent:(MDRAnalyticsType)eventType params:(NSDictionary *)params;
+ (void)logPictureEventWithParams:(NSDictionary *)params;
+ (void)logVideoEventWithParams:(NSDictionary *)params;
+ (void)logRecordEventWithParams:(NSDictionary *)params;

// consume
+ (void)consumeAnalyticsParamsForType:(MDRAnalyticsType)type;
+ (void)consumePictureAnalyticsParams;
+ (void)consumeVideoAnalyticsParams;
+ (void)consumeRecordAnalyticsParams;

// error
+ (void)reportError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
