#pragma once
#include "ilogger.hpp"
#include <string>

class DebugLogger : public ILogger
{
public:
    void log(const std::string &message);
};
