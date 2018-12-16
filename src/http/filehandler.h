//
// Created by amisher on 18-12-15.
//

#ifndef AMNET_FILEHANDLER_H
#define AMNET_FILEHANDLER_H

#include <functional>
#include <string>
#include <unordered_map>

class HttpRequest;
class HttpResponse;

class FileHandler{
public:
    FileHandler()= default;
    ~FileHandler()= default;

    void setFilePrefix(std::string path){file_prefix_=path;}

    std::function<void(const HttpRequest&, std::unordered_map<std::string, std::string>&, HttpResponse* response)> GetHandler()
    {
        return std::bind(&FileHandler::Handler, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

private:
    void Handler(const HttpRequest& request, std::unordered_map<std::string ,std::string>&, HttpResponse*response);

    std::string file_prefix_;
};

#endif //AMNET_FILEHANDLER_H
