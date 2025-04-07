#include "error_logger.hpp"

void ErrorLogger::log(const string& message) {
        std::cout << "ERROR:" << message << std::endl;
}