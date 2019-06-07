#pragma once
#include "IFunction.h"
class LogFunction :
    public IFunction
{
public:
    LogFunction();
    ~LogFunction() override;

    double value(double x) override;
};

