#pragma once
#include "IFunction.h"
class LogFunction :
	public IFunction
{
	virtual double GetValue(double x);
public:
	LogFunction();
	~LogFunction();
};

