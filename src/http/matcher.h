//
// Created by amisher on 18-12-17.
//

#ifndef AMNET_MATCHER_H
#define AMNET_MATCHER_H

#include <unordered_map>
#include <string>
#include <vector>

class HttpRequest;

class Matcher{
public:
    enum RegexType{
        REGEX_TYPE_METHOD,
        REGEX_TYPE_URL,
        REGEX_TYPE_PREFIX,
        REGEX_TYPE_HEADER,
        REGEX_TYPE_QUERY,
    };
    Matcher(std::string pattern, RegexType type, std::string& key);

    bool isValid()const { return valid_;}

    bool isMatched(const HttpRequest& request, std::unordered_map<std::string, std::string>* dict);


private:
    void InitPattern(std::string& pattern);

    bool valid_;

    //进行匹配的类型
    RegexType regex_type_;

    // 对头部或query匹配时的key
    std::string key_;

    // 正则模式
    std::string pattern_;

    // 匹配结果
    std::vector<std::string> regex_names_;

};

#endif //AMNET_MATCHER_H
