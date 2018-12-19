//
// Created by amisher on 18-12-15.
//
#include <cstdlib>
#include <string>
#include "iobuffer.h"
#include "httpparser.h"

bool HttpParser::ParseReqLine(const char *start, const char *end){
    const char* ptr = start;
    const char* space = std::find(ptr, end,' ');

    const char* question;
    const char* ampersand;
    const char* equal;

    bool succeed;
    while (request_state_ != PARSE_ERQUEST_LINE_FINISH)
    {
        //解析URL请求行
        // 形如 GET http://www.seu.edu.cn/xxx/yyy?k1=v1&k2=v2 HTTP/1.1
        switch (request_state_) {
            case PARSE_REQUEST_LINE_METHOD:
                if(space != end && request_.SetMethod(ptr, space))
                {
                    request_state_ = PARSE_REQUEST_LINE_URL;
                    break;
                }
                else
                    return false;

                // 解析域名和参数
            case PARSE_REQUEST_LINE_URL:
                ptr = space+1;
                space = std::find(ptr, end, ' ');
                if(space != end)
                {
                    // 分割路径
                    question = std::find(ptr, space, '?');
                    if(question != space) {
                        request_.SetPath(ptr, question);
                        ptr = question + 1;
                        // 遍历请求参数
                        while ((ampersand = std::find(ptr, space, '&')) != space) {
                            equal = std::find(ptr, ampersand, '=');
                            if (equal != ampersand)
                                request_.AddQuery(ptr, equal, ampersand);
                            ptr = ampersand + 1;

                        }
                        //  处理最后一对键值
                        if (ptr != space) {
                            equal = std::find(ptr, space, '=');
                            if (equal != space)
                                request_.AddQuery(ptr, equal, space);
                        }
                    }
                    else
                        // 没有URL参数
                        request_.SetPath(ptr, space);
                    request_state_ = PARSE_REQUEST_LINE_VERSION;
                    break;
                } else
                    return false;

                // 解析http版本
            case PARSE_REQUEST_LINE_VERSION:
                ptr = space+1;
                // 检查是否符合“HTTP/1.*”, 暂不支持HTTP/2.0
                succeed = (end - ptr == 8 && std::equal(ptr, end-1, "HTTP/1."));
                if(succeed)
                {
                    if(*(end-1) == '1')
                        request_.SetVersion(HttpRequest::HTTP11);
                    else if(*(end-1) == '0') {
                        request_.SetVersion(HttpRequest::HTTP10);
                    }else
                    {
                        request_.SetVersion(HttpRequest::UNKNOWN);
                    }

                    request_state_ = PARSE_ERQUEST_LINE_FINISH;
                    break;
                } else
                    return false;
            case PARSE_ERQUEST_LINE_FINISH:
                break;
            default:
                return false;
        }
    }
    return true;
}

bool HttpParser::ParseRequest(IOBuffer *buffer, TimeStamp t) {
    bool more_things = true;
    const char* crlf;

    bool ok;
    const char* colon;
    const char* start;
    const char* end;
    const char* ampersand;
    const char* equal;

    while (more_things)
    {
        switch (parse_state_)
        {
            case PARSE_STATE_REQUESTLINE:
                crlf = buffer->FindCRLF();
                if(crlf)
                {
                    ok = ParseReqLine(buffer->GetReadablePtr(), crlf);
                    if(ok)
                    {
                        request_.SetArriveTime(t);
                        buffer->RetrieveUntil(crlf+2);
                        parse_state_ = PARSE_STATE_HEADER;
                    }
                    else
                        more_things = false;
                } else
                    more_things = false;
                break;

            case PARSE_STATE_HEADER:
                crlf = buffer->FindCRLF();
                if(crlf)
                {
                    colon = std::find(buffer->GetReadablePtr(), crlf, ':');
                    if(colon != crlf)
                    {
                        request_.AddHeader(buffer->GetReadablePtr(), colon, crlf);
                    } else{
                        if(request_.GetHeader("Content-Length").empty())
                        {
                            parse_state_ = PARSE_STATE_ALL;
                            more_things = false;
                        } else{
                            body_len_ = (size_t)stoi(request_.GetHeader("Content-Length"));
                            parse_state_ = PARSE_STATE_BODY;
                        }
                    }
                    buffer->RetrieveUntil(crlf+2);
                }
                else
                    more_things = false;
                break;

            case PARSE_STATE_BODY:
                if(buffer->GetReadableSize() >= body_len_)
                {
                    start = buffer->GetReadablePtr();
                    end = start + body_len_;

                    while ((ampersand = std::find(start, end, '&')) != end)
                    {
                        equal = std::find(start, ampersand, '=');
                        if(equal != ampersand)
                            request_.AddQuery(start, equal, ampersand);
                        start = ampersand +1;
                    }
                    if(start != end)
                    {
                        equal = std::find(start, end, '=');
                        if(equal != end)
                            request_.AddQuery(start, equal, end);
                    }
                    parse_state_ = PARSE_STATE_ALL;
                    more_things = false;
                }
                else
                    more_things = false;
                break;
            default:
                more_things = false;
                break;
        }
    }
    return ok;
}


