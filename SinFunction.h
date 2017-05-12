#pragma once
#include "IFunction.h"
class SinFunction :
	public IFunction
{
	virtual double GetValue(double x);
public:
	SinFunction();
	~SinFunction();
};

