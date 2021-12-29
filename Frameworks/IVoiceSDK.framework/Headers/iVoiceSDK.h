#import <Foundation/Foundation.h>
#import "IVoiceADInfo.h"
#import "IVoiceADConfig.h"
#import "IVoiceADView.h"
#import "IVoiceLaunchView.h"
#import "IVoiceAD.h"
#import "IVoiceMeidaView.h"
#import "IVoiceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface IVoiceSDK : NSObject

+ (void)initWithMid:(NSString *)mid dnt:(BOOL) dnt;

@end

NS_ASSUME_NONNULL_END
