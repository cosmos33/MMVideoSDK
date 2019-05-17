//
//  MMImageSegmenterContext.h
//  CXBeautyKit
//
//  Created by sunfei on 2018/11/27.
//

#import <Foundation/Foundation.h>
#import "MDImageDetectorProtocol.h"

@class MMImageSegmentationResult;

NS_ASSUME_NONNULL_BEGIN

@interface MDImageSegmenterContext : NSObject <MDImageDetectorProtocol>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype _Nullable)makeDetector;
+ (void)asyncAutoMakeDetector:(void(^)(MDImageSegmenterContext * _Nullable))completed;

@property (nonatomic, readonly) MMImageSegmentationResult *result;

@end

NS_ASSUME_NONNULL_END
