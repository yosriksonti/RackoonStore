#ifndef CAPTEUR_H
#define CAPTEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class Capteur
{public:
    Capteur();
    Capteur(int,int,int,int,QString);
    QString get_type();
    int get_id();
    int get_etat();
    int get_nombre();
    int get_zone();

    bool ajouter(int,int,int,int,QString);
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool Update(int,int,int,int,QString);
private:
    int etat,id,zone,nombre;
    QString type;

};
#endif // CAPTEUR_H
