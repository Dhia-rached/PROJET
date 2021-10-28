#include "materiel.h"
#include "ui_materiel.h"
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <string>

#include "mat.h" //fichier qui contient la class mat

materiel::materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/image/logo0");
    ui->label_logo->setPixmap(pix.scaled(200,150,Qt::KeepAspectRatio));
    /*QPixmap pix1("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/image/background4");
    ui->label_back->setPixmap(pix1.scaled(1281,671,Qt::KeepAspectRatio));*/
}

materiel::~materiel()
{
    delete ui;
}

/*void materiel::on_Valider_clicked()
{
    int num_serie=ui->numserie->text().toInt();
    int quantiter=ui->quantiter->text().toInt();
    float prix=ui->prix->text().toFloat();
    string nom_fournisseur=ui->nom_f->text();
    string nom_materiel=ui->nom_m->text();
    string type=ui->type->text();
    Mat m(num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type);

}*/
