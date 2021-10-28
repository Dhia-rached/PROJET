#include "mat.h"
#include <QSqlQuery>
#include<QtDebug>
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

Mat::Mat(int num_serie,int quantiter,float prix,string nom_fournisseur,string nom_materiel,string type)
{this->num_serie=num_serie; this->quantiter=quantiter; this->prix=prix; this->nom_fournisseur=nom_fournisseur;this->nom_materiel=nom_materiel;this->type=type;}
int Mat::getnums(){return num_serie; }
int Mat::getquantiter(){return quantiter;}
float Mat::getprix(){return prix;}
string Mat::getnomf(){return nom_fournisseur;}
string Mat::getnomm(){return nom_materiel;}
string Mat::gettype(){return type;}

void Mat::setnums(int num_serie){this->num_serie=num_serie;}
void Mat::setquantiter(int quantiter ){this->quantiter=quantiter;}
void Mat::setprix(float prix ){this->prix=prix;}
void Mat::setnomf(string nom_fournisseur){this->nom_fournisseur=nom_fournisseur;}
void Mat::setnomm(string nom_materiel){this->nom_materiel=nom_materiel;}
void Mat::settype(string type){this->type=type;}

/*bool Mat::ajouter_materiel()
{
    bool test=false;
    QSqlQuery query;
          query.prepare("INSERT INTO person (id, forename, surname) "
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(":id", 1001);
          query.bindValue(":forename", "Bart");
          query.bindValue(":surname", "Simpson");
          query.exec();


    return test;
}*/
