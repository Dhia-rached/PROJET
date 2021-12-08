#ifndef VEHI_H
#define VEHI_H
#include <QString>
#include<QRadioButton>
#include<QDateEdit>
#include <qsqlquerymodel.h>
class Vehi
{
public:
    Vehi();
    Vehi(QString,QString,QString,QString,QDate);
    QString getmatricule();
    QString getmarque();
    QString getcouleur();
    QString getpan();
    QDate getdate();
    QRadioButton getetat();
    void setmatricule(QString);
    void setmarque(QString);
    void setcouleur(QString);
    void setpan(QString);
    bool ajouter();
    void setdate(QDate);
    QSqlQueryModel*  afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel*  tri();
    QSqlQueryModel*  tri1();
    QSqlQueryModel*  tri2();
    QSqlQueryModel*  recherche(QString);


private:
    QString matricule,marque,couleur,panne;
    QDate datee;

};

#endif // VEHI_H
