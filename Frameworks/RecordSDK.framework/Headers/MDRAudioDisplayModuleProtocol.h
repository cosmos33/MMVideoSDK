//
//  MDRAudioDisplayModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/28.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef void(^AudioReadyToPlayBlock)(void);

NS_ASSUME_NONNULL_BEGIN

@protocol MDRAudioDisplayModuleProtocol <NSObject>

@property (nonatomic, assign, readonly) BOOL isReadyToPlay;

- (void)setupWithAudioAsset:(AVAsset *)asset;

/// 内部设置几个播放时间点的回调，目的是延迟视频的开始录制时间
/// @param block 在该block里开始视频的录制
- (void)setupTimeObserverWithReadyToPlayCallback:(AudioReadyToPlayBlock)block;

/// 音频播放seek
/// @param targetTime 需要seek的时间戳
- (void)seekToTime:(CMTime)targetTime;

/// 音频播放
- (void)playAudio;

/// 音频变速播放
/// @param factor 音频播放的速度
- (void)playAudioWithSpeedFactor:(CGFloat)factor;

/// 音频暂停
- (void)pauseAudio;

/// 音频停止
- (void)stopAudio;

@end

NS_ASSUME_NONNULL_END
