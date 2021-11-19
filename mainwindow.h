#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "chat1.h"
#include "chat2.h"
#include <QMainWindow>
#include<QFileDialog>
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
    void on_Valider_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_trier_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_pressed();

    void on_pushButton_6_clicked();

    void on_PDF_clicked();

    void on_pushButton_7_clicked();

    void on_impression_clicked();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    chat1 *c1;
    chat2 *c2;
};
#endif // MAINWINDOW_H
