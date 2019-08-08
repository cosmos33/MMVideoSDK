//
//  MMRecordLogger.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/7/4.
//

#import <Foundation/Foundation.h>
#import "MDRIRecordLogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface MMRecordLogger : NSObject <MDRIRecordLogger>

- (instancetype)initWithCachePath:(NSString *)cachePath;

@property (nonatomic, readonly) NSString *cachePath;

- (void)writeBody:(NSString *)body;
- (void)forceUploadMMFile;

- (void)enableLogger:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
