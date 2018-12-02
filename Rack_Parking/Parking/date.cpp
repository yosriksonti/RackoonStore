#include "date.h"


Date::Date()
{


}

void Date::setDate()
{
    QDate TMPDT;
    TMPDT = QDate::currentDate();
    Day=QString::number(TMPDT.day());
    Month=QString::number(TMPDT.month());
    Year=QString::number(TMPDT.year());
}
























bool Connexion::OpenConnexion()
{
    bool test=false;
    db= QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("/DEVOra/parking.db");
        if(db.open())
            test=true;
        return test;
}
