#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <iostream>
#include "log_in.h"
#include "employe.h"
#include <QComboBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString res=ui->CIN->text();
    ui->comboBox1->addItem("res");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Valider_clicked()
{
    QString username=ui->email->text();
    QString mdp=ui->password->text();
    int i;

bool f=false;
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


    int cin=ui->CIN->text().toInt();
    QString nom=ui->NOM->text();
    QString prenom=ui->PRENOM->text();
    QString adr=ui->ADR->text();
    QString role=ui->ROLE->text();
    int salaire=ui->SALAIRE->text().toInt();
    employe e(cin,nom,prenom,adr,salaire);
   /* QString email=ui->email->text();
    QString password=ui->password->text();*/


   // int salaire=ui->SALAIRE->text().toInt();

    if(e.ajouter()==true)
    {QMessageBox::information(this,"Login","ss");}
    else
    QMessageBox::warning(this,"Login","failed");
       ui->tableView->setModel(e.afficher());


}

void MainWindow::on_pushButton_2_clicked()
{
employe e;
    int id=ui->lineEdit->text().toInt();
       bool test= e.supprimer(id);
       if(test==true)
       {QMessageBox::information(this,"Login","ss");}
       else
       QMessageBox::warning(this,"Login","failed");
          ui->tableView->setModel(e.afficher());
}




void MainWindow::on_pushButton_clicked()
{
    int cin=ui->cin22->text().toInt();
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
    ui->tableView->setModel(e.afficher());
    }
    else
    QMessageBox::warning(this,"Login","failed");

}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QString name;
}
