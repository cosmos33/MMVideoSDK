//
//  MDRIRecordLogger.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/7/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MDRIRecordLogger <NSObject>

- (void)writeBody:(NSString *)body;
- (void)forceUploadMMFile;

- (void)enableLogger:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
