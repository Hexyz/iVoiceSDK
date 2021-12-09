#import <UIKit/UIKit.h>
#import "IVoiceADInfo.h"

typedef struct {
	CGFloat top;//上边距
	CGFloat left;//左边距
	CGFloat right;//右边距
}QCiVoiceMargin;

static inline QCiVoiceMargin make (CGFloat top,CGFloat left, CGFloat right) {
	QCiVoiceMargin magin;
	magin.top = top;
	magin.left = left;
	magin.right = right;
	return magin;
}

@interface IVoiceADConfig : NSObject

///右侧工具栏是否显示，默认YES显示
@property(nonatomic, assign) BOOL isShowTools;

// MARK: - 倒计时控件控制
/**
 - 示倒计时倒计时（仅有倒计时，无法跳过）style：[sss ]
 - 展示倒计时+跳过 style：[sss | 跳过]
 - 控件需保留宽度至少70pt，高 13pt
 是否展示倒计时控件控制
 */
@property(nonatomic, assign) BOOL isShowCountDown;
//倒计时控件位置
@property(nonatomic, assign) QCiVoiceMargin countDownMargin;

// MARK: - 广告视图整体高度
@property(nonatomic, assign) CGSize iVoiceADViewSize;

// MARK: - 标题
//标题距离整个广告 左 右 上 边距
@property(nonatomic, assign) QCiVoiceMargin titleMargin;
//标题字体
@property(nonatomic, strong) UIFont *titleFont;
//标题字体颜色
@property(nonatomic, strong) UIColor *titleTextColor;
//标题最多行数，默认1行
@property(nonatomic, assign) NSInteger titleNumberOfLines;

// MARK: -  描述
//描述距离标题上边距和整个广告 左 右 边距 top为距离titleLabel底部距离
@property(nonatomic, assign) QCiVoiceMargin summaryMargin;
//描述字体尺寸
@property(nonatomic, strong) UIFont *summaryFont;
//描述字体颜色
@property(nonatomic, strong) UIColor *summaryTextColor;
//标题最多行数，默认1行
@property(nonatomic, assign) NSInteger summaryNumberOfLines;

// MARK: - 广告结束View
//标题字体
@property(nonatomic, strong) UIFont *endTipsTitleFont;
//标题字体颜色
@property(nonatomic, strong) UIColor *endTipsTitleTextColor;
//描述字体尺寸
@property(nonatomic, strong) UIFont *endTipsSummaryFont;
//描述字体颜色
@property(nonatomic, strong) UIColor *endTipsSummaryTextColor;

// MARK: - 底部 Widget
//// 是否展示底部widget ，默认 YES
@property(nonatomic, assign) BOOL isShowWidget;
//// 底部Widget 的位置
@property(nonatomic, assign) CGPoint widgetViewOrigin;
//// 底部Widget 的尺寸
@property(nonatomic, assign) CGSize widgetViewSize;
//// 底部Widget 的背景圆角
@property(nonatomic, assign) CGFloat widgetViewRadius;
//// 底部Widget 的背景颜色
@property(nonatomic, strong) UIColor *widgetViewBackgroundColor;
//// 底部Widget 的背景阴影颜色
@property(nonatomic, strong) UIColor *widgetViewShadowColor;
//// 底部Widget 的背景阴影偏移量
@property(nonatomic, assign) CGSize widgetViewShadowOffset;
//// 底部Widget 的背景阴影圆角
@property(nonatomic, assign) CGFloat widgetViewShadowRadius;
//// 底部Widget 的头像控件位置和尺寸
@property(nonatomic, assign) CGRect widgetViewHeaderViewFrame;
//// 底部Widget 的头像控件圆角
@property(nonatomic, assign) CGFloat widgetViewHeaderViewRadius;
//// 底部Widget 的标题控件位置和尺寸
@property(nonatomic, assign) CGRect widgetViewTitleLabelFrame;
//// 底部Widget 的标题控件字体大小
@property(nonatomic, strong) UIFont *widgetViewTitleLabelFont;
//// 底部Widget 的标题控件字体颜色
@property(nonatomic, strong) UIColor *widgetViewTitleLabelTextColor;
//// 底部Widget 的描述控件位置和尺寸
@property(nonatomic, assign) CGRect widgetViewSummaryLabelFrame;
//// 底部Widget 的描述控件字体
@property(nonatomic, strong) UIFont *widgetViewSummaryLabelFont;
//// 底部Widget 的描述控件字体颜色
@property(nonatomic, strong) UIColor *widgetViewSummaryLabelTextColor;
//// 底部Widget 的下载按钮控件位置和尺寸
@property(nonatomic, assign) CGRect widgetViewDoneButtonFrame;
//// 底部Widget 的位置下载按钮背景颜色
@property(nonatomic, strong) UIColor *widgetViewDoneButtonBackgroundColor;
//// 底部Widget 的下载按钮控件圆角
@property(nonatomic, assign) CGFloat widgetViewDoneButtonRadius;
//// 底部Widget 的下载按钮字体大小
@property(nonatomic, strong) UIFont *widgetViewDoneButtonFont;
//// 底部Widget 的下载按钮控件字体颜色
@property(nonatomic, strong) UIColor *widgetViewDoneButtonTextColor;
//// 底部Widget 的关闭按钮控件位置和尺寸
@property(nonatomic, assign) CGRect widgetViewCloseButtonFrame;

// MARK: - 右侧工具栏按钮
//用户头像控件位置和尺寸
@property(nonatomic, assign) CGRect toolsAvatarButtonFrame;
//用户头像控件位置和尺寸
@property(nonatomic, assign) CGFloat toolsAvatarButtonCornerRadius;
//是否隐藏🔗链接图标
@property(nonatomic, assign) BOOL toolsAvatarHiddenLink;
//点在控件位置和尺寸
@property(nonatomic, assign) CGRect toolsLoveButtonFrame;
//点赞数量控件位置和尺寸
@property(nonatomic, assign) CGRect toolsLoveLabelFrame;
//点赞数量控件字体大小
@property(nonatomic, strong) UIFont *toolsLoveLabelFont;
//点赞数量控件字体颜色
@property(nonatomic, strong) UIColor *toolsLoveLabelTextColor;

// MARK: - 封面
//背景图片位置和尺寸
@property(nonatomic, assign) CGRect backgroundImageViewFrame;
//背景图片圆角（默认0）
@property(nonatomic, assign) CGFloat backgroundImageViewCornerRadius;
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
//弹幕头像尺寸
@property(nonatomic, assign) CGSize barrageIconSize;
//弹幕内容字体大小
@property(nonatomic, strong) UIFont *barrageTitleFont;
//弹幕内容字体颜色
@property(nonatomic, strong) NSArray<UIColor *> *barrageTitleColors;
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
@property(nonatomic, copy) NSArray<IVoiceADInfo*> *label;

@property(nonatomic, copy, readonly) NSString *labelString;

@end

