#pragma once

#include "ilogger.hpp"
#include <iostream>

class InfoLogger : public ILogger
{
public:
  void log(const string &message) override;
};