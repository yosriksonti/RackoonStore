#include "user.h"
#include "QSqlQuery"
#include <QtDebug>

User::User()
{

}

bool User::Connect(QString Username,QString Password)
{
    bool Success=false;
    QSqlQuery q,Q;
    QString TMPUser,TMPPass;
    q.prepare("Select USERNAME FROM User where USERNAME= :USERNAME");
    q.bindValue(":USERNAME",Username);
    q.exec();
    while(q.next())
    TMPUser=q.value(0).toString();
    if (TMPUser==Username)
    {
        Q.prepare("Select PASSWORD FROM User where USERNAME= :USERNAME");
        Q.bindValue(":USERNAME",Username);
        Q.exec();
        while(Q.next())
        TMPPass=Q.value(0).toString();
        if (TMPPass==Password)
        {
            Success=true;
        }
    }
    return Success;
}
