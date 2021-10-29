#ifndef PUB_H
#define PUB_H

#include <QDialog>

namespace Ui {
class pub;
}

class pub : public QDialog
{
    Q_OBJECT

public:
    explicit pub(QWidget *parent = nullptr);
    ~pub();

private:
    Ui::pub *ui;
};

#endif // PUB_H
