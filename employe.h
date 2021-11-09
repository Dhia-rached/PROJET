#ifndef EMPLOYE_H
#define EMPLOYE_H


#include "mainwindow.h"
#include <QDialog>
#include <string>
#include "les_services.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
using namespace std ;
class employe
{
public:
    int cin;
    QString nom;
    QString prenom;
    QString role;
    int salaire;
public:
    ////Getters
    employe (){}
    employe(int cin,QString nom,QString prenom,QString role,float salaire);
    int get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_adr();
    QString get_email();
    QString get_mdp();
    int get_salaire();
    //Setters
    void set_cin(int cin);
    void set_nom(QString nom);
    void set_prenom(QString prenom);
    void set_adr(QString adr);
    void set_email(QString email);
    void set_mdp(QString mdp);
    void set_salaire(float salaire);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int id);
    bool modifier(int cin,QString nom,QString prenom,QString role ,int salaire);
};

#endif // EMPLOYE_H
