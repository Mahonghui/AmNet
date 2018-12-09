//
// Created by amisher on 18-12-9.
//

#ifndef AMNET_LOGFILE_H
#define AMNET_LOGFILE_H

#include <memory>
#include <string>
#include "util.h"

// 管理输出的日志
class LogFile{
public:
    explicit LogFile(const std::string& filename, int flush_every_t =1024);
    ~LogFile()= default;

    void Append(const char* str, size_t len);
    void Flush();

private:
    const std::string filename_;
    // 每append t次flush到磁盘
    const int flush_every_t_;
    // 记录append次数
    int count_;
    // 文件类，执行实际文件操作
    std::unique_ptr<File> file_;
};

#endif //AMNET_LOGFILE_H
