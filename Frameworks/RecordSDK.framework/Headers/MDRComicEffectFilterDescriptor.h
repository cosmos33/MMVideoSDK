//
//  MDRComicEffectFilterDescriptor.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/11/20.
//

#import <Foundation/Foundation.h>
#import "MDRMetalFilterDescriptor.h"

@class FDKBaseEffectItem;

typedef NS_ENUM(NSUInteger, MDRComicEffectFilterType) {
	MDRComicEffectFilterTypeComic,
	MDRComicEffectFilterInk,
	MDRComicEffectFilterSketch,
};

NS_ASSUME_NONNULL_BEGIN

@interface MDRComicEffectFilterDescriptor : NSObject <MDRMetalFilterDescriptor>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithEffectItem:(FDKBaseEffectItem *)item;

@property (nonatomic, readonly) NSURL *lookupPath;
@property (nonatomic, readonly) MDRComicEffectFilterType type;

@end

NS_ASSUME_NONNULL_END
