// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "DialogSetPlotParams.h"
#include <qwt_scale_engine.h>

DialogSetPlotParams::DialogSetPlotParams(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.leDx->setValidator(new QIntValidator(1, 1000000));
	ui.leDy->setValidator(new QIntValidator(1, 1000000));
	ui.leMinY->setValidator(new QIntValidator(-10000, 10000));
	ui.leMaxY->setValidator(new QIntValidator(-10000, 10000));
}

DialogSetPlotParams::~DialogSetPlotParams()
{
}

void DialogSetPlotParams::init(QwtPlot *plot){
	_plot = plot;

	ui.leDy->setText(QString::number(_plot->axisStepSize(QwtPlot::yLeft)));
	ui.leDx->setText(QString::number(_plot->axisStepSize(QwtPlot::xBottom)));
	ui.leMinY->setText(QString::number(_plot->axisInterval(QwtPlot::yLeft).minValue()));
	ui.leMaxY->setText(QString::number(_plot->axisInterval(QwtPlot::yLeft).maxValue()));

}

void DialogSetPlotParams::on_pbSet_clicked(){
	int minx, maxx;
	minx = _plot->axisInterval(QwtPlot::xBottom).minValue();
	maxx = _plot->axisInterval(QwtPlot::xBottom).maxValue();

	_plot->setAxisScale(QwtPlot::yLeft, ui.leMinY->text().toInt(), ui.leMaxY->text().toInt(), ui.leDy->text().toInt());
	_plot->setAxisScale(QwtPlot::yRight, ui.leMinY->text().toInt() - 122.723, ui.leMaxY->text().toInt() - 122.723, ui.leDy->text().toInt());

	_plot->setAxisScale(QwtPlot::xBottom, minx, maxx, ui.leDx->text().toInt());
	_plot->replot();
	close();
}

void DialogSetPlotParams::on_pbCancel_clicked(){
	close();
}


