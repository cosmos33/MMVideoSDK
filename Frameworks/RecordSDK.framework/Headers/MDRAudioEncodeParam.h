//
//  MDRAudioEncodeParam.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

@interface MDRAudioEncodeParam : NSObject

/// 音频编码类型，default: MDRAudioEncodeType_AAC
@property (nonatomic, assign) MDRAudioEncodeType encodeType;

/// 音频采样信息，default: {sampleRate: 44100, sampleFormat: MDRAudioSampleFormatType_S16, channelCount: 1}
@property (nonatomic, assign) MDRAudioResolution resolution;

/// 码率，单位bit，default: 256 * 1000 bit
@property (nonatomic, assign) NSUInteger bitrate;

- (NSDictionary *)audioEncodeParamForSystem;

@end

