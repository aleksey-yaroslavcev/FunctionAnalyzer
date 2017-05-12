#pragma once

#include <QtWidgets/QMainWindow>
#include <QVector>
#include "ui_FunctionAnalyzer.h"


class IFunction;
class QwtPlotCurve;
class QwtPointSeriesData;
class QwtPlotGrid;

class FunctionAnalyzer : public QMainWindow
{
	Q_OBJECT

public:

	FunctionAnalyzer(QWidget *parent = Q_NULLPTR);
	virtual bool eventFilter(QObject *, QEvent *);

private:

	IFunction* _func1;
	IFunction* _func2;

	QwtPlotCurve* _curve;
	QwtPointSeriesData* _data;
	QwtPlotGrid* _grid;

	Ui::FunctionAnalyzerClass ui;
};
