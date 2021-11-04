# <center>iVoiceSDK iOS开发文档</center>


|版本号|日期|说明|
|:---:|:---:|:---:|
|1.1.0|2021-11-03|alpha|

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
pod 'iVoiceSDK'
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
### 广告初始化类(iVoiceSDK)
* 在AppDelegate导入`#import <iVoiceSDK/iVoiceSDK.h>` 并且调用 `[iVoiceSDK initWithMid:@"xxxxxxxxxxxxxx"];;`
* 调用代码示例：
```ObjC
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions { 
    [QCiVoiceSDK initialize]; 
    [iVoiceSDK initWithMid:@"xxxxxxxxxxxxxx"];
   return YES;  
} 
```

## 广告类型
### 沉浸式自渲染音频互动广告(IVoiceADView)
* 导入`#import<IVoiceSDK/IVoiceSDK.h>`

```ObjC
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

//向iVoice发送一条弹幕
- (void)sendABarrageToiVoice:(NSString *)comment;

//锁屏展示iVoice
- (void)displayiVoiceOnLockScreen;

* 回调说明：

```ObjC
//iVoiceBarrageDelegate

///点击弹幕
- (void)didClickBarrage:(NSString *)userId
        avatar:(NSString *)avatar;

///发送弹幕成功了
- (void)sendBarrageSuccess;

///发送弹幕失败了
- (void)sendBarrageError:(NSError *)error;

// iVoiceDelegate
///广告加载成功了
- (void)loadSucceeded;

///广告加载失败了
- (void)loadFailed;

///广告曝光了
- (void)didExpoure;

///广告被点击了
- (void)didClick;

///广告播放完成
- (void)didFinish;

```
* 配置参数说明：

```ObjC
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
/** Tip广告的关闭按钮控 显示图片（本地图片） */
@property(nonatomic, copy) NSString *tipViewCloseButtonImageName;

// MARK: - 自定义按钮
//用户头像控件位置和尺寸
@property(nonatomic, assign) CGRect avatarButtonFrame;
//用户头像控件位置和尺寸
@property(nonatomic, assign) CGFloat avatarButtonCornerRadius;
//是否隐藏🔗链接图标
@property(nonatomic, assign) BOOL avatarHiddenLink;

//点在控件位置和尺寸
@property(nonatomic, assign) CGRect loveButtonFrame;
//未点赞控件显示图片（本地图片）
@property(nonatomic, copy) NSString *loveButtonImage;
//点赞后控件显示图片（本地图片）
@property(nonatomic, copy) NSString *loveButtonSelectedImage;
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
//发送弹幕控件显示图片
@property(nonatomic, copy) NSString *barrageImageName;
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
```
* 使用示例：

```ObjC
    iVoiceADConfig *config=[[iVoiceADConfig alloc] init];
	self.ADView = [iVoiceADView create:CGRectMake(0, 0, 100, 100) adid:@"xxxxxxxxxxx" config:config];
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
### 首听广告(iVoiceLaunchView)
```ObjC
	iVoiceLaunchView *view = [iVoiceLaunchView create:CGRectMake(0, -89, kScreenWidth, kScreenHeigh) adid:@"xxxxxxx"];
	view.delegate = self;
	[self addSubview:view];
````

### 冠名广告(iVoiceAD)
```ObjC
    //初始化冠名广告
    self.voiceAD = [iVoiceAD createWithAdid:@"xxxxxxxxxxxxxx"];
    //播放广告
    [self.voiceAD showiVoice];
```
* 使用示例：

```ObjC
-(void)setupVoiceAD{
    // 初始化冠名广告
    self.voiceAD = [iVoiceAD createWithAdid:@"xxxxxxxxxxxxxx"];
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
