//
// Created by 马宏辉 on 2018-12-08.
//

#ifndef AMNET_EVENTBASE_H
#define AMNET_EVENTBASE_H

#include <sys/epoll.h>
#include <functional>
#include "timestamp.h"

class EventBase{
public:
    // 类似闭包函数，包装好的函数赋给一个变量
    using callback = std::function<void()>;
    using read_callback = std::function<void (TimeStamp)>;

    EventBase(int fd);
    ~EventBase();

    // 关联读写事件
    void Readable(){
        events_ |= (EPOLLIN | EPOLLPRI);
    }
    void Writeable(){
        events_ |= (EPOLLOUT);
    }

    // 解除事件关联
    void unReadble(){
        events_ &= ~(EPOLLIN|EPOLLPRI);
    }
    void unWriteable(){
        events_ &= ~(EPOLLOUT);
    }

    // 定义事件处理函数
    void SetReadableCallback(read_callback&& cb){read_callback_ = cb;}
    void setWriteableCallback(callback&& cb){write_callback_ = cb;}
    void setErrorCallback(callback&& cb){error_callback_ = cb;}
    void setCloseCallback(callback&& cb){close_callback_ = cb;}

    // 设置活跃事件
    void SetRevents(int revent){retevent_ = revent;}

    // 事件分发器
    void EventHanlder();

    // getter
    int getFd() const { return  fd_;}
    int getEvents(){ return events_;}
    bool isWriting() const { return events_&EPOLLOUT;}

private:
    const int fd_;
    int events_;
    int retevent_;

    read_callback read_callback_;
    callback write_callback_;
    callback error_callback_;
    callback close_callback_;
};

#endif //AMNET_EVENTBASE_H
