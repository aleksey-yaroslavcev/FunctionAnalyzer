#pragma once
#include "PolynomFunction.h"
class SquarePolynomFuction :
	public PolynomFunction
{
public:

	SquarePolynomFuction() :PolynomFunction(2) 
	{
		_description = "Square polynomial function";
	}

	~SquarePolynomFuction() 
	{
	}
};

