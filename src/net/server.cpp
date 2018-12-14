//
// Created by amisher on 18-12-13.
//


#include <string.h>
#include <functional>
#include "server.h"
#include "util.h"
#include "threadpool.h"
#include "eventbase.h"

Server::Server(Looper *loop, int port, int thread_num):
loop_(loop),
thread_pool_(new ThreadPool(loop_, thread_num)),
server_fd_(util::Create()){
    bzero(&addr_, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_.sin_port = htons((uint16_t)port);

    // 可重用地址
    util::SetReuseAddr(server_fd_);
    util::Bind(server_fd_, addr_);

    server_eb_ = std::make_shared<EventBase>(server_fd_);
    server_eb_->SetReadableCallback(std::bind(&Server::NewConn,this, std::placeholders::_1));
    server_eb_->Readable();
}

Server::~Server() {
    util::Close(server_fd_);
}

void Server::Start() {
    util::Listen(server_fd_);
    loop_->AddEventBase(server_eb_);
    thread_pool_->Start();
}

void Server::NewConn(TimeStamp t) {
    struct sockaddr_in peer_addr;
    bzero(&peer_addr, sizeof(peer_addr));
    int acc_fd = util::Accept(server_fd_, &peer_addr);

    // 从线程池中取一个线程分配给该连接
    Looper* io_loop = thread_pool_->Consume();
    std::shared_ptr<Connection> conn = std::make_shared<Connection>(io_loop, acc_fd, addr_, peer_addr);
    conn->SetConnCallback(conn_cb_);
    conn->SetMsgCallback(msg_cb_);
    conn->SetReplyCallback(reply_cb_);
    conn->SetCloseCallback(close_cb_);
    conn->SetSuicideCallback(std::bind(&Server::CloseConn4CB, this, std::placeholders::_1));

    fd_conn_map_[acc_fd] = conn;
    io_loop->RunTask(std::bind(&Connection::Register,  conn));
}

void Server::CloseConn4CB(const std::shared_ptr<Connection> &conn) {
    loop_->AddTask(std::bind(&Server::CloseConn, this, conn->GetConnFd()));
}

void Server::CloseConn(int conn_fd) {
    fd_conn_map_.erase(conn_fd);
}

