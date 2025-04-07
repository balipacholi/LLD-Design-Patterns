#pragma once
#include "ilogger.hpp"

class ILoggerFactory {
    public :
      virtual ~ILoggerFactory() {}
      virtual ILogger* createLogger() =0;
};