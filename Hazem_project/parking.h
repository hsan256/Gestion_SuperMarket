#ifndef PARKING_H
#define PARKING_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class parking
{
public:
    parking();
    parking(int,QString);
    int get_Num_place();
    QString get_Etat_place();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(parking);
    QSqlQueryModel * combox8();
    QSqlQueryModel *trierparking(QString);
    QSqlQueryModel *rechercherparking(QString Num_place);
private:
    int Num_place;
    QString Etat_place;
};

#endif // PARKING_H
