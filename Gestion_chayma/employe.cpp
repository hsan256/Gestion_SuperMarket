#include "employe.h"
#include <QDebug>
Employe::Employe()
{
cin=0;
age=0;
salaire=0;
nbheure=0;
prenom="";
nom="";
service="";
}
Employe::Employe(int cin,QString nom,QString prenom,int age,int salaire,int nbheure,QString service)
{
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
  this->salaire=salaire;
    this->nbheure=nbheure;
    this->service=service;
}
QString Employe::get_nom(){return  nom;}
QString Employe::get_prenom(){return prenom;}
int Employe::get_cin(){return  cin;}
int Employe::get_age(){return  age;}
int Employe::get_salaire(){return  salaire;}
int Employe::get_nbheure(){return  nbheure;}
QString Employe::get_service(){return service;}

bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
QString res2= QString::number(age);
QString res3= QString::number(salaire);
QString res4= QString::number(nbheure);
query.prepare("INSERT INTO Employe (CIN, NOM, PRENOM, AGE, SALAIRE, NBHEURE,service) "
                    "VALUES (:cin, :nom, :prenom, :age, :salaire, :nbheure, :service)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", res2);
query.bindValue(":salaire", res3);
query.bindValue(":nbheure", res4);
query.bindValue(":service", service);
return    query.exec();
}

QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM Employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nbheure"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("service"));
    return model;
}

bool Employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("DELETE FROM Employe WHERE cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}

bool Employe::modifier(Employe e){
QSqlQuery query;
QString CIN = QString::number(e.get_cin());
QString age = QString::number(e.get_age());
QString salaire = QString::number(e.get_salaire());
QString nbheure = QString::number(e.get_nbheure());
query.prepare("UPDATE Employe SET nom = :nom, prenom = :prenom, age = :age,salaire = :salaire, nbheure = :nbheure WHERE CIN = :CIN");
query.bindValue(":CIN",CIN);
query.bindValue(":nom",e.get_nom());
query.bindValue(":prenom",e.get_prenom());
query.bindValue(":age",age);
query.bindValue(":salaire",salaire);
query.bindValue(":nbheure",nbheure);

return query.exec();
}

QSqlQueryModel * Employe::tri_cin(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Employe order by cin ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbheure"));
    return model;
}

QSqlQueryModel * Employe::tri_nom(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Employe order by nom ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbheure"));
    return model;
}

QSqlQueryModel * Employe::tri_prenom(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Employe order by prenom ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbheure"));
    return model;
}

QSqlQueryModel * Employe::tri_age(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Employe order by age ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbheure"));
    return model;
}

QSqlQueryModel * Employe::tri_salaire(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Employe order by salaire ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbheure"));
    return model;
}

QSqlQueryModel * Employe::tri_nbheure(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from Employe order by nbheure ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("nbheure"));
    return model;
}


/*QSqlQueryModel * Employe::stat(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select  Max(nbheure) , Avg(nbheure) , Min(nbheure) from Employe  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Max"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Avg"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Min"));
    return model;
}*/

QSqlQueryModel * Employe::recherche(int cin){
    QSqlQueryModel * model = new QSqlQueryModel();
  QString cinS = QString::number(cin);
    model->setQuery("SELECT * FROM Employe WHERE cin = " + cinS);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nbheure"));
    return model;
}
QSqlQueryModel * Employe::combobox(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select cin from Employe ");
    return  model;
}
