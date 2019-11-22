//
//  MDRGhsotEffectDescriptor.h
//  MMVideoSDK
//
//  Created by sunfei on 2019/11/20.
//

#import <Foundation/Foundation.h>
#import "MDRMetalFilterDescriptor.h"
#import "MDREffectFilters/MTRGhostEffectFilter.h"

@class FDKBaseEffectItem;

NS_ASSUME_NONNULL_BEGIN

@interface MDRGhostEffectDescriptor : NSObject <MDRMetalFilterDescriptor>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithEffectItem:(FDKBaseEffectItem *)item;

@property (nonatomic, readonly) MTRGhostEffectFilterType type;

@property (nonatomic, readonly) NSURL *colorOverlay0;
@property (nonatomic, readonly) NSURL *colorOverlay1;
@property (nonatomic, readonly) NSURL *colorOverlay2;

@property (nonatomic, readonly) NSURL *vertOverlay0;
@property (nonatomic, readonly) NSURL *vertOverlay1;
@property (nonatomic, readonly) NSURL *vertOverlay2;

@property (nonatomic, readonly) NSURL *circleMask0;
@property (nonatomic, readonly) NSURL *circleMask1;
@property (nonatomic, readonly) NSURL *circleMask2;
@property (nonatomic, readonly) NSURL *circleMask3;

@property (nonatomic, readonly) NSURL *vertMask;

@property (nonatomic, readonly) NSURL *lookup0;
@property (nonatomic, readonly) NSURL *lookup1;
@property (nonatomic, readonly) NSURL *lookup2;

@end

NS_ASSUME_NONNULL_END
