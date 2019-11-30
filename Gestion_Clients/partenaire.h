#ifndef PARTENAIRE_H
#define PARTENAIRE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Partenaire
{
public:
    Partenaire();
    Partenaire(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * recherche_id_part(int);
    QSqlQueryModel * recherche_nom_part(QString);
    QSqlQueryModel * trier_id_part();

private:
    QString nom_part,prenom_part;
    int id_part;
};


#endif // PARTENAIRE_H
