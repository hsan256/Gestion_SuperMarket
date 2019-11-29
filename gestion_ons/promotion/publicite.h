#ifndef PUBLICITE_H
#define PUBLICITE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class publicite{
    public:
        publicite();
        publicite(int, QString);
        int get_num();
        QString get_nom();
        bool ajouter();
        bool supprimer(int);
        bool modifierpub_2();
        QSqlQueryModel * afficher();
        QSqlQueryModel* recherche2 (QString,int);
        QSqlQueryModel * tri_pub_2();
    private:
        int num_article;
        QString nom_article;
};

#endif // PUBLICITE_HZ
