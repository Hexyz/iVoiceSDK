#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IVoiceDelegate <NSObject>

@optional
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

//广告点击了跳过
- (void)didSkip;

@end

NS_ASSUME_NONNULL_END
