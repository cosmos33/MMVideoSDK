//
//  MDObjectDetectorContext.h
//  CXBeautyKit
//
//  Created by sunfei on 2018/11/27.
//

#import <Foundation/Foundation.h>
#import "MDImageDetectorProtocol.h"

@class MMObjectDetectionResult;

NS_ASSUME_NONNULL_BEGIN

@interface MDObjectDetectorContext : NSObject <MDImageDetectorProtocol>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype _Nullable)makeDetector;
+ (void)asyncAutoMakeDetector:(void(^)(MDObjectDetectorContext * _Nullable))completed;

@property (nonatomic, readonly) MMObjectDetectionResult *result;

@end

NS_ASSUME_NONNULL_END
