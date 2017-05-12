#pragma once
#include "IFunction.h"
class PolynomFunction :
	public IFunction
{
protected:
	unsigned int _order;
	virtual double GetValue(double x);
public:
	PolynomFunction(unsigned int order=0);
	~PolynomFunction();
};

