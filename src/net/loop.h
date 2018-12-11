//
// Created by amisher on 18-12-10.
//

#ifndef AMNET_LOOP_H
#define AMNET_LOOP_H

#include <vector>
#include <memory>
#include <functional>
#include <mutex>
#include <thread>
#include "timestamp.h"
#include "epollor.h"

// 前向声明
class EventBase;
class TimerQueue;

class Looper{
public:
    using Task = std::function<void()>;
    Looper();
    ~Looper();


    void Start();
    void Exit(){ exit_=true; }

    // 注册事件
    void AddEventBase(std::shared_ptr<EventBase> eb){epollor_->Add(eb);}
    void ModEventBase(std::shared_ptr<EventBase> eb){epollor_->Mod(eb);}
    void DelEventBase(std::shared_ptr<EventBase> eb){epollor_->Del(eb);}

    // 唤醒循环处理task
    void Wakeup();
    void HandleWakeup();

    void RunTask(Task&& t);
    void AddTask(Task&& t);
    void HandleTask();

    void RunTaskAfter(Task&& t, Nanosecond interval);

    bool IsInBaseThread() const { return thread_id_ == std::this_thread::get_id();}


private:
    bool exit_;
    bool is_handling_task_;
    int wakeup_fd_;
    std::shared_ptr<EventBase> wakeup_eventbase_;

    const std::thread::id thread_id_;

    std::unique_ptr<Epollor> epollor_;

    std::unique_ptr<TimerQueue> timer_queue_;

    // 保护队列的互斥锁
    std::mutex mutex_;
    // 任务队列
    std::vector<Task> task_queue_;
};
#endif //AMNET_LOOP_H
