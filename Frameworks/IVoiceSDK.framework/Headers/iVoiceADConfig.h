#import <UIKit/UIKit.h>
@class iVoiceADInfo;

typedef struct {
	CGFloat top;//上边距
	CGFloat left;//左边距
	CGFloat right;//右边距
}iVoiceMargin;

static inline iVoiceMargin make (CGFloat top,CGFloat left, CGFloat right) {
	iVoiceMargin magin;
	magin.top = top;
	magin.left = left;
	magin.right = right;
	return magin;
}

@interface iVoiceADConfig : NSObject

// MARK: - 广告视图整体高度
@property(nonatomic, assign) CGSize iVoiceADViewSize;

// MARK: - AD标题
//标题距离整个广告 左 右 上 边距
@property(nonatomic, assign) iVoiceMargin ADTitleMargin;
//标题字体
@property(nonatomic, strong) UIFont *ADTitleFont;
//标题字体颜色
@property(nonatomic, strong) UIColor *ADTitleTextColor;
//标题最多行数，默认1行
@property(nonatomic, assign) NSInteger ADTitleNumberOfLines;

// MARK: - AD 描述
//描述距离标题上边距和整个广告 左 右 边距
@property(nonatomic, assign) iVoiceMargin ADDetailMargin;
//描述字体尺寸
@property(nonatomic, strong) UIFont *ADDetailFont;
//描述字体颜色
@property(nonatomic, strong) UIColor *ADDetailTextColor;
//标题最多行数，默认1行
@property(nonatomic, assign) NSInteger ADDetailNumberOfLines;

// MARK: - 标题
//标题距离整个广告 左 右 上 边距
@property(nonatomic, assign) iVoiceMargin widgeTitleMargin;
//标题字体
@property(nonatomic, strong) UIFont *widgeTitleFont;
//标题字体颜色
@property(nonatomic, strong) UIColor *widgeTitleTextColor;

// MARK: - 描述
//描述距离标题上边距和整个广告 左 右 边距
@property(nonatomic, assign) iVoiceMargin widgetSummaryMargin;
//描述字体尺寸
@property(nonatomic, strong) UIFont *widgetSummaryFont;
//描述字体颜色
@property(nonatomic, strong) UIColor *widgetSummaryTextColor;

// MARK: - Tip广告
//Tip广告的位置
@property(nonatomic, assign) CGPoint tipViewOrigin;
//Tip广告的尺寸（只读，不用设置）
@property(nonatomic, assign) CGSize tipViewSize;
//Tip广告的背景圆角
@property(nonatomic, assign) CGFloat tipViewRadius;
//Tip广告的背景颜色
@property(nonatomic, strong) UIColor *tipViewBackgroundColor;
//Tip广告的背景阴影颜色
@property(nonatomic, strong) UIColor *tipViewShadowColor;
//Tip广告的背景阴影偏移量
@property(nonatomic, assign) CGSize tipViewShadowOffset;
//Tip广告的背景阴影圆角
@property(nonatomic, assign) CGFloat tipViewShadowRadius;
//Tip广告的头像控件位置和尺寸
@property(nonatomic, assign) CGRect tipViewHeaderViewFrame;
//Tip广告的头像控件圆角
@property(nonatomic, assign) CGFloat tipViewHeaderViewRadius;
//Tip广告的标题控件位置和尺寸
@property(nonatomic, assign) CGRect tipViewTitleLabelFrame;
//Tip广告的标题控件字体大小
@property(nonatomic, strong) UIFont *tipViewTitleLabelFont;
//Tip广告的标题控件字体颜色
@property(nonatomic, strong) UIColor *tipViewTitleLabelTextColor;
//Tip广告的描述控件位置和尺寸
@property(nonatomic, assign) CGRect tipViewDescLabelFrame;
//Tip广告的描述控件字体
@property(nonatomic, strong) UIFont *tipViewDescLabelFont;
//Tip广告的描述控件字体颜色
@property(nonatomic, strong) UIColor *tipViewDescLabelTextColor;
//Tip广告的下载按钮控件位置和尺寸
@property(nonatomic, assign) CGRect tipViewDoneButtonFrame;
//Tip广告的位置下载按钮背景颜色
@property(nonatomic, strong) UIColor *tipViewDoneButtonBackgroundColor;
//Tip广告的下载按钮控件圆角
@property(nonatomic, assign) CGFloat tipViewDoneButtonRadius;
//Tip广告的下载按钮字体大小
@property(nonatomic, strong) UIFont *tipViewDoneButtonFont;
//Tip广告的下载按钮控件字体颜色
@property(nonatomic, strong) UIColor *tipViewDoneButtonTextColor;
//Tip广告的关闭按钮控件位置和尺寸
@property(nonatomic, assign) CGRect tipViewCloseButtonFrame;

// MARK: - 自定义按钮
//用户头像控件位置和尺寸
@property(nonatomic, assign) CGRect avatarButtonFrame;
//用户头像控件位置和尺寸
@property(nonatomic, assign) CGFloat avatarButtonCornerRadius;
//是否隐藏🔗链接图标
@property(nonatomic, assign) BOOL avatarHiddenLink;

//点在控件位置和尺寸
@property(nonatomic, assign) CGRect loveButtonFrame;

//点赞数量控件位置和尺寸
@property(nonatomic, assign) CGRect loveLabelFrame;
//点赞数量控件字体大小
@property(nonatomic, strong) UIFont *loveLabelFont;
//点赞数量控件字体颜色
@property(nonatomic, strong) UIColor *loveLabelTextColor;

// MARK: - 封面
//背景图片位置和尺寸
@property(nonatomic, assign) CGRect bgImageViewFrame;
//背景图片圆角（默认0）
@property(nonatomic, assign) CGFloat bgImageViewCornerRadius;
//封面图片位置和尺寸
@property(nonatomic, assign) CGRect coverImageViewFrame;
//封面图片圆角（默认0）
@property(nonatomic, assign) CGFloat coverImageViewCornerRadius;
//播放按钮是否隐藏（默认显示）
@property(nonatomic, assign) BOOL playButtonHidden;
//播放按钮位置和尺寸
@property(nonatomic, assign) CGRect playButtonFrame;
// MARK: - 发送弹幕弹框
//是否展示弹幕
@property(nonatomic, assign) BOOL isShowBarrage;
//点击弹幕时 是否展示用户头像
@property(nonatomic, assign) BOOL isShowBarrageIcon;
//弹幕头像尺寸
@property(nonatomic, assign) CGSize barrageIconSize;
//弹幕内容字体大小
@property(nonatomic, strong) UIFont *barrageTitleFont;
//弹幕内容字体颜色
@property(nonatomic, strong) NSArray<UIColor *> *barrageTitleColors;
//弹幕内容背景颜色
@property(nonatomic, strong) UIColor *barrageBgColor;
//弹幕滚动速度
@property(nonatomic, assign) CGFloat BarrageAnimationDuration;
//发送弹幕按钮控件位置和尺寸
@property(nonatomic, assign) CGRect barrageBtnFrame;
//弹幕数量控件位置和尺寸
@property(nonatomic, assign) CGRect barrageLabelFrame;
//弹幕数量控件字体大小
@property(nonatomic, strong) UIFont *barrageLabelFont;
//弹幕数量控件字体颜色
@property(nonatomic, strong) UIColor *barrageLabelTextColor;
/** 发布背景内 视图的边距  */
@property(nonatomic, assign) CGFloat barrageBackgroundViewPaddinng;
/** 发送弹幕输入框字体大小 */
@property(nonatomic, strong) UIFont *barrageTextViewFont;
/** 发送弹幕输入框大小  */
@property(nonatomic, assign) CGRect barrageTextViewFrame;
/** 占位符 */
@property(nonatomic, copy) NSString *barrageTextViewPlaceholder;
/** 占位符颜色 */
@property(nonatomic, strong) UIColor *barrageTextViewPlaceholderColor;
/** 输入框背景颜色 */
@property(nonatomic, strong) UIColor* barrageTextViewBackgroundColor;
/** 发送按钮背景色 */
@property(nonatomic, strong) UIColor *sendBarrageButtonBackgroundColor;
/** 发送按钮Title */
@property(nonatomic, copy) NSString *sendBarrageButtonTitle;
/** 发送按钮圆角大小 */
@property(nonatomic, assign) CGFloat sendBarrageButtonCornerRadius;
/** 发送按钮字体 */
@property(nonatomic, strong) UIFont *sendBarrageButtonFont;
/** 发送弹幕背景view大小  */
@property(nonatomic, assign) CGSize sendbarrageBackgroundViewSize;
/** 发布按钮位置  */
@property(nonatomic, assign) CGRect sendBarrageButtonFrame;

// MARK: - 用户信息自定义参数
//用户头像
@property(nonatomic, copy) NSString *avatar;
//用户ID
@property(nonatomic, copy) NSString *userId;

/**
   iVoice的sdk需要让媒体方在sdk方法中提交用户在广告请求前所听过的最近5～10条组信息，信息字段包含：标题（专辑／歌曲名称+作者+歌手等英文逗号分隔）、音频文件url、结束播放时的进度百分比
 */
// 调用者 需要传入 请求广告前 自己APP内的 最近5～10条组信息，信息字段包含：标题（专辑／歌曲名称+作者+歌手等英文逗号分隔）、音频文件url、结束播放时的进度百分比
@property(nonatomic, copy) NSArray<iVoiceADInfo*> *label;

@property(nonatomic, copy, readonly) NSString *labelString;


@end

