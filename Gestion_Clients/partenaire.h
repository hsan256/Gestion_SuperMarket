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
private:
    QString nom_part,prenom_part;
    int id_part;
};


#endif // PARTENAIRE_H
