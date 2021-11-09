#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Smart_Garage");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("dhia28102001");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}

bool Connection::ourirConnexion(){
    if (db.open())
        return true ;
    else
        return false;
}
void Connection::fermerConnexion(){db.close();}
