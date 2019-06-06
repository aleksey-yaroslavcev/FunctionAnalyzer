#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QLineSeries>
#include <QCategoryAxis>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _chart = new QtCharts::QChart;
    _chart->legend()->hide();

    QtCharts::QLineSeries* series = new QtCharts::QLineSeries();
    *series << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
    _chart->addSeries(series);

    // Customize series
    QPen pen(QRgb(0x000000));
    series->setPen(pen);

    // Customize chart title
    _chart->setTitleBrush(QBrush(Qt::black));
    _chart->setTitle("Customchart example");

    QtCharts::QCategoryAxis* axisX = new QtCharts::QCategoryAxis();
    QtCharts::QCategoryAxis* axisY = new QtCharts::QCategoryAxis();

    // Customize axis label font
    QFont labelsFont;
    labelsFont.setPixelSize(12);
    axisX->setLabelsFont(labelsFont);
    axisY->setLabelsFont(labelsFont);

    // Customize axis colors
    QPen axisPen(QRgb(0xd18952));
    axisPen.setWidth(2);
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // Customize axis label colors
    QBrush axisBrush(Qt::white);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
    axisY->setShadesVisible(true);

    axisX->append("low", 10);
    axisX->append("optimal", 20);
    axisX->append("high", 30);
    axisX->setRange(0, 30);

    axisY->append("slow", 10);
    axisY->append("med", 20);
    axisY->append("fast", 30);
    axisY->setRange(0, 30);

    _chart->addAxis(axisX, Qt::AlignBottom);
    _chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    ui->chart->setChart(_chart);
    ui->chart->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _chart;
}
