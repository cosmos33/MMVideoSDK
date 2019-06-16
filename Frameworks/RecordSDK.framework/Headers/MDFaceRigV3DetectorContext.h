//
//  MDFaceRigV3DetectorContext.h
//  CXBeautyKit
//
//  Created by sunfei on 2018/11/27.
//

#import <Foundation/Foundation.h>
#import "MDImageDetectorProtocol.h"

@class MMFaceRigFeature;

NS_ASSUME_NONNULL_BEGIN

@interface MDFaceRigV3DetectorContext : NSObject <MDImageDetectorProtocol>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype _Nullable)makeDetector;
+ (void)asyncAutoMakeDetector:(void(^)(MDFaceRigV3DetectorContext * _Nullable))completed;

@property (nonatomic, readonly) MMFaceRigFeature *result;

@end

NS_ASSUME_NONNULL_END
