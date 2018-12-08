#ifndef PANIER_H
#define PANIER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QMessageBox>

class panier
{
public:
    panier();
    panier(QString,int,QString,double);
    QString get_id_panier(){return  id_panier;}
    void set_id_panier(QString id_p){id_panier=id_p;}
    int get_id_client(){return  id_client;}
    void set_id_client(int id_c){id_client=id_c;}
    QString get_type(){return  type;}
    void set_type(QString type){this->type=type;}
    double get_prix_total(){return  prix_total;}
    void set_prix_total(double prix_t){prix_total=prix_t;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *recherche(const QString &str);
    bool maj(QString,QString,QString,QString);
    bool supprimer(QString);
    void stat(QString *x1,QString *x2);
private:
    QString id_panier;
    int id_client;
    QString type;
    double prix_total;


};

#endif // PANIER_H
