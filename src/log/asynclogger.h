//
// Created by amisher on 18-12-9.
//

#ifndef AMNET_ASYNCLOGGER_H
#define AMNET_ASYNCLOGGER_H

#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include "logbuf.h"

//异步处理日志
class AsyncLogger{
public:
    explicit  AsyncLogger(const std::string logfile, int flush_interval = 2);
    ~AsyncLogger(){
        if(is_running_)
            Stop();
    }

    void Append(const char* str, int len);
    void Start(){
        is_running_ = true;
        thread_ = std::thread(std::bind(&AsyncLogger::ThreadFunc, this));
    }
    void Stop(){
        is_running_ = false;
        // 通知将剩余内容输出
        condition_.notify_one();
        // 阻塞当前线程，直到和×this绑定的线程处理完毕
        // 由于使用单线程，也就是等自己处理完毕在再结束
        thread_.join();
    }

private:
    void ThreadFunc();

    typedef Buffer<MAX_BUF_SIZE> FixedBuffer;
    typedef std::vector<std::shared_ptr<FixedBuffer>> BufferVector;
    typedef std::shared_ptr<FixedBuffer> BufferPtr;

    const int flush_interval_;
    bool is_running_;
    std::string logfile_;
    // log线程
    std::thread thread_;
    // 互斥锁
    std::mutex mutex_;
    // 条件变量，定义缓冲区对log线程可用时的条件
    std::condition_variable condition_;

    BufferPtr cur_buffer_;
    BufferPtr next_buffer_;
    // 可供log线程使用的缓冲区列表
    BufferVector buffers_;
};

#endif //AMNET_ASYNCLOGGER_H
