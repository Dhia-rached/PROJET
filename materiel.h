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

    void on_Valider_2_clicked();

    void on_afficher_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();


    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_trier_clicked();

    void on_trier_num_serie_clicked();

    void on_pdf_clicked();

    void on_pushButton_impression_clicked();

    void on_pushButton_r_m_clicked();

    void on_pushButton_r_t_clicked();

    void on_pushButton_quantiter_clicked();

    void on_pushButton_stat_clicked();

    void on_comboBox_tri_currentIndexChanged(const QString &arg1);

private:
    Ui::materiel *ui;
    Mat m;


};

#endif // MATERIEL_H
