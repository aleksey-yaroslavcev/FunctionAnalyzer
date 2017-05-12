#include "SinFunction.h"


SinFunction::SinFunction()
{
	_params["magn"] = 1;
	_params["phase"] = 0;
}


SinFunction::~SinFunction()
{
}

double SinFunction::GetValue(double x){
	double magn = _params["magn"];
	double phase = _params["phase"];
	return magn*sin(x + phase);
}
