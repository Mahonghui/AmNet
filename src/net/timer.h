//
// Created by amisher on 18-12-10.
//

#ifndef AMNET_TIMER_H
#define AMNET_TIMER_H

#include <stdint.h>
#include <functional>
#include "timestamp.h"

class Timer{
public:
    Timer(const std::function<void()> cb, TimeStamp when):callback_(cb), when_(when){}

    void Run()const {callback_();}
    TimeStamp GetExpireTime() const{ return when_;}
private:
    const std::function<void()> callback_;
    TimeStamp when_;
};

#endif //AMNET_TIMER_H
