//
//  FDKDecoration+MDRDetectorRequirements.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/6/26.
//

@import FaceDecorationKit;
#import "MDRDetectorRequirements.h"

NS_ASSUME_NONNULL_BEGIN

@interface FDKDecoration (MDRDetectorRequirements) <MDRDetectorRequirements>

@end

@interface FDKDecoration (MDRFaceDetectorAlignment)

@property (nonatomic, readonly) NSUInteger faceAlignmentVersion;

@end

NS_ASSUME_NONNULL_END
