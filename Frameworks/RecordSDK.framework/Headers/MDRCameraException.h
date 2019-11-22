//
//  MDRCameraException.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/11/6.
//

#import <Foundation/Foundation.h>
#import "MDRCommonDefine.h"

@class MDRCameraEngine;

NS_ASSUME_NONNULL_BEGIN

@protocol MDRCameraExceptionDelegate <NSObject>

- (void)cameraDidOccurError:(MDRCameraErrorCode)errorCode errorInfo:(NSString *)errorInfo;
- (void)cameraDidOccurWarning:(MDRCameraWarningCode)warningCode warningInfo:(NSString *)warningInfo;

@end


@interface MDRCameraException : NSObject

+ (void)addErrorReportor:(id<MDRCameraExceptionDelegate>)errorReportor;
+ (void)removeErrorReportor;

//系统错误
+ (void)reportError:(NSError *)error errorCode:(MDRCameraErrorCode)errorCode;
//自定义错误
+ (void)reportErrorWithCode:(MDRCameraErrorCode)errorCode errorInfo:(NSString *)errorInfo;
//警告
+ (void)reportWarningWithCode:(MDRCameraWarningCode)warningCode
                  warningInfo:(NSString *)warningInfo
                uploadService:(BOOL)uploadService;

@end

NS_ASSUME_NONNULL_END
