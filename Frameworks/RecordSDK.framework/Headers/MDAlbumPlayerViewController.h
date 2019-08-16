//
//  MDAlbumPlayerViewController.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/23.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import UIKit;
@import AVFoundation;
@import GPUImage;

@class MDAlbumPlayer, MDAlbumPlayerViewController, MDGPUImageAlbumMovieExport;

@protocol MDProcessImageProtocol;

NS_ASSUME_NONNULL_BEGIN

@protocol MDAlbumPlayerViewControllerDelegate

- (void)playCompleteWithPlayer:(MDAlbumPlayer * _Nonnull)player;

@end

@interface MDAlbumPlayerViewController : UIViewController

@property (nonatomic, strong, nonnull) NSArray<UIImage *> *images;                   // 影集素材

// 音频素材
@property (nonatomic, strong) AVAsset *audioAsset;
@property (nonatomic, strong) AVAudioMix *audioMix;

@property (nonatomic, weak, nullable) id<MDAlbumPlayerViewControllerDelegate> delegate;
// 外部滤镜
@property (nonatomic, strong, nullable) id<MDProcessImageProtocol> filterPlugin;
// 输出
@property (nonatomic, readonly, nonnull) GPUImageOutput<GPUImageInput> *output;

// associated with player
@property (nonatomic, assign) NSTimeInterval timeInverval;                  // 图片展示时长 default 4.0s
@property (nonatomic, assign) NSString *animationType;     // 动画类型, default MDAlbumPlayerAnimationTypeNone

// 显示布局 default AVLayerVideoGravityResizeAspect
@property (nonatomic, copy, nonnull) NSString *videoGravity;
// 当前展示时间
@property (nonatomic, readonly) CMTime presentationTime;
// 展示总时长
@property (nonatomic, readonly) NSTimeInterval duration;

// 帧率 default 30
@property (nonatomic, assign) NSInteger preferredFramesPerSecond;

@property (nonatomic, assign, getter=isPause) BOOL pause;
@property (nonatomic, assign) BOOL shouldRepeat;

- (void)play;
- (void)stop;

// 用于音频和视频不同步的情况，在大部分情况下不需要调用这个方法，这个方法用于背景音乐从网络下载，但是影集已经开始播放，这时候需要在音频下载完成以后对asset & audioMix赋值以后调用该方法进行音频播放
- (void)playAudio;

@property (nonatomic, assign) BOOL automaticallyPausePlaybackWhenViewDisappeared;  // Default YES

- (MDGPUImageAlbumMovieExport *)createAlbumMovieExport;

@end

NS_ASSUME_NONNULL_END
