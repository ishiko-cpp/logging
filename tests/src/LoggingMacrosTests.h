/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_TESTS_LOGGINGMACROSTESTS_H_
#define _ISHIKO_CPP_LOGGING_TESTS_LOGGINGMACROSTESTS_H_

#include <Ishiko/Tests/Core.h>

class LoggingMacrosTests : public Ishiko::Tests::TestSequence
{
public:
    LoggingMacrosTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);
};

#endif
