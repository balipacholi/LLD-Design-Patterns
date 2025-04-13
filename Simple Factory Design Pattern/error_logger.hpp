#include "ilogger.hpp"
#include <string>

class ErrorLogger : public ILogger
{
public:
    void log(const std::string &message);
};
