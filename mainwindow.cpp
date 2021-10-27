#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <iostream>

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
        if(username.contains("@"))
        {
            f=true;
        }
    }
    if(f==true)
    {
        QMessageBox::information(this,"Login","correct");
        hide();

    }else
        QMessageBox::warning(this,"Login","incorrect");


}
