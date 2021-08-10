#import <UIKit/UIKit.h>
#import <iVoiceSDK/iVoiceDelegate.h>
#import <iVoiceSDK/iVoiceBarrageDelegate.h>

@class iVoiceADConfig;
@class iVoiceADView;
@class iVoiceADInfo;

typedef void (^iVoiceLoadStateBlock)(BOOL state);
typedef CGRect (^SetBarrageFrameBlock)(CGRect titleFrame, CGRect descFrame);

@interface iVoiceADView : UIView
@property(nonatomic, weak) id <iVoiceDelegate> delegate;
@property(nonatomic, weak) id <iVoiceBarrageDelegate> barrageDelegate;

+ (instancetype)create:(CGRect)frame
        adid:(NSString *)adid
        config:(iVoiceADConfig *)config;

//设置弹幕显示区域frame
@property(nonatomic, copy) SetBarrageFrameBlock barrageFrameBlock;
//广告数据加载状态回调
@property(nonatomic, copy) iVoiceLoadStateBlock loadStateBlock;

//iVoice开始渲染
- (void)startRenderiVoice;

//iVoice展示广告
- (void)showiVoice;

//iVoice关闭广告
- (void)closeiVoice;

//锁屏展示iVoice
- (void)displayiVoiceOnLockScreen;

@end


