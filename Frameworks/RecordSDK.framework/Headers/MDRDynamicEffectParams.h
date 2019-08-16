//
//  MDRecordDynamicEffectParams.h
//  MDRecordAlbumPlayer
//
//  Created by sunfei on 2019/6/18.
//  Copyright © 2019 sunfei. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MDRAlbumVideoSoftDynamicEffectParams : NSObject

@property (nonatomic, copy, class, nonnull) NSURL *lookupImagePath;
@property (nonatomic, copy, class, nullable) NSURL *decorationPath;
@property (nonatomic, copy, class, nullable) NSURL *watermark;

@end

@interface MDRAlbumVideoFastDynamicEffectParams : NSObject

@property (nonatomic, copy, class, nullable) NSURL *decorationPath;
@property (nonatomic, copy, class, nullable) NSString *userID;
@property (nonatomic, copy, class, nullable) NSString *nickName;

@end

@interface MDRAlbumVideoShowDynamicEffectParams : NSObject

@property (nonatomic, copy, class, nonnull) NSURL *lookupImagePath1;
@property (nonatomic, copy, class, nonnull) NSURL *lookupImagePath2;
@property (nonatomic, copy, class, nonnull) NSURL *lookupImagePath3;

@end

NS_ASSUME_NONNULL_END
