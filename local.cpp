#include "local.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Local::Local()
{
ref=" ",coordones=" ",surface="",datelocal=" ",etat="",largeur="",longueur="";
}
Local::Local(QString ref,QString coordones,QString largeur,QString longueur,QString datelocal,QString etat)
{this->ref=ref ;this->coordones=coordones ;this->surface= QString::number(largeur.toInt()*longueur.toInt()) ;this->datelocal=datelocal ; this->etat=etat;this->longueur=longueur;this->largeur=largeur;}

QString Local::getref(){return ref;}
 QString  Local::getCord(){return coordones;}
 QString  Local::getsurface(){return surface;}
 QString  Local::getdatelocal(){return datelocal;}
 QString  Local::getetat(){return etat;}
 QString  Local::getlongueur(){return longueur;}
 QString  Local::getlargeur(){return largeur;}
 void Local::setref(QString ref){this->ref=ref ;}
 void Local::setCord(QString coordones){this->coordones=coordones ;}
 void Local::setsurface(QString surface){this->surface=surface ;}
 void Local::setdatelocal(QString datelocal ){this->datelocal=datelocal ;}
 void Local::setetat(int etat){ this->etat=etat;}
 void Local::setlongueur(QString longueur){ this->longueur=longueur;}
 void Local::setlargeur(QString largeur){ this->largeur=largeur;}

bool Local::ajouter()
{
    QSqlQuery query;

     query.prepare("INSERT INTO local (REF, coordones, surface, datelocal,etat,largeur,longueur) "
                   "VALUES (:ref, :coordones, :surface, :datelocal, :etat, :largeur, :longueur)");
     query.bindValue(":ref", ref); // :ref = ref
     query.bindValue(":coordones", coordones);
     query.bindValue(":surface", surface);
     query.bindValue(":datelocal", datelocal);
     query.bindValue(":etat", etat);
     query.bindValue(":largeur", largeur);
     query.bindValue(":longueur", longueur);
     return query.exec();


}
bool Local::supprimer(QString ref)
{
     QSqlQuery query;
     query.prepare(" Delete from local where ref =:ref");
     query.bindValue(0, ref);
     return query.exec();

}
QSqlQueryModel* Local::afficher()
{
     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM local");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("COORDONES"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateLocal"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("LONGUEUR"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("LARGEUR"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("SURFACE"));
     return model;
}
QSqlQueryModel* Local::Recherche(QString rech)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM local where ref like '%"+rech+"%' or COORDONES like '%"+rech+"%' or LONGUEUR like '%"+rech+"%' or LARGEUR like '%"+rech+"%'  or surface like '%"+rech+"%'  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("COORDONES"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateLocal"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LONGUEUR"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("LARGEUR"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SURFACE"));
    return model;
}
QSqlQueryModel* Local::triRef()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM local order by ref asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordones"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datelocal"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;
}
QSqlQueryModel* Local::triSurf()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM local order by surface asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordones"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datelocal"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

QSqlQueryModel* Local::afficherReference()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select ref from local");

    return model;
}

bool Local :: modifier(QString ref)
{
    QSqlQuery query;
    query.prepare("UPDATE local SET ref=:ref,coordones=:coordones,surface=:surface ,datelocal=:datelocal ,etat=:etat,largeur=:largeur,longueur=:longueur WHERE ref=:ref");
    query.bindValue(":ref", ref);
    query.bindValue(":coordones", coordones);
    query.bindValue(":surface", surface);
    query.bindValue(":largeur", largeur);
    query.bindValue(":longueur", longueur);
    query.bindValue(":datelocal", datelocal);
    query.bindValue(":etat", etat);
    return    query.exec();

}

