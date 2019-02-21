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
    // 向 wakeup_fd_ 写一个字符 1，产生可读事件
    // 告知其他 looper 任务队列有事件要处理
    void Wakeup();

    // 响应别的进程发过来的唤醒动作，读 1 字符
    void HandleWakeup();

    void RunTask(Task&& t);
    void AddTask(Task&& t);
    void HandleTask();

    void RunTaskAfter(Task&& t, Nanosecond interval);

    bool IsInBaseThread() const { return thread_id_ == std::this_thread::get_id();}


private:
    bool exit_;
    bool is_handling_task_;
    // 唤醒描述符用来在其他 looper 上产生事件，使其从等待状态（poll）退出
    // 进而检查任务队列
    int wakeup_fd_;
    std::shared_ptr<EventBase> wakeup_eventbase_;

    const std::thread::id thread_id_;

    std::unique_ptr<Epollor> epollor_;

    std::unique_ptr<TimerQueue> timer_queue_;

    // 互斥访问任务队列
    std::mutex mutex_;
    // 任务队列
    // 每个线程都有一个任务队列，线程之间可以向对方任务队列中投放任务
    // 循环处理完一次任务后，确认任务队列为空才继续等待
    std::vector<Task> task_queue_;
};
#endif //AMNET_LOOP_H
