//
//  MDRPixelBufferDisplayModuleProtocol.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
@import MLMediaFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol MDRPixelBufferDisplayModuleProtocol <NSObject>

@property (nonatomic, strong, readonly) UIView<MLPixelBufferDisplay> *pixelBufferDisplayView;
@property (nonatomic, assign, readonly) MLPixelBufferDisplayScalingMode scalingMode;

- (void)presentPixelBuffer:(CVPixelBufferRef)pixelBuffer
            finishCallback:(void(^ _Nullable )(NSError *_Nullable error))finishCallback;

@end

NS_ASSUME_NONNULL_END
