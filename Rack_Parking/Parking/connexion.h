#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool OpenConnexion();
    bool OpenConexion();
    void CloseConnexion();
};

#endif // CONNEXION_H
