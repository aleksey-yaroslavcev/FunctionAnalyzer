#include "LogFunction.h"


LogFunction::LogFunction()
{
	_params["a"] = 1;
}


LogFunction::~LogFunction()
{
}

double LogFunction::GetValue(double x){
	double a = _params["a"];
	return a*log(x);
}
