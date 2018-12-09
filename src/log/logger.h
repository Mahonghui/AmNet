//
// Created by amisher on 18-12-9.
//

#ifndef AMNET_LOGGER_H
#define AMNET_LOGGER_H

#include "logbuf.h"

class Logger{

public:
    enum LogLevel{
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        LOG_LEVEL_NUMS;
    };
     Logger(const char* logfile, int line, LogLevel level, const char* func);
     ~Logger();

     LogStream& GetLogStream() {return stream_;}

     static LogLevel GetGlobalLevel();
     static std::string GetLogFileName() { return logfile_name_;}

     typedef void (*OutputFunc)(const char* msg, int len);
     typedef void (*FlushFunc)();

     static void SetOutput(OutputFunc);
     static void SetFlush(FlushFunc);

private:
    LogStream stream_;
    static std::string logfile_name_;
    LogLevel level_;
    const char* logfile_;
    int line_;
};

#endif //AMNET_LOGGER_H
