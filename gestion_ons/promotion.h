#ifndef PROMOTION_H
#define PROMOTION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class promotion{
    public:
        promotion();
        promotion(int, int, int);
        int get_numProduit();
        int get_prix_Promotion();
        int get_taux_promotion();
        bool ajouter();
        bool supprimer(int);
        bool modifier();
        QSqlQueryModel * afficher();
        QSqlQueryModel * rechercher(int);
        QSqlQueryModel * tri(int);
        QSqlQueryModel * tri_prix();
    private:
        int numProduit;
        int prix_Promotion;
        int taux_Promotion;
};

#endif // PROMTION_H
