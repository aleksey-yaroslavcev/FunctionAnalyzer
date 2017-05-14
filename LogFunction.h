#pragma once
#include "IFunction.h"
class LogFunction :
	public IFunction
{
public:
	virtual double GetValue(double x);
	LogFunction();
	~LogFunction();
};

