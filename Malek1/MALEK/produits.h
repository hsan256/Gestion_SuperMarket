#ifndef PRODUITS_H
#define PRODUITS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class produits{
    public:
        produits();
        produits(int, QString, QString);
        int getId();
        QString getQuantite();
        QString getPrix();
        bool ajouter();
        bool supprimer(int);
         bool modifier(produits);
        QSqlQueryModel * afficher(QString, QString);
        QSqlQueryModel *  tri_id();
        QSqlQueryModel *  tri_quant();
        QSqlQueryModel *  tri_prix();
        QSqlQueryModel * recherche(int );
        QSqlQueryModel * recherche_nbr(int idProduit);
        QSqlQueryModel * recherche_quan(QString quantiteProduit);
        QSqlQueryModel * recherche_prix(QString prixProduit);
    private:
        int idProduit;
        QString quantiteProduit, prixProduit;
};

#endif // PRODUITS_H
