//
//  MDRecordPlayerViewController.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/10/12.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <MDProcessImageProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface MDRecordPlayerViewController : UIViewController

@property (nonatomic, readonly) AVPlayer *player;
@property (nonatomic, strong, nullable) id<MDProcessImageProtocol> filter;
@property (nonatomic, copy) AVLayerVideoGravity videoGravity;
@property (nonatomic, assign) NSInteger preferredFramesPerSecond;

@property (nonatomic,strong,nullable) NSOperationQueue *renderQueue;

- (CGRect)videoRenderFrame;

@end

NS_ASSUME_NONNULL_END
