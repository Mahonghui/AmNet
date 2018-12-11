//
// Created by amisher on 18-12-9.
//

#ifndef AMNET_UTIL_H
#define AMNET_UTIL_H

#include <string>

class File{
public:
    explicit File(const std::string& filename);
    ~File();

    void Append(const char* str, size_t len);

    void Flush();

private:
    // 写函数，非线程安全
    size_t Write(const char* str, size_t len);
    FILE* fp_;
    // 文件缓冲区
    char buf_[1024*128];
};
#endif //AMNET_UTIL_H
