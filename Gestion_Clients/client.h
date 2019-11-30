#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "son.h"

class Client
{
public:
    Client();
    Client(int,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    int get_age();
    //fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    //fonctions avancées
    QSqlQueryModel * recherche_id(int);
    QSqlQueryModel * recherche_nom(QString);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_age();
private:
    QString nom,prenom;
    int id,age;  
};

#endif // CLIENT_H
