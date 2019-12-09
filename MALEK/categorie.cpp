#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "categorie.h"

categorie::categorie(){
    typeCategorie = "";
   taux=0;
}

categorie::categorie(QString typeCategorie,int taux){
    this->typeCategorie = typeCategorie;
    this->taux=taux;
}

QString categorie::getType(){
    return typeCategorie;
}


bool categorie::ajouter(){
    QSqlQuery query;
    QString idProduitS = QString::number(taux);
    query.prepare("INSERT INTO categorie (TYPE,TAUX) VALUES (:TYPE, :TAUX)");
    query.bindValue(":TYPE", typeCategorie);
    query.bindValue(":TAUX", idProduitS);
    return query.exec();
}


QSqlQueryModel *  categorie::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM categorie");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type de Categorie"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("taux de categorie"));
    return model;
}
bool categorie::modifier(categorie P){
    QSqlQuery query;
    QString taux = QString::number(P.taux);
    query.prepare("UPDATE categorie SET  TAUX =:taux , WHERE TYPE = :typeCategorie");
    query.bindValue(":typeCategorie",P.getType());
    query.bindValue(":TAUX",taux);
    return  query.exec();
}


bool categorie::supprimer(QString typeCategorie){
    QSqlQuery query;
    query.prepare("DELETE FROM categorie WHERE type = :typeCategorie");
    query.bindValue(":typeCategorie", typeCategorie);
    return query.exec();
}
