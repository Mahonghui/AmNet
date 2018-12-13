//
// Created by amisher on 18-12-13.
//

#include "threadpool.h"
#include "loop.h"
#include "loopthread.h"

ThreadPool::ThreadPool(Looper *base_loop, int threads_num):
base_loop_(base_loop),
threads_num_(threads_num),
next_(0){}

// 启动线程池，创建num个loop_thread放进线程池
void ThreadPool::Start() {
    for(int i=0; i<threads_num_;i++)
    {
        std::unique_ptr<LooperThread> t(new LooperThread());
        loopers_.push_back(t->GetLooper());
        looper_threads_.push_back(std::move(t));
    }
}

Looper* ThreadPool::Consume() {
    Looper* loop = base_loop_;

    if(!loopers_.empty()){
        loop = loopers_[next_];
        next_ = (next_ + 1)%threads_num_;
    }
    return  loop;
}