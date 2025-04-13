#pragma once
#include "ILoggerFactory.hpp"
#include "debug_logger.hpp"

class DebugFactory : public ILoggerFactory
{
public:
   ILogger *createLogger()
   {
      return new DebugLogger();
   }
};