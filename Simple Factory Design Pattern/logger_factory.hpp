#pragma once
#ifndef LOGGER_FACTORY_HPP
#define LOGGER_FACTORY_HPP

#include "ilogger.hpp"
#include "common.hpp"

class LoggerFactory{
  public: 
    static ILogger* createLogger(LogLevel level);
};

#endif //LOGGER_FACTORY_HPP
