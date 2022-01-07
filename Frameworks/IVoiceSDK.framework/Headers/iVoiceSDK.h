#import <Foundation/Foundation.h>
#import "IVoiceAD.h"
#import "IVoiceADConfig.h"
#import "IVoiceADInfo.h"
#import "IVoiceADView.h"
#import "IVoiceLaunchView.h"
#import "IVoiceMeidaView.h"

NS_ASSUME_NONNULL_BEGIN

@interface IVoiceSDK : NSObject

+ (void)initWithMid:(NSString *)mid dnt:(BOOL)dnt;

@end

NS_ASSUME_NONNULL_END
