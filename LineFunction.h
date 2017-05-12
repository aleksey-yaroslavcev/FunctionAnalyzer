#pragma once
#include "PolynomFunction.h"
class LineFunction :
	public PolynomFunction
{
public:
	LineFunction() : PolynomFunction(1) {};
	~LineFunction() {};
};

