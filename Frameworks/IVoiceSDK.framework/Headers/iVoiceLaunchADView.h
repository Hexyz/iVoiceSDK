#import <UIKit/UIKit.h>
#import <iVoiceSDK/iVoiceDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface iVoiceLaunchADView : UIView

@property(nonatomic, weak) id <iVoiceDelegate> delegate;

//+ (instancetype)createWithAdid:(NSString *)adid;
+ (instancetype)create:(CGRect)frame adid:(NSString *)adid;

@end

NS_ASSUME_NONNULL_END
