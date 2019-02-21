//
// Created by amisher on 18-12-10.
//

#ifndef AMNET_TIMERQUEUE_H
#define AMNET_TIMERQUEUE_H

#include <queue>
#include <vector>
#include <stdint.h>
#include <memory>
#include <functional>
#include "timer.h"

// 前向声明
class EventBase;
class Looper;

struct cmp{

    bool operator() (const std::shared_ptr<Timer>& lhs, const std::shared_ptr<Timer>& rhs){
        return lhs->GetExpireTime() > rhs->GetExpireTime();
    }
};

class TimerQueue{
public:
    explicit TimerQueue(Looper* loop);
    ~TimerQueue();

    void AddTimer(const std::function<void ()>& cb, TimeStamp when);
private:
    void ResetTimerFd(int fd, TimeStamp when);
    void HandleTimeExpired();
    Looper* loop_;

    // 定时器描述符用来将定时器整合到 looper 上，描述符的超时时间是时间队列队头的时间
    // 到达后就在该描述符产生可读事件，looper 处理队头上的 task
    // 然后更新为新的队头时间
    const int timer_fd_;

    std::shared_ptr<EventBase> timer_eventbase_;


    using TimerPtr = std::shared_ptr<Timer>;
    // 小根堆实现定时器队列
    std::priority_queue<Timer, std::vector<TimerPtr>, cmp> timer_queue_;
};

#endif //AMNET_TIMERQUEUE_H
