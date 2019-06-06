#pragma once
#include "IFunction.h"
class SinFunction : public IFunction
{
public:
    SinFunction();
    ~SinFunction() override;

    double value(double x) override;
};

