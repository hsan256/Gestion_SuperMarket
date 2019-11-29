#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parking.h"
#include <QMessageBox>
#include "bloc.h"

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
    ui->comboBox_etat_a_2->addItem("vide");
    ui->comboBox_etat_a_2->addItem("complet");

    ui->comboBox_bloc_m->addItem("A");
    ui->comboBox_bloc_m->addItem("B");
    ui->comboBox_etat_m_2->addItem("vide");
    ui->comboBox_etat_m_2->addItem("complet");
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
    int place = ui ->lineEdit_Num->text().toInt();
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

void MainWindow::on_pushButton_2_clicked()
{
    int place = ui->lineEdit_placem->text().toInt();
    QString etat = ui->comboBox_etat_m->currentText();
    parking p(place,etat);
    bool test = tmpParking.modifier(p);
    if (test)
    {
        ui->tabparking->setModel(tmpParking.afficher());
    }
}

void MainWindow::on_pushButton_actualiser_clicked()
{
    ui->tabparking->setModel(tmpParking.afficher());
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


void MainWindow::on_pushButton_supprimer_clicked()
{
    QString nom = ui ->lineEdit_nom_s->text();
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
    QString nom = ui->comboBox_bloc_m->currentText();
    QString etat = ui->comboBox_etat_m_2->currentText();
    int capacite = ui->lineEdit_capacite_m->text().toInt();
    bloc b(nom,capacite,etat);
    bool test = tmpbloc.modifier(b);
    if (test)
    {
        ui->tabbloc->setModel(tmpbloc.afficher());
    }
}

void MainWindow::on_pushButton_actualiser_2_clicked()
{
    ui->tabbloc->setModel(tmpbloc.afficher());
}

void MainWindow::on_pushButton_pdf_clicked()
{
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/hp/Documents/Hazem_project/pdf.pdf");
        QPainter painter;
        painter.begin(&printer);

        QFont font;
        QString bloc=ui->lineEdit_bloc_pdf->text();
        QString etat=ui->lineEdit_etat_pdf->text();
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
