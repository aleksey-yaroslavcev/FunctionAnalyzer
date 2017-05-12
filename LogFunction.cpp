#include "LogFunction.h"
#include <QApplication>


LogFunction::LogFunction()
{
	_params["a"] = 1;
	_description = QApplication::tr("Logarifmic function");
}


LogFunction::~LogFunction()
{
}

double LogFunction::GetValue(double x){
	double a = _params["a"];
	return a*log(x);
}
