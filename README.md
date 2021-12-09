# <center>IVoiceSDK iOS开发文档</center>


|版本号|日期|说明|
|:---:|:---:|:---:|
|1.1.1-beta2|2021-12-09|beta|

<!--[跳转到API接入](#gotoapi)-->
## 开发环境
* 确保您的开发及部署环境符合以下标准：
* 开发工具：推荐Xcode 11及以上版本
* 部署目标：iOS 10及以上版本
* SDK版本：官网最新版本

## 术语介绍
* adid：广告位 ID，是您在企创平台创建某种类型的广告位置的ID。
* mid:  媒体ID, 是您在企创平台创建某种类型的广告位置的MID。

## 开始使用
### 使用 CocoaPods
* 在你的项目的 Podfile 里添加如下内容：
```Objc
pod 'IVoiceSDK','1.1.2-haohi'
```
* 然后运行 pod install 即可。

如果只需要引入某几个特定的子模块，则可参照以下写法，具体的子模块列表请直接查看项目源码里的 QMUIKit.podspec 文件：



### 手动部署
* 将动态库iVoiceSDK.framework和iVoiceSDK.bundle拖入项目中（如图所示）并确保添加的动态库 Embed 属性设置为 Embed & Sign
*  ![](https://i.loli.net/2021/01/08/zGlMjSiowq4uKh6.jpg)
![-w850](https://i.loli.net/2021/01/08/UgiPxyp3BLGunIt.jpg)

## 其它设置
* 在Target->Build Settings ->Enable BitCode中设置为NO。
* 苹果公司在iOS9中升级了应用网络通信安全策略，默认推荐开发者使用HTTPS协议来进行网络通信，并限制HTTP协议的请求。为了避免出现无法拉取到广告的情况，我们推荐开发者在info.plist文件中增加如下配置来实现广告的网络访问：（信任HTTP请求）

```
<key>NSAppTransportSecurity</key>
<dict> <key>NSAllowsArbitraryLoads</key> <true/> </dict>
```
* 如果希望广告在后台可以播放请配置如图：

![](https://i.loli.net/2021/01/08/XE4x196VC8H7Rmf.jpg)

<!--#### <a id="gotoapi">4.API 接入</a>-->

## SDK 接入
### 广告初始化类(IVoiceSDK)
- mid: 您的媒体id;
- dnt: 是否允许广告跟踪;
* 在AppDelegate导入`#import <IVoiceSDK/IVoiceSDK.h>` 并且调用 `[IVoiceSDK initWithMid:@"xxxxxxxxxxxxxx" dnt:NO];`
* 调用代码示例：
```ObjC
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions { 
     [IVoiceSDK initWithMid:@"xxxxxxxxxxxxxx" dnt:NO]
   return YES;  
} 
```

## 广告类型
### 沉浸式自渲染音频互动广告(IVoiceADView)
* 导入`#import<IVoiceSDK/IVoiceSDK.h>`

```ObjC
+ (instancetype)create:(CGRect)frame
        adid:(NSString *)adid
        config:(IVoiceADConfig *)config;

//设置弹幕显示区域frame
@property(nonatomic, copy) SetBarrageFrameBlock barrageFrameBlock;
//广告数据加载状态回调
@property(nonatomic, copy) IVoiceLoadStateBlock loadStateBlock;

//iVoice开始渲染
- (void)startRenderiVoice;

//iVoice展示广告
- (void)showiVoice;

//iVoice关闭广告
- (void)closeiVoice;

//锁屏展示iVoice
- (void)displayiVoiceOnLockScreen;

* 回调说明：

```ObjC
//iVoiceBarrageDelegate

//点击弹幕
- (void)didClickBarrage:(NSString *)userId
        avatar:(NSString *)avatar;

//发送弹幕成功了
- (void)sendBarrageSuccess;

//发送弹幕失败了
- (void)sendBarrageError:(NSError *)error;

// IVoiceDelegate
//广告加载成功了
- (void)loadSucceeded;

//广告加载失败了
- (void)loadFailed;

//广告曝光了
- (void)didExpoure;

//广告被点击了
- (void)didClick;

//广告播放完成
- (void)didFinish;

```
* 配置参数说明：

```ObjC
typedef struct {
	CGFloat top;//上边距
	CGFloat left;//左边距
	CGFloat right;//右边距
}QCiVoiceMargin;

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
```
* 使用示例：

```ObjC
    IVoiceADConfig *config=[[IVoiceADConfig alloc] init];
	 config.isShowCountDown = YES;
    config.titleNumberOfLines = 1;
    config.summaryNumberOfLines = 0;
    config.countDownMargin = make(100, adWidth-100, 0);
    config.titleMargin = make(100, 20,300);
    config.summaryMargin = make(16, 20, 200);

	self.ADView = [IVoiceADView create:CGRectMake(0, 0, 100, 100) adid:@"xxxxxxxxxxx" config:config];
	self.ADView.delegate = self;
	self.ADView.barrageDelegate = self;
	__weak typeof(self) weakSelf=self;
	self.ADView.loadStateBlock = ^(BOOL isSuccess) {
		__strong typeof(self) StrongSelf=weakSelf;
		if (isSuccess==YES) {
			[StrongSelf.ADView startRenderiVoice];
			[StrongSelf.ADView showiVoice];
		}
	};
	[self.view addSubview:self.ADView];
```
### 首听广告(IVoiceLaunchView)
```ObjC
	IVoiceLaunchView *view = [IVoiceLaunchView create:CGRectMake(0, -89, kScreenWidth, kScreenHeigh) adid:@"xxxxxxx"];
	view.delegate = self;
	[self addSubview:view];
```
### 冠名广告(IVoiceAD)
```ObjC
    //初始化冠名广告
    self.voiceAD = [IVoiceAD createWithAdid:@"xxxxxxxxxxxxxx"];
    //播放广告
    [self.voiceAD showiVoice];
```
* 使用示例：

```ObjC
-(void)setupVoiceAD{
    // 初始化冠名广告
    self.voiceAD = [IVoiceAD createWithAdid:@"xxxxxxxxxxxxxx"];
    self.voiceAD.delegate = self;
}

-(void)playButtonClick {
    //播放广告
    [self.voiceAD showiVoice];
}

-(void)stopButtonClick {
    //关闭广告
    [self.voiceAD closeiVoice];
}

```
### 懒人听书广告(IVoiceMeidaView)
```ObjC
 // 封面图
@property(nonatomic, strong) UIImageView *coverImageView;
// 广告标识
@property(nonatomic, strong) UIButton *adButton;
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

/**
广告数据加载状态回调
state：广告是否加载成功，title：广告标题
typedef void (^IVoiceLoadStateBlock)(BOOL state, NSString *title);
*/
@property(nonatomic, copy) IVoiceLoadStateBlock loadStateBlock;

//iVoice开始渲染
- (void)startRenderiVoice;

//iVoice展示广告
- (void)showiVoice;

//iVoice关闭广告
- (void)closeiVoice;

```
- 使用
```ObjC
 /**
     label：
    iVoice的sdk需要让媒体方在sdk方法中提交用户在广告请求前所听过的最近5～10条组信息，信息字段包含：标题（专辑／歌曲名称+作者+歌手等英文逗号分隔）、音频文件url、结束播放时的进度百分比
    调用者 需要传入 请求广告前 自己APP内的 最近5～10条组信息，信息字段包含：标题（专辑／歌曲名称+作者+歌手等英文逗号分隔）、音频文件url、结束播放时的进度百分比
    如果没有可传 nil
 */
    self.ADView = [IVoiceMeidaView create:CGRectMake(0, 0, 100, 100) adid:@"xxxxxxxxxxx" label:nil];
    self.ADView.isShowCountDown = YES;
    [self.view addSubview:self.ADView];
    
    self.ADView.delegate = self;
    __weak typeof(self) weakSelf = self;
    self.ADView.loadStateBlock = ^(BOOL isSuccess, NSString *title) {
        __strong typeof(self) StrongSelf=weakSelf;
        if (isSuccess==YES) {
            [StrongSelf.ADView startRenderiVoice];
            [StrongSelf.ADView showiVoice];
            /// title ：广告标题
            StrongSelf.label.text = title;
            ///此处自可定义控件属性
            StrongSelf.ADView.titleLabel.textColor = UIColor.redColor;
        }
    };
```
- 回调
```ObjC
// IVoiceDelegate
//广告加载成功了
- (void)loadSucceeded;

//广告加载失败了
- (void)loadFailed;

//广告曝光了
- (void)didExpoure;

//广告被点击了
- (void)didClick;

//广告播放完成
- (void)didFinish;
```

