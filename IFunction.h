#pragma once

#include <vector>
#include <QList>
#include <QString>
#include <QMap>

class IFunction
{
public:
    IFunction();
    virtual ~IFunction();
    std::size_t values(std::vector<double>& array, double x1, double x2, double step);
    virtual double value(double x) = 0;

    QList<QString> params();
    void setParam(const QString& name, double val);
    QString description();

protected:
    QMap<QString, double> _params;
    QString _description;
};

