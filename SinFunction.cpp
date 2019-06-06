#include "SinFunction.h"

#include <QtMath>

SinFunction::SinFunction()
{
    _params["magn"] = 1;
    _params["phase"] = 0;
    _params["frequency"] = 1;
    _description = "Sine function";
}


SinFunction::~SinFunction()
{
}

double SinFunction::value(double x)
{
    return _params["magn"] * sin(_params["frequency"] * x + _params["phase"]);
}
