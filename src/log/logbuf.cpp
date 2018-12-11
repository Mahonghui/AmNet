//
// Created by amisher on 18-12-8.
//

#include <string>
#include <string.h>
#include <stdint.h>
#include <algorithm>
#include "logbuf.h"

// 整形数字转字符
template <typename T>
size_t Itoa(char buf[], T v){
    char* p = buf;
    int res = 0;
    T n = v;
    if(n<0)
        n = -n;
    while (n)
    {
        *p++ = (n%10)+'0';
        n /= 10;
        if(n<10) {
            *p++ = n+'0';
            break;
        }
    }
    if(v<0)
        *p++ = '-';

    *p = '\0';
    std::reverse(buf, p);
    return p-buf;
}

template <typename T>
void LogStream::ParseInt(T v){
    if(buffer_.GetAvail() >= MAX_NUM_SIZE)
    {
        size_t len = Itoa(buffer_.GetCur(),v);
        buffer_.Seekp(len);
    }
}

LogStream& LogStream::operator<<(bool v) {
    buffer_.Append(v?"1":"0", 1);
    return *this;
}

LogStream&  LogStream::operator<<(short v) {
    // 提升
    *this<< static_cast<int>(v);
    return *this;
}

LogStream& LogStream::operator<<(int v) {
    ParseInt(v);
    return *this;
}
LogStream& LogStream::operator<<(long v)
{
    ParseInt(v);
    return *this;
}

LogStream& LogStream::operator<<(float v) {
    // 提升
    *this<< static_cast<double >(v);
    return *this;
}

LogStream& LogStream::operator<<(double v) {
    if(buffer_.GetAvail() > MAX_NUM_SIZE)
    {
        int  len = snprintf(buffer_.GetCur(), MAX_NUM_SIZE, "%.12g", v);
        buffer_.Seekp((size_t)len);
    }
    return  *this;
}

LogStream& LogStream::operator<<(char c) {
    buffer_.Append(&c, 1);
    return *this;
}

LogStream& LogStream::operator<<(const char* str) {
    if(str)
    {
        buffer_.Append(str, strlen(str));
    }
    else
    {
        buffer_.Append("NULL", 4);
    }
    return *this;
}

LogStream& LogStream::operator<<(std::string & str) {
    if(!str.empty())
        buffer_.Append(str.c_str(), str.size());
    else
        buffer_.Append("NULL", 4);
    return *this;
}







