#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employe
{public:
    Employe();

    Employe(int,QString,QString,int,int,int,QString);
    QString get_nom();
    QString get_prenom();
    int get_cin();
    int get_age();
    int get_salaire();
    int get_nbheure();
    QString get_service();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(Employe );
     QSqlQueryModel * tri_cin();
     QSqlQueryModel * tri_nom();
     QSqlQueryModel * tri_prenom();
     QSqlQueryModel * tri_age();
     QSqlQueryModel * tri_salaire();
     QSqlQueryModel * tri_nbheure();
     QSqlQueryModel * recherche(int);
     //QSqlQueryModel * stat();
private:
    QString nom,prenom;
    int cin;
    int age;
    int salaire;
    int nbheure;
    QString service;
};

#endif // ETUDIANT_H
