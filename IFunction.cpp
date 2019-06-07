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

QPointF IFunction::point(double x)
{
    return QPointF(x, value(x));
}

QList<QString> IFunction::params()
{
    QList<QString> l;

    for (auto it = _params.begin(); it != _params.end(); ++it)
        l.push_back(it.key());

    return l;
}

void IFunction::setParam(const QString& name, double val)
{
    _params[name] = val;
}

QString IFunction::description()
{
    return _description;
}
