#pragma once
#include "common.hpp"

class ILogger
{
public:
    virtual void log(const std::string &message) = 0;
    virtual ~ILogger() {}
};
