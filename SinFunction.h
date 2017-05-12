#pragma once
#include "IFunction.h"
class SinFunction :
	public IFunction
{
protected:
	virtual double GetValue(double x);
public:
	SinFunction();
	~SinFunction();
};

