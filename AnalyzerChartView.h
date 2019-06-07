#pragma once
#include <QChartView>
#include <QSplineSeries>
#include <QCategoryAxis>

#include "IFunction.h"

class AnalyzerChartView : public QtCharts::QChartView
{
public:
    AnalyzerChartView(QWidget* parent = nullptr);
    ~AnalyzerChartView() override;

    void setFirstFunction(IFunction* firstFunction);
    void setSecondFunction(IFunction* secondFunction);

    QtCharts::QChart* qtChart();

private:
    void updateSeries(QtCharts::QXYSeries* series, IFunction* function);
    QtCharts::QChart _chart;
    QtCharts::QSplineSeries _firstSeries;
    QtCharts::QSplineSeries _secondSeries;
};

