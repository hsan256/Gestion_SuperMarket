#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parking.h"
#include "bloc.h"
#include "stat.h"
#include <QMessageBox>
#include <QDebug>
#include <QWidget>
#include <QTableView>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox_etat_a->addItem("Reserve");
    ui->comboBox_etat_a->addItem("Vide");
    ui->comboBox_etat_m->addItem("Reserve");
    ui->comboBox_etat_m->addItem("Vide");

    ui->comboBox_bloc_a->addItem("A");
    ui->comboBox_bloc_a->addItem("B");
    ui->comboBox_etat_a_2->addItem("Vide");
    ui->comboBox_etat_a_2->addItem("Complet");

    ui->comboBox_bloc_m->addItem("A");
    ui->comboBox_bloc_m->addItem("B");
    ui->comboBox_etat_m_2->addItem("Vide");
    ui->comboBox_etat_m_2->addItem("Complet");


    ui->comboBox_E->addItem("Reserve");
    ui->comboBox_E->addItem("Vide");
    ui->comboBox_B->addItem("A");
    ui->comboBox_B->addItem("B");
    ui->comboBox_Num->setModel(tmpParking.combox8());
    ui->comboBox_etat_m_p->setModel(tmpParking.combox8());

    ui->comboBox_S->addItem("A");
    ui->comboBox_S->addItem("B");

    ui->comboBox_rechbloc->addItem("Complet");
    ui->comboBox_rechbloc->addItem("Vide");

    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(s.Preparechart());
    ui->Stat->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int Num_place = ui->lineEdit_Place->text().toInt();
    QString Etat_place = ui ->comboBox_etat_a->currentText();
    parking p(Num_place,Etat_place);
      bool test=p.ajouter();
      if(test)
      {ui->tabparking->setModel(tmpParking.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter une place"),
                        QObject::tr("place ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter une place"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_pb_supprimer_clicked()
{
    int place = ui ->comboBox_Num->currentText().toInt();
    bool test=tmpParking.supprimer(place);
    if(test)
    {ui->tabparking->setModel(tmpParking.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une place"),
                    QObject::tr("place supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une place"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_actualiser_clicked()
{
    ui->tabparking->setModel(tmpParking.afficher());
    QSqlQuery query;

}

void MainWindow::on_pushButton_2_clicked()
{
    int place = ui->comboBox_etat_m_p->currentText().toInt();
    QString etat = ui->comboBox_etat_m->currentText();
    parking p(place,etat);
    bool test = tmpParking.modifier(p);
    if (test)
    {
        ui->tabparking->setModel(tmpParking.afficher());
    }
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int capacite = ui->lineEdit_capacite->text().toInt();
    QString etat = ui->comboBox_etat_a_2->currentText();
    QString nom =  ui->comboBox_bloc_a->currentText();
    bloc b(nom,capacite,etat);
      bool test=b.ajouter();
      if(test)
      {ui->tabbloc->setModel(tmpbloc.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("Ajouter une place"),
                        QObject::tr("place ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter une place"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_actualiser_2_clicked()
{
    ui->tabbloc->setModel(tmpbloc.afficher());
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QString nom = ui ->comboBox_S->currentText();
    bool test=tmpbloc.supprimer(nom);
    if(test)
    {ui->tabbloc->setModel(tmpbloc.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une place"),
                    QObject::tr("place supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une place"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    QString Nom = ui->comboBox_bloc_m->currentText();
    QString Etat = ui->comboBox_etat_m_2->currentText();
    int Capacite = ui->lineEdit_capacite_m->text().toInt();
    bloc b(Nom,Capacite,Etat);
    bool test = tmpbloc.modifier(b);
    if (test)
    {
        ui->tabbloc->setModel(tmpbloc.afficher());
    }
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/hp/Desktop/2A6/Project_Hazem/pdf.pdf");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    QString bloc=ui->comboBox_B->currentText();
    QString etat=ui->comboBox_E->currentText();
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(20,300,"bloc :");
    painter.drawText(20,500,"etat :");

    font.setPixelSize(22);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(250,300,bloc);
    painter.drawText(250,500,etat);
    painter.end();

}



void MainWindow::on_pushtrier_clicked()
{
    QString col ;
        qDebug()<< "triii " ;
       QModelIndexList a = ui->tabparking->selectionModel()->selectedColumns() ;
    for (int i =0 ;i< a.count();i++){
     col =  ui->tabparking->selectionModel()->model()->headerData(a.at(i).column(),Qt::Horizontal).toString();
    qDebug() << col;
    }
         parking *e= new parking();
         ui->tabparking->setModel(e->trierparking(col));
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    qDebug()<<"oooooooo";
    QString valeur=ui->lineEdit_R->text();
        parking *e=new parking();
        ui->tabparking->setModel(e->rechercherparking(valeur));
}

void MainWindow::on_pushButton_rb_clicked()
{
    qDebug()<<"oooooooo";
    QString valeur=ui->comboBox_rechbloc->currentText();
        bloc *e=new bloc();
        ui->tabbloc->setModel(e->rechercherbloc(valeur));
}

void MainWindow::on_Stat_currentChanged(int index)
{
    if(index==2)
    {
        delete mainLayout;
        mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(s.Preparechart());

        ui->Stat->setLayout(mainLayout);
    }
}
