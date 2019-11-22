//
//  MDCameraEngineDelegate.h
//  BroadcastChannel
//
//  Created by 符吉胜 on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class MDRCameraEngine;
@class MDRFaceFeatureInfo;
@class MDRMediaSegmentInfo;

@protocol MDRCameraEngineDelegate <NSObject>

@optional

/// 引擎状态发生改变
/// @param cameraEngine 引擎对象
/// @param state 当前引擎状态
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine didChangeEngineState:(MDRCameraEngineState)state;

/// 录制进度改变
/// @param cameraEngine 引擎对象
/// @param progress 当前录制进度
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine didChangeRecordProgress:(double)progress;

/// 导出进度改变
/// @param cameraEngine 引擎对象
/// @param progress 导出进度
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine didChangeExportProgress:(double)progress;

/// 达到了最大录制时长，SDK内部会在最后一段视频导出完成后回调，
/// 业务端可以选择在这个回调里调用exportVideoWithCompletionHandler进行视频多段合并导出
/// @param cameraEngine 引擎对象
- (void)didReachRecordMaxDuration:(MDRCameraEngine *)cameraEngine;

/// 每段录制失败会回调
/// @param cameraEngine 引擎对象
/// @param failType 失败类型
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine
didASegmentGenerateFailType:(MDRSegmentGenerateFailType)failType;

/// 录制片段数改变的回调，增删片段会回调
/// @param cameraEngine 引擎对象
/// @param segmentInfos 媒体片段数组
- (void)didVideoSegmentNumbnerChange:(MDRCameraEngine *)cameraEngine
                        segmentInfos:(NSArray<MDRMediaSegmentInfo *> *)segmentInfos;

/// 人脸关键信息回调
/// @param cameraEngineC引擎对象
/// @param faceFeatureInfo 人脸特征信息
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine didOutputFaceFeatureInfo:(MDRFaceFeatureInfo *)faceFeatureInfo;

/// 视频数据回调
/// @param cameraEngine 引擎对象
/// @param sampleBuffer 视频buffer
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine didOutputVideoSampleBuffer:(CVPixelBufferRef)sampleBuffer;

/// 音频裸数据回调
/// @param cameraEngine 引擎对象
/// @param audioSampleBuffer 音频裸数据
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine didOutputAudioSampleBuffer:(CMSampleBufferRef)audioSampleBuffer;

/// 引擎出异常
/// @param cameraEngine 引擎对象
/// @param errorCode 错误码
/// @param errorInfo 错误描述
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine
       didOccurError:(MDRCameraErrorCode)errorCode
           errorInfo:(NSString *)errorInfo;

/// 引擎警告，此类回调不影响引擎的正常使用 （一般是业务端参数配置有问题、接口使用不当导致）
/// @param cameraEngine 引擎对象
/// @param errorCode 错误码
/// @param errorInfo 错误描述
- (void)cameraEngine:(MDRCameraEngine *)cameraEngine
     didOccurWarning:(MDRCameraWarningCode)warningCode
         warningInfo:(NSString *)warningInfo;

@end
