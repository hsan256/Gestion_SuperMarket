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

Stat::Stat(){

}

QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;

       if(query.exec("select Etat_place from parking"))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="Reserve"){
                count1++; }
            else if(query.value(0).toString()=="Vide"){
                count2++;}
          }
        }
       QPieSeries *series;
       series = new QPieSeries();

       series->append("Reserve", count1);
       series->append("Vide", count2);

       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistique des Etat de place de parking");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;
}
