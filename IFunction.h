#pragma once

#include <QVector>
#include <QList>
#include <QString>
#include <QMap>

class IFunction
{
protected:
	QMap<QString, double> _params;
	QString _description;

	virtual double GetValue(double x) = 0;
public:
	IFunction(){};
	~IFunction(){};
	unsigned int GetFunctionValues(QVector<double>& array, double x1, double x2, double step);

	QList<QString> GetParamsList(){ return _params.keys(); };
	void SetParam(QString name, double val){ _params[name] = val; };
	QString GetFunctionDescription(){ return _description; };
};

