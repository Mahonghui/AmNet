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
    const int timer_fd_;
    std::shared_ptr<EventBase> timer_eventbase_;

    // 小根堆实现定时器队列
    using TimerPtr = std::shared_ptr<Timer>;
    std::priority_queue<Timer, std::vector<TimerPtr>, cmp> timer_queue_;
};

#endif //AMNET_TIMERQUEUE_H
