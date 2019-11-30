#include "stat.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtCharts/QPieSlice>


QT_CHARTS_USE_NAMESPACE

Stat::Stat()
{}

QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;

       if(query.exec("select age from client"))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="Entre 0 et 10")
                count1++;
            else if(query.value(0).toString()=="Entre 10 et 50")
                count2++;
            else if(query.value(0).toString()=="Entre 50 et 80")
                count3++;
          }
        }
       QPieSeries *series;
       series = new QPieSeries();

       series->append("Entre 0 et 10", count1);
       series->append("Entre 10 et 50", count2);
       series->append("Entre 50 et 80", count3);
       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistique des Ages des clients");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;
}
