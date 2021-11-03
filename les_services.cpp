#include "les_services.h"
#include "ui_les_services.h"
#include "mainwindow.h"
les_services::les_services(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::les_services)
{
    ui->setupUi(this);
}

les_services::~les_services()
{
    delete ui;
}

void les_services::on_trier_2_clicked()
{
    hide();
    mainwindow = new MainWindow(this);
    mainwindow->show();
}
