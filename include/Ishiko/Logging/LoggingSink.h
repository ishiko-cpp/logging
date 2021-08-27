/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGINGSINK_H_
#define _ISHIKO_CPP_LOGGING_LOGGINGSINK_H_

#include <string>

namespace Ishiko
{

class LoggingSink
{
public:
    virtual void send(const std::string& record) = 0;
};

}

#endif
