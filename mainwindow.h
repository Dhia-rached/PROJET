#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "local.h"
#include <QMainWindow>
#include "statlocal.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Valider_ajout_clicked();

    void on_pushButton_2_clicked();

    void on_reference_modifier_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pdfBtn_clicked();

    void on_statBtn_clicked();

    void on_trier_clicked();

    void on_impression_clicked();

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_statBtn_2_clicked();

    void on_afficher2_clicked();

private:
    Ui::MainWindow *ui;
    Local locale;
    Statlocal *s;
};
#endif // MAINWINDOW_H
