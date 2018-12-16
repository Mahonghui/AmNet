//
// Created by amisher on 18-12-16.
//

#include "filehandler.h"
#include "filestat.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "util.h"

void FileHandler::Handler(const HttpRequest &request, std::unordered_map<std::string, std::string> & m,
                          HttpResponse *response) {
    std::string s(file_prefix_ + m["file_path"]);

    FileStat file(s);
    if(file.Exist()){
        if(file.isFile()){
            // 如果是文件，把文件写到缓存
            response->SetStatusCode(HttpResponse::OK);
            response->SetStatusPhrase("OK");
            response->SetContentType(file.GetMimeType());
            response->AddHeader("Content-Length", std::to_string(file.GetSize()));
            // 头部写入缓存
            response->WriteHeader2Buffer();
            // 文件剩余内容作为body写入缓存
            file.Dump2Buffer(response->GetBuffer());
        }else{
            // 如果是目录，列出下面的文件
            response->SetStatusCode(HttpResponse::OK);
            response->SetStatusPhrase("OK");
            response->SetContentType("text/html");

            std::string body = "<pre>\n";
            std::string slash = "/";
            auto dir = file.ListDir();
            for(auto& f: dir){
                slash = f.isDir()?"/":"";
                body.append("<a href = \">");
                body.append(f.GetName());
                body.append(slash);
                body.append("/>");
                body.append(f.GetName());
                body.append(slash);
                body.append("</a>\n");
            }

            body += "</pre>";
            response->AddHeader("Content-Length", std::to_string(body.size()));
            response->WriteHeader2Buffer();
            response->WriteMsg2Buffer(body);
        }
    }
    else{
        // 文件不存在,返回404
        response->SetStatusCode(HttpResponse::NOT_FOUND);
        response->SetStatusPhrase("NOT FOUND");
        response->SetCloseConn(true);
        response->SetContentType("text/html");

        std::string body = "404 Not Found";
        response->AddHeader("Content-;ength", std::to_string(body.size()));

        response->WriteHeader2Buffer();
        response->WriteMsg2Buffer(body);
    }
}
