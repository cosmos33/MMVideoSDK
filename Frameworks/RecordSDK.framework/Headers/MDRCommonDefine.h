//
//  MDRCommonDefine.h
//  MMVideoSDK
//
//  Created by 符吉胜 on 2019/10/25.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MDRCameraErrorCode) {
    MDRCameraErrorCode_NoError = 0,
    MDRCameraErrorCode_CameraRunningFail, //camera运行失败
    MDRCameraErrorCode_CameraDeviceNotWorking, //camera设备不可用
    MDRCameraErrorCode_RenderPixelBufferFail, //pixelBuffer渲染处理出错
    MDRCameraErrorCode_DisplayPixelbufferFail, //pixelBuffer显示到画布出错
};

typedef NS_ENUM(NSInteger, MDRCameraWarningCode) {
    MDRCameraWarningCode_NoWarning = 0,
    MDRCameraWarningCode_EngineStateWrong, //引擎状态不对 EX：在录制过程中调用开始预览会触发
    MDRCameraWarningCode_CaptureResolutionNotSuitable, //录制分辨率设置过大，SDK内部会默认降分辨率
    MDRCameraWarningCode_CameraDeviceConfigureFail, //设备配置出错
    MDRCameraWarningCode_RecordingFail, //录制失败
    MDRCameraWarningCode_VideoExportNotWorking, //录制失败
};

typedef NS_ENUM(NSInteger, MDRCaptureResolutionType) {
    MDRCaptureResolutionType_480P,
    MDRCaptureResolutionType_540P,
    MDRCaptureResolutionType_720P,
    MDRCaptureResolutionType_1080P
};

typedef NS_ENUM(NSInteger, MDRCompileResolutionType) {
    MDRCompileResolutionType_480P,
    MDRCompileResolutionType_540P,
    MDRCompileResolutionType_720P,
    MDRCompileResolutionType_1080P
};

typedef NS_ENUM(NSInteger, MDRCaptureFlagOption) {
    MDRCaptureFlagOption_None = 0,
    MDRCaptureFlagOption_DisableAudio = 1 << 0, //不采集音频
};

typedef NS_ENUM(NSInteger, MDRRecordingFlagOption) {
    MDRRecordingFlagOption_None = 0,
    MDRRecordingFlagOption_DisableAudio = 1 << 0,     //不编码音频 （SDK内部会和MDRCaptureFlagOption_DisableAudio同步）
    MDRRecordingFlagOption_ReverseVideo = 1 << 1,     //水平镜像输出
    MDRRecordingFlagOption_DisableAllEffects = 1 << 2, //屏蔽所有动效
};

typedef NS_ENUM(NSInteger, MDRCaptureDeviceType) {
    MDRCaptureDeviceType_Front  = 0,
    MDRCaptureDeviceType_Back = 1,
};

typedef NS_ENUM(NSUInteger, MDRecordCameraSourceType)
{
    MDRecordCameraSourceType_captureSession,    //普通拍摄
    MDRecordCameraSourceType_ARKIT              //AR拍摄
};

typedef NS_ENUM(NSInteger, MDRCameraEngineState) {
    MDRCameraEngineState_Stop,      //引擎停止
    MDRCameraEngineState_Preview,   //预览中
    MDRCameraEngineState_Recording, //录制中
    MDRCameraEngineState_Exporting,   //片段合成中
};

//音频采样精度
typedef NS_ENUM(NSInteger, MDRAudioSampleFormatType) {
    MDRAudioSampleFormatType_None,
    MDRAudioSampleFormatType_U8,
    MDRAudioSampleFormatType_S16,
    MDRAudioSampleFormatType_S32
};

typedef NS_ENUM(NSInteger, MDRVideoEncodeType) {
    MDRVideoEncodeType_None,
    MDRVideoEncodeType_H264,
    MDRVideoEncodeType_H265
};

typedef NS_ENUM(NSInteger, MDRAudioEncodeType) {
    MDRAudioEncodeType_None,
    MDRAudioEncodeType_AAC
};

typedef NS_ENUM(NSInteger, MDRVideoEncodeScaleMode) {
    MDRVideoEncodeScaleMode_Fit,                //保持比例，缩长边
    MDRVideoEncodeScaleMode_Resize,             //忽视比例，填满区域
    MDRVideoEncodeScaleMode_ResizeAspect,       //保持比例，缩长边，以黑边填补空白地方
    MDRVideoEncodeScaleMode_ResizeAspectFill    //保持比例，等比放大短边，图片会被裁剪
};

typedef NS_ENUM(NSInteger, MDRSegmentGenerateFailType) {
    MDRSegmentGenerateFailType_Unknow,
    MDRSegmentGenerateFailType_RecodingDuration2Short   //录制时长少于单段录制的最短时长segmentMinDuration
};

typedef NS_ENUM(NSUInteger, MDRecordCaptureFlashMode) {
    MDRecordCaptureFlashModeOff   = 0,
    MDRecordCaptureFlashModeOn    = 1,
    MDRecordCaptureFlashModeAuto  = 2,
};


typedef struct {
    int num;    //分子
    int den;    //分母
} MDRRatio;
extern const MDRRatio MDRRatioZero;
NS_INLINE MDRRatio MDRRatioMake(int num, int den)
{
    MDRRatio ratio; ratio.num = num; ratio.den = den; return ratio;
}
NS_INLINE BOOL MDRRatioEqualToRatio(MDRRatio ratio1, MDRRatio ratio2)
{
    return ratio1.num == ratio2.num && ratio1.den == ratio2.den;
}


typedef struct {
    unsigned int imageWidth;
    unsigned int imageHeigth;
} MDRVideoResolution;

typedef struct {
    double sampleRate;
    MDRAudioSampleFormatType sampleFormat;
    unsigned int channelCount;
} MDRAudioResolution;


typedef NSString * MDRVideoEncodeAttributeKey NS_STRING_ENUM;
extern MDRVideoEncodeAttributeKey const MDRVideoEncodeBitRateKey;   //视频编码码率，单位bit， EX：1000000
extern MDRVideoEncodeAttributeKey const MDRVideoEncodeScaleModeKey; //视频缩放模式，EX：MDRVideoEncodeScaleMode_Fit
extern MDRVideoEncodeAttributeKey const MDRVideoEncodeResolutionKey;//视频编码分辨率 EX: MDRVideoResolution {720, 1280}
extern MDRVideoEncodeAttributeKey const MDRVideoEncodeFrameRateKey; //视频编码帧率 EX: 30

typedef NSString * MDRAudioEncodeAttributeKey NS_STRING_ENUM;
extern MDRAudioEncodeAttributeKey const MDRAudioEncodeBitRateKey;   //音频编码码率，单位bit， EX：128000
extern MDRAudioEncodeAttributeKey const MDRAudioEncodeSampleRate;   //音频采样频率，单位HZ， EX：44100

