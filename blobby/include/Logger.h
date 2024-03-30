#pragma once

#include <cstdint>

#include <memory>
#include <string>

enum class LogLevel : uint8_t
{
    NONE = 0,
    ERROR = 1,
    WARN = 2,
    INFO = 3,
    STRUCTURED = 4,
    DEBUG = 5,
};

enum class LogDestination : uint8_t
{
    CONSOLE = 0,
    FILE = 1,

};
/*
#define LOG_ERROR(pLogger) pLogger->Log(LogLevel::ERROR, sError);
#define LOG_WARNING(pLogger) pLogger->Log(LogLevel::WARN, sError);
#define LOG_INFO(pLogger) pLogger->Log(LogLevel::INFO, sError);
#define LOG_STRUCTURED(pLogger) pLogger->Log(LogLevel::STRUCTURED, sError);
#define LOG_DEBUG(pLogger) pLogger->Log(LogLevel::DEBUG, sError);

class Logger
{
public:
    void Log(LogLevel eLevel, const std::string& sLogMessage);
    std::shared_ptr<Logger> GetInstance();

private:

    LogDestination eOutputDestination;
    static std::shared_ptr<Logger> m_pLogger;


};
*/