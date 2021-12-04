#ifndef SECURITE_H
#define SECURITE_H
#include "log_in.h"
#include <QDialog>

namespace Ui {
class securite;
}

class securite : public QDialog
{
    Q_OBJECT

public:
    explicit securite(QWidget *parent = nullptr);
    void notification(QString cls);
    void notification1(QString cls);
    ~securite();

private slots:
    void on_login_clicked();

private:
    Ui::securite *ui;
    Log_in *l;
};

#endif // SECURITE_H
