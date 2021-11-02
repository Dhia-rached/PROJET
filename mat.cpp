#include "mat.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
using namespace std;

Mat::Mat()
{
    num_serie=0;
    quantiter=0;
    prix=0;
    nom_fournisseur=" ";
    nom_materiel=" ";
    type=" ";

}

Mat::Mat(int num_serie,int quantiter,int prix,QString nom_fournisseur,QString nom_materiel,QString type)
{this->num_serie=num_serie; this->quantiter=quantiter; this->prix=prix; this->nom_fournisseur=nom_fournisseur;this->nom_materiel=nom_materiel;this->type=type;}
int Mat::getnums(){return num_serie; }
int Mat::getquantiter(){return quantiter;}
int Mat::getprix(){return prix;}
QString Mat::getnomf(){return nom_fournisseur;}
QString Mat::getnomm(){return nom_materiel;}
QString Mat::gettype(){return type;}

void Mat::setnums(int num_serie){this->num_serie=num_serie;}
void Mat::setquantiter(int quantiter ){this->quantiter=quantiter;}
void Mat::setprix(int prix ){this->prix=prix;}
void Mat::setnomf(QString nom_fournisseur){this->nom_fournisseur=nom_fournisseur;}
void Mat::setnomm(QString nom_materiel){this->nom_materiel=nom_materiel;}
void Mat::settype(QString type){this->type=type;}

bool Mat::ajouter_materiel()
{
    //bool test=false;

    QSqlQuery query;
    //convertir les int et float en string
    QString num_serie_s=QString::number(num_serie);
    QString quantiter_s=QString::number(quantiter);
    QString prix_s=QString::number(prix);

          query.prepare("INSERT INTO GESTION_MATERIEL (num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type) VALUES (:num_serie,:quantiter,:prix,:nom_fournisseur,:nom_materiel, :type)");
          query.bindValue(":num_serie",num_serie_s );
          query.bindValue(":quantiter", quantiter_s);
          query.bindValue(":prix", prix_s);
          query.bindValue(":nom_fournisseur", nom_fournisseur);
          query.bindValue(":nom_materiel", nom_materiel);
          query.bindValue(":type", type);

          return query.exec();


    //return test;
}

QSqlQueryModel* Mat::afficher_materiel()
{

    QSqlQueryModel*  model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM GESTION_MATERIEL ");
          model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
          model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
          model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
          model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
          model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

    return model;

}
bool Mat::supprimer_materiel(int num_serie)
{

    QSqlQuery query;
    query.prepare("delet form GESTION_MATERIEL where num_serie= num_serie ");
    query.bindValue(":num_serie",num_serie );
    return query.exec();

}




