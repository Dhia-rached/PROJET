#include "chat2.h"
#include "ui_chat2.h"
#include "chat1.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include "chat1.h"
#include "ui_chat1.h"
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "mainwindow.h"
#include "log_in.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
#include "lgoin_bd.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
chat2::chat2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat2)
{
    ui->setupUi(this);
}

chat2::~chat2()
{
    delete ui;
}

void chat2::on_pushButton_clicked()
{
    string d=ui->employe2->text().toStdString()+"\n";
    fstream file("C:/Users/Kiraxer/Desktop/oracle/gestion_des_employees/chat.txt",ios::in |ios::out |ios::app);
    if (!file.is_open())
    {
QMessageBox::warning(this,"file","failed");
    }
    else
    {
        file<<d;
    }

    chat1 c;


   QString e1;

   //fprintf(f,"%s",d);

   ui->textEdit->append(ui->employe2->text()+"\n");


}

void chat2::on_pushButton_2_clicked()
{
    fstream file("C:/Users/Kiraxer/Desktop/oracle/gestion_des_employees/chat.txt",ios::in |ios::out |ios::app);
    string d="employe 1:"+ui->employe2_2->text().toStdString()+"\n";
    if (!file.is_open())
    {
QMessageBox::warning(this,"file","failed");
    }
    else
    {
        file<<d;
    }

 ui->textEdit->append("employe 2:"+ui->employe2_2->text()+"\n");
}
