//
// Created by amisher on 18-12-18.
//

#include "httpserver.h"
#include "httpparser.h"
#include "httprequest.h"
#include "httpresponse.h"

void PageNotFoundHandler(const HttpRequest& request, std::unordered_map<std::string, std::string>& dict, HttpResponse* response){
    response->SetStatusCode(HttpResponse::NOT_FOUND);
    response->SetStatusPhrase("Not Found");
    response->SetContentType("text/html");
    response->SetCloseConn(true);

    std::string body = "404 Page Not Found";
    response->AddHeader("Content-Length", std::to_string(body.size()));
    response->WriteHeader2Buffer();
    response->WriteMsg2Buffer(body);
}

HttpServer::HttpServer(Looper *loop, int port, int thread_num):
server_(loop, port, thread_num),
default_handler_(PageNotFoundHandler){
    server_.SetConnCallback(std::bind(&HttpServer::WhenConnect, this, std::placeholders::_1));
    server_.SetMsgCallback(std::bind(&HttpServer::WhenMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
//    server_.SetCloseCallback(std::bind(&HttpServer::WhenClose, this, std::placeholders::_1));
}


void HttpServer::Start() {server_.Start();}


void HttpServer::WhenConnect(const std::shared_ptr<Connection> &conn) {
    conn->SetContext((Any)HttpParser());
}

void HttpServer::WhenMessage(const std::shared_ptr<Connection> &conn, IOBuffer *buffer, TimeStamp t) {
    auto parser = any_cast<HttpParser>(conn->GetMutableContext());

    bool ret = parser->ParseRequest(buffer, t);
    if(!ret){
        conn->Send("HTTP/1.1 Bad Request \r\n\r\n");
        conn->Shutdown();
    }

    if(parser->IsFinished()){
        // 处理完毕后重置解析器状态
        WhenRequest(conn,parser->GetRequest());
    }
}

void HttpServer::WhenRequest(const std::shared_ptr<Connection> &conn, HttpRequest &request) {
    std::string conn_str = request.GetHeader("Connection");
    bool is_close = (conn_str == "close") || (request.GetVerison() == HttpRequest::Version::HTTP10 && conn_str != "keep-alive");

    HttpResponse response(is_close);
    std::unordered_map<std::string, std::string> dict;
    auto handler = router_.Match(request, &dict);
    if(handler){
        handler(request, dict, &response);
    } else{
        default_handler_(request, dict, &response);
    }

    conn->Send(response.GetBuffer());

    // 不是长连接
    if(!response.GetCloseConn()){
        conn->Shutdown();
    }

}
