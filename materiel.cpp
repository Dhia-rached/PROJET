#include "materiel.h"
#include "ui_materiel.h"
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
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
