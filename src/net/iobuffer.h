//
// Created by amisher on 18-12-9.
//

#ifndef AMNET_IOBUFFER_H
#define AMNET_IOBUFFER_H

#include <string.h>
#include <string>
#include <endian.h>
#include <arpa/inet.h>
#include <algorithm>
#include <vector>

class IOBuffer{

public:
    // 缓冲区头
    static const size_t PREPEND_SIZE = 8;
    // 缓冲区初始大小
    static const size_t INITIAL_SIZE = 1024;
    // 换行符
    static const char CRLF[];

    explicit IOBuffer(size_t init = INITIAL_SIZE):
    buffer_(PREPEND_SIZE+init), read_index_(PREPEND_SIZE), write_index_(PREPEND_SIZE)
    {}

    //交换缓冲区
    void Swap(IOBuffer& rhs){
        buffer_.swap(rhs.buffer_);
        std::swap(read_index_, rhs.read_index_);
        std::swap(write_index_, rhs.write_index_);
    }
    // 获取可读、可写、预留区的大小
    size_t GetReadableSize() const{ return write_index_ - read_index_;}
    size_t GetWriteableSize() const { return buffer_.size() - write_index_;}
    size_t GetPrependSize() const { return read_index_;}

    // 获取可读、可写区的指针
    const char* GetReadablePtr()const { return GetBegin() + read_index_;}
    const char* GetWriteablePtr() const { return GetBegin() + write_index_;}
    char* GetWriteablePtr() { return GetBegin()+write_index_;}


    const char* FindCRLF() const {
        const char* crlf = std::search(GetReadablePtr(),GetWriteablePtr(), CRLF,CRLF+2);
        return crlf == GetReadablePtr()?nullptr:crlf;
    }

    const char* FindCRLF(const char* start)const {
        const char* crlf = std::search(start, GetWriteablePtr(), CRLF, CRLF+2);
        return crlf == GetWriteablePtr()?nullptr:crlf;
    }

    const char* FindEOL(const char* start)const{
        const void* eol = memchr(start, '\n', GetReadablePtr() - start);
        return static_cast<const char*> (eol);
    }

    // 读数据时，用来更新read_index_
    void Retrieve(size_t len)
    {
        if(len < GetReadableSize())
        {
            read_index_ += len;
        } else{
            // len == GetReadSize()
            RetrieveAll();
        }
    }

    void RetrieveAll(){
        read_index_ = PREPEND_SIZE;
        write_index_ = PREPEND_SIZE;
    }

    void RetrieveUntil(const char* end){
        Retrieve(end - GetReadablePtr());
    }

    std::string RetrieveAsString(size_t len){
        std::string aux(GetReadablePtr(), len);
        Retrieve(len);// 前移更新的位置
        return aux;
    }

    std::string RetrieveAllAsString(){
        return RetrieveAsString(GetReadableSize());
    }

    // 确保至少有len可写空间
    void EnsureWriteable(size_t len){
        if(GetWriteableSize() < len)
        {
            MakeRoom(len);
        }
    }

    // 填数据
    void Append(const char* data, size_t len){
        if(GetWriteableSize() < len){
            MakeRoom(len);
        }
        std::copy(data, data+len, GetWriteablePtr());
        write_index_ += len;
    }

    void Append(const void* data, size_t len){
        Append(static_cast<const char*>(data), len);
    }

    void Append(const std::string& data){
        Append(data.c_str(), data.size());
    }

    void Shrink(size_t len){
        IOBuffer temp;
        temp.EnsureWriteable(GetReadableSize() + len);
        temp.Append(GetReadablePtr(), GetReadableSize());
        Swap(temp);
    }

    size_t GetCapacity()const { return buffer_.capacity();}

    ssize_t ReadIntoFd(int fd, int * saved_errno);



private:
    char* GetBegin(){ return &*buffer_.begin();}
    const char* GetBegin() const { return  &*buffer_.begin();}

    // 调整足够的空间，至少len
    void MakeRoom(size_t len)
    {
        if(GetWriteableSize() + GetPrependSize() < len + PREPEND_SIZE)
            buffer_.resize(write_index_+len);
        else{
            size_t readable = GetReadableSize();
            // 整体向前挪动到头部
            std::copy(GetBegin()+read_index_, GetBegin()+write_index_, GetBegin()+PREPEND_SIZE);
            read_index_ = PREPEND_SIZE;
            write_index_ = readable + read_index_;
        }
    }

    // 数据缓冲区
    std::vector<char> buffer_;
    // 可读位置
    size_t read_index_;
    //可写位置
    size_t write_index_;
};

#endif //AMNET_IOBUFFER_H
