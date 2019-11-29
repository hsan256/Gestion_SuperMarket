#ifndef STAT_H
#define STAT_H
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QtCharts/QChartView>

#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class statistique
{
    QChart *chart;
    QChartView *chartView;
public:
    statistique();
    QChartView * Preparechart();

};

#endif // STAT_H
