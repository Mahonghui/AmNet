//
// Created by amisher on 18-12-13.
//

#ifndef AMNET_THREADPOOL_H
#define AMNET_THREADPOOL_H

#include <memory>
#include <vector>

class Looper;
class LooperThread;

class ThreadPool{
public:
    ThreadPool(Looper* base_loop, int threads_num);
    ~ThreadPool();

    void Start();

    Looper* Consume();
private:
    // 线程池本身所在的线程
    Looper* base_loop_;
    // 线程池中线程数量
    int threads_num_;
    // 要取出的下一个位置
    int next_;

    std::vector<std::unique_ptr<LooperThread>> looper_threads_;
    std::vector<Looper*> loopers_;
};

#endif //AMNET_THREADPOOL_H
