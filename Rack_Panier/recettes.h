#ifndef RECETTES_H
#define RECETTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class recettes
{public:
    recettes();
    recettes(QString,QString, QString,QString);
    QString get_ref(){return ref;}
    void set_ref(QString r){ref=r;}
    QString get_type(){return type;}
    void set_type(QString t){type=t;}
    QString get_produits(){return produits;}
    void set_produits(QString p){produits=p;}
    QString get_remise(){return  remise;}
    void set_remise(QString rem){remise=rem;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *recherche(const QString &str);
    bool maj(QString,QString,QString,QString);
    bool supprimer(QString);
    void stat(QString *x1,QString *x2,QString *x3);
private:
    QString ref;
    QString produits;
    QString remise;
    QString type;
};

#endif // RECETTES_H
