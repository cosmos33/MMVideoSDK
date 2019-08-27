//
//  MDRDetectorRequirements.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/6/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MDRDetectorRequirements <NSObject>

@property (nonatomic, readonly) BOOL mdr_enable3D;
@property (nonatomic, readonly) BOOL mdr_enableMultiFaceSwitch;
@property (nonatomic, readonly) BOOL mdr_enableBodyDetector;
@property (nonatomic, readonly) BOOL mdr_enableAnimojiDetector;
@property (nonatomic, readonly) BOOL mdr_enableImageSegmenter;
@property (nonatomic, readonly) BOOL mdr_enableObjectDetector;
@property (nonatomic, readonly) BOOL mdr_enableHandGestureDetector;
@property (nonatomic, readonly) NSUInteger mdr_handGestureType;

@property (nonatomic, readonly) NSUInteger mdr_facialDistortionsCount;

@end

NS_ASSUME_NONNULL_END
