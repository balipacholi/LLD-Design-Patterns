#ifndef INFO_LOGGER_HPP
#define INFO_LOGGER_HPP
#include "ilogger.hpp"
#include <string>

class InfoLogger : public ILogger
{
public:
    void log(const std::string &message);
};
#endif
