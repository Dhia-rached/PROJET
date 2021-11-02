#include "materiel.h"
#include "ui_materiel.h"
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <QString>
#include <string>
#include <QIntValidator>

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
    ui->tab_mat->setModel(m.afficher_materiel());

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

}

void materiel::on_supp_clicked()
{

    Mat m1;m1.setnums(ui->num_serie_supp->text().toInt());
    bool test=m1.supprimer_materiel(m1.getnums());
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

}
