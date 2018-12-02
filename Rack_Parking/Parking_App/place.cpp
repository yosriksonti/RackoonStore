#include "place.h"

Place::Place()
{

}



unsigned Place::getState(unsigned Num)
{
    QSqlQuery q;
        q.prepare("SELECT STATE FROM Place WHERE NUM= :Num");
        q.bindValue(":Num",QString::number(Num));
        q.exec();
        while(q.next())
        {
        State=unsigned(q.value(0).toInt());
        }
    return State;
}

bool Place::Reserve(unsigned Num,QString Mat)
{
    QSqlQuery q,Q;
    bool Success=false;
        State=getState(Num);
    if(State==0)
    {
        Q.prepare("UPDATE Place SET STATE= :State WHERE NUM= :Num");
        Q.bindValue(":State","1");
        Q.bindValue(":Num",QString::number(Num));
        q.prepare("UPDATE Place SET MAT= :Mat WHERE NUM= :Num");
        q.bindValue(":Mat",Mat);
        q.bindValue(":Num",QString::number(Num));
        Success=(q.exec() && Q.exec());
    }
    return Success;
}

bool Place::Free(unsigned Num)
{
    QSqlQuery q,Q,Query,query;
    bool Success=false;
        State=getState(Num);
    if(State==1)
    {
        QString Mat;
        query.prepare("SELECT MAT FROM Vehicule WHERE PLACE= :Place");
        query.bindValue(":Place",QString::number(Num));
        query.exec();
        while(query.next())
        {
        Mat=QString(q.value(0).toString());
        }
        Query.prepare("UPDATE Vehicule SET Place= 0 WHERE Place= :Place");
        Query.bindValue(":Place",QString::number(Num));
        Query.exec();
        q.prepare("UPDATE Place SET STATE= :State WHERE NUM= :Num");
        q.bindValue(":State","0");
        q.bindValue(":Num",QString::number(Num));
        Q.prepare("UPDATE Place SET MAT= :Mat WHERE NUM= :Num");
        Q.bindValue(":Mat","");
        Q.bindValue(":Num",QString::number(Num));

        Success=(q.exec() && Q.exec());
    }
    return Success;
}

bool Place::Enable(unsigned Num)
{
    QSqlQuery q,Q;
    bool Success=false;
        State=getState(Num);
    if(State==2)
    {
        q.prepare("UPDATE Place SET STATE= :State WHERE NUM= :Num");
        q.bindValue(":State","0");
        q.bindValue(":Num",QString::number(Num));
        Q.prepare("UPDATE Place SET MAT = :Mat WHERE NUM= :Num");
        Q.bindValue(":Mat","");
        Q.bindValue(":Num",QString::number(Num));
        Success=(q.exec() && Q.exec());
    }
    return Success;
}

bool Place::Disable(unsigned Num)
{
    QSqlQuery q,Q;
    bool Success=false;
        State=getState(Num);
    if(State==0)
    {
        q.prepare("UPDATE Place SET STATE= :State WHERE NUM= :Num");
        q.bindValue(":State","2");
        q.bindValue(":Num",QString::number(Num));
        Q.prepare("UPDATE Place SET MAT = :Mat WHERE NUM= :Num");
        Q.bindValue(":Mat","");
        Q.bindValue(":Num",QString::number(Num));
        Success=(q.exec() && Q.exec());
    }
    return Success;
}

unsigned Place::getFreePlace()
{
    QSqlQuery q;
        q.prepare("SELECT Num FROM Place WHERE State= :State");
        q.bindValue(":State",0);
        q.exec();
        while(q.next())
        {
        Num=unsigned(q.value(0).toInt());
        }
    return Num;
}

QSqlQueryModel* Place::getPlaces()
{

    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT NUM, STATE, MAT FROM PLACE");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("State"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Matricule"));
    return Model;
}

QSqlQueryModel* Place::getPlacesNum(QString Num)
{

    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT NUM , STATE , MAT FROM PLACE Where NUM= "+Num);
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Num"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("State"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Matricule"));
    return Model;
}

QSqlQueryModel* Place::getPlacesCB()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT NUM FROM PLACE");
    return Model;
}
