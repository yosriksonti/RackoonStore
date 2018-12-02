#include "admin.h"
#include <QSqlQuery>
#include <QtDebug>



Admin::Admin()
{

}

bool Admin::Connect(QString Username,QString Password)
{
    bool Success=false;
    QSqlQuery q;
    QString TMPUser,TMPPass;
    q.prepare("SELECT USERNAME FROM Admin where USERNAME= :USERNAME");
    q.bindValue(":USERNAME",Username);
    q.exec();
    while(q.next())
    TMPUser=q.value(0).toString();
    if (TMPUser==Username)
    {
        q.prepare("SELECT PASSWROD FROM Admin where USERNAME= :USERNAME");
        q.bindValue(":USERNAME",Username);
        q.exec();
        while(q.next())
        TMPPass=q.value(0).toString();
        if (TMPPass==Password)
        {

            Success=true;
        }
    }
    return Success;
}
