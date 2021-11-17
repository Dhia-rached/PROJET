#include "lgoin_bd.h"

lgoin_bd::lgoin_bd()
{

}



bool lgoin_bd::createconnect1()
{bool test=false;
db1 = QSqlDatabase::addDatabase("QODBC");
db1.setDatabaseName("log_in");//inserer le nom de la source de données ODBC
db1.setUserName("login");//inserer nom de l'utilisateur
db1.setPassword("login");//inserer mot de passe de cet utilisateur

if (db1.open())
test=true;
    return  test;
}

bool lgoin_bd::ourirConnexion1(){
    if (db1.open())
        return true ;
    else
        return false;
}
void lgoin_bd::fermerConnexion1(){db1.close();}
