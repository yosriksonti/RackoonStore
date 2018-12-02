#ifndef SYSTEM_H
#define SYSTEM_H

#include <QString>
#include <iostream>
#include <string>
#include "QSqlQuery"
#include <QSqlDatabase>

class System
{
private:
    unsigned CONNECTED;
    unsigned ACTIVE;
    QString PHASE;
    QString Name;
public:
    System();
    System(QString Name){this->Name = Name;}
    void setName(QString Name){this->Name=Name;}
    bool Connect();
    bool Disconnect();
    bool isConnected();
    bool Activate();
    bool Diactivate();
    bool setPhase(QString Phase);
    QString GetName(){return Name;}
};

#endif // SYSTEM_H
