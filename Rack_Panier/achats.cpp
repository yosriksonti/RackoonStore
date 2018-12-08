#include "achats.h"
#include <QDebug>
achats::achats()
{
    ref="";
    code="";
    qte=0;
    prix_u=0;
}

achats::achats(QString ref,QString code,int qte,double prix_u)
{
  this->ref=ref;
  this->code=code;
  this->qte=qte;
  this->prix_u=prix_u;
}

bool achats::ajouter()
{
QSqlQuery query;
QString res1= QString::number(qte);
QString res2= QString::number(prix_u);
query.prepare("INSERT INTO achats (REF, QTE, PRIX_U, CODE) "
                    "VALUES (:ref, :qte, :prix_u, :code)");
query.bindValue(":ref", ref);
query.bindValue(":qte", res1);
query.bindValue(":prix_u", res2);
query.bindValue(":code", code);

return    query.exec();
}

QSqlQueryModel * achats::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from achats");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix Unitaire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Code"));
    return model;
}

bool achats::supprimer(QString reff)
{
QSqlQuery query;
query.prepare("Delete from achats where REF = :ref ");
query.bindValue(":ref", reff);
return    query.exec();
}


bool achats::maj(QString ref,QString code,int qte,double prix_u)
{
    QSqlQuery query;
    QString res1= QString::number(qte);
    QString res2= QString::number(prix_u);
    query.prepare("UPDATE achats SET QTE = :qte, PRIX_U = prix_u, CODE = :code WHERE REF = :ref ");
    query.bindValue(":ref", ref);
    query.bindValue(":qte", res1);
    query.bindValue(":prix_u", res2);
    query.bindValue("code", code);
    return    query.exec();
}

QSqlQueryModel * achats::recherche(const QString &str)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from achats where ref like '%" + str + "%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix Unitaire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Code"));
    return model;
}

QSqlQueryModel * achats::displayprod()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select code from produits");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code"));
        return model;
}
