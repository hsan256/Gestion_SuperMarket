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
    age=0;
}

Client::Client(int id,QString nom,QString prenom, int age)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
}

QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
int Client::get_id(){return  id;}
int Client::get_age(){return age;}

bool Client::ajouter(){
    QSqlQuery query;
    QString res= QString::number(id);
    QString rec= QString::number(age);
    query.prepare("INSERT INTO client (id, nom, prenom, age) "
                        "VALUES (:id, :nom, :prenom, :age)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", rec);
    return query.exec();
}

QSqlQueryModel * Client::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
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
    QString age_modif= QString::number(this->age);
    query.prepare("UPDATE client SET nom =:nom , prenom=:prenom WHERE id =:id");
    query.bindValue(":id",id_modif);
    query.bindValue(":nom",nom_modif);
    query.bindValue(":prenom",prenom_modif);
    query.bindValue(":age",age_modif);
    return  query.exec();
}

QSqlQueryModel * Client::recherche_id(int id){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(id);
    model->setQuery("Select * From client WHERE id = " + res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    return model;
}

QSqlQueryModel * Client::recherche_nom(QString nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From client WHERE nom ='" +nom+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    return model;
}

QSqlQueryModel * Client::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from client\
                         Order by id ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    return model;
}

QSqlQueryModel * Client::trier_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from client\
                         Order by age ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    return model;
}
