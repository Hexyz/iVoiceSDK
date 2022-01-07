#import <IVoiceSDK/IVoiceDelegate.h>
#import <UIKit/UIKit.h>
#import "IVoiceADInfo.h"

@class IVoiceADConfig;
@class IVoiceMeidaView;
@class IVoiceADInfoIVoiceADInfo;

// state：广告是否加载成功，title：广告标题
typedef void (^IVoiceLoadStateBlock)(BOOL state, NSString *title);

@interface IVoiceMeidaView : UIView
// 封面图
@property(nonatomic, strong) UIImageView *coverImageView;
// 广告标识
@property(nonatomic, strong) UILabel *adLabel;
// 跳过按钮
@property(nonatomic, strong) UIButton *skipButton;
// 标题
@property(nonatomic, strong) UILabel *titleLabel;
// 描述
@property(nonatomic, strong) UILabel *summaryLabel;
// logo图
@property(nonatomic, strong) UIImageView *logoImageView;
// 动作按钮（打开详情）
@property(nonatomic, strong) UIButton *actionButton;

@property(nonatomic, weak) id<IVoiceDelegate> delegate;

/**
 - 示倒计时倒计时（仅有倒计时，无法跳过）style：[sss ]
 - 展示倒计时+跳过 style：[sss | 跳过]
 - 控件需保留宽度至少70pt，高 13pt
  是否展示倒计时控件控制
  默认 NO 不显示
 */
@property(nonatomic, assign) BOOL isShowCountDown;

/**
     label：
    iVoice的sdk需要让媒体方在sdk方法中提交用户在广告请求前所听过的最近5～10条组信息，信息字段包含：标题（专辑／歌曲名称+作者+歌手等英文逗号分隔）、音频文件url、结束播放时的进度百分比
    调用者 需要传入 请求广告前 自己APP内的
   最近5～10条组信息，信息字段包含：标题（专辑／歌曲名称+作者+歌手等英文逗号分隔）、音频文件url、结束播放时的进度百分比
    如果没有可传 nil
 */
+ (instancetype)create:(CGRect)frame adid:(NSString *)adid label:(NSArray<IVoiceADInfo *> *)label;

//广告数据加载状态回调
@property(nonatomic, copy) IVoiceLoadStateBlock loadStateBlock;

// iVoice展示广告
- (void)showiVoice;

// iVoice关闭广告
- (void)closeiVoice;

@end
