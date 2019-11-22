//
//  MDRMetalEffectDispatcher.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/11/21.
//

#import <Foundation/Foundation.h>
#import "MDRMetalFilterDescriptor.h"

@class FDKBaseEffectItem;

NS_ASSUME_NONNULL_BEGIN

@interface MDRMetalEffectDispatcher : NSObject

+ (id<MDRMetalFilterDescriptor> _Nullable)effectDescriptorForItem:(FDKBaseEffectItem *)item;

@end

NS_ASSUME_NONNULL_END
