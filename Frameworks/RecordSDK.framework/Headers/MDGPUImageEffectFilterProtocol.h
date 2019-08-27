//
//  MDGPUImageEffectFilterProtocol.h
//  MomoChat
//
//  Created by sunfei on 2018/9/13.
//  Copyright © 2018 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MDGPUImageEffectFilterProtocol <NSObject>

- (instancetype)initWithImage:(UIImage *)image sizeInPixels:(CGSize)sizeInPixels;

@optional
@property (nonatomic, assign) BOOL isLastFilter;

@end
