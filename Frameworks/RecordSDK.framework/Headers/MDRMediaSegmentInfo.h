//
//  MDRMediaSegmentInfo.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/28.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@interface MDRMediaSegmentInfo : NSObject

@property (nonatomic, assign) CMTimeScale timeScale;
/// 未变速时长
@property (nonatomic, assign) NSTimeInterval duration;
/// 变速因子
@property (nonatomic, assign) CGFloat speedVaryFactor;
/// duration * speedVaryFactor
@property (nonatomic, assign, readonly) NSTimeInterval presentDuration;
/// 媒体文件路径
@property (nonatomic, copy) NSURL *filePathURL;

@end

NS_ASSUME_NONNULL_END
