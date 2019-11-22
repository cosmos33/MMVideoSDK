//
//  MDRFaceDetectorInfo.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>

@class MMBodyFeature;
@class MMHandFeature;
@class FDKDecorationFilterUpdateRequest;
@class MMFaceFeature;
@class MMImageSegmentationResult;
@class MMFacialExpression;

@protocol FDKObjectFeature;
@protocol FDKFaceWarpResult;

NS_ASSUME_NONNULL_BEGIN

@interface MDRFaceDetectorInfo : NSObject

- (instancetype)initWithPixelBufferSize:(CGSize)size;

// 正在使用的人脸
@property (nonatomic, strong) MMFaceFeature *currentFaceFeature;
// 所有检测到的人脸
@property (nonatomic, copy) NSArray<MMFaceFeature *> *faceFeatures;
// 表情信息
@property (nonatomic, copy) NSArray<MMFacialExpression *> *expressions;
// animoji
@property (nonatomic, strong) MMFaceFeature *facerigFeature;
// 手势信息
@property (nonatomic, strong) MMHandFeature *handFeature;
// 肢体动作信息
@property (nonatomic, copy) NSArray<id<FDKObjectFeature>> *objectFeatures;
// 图像分割
@property (nonatomic, strong) MMImageSegmentationResult *imageSegmentationResult;
// 躯体信息
@property (nonatomic, copy) NSArray<MMBodyFeature *> *bodyFeatures;

// 光膀子信息
@property (nonatomic, assign, getter=isBareness) BOOL bareness;

@property (nonatomic, readonly) CGSize pixelBufferSize;

@end

NS_ASSUME_NONNULL_END
