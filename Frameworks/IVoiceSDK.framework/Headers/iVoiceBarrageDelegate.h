NS_ASSUME_NONNULL_BEGIN

@protocol IVoiceBarrageDelegate <NSObject>

//点击弹幕
- (void)didClickBarrage:(NSString *)userId
        avatar:(NSString *)avatar;

//发送弹幕成功了
- (void)sendBarrageSuccess;

//发送弹幕失败了
- (void)sendBarrageError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
