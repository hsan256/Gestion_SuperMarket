#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "publicite.h"
#include <QMessageBox>
#include "mainwindow.h"

publicite::publicite()
{
    num_article = 0;
    nom_article="";
}

publicite::publicite(int num_article , QString nom_article){
    this->num_article = num_article;
    this->nom_article= nom_article;
}

int publicite::get_num(){
    return num_article;
}

QString publicite::get_nom(){
    return nom_article;
}

bool publicite::ajouter(){
    QSqlQuery query;
    QString num_articleS = QString::number(num_article);
    QString nom_articleS = QString(nom_article);
    query.prepare("INSERT INTO publicite(num_articleS, nom_articleS) VALUES (:num_articleS, :nom_articleS)");
    query.bindValue(":num_articleS", num_articleS);
    query.bindValue(":nom_articleS",nom_articleS);
    if(query.exec())
    {

        QMessageBox::critical(nullptr, QObject::tr("Succée !"),
                    QObject::tr("Ajout avec succée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                    QObject::tr("Ajout not successfull.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
 return query.exec();
}

    QSqlQueryModel *  publicite::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * from publicite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_articleS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_articleS"));
    return model;
}

bool publicite::supprimer(int num_article){
    QSqlQuery query;
    QString num_articleS = QString::number(num_article);
    query.prepare("DELETE from publicite WHERE num_articleS = :num_articleS");
    query.bindValue(":num_articleS", num_articleS);
    if(query.exec())
    {

        QMessageBox::critical(nullptr, QObject::tr("Succée !"),
                    QObject::tr("Suppression avec succée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                    QObject::tr("Suppression not successfull.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    return query.exec();
}

bool publicite::modifierpub_2(){
    QSqlQuery query;
    QString num_articleS = QString::number(get_num());
    QString nom_articleS = QString(get_nom());
    query.prepare("UPDATE publicite SET nom_articleS = :nom_articleS WHERE num_articleS = :num_articleS");
    query.bindValue(":num_articleS", num_articleS);
    query.bindValue(":nom_articleS", nom_articleS);
    return query.exec();
}

QString test_recherche(int c)
{
    if (c==0)
    {
        return "NUM_ARTICLES" ;
    }
    else if (c==1)
    {
        return "NOM_ARTICLES";
    }
    return "NULL";
}


QSqlQueryModel* publicite::recherche2(QString x,int i)
{
    QString col = test_recherche(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT* FROM publicite WHERE "+col+" LIKE '"+x+"%'";
    model->setQuery(header);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_articleS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_articleS"));
    return model;
}


QSqlQueryModel * publicite::tri_pub_2(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM publicite order by num_articleS ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_articleS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_articleS"));
    return model;
}

