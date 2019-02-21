//
// Created by amisher on 18-12-8.
//

#include "util.h"
#include "logger.h"
#include "eventbase.h"
#include "epollor.h"


// 监听事件上限
const int EVENTS_MAX = 4096;
// wait超时时间
const int EPOLL_WAIT_TIME = 10000;


// 创建一个类对象，在内核创建一张内核事件表
Epollor::Epollor(): epoll_fd_(epoll_create1(EPOLL_CLOEXEC)), active_event_(EVENTS_MAX) {
    if(epoll_fd_ < 0)
    {
        LOG_FATAL<<"fail to create epoll_fd_ ";
    }
}

Epollor::~Epollor() {
    util::Close(epoll_fd_);
}

void Epollor::Add(std::shared_ptr<EventBase> eb) {

    int fd = eb->getFd();
    struct epoll_event event;
    event.events = (uint32_t)eb->getEvents();
    event.data.fd = fd;

    fd2eb[fd] = eb;
    // 注册到epoll事件表
    if(epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &event) < 0)
    {
        // 注册失败
        LOG_ERROR<<"fail to invoke epoll_ctl[ADD]";
        fd2eb.erase(fd);
    }
}

void Epollor::Mod(std::shared_ptr <EventBase> eb) {
    int fd = eb->getFd();
    struct epoll_event event;
    event.events = (uint32_t)eb->getEvents();
    event.data.fd = fd;

    if(epoll_ctl(epoll_fd_, EPOLL_CTL_MOD, fd, &event)<0)
    {
        LOG_ERROR<<"fail to invoke epoll_ctl[MOD]";
        fd2eb.erase(fd);
    }

}

void Epollor::Del(std::shared_ptr <EventBase> eb) {
    int fd = eb->getFd();
    struct epoll_event event;
    event.events = (uint32_t)eb->getEvents();
    event.data.fd = fd;

    if(epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, &event) < 0)
    {
        LOG_ERROR<< "fail to invoke epoll_ctl[DEL]";
    }
    fd2eb.erase(fd);
}

std::vector<std::shared_ptr<EventBase>> Epollor::Poll() {
    // active_event中接受活跃的epoll_event
    int active_event_count = epoll_wait(epoll_fd_, &*active_event_.begin(),
            (int)(active_event_.size()), EPOLL_WAIT_TIME);

    if(active_event_count<0)
    {
        LOG_ERROR <<"Error in epoll_wait";
    }

    std::vector<std::shared_ptr<EventBase>> active_events_list;
    for(int i=0; i<active_event_count; ++i)
    {
        //按就绪的socket，找对应的事件智能指针
        std::shared_ptr<EventBase> eb = fd2eb[active_event_[i].data.fd];
        active_events_list.push_back(eb);
    }
    return active_events_list;
}

