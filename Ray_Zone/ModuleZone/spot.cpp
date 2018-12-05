#include "spot.h"
#include <QDebug>

Spot::Spot()
{
id=0;
etat=0;    //0:eteint , 1:lumineux //
zone=0;
nombre=0;
}

Spot::Spot(int id,int etat,int zone,int nombre)
{
  this->id=id;
  this->etat=etat;
  this->zone=zone;
  this->nombre=nombre;
}

int Spot::get_etat(){return  etat;}
int Spot::get_zone(){return zone;}
int Spot::get_id(){return  id;}
int Spot::get_nombre(){return nombre;}



bool Spot::ajouter(int id,int etat,int zone,int nombre)
{
QSqlQuery query;

QString res= QString::number(id);
QString res1= QString::number(etat);
QString res2= QString::number(zone);
QString res3= QString::number(nombre);
query.prepare("INSERT INTO spot (ID, ETAT, ZONE,NOMBRE) "
                    "VALUES (:id, :etat, :zone, :nombre)");
query.bindValue(":id", res);
query.bindValue(":etat", res1);
query.bindValue(":zone", res2);
query.bindValue(":nombre", res3);
return    query.exec();

}


QSqlQueryModel * Spot::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from spot");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre"));
    return model;
}


bool Spot::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from spot where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


bool Spot::Update(int id,int etat,int zone,int nombre )
{
    QSqlQuery Q;
    Q.prepare("Update Spot Set(etat= :etat,zone= :zone,nombre= :nombre) where id= :id");
    QString res= QString::number(etat);
    QString res1= QString::number(zone);
    QString res2= QString::number(nombre);
    Q.bindValue(":id",QString::number(id));
    Q.bindValue(":etat",res);
    Q.bindValue(":zone",res1);
    Q.bindValue(":nombre",res2);
    return Q.exec();
}







