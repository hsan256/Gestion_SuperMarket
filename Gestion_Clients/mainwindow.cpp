#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "partenaire.h"
#include "QMessageBox"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabClient->setModel(tmpClient.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ajouter_client_clicked()
{
    int idClient = ui->id_client->text().toInt();
    QString nomClient = ui->Nom_client->text();
    QString prenomClient = ui->prenom_client->text();
    Client cl(idClient, nomClient, prenomClient);
    bool test = cl.ajouter();
    if(test){
        ui->tabClient->setModel(tmpClient.afficher());
        qDebug() <<"Client ajouté";
    }else{
       qDebug() <<"Erreur d'ajout de client";
    }
}

void MainWindow::on_Supprimer_client_clicked()
{
    int idClient = ui->id_client_suppr->text().toInt();
    bool test= tmpClient.supprimer(idClient);
    if(test)
    {ui->tabClient->setModel(tmpClient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur 2 !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_Modifier_client_clicked()
{
    int idClient = ui->id_client_modif->text().toInt();
    QString nomClient= ui->nom_client_modif->text();
    QString prenomClient = ui->Prenom_client_modif->text();
    Client cl(idClient, nomClient, prenomClient);
    bool test = cl.modifier();
    if(test){
        ui->tabClient->setModel(cl.afficher());
    }
}

void MainWindow::on_Ajouter_partenaire_clicked()
{
    int idPartenaire = ui->idPartenaire->text().toInt();
    QString nomPartenaire = ui->NomPartenaire->text();
    QString prenomPartenaire = ui->prenomPartenaire->text();
    Partenaire part(idPartenaire, nomPartenaire, prenomPartenaire);
    bool test = part.ajouter();
    if(test){
        ui->tabPartenaire->setModel(tmpPartenaire.afficher());
        qDebug() <<"Partenaire ajouté";
    }else{
        qDebug() <<"Erreur d'ajout de partenaire";
    }
}

void MainWindow::on_supprimerpartenaire_clicked()
{
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
    int idPartenaire = ui->idPartenairemdoif->text().toInt();
    QString nomPartenaire= ui->nomPartenairemodif->text();
    QString prenomPartenaire = ui->prenomPartenairemodif->text();
    Partenaire part(idPartenaire, nomPartenaire, prenomPartenaire);
    bool test = tmpPartenaire.modifier();
    if(test){
        ui->tabPartenaire->setModel(tmpPartenaire.afficher());
    }
}

void MainWindow::display_list_client_partenaire(){
    ui->tabClient->setModel(tmpClient.afficher());
    ui->tabPartenaire->setModel(tmpPartenaire.afficher());
}

void MainWindow::on_recherche_clicked()
{
    int id = ui->id_6->text().toInt();
    ui->tabClient->setModel(tmpClient.recherche(id));
}


void MainWindow::on_Trier_clicked()
{
    ui->tabClient->setModel(tmpClient.trier());
}
