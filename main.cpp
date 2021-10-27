#include "mainwindow.h"
#include "log_in.h"
#include <QApplication>
//Dhia
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Log_in l;
    MainWindow w;
    l.show();
    return a.exec();
}
