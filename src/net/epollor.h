//
// Created by amisher on 18-12-8.
//

#ifndef AMNET_EPOLLOR_H
#define AMNET_EPOLLOR_H


#include <sys/epoll.h>
#include <vector>
#include <map>
#include <memory>

class EventBase;

class Epollor{
public:
    Epollor();
    ~Epollor();

    // 注册，修改，删除事件
    void Add(std::shared_ptr<EventBase> eb);
    void Mod(std::shared_ptr<EventBase> eb);
    void Del(std::shared_ptr<EventBase> eb);


    // 等待事件
    std::vector<std::shared_ptr<EventBase>> Poll();

private:
    // epoll描述符，标识内核中的epoll事件表
    int epoll_fd_;
    // 负责接受epoll_wait返回的就绪事件
    std::vector<epoll_event> active_event_;
    // socket到eventbase的映射，根据就绪的socket找到具体的事件处理器
    std::map<int, std::shared_ptr<EventBase>> fd2eb;
};
#endif //AMNET_EPOLLOR_H
