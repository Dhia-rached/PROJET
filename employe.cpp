#include "employe.h"
#include "log_in.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>

#include <QMainWindow>
#include <iostream>
using namespace std;
employe::employe(int cin,QString nom,QString prenom,QString role,float salaire)
{
this->cin=cin;
this->nom=nom;
this->prenom=prenom;
this->role=role;
this->salaire=salaire;
}

int employe::get_cin()
{return  cin;}
QString employe::get_nom()
{return nom;}
QString employe::get_prenom()
{return prenom;}
/*QString employe::get_adr()
{return adr;}*/

int employe::get_salaire()
{return salaire;
}
bool employe::ajouter()
{
QString res=QString::number(cin);
    QSqlQuery query;
    QString res1= QString::number(cin);
    QString res2= QString::number(salaire);
    query.prepare("INSERT INTO GESTION_EMPLOYE (cin,nom,prenom,role,salaire) "
                        "VALUES (:CIN,:NOM,:PRENOM,:ROLE,:SALAIRE)");
    query.bindValue(":CIN",cin);
   // QMessageBox::information(this,"Login","ss");
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    //query.bindValue(":ADRESS",adr);
    query.bindValue(":ROLE",role);
    query.bindValue(":SALAIRE",salaire);


    return    query.exec();
}

QSqlQueryModel * employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from GESTION_EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

    return model;
    }
bool employe::supprimer(int cin)
{QSqlQuery query;
QString res=QString::number(cin);
query.prepare("Delete from GESTION_EMPLOYE where cin= :CIN");
query.bindValue(":CIN",res);
return query.exec();
}

bool employe::modifier(int cin,int salaire)
{
    QSqlQuery query;
    cout<<cin<<endl;
       /* QString res1=QString::number(salaire);
        QString res=QString::number(cin);*/
        query.prepare("UPDATE GESTION_EMPLOYE SET salaire=:SALAIRE WHERE cin=:CIN");
        query.bindValue(":SALAIRE",salaire);
        query.bindValue(":CIN",cin);
        cout<<cin<<endl;
        return query.exec();
}
