#include "bloc.h"
#include <QDebug>
bloc::bloc()
{
    nom="";
    etat="";
    capacite=0;
}

bloc::bloc(QString a,int b,QString c)
{
    nom=a;
    etat=c;
    capacite=b;
}
QString bloc::get_nom()
{return nom;}
int bloc::get_capacite(){return capacite;}
QString bloc::get_etat(){return etat;}
bool bloc :: ajouter()
{
QSqlQuery query;
QString res= QString::number(capacite);
query.prepare("INSERT INTO bloc (nom,etat,capacite) VALUES (:nom,:etat,:capacite)");
query.bindValue(":capacite", res);
query.bindValue(":nom",nom);
query.bindValue(":etat",etat);
return    query.exec();
}
QSqlQueryModel *bloc::rechercherbloc(QString etat)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from bloc where etat= '"+etat+"' ");
        query.exec();
        model->setQuery(query);
        return model;

}

QSqlQueryModel * bloc ::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from bloc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

bool bloc::supprimer(QString nom)
{
QSqlQuery query;
query.prepare("Delete from bloc where nom = :nom");
query.bindValue(":nom", nom);
return    query.exec();
}

bool bloc :: modifier (bloc b)
{
    QSqlQuery query;
    QString capacite = QString :: number(b.get_capacite());
    //QString etat = QString :: number(p.get_bloc());
    query.prepare("UPDATE bloc SET capacite= :capacite, etat=:etat WHERE nom= :nom");
    query.bindValue(":nom",b.get_nom());
    query.bindValue(":capacite",b.get_capacite());
    query.bindValue(":etat",b.get_etat());
    return query.exec();

}

