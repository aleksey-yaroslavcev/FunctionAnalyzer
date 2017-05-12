#pragma once
#include "PolynomFunction.h"
class CubePolynomFunction :
	public PolynomFunction
{
public:

	CubePolynomFunction() :PolynomFunction(3)
	{
		_description = QApplication::tr("Cube polynomial function");
	}

	~CubePolynomFunction()
	{
	}
};

