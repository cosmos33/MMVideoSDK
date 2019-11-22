//
//  MDRMetalFilterDescriptor.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/11/20.
//

#import <MetalPetal/MetalPetal.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MDRMetalFilterDescriptor <NSCopying>

@property (nonatomic, copy) NSString *identifier;

- (id<MTIUnaryFilter> _Nullable)createFilter;

@end

NS_ASSUME_NONNULL_END
