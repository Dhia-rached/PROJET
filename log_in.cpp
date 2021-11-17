#include "log_in.h"
#include "ui_log_in.h"
#include <QMessageBox>
#include <mainwindow.h>
#include <string>
#include "employe.h"
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
      employe e;
    e.email=ui->email->text();
    e.mdp=ui->password->text();
  int i;

bool f=false,m=false;
    for(i=0;i<e.email.length();i++)
    {
        if(e.email.contains("@")&&e.email.contains(".")&&e.email.contains("com")&&e.email.contains("gmail"))
        {
            f=true;
        }
    }
    if(e.mdp!="")
        m=true;
    if(f==true&&m==true)
    {
         e.ajouter1();
        QMessageBox::information(this,"Login","correct");
        hide();
        services = new les_services(this);
        services->show();
    }
    if(f==false)
        QMessageBox::warning(this,"Login","check your email");
    if(m==false)
        QMessageBox::warning(this,"Login","check your mot de passe");



}


