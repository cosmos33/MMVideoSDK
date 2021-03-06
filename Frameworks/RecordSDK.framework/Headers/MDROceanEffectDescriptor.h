//
//  MDROceanEffectDescriptor.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/11/20.
//

#import <Foundation/Foundation.h>
#import "MDRMetalFilterDescriptor.h"

@class FDKBaseEffectItem;

NS_ASSUME_NONNULL_BEGIN

@interface MDROceanEffectDescriptor : NSObject <MDRMetalFilterDescriptor>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithEffectItem:(FDKBaseEffectItem *)item;

@property (nonatomic, readonly) NSURL *overlay;

@end

NS_ASSUME_NONNULL_END
