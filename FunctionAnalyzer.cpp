// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "FunctionAnalyzer.h"
#include "IFunction.h"
#include "SinFunction.h"
#include "LogFunction.h"
#include "LineFunction.h"
#include "SquarePolynomFuction.h"
#include "CubePolynomFunction.h"
#include "XLogXFunction.h"

#include "DialogSetPlotParams.h"

#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_point_data.h>
#include <QEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QList>


FunctionAnalyzer::FunctionAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

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

	_functionPool.push_back(new LineFunction);
	_functionPool.push_back(new SquarePolynomFuction);
	_functionPool.push_back(new CubePolynomFunction);
	_functionPool.push_back(new LogFunction);
	_functionPool.push_back(new SinFunction);
	_functionPool.push_back(new XLogXFunction);

	FillFunctionsCombo(ui.cobFunc1);
	FillFunctionsCombo(ui.cobFunc2);
	
	for (unsigned int i = 0; i < _functionPool.size(); ++i){
		_grpBoxesF1.push_back(new QGroupBox());
		ui.func1Layout->addWidget(_grpBoxesF1.at(i));

		QFormLayout* layout = new QFormLayout;
		QList<QString> paramList = _functionPool.at(i)->GetParamsList();
		for (unsigned int j = 0; j < paramList.size(); j++){
			layout->addRow(new QLabel(paramList.at(j)), new QLineEdit);
		}
		
		_grpBoxesF1.at(i)->setLayout(layout);
		_grpBoxesF1.at(i)->hide();
	}
	ui.func1Layout->addItem(new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

	for (unsigned int i = 0; i < _functionPool.size(); ++i){
		_grpBoxesF2.push_back(new QGroupBox());
		ui.func2Layout->addWidget(_grpBoxesF2.at(i));

		QFormLayout* layout = new QFormLayout;
		QList<QString> paramList = _functionPool.at(i)->GetParamsList();
		for (unsigned int j = 0; j < paramList.size(); j++){
			layout->addRow(new QLabel(paramList.at(j)),new QLineEdit);
		}

		_grpBoxesF2.at(i)->setLayout(layout);
		_grpBoxesF2.at(i)->hide();
	}
	ui.func2Layout->addItem(new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));
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

void FunctionAnalyzer::FillFunctionsCombo(QComboBox *cob){
	cob->clear();
	cob->insertItem(0,QString("----"));
	for (unsigned int i = 0; i < _functionPool.size(); ++i)
		cob->insertItem(i+1,_functionPool.at(i)->GetFunctionDescription());
}

void FunctionAnalyzer::on_cobFunc1_currentIndexChanged(int idx){
	for (unsigned int i = 0; i < _grpBoxesF1.size(); i++)
		_grpBoxesF1.at(i)->hide();
	if (idx>0)
		_grpBoxesF1.at(idx - 1)->show();
}

void FunctionAnalyzer::on_cobFunc2_currentIndexChanged(int idx){
	for (unsigned int i = 0; i < _grpBoxesF2.size(); i++)
		_grpBoxesF2.at(i)->hide();
	if (idx>0)
		_grpBoxesF2.at(idx - 1)->show();
}
