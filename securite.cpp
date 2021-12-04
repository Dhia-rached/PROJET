#include "securite.h"
#include "ui_securite.h"
#include <QMessageBox>
#include <QMediaPlayer>
//#include <MMsystem.h>
#include <windows.h>
#include <stdio.h>
#include <QSystemTrayIcon>
#include <QtMultimedia/QSound>
securite::securite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::securite)
{
    ui->setupUi(this);
}

securite::~securite()
{
    delete ui;
}
void securite::notification(QString cls)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("operation effectué",cls,QSystemTrayIcon::Information,15000);
  //  QSound newMessage(":/mixkit-positive-interface-beep-221.wav");
   // newMessage.play();
}
void securite::notification1(QString cls)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("operation effectué",cls,QSystemTrayIcon::Warning,15000);
  QSound newMessage("Welcome.mp3");
   newMessage.play();
}
void securite::on_login_clicked()
{
    QMediaPlayer *player=new QMediaPlayer();
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    if(ui->code->text()=="smartgarage2022")
    {
//PlaySound(TEXT("Users/Kiraxer/Desktop/sound.mp3"),NULL,SND_SYNC);

        hide();
notification("welcome");
l=new Log_in(this);

l->show();

    }else
    {
        notification1("Failed");
        QMessageBox::warning(this,"Login","failed");

}



}
