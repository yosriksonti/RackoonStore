#include "climatiseur.h"
#include <QDebug>

Climatiseur::Climatiseur()
{
id=0;
etat=0;    //0:eteint , 1:lumineux //
zone=0;
nombre=0;
temp=0;
}

Climatiseur::Climatiseur(int id,int etat,int zone,int nombre,int temp)
{
  this->id=id;
  this->etat=etat;
  this->zone=zone;
  this->nombre=nombre;
  this->temp=temp;
}

int Climatiseur::get_etat(){return etat;}
int Climatiseur::get_zone(){return zone;}
int Climatiseur::get_id(){return  id;}
int Climatiseur::get_nombre(){return nombre;}
int Climatiseur::get_temp(){return temp;}

bool Climatiseur::ajouter(int id,int etat,int zone,int nombre,int temp)
{
QSqlQuery query;

QString res= QString::number(id);
QString res1= QString::number(etat);
QString res2= QString::number(zone);
QString res3= QString::number(nombre);
QString res4= QString::number(temp);


query.prepare("INSERT INTO climatiseur (id,etat,zone,nombre,temp) "
                    "VALUES (:id, :etat, :zone, :nombre, :temp)");
query.bindValue(":id", res);
query.bindValue(":etat", res1);
query.bindValue(":zone", res2);
query.bindValue(":nombre",res3);
query.bindValue(":temp",res4);

return    query.exec();
}


QSqlQueryModel * Climatiseur::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from climatiseur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Temperature"));



    return model;
}


bool Climatiseur::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from climatiseur where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


bool Climatiseur::Update(int id,int etat,int zone,int nombre,int temp)
{
    QSqlQuery Q;
    Q.prepare("Update climatiseur Set(etat= :etat,zone= :zone,nombre= :nombre,temp= :temp) where id= :id");

    QString res= QString::number(etat);
    QString res1= QString::number(zone);
    QString res2= QString::number(nombre);
    QString res3= QString::number(temp);
     Q.bindValue(":id",QString::number(id));
     Q.bindValue(":etat",res);
     Q.bindValue(":zone",res1);
     Q.bindValue(":nombre",res2);
     Q.bindValue(":temp",res3);
    return Q.exec();
}







