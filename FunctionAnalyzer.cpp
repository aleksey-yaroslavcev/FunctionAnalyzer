#include "FunctionAnalyzer.h"
#include "IFunction.h"
#include "SinFunction.h"
#include "LogFunction.h"
#include "LineFunction.h"
#include "SquarePolynomFuction.h"
#include "CubePolynomFunction.h"

#include "DialogSetPlotParams.h"

#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_point_data.h>
#include <QEvent>
#include <QMouseEvent>
#include <QMessageBox>

FunctionAnalyzer::FunctionAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	_func1=new LineFunction;
	_func2=new LineFunction;

	ui.plot->setCanvas(new QwtPlotCanvas);
	_curve = new QwtPlotCurve;
	_data = new QwtPointSeriesData;
	_curve->setData(_data);
	_curve->setPen(Qt::yellow);
	_curve->attach(ui.plot);
	_grid = new QwtPlotGrid();
	_grid->setMajorPen(QPen(Qt::darkGray, 0, Qt::DotLine));
	_grid->setMinorPen(QPen(Qt::darkGray, 0, Qt::DotLine));
	_grid->attach(ui.plot);
	ui.plot->canvas()->setCursor(Qt::ArrowCursor);
	ui.plot->canvas()->setContentsMargins(0, 0, 0, 0);
	ui.plot->canvas()->installEventFilter(this);
}

bool FunctionAnalyzer::eventFilter(QObject *object, QEvent *event){
	QwtPlotCanvas *canvas = static_cast<QwtPlotCanvas *>(object);
	switch (event->type())
	{
	case QEvent::MouseButtonPress:
	{
		const QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
		//Настройки графика
		if (mouseEvent->button() == Qt::RightButton) {
			DialogSetPlotParams *dlg = new DialogSetPlotParams;
			dlg->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint);
			dlg->init(ui.plot);
			dlg->show();
			return true;
		}
	}
	default:
		break;
	}
	return QObject::eventFilter(object, event);
}