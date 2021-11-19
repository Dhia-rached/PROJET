#include "mat.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <iostream>
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

{this->num_serie=num_serie; this->quantiter=quantiter; this->prix=prix; this->nom_fournisseur=nom_fournisseur;this->nom_materiel=nom_materiel;this->type=type; }
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

          query.prepare("INSERT INTO GESTION_MATERIEL (num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type) VALUES (:NUM_SERIE,:QUANTITER,:PRIX,:NOM_FOURNISSEUR,:NOM_MATERIEL, :TYPE)");
          query.bindValue(":NUM_SERIE",num_serie_s );
          query.bindValue(":QUANTITER", quantiter_s);
          query.bindValue(":PRIX", prix_s);
          query.bindValue(":NOM_MATERIEL",nom_materiel);
          query.bindValue(":NOM_FOURNISSEUR", nom_fournisseur);
          query.bindValue(":TYPE", type);

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
          model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
          model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
          model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

    return model;

}
bool Mat::supprimer_materiel(int num_serie)
{
      QSqlQuery query;

        query.prepare("Delete from GESTION_MATERIEL where num_serie=:num_serie");
        query.bindValue(":num_serie", num_serie);


    return query.exec();
}


bool Mat::modifier_materiel()
{

    QSqlQuery query;

          query.prepare("UPDATE GESTION_MATERIEL SET num_serie=:NUM_SERIE, quantiter=:QUANTITER, prix=:PRIX, nom_fournisseur=:NOM_FOURNISSEUR, nom_materiel=:NOM_MATERIEL, type=:TYPE WHERE num_serie=:NUM_SERIE");
          query.bindValue(":NUM_SERIE",num_serie );
          query.bindValue(":QUANTITER", quantiter);
          query.bindValue(":PRIX", prix);
          query.bindValue(":NOM_MATERIEL",nom_materiel);
          query.bindValue(":NOM_FOURNISSEUR", nom_fournisseur);
          query.bindValue(":TYPE", type);

          return query.exec();



}
QSqlQueryModel * Mat::rechercher_f(QString nom_f )
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM GESTION_MATERIEL WHERE NOM_MATERIEL =  '"+nom_f+"' ;");

        model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
        model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
        model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
        model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
        model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

    return model ;
}
QSqlQueryModel * Mat::rechercher_m(QString nom_m )
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM GESTION_MATERIEL WHERE NOM_FOURNISSEUR =  '"+nom_m+"' ;");

        model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
        model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
        model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
        model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
        model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

    return model ;
}

QSqlQueryModel * Mat::rechercher_t(QString type )
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * FROM GESTION_MATERIEL WHERE type =  '"+type+"' ;");

        model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
        model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
        model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
        model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
        model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
        model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

    return model ;
}
QSqlQueryModel * Mat::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM GESTION_MATERIEL ORDER BY Prix ;");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

return model ;
}
QSqlQueryModel * Mat::trier_num_serie()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM GESTION_MATERIEL ORDER BY num_serie ;");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

return model ;
}

QSqlQueryModel * Mat::trier_quantiter()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM GESTION_MATERIEL ORDER BY Quantiter ;");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("num_serie"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Quantiter"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Prix"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("Nom_materiel"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("Nom_fournisseur"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("Type"));

    return model ;
}
////////////////////////////////////////////////////////////////////////////////////////
int Mat::critere_1()
{

     /*QSqlQuery query ;
    int nb_prix_chere = query.prepare("SELECT COUNT(*) FROM GESTION_MATERIEL WHERE prix>=50 ");
    query.exec();*/
    /*int nb_rows = query_1.prepare("SELECT COUNT(*) FROM GESTION_MATERIEL  ");
    query_1.exec();

    int x=(nb_prix_chere*360)/nb_rows;*/

    QSqlQuery q;
    q.prepare("SELECT COUNT (*) FROM GESTION_MATERIEL WHERE prix<=50");
    q.exec();
    int nb_prix_chere= 0;
    if (q.next()) {
    nb_prix_chere= q.value(0).toInt();
    }

    return  nb_prix_chere;
}

int Mat::critere_2()
{

     /*QSqlQuery query ;

    int nb_prix_bat = query.prepare("SELECT COUNT(*) FROM GESTION_MATERIEL WHERE prix>=50 ");
    query.exec();*/
    /*int nb_rows = query_1.prepare("SELECT COUNT(*) FROM GESTION_MATERIEL  ");
    query_1.exec();
    int x=(nb_prix_bat*360)/nb_rows;*/

    QSqlQuery q;
    q.prepare("SELECT COUNT (*) FROM GESTION_MATERIEL WHERE prix<=50");
    q.exec();
    int nb_prix_bat= 0;
    if (q.next()) {
    nb_prix_bat= q.value(0).toInt();
    }


    return  nb_prix_bat;
}

int Mat::num_row()
{
    QSqlQuery q;
    q.prepare("SELECT COUNT (*) FROM GESTION_MATERIEL");
    q.exec();
    int rows= 0;
    if (q.next()) {
    rows= q.value(0).toInt();
    }
    return rows;
}

int Mat::count(int val, QString att )
{
    QSqlQuery query;
     int row_count = 0;
     query.exec("SELECT * FROM gestion_materiel");

     while(query.next())
         if (query.value(val)==att)
            row_count++;
    int size = row_count;
    return size;
}

QChartView * Mat::piechart()
{
    int ap = count(5,"rep");
    int ap2 = count(5,"remplacemment");

    QPieSeries *series = new QPieSeries();
    series->append("rep",ap);
    series->append("remplacemment", ap2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Charte graphique du type du materiel ");
    chart->createDefaultAxes();

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->resize(300,300);
    chartview->scale(1,1);
    return chartview;

}

QChartView * Mat::piechart2()
{
    int ap = count(3,"aissa");
    int ap2 = count(3,"azer");
    int ap3 = count(3,"dhia");
    int ap4 = count(3,"aziz");

    QPieSeries *series = new QPieSeries();
    series->append("aissa",ap);
    series->append("azer", ap2);
    series->append("dhia", ap3);
    series->append("aziz", ap4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Charte graphique des fournisseur ");
    chart->createDefaultAxes();

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->resize(350,350);
    chartview->scale(1,1);
    return chartview;

}






















