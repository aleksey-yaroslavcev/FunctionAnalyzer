#pragma once
#include "IFunction.h"
class SinFunction :
	public IFunction
{
public:
	virtual double GetValue(double x);
	SinFunction();
	~SinFunction();
};

