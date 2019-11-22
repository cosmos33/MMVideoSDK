//
//  MDRVideoEncodeParam.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/29.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

@interface MDRVideoEncodeParam : NSObject

/// 视频编码类型，default: MDRVideoEncodeType_H264
@property (nonatomic, assign) MDRVideoEncodeType encodeType;

/// 视频编码分辨率，default: {720, 1280}
@property (nonatomic, assign) MDRVideoResolution resolution;

/// 码率，单位bit，default: 5 * 1000 * 1000 bit
@property (nonatomic, assign) NSInteger bitrate;

/// 视频编码裁剪模式，default:MDRVideoEncodeScaleMode_ResizeAspectFill
@property (nonatomic, assign) MDRVideoEncodeScaleMode scaleMode;

/// 视频编码帧率，default: 30
@property (nonatomic, assign) NSInteger frameRate;

- (NSDictionary *)videoEncodeParamForSystem;

@end
