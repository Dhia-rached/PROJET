#include "pub.h"
#include "ui_pub.h"

pub::pub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pub)
{
    ui->setupUi(this);
}

pub::~pub()
{
    delete ui;
}
