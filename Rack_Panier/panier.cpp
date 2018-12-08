#include "panier.h"
#include <QDebug>

panier::panier()
{
    id_panier="";
    id_client=0;
    type="";
    prix_total=0;

}

panier::panier(QString id_panier,int id_client,QString type,double prix_total)
{
    this->id_panier=id_panier;
    this->id_client=id_client;
    this->type=type;
    this->prix_total=prix_total;
}
void panier::stat(QString *x1,QString *x2){
    int somme(0);
    int y1(0),y2(0);
    QSqlQuery query,query1,query2;
    query.prepare("select count(id_panier) from panier");
    if(query.exec())
    while(query.next())
    {
        somme = query.value(0).toInt();
    }
    query1.prepare("select count(id_panier) from panier where type  ='Panier'");
    if(query1.exec())
        while(query1.next())
        {
            y1 = query1.value(0).toInt();
        }
    query2.prepare("select count(id_panier) from panier where type  ='Chariot'");
    query2.exec();
    while(query2.next())
    {

        y2 = query2.value(0).toInt();

    }
    y1 = (y1 * 100)/somme;
    y2 = (y2 * 100)/somme;
    *x1 = QString::number(y1);
    *x2 = QString::number(y2);


}
bool panier::ajouter()
{
QSqlQuery query;
QString res2= QString::number(id_client);
QString res3= QString::number(prix_total);

query.prepare("INSERT INTO panier (ID_PANIER, ID_CLIENT, TYPE, PRIX_TOTAL) "
                    "VALUES (:id_panier, :id_client, :type, :prix_total)");
query.bindValue(":id_panier", id_panier);
query.bindValue(":id_client", res2);
query.bindValue(":type", type);
query.bindValue(":prix_total", res3);
return    query.exec();
}

QSqlQueryModel * panier::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from panier");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Panier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type du Panier"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Total à Payer"));
    return model;
}

bool panier::supprimer(QString idd)
{
    QMessageBox::information(nullptr,"",idd);
QSqlQuery query;
query.prepare("Delete from panier where ID_PANIER =:id");
query.bindValue(":id", idd);
return    query.exec();
}


bool panier::maj(QString id_panier,QString type,QString id_client,QString prix_total)
{

    QSqlQuery query;
    QString res2= id_client;
    QString res3= prix_total;

    query.prepare("UPDATE panier SET ID_CLIENT =:id_client, TYPE =:type , PRIX_TOTAL =:prix_total WHERE ID_PANIER=:id_panier");

    query.bindValue(":id_client", res2);
    query.bindValue(":type", type);
    query.bindValue(":prix_total", res3);
    query.bindValue(":id_panier",id_panier);
    return(query.exec());
}

QSqlQueryModel * panier::recherche(const QString &str)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from panier where id_panier like '%" + str + "%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Panier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type du Panier"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Total à Payer"));
    return model;
}
