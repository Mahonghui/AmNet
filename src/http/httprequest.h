//
// Created by amisher on 18-12-14.
//

#ifndef AMNET_HTTPREQUEST_H
#define AMNET_HTTPREQUEST_H

#include <unordered_map>
#include "timestamp.h"

class HttpRequest{
public:
    enum Method{
        GET,
        POST,
        HEAD,
        PUT,
        DELETE,
        OPTION,
        INVALID,
    };
    enum Version{
        HTTP10,
        HTTP11,
        UNKNOWN,
    };

    HttpRequest():method_(INVALID), version_(UNKNOWN){}

    bool SetMethod(const char* start, const char* end){
        std::string s(start, end);
        if(s == "GET")
            method_ = GET;
        if(s == "POST")
            method_ = POST;
        if(s == "HEAD")
            method_=HEAD;
        if(s == "PUT")
            method_=PUT;
        if(s == "DELETE")
            method_ = DELETE;
        if(s == "OPTION")
            method_ = OPTION;
        return method_ != INVALID;
    }

    Method GetMethod()const { return method_;}

    const char* GetMethodStr()const {
        const char* m = "INVALID";
        switch (method_){
            case GET:
                m = "GET";
                break;
            case POST:
                m = "POST";
                break;
            case HEAD:
                m = "HEAD";
                break;
            case PUT:
                m = "PUT";
                break;
            case DELETE:
                m = "DELETE";
                break;
            case OPTION:
                m = "OPTION";
                break;
            default:
                break;
        }

        return m;
    }

    void SetVersion(Version v){version_ = v;}
    Version GetVerison()const{ return version_;}

    void SetPath(const char* start, const char* end){path_.assign(start, end);}

    const std::string& GetPath()const { return path_;}

    void AddQuery(const char* k, const char* equal, const char* v){
        std::string key(k, equal++);
        std::string value(equal, v);
        queries_[key] = value;
    }

    const std::string GetQuery(const std::string& key) const
    {
        auto it = queries_.find(key);
        if(it != queries_.end())
            return it->second;
        else
            return std::string("No such field in query");
    }

    void AddHeader(const char* start, const char* coln, const char* end)
    {
        std::string key(start, coln++);
        // 过滤空格
        while (coln<end&&isspace(*coln))
            ++coln;
        std::string value(coln, end);
        while (!value.empty()&&isspace(value[value.size()-1]))
            value.resize(value.size()-1);

        headers_[key] = value;
    }

    std::string GetHeader(const std::string& key)const {
        auto it = headers_.find(key);
        if(it != headers_.end())
            return it->second;
        return std::string("No such field in header");
    }

    void SetArriveTime(TimeStamp t){arrive_time_ = t;}
    TimeStamp GetArriveTime()const { return  arrive_time_;}

    // 自定义交换方法
    void Swap(HttpRequest& rhs)
    {
        std::swap(method_, rhs.method_);
        std::swap(version_, rhs.version_);
        path_.swap(rhs.path_);
        queries_.swap(rhs.queries_);
        headers_.swap(rhs.headers_);
        std::swap(arrive_time_,rhs.arrive_time_);
    }

private:
    Method method_;
    Version version_;
    std::string path_;
    std::unordered_map<std::string, std::string> queries_;
    std::unordered_map<std::string, std::string> headers_;
    TimeStamp arrive_time_;
};

#endif //AMNET_HTTPREQUEST_H
