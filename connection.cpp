#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("smart_garage");//inserer le nom de la source de données ODBC
db.setUserName("kiraxer");//inserer nom de l'utilisateur
db.setPassword("kiraxer");//inserer mot de passe de cet utilisateur

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
