#pragma once
#include "ILoggerFactory.hpp"
#include "info_logger.hpp"

class InfoFactory : public ILoggerFactory
{
public:
  ILogger *createLogger() override
  {
    return new InfoLogger();
  }
};