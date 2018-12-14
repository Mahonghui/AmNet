//
// Created by amisher on 18-12-13.
//

#ifndef AMNET_SERVER_H
#define AMNET_SERVER_H

#include <netinet/in.h> // for sockaddr_in
#include <memory>
#include <map>
#include "loop.h"
#include "iobuffer.h"
#include "connection.h"
#include "timestamp.h"

class ThreadPool;
class EventBase;

class Server{
public:
    Server(Looper* loop, int port, int thread_num =1);
    ~Server();

    void Start();

    void SetConnCallback(Connection::Callback&& cb){conn_cb_ = cb;}
    void SetMsgCallback(Connection::MessageCallback&& cb){msg_cb_=cb;}
    void SetReplyCallback(Connection::Callback&& cb){reply_cb_ = cb;}
    void SetCloseCallback(Connection::Callback&& cb){close_cb_ = cb;}

private:
    // 连接请求
    void NewConn(TimeStamp t);

    void CloseConn4CB(const std::shared_ptr<Connection>& conn);
    void CloseConn(int conn_fd);

    Looper* loop_;
    std::unique_ptr<ThreadPool> thread_pool_;

    const int server_fd_;
    struct sockaddr_in addr_;
    std::shared_ptr<EventBase> server_eb_;

    // 描述符到连接的映射，保存所有连接
    std::map<int, std::shared_ptr<Connection>> fd_conn_map_;

    // 连接建立、消息到达、回复、关闭回调函数
    Connection::Callback conn_cb_;
    Connection::MessageCallback msg_cb_;
    Connection::Callback reply_cb_;
    Connection::Callback close_cb_;

};

#endif //AMNET_SERVER_H
