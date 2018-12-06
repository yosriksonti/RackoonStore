#ifndef SPOT_H
#define SPOT_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class Spot
{public:
    Spot();
    Spot(int,int,int,int);
    int get_etat();
    int get_zone();
    int get_id();
    int get_nombre();
    bool ajouter(int,int,int,int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Update(int,int,int,int);
    QSqlQueryModel* Find(int Zone);
private:
    int id,zone,nombre,etat;
};




#endif // SPOT_H
