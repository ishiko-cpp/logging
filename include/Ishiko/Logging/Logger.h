/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/logging/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_LOGGING_LOGGER_H_
#define _ISHIKO_CPP_LOGGING_LOGGER_H_

#include "LoggingSink.h"
#include <fmt/format.h>
#include <string>

namespace Ishiko
{

class Logger
{
public:
    enum class Level
    {
        fatal = 1,
        error = 2,
        warning = 3,
        info = 4,
        trace = 5
    };

    struct KeyValue
    {
        const char* key;
        const char* value;
    };

    Logger(LoggingSink& sink);
    Logger(LoggingSink& sink, Level level);

    void setLevel(Level level);

    template <typename... Args>
    void error(const std::string& message, Args&&... args);

    template <typename... Args>
    void warning(const std::string& message, Args&&... args);

    template <typename... Args>
    void info(const std::string& message, Args&&... args);

    template <typename... Args>
    void trace(const std::string& message, Args&&... args);

private:
    LoggingSink& m_sink;
    Level m_level;
};

template <typename... Args>
void Logger::error(const std::string& message, Args&&... args)
{
    if (m_level >= Level::error)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(formattedMessage);
    }
}

template <typename... Args>
void Logger::warning(const std::string& message, Args&&... args)
{
    if (m_level >= Level::warning)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(formattedMessage);
    }
}

template <typename... Args>
void Logger::info(const std::string& message, Args&&... args)
{
    if (m_level >= Level::info)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(formattedMessage);
    }
}

template <typename... Args>
void Logger::trace(const std::string& message, Args&&... args)
{
    if (m_level >= Level::trace)
    {
        std::string formattedMessage = fmt::format(message, std::forward<Args>(args)...);
        m_sink.send(formattedMessage);
    }
}

}

template<>
class fmt::formatter<Ishiko::Logger::KeyValue>
{
public:
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const Ishiko::Logger::KeyValue& kv, FormatContext& ctx) -> decltype(ctx.out()) {
        return format_to(ctx.out(), "{}, {}", kv.key, kv.value);
    }
};

#endif
