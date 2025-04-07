#pragma once

#include "ilogger.hpp"
#include <iostream>

class DebugLogger : public ILogger {
    public:
      void log(const string& message);
};