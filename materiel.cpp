#include "materiel.h"
#include "ui_materiel.h"
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <QString>
#include <string>
#include <QIntValidator>
#include <QSqlQuery>
#include <QRegExpValidator>
#include "mat.h" //fichier qui contient la class mat

materiel::materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);

    /*QPixmap pix("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/image/logo0");
    ui->label_logo->setPixmap(pix.scaled(200,150,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/image/background4");
    ui->label_back->setPixmap(pix1.scaled(1281,671,Qt::KeepAspectRatio));*/
    ui->numserie->setValidator( new QIntValidator(0, 99999999, this));
    ui->numserie_2->setValidator( new QIntValidator(0, 99999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->type->setValidator(valiNom);
    ui->nom_m->setValidator(valiNom);
    ui->nom_f->setValidator(valiNom);
    //ui->tab_mat->setModel(m.afficher_materiel());

}

materiel::~materiel()
{
    delete ui;
}

void materiel::on_Valider_clicked()
{

    int num_serie=ui->numserie->text().toInt();
    int quantiter=ui->quantiter->text().toInt();
    int prix=ui->prix->text().toInt();
    QString nom_fournisseur=ui->nom_f->text();
    QString nom_materiel=ui->nom_m->text();
    QString type=ui->type->text();
    Mat m(num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type);

    bool test=m.ajouter_materiel();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("l'ajout effectué avec succ.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE L'AJOUT .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->tab_mat->setModel(m.afficher_materiel());
}

void materiel::on_supp_clicked()
{

    Mat m1;
    m1.setnums(ui->num_serie_supp->text().toInt());
    bool test=m1.supprimer_materiel(m1.getnums());


   /* QSqlQuery query;
        if(query.exec("SELECT * FROM GESTION_MATERIEL"))
        {
            while(query.next())
            {

                if(query.value("num_serie")==m1.getnums())
                {
                    test = true;

                }
                else test=false;
            }
        }*/


   // bool test=m1.supprimer_materiel(m1.getnums());
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("a suppression effectué avec succ.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE La suppression .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tab_mat->setModel(m.afficher_materiel());

}

void materiel::on_Valider_2_clicked()
{
    int num_serie=ui->numserie_2->text().toInt();
    int quantiter=ui->quantiter_2->text().toInt();
    int prix=ui->prix_2->text().toInt();
    QString nom_fournisseur=ui->nom_f_2->text();
    QString nom_materiel=ui->nom_m_2->text();
    QString type=ui->type_2->text();
    Mat m(num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type);

    bool test=m.modifier_materiel();



    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("la modification effectué avec succ.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE LA MODIF .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tab_mat->setModel(m.afficher_materiel());

}

void materiel::on_afficher_clicked()
{
    ui->tab_mat->setModel(m.afficher_materiel());

}

//for loading list
void materiel::on_pushButton_clicked()
{
     QSqlQueryModel*  model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT num_serie FROM GESTION_MATERIEL");
     query.exec();
     model->setQuery(query);
    ui->comboBox->setModel(model);

}

void materiel::on_comboBox_currentIndexChanged(int index)
{

    int n_serie=ui->comboBox->currentIndex();
     QString n_serie_s=QString::number(n_serie);
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTION_MATERIEL where num_serie='"+n_serie_s+"'");
    if(query.exec())
    {
        while (query.next())
        {
          ui->numserie_2->setText(query.value(0).toString()) ;
          ui->quantiter_2->setText(query.value(1).toString()) ;
          ui->prix_2->setText(query.value(2).toString()) ;
          ui->nom_m_2->setText(query.value(3).toString()) ;
          ui->nom_f_2->setText(query.value(4).toString()) ;
          ui->type_2->setText(query.value(5).toString()) ;
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE chargement .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}


void materiel::on_pushButton_2_clicked()
{
    QSqlQueryModel*  model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT num_serie FROM GESTION_MATERIEL");
    query.exec();
    model->setQuery(query);
   ui->comboBox_2->setModel(model);
}

void materiel::on_comboBox_2_currentIndexChanged(int index)
{
    int n_serie=ui->comboBox_2->currentIndex();
     QString n_serie_s=QString::number(n_serie);
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTION_MATERIEL where num_serie='"+n_serie_s+"'");
    if(query.exec())
    {
        while (query.next())
        {
          ui->num_serie_supp->setText(query.value(0).toString()) ;

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE chargement .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}


