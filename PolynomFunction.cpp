#include "PolynomFunction.h"


PolynomFunction::PolynomFunction(unsigned int order)
{
	for (unsigned int i = 0; i < order; i++)
		_params[QString("a%1").arg(i)] = 1;
	_order = order;
}


PolynomFunction::~PolynomFunction()
{
}

double PolynomFunction::GetValue(double x){
	double res = 0;
	double a;
	for (unsigned int i = 0; i < _order; i++){
		a = _params[QString("a%1").arg(i)];
		res += a*pow(x, i);
	}
	return res;
}
