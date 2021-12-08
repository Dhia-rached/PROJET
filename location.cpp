#include "location.h"

location::location()
{

}
location::location(int id,QString duree,QString etat,float prix)
{
    this->id=id;
    this->prix=prix;
    this->duree=duree;
    this->etat=etat;
}
bool location::rech(int id)
{
    QString res=QString::number(id);
    QSqlQuery q("select * from location where id="+res);
    return q.next();
}
bool location::ajouter()
{
    QString p=QString::number(prix);
    QSqlQuery q;
    q.prepare("insert into location values(:id,:duree,:etat,:prix)");
    q.bindValue(":id",id);
    q.bindValue(":duree",duree);
    q.bindValue(":etat",etat);
    q.bindValue(":prix",p);
    return q.exec();
}
bool location::modifier(int id)
{
    QString p=QString::number(prix);
    QSqlQuery q;
    q.prepare("update location set duree=:duree,etat=:etat,prix=:prix where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":duree",duree);
    q.bindValue(":etat",etat);
    q.bindValue(":prix",p);
    q.exec();
    return rech(id);
}

bool location::supprimer(int id)
{
    if(!rech(id)) return false;
    QSqlQuery q;
    q.prepare("delete from location where id=:id");
    q.bindValue(":id",id);
    return q.exec();

}
QSqlQueryModel* location::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from location");
    return model;
}
QSqlQueryModel* location::afficherTri(QString critere)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from location order by "+critere);
    return model;
}
QSqlQueryModel* location::afficherRech(QString critere,QString rech)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from location where "+critere+" like '"+rech+"%'");
    return model;
}


