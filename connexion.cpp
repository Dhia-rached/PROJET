#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirConnexion()
{
    bool testOuverture=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("aziz");
    db.setUserName("aziz");
    db.setPassword("aziz");
    if (db.open())
        testOuverture=true;
    return  testOuverture;
}
void connexion::fermerConnexion()
{db.close();}
