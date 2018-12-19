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
        {"tar", "application-xtar"},
};

FileStat::FileStat(std::string &path):path_(path) {
    if(path_[path_.size()-1] == '/'){
        path_.pop_back();
    }
    // stat: gets file information of 'filename' and store them into struct stat variable.
    // return value: 0[ok], -1[err]
    exist_ = (stat(path_.c_str(), &file_stat_) == 0);
}

bool FileStat::Exist() const { return exist_;}

bool FileStat::isFile() {
    if(!exist_)
        return false;
    return S_ISREG(file_stat_.st_mode);
}

bool FileStat::isDir() {
    if(!exist_)
        return false;
    return S_ISDIR(file_stat_.st_mode);
}

bool FileStat::isLink() {
    if(!exist_)
        return false;
    return S_ISLNK(file_stat_.st_mode);
}

TimeStamp FileStat::GetCreaTiem(){
    if(!exist_)
        return system_clock::now();
    return util::StrfTime(file_stat_.st_ctim);
}

TimeStamp FileStat::GetModTime() {
    if(!exist_)
        return system_clock::now();
    return util::StrfTime(file_stat_.st_mtim);
}

std::string FileStat::GetName() {
    std::string abs_path = path_;
    // /var/www/http/data.dat --> data.dat
    return abs_path.erase(0, abs_path.find_last_of('/')+1);
}

std::string FileStat::GetExtension() {
    std::string name = GetName();
    long int aux = name.find_last_of('.');
    if(aux == -1 || aux == (int)(name.length()-1))
        return "";
    else
    {
        std::string ext = name.substr((unsigned)aux+1);
        util::ToLowerCase(ext);
        return ext;
    }
}

off_t FileStat::GetSize() {
    if(!exist_)
        return 0;
    return file_stat_.st_size;
}

std::string FileStat::GetMimeType() {
    std::string ext = GetExtension();
    auto it = mime_.find(ext);
    if(it != mime_.end())
        return it->second;
    else
        return mime_["default"];
}

std::string FileStat::GetText() {
    std::ifstream ifs(path_, std::ios_base::in);
    if(!ifs)
        return "";
    std::string content;
    std::string line;
    while (!ifs.eof()){
        getline(ifs, line);
        content += line;
        content += '\n';
    }
    content.erase(content.size()-1);
    return content;

}

std::vector<FileStat> FileStat::ListDir() {
    std::string abs_path = path_;

    DIR* d_ptr = nullptr;
    struct dirent* dir_entry = nullptr;

    d_ptr = opendir(abs_path.c_str());

    std::vector<FileStat> files;

    while ((dir_entry = readdir(d_ptr)) != nullptr)
    {
        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
            continue;
        std::string s(abs_path + "/" + dir_entry->d_name);
        FileStat tmp = FileStat(s);
        files.push_back(tmp);
    }

    closedir(d_ptr);
    return files;
}

void FileStat::Dump2Buffer(IOBuffer &buffer) {
    int fd = open(path_.c_str(), O_RDONLY, 0);
    if(fd == -1){
        close(fd);
        return;
    }

    void* ret = mmap(nullptr, (size_t)file_stat_.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    if(ret == (void*)-1){
        munmap(ret, (size_t)file_stat_.st_size);
        return;
    }

    char* addr = static_cast<char*>(ret);
    buffer.Append(addr, (size_t)file_stat_.st_size);

    munmap(ret, (size_t)file_stat_.st_size);
    return;
}