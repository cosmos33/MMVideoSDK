//
//  MDPhotoDetectorPipline.h
//  MDRecordSDK
//
//  Created by sunfei on 2018/11/28.
//

#import <Foundation/Foundation.h>
#import "MDImageDetectorProtocol.h"

NS_ASSUME_NONNULL_BEGIN


@interface MDPhotoDetectorPipline : NSObject <MDImageDetectorProtocol>

- (instancetype)init;

@property (nonatomic, assign) BOOL canUseBodyThinSetting;

@property (nonatomic, assign) CGSize outputImageSize;

@end

NS_ASSUME_NONNULL_END
