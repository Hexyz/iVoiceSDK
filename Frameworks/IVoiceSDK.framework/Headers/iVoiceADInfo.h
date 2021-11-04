#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface iVoiceADInfo : NSObject
/**音频标题 */
@property(nonatomic, copy) NSString *title;
///** 音频地址 */
@property(nonatomic, copy) NSString *url;
/** 音频描述 */
@property(nonatomic, copy) NSString *desc;
/** 音频f封面 */
@property(nonatomic, copy) NSString *image;
///**播放进度，0 - 100 完整播放 */
@property(nonatomic, assign) int progress;

@end

NS_ASSUME_NONNULL_END
