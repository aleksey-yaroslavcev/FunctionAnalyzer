#include "IFunction.h"

#include <algorithm>
#include <iterator>


unsigned int IFunction::GetFunctionValues(std::vector<double>& array, double x1, double x2, double step)
{
	int arraySz;

	arraySz = (x2 - x1) / step + 1;
	array.resize(arraySz);
	for (unsigned int i = 0; i < arraySz; ++i)
		array[i] = GetValue(x1 + step*i);
	return arraySz;
}

std::list<std::string> IFunction::GetParamsList()
{
	std::list<std::string> l;

	for (auto it = _params.begin(); it != _params.end(); ++it)
		l.push_back(it->first);

	return l;
}
