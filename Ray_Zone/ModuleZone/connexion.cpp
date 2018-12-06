#include "connexion.h"
#include <QtDebug>
#include <QSqlError>

Connexion::Connexion(){}


bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("rtest");
db.setUserName("mahdi");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
qDebug()<<db.lastError().text();

return  test;
}


void Connexion::fermerConnexion()
{
    db.close();
}

