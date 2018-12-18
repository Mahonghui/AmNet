//
// Created by amisher on 18-12-18.
//

#include "route.h"
#include <iostream>

bool Route::AddRegex(std::string& pattern, Matcher::RegexType type, std::string key) {
    Matcher m(pattern, type, key);

    if(m.isValid()){
        matchers_.push_back(m);
        return true;
    }
    else
        return false;
}

Route::RoutePtr Route::SetMethodPattern(std::string& pattern) {
    if(!AddRegex(pattern, Matcher::REGEX_TYPE_METHOD)){
        std::cout<<"Invalid Method pattern."<<std::endl;
        abort();
    }
    return shared_from_this();
}

Route::RoutePtr Route::SetURLPattern(std::string& pattern) {
    if(!AddRegex(pattern, Matcher::REGEX_TYPE_URL)){
        std::cout<<"Invalid URL pattern."<<std::endl;
        abort();
    }
    return shared_from_this();
}

Route::RoutePtr Route::SetPreifxPattern(std::string &pattern) {
    if(!AddRegex(pattern, Matcher::REGEX_TYPE_PREFIX)){
        std::cout<<"Invalid Prefix pattern."<<std::endl;
        abort();
    }
    return shared_from_this();
}

Route::RoutePtr Route::SetHeaderPattern(std::string& key, std::string& value) {
    if(!AddRegex(key, Matcher::REGEX_TYPE_HEADER, value)){
        std::cout<<"Invalid Header pattern."<<std::endl;
        abort();
    }
    return shared_from_this();
}

Route::RoutePtr Route::SetQueryPattern(std::string &key, std::string &value) {
    if(!AddRegex(key,Matcher::REGEX_TYPE_QUERY, value)){
        std::cout<<"Invalid Query pattern."<<std::endl;
        abort();
    }
    return shared_from_this();
}

Route::RoutePtr Route::SetHandler(Handler& handler) {
    handler_ = handler;
    return shared_from_this();
}

bool Route::Match(const HttpRequest &request, std::unordered_map<std::string, std::string> *dict) {
    // 当该路由下所有匹配条件都匹配时返回true
    // 否则清空matchers_, 返回false
    for(auto& matcher:matchers_){
        if(matcher.isMatched(request, dict)){
            matchers_.clear();
            return false;
        }
    }
    return true;
}





