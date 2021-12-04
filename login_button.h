#ifndef LOGIN_BUTTON_H
#define LOGIN_BUTTON_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class login_button;
}

class login_button : public QDialog
{
    Q_OBJECT

public:
    explicit login_button(QWidget *parent = nullptr);
    ~login_button();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login_button *ui;
    MainWindow *m;
};

#endif // LOGIN_BUTTON_H
