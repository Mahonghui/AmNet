//
// Created by amisher on 18-12-9.
//

#include "logfile.h"
#include "util.h"

LogFile::LogFile(const std::string &filename, int flush_every_t):
filename_(filename), flush_every_t_(flush_every_t),count_(0){
    file_= std::make_unique<File>(filename);
}

void LogFile::Append(const char *str, size_t len) {
    //调用File类的Append方法
    file_->Append(str, len);
    ++count_;
    if(count_ == flush_every_t_)
    {
        file_->Flush();
        count_ = 0;
    }
}

void LogFile::Flush() {
    file_->Flush();
}

