#include "zone.h"
#include <QDebug>

Zone::Zone()
{
id=0;
surface=0;
nom="";
}

Zone::Zone(int id,float surface,QString nom)
{
  this->id=id;
  this->surface=surface;
  this->nom=nom;
}

int Zone::get_id(){return  id;}
float Zone::get_surface(){return surface;}
QString Zone::get_nom(){return nom;}


bool Zone::ajouter(int id,float surface,QString nom)
{
QSqlQuery query;

QString res= QString::number(id);
QString res1=QString::number(surface);

query.prepare("INSERT INTO zone (ID, Surface, Nom) "
                    "VALUES (:id, :surface, :nom)");
query.bindValue(":id", res);
query.bindValue(":surface", res1);
query.bindValue(":nom",nom);

return    query.exec();

}


QSqlQueryModel * Zone::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from zone");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Surface"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}


bool Zone::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from zone where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


bool Zone::Update(int id,float surface,QString nom)
{
    QSqlQuery Q;
    Q.prepare("Update Zone Set(surface= :surface,nom= :nom) where id= :id");
    QString res= QString::number(surface);
    Q.bindValue(":id",QString::number(id) );
    Q.bindValue(":surface",res);
    Q.bindValue(":nom",nom);


    return Q.exec();
}


QSqlQueryModel* Zone::getZones()
{
    QSqlQueryModel* Model = new QSqlQueryModel;
    Model->setQuery("Select ID from Zone");
    return Model;
}


QSqlQueryModel * Zone::rechercherSPOT(QString id)
{

    QSqlQueryModel* Model = new QSqlQueryModel;
    Model->setQuery("select count(*) from spot where zone= '"+id+"'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("NB Spots"));
    return Model;


}


QSqlQueryModel * Zone::rechercherCLIM(QString id)
{

    QSqlQueryModel* Model = new QSqlQueryModel;
    Model->setQuery("select count(*) from climatiseur where zone= '"+id+"'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("NB Climatiseurs"));
    return Model;

}
