#include "log_in.h"
#include "ui_log_in.h"
#include <QMessageBox>
#include <mainwindow.h>
#include <string>
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

bool f=false,m=false;
    for(i=0;i<username.length();i++)
    {
        if(username.contains("@")&&username.contains(".")&&username.contains("com")&&username.contains("gmail"))
        {
            f=true;
        }
    }
    if(mdp!="")
        m=true;
    if(f==true&&m==true)
    {
        QMessageBox::information(this,"Login","correct");
        hide();
        services = new les_services(this);
        services->show();
    }
    if(f==false)
        QMessageBox::warning(this,"Login","email incorrect");
    if (m==false)
         QMessageBox::warning(this,"Login","mot de passe incorrect");
}


