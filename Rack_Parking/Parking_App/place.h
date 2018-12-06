#ifndef PLACE_H
#define PLACE_H

#include <QString>
#include <iostream>
#include <string>
#include "QSqlQuery"
#include <QSqlDatabase>
#include <QSqlQueryModel>


class Place
{
public:
    Place();
    bool AddPlace(unsigned Num);
    unsigned getState(unsigned Num);
    bool Reserve(unsigned Num,QString Mat);
    bool Free(unsigned Num);
    bool Enable(unsigned Num);
    bool Disable(unsigned Num);
    unsigned getFreePlace();
    QSqlQueryModel* getPlaces();
    QSqlQueryModel* getPlacesNum(QString Num);
    QSqlQueryModel* getPlacesCB();
private:
    unsigned Num;
    unsigned State;
    QString Mat;
};

#endif // PLACE_H
