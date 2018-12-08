#ifndef ACHATS_H
#define ACHATS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class achats
{
public:
    achats();
    achats(QString,QString,int,double);
    QString get_ref(){return  ref;}
    void set_ref(QString r){ref = r;}
    QString get_code(){return  code;}
    void set_code(QString c){code = c;}
    int get_qte(){return qte;}
    void set_qte(int q){qte = q;}
    double get_prix_u(){return prix_u;}
    void set_prix_u(double prix){prix_u = prix;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *recherche(const QString &str);
    bool maj(QString,QString,int,double);
    bool supprimer(QString);
    QSqlQueryModel * displayprod();
private:
    QString ref;
    QString code;
    int qte;
    double prix_u;
};

#endif // ACHATS_H
