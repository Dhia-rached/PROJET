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
//#include <cstidio>
using namespace  std;
chat1::chat1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat1)
{
    ui->setupUi(this);
}
void chat1::affichere1()
{
 ofstream file;
 FILE* f=fopen("chat.txt","w+");

QString e1;
string d=ui->employe1->text().toStdString()+"\n";
//fprintf(f,"%s",d);
cout<<d;
ui->lineEdit->setText(ui->employe1->text()+"\n");
fprintf(f,"%s","dxcbvbc");

fclose(f);
QSqlQueryModel *model = new QSqlQueryModel(this);
   model->setHeaderData(0, Qt::Vertical, tr("chat"));
}
chat1::~chat1()
{
    delete ui;
}

void chat1::on_pushButton_clicked()
{
    affichere1();
}
