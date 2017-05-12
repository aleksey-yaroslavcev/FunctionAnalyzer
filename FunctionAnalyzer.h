#pragma once

#include <QtWidgets/QMainWindow>
#include <QVector>
#include "ui_FunctionAnalyzer.h"


class IFunction;

class FunctionAnalyzer : public QMainWindow
{
	Q_OBJECT

	QVector<IFunction*> _fuctions;
public:
    FunctionAnalyzer(QWidget *parent = Q_NULLPTR);


private:
    Ui::FunctionAnalyzerClass ui;
};
