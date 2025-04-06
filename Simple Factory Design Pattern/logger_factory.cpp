#include "logger_factory.hpp"
#include "debug_logger.hpp"
#include "info_logger.hpp"
#include "error_logger.hpp"

ILogger* LoggerFactory::createLogger(LogLevel level){
    if(level == LogLevel::DEBUG){
        return new DebugLogger();
    }
    else if(level == LogLevel::INFO){
        return new InfoLogger();
    } else {
        return new ErrorLogger();
    }
    return nullptr;
}