//
// Created by amisher on 18-12-8.
//

#ifndef AMNET_LOGBUF_H
#define AMNET_LOGBUF_H

#include <string>
#include <string.h>

const int MIN_BUF_SIZE = 1024;
const int MAX_BUF_SIZE = 1000*1024;

// 缓冲区模板类

template <int SIZE>
class Buffer{
public:
    Buffer():cur_(data_){}

    void Append(const char* buf, size_t len){
        if(GetAvail() > static_cast<int>len)
        {
            memcpy(cur_, buf, len);
            Seekp(len);
        }
    }

    void Seekp(size_t len){
        cur_ += len;
    }

    void Clear(){bzero(data_,sizeof(data_));}

    void Reset(){cur_ = data;}

    const char* GetData() const { return data_;}
    int GetLen()const { return static_cast<int>(cur_ - data);}

    char* GetCur(){ return cur_;}

    int GetAvail()const { return static_cast<int>(GetEnd() - cur_);}

private:
    const char* getEnd()const { return data_+ sizeof(data_);}
    // 存储数据的数组
    char data_[SIZE];
    // 超尾指针
    char* cur_;
};

// 日志流
class LogStream{
public:
    typedef Buffer<MIN_BUF_SIZE> FixedBuffer;

    // 输出流重载
    LogStream&operator<<(bool);
    LogStream&operator<<(short);
    LogStream&operator<<(int);
    LogStream&operator<<(long);
    LogStream&operator<<(float);
    LogStream&operator<<(double);
    LogStream&operator<<(char);
    LogStream&operator<<(const char*);
    LogStream&operator<<(std::string&);

    void Append(const char* data, size_t len){
        buffer_.Append(data, len);
    }

    const FixedBuffer& GetBuffer() const { return buffer_;}
private:
    FixedBuffer buffer_;

    template <class T>
    void ParseInt(T);
    static const int MAX_NUM_SIZE = 32;
};
#endif //AMNET_LOGBUF_H
