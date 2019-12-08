#include "parking.h"
#include <QDebug>

parking::parking()
{
 Num_place=0;
 Etat_place="";
}
parking :: parking (int Num_place , QString Etat_place)
{
    this->Num_place=Num_place;
    this->Etat_place=Etat_place;

}
int parking :: get_Num_place(){return Num_place;}
QString parking :: get_Etat_place(){return Etat_place;}
bool parking :: ajouter()
{
QSqlQuery query;
QString res= QString::number(Num_place);
query.prepare("INSERT INTO parking (Num_place,Etat_place ) VALUES (:Num_place, :Etat_place)");
query.bindValue(":Num_place", res);
query.bindValue(":Etat_place",Etat_place);

return    query.exec();
}
QSqlQueryModel * parking ::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parking");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_place"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat_place "));
    return model;
}

bool parking::supprimer(int Num_place)
{
QSqlQuery query;
QString res= QString::number(Num_place);
query.prepare("Delete from parking where Num_place = :Num_place ");
query.bindValue(":Num_place", res);
return    query.exec();
}
bool parking :: modifier (parking p)
{
    QSqlQuery query;
    QString place = QString :: number(p.get_Num_place());
    //QString etat = QString :: number(p.get_bloc());
    query.prepare("UPDATE parking SET Etat_place= :Etat_place WHERE Num_place= :Num_place");
    query.bindValue(":Num_place",place);
    query.bindValue(":Etat_place",p.get_Etat_place());
    return query.exec();

}
