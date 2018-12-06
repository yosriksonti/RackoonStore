#include "capteur.h"
#include <QDebug>

Capteur::Capteur()
{
id=0;
etat=0;    //0:eteint , 1:lumineux //
zone=0;
nombre=0;
type="";
}

Capteur::Capteur(int id,int etat,int zone,int nombre,QString type)
{
  this->id=id;
  this->etat=etat;
  this->zone=zone;
  this->nombre=nombre;
  this->type=type;
}

int Capteur::get_etat(){return etat;}
int Capteur::get_zone(){return zone;}
int Capteur::get_id(){return  id;}
int Capteur::get_nombre(){return nombre;}
QString Capteur::get_type(){return type;}

bool Capteur::ajouter(int id,int etat,int zone,int nombre,QString type)
{
QSqlQuery query;

QString res= QString::number(id);
QString res1= QString::number(etat);
QString res2= QString::number(zone);
QString res3= QString::number(nombre);



query.prepare("INSERT INTO capteur (id,etat,zone,nombre,type) "
                    "VALUES (:id, :etat, :zone, :nombre, :type)");
query.bindValue(":id", res);
query.bindValue(":etat", res1);
query.bindValue(":zone", res2);
query.bindValue(":nombre",res3);
query.bindValue(":type",type);

return    query.exec();
}


QSqlQueryModel * Capteur::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from capteur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Zone"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));



    return model;
}


bool Capteur::supprimer(QString idd)
{
QSqlQuery query;
query.prepare("Delete from capteur where ID = :id ");
query.bindValue(":id", idd);
return  query.exec();
}

bool Capteur::Update(int id,int etat,int zone,int nombre,QString type)
{
    QSqlQuery Q;
    Q.prepare("Update Capteur Set(etat= :etat,zone= :zone,nombre= :nombre,type= :type) where id= :id");
    QString res= QString::number(etat);
    QString res1= QString::number(zone);
    QString res2= QString::number(nombre);
    Q.bindValue(":id",QString::number(id));
    Q.bindValue(":etat",res);
    Q.bindValue(":zone",res1);
    Q.bindValue(":nombre",res2);
    Q.bindValue(":type",type);
    return Q.exec();
}


