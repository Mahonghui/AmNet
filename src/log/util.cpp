//
// Created by amisher on 18-12-9.
//

#include <string.h>
#include <stdio.h>
#include "util.h"

File::File(const std::string& filename){
    if((fp_ = fopen(filename.c_str(), "ae")) == nullptr)
        printf("fail to open logfile: %d[%s]", errno, strerror(errno));
    setbuffer(fp_, buf_, sizeof(buf_));
}

File::~File() {
    fclose(fp_);
}

void File::Append(const char *str, size_t len) {
    size_t  n = Write(str, len);
    // 数据一次可能写不完
    size_t remain = len - n;
    while (remain>0)
    {
        size_t temp = Write(str+n, remain);
        if(temp == 0)
        {
            int e = ferror(fp_);
            if(e)
                fprintf(stderr, "Append error: %d[%s]", errno, strerror(errno));
            break;
        }

        n += temp;
        remain = len - n;
    }
}

void File::Flush() {
    fflush(fp_);
}

size_t File::Write(const char *str, size_t len) {
    // 只使用一个log线记录日志，因此不要求线程安全性
    return fwrite_unlocked(str,1,len, fp_);
}