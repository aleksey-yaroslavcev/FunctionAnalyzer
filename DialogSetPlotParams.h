#pragma once

#include <QDialog>
#include <qwt_plot.h>
#include "ui_DialogSetPlotParams.h"


class DialogSetPlotParams : public QDialog
{
	Q_OBJECT

	QwtPlot *_plot;
	
public:
	DialogSetPlotParams(QWidget *parent = Q_NULLPTR);
	~DialogSetPlotParams();

	void init(QwtPlot *plot);

public slots:
	void on_pbSet_clicked();
	void on_pbCancel_clicked();
private:
	Ui::DialogSetPlotParams ui;
};
