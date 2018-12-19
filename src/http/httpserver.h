//
// Created by amisher on 18-12-18.
//

#ifndef AMNET_HTTPSERVER_H
#define AMNET_HTTPSERVER_H

#include "server.h"
#include "router.h"
#include "filehandler.h"

class HttpRequest;
class HttpResponse;
class HttpParser;

class HttpServer{
public:
    HttpServer(Looper* loop, int port,  int thread_num =1);
    void SetDefaultHandler(const Route::Handler& handler){default_handler_ = handler;}
    Route::RoutePtr NewRoute(){ return  router_.NewRoute(); }

    void Start();

    Route::Handler SetFileHandler(std::string& prefix){
        file_handler_.setFilePrefix(prefix);
        return file_handler_.GetHandler();
    }

private:
    void WhenConnect(const std::shared_ptr<Connection>& conn);
    void WhenRequest(const std::shared_ptr<Connection>& conn,HttpRequest& request);
    void WhenMessage(const std::shared_ptr<Connection>& conn, IOBuffer* buffer, TimeStamp t);
//    void WhenClose(const std::shared_ptr<Connection>& conn);

    Server server_;
    // 默认处理器
    Route::Handler default_handler_;
    // 路由分发器
    Router router_;
    // 负责处理文件
    FileHandler file_handler_;

};
#endif //AMNET_HTTPSERVER_H
