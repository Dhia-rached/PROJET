#ifndef CHAT1_H
#define CHAT1_H

#include <QDialog>

namespace Ui {
class chat1;
}

class chat1 : public QDialog
{
    Q_OBJECT

public:
    explicit chat1(QWidget *parent = nullptr);
    void affichere1();
    ~chat1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::chat1 *ui;
};

#endif // CHAT1_H
