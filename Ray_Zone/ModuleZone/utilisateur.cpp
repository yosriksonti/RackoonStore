#include "utilisateur.h"


bool User::verification(QString id,QString mdp)
 {

     QSqlQuery query;
     query.prepare("Select * from users where ((id=:id)and(mdp=:mdp))");
     query.bindValue(":id",id);
     query.bindValue(":mdp",mdp);
     query.exec();
     if(query.next())
        {
         return true;

 }
     return false;

}
