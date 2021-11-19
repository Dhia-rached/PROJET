#ifndef MAT_H
#define MAT_H
#include <QString>
#include<QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

using namespace std;

class Mat
{
public:
    Mat();
    Mat(int,int,int,QString,QString,QString);
    int getnums();
    int getquantiter();
    int getprix();
    QString getnomf();
    QString getnomm();
    QString gettype();

    void setnums(int);
    void setquantiter(int);
    void setprix(int);
    void setnomf(QString);
    void setnomm(QString);
    void settype(QString);

    bool ajouter_materiel();
    QSqlQueryModel* afficher_materiel();
    bool supprimer_materiel(int);
    bool modifier_materiel();
    QSqlQueryModel * rechercher_f(QString);
    QSqlQueryModel * rechercher_m(QString);
    QSqlQueryModel * rechercher_t(QString);
    QSqlQueryModel * trier();
    QSqlQueryModel * trier_num_serie();
    QSqlQueryModel * trier_quantiter();
    int critere_1();
    int critere_2();
    int num_row();

    QString size();
        QChartView * piechart();
        QChartView * piechart2();
        int count(int, QString);

private:
    int num_serie;
    int quantiter;
    int prix;
    QString nom_fournisseur;
    QString nom_materiel;
    QString type;


};

#endif // MAT_H
