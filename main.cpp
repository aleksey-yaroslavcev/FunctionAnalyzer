#include "FunctionAnalyzer.h"
#include <QtWidgets/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QTranslator translator;
	translator.load("functionanalyzer_ru");
	a.installTranslator(&translator);
	FunctionAnalyzer w;
    w.show();
    return a.exec();
}
