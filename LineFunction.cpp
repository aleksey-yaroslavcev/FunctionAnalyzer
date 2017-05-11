#include "LineFunction.h"


LineFunction::LineFunction()
{
	_params["k"] = 0;
	_params["b"] = 0;
}


LineFunction::~LineFunction()
{
}

double LineFunction::GetValue(double x){
	double k = _params["k"];
	double b = _params["b"];
	return k*x + b;
}
