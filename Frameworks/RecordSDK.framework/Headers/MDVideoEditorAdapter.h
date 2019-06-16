//
//  MDVideoEditorAdapter.h
//  MDRecordSDK
//
//  Created by sunfei on 2019/2/27.
//  Copyright © 2019 sunfei. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import "MDRecordFilter.h"
#import "MDRSpecialFilterLifeStyleProtocol.h"
#import "MDCancellable.h"
#import "MDRecordDynamicSticker.h"
@import CXBeautyKit;

@class FDKDecoration, CXBeautyConfiguration, GPUImageOutput;
@protocol MLTimeRangeMappingEffect, GPUImageInput;

NS_ASSUME_NONNULL_BEGIN

@interface MDVideoEditorAdapter : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithToken:(NSString *)token;

// 加载视频
- (void)loadVideo:(AVAsset *)asset;
- (void)setVideoTimeRange:(CMTimeRange)timeRange;
- (void)setPitchShiftURL:(NSURL *)url;
- (void)setTimeRangeMappingEffects:(NSArray<id<MLTimeRangeMappingEffect>> *)timeRangeMappingEffects;
- (void)setMediaSourceRepeatRange:(CMTimeRange)timeRange;

@property (nonatomic, strong) NSURL *backgroundAudioURL;
@property (nonatomic, assign) CMTimeRange backgroundAudioRange;

- (void)setSourceVolume:(float)volume;
- (void)setBackgroundMusicVolume:(float)volume;

- (BOOL)compositeVideoWithError:(NSError **)error;
- (void)updateAudioMix;

// 播放器控制
- (void)play;
- (void)stop;
- (void)pause;
- (void)replay;

@property (nonatomic, readonly) UIViewController *playerViewController;
@property (nonatomic, readonly) AVPlayer *player;
@property (nonatomic, readonly) BOOL isPlaying;

- (void)seekTime:(CMTime)time;
- (NSTimeInterval)duration;
- (CMTime)getCurrentPlayTime;
- (void)setPlayerPerferredFPS:(int)fps;

@property (nonatomic, readonly) CGRect videoRenderFrame;
@property (nonatomic, readonly) AVComposition *composition;

- (void)waitUntilAllOperationsAreFinished;

@property (nonatomic, copy) void(^ _Nullable playToEndTime)(AVPlayer *player);
@property (nonatomic, copy) void(^ _Nullable playerPeriodicTimeCallback)(CMTime time);

@end

@interface MDVideoEditorAdapter (Beauty)

- (void)enableAIBeauty:(BOOL)enable;

- (void)setBeautyConfiguration:(CXBeautyConfiguration *)configuration;
- (void)setSkinWhitenValue:(float)value;
- (void)setSkinSmoothValue:(float)value;
- (void)setBeautyBigEyeValue:(float)value;
- (void)setBeautyThinFaceValue:(float)value;
- (void)setBeautyThinBodyValue:(float)value;
- (void)setBeautyLenghLegValue:(float)value;

@end

@interface MDVideoEditorAdapter (Filter)

- (void)configCurrentFilter:(MDRecordFilter *)filter;
- (void)configFilterA:(MDRecordFilter *)filterA configFilterB:(MDRecordFilter *)filterB offset:(float)offset;

@property (nonatomic, readonly) UIImage *mosaicCanvasImage;
- (void)setGraffitiCanvasImage:(UIImage * _Nullable)graffitiCanvasImage mosaicCanvasImage:(UIImage * _Nullable)mosaicCanvasImage;

- (void)setReverse:(BOOL)reverse;
- (void)addSpecialFilter:(GPUImageOutput<GPUImageInput, MDRSpecialFilterLifeStyleProtocol> *)newTarget timeRange:(CMTimeRange)range;
- (void)deleteLastSpecialFilter;
- (void)deleteAllSpecialFilters;
- (void)updateCurrentFilterWithTime:(CMTime)time timeRange:(CMTimeRange)timeRange;
- (NSArray<GPUImageOutput<GPUImageInput, MDRSpecialFilterLifeStyleProtocol> *> *)specialFilters;
- (BOOL)hasSpecialFilter;

- (void)addDynamicSticker:(MDRecordDynamicSticker *)dynamicSticker;
- (void)removeDynamicSticker:(MDRecordDynamicSticker *)dynamicSticker;

- (void)updateDecoration:(FDKDecoration *)decoration;
- (void)removeDecoration;

// add custom filter
- (void)addCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;
- (void)removeCustomFilter:(GPUImageOutput<GPUImageInput> *)filter;

@end

@interface MDVideoEditorAdapter (Export)

@property (nonatomic, strong) UIImage * _Nullable overlayImage;

@property (nonatomic, assign) float targetBitRate;
@property (nonatomic, assign) CGSize presentationSize;
@property (nonatomic, assign) NSInteger targetFrameRate;
@property (nonatomic, assign) CGAffineTransform videoPerferredTransform;

- (void)enableFilterEffect:(BOOL)enable;

- (id<MDCancellable>)exportToURL:(NSURL *)url
                 progressHandler:(void(^ _Nullable)(double progress))progressHandler
                      completion:(void(^ _Nullable)(NSURL *url))completion
                         failure:(void(^ _Nullable)(NSError * _Nullable error))failure;

@end

@interface MDVideoEditorAdapter (MDRMakeUp)

/**
 启用美妆功能
 
 @param enable YES启用，NO禁用
 */
- (void)enableMakeup:(BOOL)enable;

/**
 增加美妆效果
 
 @param resouceURL 资源文件路径
 @return 该效果identifier
 */
- (NSString *)addMakeUpEffectWithResourceURL:(NSURL *)resouceURL;

/**
 根据identifier移除美妆效果
 
 @param identifiter 要移除的美妆效果的identifier
 */
- (void)removeMakeUpEffectWithIdentifier:(NSString *)identifiter;

/**
 移除所有的美妆效果
 */
- (void)removeAllMakeUpEffect;

/**
 调整美妆效果程度
 
 @param intensity 程度(0-1)
 @param identifier 美妆效果
 */
- (void)setIntensity:(CGFloat)intensity forIdentifiler:(NSString *)identifier;

@end

@interface MDVideoEditorAdapter (MDRBackgroundBlur)

/**
 是否启用背景模糊
 
 @param enable YES启用，NO禁用
 */
- (void)enableBackgroundBlur:(BOOL)enable;

/**
 设置背景模糊效果
 
 @param mode 背景模糊样式
 */
- (void)setBackgroundBlurMode:(CXBackgroundBlurMode)mode;

// 背景模糊程度(0-1)
- (void)setBackgroundBlurIntensity:(CGFloat)intensity;

@end

NS_ASSUME_NONNULL_END
