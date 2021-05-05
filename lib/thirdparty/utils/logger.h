#pragma once

#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <vector>
#include <map>

class Logger
{
public:
    Logger(std::string name);
    ~Logger();

protected:
    template <typename T>
    void logInfo(T value);
    template <typename K, typename T>
    void logInfo(std::map<K, T> map);
    template <typename T>
    void logInfo(std::vector<T> &value);
    template <typename T>
    void logError(T value);

private:
    std::string m_name;
    static std::mutex m_mutex;
    std::_Put_time<char> getTime();
};

template <typename T>
void Logger::logInfo(T value)
{
    std::lock_guard<std::mutex>(Logger::m_mutex);
    std::cout << getTime() << " [info]"
              << "[" << m_name << "] " << value << "\n ";
}

template <typename T>
void Logger::logInfo(std::vector<T> &values)
{
    std::lock_guard<std::mutex>(Logger::m_mutex);
    std::cout << getTime() << " [info][" << m_name << "] "
              << " vector"
              << "(";
    for (auto &vaule : values)
    {
        std::cout << vaule << ", ";
    }
    std::cout << ")\n";
}
template <typename K, typename T>
void Logger::logInfo(std::map<K, T> map)
{
    std::lock_guard<std::mutex>(Logger::m_mutex);
    std::cout << getTime() << " [info][" << m_name << "] map(";
    for (auto val : map)
    {
        std::cout << val.first << ":" << val.second << ", ";
    }
    std::cout << ")\n";
}

template <typename T>
void Logger::logError(T value)
{
    std::lock_guard<std::mutex>(Logger::m_mutex);
    std::cout << getTime() << " [error]"
              << "[" << m_name << "] " << value << "\n ";
}