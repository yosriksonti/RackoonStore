#ifndef ZONE_H
#define ZONE_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class Zone
{public:
    Zone();
    Zone(int,float,QString);
    int get_id();
    float get_surface();
    QString get_nom();
    bool ajouter(int,float,QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * getZones();
    bool supprimer(int);
    bool Update(int,float,QString);
    QSqlQueryModel * rechercherSPOT(QString);
     QSqlQueryModel * rechercherCLIM(QString);
private:
    int id;
    float surface;
    QString nom;
};

#endif // ZONE_H
