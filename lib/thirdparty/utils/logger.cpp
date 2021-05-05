#include "logger.h"

std::mutex Logger::m_mutex;

Logger::Logger(std::string name) : m_name(name)
{
}

Logger::~Logger()
{
}

std::_Put_time<char> Logger::getTime()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    auto gmt_time = gmtime(&now_time);
    auto timestamp = std::put_time(gmt_time, "%H:%M:%S");
    return timestamp;
}
