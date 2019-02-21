//
// Created by amisher on 18-12-14.
//

#ifndef AMNET_HTTPPARSER_H
#define AMNET_HTTPPARSER_H

#include "httprequest.h"

class IOBuffer;

// 解析成 HttpRequest
class HttpParser{

public:
    // 解析状态
    enum Parse_state{
        PARSE_STATE_REQUESTLINE,
        PARSE_STATE_HEADER,
        PARSE_STATE_BODY,
        PARSE_STATE_ALL,
    };
    // 解析请求的状态
    enum Parse_Request_state{
        PARSE_REQUEST_LINE_METHOD,
        PARSE_REQUEST_LINE_URL,
        PARSE_REQUEST_LINE_VERSION,
        PARSE_ERQUEST_LINE_FINISH,
    };

    HttpParser():parse_state_(PARSE_STATE_REQUESTLINE), request_state_(PARSE_REQUEST_LINE_METHOD),body_len_(0){}
    ~HttpParser()= default;
    bool ParseRequest(IOBuffer* buf, TimeStamp t);
    bool IsFinished()const { return parse_state_ == PARSE_STATE_ALL;}

    void Reset(){
        parse_state_ = PARSE_STATE_REQUESTLINE;
        request_state_ = PARSE_REQUEST_LINE_METHOD;
        body_len_ = 0;
        HttpRequest nothing;
        request_.Swap(nothing);
    }

    HttpRequest& GetRequest()  { return request_;}


private:
    bool ParseReqLine(const char* start, const char* end);

    Parse_state parse_state_;
    Parse_Request_state request_state_;
    HttpRequest request_;
    size_t body_len_;

};


#endif //AMNET_HTTPPARSER_H
