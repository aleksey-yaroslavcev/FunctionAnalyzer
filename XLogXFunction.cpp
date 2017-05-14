#include "XLogXFunction.h"



double XLogXFunction::GetValue(double x)
{
	return _line.GetValue(x)*_log.GetValue(x);
}

XLogXFunction::XLogXFunction()
{
	_description = "x*log(x) function";
	_line.SetParam("a1", 1);
	_line.SetParam("a0", 0);
	_log.SetParam("a",1);
}


XLogXFunction::~XLogXFunction()
{
}