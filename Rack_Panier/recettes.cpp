#include "recettes.h"
#include <QDebug>

recettes::recettes()
{
    ref="";
    produits="";
    remise="";
    type="";
}
recettes::recettes(QString ref,QString produits, QString remise,QString type)
{
      this->ref=ref;
      this->produits=produits;
      this->remise=remise;
      this->type=type;
}

void recettes::stat(QString *x1,QString *x2,QString *x3)
{
    int c1(0), c2(0), c3(0);
    QSqlQuery query1,query2,query3;

    query1.prepare("select count(ref) from recettes where type  = 'spaghetti'");
    query1.exec();
    c1 = query1.value(0).toInt();
    query2.prepare("select count(ref) from recettes where type  = 'steak'");
    query2.exec();
    c2 = query2.value(0).toInt();
    query3.prepare("select count(ref) from recettes where type  = 'salade'");
    query3.exec();
    c3 = query3.value(0).toInt();

    *x1 = QString::number(c1);
    *x2 = QString::number(c2);
    *x3 = QString::number(c3);
}

bool recettes::ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO recettes (REF, REMISE, PRODUITS, TYPE) VALUES (:ref, :remise, :produits, :type)");
query.bindValue(":ref", ref);
query.bindValue(":remise", remise);
query.bindValue(":produits", produits);
query.bindValue(":type", type);

return    query.exec();
}

QSqlQueryModel * recettes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from recettes");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Remise"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produits"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));

    return model;
}

bool recettes::supprimer(QString reff)
{
QSqlQuery query;
query.prepare("Delete from recettes where REF = :ref ");
query.bindValue(":ref", reff);
return    query.exec();
}


bool recettes::maj(QString ref,QString remise,QString produits,QString type)
{
    QSqlQuery query;
    query.prepare("UPDATE recettes SET REMISE= :remise, PRODUITS = :produits, TYPE = :Type WHERE REF = :ref");
    query.bindValue(":ref", ref);
    query.bindValue(":remise", remise);
    query.bindValue(":produits", produits);
    query.bindValue(":type", type);

    return    query.exec();
}

QSqlQueryModel * recettes::recherche(const QString &str)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from recettes where ref like '%" + str + "%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Remise"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produits"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));
    return model;
}
