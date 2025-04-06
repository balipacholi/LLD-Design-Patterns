#include "debug_logger.hpp"

void DebugLogger::log(const string& message){
    std::cout << "Debug: " << message <<std::endl;
}