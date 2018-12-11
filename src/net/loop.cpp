//
// Created by amisher on 18-12-11.
//

#include <sys/eventfd.h>
#include <unistd.h>
#include "loop.h"
#include "eventbase.h"
#include "timerqueue.h"
#include "logger.h"

Looper::Looper():
exit_(false),
is_handling_task_(false),
wakeup_fd_(eventfd(0, EFD_NONBLOCK| EFD_CLOEXEC)),
wakeup_eventbase_(std::make_shared<EventBase>(wakeup_fd_)),
thread_id_(std::this_thread::get_id()),
timer_queue_(new TimerQueue(this))
{
    if(wakeup_fd_ < 0)
        LOG_FATAL<<"fail to create wakeup_fd_";
    // 监视可读事件
    wakeup_eventbase_->SetReadableCallback(std::bind(&Looper::HandleWakeup, this));
    wakeup_eventbase_->Readable();
    // 注册到epollor
    AddEventBase(wakeup_eventbase_);
}

Looper::~Looper()=default;

void Looper::Start() {
    std::vector<std::shared_ptr<EventBase>> active_eb_list;
    while (!exit_)
    {
        active_eb_list.clear();
        active_eb_list = epollor_->Poll();
        for(auto& it: active_eb_list)
        {
            it->EventHanlder();
        }
        HandleTask();
    }
}

void Looper::Wakeup() {
    uint64_t on = 1;
    ssize_t n = write(wakeup_fd_, &on, sizeof(on));
    if(n != sizeof(on))
    {
        LOG_ERROR << "wake up error in write()";
    }
}

void Looper::HandleWakeup() {
    uint64_t on = 1;
    ssize_t n = read(wakeup_fd_, &on, sizeof(on));
    if(n != sizeof(on))
        LOG_ERROR<<"handle wake up error in read()";
}

void Looper::RunTask(Looper::Task &&t) {
    if(IsInBaseThread())
        Task();
    else
        AddTask(std::move(t));
}

void Looper::AddTask(Looper::Task &&t) {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        task_queue_.emplace_back(std::move(t));
    }
    if(! IsInBaseThread() || is_handling_task_)
    {
        Wakeup();
    }
}

void Looper::HandleTask() {
    is_handling_task_ = true;
    std::vector<Task > tasks;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        tasks.swap(task_queue_);
    }

//    for(size_t i=0; i<tasks.size(); ++i)
//        tasks[i]();

    for(auto& task: tasks)
        task();

    is_handling_task_ = false;
}

void Looper::RunTaskAfter(Looper::Task &&t, Nanosecond interval) {
    timer_queue_->AddTimer(t, system_clock::now()+interval);
}