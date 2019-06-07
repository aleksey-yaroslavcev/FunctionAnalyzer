#include "MainWindow.h"
#include <QApplication>

#include "CubePolynomFunction.h"
#include "LineFunction.h"
#include "LogFunction.h"
#include "SinFunction.h"
#include "SquarePolynomFuction.h"
#include "XLogXFunction.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.registerFunction(new CubePolynomFunction());
    w.registerFunction(new LineFunction());
    w.registerFunction(new LogFunction());
    w.registerFunction(new SinFunction());
    w.registerFunction(new SquarePolynomFuction());
    w.registerFunction(new XLogXFunction());
    w.updateFunctionComboboxes();

    w.show();

    return a.exec();
}
