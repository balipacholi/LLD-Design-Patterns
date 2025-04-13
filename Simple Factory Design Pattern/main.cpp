#include "logger_factory.hpp"

int main()
{
    // Create a logger instance
    ILogger *debuglogger = LoggerFactory::createLogger(LogLevel::DEBUG);
    // ILogger* infologger = LoggerFactory::createLogger(LogLevel::INFO);
    // ILogger* errorlogger = LoggerFactory::createLogger(LogLevel::ERROR);

    // Log messages
    debuglogger->log("This is a debug log msg");
    // infologger->log("This is an info log msg");
    // errorlogger->log("This is an error log msg");

    // clean up
    delete debuglogger;
    // delete infologger;
    // delete errorlogger;

    return 0;
}
