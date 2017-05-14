#pragma once
#include "IFunction.h"
class PolynomFunction :
	public IFunction
{
protected:
	unsigned int _order;
public:
	virtual double GetValue(double x);
	PolynomFunction(unsigned int order=0);
	~PolynomFunction();
};

