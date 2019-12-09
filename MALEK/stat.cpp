#include "stat.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <string>
#include <QPainter>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtCharts/QPieSlice>
#include "produits.h"


QT_CHARTS_USE_NAMESPACE

Stat::Stat()
{

}
QChartView * Stat::Preparechart(){
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;

       if(query.exec("select quantiteProduit from produits"))
       {
       while(query.next())
         {
            if(query.value(0).toString()=="prix_elevee")
                count1++;
            else if(query.value(0).toString()=="prix_moyen")
                count2++;
            else
                count3++;
          }
        }
         QPieSeries *series;
       series = new QPieSeries();

       series->append("prix elevee", count1);
       series->append("prix moyen", count2);
       series->append("prix faible", count3);
       chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Les Types");
       chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;


}
