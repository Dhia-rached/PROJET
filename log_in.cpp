#include "log_in.h"
#include "ui_log_in.h"
#include <QMessageBox>
#include <mainwindow.h>
Log_in::Log_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_in)
{
    ui->setupUi(this);
}

Log_in::~Log_in()
{
    delete ui;
}

void Log_in::on_login_clicked()
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
        mainwindow = new MainWindow(this);
        mainwindow->show();
    }else
        QMessageBox::warning(this,"Login","incorrect");
}
