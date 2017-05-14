#include "PolynomFunction.h"

PolynomFunction::PolynomFunction(unsigned int order)
{
	_order = order;
	for (unsigned int i = 0; i <= _order; i++)
		_params["a"+i] = 1;
	_description = "Polynomial function of order "+_order;
}


PolynomFunction::~PolynomFunction()
{
}

double PolynomFunction::GetValue(double x){
	double res = 0;
	double a;
	for (unsigned int i = 0; i <= _order; i++){
		a = _params["a"+i];
		res += a*pow(x, i);
	}
	return res;
}
