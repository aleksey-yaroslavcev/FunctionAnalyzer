// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "IFunction.h"


unsigned int IFunction::GetFunctionValues(QVector<double>& array, double x1, double x2, double step){
	int arraySz;

	arraySz = (x2 - x1) / step + 1;
	array.resize(arraySz);
	for (unsigned int i = 0; i < arraySz; ++i)
		array[i] = GetValue(x1 + step*i);
	return arraySz;
}