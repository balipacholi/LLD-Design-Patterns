#include "ILoggerFactory.hpp"
#include "debug_factory.hpp"
#include "error_factory.hpp"
#include "info_factory.hpp"

int main(){
    //create a Interface factory 
    
    ILoggerFactory* factory1 = new DebugFactory();
    ILogger* debugLogger = factory1->createLogger();
    debugLogger->log("This is a debug message ");
    delete debugLogger;

    ILoggerFactory* factory2 = new ErrorFactory();
    ILogger* errorLogger = factory2->createLogger();
    errorLogger->log("This is a error message ");
    delete errorLogger;

    ILoggerFactory* factory3 = new InfoFactory();
    ILogger* InfoLogger = factory3->createLogger();
    InfoLogger->log("This is a info message ");
    delete InfoLogger;
    return 0;
}