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

    void on_Valider_2_clicked();

    void on_afficher_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_load_list_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::materiel *ui;
    Mat m;
};

#endif // MATERIEL_H
