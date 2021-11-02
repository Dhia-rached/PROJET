#ifndef MATERIEL_H
#define MATERIEL_H

#include <QDialog>
#include<string>
#include"mat.h"
using namespace std;


namespace Ui {
class materiel;
}

class materiel : public QDialog
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();

private slots:
    void on_Valider_clicked();

    void on_supp_clicked();

    void on_nom_m_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::materiel *ui;
    Mat m;
};

#endif // MATERIEL_H
