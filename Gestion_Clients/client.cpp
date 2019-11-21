#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "client.h"

Client::Client()
{
    id=0;
    nom="";
    prenom="";
}

Client::Client(int id,QString nom,QString prenom)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
}

QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_id(){return  id;}

bool Client::ajouter(){
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO client (id, nom, prenom) "
                        "VALUES (:id, :nom, :prenom)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    return query.exec();
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    return model;
}

bool Client::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from client where id = :id");
    query.bindValue(":id", res);
    return query.exec();
}

bool Client::modifier(){
    QSqlQuery query;
    QString id_modif= QString::number(this->id);
    QString nom_modif= this->nom;
    QString prenom_modif= this->prenom;
    query.prepare("UPDATE client SET nom =:nom , prenom=:prenom WHERE id =:id");
    query.bindValue(":id",id_modif);
    query.bindValue(":nom",nom_modif);
    query.bindValue(":prenom",prenom_modif);
    return  query.exec();
}
