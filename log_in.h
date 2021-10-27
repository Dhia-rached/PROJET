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

private:
    int cin;
    string nom,prenom,adr,email,mdp;
    float salaire;
public:
    ////Getters
    int get_cin();
    string get_nom();
    string get_prenom();
    string get_adr();
    string get_email();
    string get_mdp();
    float get_salaire();
    ////Setters
    void set_cin(int cin);
    void set_nom(string nom);
    void set_prenom(string prenom);
    void set_adr(string adr);
    void set_email(string email);
    void set_mdp(string mdp);
    void set_salaire(float salaire);

};

#endif // LOG_IN_H
