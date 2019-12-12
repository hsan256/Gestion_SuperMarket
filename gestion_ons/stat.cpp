#include "stat.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include <QSqlRecord>

QT_CHARTS_USE_NAMESPACE

Stat::Stat()
{}
QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;

       if(query.exec("select prix_PromotionS from promotion"))
       {
       while(query.next())
         {

            if(query.value(0).toInt()>0 && query.value(0).toInt()<10)
                count1++;
            else if(query.value(0).toInt()>11 && query.value(0).toInt()<50)
                count2++;
            else if(query.value(0).toInt()>51 && query.value(0).toInt()<100)
                count3++;
          }
        }
         QPieSeries *series;
       series = new QPieSeries();

       qDebug()<<count1;
       qDebug()<<count2;        //Test counters.
       qDebug()<<count3;


       series->append("Entre 0 et 10", count1);
       series->append("Entre 10 et 50", count2);
       series->append("Entre 50 et 100", count3);
       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Les prix stat");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;


}
