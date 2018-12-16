//
// Created by amisher on 18-12-16.
//

#include <sys/mman.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <fstream>
#include "filestat.h"
#include "util.h"
#include "iobuffer.h"



// define MIME Types mapping
std::unordered_map<std::string, std::string> FileStat::mime_ = {
        {"default", "text/plain"},
        {"txt", "text/plain"},
        {"html", "text/html"},
        {"htm", "text/html"},
        {"css", "text/css"},
        {"js", "text/javascript"},
        {"csv", "text/csv"},
        {"jpg", "image/jpg"},
        {"jpeg", "image/jpeg"},
        {"png", "image/png"},
        {"gif", "image/gif"},
        {"bmp", "image/bmp"},
        {"ico", "image/x_icon"},
        {"mp3", "audio/mp3"},
        {"avi", "video/x-msvideo"},
        {"json", "application/json"},
        {"doc", "application/msword"},
        {"ppt", "application/vnd.ms-powerpoint"},
        {"pdf", "application/pdf"},
        {"gz", "application/x-gzip"},
        {"tar", "application-xtar"}
};