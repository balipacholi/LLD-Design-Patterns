#include "error_logger.hpp"

void ErrorLogger::log(const string &message)
{
    std::cout << "Error:" << message << std::endl;
}