//
//  iVoiceAD.h
//  iVoiceDemo
//
//  Created by lizhi on 2021/10/15.
//

#import <Foundation/Foundation.h>
#import <iVoiceSDK/IVoiceDelegate.h>
#import <UIKit/UIKit.h>
#import "IVoiceADConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class IVoiceADInfoIVoiceADInfo;

typedef void (^iVoiceLoadStateBlock)(BOOL state);


@interface IVoiceAD : NSObject

@property(nonatomic, weak) id <IVoiceDelegate> delegate;

/// 创建音频广告
/// @param adid 广告adid
+ (instancetype)createWithAdid:(NSString *)adid
                        config:(IVoiceADConfig *)config;
//广告数据加载状态回调
@property(nonatomic, copy) iVoiceLoadStateBlock loadStateBlock;

//iVoice展示广告
- (void)showiVoice;

//iVoice关闭广告

- (void)closeiVoice;

//锁屏展示iVoice
- (void)displayiVoiceOnLockScreen;


@end

NS_ASSUME_NONNULL_END
