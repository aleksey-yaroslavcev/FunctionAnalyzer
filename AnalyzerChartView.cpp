#include "AnalyzerChartView.h"

AnalyzerChartView::AnalyzerChartView(QWidget* parent):
    QtCharts::QChartView(parent)
{
    _chart.legend()->hide();

    // Customize chart title
    _chart.setTitleBrush(QBrush(Qt::black));
    _chart.setTitle("Functions comparing");

    _firstSeries.setPen(QPen(QRgb(0xff0000)));
    _secondSeries.setPen(QPen(QRgb(0x0000ff)));

    _chart.addSeries(&_firstSeries);
    _chart.addSeries(&_secondSeries);
    _chart.createDefaultAxes();

    this->setChart(&_chart);
    this->setRenderHint(QPainter::Antialiasing);
}

AnalyzerChartView::~AnalyzerChartView()
{

}

void AnalyzerChartView::setFirstFunction(IFunction* firstFunction)
{
    updateSeries(&_firstSeries, firstFunction);
}

void AnalyzerChartView::setSecondFunction(IFunction* secondFunction)
{
    updateSeries(&_secondSeries, secondFunction);
}

QtCharts::QChart* AnalyzerChartView::qtChart()
{
    return &_chart;
}

void AnalyzerChartView::updateSeries(QtCharts::QXYSeries* series, IFunction* function)
{
    _chart.removeSeries(series);
    series->clear();
    for (double x = -10.0; x < 10.0; x += 0.1) {
        *series << function->point(x);
    }
    _chart.addSeries(series);
}
