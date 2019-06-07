#include "XLogXFunction.h"

XLogXFunction::XLogXFunction()
{
    _description = "x*log(x) function";
    _line.setParam("a1", 1);
    _line.setParam("a0", 0);
    _log.setParam("a", 1);
}

XLogXFunction::~XLogXFunction()
{
}

double XLogXFunction::value(double x)
{
    return _line.value(x) * _log.value(x);
}
