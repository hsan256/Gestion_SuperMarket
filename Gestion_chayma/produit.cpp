#include "produit.h"
#include <QDebug>
#include <QMessageBox>
produit::produit()
{
code=0;
nbr=0;
prix=0;
}
produit::produit(int code,int nbr,int prix)
{
  this->code=code;
  this->nbr=nbr;
  this->prix=prix;
}
int produit::get_code(){return  code;}
int produit::get_nbr(){return nbr;}
int produit::get_prix(){return  prix;}

bool produit::ajouter()
{
QSqlQuery query;
QString res= QString::number(code);
QString res2= QString::number(nbr);
QString res3= QString::number(prix);
query.prepare("INSERT INTO Produit (code, nbr, prix) "
                    "VALUES (:code, :nbr, :prix)");
query.bindValue(":code", res);
query.bindValue(":nbr", res2);
query.bindValue(":prix", res3);

return    query.exec();
}

QSqlQueryModel * produit:: afficher_taux()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM Produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool produit::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("DELETE FROM Produit WHERE code = :code ");
query.bindValue(":code", res);
return    query.exec();
}


bool produit::modifier(produit p){
QSqlQuery query;
QString codeS = QString::number(p.get_code());
QString nbr = QString::number(p.get_nbr());
QString prix = QString::number(p.get_prix());
query.prepare("UPDATE produit SET nbr = :nbr, prix = :prix WHERE code = :codeS");
query.bindValue(":codeS", codeS);
query.bindValue(":nbr", nbr);
query.bindValue(":prix", prix);

return query.exec();
}

QSqlQueryModel * produit::tri_code(){

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from produit order by code ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    return model;
}


QSqlQueryModel * produit::tri_nbr(){

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from produit order by nbr ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

QSqlQueryModel * produit::tri_prix(){

QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select * from produit order by prix ASC ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    return model;
}



/*QSqlQueryModel * produit::stat(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("Select  Max(nbr) , Avg(nbr) , Min(nbr) from produit  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Max"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Avg"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Min"));
    return model;
}*/

QSqlQueryModel * produit::recherche_code(int code){
    QSqlQueryModel * model = new QSqlQueryModel();
  QString codeS = QString::number(code);
    model->setQuery("SELECT * FROM produit WHERE code = " + codeS);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nbr"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    return model;
}

QSqlQueryModel * produit::recherche_nbr(int nbr){
    QSqlQueryModel * model = new QSqlQueryModel();
  QString nbrS = QString::number(nbr);
    model->setQuery("SELECT * FROM produit WHERE nbr = " + nbrS);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nbr"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    return model;
}

QSqlQueryModel * produit::recherche_prix(int prix){
    QSqlQueryModel * model = new QSqlQueryModel();
  QString prixS = QString::number(prix);
    model->setQuery("SELECT * FROM produit WHERE prix = " + prixS);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nbr"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    return model;
}
