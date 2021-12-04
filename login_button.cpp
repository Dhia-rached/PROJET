#include "login_button.h"
#include "ui_login_button.h"
#include <string>
#include "employe.h"
#include <iostream>
#include "mainwindow.h"
#include "log_in.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
#include "lgoin_bd.h"
#include <QMessageBox>
#include <iostream>
#include <string>
login_button::login_button(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_button)
{

    ui->setupUi(this);

   /* lgoin_bd b;
    Connection c;
    Log_in l;
    bool test,test1;



        b.createconnect1();
        test1=b.ourirConnexion1();
        if(test1==true)
        {
        l.show();
         QMessageBox::information(nullptr,"Data base ","connection succeful");
        }else
        {
         QMessageBox::warning(nullptr,"Data base ","connection failed");
        }



*/


}

login_button::~login_button()
{
    delete ui;
}

void login_button::on_pushButton_clicked()
{
  employe e;
    e.email=ui->email->text();
    e.mdp=ui->password->text();
if(e.recherche2()==true)
{

    QMessageBox::warning(this,"Login","check your email");

}
else
{




m=new MainWindow(this);
m->show();
}
}
