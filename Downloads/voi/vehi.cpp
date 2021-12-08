#include "vehi.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QDateEdit>
Vehi::Vehi()
{
matricule=""; marque="";couleur="";panne="";
}
Vehi::Vehi(QString matricule,QString marque,QString couleur,QString panne,QDate datee)
{this->matricule=matricule; this->marque=marque; this->couleur=couleur; this->panne=panne; this->datee=datee;}
QString Vehi::getmatricule(){return matricule;}
QString Vehi::getmarque(){return marque;}
QString Vehi::getcouleur(){return couleur;}
QString Vehi::getpan(){return panne;}
QDate   Vehi::getdate(){return datee;}
void Vehi::setmatricule(QString matricule){this->matricule=matricule;}
void Vehi::setmarque(QString marque){this->marque=marque;}
void Vehi::setcouleur(QString couleur){this->couleur=couleur;}
void Vehi::setpan(QString panne){this->panne=panne;}
void Vehi::setdate(QDate datee){this->datee=datee;}
bool Vehi::ajouter()
{
    QSqlQuery query;
    QString datees= datee.toString();
         query.prepare("INSERT INTO GESTION_VEHICULE (matricule, marque, couleur, panne, datee) VALUES (:matricule, :marque, :couleur,:panne, :datee)");
         query.bindValue(":matricule", matricule);
         query.bindValue(":marque", marque);
         query.bindValue(":couleur", couleur);
         query.bindValue(":panne", panne);
         query.bindValue(":datee", datees);
         return query.exec();
                    
}
bool Vehi::supprimer(QString matricule)
{
    QSqlQuery query;
         query.prepare("Delete from GESTION_VEHICULE where matricule=:matricule");
         query.bindValue(0, matricule);
         return query.exec();


}
QSqlQueryModel* Vehi::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM GESTION_VEHICULE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PANNE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));

    return model;
}

bool Vehi::modifier()



{

         QSqlQuery query;
         QString datees= datee.toString();
         query.prepare("UPDATE GESTION_VEHICULE set matricule=:matricule,marque=:marque,couleur=:couleur,panne=:panne,datee=:datees where matricule=:matricule");
         query.bindValue(":matricule", matricule);
         query.bindValue(":marque", marque);
         query.bindValue(":couleur", couleur);
         query.bindValue(":panne", panne);
         query.bindValue(":datee", datees);

         return query.exec();



}

QSqlQueryModel*  Vehi::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM GESTION_VEHICULE order by matricule");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PANNE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));


    return model;

}


QSqlQueryModel*  Vehi::tri1()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM GESTION_VEHICULE order by marque");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PANNE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));


    return model;

}

QSqlQueryModel*  Vehi::tri2()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM GESTION_VEHICULE order by datee");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("PANNE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));


    return model;

}

QSqlQueryModel * Vehi::recherche(QString nom_m )
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM GESTION_VEHICULE WHERE MATRICULE =  '"+nom_m+"' ;");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MARQUE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("COULEUR"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PANNE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));

    return model ;
}
