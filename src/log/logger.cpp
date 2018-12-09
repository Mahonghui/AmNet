//
// Created by amisher on 18-12-9.
//

#include <pthread.h>
#include <cstdio>
#include "logger.h"
#include "logbuf.h"
#include "asynclogger.h"


// 初始化日志等级
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
    std::fwrite(msg,1,(size_t)len, stdout);
}

void DefaultFlush()
{
    std::fflush(stdout);
}

static pthread_once_t once_control = PTHREAD_ONCE_INIT;
static AsyncLogger* asyncLogger;

std::string Logger::logfile_name_ = "./AmNetlib.log";

// 初始化异步log
void OnceInit()
{
    asyncLogger = new AsyncLogger(Logger::GetLogFileName());
    asyncLogger->Start();
}

void AsyncOutput(const char* str, int len)
{
    pthread_once(&once_control, OnceInit);
    asyncLogger->Append(str, len);
}

Logger::OutputFunc g_output = AsyncOutput;
Logger::FlushFunc g_flush = DefaultFlush;

void Logger::SetOutput(Logger::OutputFunc out){
    g_output = out;
}

void Logger::SetFlush(Logger::FlushFunc flu){
    g_flush = flu;
}

const char* loglevel_name[Logger::LOG_LEVEL_NUMS] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "FATAL"
};

Logger::Logger(const char *logfile, int line, Logger::LogLevel level, const char *func):
stream_(),
level_(level),
logfile_(logfile),
line_(line){
    stream_<<loglevel_name[level_]<< func<<"\n";
}

Logger::~Logger() {
    // 输出日志缓冲区中的内容
    stream_<<"## "<<logfile_<<" : "<<line_<<"\n";
    g_output(GetLogStream().GetBuffer().GetData(), GetLogStream().GetBuffer().GetLen());
    if(level_ == FATAL)
    {
        g_flush();
        abort();
    }
}
