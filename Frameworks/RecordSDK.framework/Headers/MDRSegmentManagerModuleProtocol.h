//
//  MDRSegmentManagerModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/28.
//

#import <Foundation/Foundation.h>

@class MDRMediaSegmentInfo;
@protocol MDRSegmentManagerModuleProtocol;

NS_ASSUME_NONNULL_BEGIN

@protocol MDRSegmentManagerModuleDelegate <NSObject>

@optional
- (void)segmentManagerModule:(id<MDRSegmentManagerModuleProtocol>)module didChangeExportProgress:(CGFloat)progress;
- (void)segmentManagerModule:(id<MDRSegmentManagerModuleProtocol>)module
           didChangeSegments:(NSArray<MDRMediaSegmentInfo *> *)segments;

@end


@protocol MDRSegmentManagerModuleProtocol <NSObject>

/// 是否存在变速的片段
@property (nonatomic, assign, readonly) BOOL existSpeedVarySegment;
@property (nonatomic, strong, readonly) NSArray<MDRMediaSegmentInfo *> *segmentInfos;

- (void)bindDelegate:(id<MDRSegmentManagerModuleDelegate>)delegate;

/// 媒体片段合并导出回调
- (void)mergeAllSegmentsWithCompletionHandler:(void (^)(NSURL * _Nullable videoFileURL, NSError * _Nullable error))completionHandler;
/// 停止多段合并的导出
- (void)stopMergeAllSegments;

/// 追加片段
- (void)appendASegmentInfo:(MDRMediaSegmentInfo *)aSegmentInfo;

/// 删除最后一个片段
- (void)deleteLastSavedSegment;

/// 删除所有录制片段
- (void)deleteAllSegments;

/// 所有片段的总时长
- (NSTimeInterval)totalDurationOfAllSegments;
/// 所有片段变速后的总时长
- (NSTimeInterval)totalPresentDurationOfAllSegents;

/// 设置设备旋转方向
- (void)setDeviceOrientation:(UIDeviceOrientation)orientation;

@end

NS_ASSUME_NONNULL_END
