//
//  MDRCaptureRecordingConfig.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

@class MDRAudioEncodeParam;
@class MDRVideoEncodeParam;

@interface MDRCaptureRecordingConfig : NSObject

/// 录制片段输出路径
@property (nonatomic, copy) NSURL *outputFilePathURL;

/// 录制选项
@property (nonatomic, assign) MDRRecordingFlagOption flags;

/// 视频编码参数
@property (nonatomic, strong) MDRVideoEncodeParam *videoEncodeParam;

/// 音频编码参数
@property (nonatomic, strong) MDRAudioEncodeParam *audioEncodeParam;


/// 更新编码配置
/// @param encodeParam 业务传的编码配置
/// @param captureResolution 实际采集分辨率，如果外界没有设置编码分辨率，默认用采集分辨率
/// @param captureFrameRate 采集帧率
- (void)updateWithEncodeParam:(NSDictionary *)encodeParam
            captureResolution:(MDRVideoResolution)captureResolution
             captureFrameRate:(NSInteger)captureFrameRate;

@end
