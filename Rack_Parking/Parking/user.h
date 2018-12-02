#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
#include <string>
#include <vector>
#include "QSqlQuery"
#include <QSqlDatabase>

class User
{
private:
    QString Password;
    QString Username;
public:
    User();
    bool Connect(QString Username,QString Password);
};



#endif // USER_H
