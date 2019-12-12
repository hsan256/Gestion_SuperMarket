#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "promotion.h"

promotion::promotion(){
    numProduit = 0;
    prix_Promotion = 0;
    taux_Promotion=0;
}

promotion::promotion(int numProduit , int prix_promotion , int taux_promotion ){
    this->numProduit = numProduit;
    this->prix_Promotion = prix_promotion;
    this->taux_Promotion = taux_promotion;
}

int promotion::get_numProduit(){
    return numProduit;
}

int promotion::get_prix_Promotion(){
    return prix_Promotion;
}

int promotion::get_taux_promotion(){
    return taux_Promotion;
}

bool promotion::ajouter(){
    QSqlQuery query;
    QString numProduitS = QString::number(numProduit);
    QString prix_PromtionS = QString::number(prix_Promotion);
    QString taux_PromotionS = QString::number(taux_Promotion);
    query.prepare("INSERT INTO promotion (numProduitS,prix_PromotionS, taux_PromotionS ) VALUES (:numProduitS, :prix_PromtionS, :taux_PromotionS)");
    query.bindValue(":numProduitS", numProduitS);
    query.bindValue(":prix_PromtionS", prix_PromtionS);
    query.bindValue(":taux_PromotionS", taux_PromotionS);
    return query.exec();
}

QSqlQueryModel *  promotion::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM promotion");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numProduitS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix_PromotionS"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("taux_PromotionS"));
    return model;
}

bool promotion::supprimer(int numProduit){
    QSqlQuery query;
    QString numProduitS = QString::number(numProduit);
    query.prepare("DELETE FROM promotion WHERE  numProduitS = :numProduitS");
    query.bindValue(":numProduitS", numProduitS);
    return query.exec();
}

bool promotion::modifier(){
     QSqlQuery query;
    QString numProduitS = QString::number(get_numProduit());
    QString prix_PromotionS= QString::number (get_prix_Promotion());
    QString taux_PromotionS = QString::number (get_taux_promotion());
    query.prepare("UPDATE promotion SET taux_PromotionS = :taux_PromotionS, prix_PromotionS = :prix_PromotionS WHERE numProduitS = :numProduitS");
    query.bindValue(":numProduitS", numProduitS);
    query.bindValue(":prix_PromotionS", prix_PromotionS);
    query.bindValue(":taux_PromotionS", taux_PromotionS);
    return query.exec();
}

QSqlQueryModel * promotion::rechercher(int numProduit){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString nbr =QString :: number(numProduit);
    model->setQuery("SELECT * FROM promotion WHERE numProduitS = " + nbr);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numProduitS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix_PromotionS"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("taux_PromotionS"));
    return model;
}



QString test_tri(int c)
{
    if (c==0)
    {
        return "numProduitS" ;
    }
    else if (c==1)
    {
        return "prix_PromotionS";
    }
    else if (c==2)
    {
     return "taux_PromotionS" ;
    }


    return "NULL";
}



QSqlQueryModel * promotion::tri(int i)
{
    QString col = test_tri(i);
    QSqlQueryModel *model = new QSqlQueryModel() ;
    QString header = "SELECT * FROM promotion ORDER BY "+col;
    model->setQuery(header);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numProduitS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix_PromotionS"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("taux_PromotionS"));
    return model;
}

QSqlQueryModel * promotion::tri_prix(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM promotion order by prix_PromotionS ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numProduitS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix_PromotionS"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("taux_PromotionS"));
    return model;
}
