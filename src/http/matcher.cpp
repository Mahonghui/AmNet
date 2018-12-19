//
// Created by amisher on 18-12-17.
//

#include <regex>
#include <iostream>
#include <utility>
#include "matcher.h"
#include "httprequest.h"

Matcher::Matcher(std::string pattern, Matcher::RegexType type, std::string& key):
valid_(true),
regex_type_(type),
key_(key)
{
    InitPattern(pattern);
}

void Matcher::InitPattern(std::string& pattern) {
    // 判断{} 是否配对
    int level = 0;
    unsigned int index =0;
    std::vector<unsigned int> indexes;

    for(unsigned int i=0; i<pattern.size(); ++i){
        if(pattern[i] == '{'){
            if(++level == 1)
                index = i;
        }
        else if(pattern[i] == '}'){
            if(--level == 0){
                indexes.push_back(index);
                indexes.push_back(i+1);
            }
            else if(level < 0){
                valid_ = false;
                return;
            }
        }
    }

    if(level != 0){
        valid_ = false;
        return;
    }
    // xx{name: [0-9]+}yy --> xx([0-9]+)yy
    unsigned int end = 0;
    for(unsigned int i=0; i<indexes.size(); i += 2){
        std::string r = pattern.substr(end, indexes[i]-end);
        end = indexes[i+1];

        pattern_.append(r);

        unsigned int j;
        for(j =indexes[i]; j<end; ++j){
            if(pattern[j] == ':'){
                regex_names_.push_back(pattern.substr(indexes[i]+1, j-(indexes[i]+1)));
                pattern_.append( "(" + pattern.substr(j+1, (end-1)-(j+1))+")");
                break;
            }
        }

        if(j == end){
            regex_names_.push_back(pattern.substr(indexes[i]+1, (end-1)-(indexes[i]+1)));
            pattern_.append("(.*)");
        }
    }

    if(end < pattern.size()){
        pattern_.append(pattern.substr(end, pattern.size()-end));
    }
}

bool Matcher::isMatched(const HttpRequest &request, std::unordered_map<std::string, std::string> *dict) {
    std::regex reg(pattern_);
    std::smatch m;

    if(regex_type_ == REGEX_TYPE_URL || regex_type_ == REGEX_TYPE_PREFIX){
        if(regex_match(request.GetPath(), m, reg)){
            // m 中包含匹配的整个字符串和匹配子串
            for(unsigned long int i=regex_names_.size()-1, j = m.size()-1; i>=0&&j>=0; --i, --j){
                dict->insert(std::make_pair(regex_names_[i], m[j]));
            }
            return true;
        }
    }else if(regex_type_ == REGEX_TYPE_METHOD){
        if(regex_match(request.GetMethodStr(), reg))
            return true;
    }else if(regex_type_ == REGEX_TYPE_HEADER){
        if(regex_match(request.GetHeader(key_), reg))
            return true;
    }else if(regex_type_ == REGEX_TYPE_QUERY){
        if(regex_match(request.GetQuery(key_), reg))
            return true;
    }
    return false;
}