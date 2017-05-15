#pragma once
#include "IFunction.h"
#include "LineFunction.h"
#include "LogFunction.h"
#include "PolynomFunction.h"
class XLogXFunction :
	public IFunction
{
	LineFunction _line;
	LogFunction _log;
public:
	virtual double GetValue(double x);
	XLogXFunction();
	~XLogXFunction();
};

