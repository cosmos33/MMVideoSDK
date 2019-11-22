//
//  MDRRenderModule.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>
#import "MDRRenderModuleProtocol.h"
#import "MDRFiltersModuleProtocol.h"
#import "MDRXEngineModuleProtocol.h"
#import "MDRMetalModuleProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface MDRRenderModule : NSObject<MDRRenderModuleProtocol, MDRRenderModuleInput, MDRMetalModuleProtocol, MDRFiltersModuleProtocol, MDRXEngineModuleProtocol>

@end

NS_ASSUME_NONNULL_END
