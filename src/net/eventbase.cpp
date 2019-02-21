//
// Created by 马宏辉 on 2018-12-08.
//

#include "eventbase.h"
#include "logger.h"

EventBase::EventBase(int fd):fd_(fd), events_(EPOLLRDHUP), retevent_(0){}
EventBase::~EventBase()=default;
void EventBase::EventHanlder() {

    if((retevent_ & EPOLLHUP) && !(retevent_& EPOLLIN))
    {
        //EPOLLHUP 不代表正常的关闭，而是服务器错误
        if(close_callback_)
            close_callback_();
        return;
    }

    // 客户端断开连接
    if(retevent_ & EPOLLRDHUP)
    {
        // EPOLLRDHUP 对端关闭连接
        if(close_callback_)
            close_callback_();
        return;
    }

    //出错
    if(retevent_ & EPOLLERR )
    {
        if(error_callback_)
            error_callback_();
        if(close_callback_)
            close_callback_();
        return;
    }

    //可读事件
    if(retevent_ & (EPOLLIN | EPOLLPRI | EPOLLHUP))
    {
        if(read_callback_)
            read_callback_(system_clock::now());
    }

    // 可写事件
    if(retevent_ & (EPOLLOUT))
    {
        if(write_callback_)
            write_callback_();
    }
}
