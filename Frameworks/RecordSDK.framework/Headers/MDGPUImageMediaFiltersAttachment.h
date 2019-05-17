//
//  MDGPUImageMediaFiltersAttachment.h
//  MMVideoSDK
//
//  Created by wuzhijia on 2019/5/16.
//

#import <Foundation/Foundation.h>
@import GPUImage;

NS_ASSUME_NONNULL_BEGIN

@interface MDGPUImageMediaFiltersAttachment : NSObject

@property (nonatomic, strong) GPUImageOutput <GPUImageInput> * piplineInputFilter;      // first filter of the pipline.
@property (nonatomic, strong) GPUImageOutput <GPUImageInput> * piplineOutputFilter;     // last filter of the pipline.
@property (nonatomic, strong) GPUImageOutput <GPUImageInput> * slidingFinishedFilter;   // filter behind sliding filters and before beauty filters.
@property (nonatomic, strong) GPUImageOutput <GPUImageInput> * beautyFinishedFilter;    // filter behind sliding filters and before sticker filters

@end

NS_ASSUME_NONNULL_END
