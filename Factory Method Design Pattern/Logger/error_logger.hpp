#pragma once

#include "ilogger.hpp"
#include <iostream>

class ErrorLogger : public ILogger {
    public:
      void log(const string& message) override;
};