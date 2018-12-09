//
// Created by amisher on 18-12-9.
//

#include "logger.h"
#include "logbuf.h"
#include <pthread.h>
#include <cstdio>

Logger::LogLevel InitLogLevel(){
    if(getenv("LOG_DEBUG"))
        return Logger::DEBUG;
    else
        return Logger::INFO;
}

Logger::LogLevel global_level =InitLogLevel();

Logger::LogLevel Logger::GetGlobalLevel() {
    return global_level;
}

void DefaultOutput(const char* msg, int len)
{
    std::fwrite(msg,len, stdout);
}

void DefaultFlush()
{
    std::fflush(stdout);
}

Logger::Logger(const char *logfile, int line, Logger::LogLevel level, const char *func):
stream_(),
level_(level),
logfile_(logfile),
line_(line){
    stream_<<" ## "<<logfile_<<": "<<line_<<'\n';
}

Logger::~Logger() {
    stream_<<" ## "<<logfile_<<": "<<line_<<'\n';

}
