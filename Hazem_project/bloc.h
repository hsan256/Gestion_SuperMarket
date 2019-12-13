#ifndef BLOC_H
#define BLOC_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class bloc
{
public:
    bloc();
    bloc(QString,int,QString);
    QString get_nom();
    int get_capacite();
    QString get_etat();
    bool ajouter();
    bool modifier(bloc);
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel *rechercherbloc(QString etat);
private:
    QString nom;
    int capacite;
    QString etat;
};

#endif // BLOC_H
