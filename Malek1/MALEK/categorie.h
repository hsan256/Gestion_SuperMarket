#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class categorie{
    public:
        categorie();
        categorie(QString,int);
        QString getType();
        bool ajouter();
        bool modifier(categorie );
        bool supprimer(QString);
        QSqlQueryModel * afficher();
    private:
        QString typeCategorie;
      int taux;
};

#endif // CATEGORIE_H
