#include "IFunction.h"

#include <algorithm>
#include <iterator>


IFunction::IFunction() {}

IFunction::~IFunction() {}

std::size_t IFunction::values(std::vector<double>& array, double x1, double x2,
                              double step)
{
    auto arraySz = std::size_t((x2 - x1) / step + 1);
    array.resize(arraySz);
    for (unsigned int i = 0; i < arraySz; ++i)
        array[i] = value(x1 + step * i);
    return arraySz;
}

std::list<std::string> IFunction::params()
{
    std::list<std::string> l;

    for (auto it = _params.begin(); it != _params.end(); ++it)
        l.push_back(it->first);

    return l;
}

void IFunction::setParam(std::string name, double val)
{
    _params[name] = val;
}

std::string IFunction::description()
{
    return _description;
}
