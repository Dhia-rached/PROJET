#ifndef MAT_H
#define MAT_H
#include <QString>
#include<QSqlQueryModel>
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
    void modifier_materiel();



private:
    int num_serie;
    int quantiter;
    int prix;
    QString nom_fournisseur;
    QString nom_materiel;
    QString type;


};

#endif // MAT_H
