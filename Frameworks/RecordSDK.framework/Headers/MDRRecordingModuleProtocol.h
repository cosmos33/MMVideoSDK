//
//  MDRRecordingModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^FinishRecordingCallback)(NSURL * _Nullable filePath, CMTime segmentDuration, NSError  * _Nullable error);

@class MDRCaptureRecordingConfig;
@protocol MDRRecordingModuleProtocol;

@protocol MDRRecordingModuleDelegate <NSObject>

@optional
- (void)recordingModule:(id<MDRRecordingModuleProtocol>)recordingModule didChangeSegmentDuration:(CMTime)segmentDuration;
- (void)recordingModule:(id<MDRRecordingModuleProtocol>)recordingModule
didOutputASegmentFilePath:(NSURL *)filePath
          segmentDuration:(CMTime)segmentDuration;

@end


@protocol MDRRecordingModuleProtocol <NSObject>

@property (nonatomic, assign, readonly) NSTimeInterval currentSegmentDuration;

- (void)bindDelegate:(id<MDRRecordingModuleDelegate> _Nullable)delegate;

- (BOOL)startRecordingWithConfig:(MDRCaptureRecordingConfig *)config;

- (void)appendVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (void)appendAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)finishRecording:(FinishRecordingCallback _Nullable)completionBlock;

- (void)cancelRecording;

//TODO:临时这么处理，后期需要优化 （@符吉胜）
- (void)setLastVideoPresentTime:(CMTime)time;
- (void)setLastAudioPresentTime:(CMTime)time;

@end

NS_ASSUME_NONNULL_END
