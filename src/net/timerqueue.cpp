//
// Created by amisher on 18-12-10.
//

#include <string.h>
#include <unistd.h>
#include <ratio>
#include <sys/timerfd.h>
#include "loop.h"
#include "timer.h"
#include "timerqueue.h"
#include "util.h"
#include "logger.h"
#include "eventbase.h"


TimerQueue::TimerQueue(Looper *loop):loop_(loop),
timer_fd_(timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK|TFD_CLOEXEC)),
timer_eventbase_(std::make_shared<EventBase>(timer_fd_)){

    timer_eventbase_->SetReadableCallback(std::bind(&TimerQueue::HandleTimeExpired, this));
    timer_eventbase_->Readable();
    loop->AddEventBase(timer_eventbase_);
}

TimerQueue::~TimerQueue() {
    util::Close(timer_fd_);
}

void TimerQueue::AddTimer(const std::function<void()> &cb, TimeStamp when) {
    auto timer = std::make_shared<Timer>(cb, when);
    // 新的定时器小于堆顶定时器,更新timer_fd_ 的到期时间
    if(timer_queue_.empty() || timer->GetExpireTime() < timer_queue_.top()->GetExpireTime())
    {
        ResetTimerFd(timer_fd_, timer->GetExpireTime());
    }

    timer_queue_.push(timer);
}

void TimerQueue::ResetTimerFd(int fd, TimeStamp when) {
    struct timespec ts;
    Nanosecond diff = when - system_clock::now();
    ts.tv_sec = static_cast<time_t >(diff.count() / std::nano::den);
    ts.tv_nsec = diff.count() % std::nano::den;

    struct itimerspec newv, oldv;
    bzero(&newv, sizeof(newv));
    bzero(&oldv, sizeof(oldv));

    newv.it_value = ts;
    timerfd_settime(fd, 0, &newv, &oldv);
}

void TimerQueue::HandleTimeExpired() {
    uint64_t exp_c;
    ssize_t n = read(timer_fd_, &exp_c, sizeof(exp_c));
    if( n != sizeof(exp_c))
    {
        LOG_ERROR<<"fail to read";
    }
    // 处理所有过期定时器
    TimeStamp now(system_clock::now());
    while (!timer_queue_.empty() && timer_queue_.top()->GetExpireTime() < now)
    {
        timer_queue_.top()->Run();
        timer_queue_.pop();
    }
    //
    if(!timer_queue_.empty())
    {
        ResetTimerFd(timer_fd_, timer_queue_.top()->GetExpireTime());
    }

}

