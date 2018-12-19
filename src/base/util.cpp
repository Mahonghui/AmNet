//
// Created by amisher on 18-12-8.
//

#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include <algorithm>
#include "util.h"
#include "logger.h"

int util::Create() {
    int fd = socket(AF_INET, SOCK_STREAM,0);
    if(fd < 0)
    {
        LOG_ERROR<<"fail to create socket";
    }
    return fd;
}

void util::Bind(int fd, const struct sockaddr_in &addr) {
    int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));

    if(ret<0)
    {
        LOG_ERROR<<"fail to bind";
    }
}

void util::Listen(int lfd) {
    if(listen(lfd, SOMAXCONN) < 0)
    {
        LOG_ERROR<<"fail to listen";
    }
}

void util::Connect(int fd, const struct sockaddr_in &addr) {
    if(connect(fd, (struct sockaddr*)&addr, sizeof(addr))<0)
    {
        LOG_ERROR<<"fail to connect";
    }
}

int util::Accept(int lfd, struct sockaddr_in *addr) {
    socklen_t addrlen = sizeof(addr);
    int client_fd = accept4(lfd, (struct sockaddr*)&addr, &addrlen, SOCK_NONBLOCK|SOCK_CLOEXEC);

    if(client_fd<0)
    {
        int saved_erron = errno;
        LOG_ERROR<<"fail to accept client";
        switch (saved_erron)
        {
            case EAGAIN:
            case ECONNABORTED:
            case EINTR:
            case EPROTO:
            case EPERM:
            case EMFILE:
                errno = saved_erron;
                break;
            case EBADF:
            case EFAULT:
            case EINVAL:
            case ENFILE:
            case ENOBUFS:
            case ENOMEM:
            case ENOTSOCK:
            case EOPNOTSUPP:
                LOG_FATAL<<"Unexpected error"<<saved_erron;
                break;
            default:
                LOG_FATAL<<"Unknown error"<<saved_erron;
                break;
        }
    }
    return client_fd;
}


void util::Close(int fd) {
    if(close(fd)<0)
    {
        LOG_ERROR<<"fail to close socket";
    }
}

void util::Shutdown(int fd) {
    if(shutdown(fd,SHUT_WR)<0)
    {
        LOG_ERROR<<"fail to shutdown socket's write";
    }
}


void util::SetReuseAddr(int fd) {
    int on = 1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&on, sizeof(on));
}

std::string util::StrpLocalTime(TimeStamp time) {
    char buf[32];
    time_t tt = system_clock::to_time_t(time);
    struct tm tms;
    localtime_r(&tt,&tms);
    snprintf(buf, sizeof(buf), "%4d%02d%02d %02d%02d%02d",
            tms.tm_year+1900,
            tms.tm_mon+1,
            tms.tm_mday,
            tms.tm_hour,
            tms.tm_min,
            tms.tm_sec);
    return std::string(buf, sizeof(buf));
}

std::string util::StrpGMTime(TimeStamp time) {
    char buf[32];
    time_t tt = system_clock::to_time_t(time);
    struct tm tms;
    gmtime_r(&tt, &tms);
    strftime(buf, sizeof(buf),"%a, %d %b %Y %H:%M:%S GMT", &tms);
    return std::string(buf, sizeof(buf));
}

TimeStamp util::StrfTime(struct timespec &ts) {
    return TimeStamp(Nanosecond((long int)ts.tv_sec * std::nano::den + ts.tv_nsec));
}

void util::ToUpperCase(std::string &str) {
    std::transform(str.begin(), str.end(),str.begin(),(int (*)(int)) toupper);
}

void util::ToLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), (int (*)(int)) tolower);
}