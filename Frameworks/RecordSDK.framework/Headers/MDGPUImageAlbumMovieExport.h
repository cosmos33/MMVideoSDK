//
//  MDGPUImageAlbumMovie.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/26.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import Foundation;
@import MLMediaFoundation;
#import <CoreMedia/CoreMedia.h>
#import "MDAlbumPlayerTransitionAnimation.h"

@class MDGPUImageAlbumMovieExport, MDAlbumPlayer, MDPictureInputItem, MDAlbumMovieWriter, GPUImageOutput;

NS_ASSUME_NONNULL_BEGIN

@protocol MDGPUImageAlbumMovieExportDelegate <NSObject>

- (void)albumMovieDidFinishProcessing:(MDGPUImageAlbumMovieExport *)exporter;

@optional

- (void)albumMovieDidCancelProcessing:(MDGPUImageAlbumMovieExport *)exporter;

@end

@interface MDGPUImageAlbumMovieExport : NSObject

/** This specifies the progress of the process on a scale from 0 to 1.0. A value of 0 means the process has not yet begun, A value of 1.0 means the conversaion is complete.
 This property is not key-value observable.
 */
@property(readonly, nonatomic) float progress;

@property (nonatomic, readonly) MDAlbumPlayer *player;

@property (nonatomic, readonly) CGSize preferedSize;

@property (nonatomic, copy) NSURL *exportURL;

@property (nonatomic, strong) MDAlbumPlayerAnimationKey animationType;

/** This is used to send the delete Movie did complete playing alert
 */
@property (readwrite, nonatomic, assign, nullable) id <MDGPUImageAlbumMovieExportDelegate>delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithItems:(NSArray<MDPictureInputItem *> *)items
                   audioAsset:(AVAsset * _Nullable)asset;
- (instancetype)initWithItems:(NSArray<MDPictureInputItem *> *)items
                   audioAsset:(AVAsset * _Nullable)asset
                     audioMix:(AVAudioMix * _Nullable)audioMix;
- (instancetype)initWithItems:(NSArray<MDPictureInputItem *> *)items
                 sizeInPixels:(CGSize)sizeInPixels
                   audioAsset:(AVAsset * _Nullable)asset
                     audioMix:(AVAudioMix * _Nullable)audioMix NS_DESIGNATED_INITIALIZER;


- (void)exportVideo;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
