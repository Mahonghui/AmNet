//
// Created by amisher on 18-12-14.
//

#ifndef AMNET_HTTPRESPONSE_H
#define AMNET_HTTPRESPONSE_H

#include <unordered_map>
#include "iobuffer.h"

class HttpResponse{
public:
    enum HttpStatusCode{
        OK=200,
        MOVED_PERMANENTLY=301,
        BAD_REQUEST=400,
        NOT_FOUND=404,
        INTERNAL_ERROR=500,
        UNKNOWN,
    };

    explicit HttpResponse(bool close): short_conn_(close), status_(UNKNOWN){}

    void SetCloseConn(bool close){short_conn_=close;}
    bool GetCloseConn()const { return short_conn_;}

    void SetStatusCode(HttpStatusCode c){status_=c;}
    HttpStatusCode GetStatusCode()const { return status_;}
    void SetStatusPhrase(const std::string& msg){phrase_=msg;}
    void AddHeader(const std::string& key, const std::string& value){headers_[key]=value;}
    void SetContentType(const std::string& type){
        AddHeader("Content-Type", type+"; charset=utf-8");
    }

    IOBuffer& GetBuffer() { return buffer_;}

    void WriteHeader2Buffer();
    void WriteMsg2Buffer(std::string& msg);

private:
    bool short_conn_;
    HttpStatusCode status_;
    std::string phrase_;
    std::unordered_map<std::string, std::string> headers_;
    IOBuffer buffer_;
};

#endif //AMNET_HTTPRESPONSE_H
