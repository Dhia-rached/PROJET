#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <iostream>
#include "log_in.h"
#include "employe.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


    int cin=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_5->text();
    QString role=ui->lineEdit_6->text();
    int salaire=ui->lineEdit_18->text().toFloat();
    QString email=ui->email->text();
    QString password=ui->password->text();
    employe e(cin,nom,prenom,role,email,password,salaire);
    if(e.ajouter()==true)
    {QMessageBox::information(this,"Login","ss");}
    else
    QMessageBox::warning(this,"Login","ff");
}


