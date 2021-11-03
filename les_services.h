#ifndef LES_SERVICES_H
#define LES_SERVICES_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class les_services;
}

class les_services : public QDialog
{
    Q_OBJECT

public:
    explicit les_services(QWidget *parent = nullptr);
    ~les_services();

private slots:
    void on_trier_2_clicked();

private:
    Ui::les_services *ui;
    MainWindow *mainwindow;
};

#endif // LES_SERVICES_H
