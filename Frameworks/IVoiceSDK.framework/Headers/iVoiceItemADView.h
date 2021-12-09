#import <UIKit/UIKit.h>
#import <iVoiceSDK/iVoiceDelegate.h>
#import <iVoiceSDK/iVoiceBarrageDelegate.h>

@class iVoiceADConfig;
@class iVoiceADView;
@class iVoiceADInfo;

typedef void (^iVoiceLoadStateBlock)(BOOL state);
typedef CGRect (^SetBarrageFrameBlock)(CGRect titleFrame, CGRect descFrame);

@interface iVoiceItemADView : UIView
@property(nonatomic, weak) id <iVoiceDelegate> delegate;

+ (instancetype)createWithAdid:(NSString *)adid;

//广告数据加载状态回调
@property(nonatomic, copy) iVoiceLoadStateBlock loadStateBlock;

//iVoice开始渲染
- (void)startRenderiVoice;

//iVoice展示广告
- (void)showiVoice;

//iVoice展示弹出广告
- (void)showPopulAdView;

//iVoice关闭广告
- (void)closeiVoice;

//锁屏展示iVoice
- (void)displayiVoiceOnLockScreen;

@end


