//
// Created by amisher on 18-12-8.
// 对一些socket的系统调用进行一些封装
//

#ifndef AMNET_UTIL_H
#define AMNET_UTIL_H

#include <arpa/inet.h>
#include <string>
#include "timestamp.h"

namespace util{

    int Create();
    void Bind(int fd, const struct sockaddr_in& addr);
    void Listen(int lfd);
    void Connect(int fd, const struct sockaddr_in& addr);
    int Accept(int lfd, struct sockaddr_in* addr);
    void Close(int fd);
    void Shutdown(int fd);
    void SetReuseAddr(int fd);

    std::string StrpLocalTime(TimeStamp time);
    std::string StrpGMTime(TimeStamp time);
    TimeStamp StrfTime(struct timespec& ts);


    void ToUpperCase(std::string& str);
    void ToLowerCase(std::string& str);
}
#endif //AMNET_UTIL_H
