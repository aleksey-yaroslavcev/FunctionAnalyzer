// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "PolynomFunction.h"

PolynomFunction::PolynomFunction(unsigned int order)
{
	_order = order;
	for (unsigned int i = 0; i <= _order; i++)
		_params[QString("a%1").arg(i)] = 1;
	_description = tr("Polynomial function of order %1").arg(_order);
}


PolynomFunction::~PolynomFunction()
{
}

double PolynomFunction::GetValue(double x){
	double res = 0;
	double a;
	for (unsigned int i = 0; i <= _order; i++){
		a = _params[QString("a%1").arg(i)];
		res += a*pow(x, i);
	}
	return res;
}
