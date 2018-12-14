//
// Created by amisher on 18-12-14.
//

#include <stdio.h>
#include "httpresponse.h"

void HttpResponse::WriteHeader2Buffer() {
    char buf[32];
    snprintf(buf, sizeof(buf), "HTTP/1.1 %d ", status_);

    buffer_.Append(buf);
    buffer_.Append(phrase_);
    buffer_.Append("\r\n");

    if(short_conn_)
        buffer_.Append("Connection: close\r\n");
    else
        buffer_.Append("Connection: keep alive\r\n");

    for(auto& it:headers_)
    {
        buffer_.Append(it.first);
        buffer_.Append(": ");
        buffer_.Append(it.second);
        buffer_.Append("\r\n");
    }
    buffer_.Append("\r\n");
}

void HttpResponse::WriteMsg2Buffer(std::string &msg) {
    buffer_.Append(msg);
}