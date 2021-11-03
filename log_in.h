#ifndef LOG_IN_H
#define LOG_IN_H
#include "mainwindow.h"
#include <QDialog>
#include <string>
#include "les_services.h"
using namespace std ;
namespace Ui {
class Log_in;
}
class Log_in : public QDialog
{
    Q_OBJECT
public:
    explicit Log_in(QWidget *parent = nullptr);
    ~Log_in();
private slots:
    void on_login_clicked();
private:
    Ui::Log_in *ui;
    MainWindow *mainwindow;
    les_services *services;
};
#endif // LOG_IN_H
