//
// Created by amisher on 18-12-9.
//

#include <stdio.h>
#include <unistd.h>
#include <functional>
#include <chrono>
#include "asynclogger.h"
#include "logfile.h"

AsyncLogger::AsyncLogger(const std::string logfile, int flush_interval):
flush_interval_(flush_interval),
is_running_(false),
logfile_(logfile),
thread_(),
mutex_(),
condition_(),
cur_buffer_(new FixedBuffer),
next_buffer_(new FixedBuffer),
buffers_(){
    cur_buffer_->Clear();
    next_buffer_->Clear();
    buffers_.reserve(16);
}

void AsyncLogger::Append(const char *str, int len) {
    std::unique_lock<std::mutex> lock(mutex_);

    if(cur_buffer_->GetAvail() > len)
        cur_buffer_->Append(str,(size_t)len);
    else
    {
        // 缓冲区已经满了
        //  当前的存下来
        buffers_.push_back(cur_buffer_);
        // cur_buffer 置空
        cur_buffer_.reset();
        // 如果下一个缓冲区可用
        if(next_buffer_)
        {
            cur_buffer_ = std::move(next_buffer_);
        }

        cur_buffer_->Append(str, (size_t)len);
        // 通知log
        condition_.notify_one();
    }
}

void AsyncLogger::ThreadFunc() {
    LogFile output(logfile_);

    BufferPtr back_buffer1(new FixedBuffer);
    BufferPtr back_buffer2(new FixedBuffer);
    back_buffer1->Clear();
    back_buffer2->Clear();

    BufferVector buffers_write;
    buffers_write.reserve(16);

    while (is_running_)
    {
        {
            std::unique_lock<std::mutex>lock(mutex_);
            if(buffers_.empty())
            {
                condition_.wait_for(lock, std::chrono::seconds(flush_interval_));
            }

            buffers_.push_back(cur_buffer_);
            cur_buffer_.reset()();
            cur_buffer_ = std::move(back_buffer1);

            // 把buffers 和专门读取的vector交换
            buffers_write.swap(buffers_);

            // 如果下一个缓冲区为空，就把log线程的缓冲区2交给next
            if(!next_buffer_)
            {
                next_buffer_ = std::move(back_buffer2);
            }

            // 缓冲区过多，生产比消费快
            if(buffers_write.size() > 25)
            {
                // 丢弃，保留两个空间给1和2
                buffers_write.erase(buffers_write.begin()+2, buffers_write.end());
            }

            for(std::shared_ptr<FixedBuffer>& i: buffers_write)
            {
                output.Append(i->GetData(), (size_t)i->GetLen());
            }

            // 丢弃多余的缓冲区
            if(buffers_write.size()>2)
            {
                buffers_write.resize(2);
            }
            // 恢复备用缓冲区
            if(!back_buffer1)
            {
                back_buffer1 = buffers_write.back();
                buffers_write.pop_back();
                back_buffer1->Reset();
            }

            if(!back_buffer2)
            {
                back_buffer2 = buffers_write.back();
                buffers_write.pop_back();
                back_buffer2->Reset();
            }

            // 清空缓冲区列表
            buffers_write.clear();
            output.Flush();
        }
        output.Flush();
    }
}

