#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "partenaire.h"
#include "stat.h"
#include "son.h"
#include "QMessageBox"
#include <QDebug>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QWidget>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabClient->setModel(tmpClient.afficher());
    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(s.Preparechart());
    ui->Stat->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_client_clicked()
{
    mettreMusique();
    int idClient = ui->id_client->text().toInt();
    QString nomClient = ui->Nom_client->text();
    QString prenomClient = ui->prenom_client->text();
    int ageClient = ui->age_client->text().toInt();
    Client cl(idClient, nomClient, prenomClient,ageClient);

    if(idClient < 999999 && ageClient > 0 && ageClient <80){
    bool test = cl.ajouter();
    if(test){
        ui->tabClient->setModel(tmpClient.afficher());
        qDebug() <<"Client ajouté";
        QMessageBox::information(nullptr, QObject::tr("Ajouter client"),
                    QObject::tr("client ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
       qDebug() <<"Erreur d'ajout de client";
       QMessageBox::critical(nullptr, QObject::tr("Ajouter client"),
                   QObject::tr("Erreur 2 !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
    }else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                    QObject::tr("Controle de Saisie!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Supprimer_client_clicked()
{
    mettreMusique();
    int idClient = ui->id_client_suppr->text().toInt();
    bool test = tmpClient.supprimer(idClient);
    if(test){
        ui->tabClient->setModel(tmpClient.afficher());
        qDebug() <<"Client supprimé";
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur de suppression !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Modifier_client_clicked()
{
    mettreMusique();
    int idClient = ui->id_client_modif->text().toInt();
    QString nomClient= ui->nom_client_modif->text();
    QString prenomClient = ui->Prenom_client_modif->text();
    int ageClient = ui->age_client_modif->text().toInt();
    Client cl(idClient, nomClient, prenomClient,ageClient);

    if(idClient < 999999 && ageClient > 0 && ageClient <80){
    bool test = cl.modifier();
    if(test){
        ui->tabClient->setModel(cl.afficher());
        qDebug() <<"Client modifier";
        QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                    QObject::tr("Client modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
       qDebug() <<"Erreur de modification de client";
       QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                   QObject::tr("Erreur 2 !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
    }else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                    QObject::tr("Controle de Saisie!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_Ajouter_partenaire_clicked()
{
    mettreMusique();

    int idPartenaire = ui->idPartenaire->text().toInt();
    QString nomPartenaire = ui->NomPartenaire->text();
    QString prenomPartenaire = ui->prenomPartenaire->text();
    Partenaire part(idPartenaire, nomPartenaire, prenomPartenaire);

    if(idPartenaire < 999999 ){
    bool test = part.ajouter();
    if(test){
        ui->tabClient->setModel(tmpPartenaire.afficher());
        qDebug() <<"Partenaire ajouté";
        QMessageBox::information(nullptr, QObject::tr("Ajouter partenaire"),
                    QObject::tr("partenaire ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
       qDebug() <<"Erreur d'ajout de partenaire";
       QMessageBox::critical(nullptr, QObject::tr("Ajouter partenaire"),
                   QObject::tr("Erreur 2 !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
    }else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                    QObject::tr("Controle de Saisie!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimerpartenaire_clicked()
{
    mettreMusique();

    int idPartenaire = ui->id_partenairesupp->text().toInt();
    bool test= tmpPartenaire.supprimer(idPartenaire);
    if(test)
    {ui->tabPartenaire->setModel(tmpPartenaire.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un partenaire"),
                    QObject::tr("partenaire supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un partenaire"),
                    QObject::tr("Erreur 2 !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifierPartenaire_clicked()
{
    mettreMusique();

    int idPartenaire = ui->idPartenairemdoif->text().toInt();
    QString nomPartenaire= ui->nomPartenairemodif->text();
    QString prenomPartenaire = ui->prenomPartenairemodif->text();
    Partenaire part(idPartenaire, nomPartenaire, prenomPartenaire);

    if(idPartenaire < 999999 ){
    bool test = part.modifier();
    if(test){
        ui->tabClient->setModel(part.afficher());
        qDebug() <<"Partenaire modifier";
        QMessageBox::information(nullptr, QObject::tr("Modifier un partenaire"),
                    QObject::tr("Partenaire modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
       qDebug() <<"Erreur de modification de partenaire";
       QMessageBox::critical(nullptr, QObject::tr("Modifier un partenaire"),
                   QObject::tr("Erreur 2 !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
    }else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                    QObject::tr("Controle de Saisie!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::display_list_client_partenaire()
{
    ui->tabClient->setModel(tmpClient.afficher());
    ui->tabPartenaire->setModel(tmpPartenaire.afficher());
}

void MainWindow::on_rechId_clicked()
{
    int id = ui->id_rech->text().toInt();
    ui->tabClient->setModel(tmpClient.recherche_id(id));
}

void MainWindow::on_id_rech_textChanged(const QString &arg1)
{
    int id = arg1.toInt();
    ui->tabClient->setModel(tmpClient.recherche_id(id));
}

void MainWindow::on_rechNom_clicked()
{
    QString nom = ui->nom_rech->text();
    ui->tabClient->setModel(tmpClient.recherche_nom(nom));
}

void MainWindow::on_nom_rech_textChanged(const QString &arg1)
{
    ui->tabClient->setModel(tmpClient.recherche_nom(arg1));
}

void MainWindow::on_identifianttri_clicked()
{
    ui->tabClient->setModel(tmpClient.trier_id());
}

void MainWindow::on_Trier_2_clicked()
{
    ui->tabClient->setModel(tmpClient.trier_age());
}

void MainWindow::on_pushButton_clicked()
{
    QPrinter printer;
    QPainter painter;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tabClient->render(&printer);
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

void MainWindow::on_combo_part_currentTextChanged(const QString &arg1)
{
            if(arg1=="")
                ui->tabPartenaire->setModel(tmpPartenaire.afficher());
            if(arg1 == "Trie par id")
                ui->tabPartenaire->setModel(tmpPartenaire.trier_id_part());
            else if (arg1 == "Rechercher par id")
                ui->tabPartenaire->setModel(tmpPartenaire.recherche_id_part(ui->partenaire_combo_line->text().toInt()));
}

void MainWindow::on_partenaire_combo_line_textChanged(const QString &arg1)
{
        int id = arg1.toInt();
        ui->tabPartenaire->setModel(tmpPartenaire.recherche_id_part(id));
}

void MainWindow::on_print_part_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tabPartenaire->render(&printer);
}
