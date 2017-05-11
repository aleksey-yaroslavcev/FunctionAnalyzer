#pragma once
#include "IFunction.h"
class LineFunction :
	public IFunction
{
	virtual double GetValue(double x);
public:
	LineFunction();
	~LineFunction();
};

