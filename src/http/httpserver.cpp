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


