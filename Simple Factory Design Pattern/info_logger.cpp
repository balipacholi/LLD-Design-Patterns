#include "info_logger.hpp"

void InfoLogger::log(const string& message){
    std::cout << "Info:" << message <<std::endl;
}