#ifndef LGOIN_BD_H
#define LGOIN_BD_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class lgoin_bd
{
    QSqlDatabase db1;
public:
    lgoin_bd();
    bool ourirConnexion1();
    void fermerConnexion1();
    bool createconnect1();
};











#endif // LGOIN_BD_H
