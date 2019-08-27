//
//  MDAlbumPlayer.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/25.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import Foundation;
@import GPUImage;
@import AVFoundation;
@import MLGPUImageCVPixelBufferIO;
#import "MDGPUImagePicture.h"

@class MDPictureInputItem, MDAlbumPlayer;

NS_ASSUME_NONNULL_BEGIN

@protocol MDAlbumPlayerDelegate <NSObject>

- (void)playCompleteWithAlbumPlayer:(MDAlbumPlayer * _Nonnull)player;

@optional
- (BOOL)playerSetupSynchronizedPlay:(MDAlbumPlayer * _Nonnull)player;

@end

@interface MDAlbumPlayer : NSObject

@property (nonatomic, weak, nullable) id<MDAlbumPlayerDelegate> delegate;

@property (nonatomic, copy, nullable) NSString *animationType;     // 动画类型, default MDAlbumPlayerAnimationTypeNone

// 当前展示时间
@property (nonatomic, readonly) CMTime presentationTime;
// 展示总时长
@property (nonatomic, readonly) NSTimeInterval duration;

// 图片显示效果
@property (nonatomic, assign) GPUImageFillModeType fillMode;
// 帧率 default 30
@property (nonatomic, assign) NSInteger preferredFramesPerSecond;

// 输出分辨率, 需要考虑retina屏幕
@property (nonatomic, assign) CGSize sizeInPixels;
// 输出
@property (nonatomic, readonly, nonnull) GPUImageOutput<GPUImageInput> *output;

// 暂停播放
@property (nonatomic, assign, getter=isPause) BOOL pause;
// 重复播放
@property (nonatomic, assign) BOOL shouldRepeat;

// 音频
@property (nonatomic, strong, nullable) AVAsset *asset;
@property (nonatomic, strong, nullable) AVAudioMix *audioMix;

- (instancetype _Nonnull)initWithItems:(NSArray<MDPictureInputItem *> * _Nonnull)items;
- (instancetype _Nonnull)initWithItems:(NSArray<MDPictureInputItem *> * _Nonnull)items sizeInPixels:(CGSize)size;
- (void)play;
- (void)stop;

// 用于音频和视频不同步的情况，在大部分情况下不需要调用这个方法，这个方法用于背景音乐从网络下载，但是影集已经开始播放，这时候需要在音频下载完成以后对asset & audioMix赋值以后调用该方法进行音频播放
- (void)audioPlayOnly;

// 读取某一帧的内容
- (BOOL)readNextVideoFrame;
- (void)resetState;

@end

@interface MDPictureInputItem: NSObject

- (instancetype  _Nonnull)initWithImage:(UIImage * _Nonnull)image displayTimeRange:(CMTimeRange)range;
- (BOOL)canShowAtTime:(CMTime)time;

@property (nonatomic, readonly, nonnull) UIImage *image;
@property (nonatomic, readonly) CGSize sizeRelativeToScreen;
@property (nonatomic, assign) CMTimeRange timeRange;
@property (nonatomic, readonly, nonnull) MDGPUImagePicture *pictureInput;
@property (nonatomic, readonly) CMTime endTime;

+ (NSArray<MDPictureInputItem *> *)itemsForImages:(NSArray<UIImage *> *)images
                                     timeInterval:(NSTimeInterval)interval
                                        frameRate:(NSInteger)frameRate;

@end

NS_ASSUME_NONNULL_END
