//
// Created by amisher on 18-12-11.
//

#ifndef AMNET_LOOPTHREAD_H
#define AMNET_LOOPTHREAD_H

#include <mutex>
#include <thread>
#include <condition_variable>

class Looper;

class LooperThread{
public:
    LooperThread();
    ~LooperThread();

    Looper* GetLooper();
private:
    // 新创建线程执行的函数， 也就是开启looper
    void ThreadFunc();
    Loooper *loop_;
    std::thread thread_;

    std::mutex mutex_;
    std::condition_variable condition_;
};

#endif //AMNET_LOOPTHREAD_H
