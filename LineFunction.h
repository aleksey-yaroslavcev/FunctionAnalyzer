#pragma once
#include "PolynomFunction.h"
class LineFunction :
	public PolynomFunction
{
public:

	LineFunction() : PolynomFunction(1) 
	{ 
		_description = QApplication::tr("Line function");
	}
	
	~LineFunction() 
	{
	}
};

