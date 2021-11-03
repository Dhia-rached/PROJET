#include "employe.h"
#include "log_in.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QSqlQueryModel>
employe::employe(int cin,QString nom,QString prenom,QString adr,QString email,QString mdp,float salaire)
{
this->cin=cin;
this->nom=nom;
this->prenom=prenom;
this->adr=adr;
this->email=email;
this->mdp=mdp;
this->salaire=salaire;
}

int employe::get_cin()
{return  cin;}
QString employe::get_nom()
{return nom;}
QString employe::get_prenom()
{return prenom;}
QString employe::get_adr()
{return adr;}
QString employe::get_email()
{return email;}
QString employe::get_mdp()
{return mdp;}
int employe::get_salaire()
{return salaire;
}
bool employe::ajouter()
{
QString res=QString::number(cin);
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (CIN,NOM,PRENOM,ADR,EMAIL,MDP,SALAIRE) "
                        "VALUES (:111,:nom,:prenom,:adr,:email,:mdp,:salaire)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adr",adr);
    query.bindValue(":email",email);
    query.bindValue(":mdp",mdp);
    query.bindValue(":salaire",salaire);

    return    query.exec();
}

QSqlQueryModel * employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    return model;
    }

