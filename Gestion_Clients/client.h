#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Client
{
public:
    Client();
    Client(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    //fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    //fonctions avancées
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * trier();

private:
    QString nom,prenom;
    int id;
};

#endif // CLIENT_H
