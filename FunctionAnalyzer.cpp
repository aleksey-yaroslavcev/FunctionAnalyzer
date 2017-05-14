// FunctionAnalyzer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "IFunction.h"
#include "PolynomFunction.h"
#include "LineFunction.h"
#include "SquarePolynomFuction.h"
#include "CubePolynomFunction.h"
#include "LogFunction.h"
#include "SinFunction.h"

#include <iostream>

int main(int argc, char *argv[])
{
	std::vector<IFunction*> objectPool;

	objectPool.push_back(new LineFunction);
	objectPool.push_back(new SquarePolynomFuction);
	objectPool.push_back(new CubePolynomFunction);
	objectPool.push_back(new LogFunction);
	objectPool.push_back(new SinFunction);

	for (unsigned int i = 0; i < objectPool.size(); ++i)
		std::cout << objectPool.at(i)->GetFunctionDescription() << std::endl;

	return 0;
}
