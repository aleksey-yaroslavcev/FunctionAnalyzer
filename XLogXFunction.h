#pragma once
#include "IFunction.h"
#include "LineFunction.h"
#include "LogFunction.h"
#include "PolynomFunction.h"

class XLogXFunction : public IFunction
{
public:
    XLogXFunction();
    ~XLogXFunction() override;

    double value(double x) override;
private:
    LineFunction _line;
    LogFunction _log;
};

