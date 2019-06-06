#pragma once

#include <vector>
#include <list>
#include <QString>
#include <QMap>

class IFunction
{
public:
    IFunction();
    virtual ~IFunction();
    std::size_t values(std::vector<double>& array, double x1, double x2, double step);
    virtual double value(double x) = 0;

    std::list<std::string> params();
    void setParam(std::string name, double val);
    std::string description();

protected:
    QMap<QString, double> _params;
    QString _description;
};

