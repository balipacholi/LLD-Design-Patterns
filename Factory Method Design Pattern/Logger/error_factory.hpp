#pragma once
#include "ILoggerFactory.hpp"
#include "error_logger.hpp"

class ErrorFactory : public ILoggerFactory {
 public:
  ILogger* createLogger() override{
        return new ErrorLogger();
  }
};