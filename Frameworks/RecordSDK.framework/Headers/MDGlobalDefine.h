//
//  MDGlobalDefine.h
//  MMVideoSDK
//
//  Created by wuzhijia on 2019/5/16.
//

#ifndef MDGlobalDefine_h
#define MDGlobalDefine_h

#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>

@class MMFaceFeature, MMBodyFeature;

typedef void(^MDVideoDetectorBlock)(CVPixelBufferRef pixelbuffer, NSArray<MMFaceFeature *> *faceFeatures, NSArray<MMBodyFeature *> *bodyFeatures) ;


#endif /* MDGlobalDefine_h */
