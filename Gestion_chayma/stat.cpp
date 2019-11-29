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
{

}
QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;


       if(query.exec("select service from Employe "))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="service_jour")
                count1++;
            else if(query.value(0).toString()=="service_nuit")
                count2++;
          }
        }
         QPieSeries *series;
       series = new QPieSeries();

       series->append("service_jour", count1);
       series->append("service_nuit", count2);
       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Les Types");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;


}
