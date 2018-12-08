//
// Created by amisher on 18-12-8.
//

#ifndef AMNET_TIMESTAMP_H
#define AMNET_TIMESTAMP_H

#include <chrono>

using std::chrono::system_clock;

using Nanosecond    = std::chrono::nanosecond;
using Microsecond   = std::chrono::microsecond;
using Millisecond   = std::chrono::millisecond;
using Second        = std::chrono::second;
using Minute        = std::chrono::minute;
using Hour          = std::chrono::hour;

using TimeStamp     = std::chrono::time_point<system_clock, Nanosecond >;

#endif //AMNET_TIMESTAMP_H
