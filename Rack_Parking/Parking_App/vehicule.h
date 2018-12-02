#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <iostream>
#include <string>
#include "QSqlQuery"
#include <QSqlDatabase>
#include <QSqlQueryModel>

class Vehicule
{
private:
    QString Matricule;
    QString ID;
    unsigned Place;
    bool in;
public:
    bool addVeh(QString Mat,QString ID);
    bool deleteVeh(QString Mat);
    unsigned getPlace(QString Mat);
    QSqlQueryModel* getMat();
    QSqlQueryModel* displayVehs();
    QSqlQueryModel* displayPresentVehs();
    QSqlQueryModel* displayVehMat(QString Mat);
    QSqlQueryModel* VehLog();
    QSqlQueryModel* VehLogMat(QString Mat);
    QSqlQueryModel* VehLogDay(QString Day);
    QSqlQueryModel* VehLogMonth(QString Month);
    QSqlQueryModel* VehLogYear(QString Year);
    QSqlQueryModel* VehLogDayYear(QString Day,QString Year);
    QSqlQueryModel* VehLogDayMonth(QString Day,QString Month);
    QSqlQueryModel* VehLogMonthYear(QString Month,QString Year);
    QSqlQueryModel* VehLogDate(QString Day,QString Month,QString Year);
    QSqlQueryModel* VehLogDayMat(QString Day,QString Mat);
    QSqlQueryModel* VehLogMonthMat(QString Month,QString Mat);
    QSqlQueryModel* VehLogYearMat(QString Year,QString Mat);
    QSqlQueryModel* VehLogDayYearMat(QString Day,QString Year,QString Mat);
    QSqlQueryModel* VehLogDayMonthMat(QString Day,QString Month,QString Mat);
    QSqlQueryModel* VehLogMonthYearMat(QString Month,QString Year,QString Mat);
    QSqlQueryModel* VehLogDateMat(QString Day,QString Month,QString Year,QString Mat);
    bool grantEntry(QString Mat,QString CID,QString Day, QString Month,QString Year,unsigned Place);
    bool grantExit(QString Mat);
    unsigned CountEntry(QString Day,QString Month,QString Year);
    unsigned CountEntry();
};

#endif // VEHICULE_H
