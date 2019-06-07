#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QLineSeries>
#include <QCategoryAxis>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    qDeleteAll(_functions);
}

void MainWindow::registerFunction(IFunction* function)
{
    _functions.push_back(function);
}

void MainWindow::updateFunctionComboboxes()
{
    ui->cobF1Type->clear();
    ui->cobF2Type->clear();
    for (auto function : _functions) {
        ui->cobF1Type->addItem(function->description());
        ui->cobF2Type->addItem(function->description());
    }
}

void MainWindow::on_zoomInBut_clicked()
{
    ui->chart->qtChart()->zoomIn();
}

void MainWindow::on_zoomOutBut_clicked()
{
    ui->chart->qtChart()->zoomOut();
}

void MainWindow::on_scrollUpBut_clicked()
{
    ui->chart->qtChart()->scroll(0, 1);
}

void MainWindow::on_scrollDownBut_clicked()
{
    ui->chart->qtChart()->scroll(0, -1);
}

void MainWindow::on_scrollLeftBut_clicked()
{
    ui->chart->qtChart()->scroll(-1, 0);
}

void MainWindow::on_scrollRightBut_clicked()
{
    ui->chart->qtChart()->scroll(1, 0);
}

void MainWindow::on_resetBut_clicked()
{
    ui->chart->qtChart()->zoomReset();

}

void MainWindow::on_cobF1Type_activated(int index)
{
    ui->chart->setFirstFunction(_functions[index]);
}

void MainWindow::on_cobF2Type_activated(int index)
{
    ui->chart->setSecondFunction(_functions[index]);
}
