#import <UIKit/UIKit.h>
#import "IVoiceDelegate.h"
#import "IVoiceADConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface IVoiceLaunchView : UIView


// state：广告是否加载成功，title：广告标题
typedef void (^LaunchStringBlock)(NSString *title);


//广告数据加载状态回调
@property(nonatomic, copy) LaunchStringBlock block;

@property(nonatomic, copy) NSString *ADString;

@property(nonatomic, weak) id <IVoiceDelegate> delegate;

+ (instancetype)create:(CGRect)frame
                  adid:(NSString *)adid
                config:(IVoiceADConfig *)config;



@end

NS_ASSUME_NONNULL_END
