#ifndef LOCATION_H
#define LOCATION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class location
{
public:
    location();
    location(int,QString,QString,float);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherTri(QString);
    QSqlQueryModel* afficherRech(QString,QString);
    bool rech(int);
private:
    int id;
    QString duree,etat;
    float prix;
};

#endif // location_H
