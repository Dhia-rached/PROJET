#include "mainwindow.h"
#include "log_in.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
//Dhia
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test;
    c.createconnect();
    test=c.ourirConnexion();

    Log_in l;

        MainWindow w;
    if(test==true)
    {
    w.show();
     QMessageBox::information(nullptr,"Data base ","connection succeful");
    }else
    {
        QMessageBox::warning(nullptr,"Data base ","connection failed");


    }
    return a.exec();

}
