#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vehi.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajout_clicked();

    void on_pb_sup_clicked();

    void on_pb_ajout_2_clicked();

    void on_tab_vehi_2_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_recherche_clicked();

    void on_pb_marque_clicked();

    void on_pb_date_clicked();

    void on_rechercher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sendBtn_clicked();

    void on_pushButton_3_clicked();

   /* void on_browseBtn_clicked();
            void  browse();
            void  mailSent(QString status);
            //void on_sendBtn_clicked();*/

            void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Vehi V;
};

#endif // MAINWINDOW_H
