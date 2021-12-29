
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSUInteger, InteractiveType) {
	InteractiveTypeNone           = 0,// 不操作
	InteractiveTypeWebview        = 1,// App webview 打开链接
	InteractiveTypeSafari         = 2,// safari打开
	InteractiveTypePhone          = 3,// 打电话
	InteractiveTypeDownload       = 6,// 下载App
	InteractiveTypeDeeplink       = 7,// deepliink
};

typedef NS_ENUM (NSUInteger, PlayType) {
	PlayTypeDefault          = 0,
	PlayTypeClose            = 1,
	PlayTypeAgain            = 2,
	PlayTypeWaitAMoment      = 3,

};

@interface IVoiceRemindSource : NSObject

@property(nonatomic, copy) NSString *start;
@property(nonatomic, copy) NSString *restart;
@property(nonatomic, assign) NSInteger starttime;

@end

//------------------------------------------


@interface IVoiceRemindModel : NSObject
@property(nonatomic, strong) IVoiceRemindSource *shakeme;
@property(nonatomic, strong) IVoiceRemindSource *chat;
@property(nonatomic, strong) IVoiceRemindSource *combined;

@end

//------------------------------------------

@interface IVoiceRemind : NSObject

@property(nonatomic, strong) IVoiceRemindModel *deeplink;
@property(nonatomic, strong) IVoiceRemindModel *phone;
@property(nonatomic, strong) IVoiceRemindModel *download;
@property(nonatomic, strong) IVoiceRemindModel *openldp;

@end

//------------------------------------------

@interface IVoiceInteractive : NSObject

@property(nonatomic, assign) NSInteger reminds;
@property(nonatomic, assign) NSInteger wait;
@property(nonatomic, strong) IVoiceRemind *remind;

@end

@interface IVoiceEvent : NSObject

@property(nonatomic, strong) NSArray <NSString *> *close;
@property(nonatomic, strong) NSArray <NSString *> *thirdQuartile;
@property(nonatomic, strong) NSArray <NSString *> *complete;
@property(nonatomic, strong) NSArray <NSString *> *midpoint;
@property(nonatomic, strong) NSArray <NSString *> *start;
@property(nonatomic, strong) NSArray <NSString *> *firstQuartile;

@end
@interface IVoiceConfig : NSObject
@property(nonatomic, assign) PlayType stop_playing_mode;
@property(nonatomic, assign) NSInteger rendering_type;
@end

@interface IVoiceIcon : NSObject
@property(nonatomic, copy) NSString *desc;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *url;
@property(nonatomic, assign) NSInteger w;
@property(nonatomic, assign) NSInteger h;
@end

@interface IVoiceCompanion : NSObject
@property(nonatomic, copy) NSString *url;
@property(nonatomic, assign) NSInteger h;
@property(nonatomic, assign) NSInteger w;
@end

@interface IVoiceChimeSetion : NSObject
@property(nonatomic, assign) NSInteger s;
@property(nonatomic, assign) NSInteger e;
@end

//------------------------------------------
@interface IVoiceModel : NSObject

@property(nonatomic, copy) NSString *format;
@property(nonatomic, copy) NSString *advertiser;
@property(nonatomic, copy) NSString *creativeid;
@property(nonatomic, strong) IVoiceConfig *rendering_config;
@property(nonatomic, assign) InteractiveType action;
@property(nonatomic, assign) NSInteger start;
@property(nonatomic, strong) IVoiceInteractive *interactive;
@property(nonatomic, assign) NSInteger volume;
@property(nonatomic, copy) NSString *deeplink;
@property(nonatomic, copy) NSString *tpnumber;
@property(nonatomic, copy) NSString *download;
@property(nonatomic, assign) NSInteger duration;
@property(nonatomic, assign) NSInteger skip;
@property(nonatomic, strong) IVoiceIcon *icon;
@property(nonatomic, copy) NSString *audiourl;
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;
@property(nonatomic, copy) NSString *desc;
@property(nonatomic, copy) NSString *ldp;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, strong) IVoiceEvent *event;
@property(nonatomic, copy) NSString *firstimg;
@property(nonatomic, strong) IVoiceCompanion *companion;
@property(nonatomic, assign) NSInteger end;
@property(nonatomic, strong) NSArray <NSString *> *clks;
@property(nonatomic, strong) NSArray <NSString *> *imps;

@property(nonatomic, copy) NSString *interactivePlayUrl; // 要播放的互动音频url
@property(nonatomic, copy) NSString *replayInteractivePlayUrl; //重新播放的互动音频url
@property(nonatomic, copy) NSString *shakeAudioUrl; //摇一摇音频
@property(nonatomic, copy) NSString *downloadBtnTitle;// 下载按钮标题

@property(nonatomic, strong) IVoiceChimeSetion *section;

- (void)configInteractivePlayUrl;

@end


@interface IVoiceADModel : NSObject

@property(nonatomic, strong) IVoiceModel *normal;
@property(nonatomic, strong) IVoiceModel *chime;

@end

@interface IVoiceADResponse : NSObject
@property(nonatomic, strong) IVoiceADModel *adm;
@end

NS_ASSUME_NONNULL_END
