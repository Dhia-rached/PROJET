#ifndef LOCAL_H
#define LOCAL_H

#include <QString>
#include <QSqlQueryModel>

class Local
{
public:
    Local();
    Local(QString,QString,QString,QString,QString,QString);
    QString getref();
    QString getCord();
    QString getsurface();
    QString getdatelocal();
    QString getetat();
    QString getlargeur();
    QString getlongueur();
    void setref(QString);
    void setCord(QString);
    void setsurface(QString);
    void setdatelocal(QString);
    void setetat(int);
    void setlargeur(QString);
    void setlongueur(QString);
    bool ajouter();

    QSqlQueryModel* afficher();
    QSqlQueryModel* Recherche(QString);
    QSqlQueryModel* triRef();
    QSqlQueryModel* triSurf();
    QSqlQueryModel* afficherReference();
    bool supprimer(QString);
    bool modifier(QString ref);


private:
    QString ref,coordones,datelocal,etat;
    QString surface,longueur,largeur;

};



#endif // LOCAL_H
