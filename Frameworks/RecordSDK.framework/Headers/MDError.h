//
//  MDError.h
//  MDRecordSDK
//
//  Created by sunfei on 2018/12/17.
//  Copyright © 2018 sunfei. All rights reserved.
//

#ifndef MDError_h
#define MDError_h

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSErrorDomain const MDRAuthenticationErrorDomain;
FOUNDATION_EXPORT NSErrorDomain const MDRImageProcessErrorDomain;
FOUNDATION_EXPORT NSErrorDomain const MDRVideoProcessErrorDomain;
FOUNDATION_EXPORT NSErrorDomain const MDRRecordingErrorDomain;

FOUNDATION_EXPORT NSErrorUserInfoKey const MDRVideoProcessExportSessionInitializeFailedErrorKey;

typedef NS_ERROR_ENUM(MDRAuthenticationErrorDomain, MDRAutorizationError) {
    MDRAutorizationErrorAlbumDenied = -200,
    MDRAutorizationErrorCameraDenied = -201,
};

typedef NS_ERROR_ENUM(MDRImageProcessErrorDomain, MDRImageProcessError) {
    MDRImageProcessErrorUnknown = -301,
    
    MDRImageProcessErrorRenderFrameError = -350
};

typedef NS_ERROR_ENUM(MDRVideoProcessErrorDomain, MDRVideoProcessError) {
    MDRVideoProcessErrorUnknown = -401,
    
    MDRVideoProcessErrorExportSessionUnknown = -402,
    MDRVideoProcessErrorExportSessionInitializeFailed = -403,
    MDRVideoProcessErrorExportSessionCancelled = -404,
    
    MDRVideoProcessErrorPrepare = 205001,
    MDRVideoProcessErrorMakeVideo,
    MDRVideoProcessErrorPreview,
    MDRVideoProcessErrorMixAudioInit,
    MDRVideoProcessErrorVoiceChangeInit,
    MDRVideoProcessErrorVoiceChange,
    
    MDRVideoProcessErrorDecodeAudioInitMuxer = 209001,
    MDRVideoProcessErrorDecodeVideoInitMuxer,
    MDRVideoProcessErrorDecodeAudioCodec,
    MDRVideoProcessErrorDecodeVideoCodec,
    MDRVideoProcessErrorDecodeAudio,
    MDRVideoProcessErrorDecodeVideo,
    
    MDRVideoProcessErrorBgMixInit = 208001,
    MDRVideoProcessErrorBgMixSetOutPath,
    MDRVideoProcessErrorBgMixInitVideoSource,
    MDRVideoProcessErrorBgMixInitAudioSource,
    MDRVideoProcessErrorBgMixRunning,
    
    MDRVideoProcessErrorAudioPlayerPrepare = 206001,
    MDRVideoProcessErrorAudioPlayerResume,
    MDRVideoProcessErrorAudioPlayerRelease,
    MDRVideoProcessErrorAudioPlayerRunning,
    
    MDRVideoProcessErrorRenderAddTarget = 207001,
    MDRVideoProcessErrorRenderFrameError
};

typedef NS_ERROR_ENUM(MDRRecordingErrorDomain, MDRRecordingError) {
    MDRRecordingErrorUnknown = 100001,
    
    MDRRecordingErrorRenderFrameError = 100002,
    
    MDRRecordingErrorStatusError = 101001,
    MDRRecordingErrorCancel,
    MDRRecordingErrorSplice,
    MDRRecordingErrorFilePathEmpty,
    MDRRecordingErrorSpliceInit,
    MDRRecordingErrorSpliceRunning,
    MDRRecordingErrorSpliceRelease,
    MDRRecordingErrorSaveFragment,
    MDRRecordingErrorSelectResolution,
    MDRRecordingErrorLoadFaceDetector,
    MDRRecordingErrorLoadGestureDetector,
    MDRRecordingErrorLoadHandGestureDetector,
    MDRRecordingErrorLoadSegmentDetector,
    MDRRecordingErrorLoadBodylandDetector,
    MDRRecordingErrorLoadBarnessDetector,
    MDRRecordingErrorLoadDataRecyleDetector,
    MDRRecordingErrorEncoderInit,
    MDRRecordingErrorGetAudioStatus,
    MDRRecordingErrorResetCamera,
    
    MDRRecordingErrorAudioRecordOpen = 102001,
    MDRRecordingErrorAudioStartEncode,
    MDRRecordingErrorAudioStopEncode,
    MDRRecordingErrorAudioEncoding,
    
    MDRRecordingErrorAudioParameter = 103001,
    MDRRecordingErrorVideoParameter,
    MDRRecordingErrorMuxerCreate,
    MDRRecordingErrorVideoCodecCreate,
    MDRRecordingErrorAudioCodecCreate,
    MDRRecordingErrorVideoCodecStatus,
    MDRRecordingErrorAudioCodecStatus,
    MDRRecordingErrorStopEncode,
    MDRRecordingErrorEncodingRunning,
    MDRRecordingErrorSetParamsException,
    
    MDRRecordingErrorCameraPrepare = 104001,
    MDRRecordingErrorCameraStartPreview,
    MDRRecordingErrorCameraStopPreview,
    MDRRecordingErrorCameraOpen,
    MDRRecordingErrorCameraConfig,
    MDRRecordingErrorCameraSelectColorFormat,
    MDRRecordingErrorCameraGetStatus,
    MDRRecordingErrorCameraSwitch,
    MDRRecordingErrorCameraTakePhoto
};

#endif /* MDError_h */

