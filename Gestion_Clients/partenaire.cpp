#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "partenaire.h"

Partenaire::Partenaire()
{
    id_part=0;
    nom_part="";
    prenom_part="";
}

Partenaire::Partenaire(int id,QString nom,QString prenom)
{
  this->id_part=id;
  this->nom_part=nom;
  this->prenom_part=prenom;
}

QString Partenaire::get_nom(){return  nom_part;}
QString Partenaire::get_prenom(){return prenom_part;}
int Partenaire::get_id(){return  id_part;}

bool Partenaire::ajouter(){
    QSqlQuery query;
    QString res= QString::number(id_part);
    query.prepare("INSERT INTO partenaire (id, nom, prenom) "
                        "VALUES (:id, :nom, :prenom)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom_part);
    query.bindValue(":prenom", prenom_part);
    return query.exec();
}


QSqlQueryModel * Partenaire::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from partenaire");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    return model;
}

bool Partenaire::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from partenaire where id = :id");
    query.bindValue(":id", res);
    return query.exec();
}

bool Partenaire::modifier(){
    QSqlQuery query;
    QString id_modif= QString::number(this->id_part);
    QString nom_modif= this->nom_part;
    QString prenom_modif= this->prenom_part;
    query.prepare("UPDATE partenaire SET nom =:nom , prenom=:prenom WHERE id =:id");
    query.bindValue(":id", id_modif);
    query.bindValue(":nom", nom_modif);
    query.bindValue(":prenom", prenom_modif);
    return  query.exec();
}

QSqlQueryModel * Partenaire::recherche_id_part(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(id);
    model->setQuery("Select * From partenaire WHERE id = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    return model;
}

QSqlQueryModel * Partenaire::recherche_nom_part(QString nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From partenaire WHERE nom ='" +nom+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    return model;
}

QSqlQueryModel * Partenaire::trier_id_part()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from partenaire\
                         Order by id DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    return model;
}
