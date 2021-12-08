#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "location.h"
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QTextDocument>
#include <QMediaPlayer>
#include "arduino.h"

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
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void affrech();

    void on_pushButton_clicked();

    void update_label();

private:
    Ui::MainWindow *ui;
    location l;
    QMediaPlayer *player = new QMediaPlayer;

    arduino a;
    QByteArray data;
};
#endif // MAINWINDOW_H
