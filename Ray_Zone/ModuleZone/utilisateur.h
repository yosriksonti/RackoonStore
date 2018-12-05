#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class User
{
public:
    int nb=0;
private :
    QString id;
    QString mdp;
    QModelIndex *index;
public :


    bool verification(QString,QString);

};
#endif // UTILISATEUR_H
