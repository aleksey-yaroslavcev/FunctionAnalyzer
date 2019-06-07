#include "LogFunction.h"

#include <QtMath>

LogFunction::LogFunction()
{
    _params["a"] = 1;
    _description = "Logarifmic function";
}


LogFunction::~LogFunction()
{
}

double LogFunction::value(double x)
{
    double a = _params["a"];
    return a * log(x);
}
