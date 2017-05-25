// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "LogFunction.h"


LogFunction::LogFunction()
{
	_params["a"] = 1;
	_description = tr("Logarifmic function");
}


LogFunction::~LogFunction()
{
}

double LogFunction::GetValue(double x){
	double a = _params["a"];
	return a*log(x);
}
