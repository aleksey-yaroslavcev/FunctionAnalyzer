#pragma once

#include <QtWidgets/QMainWindow>
#include <QVector>
#include "ui_FunctionAnalyzer.h"


class IFunction;
class QwtPlotCurve;
class QwtPointSeriesData;
class QwtPlotGrid;
class QGroupBox;

class FunctionAnalyzer : public QMainWindow
{
	Q_OBJECT

public:

	FunctionAnalyzer(QWidget *parent = Q_NULLPTR);
	virtual bool eventFilter(QObject *, QEvent *);

public slots:
	void on_cobFunc1_currentIndexChanged(int);
	void on_cobFunc2_currentIndexChanged(int);
private:

	QVector<IFunction*> _functionPool;
	QVector<QGroupBox*> _grpBoxesF1, _grpBoxesF2;

	QwtPlotCurve* _curve;
	QwtPointSeriesData* _data;
	QwtPlotGrid* _grid;

	Ui::FunctionAnalyzerClass ui;

	void FillFunctionsCombo(QComboBox *cob);
};
