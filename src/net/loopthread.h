//
// Created by amisher on 18-12-11.
//

#ifndef AMNET_LOOPTHREAD_H
#define AMNET_LOOPTHREAD_H

#include <mutex>
#include <thread>
#include <condition_variable>

class Looper;

// LooperThread 把 Looper 和 线程绑定在一起
// 创建一个该类对象，就创建一个线程，并运行着一个 looper
// 所有这些线程由 threadpool 管理
class LooperThread{
public:
    LooperThread();
    ~LooperThread();

    Looper* GetLooper();
private:
    // 新创建线程执行的函数， 也就是开启looper
    void ThreadFunc();
    Looper *loop_;
    std::thread thread_;

    std::mutex mutex_;
    std::condition_variable condition_;
};

#endif //AMNET_LOOPTHREAD_H
