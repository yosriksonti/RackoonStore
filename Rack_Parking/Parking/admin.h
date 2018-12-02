#ifndef ADMIN_H
#define ADMIN_H

#include <QString>
#include <iostream>
#include <string>
#include <vector>
#include "QSqlQuery"
#include <QSqlDatabase>



class Admin
{
private:
    QString Username;
    QString Password;
public:
    Admin();
    bool Connect(QString Username,QString Password);
};


#endif // ADMIN_H
