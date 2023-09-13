//
//  LTSSDK.h
//  LTSSDK
//
//  Created by LTS on 2023/5/19.
//
//

#import <Foundation/Foundation.h>
#import <LTSSDK/LTSConfigParams.h>

NS_ASSUME_NONNULL_BEGIN

@interface LTSSDK : NSObject

/**
 使用配置项初始化实例对象【如果在子线程调用，将切换至主线程同步调用】.
 
 @param params 配置项.
 */
- (instancetype)initWithConfig:(LTSConfigParams *)params;

/**
 设置配置项【如果在子线程调用，将切换至主线程同步调用】.
 
 @param params 配置项.
 @return 入参检测通过返回YES，否则返回NO.
 */
- (BOOL)config:(LTSConfigParams *)params;

/**
 上报日志：先存入本地数据库，根据策略实施上报.
 
 @param content 日志内容，支持字典和字典数组；键值对最多500个；content转JSON字符串最大支持长度为1024*30，超出则被截断丢弃。
 @param labels 日志标签，可空；value支持NSString、NSNumber类型；key最大长度为64，支持字母、数字和下划线组合，首字符须是字母；如果value是NSString类型，最大长度为256。键值对最多50个。
 @return 入参及内部状态检测通过返回YES，否则返回NO.
 */
- (BOOL)report:(id)content labels:(nullable NSDictionary<NSString *, id> *)labels;

/**
 立即上报日志.
 
 @param content 日志内容，支持字典和字典数组；键值对最多500个；content转JSON字符串最大支持长度为1024*30，超出则被截断丢弃。
 @param labels 日志标签，可空；value支持NSString、NSNumber类型；key最大长度为64，支持字母、数字和下划线组合，首字符须是字母；如果value是NSString类型，最大长度为256；键值对最多50个。
 @return 入参及内部状态检测通过返回YES，否则返回NO.
 */
- (BOOL)reportImmediately:(id)content labels:(nullable NSDictionary<NSString *, id> *)labels;

@end

NS_ASSUME_NONNULL_END
