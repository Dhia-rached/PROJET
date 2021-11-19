#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <iostream>
#include "log_in.h"
#include "employe.h"
#include <QComboBox>
#include "connection.h"
#include "mainwindow.h"
#include "log_in.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
#include "lgoin_bd.h"
#include <QMessageBox>
#include <iostream>
#include "chat1.h"
#include "chat2.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    lgoin_bd l;
    l.fermerConnexion1();

        Connection c;
        c.createconnect();


        bool test;
        test=c.ourirConnexion();
    employe e;
    ui->setupUi(this);
    ui->comboBox1->setModel(e.afficher());
    ui->comboBox2->setModel(e.afficher());
    ui->comboBox3->setModel(e.afficher());

   // ui->lineEdit=ui->comboBox1->setCurrentIndex()
    QString res=ui->CIN->text();
}

MainWindow::~MainWindow()
{





    delete ui;
}
void MainWindow::on_Valider_clicked()
{







    int salaire=ui->SALAIRE->text().toInt();
    int i;

bool f=false;
bool m=false;
//Salaire
if(salaire>0)
    m=true;
/*
//email(username =email)
    for(i=0;i<username.length();i++)
    {
        if(username.contains("@")&&username.contains(".")&&username.contains("com")&&username.contains("gmail")&& mdp!="")
        {
            f=true;
        }
    }
    if(f==true)
    {
        QMessageBox::information(this,"Login","correct");

    }else
        QMessageBox::warning(this,"Login","incorrect");
*/

    int cin=ui->CIN->text().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    QString adr=ui->ADR->text();
    QString role=ui->ROLE->text();
    //int salaire=ui->SALAIRE->text().toInt();

  QString res2= QString::number(cin);

    employe e(cin,nom,prenom,adr,salaire);
   /* QString email=ui->email->text();
    QString password=ui->password->text();*/


   // int salaire=ui->SALAIRE->text().toInt();

    if(m==true)
    {
        e.ajouter()==true;
        QMessageBox::information(this,"Login","ss");
        ui->comboBox1->addItem(res2);

    }
    else if(m==false)
    QMessageBox::warning(this,"Login","failed");
       ui->tableView->setModel(e.afficher());
       ui->comboBox1->addItem(res2);
       ui->comboBox2->addItem(res2);
       ui->comboBox3->addItem(res2);

       ui->comboBox1->setModel(e.afficher());
       ui->comboBox2->setModel(e.afficher());
       ui->comboBox3->setModel(e.afficher());


}

/*void MainWindow::on_pushButton_2_clicked()
{
employe e;
e.set_cin(ui->comboBox2->currentText().toInt());
int cin=ui->comboBox2->currentText().toInt();

       bool test= e.supprimer(cin);
       ui->comboBox2->setModel(e.afficher());
       if(test==true)
       {QMessageBox::information(this,"Login","check employer list ");
           QString res2= QString::number(cin);
            ui->comboBox2->removeItem(cin);


       }
       else if (test==false)
       QMessageBox::warning(this,"Login","failed");
          ui->tableView->setModel(e.afficher());

}
*/




////////Supression///////////////////
void MainWindow::on_pushButton_2_clicked()
{
employe e;
    int cin=ui->comboBox1->currentText().toInt();
       bool test= e.supprimer(cin);
       if(test==true)
       {QMessageBox::information(this,"Login","ss");
           ui->comboBox2->removeItem(cin);
           ui->comboBox1->removeItem(cin);
           ui->comboBox3->removeItem(cin);
           ui->comboBox1->setModel(e.afficher());
           ui->comboBox2->setModel(e.afficher());
           ui->comboBox3->setModel(e.afficher());

       }
       else
       QMessageBox::warning(this,"Login","failed");
          ui->tableView->setModel(e.afficher());

}

/*
void MainWindow::on_pushButton_clicked()
{
    int cin=ui->comboBox1->currentText().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    //QString adr=ui->ADR->text();
    QString role=ui->ROLE->text();
    int salaire=ui->salaire1->text().toInt();
    employe e(cin,nom,prenom,role,0);
    QString res2= QString::number(salaire);
    cout <<cin<<endl;
    if(e.modifier(cin,salaire)==true)
    {
    QMessageBox::information(this,"Login","check employer list ");
    ui->tableView->setModel(e.afficher());
    ui->comboBox1->setModel(e.afficher_id());
    }
    else if(e.modifier(cin,salaire)==false)
    QMessageBox::warning(this,"Login","failed");
    QString res1= QString::number(cin);

}

*/


void MainWindow::on_pushButton_clicked()
{
    int cin=ui->comboBox2->currentText().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    //QString adr=ui->ADR->text();
    QString role=ui->ROLE->text();
    int salaire=ui->salaire1->text().toInt();
    employe e(cin,nom,prenom,role,salaire);
    cout  <<cin<<endl;
    if(e.modifier(cin,salaire)==true)
    {
    QMessageBox::information(this,"Login","ss");
    ui->tableView->setModel(e.afficher());    }
    else
    QMessageBox::warning(this,"Login","failed");

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QString name;
}


void MainWindow::on_pushButton_3_pressed()
{
    employe e;
    bool test=true;//pour tester la boutton
    if(test==true)
    {
    QMessageBox::information(this,"Login","ss");
    ui->tableView->setModel(e.trier());}
    else
    QMessageBox::warning(this,"Login","failed");
}



void MainWindow::on_pushButton_6_clicked()
{
    int cin=ui->comboBox3->currentText().toInt();

   // int cin1=ui->lineEdit_2->text().toInt();

    employe e(2,"","","",0);
    bool test=true;//pour tester la boutton
    if(test==true)
    {
    QMessageBox::information(this,"Login","ss");
    ui->tableView_3->setModel(e.rechercher(cin));}
    else
    QMessageBox::warning(this,"Login","failed");
}


void MainWindow::on_PDF_clicked()
{

}

void MainWindow::on_pushButton_7_clicked()
{
QString filename=QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.png *.jpeg *.jpg)"));
if(QString::compare(filename, QString())!=0)
{
   QImage image;
   bool test=image.load(filename);
  if (test)
  {
      ui->label_25->setPixmap(QPixmap::fromImage(image));
  }


}
}

void MainWindow::on_impression_clicked()
{

//c1= new chat1(this);
c2=new chat2(this);
//c1->show();
c2->show();
QString e1;
QString e2;

}

void MainWindow::on_pushButton_4_pressed()
{
    employe e;
    bool test=true;//pour tester la boutton
    if(test==true)
    {
    QMessageBox::information(this,"Login","ss");
    ui->tableView->setModel(e.trier_n());}
    else
    QMessageBox::warning(this,"Login","failed");
}


void MainWindow::on_pushButton_5_pressed()
{
    employe e;
    bool test=true;//pour tester la boutton
    if(test==true)
    {
    QMessageBox::information(this,"Login","ss");
    ui->tableView->setModel(e.trier_p());}
    else
    QMessageBox::warning(this,"Login","failed");
}
