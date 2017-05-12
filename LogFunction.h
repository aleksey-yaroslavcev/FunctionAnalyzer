#pragma once
#include "IFunction.h"
class LogFunction :
	public IFunction
{
protected:
	virtual double GetValue(double x);
public:
	LogFunction();
	~LogFunction();
};

