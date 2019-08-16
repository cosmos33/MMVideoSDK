//
//  MDGPUImagePicture.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/22.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

@interface MDGPUImagePicture : GPUImagePicture

- (void)processImageAtTime:(CMTime)time;
- (BOOL)processImageAtTime:(CMTime)time withCompletionHandler:(void(^)(void))completion;

@end
