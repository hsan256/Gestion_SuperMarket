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

       if(query.exec("select sexe from client"))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="Homme"){
                count1++; }
            else if(query.value(0).toString()=="Femme"){
                count2++;}
          }
        }
       QPieSeries *series;
       series = new QPieSeries();

       series->append("Homme", count1);
       series->append("Femme", count2);

       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistique des sexe des clients");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;
}
