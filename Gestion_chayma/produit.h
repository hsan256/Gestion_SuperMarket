#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class produit
{
public:
    produit();
    produit(int ,int ,int);
    int get_code();
    int get_nbr();
    int get_prix();
    bool ajouter();
    QSqlQueryModel * afficher_taux();
    bool supprimer(int);
    bool modifier(produit);
    QSqlQueryModel * tri_code();
     QSqlQueryModel * tri_nbr();
     QSqlQueryModel * tri_prix();
    QSqlQueryModel * recherche_code(int);
    QSqlQueryModel * recherche_nbr(int);
    QSqlQueryModel * recherche_prix(int);
  //  QSqlQueryModel * stat();
private:
    int code ;
    int nbr;
   int prix;
};











#endif // PRODUIT_H
