#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "produits.h"

produits::produits(){
    idProduit = 0;
    quantiteProduit = prixProduit = "";
}

produits::produits(int idProduit, QString quantiteProduit, QString prixProduit){
    this->idProduit = idProduit;
    this->quantiteProduit = quantiteProduit;
    this->prixProduit = prixProduit;
}

int produits::getId(){
    return idProduit;
}

QString produits::getQuantite(){
    return quantiteProduit;
}

QString produits::getPrix(){
    return prixProduit;
}

bool produits::ajouter(){
    QSqlQuery query;
    QString idProduitS = QString::number(idProduit);
    query.prepare("INSERT INTO produits VALUES (:idProduitS, :quantiteProduit, :prixProduit)");
    query.bindValue(":idProduitS", idProduitS);
    query.bindValue(":quantiteProduit", quantiteProduit);
    query.bindValue(":prixProduit", prixProduit);
    return query.exec();
}

QSqlQueryModel *  produits::afficher(QString rech, QString comboRech){
    QSqlQueryModel * model = new QSqlQueryModel();
    qDebug() << rech + " " + comboRech;
    model->setQuery("SELECT * FROM produits WHERE " + comboRech + " LIKE '%" + rech + "%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model;
}

bool produits::supprimer(int idProduit){
    QSqlQuery query;
    QString idProduitS = QString::number(idProduit);
    query.prepare("DELETE FROM produits WHERE id_produit = :idProduitS");
    query.bindValue(":idProduitS", idProduitS);
    return query.exec();
}

bool produits::modifier(produits p){
    QSqlQuery query;
    QString idProduitS = QString::number(p.getId());
    query.prepare("UPDATE produits SET quantite = :quantiteProduit, prix_produit = :prixProduit WHERE id_produit = :idProduitS");
    query.bindValue(":idProduitS", idProduitS);
    query.bindValue(":quantiteProduit", p.getQuantite());
    query.bindValue(":prixProduit", p.getPrix());
    return query.exec();
}

QSqlQueryModel* produits :: tri_id() {

QSqlQueryModel *model = new QSqlQueryModel() ;
    model->setQuery ( "SELECT * FROM produits ORDER BY id_produit ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model ;
}
QSqlQueryModel* produits :: tri_quant() {

QSqlQueryModel *model = new QSqlQueryModel() ;
    model->setQuery ( "SELECT * FROM produits ORDER BY QUANTITE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model ;
}

QSqlQueryModel* produits :: tri_prix() {

QSqlQueryModel *model = new QSqlQueryModel() ;
    model->setQuery ( "SELECT * FROM produits ORDER BY PRIX_PRODUIT ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model ;
}
QSqlQueryModel * produits::recherche_nbr(int idProduit){
    QSqlQueryModel * model = new QSqlQueryModel();
  QString idProduits = QString::number(idProduit);
    model->setQuery("SELECT * FROM produit WHERE id_produit =" + idProduits);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model;
}
QSqlQueryModel * produits::recherche_quan(QString quantiteProduit){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM produit WHERE QUANTITE ='" + quantiteProduit + "'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model;
}
QSqlQueryModel * produits::recherche_prix(QString prixProduit){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM produit WHERE Prix ='" + prixProduit+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prix"));
    return model;
}

