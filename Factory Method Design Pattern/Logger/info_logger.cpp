#include "info_logger.hpp"

void InfoLogger::log(const string& message) {
        std::cout << "INFO:" << message << std::endl;
}