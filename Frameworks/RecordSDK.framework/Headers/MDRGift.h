//
//  MDRGift.h
//  CXBeautyKit
//
//  Created by sunfei on 2019/6/26.
//

#import <Foundation/Foundation.h>
#import "MDRDetectorRequirements.h"

@class FDKDecorationFilter;

NS_ASSUME_NONNULL_BEGIN

@interface MDRGift : NSObject <MDRDetectorRequirements>

- (instancetype)initWithResourceURL:(NSURL *)resourceURL;
- (instancetype)initWithResourceURL:(NSURL *)resourceURL duration:(NSTimeInterval)duration;

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) NSURL *resourceURL;

@property (nonatomic, readonly) FDKDecorationFilter *decorationFilter;

@end

NS_ASSUME_NONNULL_END
