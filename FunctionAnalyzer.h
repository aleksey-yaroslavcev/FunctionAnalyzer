#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FunctionAnalyzer.h"

class FunctionAnalyzer : public QMainWindow
{
    Q_OBJECT

public:
    FunctionAnalyzer(QWidget *parent = Q_NULLPTR);

private:
    Ui::FunctionAnalyzerClass ui;
};
