#include "connexion.h"

Connexion::Connexion()
{

}


bool Connexion::OpenConexion()
{
    bool test=false;
    db= QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("DEVOra");
        db.setUserName("Eazy_E");
        db.setPassword("Esprit2018");
        if(db.open())
            test=true;
        return test;
}

void Connexion::CloseConnexion()
{
    db.close();
}





