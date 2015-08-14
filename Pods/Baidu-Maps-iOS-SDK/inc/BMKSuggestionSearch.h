/*
 *  BMKSuggestionSearch.h
 *  BMapKit
 *
 *  Copyright 2014 Baidu Inc. All rights reserved.
 *
 */

#import "BMKSuggestionSearchOption.h"
#import "BMKTypes.h"

///Suggestion结果类
@interface BMKSuggestionResult : NSObject
{
    NSArray* _keyList;
    NSArray* _cityList;
    NSArray* _districtList;
}
///key列表，成员是NSString
@property (nonatomic, retain) NSArray* keyList;
///city列表，成员是NSString
@property (nonatomic, retain) NSArray* cityList;
///district列表，成员是NSString
@property (nonatomic, retain) NSArray* districtList;
@end

@protocol BMKSuggestionSearchDelegate;
///sug搜索服务
@interface BMKSuggestionSearch : NSObject
/// 检索模块的Delegate，此处记得不用的时候需要置nil，否则影响内存的释放
@property (nonatomic, retain) id<BMKSuggestionSearchDelegate> delegate;

/**
 *搜索建议检索
 *@param suggestionSearchOption       sug检索信息类
 *异步函数，返回结果在BMKSuggestionSearchDelegate的onGetSuggestionResult通知
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)suggestionSearch:(BMKSuggestionSearchOption*)suggestionSearchOption;

@end

///搜索delegate，用于获取搜索结果
@protocol BMKSuggestionSearchDelegate<NSObject>
@optional
/**
 *返回suggestion搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号，@see BMKSearchErrorCode
 */
- (void)onGetSuggestionResult:(BMKSuggestionSearch*)searcher result:(BMKSuggestionResult*)result errorCode:(BMKSearchErrorCode)error;


@end




