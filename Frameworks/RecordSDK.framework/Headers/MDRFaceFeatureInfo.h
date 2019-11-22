//
//  MDRFaceFeatureInfo.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/11/5.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class MMFaceFeature;
@class MMBodyFeature;

@interface MDRFaceFeatureInfo : NSObject

/// 检测依赖的buffer
@property (nonatomic, assign) CVPixelBufferRef pixelBuffer;
/// 所有检测到的人脸
@property (nonatomic, copy) NSArray<MMFaceFeature *> *faceFeatures;
/// 躯体信息
@property (nonatomic, copy) NSArray<MMBodyFeature *> *bodyFeatures;
/// 是否检测到光膀子
@property (nonatomic, assign) BOOL hasDetectorBareness;

@end
