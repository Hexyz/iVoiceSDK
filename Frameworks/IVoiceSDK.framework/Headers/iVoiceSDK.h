#import <Foundation/Foundation.h>
#import "iVoiceADInfo.h"
#import "iVoiceADConfig.h"
#import "iVoiceADView.h"
#import "iVoiceLaunchADView.h"
#import "iVoiceItemADView.h"
#import "iVoiceAD.h"

NS_ASSUME_NONNULL_BEGIN

@interface iVoiceSDK : NSObject

+ (void)initWithMid:(NSString *)mid;

@end

NS_ASSUME_NONNULL_END
