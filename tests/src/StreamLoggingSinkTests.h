/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_TESTS_STREAMLOGGINGSINKTESTS_H_
#define _ISHIKO_CPP_LOGGING_TESTS_STREAMLOGGINGSINKTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class StreamLoggingSinkTests : public Ishiko::Tests::TestSequence
{
public:
    StreamLoggingSinkTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void SendTest1(Ishiko::Tests::Test& test);
};

#endif
