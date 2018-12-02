#include "system.h"
#include "QSqlQuery"
#include <QtDebug>
System::System()
{

}

bool System::Connect()
{
    QSqlQuery Q;
    Q.prepare("UPDATE System SET CONNECTED = 1 WHERE Name= :Name");
    Q.bindValue(":Name",Name);
    return Q.exec();
}

bool System::Disconnect()
{
    QSqlQuery Q;
    Q.prepare("UPDATE System SET CONNECTED = 0 WHERE Name= :Name");
    Q.bindValue(":Name",Name);
    return Q.exec();
}

bool System::Activate()
{
    QSqlQuery Q;
    Q.prepare("UPDATE System SET ACTIVE = 1 WHERE Name= :Name");
    Q.bindValue(":Name",Name);
    return Q.exec();
}

bool System::Diactivate()
{
    QSqlQuery Q;
    Q.prepare("UPDATE System SET ACTIVE = 0 WHERE Name= :Name");
    Q.bindValue(":Name",Name);
    return Q.exec();
}

bool System::setPhase(QString Phase)
{
    QSqlQuery Q;
    Q.prepare("UPDATE System SET PHASE = :Phase WHERE Name= :Name");
    Q.bindValue(":Phase",Phase);
    Q.bindValue(":Name",Name);
    return Q.exec();
}

bool System::isConnected()
{
    QSqlQuery q;
    int Connected=0;
    q.prepare("SELECT CONNECTED FROM System WHERE NAME= :Name");
    q.bindValue(":Name",Name);
    q.exec();
    while(q.next())
    {
    Connected=int(q.value(0).toInt());
    }
    if (Connected==1)
    return true;
    else
        return false;
}
