#ifndef CLIMATISEUR_H
#define CLIMATISEUR_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class Climatiseur
{public:
    Climatiseur();
    Climatiseur(int,int,int,int,int);
    int get_etat();
    int get_zone();
    int get_temp();
    int get_id();
    int get_nombre();
    bool ajouter(int,int,int,int,int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool Update(int,int,int,int,int);
    QSqlQueryModel* Find(int zone);

private:

    int id,zone,etat,temp,nombre;
};

#endif // CLIMATISEUR_H
