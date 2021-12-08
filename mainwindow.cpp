#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QSqlQuery>
#include "statmans.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableLocal->setModel(locale.afficher());


    ui->reference_supprimer->setModel(locale.afficherReference());
    ui->reference_modifier->setModel(locale.afficherReference());
    ui->longueur_ajout->setValidator(new QIntValidator(0,9999999,this));
    ui->largeur_ajout->setValidator(new QIntValidator(0,9999999,this));
    ui->ref_ajout->setValidator(new QIntValidator(0,9999999,this));
    ui->coordones_ajout->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*") , this ));
    ui->largeur_modifier->setValidator(new QIntValidator(0,9999999,this));
    ui->longueur_modifier->setValidator(new QIntValidator(0,9999999,this));
    ui->coordones_modifier->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*") , this ));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Valider_ajout_clicked()
{
    QString ref = ui->ref_ajout->text();
    QString coordones = ui->coordones_ajout->text();
    QString etat = ui->etat_ajout->currentText();
    QString daten = ui->date_ajout->date().toString("dd/MM/yyyy");
    int reff = ref.toInt();
    QString largeur = ui->largeur_ajout->text();
    QString longueur = ui->longueur_ajout->text();
    if (reff<=0){
        QMessageBox::critical(nullptr, QObject::tr("Local ajout"),
                                      QObject::tr("Verifier  reference ! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }

    else if(coordones.size()<=2){
        QMessageBox::critical(nullptr, QObject::tr("Local ajout"),
                                      QObject::tr("Verifier coordones ! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }


    else{
    Local  s(ref,coordones,largeur,longueur,daten,etat);
    bool validation = (s.ajouter());
    if (validation){
            ui->tableLocal->setModel(locale.afficher());
            ui->reference_supprimer->setModel(locale.afficherReference());
            ui->reference_modifier->setModel(locale.afficherReference());

            ui->ref_ajout->clear();
           ui->coordones_ajout->clear();
           ui->longueur_ajout->clear();
           ui->largeur_ajout->clear();
           ui->etat_ajout->setCurrentIndex(0);
        QMessageBox::information(nullptr, QObject::tr("Local ajout"),
                                      QObject::tr("Local ajouté !! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Local ajout"),
                                      QObject::tr("reference deja utiliser! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QString ref = ui->reference_supprimer->currentText();
    bool test = locale.supprimer(ref);
    if (test){
        ui->tableLocal->setModel(locale.afficher());
        ui->reference_supprimer->setModel(locale.afficherReference());
        QMessageBox::information(nullptr, QObject::tr("Local Suppression"),
                                      QObject::tr("Local supprimer!! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);
    }
    else{
        ui->tableLocal->setModel(locale.afficher());
        ui->reference_supprimer->setModel(locale.afficherReference());
        QMessageBox::critical(nullptr, QObject::tr("Local Suppression"),
                                      QObject::tr("Erreur CONX!! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
}

void MainWindow::on_reference_modifier_currentIndexChanged(const QString &arg1)
{


}

void MainWindow::on_pushButton_clicked()
{
    QString ref = ui->reference_modifier->currentText();
    QString coordones = ui->coordones_modifier->text();
    QString etat = ui->etat_modifier->currentText();
    QString daten = ui->date_modifier->date().toString("dd/MM/yyyy");
    int reff = ref.toInt();
   // QString largeur = ui->surface_modifier->text().toInt();
    QString largeur = ui->largeur_modifier->text();
    QString longueur =ui->longueur_modifier->text();
    if (reff<=0){
        QMessageBox::critical(nullptr, QObject::tr("Local modifier"),
                                      QObject::tr("Verifier  reference ! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }

    else if(coordones.size()<=2){
        QMessageBox::critical(nullptr, QObject::tr("Local modifier"),
                                      QObject::tr("Verifier coordones ! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }


    else{
    Local  s(ref,coordones,largeur,longueur,daten,etat);
    bool validation = (s.modifier(ref));
    if (validation){
            ui->tableLocal->setModel(locale.afficher());
            ui->reference_supprimer->setModel(locale.afficherReference());
            ui->reference_modifier->setModel(locale.afficherReference());
            ui->coordones_modifier->clear();
            ui->largeur_modifier->clear();
            ui->longueur_modifier->clear();
            ui->etat_modifier->setCurrentIndex(0);
        QMessageBox::information(nullptr, QObject::tr("Local Modification"),
                                      QObject::tr("Local modifier !! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Local modifier"),
                                      QObject::tr("ERROR CHECK SQL CONNECTION! .\n"
                                                  "Click Ok to exit."), QMessageBox::Ok);

    }
    }
}

void MainWindow::on_pdfBtn_clicked()
{

    QPdfWriter pdf("E:/PdfLocal.pdf");

                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(2300,1200,"Liste Des Locaux");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 50));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(1500,200,7300,2600);
                          //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(300,3300,"REF");
                          painter.drawText(2300,3300,"COORDONES");
                          painter.drawText(4300,3300,"SURFACE");
                          painter.drawText(6300,3300,"DATE LOCAL");



                          QSqlQuery q;
                          q.prepare("select * from local");
                          q.exec();
                          while (q.next())
                          {
                              painter.drawText(300,i,q.value(0).toString());
                              painter.drawText(2300,i,q.value(1).toString());
                              painter.drawText(4300,i,q.value(2).toString());
                              painter.drawText(6300,i,q.value(3).toString());



                             i = i +500;
                          }
                          int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                              if (reponse == QMessageBox::Yes)
                              {
                                  QDesktopServices::openUrl(QUrl::fromLocalFile("E:/PdfLocal.pdf"));

                                  painter.end();
                              }
                              if (reponse == QMessageBox::No)
                              {
                                   painter.end();
                              }
}

void MainWindow::on_statBtn_clicked()
{
    s = new Statlocal();

  s->setWindowTitle("statistique ComboBox");
  s->choix_bar();
  s->show();
}

void MainWindow::on_trier_clicked()
{
    int t = ui->comboBoxtRI->currentIndex();
    if(t==0){
        ui->tableLocal->setModel(locale.triRef());

    }else if(t==1){
        ui->tableLocal->setModel(locale.triSurf());

}
}

void MainWindow::on_impression_clicked()
{

}

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)
{
    ui->tableLocal->setModel(locale.Recherche(arg1));
}

void MainWindow::on_statBtn_2_clicked()
{
        statmans s;
        s.exec();
}

void MainWindow::on_afficher2_clicked()
{

}
