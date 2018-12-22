//
// Created by amisher on 18-12-12.
//

#include "loop.h"
#include "loopthread.h"

LooperThread::LooperThread():
loop_(nullptr),
thread_(std::bind(&LooperThread::ThreadFunc, this)),
mutex_(),
condition_(){}

LooperThread::~LooperThread() {
    loop_->Exit();
    thread_.join();
}

Looper* LooperThread::GetLooper() {

    // 条件变量+互斥锁，确保安全获得looper
    // 单独一个语句块形成临界区
    {
        std::unique_lock<std::mutex> lock(mutex_);
        while (loop_ == nullptr)
        {
            condition_.wait(lock);
        }
    }// 区块结束自动析构lock，释放互斥锁
    return  loop_;
}

void LooperThread::ThreadFunc() {
    Looper loop;
    // 获得锁的临界区
    {
        std::unique_lock<std::mutex> lock(mutex_);
        loop_ = &loop;
        condition_.notify_one();// 得到一个looper了，通知wait
    }
    loop.Start();
}