//
//  MDRFiltersModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MDRRenderModuleProtocol.h"
#import "MDBBGPUImageSlidingFilter.h"

@class FDKDecoration;
@class MDRFaceDetectorInfo;
@class MDRGift;
@class MDRecordFilter;
@class FDKBeautySettings;
@class MDGPUImageMediaFiltersAttachment;

NS_ASSUME_NONNULL_BEGIN

@protocol MDRFiltersModuleProtocol <MDRRenderModuleProtocol>

// 滤镜
@property (nonatomic, copy) MDRecordFilter *slidingFilterA;   // 左滑滤镜
@property (nonatomic, copy) MDRecordFilter *slidingFilterB;   // 右滑滤镜
@property (nonatomic, assign) CGFloat slidingOffset;          // 滤镜切换进度
@property (nonatomic, assign) MDRGPUImageSlidingFilterMode mode; // 水平/垂直动画

// 道具
- (void)updateDecoration:(FDKDecoration * _Nullable)decoration;         // 更新道具
- (void)adjustVolumeOfCurrentDecoration:(CGFloat)volume;      // 调整贴纸音量
- (void)adjustBeautySetting:(FDKBeautySettings * _Nullable)beautySetting;  // 仅更新美颜效果

// 礼物贴纸
- (void)addGift:(MDRGift *)gift;
- (void)removeGift:(NSString *)giftID;
- (void)clearAllGifts;

// 清除缓存
- (void)cleanCache;

// 配置附加滤镜
- (void)configDecorationFilterAttachment:(MDGPUImageMediaFiltersAttachment *)filtersAttachment;

@end

NS_ASSUME_NONNULL_END
