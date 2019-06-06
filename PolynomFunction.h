#pragma once
#include "IFunction.h"
class PolynomFunction :
    public IFunction
{
public:
    PolynomFunction(unsigned int order = 0);
    ~PolynomFunction() override;

    double value(double x) override;
protected:
    unsigned int _order;
};

