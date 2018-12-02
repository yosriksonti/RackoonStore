#include "vehicule.h"
#include "QSqlQuery"
#include <QtDebug>
using namespace std;

unsigned Vehicule::getPlace(QString Mat)
{
    QSqlQuery q;
        q.prepare("SELECT PLACE FROM Vehicule WHERE MAT= :Mat");
        q.bindValue(":Mat",Mat);
        q.exec();
        while(q.next())
        {
        Place=unsigned(q.value(0).toInt());
        }
    return Place;
}

bool Vehicule::addVeh(QString const Mat,QString const  ID)
{

    QSqlQuery query;
    query.prepare("INSERT INTO Vehicule (MAT,CID,IS_IN) VALUES (:MAT, :CID, :IS_IN)");
    query.bindValue(":MAT",Mat);
    query.bindValue(":CID",ID);
    query.bindValue(":IS_IN",QString::number(0));
    return query.exec();
}

bool Vehicule::deleteVeh(QString Mat)
{
    QSqlQuery q;
    unsigned is_in=1;
    bool Success=false;
    q.prepare("SELECT IS_IN FROM Vehicule WHERE MAT= :MAT");
    q.bindValue(":MAT",Mat);
    q.exec();
    while(q.next())
    {
    is_in=unsigned(q.value(0).toInt());
    }
   if(is_in==0)
   {
    QSqlQuery query;
    query.prepare("DELETE From Vehicule WHERE MAT= :MAT");
    query.bindValue(":MAT",Mat);
    /*QSqlQuery Query;
    Query.prepare("DELETE From ELog WHERE MAT= :MAT");
    Query.bindValue(":MAT",Mat);*/
    Success=(query.exec()); // && Query.exec());
   }
    return Success ;
}
QSqlQueryModel* Vehicule::getMat()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT FROM Vehicule Where IS_IN = 0");
    return Model;
}

QSqlQueryModel* Vehicule::displayVehs()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, IS_IN, Place FROM Vehicule");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Presence"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Place"));
    return Model;
}

QSqlQueryModel* Vehicule::displayPresentVehs()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, Place FROM Vehicule where IS_IN= 1");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Place"));
    return Model;
}

QSqlQueryModel* Vehicule::displayVehMat(QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID,IS_IN, Place FROM Vehicule where MAT like '%"+Mat+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Presence"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Place"));
    return Model;
}

QSqlQueryModel* Vehicule::VehLog()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT * FROM ELog");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}

QSqlQueryModel* Vehicule::VehLogMat(QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where MAT like '%"+Mat+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}

QSqlQueryModel* Vehicule::VehLogDay(QString Day)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day);
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDayMat(QString Day,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and MAT like '%"+Mat+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogMonth(QString Month)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Month= "+Month);
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogMonthMat(QString Month,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Month= "+Month+" and MAT like '%"+Mat+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogYear(QString Year)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Year= "+Year);
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogYearMat(QString Year,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Year= "+Year+" and MAT like '%"+Mat+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDayMonth(QString Day,QString Month)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and Month= "+Month );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDayMonthMat(QString Day,QString Month,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and Month= "+Month+" and MAT like '%"+Mat+"%'" );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDayYear(QString Day,QString Year)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and Year= "+Year );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDayYearMat(QString Day,QString Year,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and Year= "+Year+" and MAT like '%"+Mat+"%'");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogMonthYear(QString Month,QString Year)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Year= "+Year+" and Month= "+Month );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogMonthYearMat(QString Month,QString Year,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Year= "+Year+" and Month= "+Month+" and MAT like '%"+Mat+"%'" );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDate(QString Day,QString Month,QString Year)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and Month= "+Month+" and Year= "+Year );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}
QSqlQueryModel* Vehicule::VehLogDateMat(QString Day,QString Month,QString Year,QString Mat)
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT MAT, CID, DAY, MONTH, YEAR FROM ELog where Day= "+Day+" and Month= "+Month+" and Year= "+Year+" and MAT like '%"+Mat+"%'" );
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Matricule"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
    return Model;
}

bool Vehicule::grantEntry(QString Mat,QString CID,QString Day, QString Month,QString Year,unsigned Place)
{

    QSqlQuery q,Q;
    QSqlQuery Query, query;
    QString MAT;
    unsigned is_in=1;
    bool Success=false;
        q.prepare("SELECT MAT FROM Vehicule WHERE MAT= :MAT");
        q.bindValue(":MAT",Mat);
        q.exec();
        while(q.next())
        {
        MAT=QString(q.value(0).toString());
        }
        q.prepare("SELECT IS_IN FROM Vehicule WHERE MAT= :MAT");
        q.bindValue(":MAT",Mat);
        q.exec();
        while(q.next())
        {
        is_in=unsigned(q.value(0).toInt());
        }
        if(MAT==Mat && is_in==0)
        {
        query.prepare("UPDATE Vehicule SET IS_IN=1 WHERE MAT= :MAT");
        query.bindValue(":MAT",Mat);
        query.exec();
        Q.prepare("UPDATE Vehicule SET PLACE=:Place WHERE MAT= :MAT");
        Q.bindValue(":MAT",Mat);
        Q.bindValue(":Place",QString::number(Place));

        Query.prepare("INSERT INTO ELog (MAT,CID,DAY,MONTH,YEAR) VALUES (:MAT,:CID,:DAY,:MONTH,:YEAR)");
        Query.bindValue(":MAT",Mat);
        Query.bindValue(":CID",CID);
        Query.bindValue(":DAY",Day);
        Query.bindValue(":MONTH",Month);
        Query.bindValue(":YEAR",Year);
        Success=Query.exec() && Q.exec();
        }
    return Success;
}


bool Vehicule::grantExit(QString Mat)
{
    QSqlQuery q,Q;
    QString MAT;
    bool Success=false;
    QSqlQuery query;
    q.prepare("SELECT MAT FROM Vehicule WHERE MAT= :MAT");
    q.bindValue(":MAT",Mat);
    q.exec();
    while(q.next())
    {
    MAT=QString(q.value(0).toString());
    }
    if(MAT==Mat)
    {
        query.prepare("UPDATE Vehicule SET IS_IN=0 WHERE MAT= :MAT");
        query.bindValue(":MAT",Mat);
        query.exec();
        Success=true;
    }
    return Success;
}
unsigned Vehicule::CountEntry(QString Day,QString Month,QString Year)
{

    QSqlQuery q;
    unsigned count=0;
    q.prepare("SELECT * FROM ELog WHERE Day= :Day and Month= :Month and Year= :Year");
    q.bindValue(":Day",Day);
    q.bindValue(":Month",Month);
    q.bindValue(":Year",Year);
    q.exec();
    while(q.next())
    {
    count++;
    }
    return count;
}

unsigned Vehicule::CountEntry()
{

    QSqlQuery q;
    unsigned count=0;
    q.prepare("SELECT * FROM ELog");
    q.exec();
    while(q.next())
    {
    count++;
    }
    return count;
}
