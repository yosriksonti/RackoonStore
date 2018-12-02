#ifndef DATE_H
#define DATE_H

#include "connexion.h"
#include <QString>
#include <QDate>

class Date
{
public:
    Date();
    void setDate();
    QString getDay(){return Day;}
    QString getMonth(){return Month;}
    QString getYear(){return Year;}
private:
    QString Day;
    QString Month;
    QString Year;
};

#endif // DATE_H
