//
//  MDFaceDetectorContext.h
//  CXBeautyKit
//
//  Created by sunfei on 2018/11/27.
//

#import <Foundation/Foundation.h>
#import "MDImageDetectorProtocol.h"
@import MomoCV;

NS_ASSUME_NONNULL_BEGIN

@interface MMFaceDetectOptions (MDOptions) <MDImageDetectorOptions>

@end

@interface MDFaceDetectorContext : NSObject <MDImageDetectorProtocol>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype _Nullable)makeDetector;
+ (void)asyncAutoMakeDetector:(void(^)(MDFaceDetectorContext * _Nullable))completed;

@property (nonatomic, readonly) NSArray<MMFaceFeature *> *result;
@property (nonatomic, readonly) NSArray<NSNumber *> *skinColorThreshold;

@property (nonatomic, assign) BOOL advancedStabilizationModeEnabled;

@end

NS_ASSUME_NONNULL_END
