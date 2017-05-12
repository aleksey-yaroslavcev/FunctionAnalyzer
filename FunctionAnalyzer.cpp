#include "FunctionAnalyzer.h"
#include "IFunction.h"
#include "SinFunction.h"
#include "LogFunction.h"
#include "LineFunction.h"
#include "SquarePolynomFuction.h"
#include "CubePolynomFunction.h"

FunctionAnalyzer::FunctionAnalyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	_fuctions.push_back(new LineFunction);
	_fuctions.push_back(new LineFunction);
}
