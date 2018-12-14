//
// Created by amisher on 18-12-12.
//

#ifndef AMNET_CONNECTION_H
#define AMNET_CONNECTION_H

#include <functional>
#include <memory>
#include "iobuffer.h"
#include "timestamp.h"
#include "anyone.h"

class EventBase;
class Looper;

class Connection:public std::enable_shared_from_this<Connection>{
public:
    using Callback = std::function<void (const std::shared_ptr<Connection>&)>;
    using MessageCallback = std::function<void(const std::shared_ptr<Connection>&, IOBuffer*, TimeStamp)>;

    Connection(Looper* loop, int conn_fd, const struct sockaddr_in& local_addr, const struct sockaddr_in& peer_addr);
    ~Connection();

    // 关联事件，连接建立时调用
    void Register();

    // send函数重载
    void Send(const void* data, size_t len);
    void Send(const std::string& msg);
    void Send(IOBuffer& buffer);

    // 关闭读写
    void Shutdown();

    // 处理事件
    void ReadHandler(TimeStamp t);
    void WriteHandler();
    void CloseHandler();

    // 设置回调
    void SetConnCallback(const Callback& cb){conn_cb_ = cb;}
    void SetMsgCallback(const MessageCallback & cb){msg_cb_ = cb;}
    void SetReplyCallback(const Callback& cb){reply_cb_ = cb;}
    void SetCloseCallback(const Callback& cb){close_cb_ = cb;}
    void SetSuicideCallback(const Callback& cb){suicide_cb_ = cb;}

    const int GetConnFd()const { return sock_fd_;}
    const IOBuffer& GetTxBuffer()const { return tx_buffer_;}
    const IOBuffer& GetRxBuffer()const { return rx_buffer_;}


    void SetContext(const Any& context){context_ = context;}
    const Any& GetContext() const { return context_;}
    Any* GetMutableContext() { return &context_;}

private:
    Looper* loop_;
    const int sock_fd_;
    std::shared_ptr<EventBase> conn_eb_;

    struct sockaddr_in local_addr_;
    struct sockaddr_in peer_addr_;
    // 连接建立、可读、可写、关闭、自关闭的回调函数
    Callback conn_cb_;
    MessageCallback msg_cb_;
    Callback reply_cb_;
    Callback close_cb_;
    Callback suicide_cb_;

    //输入输出缓冲区
    IOBuffer rx_buffer_;
    IOBuffer tx_buffer_;

    // 解析上下文
    Any context_;
};

#endif //AMNET_CONNECTION_H
