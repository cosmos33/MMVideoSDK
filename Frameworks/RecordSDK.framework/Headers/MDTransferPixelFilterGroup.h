//
//  MDTransferPixelFilterGroup.h
//  TestPicturePlayer
//
//  Created by sunfei on 2018/8/23.
//  Copyright © 2018 sunfei. All rights reserved.
//

@import GPUImage;

@interface MDTransferPixelFilterGroup : GPUImageFilterGroup

@property (nonatomic, copy) void(^processPixelBuffer)(CVPixelBufferRef pixelbuffer, CMTime frameTime, void(^callback)(CVPixelBufferRef processedPixelBuffer, NSError *error));
@property (nonatomic, copy) void(^endProcessing)(void);

@end
