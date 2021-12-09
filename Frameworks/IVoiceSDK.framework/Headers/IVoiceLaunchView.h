#import <UIKit/UIKit.h>
#import "IVoiceDelegate.h"
#import "IVoiceADConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface IVoiceLaunchView : UIView

@property(nonatomic, weak) id <IVoiceDelegate> delegate;

+ (instancetype)create:(CGRect)frame
                  adid:(NSString *)adid
                config:(IVoiceADConfig *)config;

@end

NS_ASSUME_NONNULL_END
