//
// Created by amisher on 18-12-12.
//

#include <unistd.h>
#include "connection.h"
#include "eventbase.h"
#include "logger.h"
#include "loop.h"
#include "util.h"

Connection::Connection(Looper *loop, int conn_fd, const struct sockaddr_in &local_addr,
                       const struct sockaddr_in &peer_addr):
                               loop_(loop), sock_fd_(conn_fd),
                               conn_eb_(new EventBase(sock_fd_)),
                               local_addr_(local_addr),
                               peer_addr_(peer_addr),
                               context_(nullptr){
    conn_eb_->SetReadableCallback(std::bind(&Connection::ReadHandler, this,std::placeholders::_1));
    conn_eb_->setWriteableCallback(std::bind(&Connection::WriteHandler,this));
    conn_eb_->setCloseCallback(std::bind(&Connection::CloseHandler, this));
    conn_eb_->Writeable();
}

Connection::~Connection() {
    util::Close(sock_fd_);
}
// 连接建立时为线程分配事件
void Connection::Register() {
    loop_->AddEventBase(conn_eb_);
    if(conn_cb_)
        conn_cb_(shared_from_this());
}

// send
void Connection::Send(const void *data, size_t len) {
    ssize_t n =0;
    //缓冲区为空时直接写
    if(!conn_eb_->isWriting()&&tx_buffer_.GetReadableSize() == 0)
    {
        n = write(conn_eb_->getFd(), data, len);
        if(n >=0) {
            if ((size_t) (n) == len && reply_cb_) {
                // 数据已经写完
                reply_cb_(shared_from_this());
            }
        }
        else
            {
                n=0;
                if(errno != EWOULDBLOCK)
                    LOG_ERROR<<"Unexpected error in write";
            }
        }
    // 缓冲区不满
    if((size_t)n < len)
    {
        tx_buffer_.Append(static_cast<const char*>(data)+n, len-n);
        if(!conn_eb_->isWriting())
        {
            conn_eb_->Readable();
            loop_->ModEventBase(conn_eb_);
        }
    }
}

void Connection::Send(const std::string &msg){
    Send(msg.data(), msg.size());
}

void Connection::Send(IOBuffer &buffer) {
    Send(buffer.GetReadablePtr(), buffer.GetReadableSize());
    buffer.RetrieveAll();
}

void Connection::Shutdown() {
    if(!conn_eb_->isWriting())
        util::Shutdown(sock_fd_);
}

void Connection::ReadHandler(TimeStamp t) {
    int saved_errno = 0;
    ssize_t n = 0;

    n = rx_buffer_.ReadIntoFd(conn_eb_->getFd(), &saved_errno);
    if(n>0){
        if(msg_cb_)
            msg_cb_(shared_from_this(), &rx_buffer_, t);
    } else
        CloseHandler();
}

void Connection::WriteHandler() {
    if(conn_eb_->isWriting()){
        ssize_t n = write(conn_eb_->getFd(), tx_buffer_.GetReadablePtr(), tx_buffer_.GetReadableSize());
        if(n>0){
            tx_buffer_.Retrieve(n);
            if(tx_buffer_.GetReadableSize() == 0){
                conn_eb_->unWriteable();
                loop_->ModEventBase(conn_eb_);
                if(reply_cb_)
                    reply_cb_(shared_from_this());
            }
        } else
            LOG_ERROR<<"Unexpected error in write";
    }
}

void Connection::CloseHandler() {
    loop_->DelEventBase(conn_eb_);
    if(close_cb_)
        close_cb_(shared_from_this());
    if(suicide_cb_)
        suicide_cb_(shared_from_this());
}

