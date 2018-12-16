//
// Created by amisher on 18-12-16.
//

#ifndef AMNET_FILE_H
#define AMNET_FILE_H

#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <string>
#include <unordered_map>
#include "timestamp.h"


class IOBuffer;

class FileStat{
public:
    explicit FileStat(std::string& path);
    ~FileStat() = default;

    bool Exist () const;
    bool isFile();
    bool isDir();
    bool isLink();

    TimeStamp GetModTime();
    TimeStamp GetCreaTiem();

    std::string GetName();
    std::string GetExtension();
    std::string GetMimeType();

    off_t GetSize();

    std::string GetText();
    std::vector<FileStat> ListDir();

    void Dump2Buffer(IOBuffer& buffer);
private:
    struct stat file_stat_;
    bool exist_;
    std::string path_;
    static std::unordered_map<std::string, std::string> mime_;
};
#endif //AMNET_FILE_H
