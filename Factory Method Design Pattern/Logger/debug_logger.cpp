#include "debug_logger.hpp"

void DebugLogger::log(const string& message) {
        std::cout << "DEBUG:" << message << std::endl;
}