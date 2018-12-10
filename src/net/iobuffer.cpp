//
// Created by amisher on 18-12-10.
//

#include <sys/uio.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "iobuffer.h"

const size_t IOBuffer::PREPEND_SIZE;
const size_t IOBuffer::INITIAL_SIZE;
const char IOBuffer::CRLF[] = "\r\n";


ssize_t IOBuffer::ReadIntoFd(int fd, int *saved_errno) {
    char ex_buf[UINT16_MAX];
    struct iovec vec[2];
    const size_t writeable = GetWriteableSize();
    vec[0].iov_base = GetBegin() + write_index_;
    vec[0].iov_len = writeable;
    vec[1].iov_base = ex_buf;
    vec[1].iov_len = sizeof(ex_buf);

    // 如果缓冲区大于ex_buf, 则使用缓冲区,否则使用ex_buf
    const int iov_idx = (writeable > sizeof(ex_buf))?1:2;
    const ssize_t n = readv(fd, vec, iov_idx);
    if(n<0)
        *saved_errno = errno;
    else
        if((size_t)(n) <= writeable)
            write_index_ += n;
        else{
            // 要写的数据比缓冲区可写空间大
            write_index_ = buffer_.size();
            // append 会扩充空间
            Append(ex_buf,n-writeable);
        }

    return n;
}
