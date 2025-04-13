#pragma once
#include <string>
using namespace std;
class ILogger
{
public:
    virtual ~ILogger() {}
    virtual void log(const string &message) = 0;
};