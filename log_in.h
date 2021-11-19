#ifndef LOG_IN_H
#define LOG_IN_H
#include "mainwindow.h"
#include <QDialog>
#include <string>
#include "les_services.h"
#include "login_button.h"
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
    void on_pushButton_clicked();

private:
    Ui::Log_in *ui;
    MainWindow *mainwindow;
    les_services *services;
    login_button *lg;
};
#endif // LOG_IN_H
