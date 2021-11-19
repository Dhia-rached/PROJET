#include "mainwindow.h"
#include "log_in.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
#include "lgoin_bd.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include "securite.h"
//Dhia
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    securite h;
    lgoin_bd b;
    Connection c;
    Log_in l;
    bool test,test1;



        b.createconnect1();
        test1=b.ourirConnexion1();
        if(test1==true)
        {
        h.show();
         QMessageBox::information(nullptr,"Data base ","connection succeful");
        }else
        {
           QMessageBox::warning(nullptr,"Data base ","connection failed");
        }












//////////////////////////////////////connection 2








/*
    c.createconnect();



    test=c.ourirConnexion();


        MainWindow w;
    if(test==true)
    {
    w.show();
     QMessageBox::information(nullptr,"Data base ","connection succeful");
    }else
    {

       QMessageBox::warning(nullptr,"Data base ","connection failed");


    }
/* w.close();
c.fermerConnexion();
    b.createconnect1();
    test1=b.ourirConnexion1();

    if(test1==true)
    {
    w.show();
     QMessageBox::information(nullptr,"Data base ","connection succeful");
    }else
    {
       QMessageBox::warning(nullptr,"Data base ","connection failed");


    }*/

    if (test1==true && test==true)
        cout<<"hello"<<endl;

    return a.exec();

}
