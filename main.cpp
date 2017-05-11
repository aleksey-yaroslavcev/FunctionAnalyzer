#include "FunctionAnalyzer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FunctionAnalyzer w;
    w.show();
    return a.exec();
}
