#include "employe.h"
#include "log_in.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "mainwindow.h"
#include <QMainWindow>
#include <iostream>
#include <string>
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

QSqlQueryModel* employe ::afficher_id()
   {
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select cin from GESTION_EMPLOYE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    return model;

   }
QSqlQueryModel * employe::trier()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from GESTION_EMPLOYE order by salaire");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
return model;
}
QSqlQueryModel *employe::rechercher(int cin)
{
QSqlQueryModel * model=new QSqlQueryModel();
QString res1= QString::number(cin);
model->setQuery("SELECT * FROM GESTION_EMPLOYE WHERE cin='"+res1+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

return model;
}

bool employe::ajouter1()
{
QString res=QString::number(cin);
    QSqlQuery query;
    QString res1= QString::number(cin);
    QString res2= QString::number(salaire);
    query.prepare("INSERT INTO LOGIN1 (email,mdp)" "VALUES (:EMAIL,:MDP)");
    query.bindValue(":EMAIL",email);
    query.bindValue(":MDP",mdp);
    return    query.exec();
}
bool employe::recherche2()
{
    QString res=QString::number(cin);
        QSqlQuery query;
        QString res1= QString::number(cin);
        QString res2= QString::number(salaire);
        query.prepare("INSERT INTO LOGIN1 (email,mdp)" "VALUES (:EMAIL,:MDP)");
        query.bindValue(":EMAIL",email);
        query.bindValue(":MDP",mdp);
        return    query.exec();
    }



QSqlQueryModel * employe::trier_n()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from GESTION_EMPLOYE order by nom");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
return model;
}
QSqlQueryModel * employe::trier_p()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from GESTION_EMPLOYE order by prenom");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
return model;
}
QSqlQueryModel *employe::rechercher1(QString nom_e)
{
QSqlQueryModel * model=new QSqlQueryModel();
string res1= nom.toStdString();
model->setQuery("SELECT * FROM GESTION_EMPLOYE WHERE NOM='"+nom_e+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

return model;
}


QSqlQueryModel *employe::rechercher_2(QString nom_e)
{
QSqlQueryModel * model=new QSqlQueryModel();
string res1= nom.toStdString();
model->setQuery("SELECT * FROM GESTION_EMPLOYE WHERE PRENOM='"+nom_e+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

return model;
}
