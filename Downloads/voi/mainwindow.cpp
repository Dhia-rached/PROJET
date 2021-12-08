#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehi.h"
#include <QRegExpValidator>
#include <QMessageBox>
#include <qsqlquerymodel.h>
#include<QDateEdit>
#include <QSqlQuery>
#include<QObject>
#include<QPdfWriter>
#include<QUrl>
#include<QDesktopServices>
#include<QPainter>
#include<QFileDialog>
#include<QFile>
#include<QStringList>
#include"smtp.h"



using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx;
    rx.setPattern("[0-9]\\d{0,2}TUN[0-9]\\d{0,3}");
    ui->mat->setValidator( new QRegExpValidator(rx, this));
    ui->tab_vehi->setModel(V.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
   //
}

void MainWindow::on_pb_ajout_clicked()
{
    QString matricule=ui->mat->text();
    QString marque=ui->mar->text();
    QString couleur=ui->cou->text();
    QString panne=ui->panne->text();
    QDate   datee=ui->date->date();
    Vehi v(matricule,marque,couleur,panne,datee);
    bool test =v.ajouter();
    QMessageBox msgbox;
    if (test)
    {   ui->tab_vehi->setModel(V.afficher());
        ui->tab_vehi_2->setModel(V.afficher());
        msgbox.setText("ajout avec succes");
        msgbox.exec();
    }

    else
    {
        msgbox.setText("ajout a echoue");
        msgbox.exec();

    }


}

void MainWindow::on_pb_sup_clicked()
{
    Vehi v1;
    QMessageBox msgbox;
    v1.setmatricule(ui->le_sup->text());
    QString matricule=ui->le_sup->text();
    bool test=v1.supprimer(matricule);
    QMessageBox msgbox1;
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTION_VEHICULE where matricule=:matricule");
    query.bindValue(":matricule", matricule);
    query.exec();
    bool alreadyExist = false;
    alreadyExist = query.next();
    if(alreadyExist==true)
    {


    if (test)
    {   ui->tab_vehi->setModel(V.afficher());
        ui->tab_vehi_2->setModel(V.afficher());
        msgbox.setText("suppretion avec succes");
        msgbox.exec();
    }

    else
    {
        msgbox.setText("suppretion a echoue");
        msgbox.exec();

    }
    }
    else

        msgbox1.setText("matricule n'existe pas");
        msgbox1.exec();
}

void MainWindow::on_pb_ajout_2_clicked()
{
    QString matricule=ui->mat_2->text();
    QString marque=ui->mar_2->text();
    QString couleur=ui->cou_2->text();
    QString panne=ui->panne_2->text();
    QDate   datee=ui->date_2->date();
    Vehi v (matricule,marque,couleur,panne,datee);
    QMessageBox msgbox1;
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTION_VEHICULE where matricule=:matricule");
    query.bindValue(":matricule", matricule);
    query.exec();
    bool alreadyExist = false;
    alreadyExist = query.next();
    if(alreadyExist)
    {
        QMessageBox msgbox;

        bool test =v.modifier();
    if (test==true)
    {
        msgbox.setText("modification avec succes");
        ui->tab_vehi->setModel(v.afficher());
        msgbox.exec();
        ui->mat_2->setText("");
        ui->mar_2->setText("");
        ui->cou_2->setText("");
        ui->panne_2->setText("");
        ui->date_2->setDate(datee);




    }

    else
    {
        msgbox.setText("modification a echoue");
        msgbox.exec();

    }
    }
    else

        msgbox1.setText("matricule n'existe pas");
        msgbox1.exec();
}


void MainWindow::on_tab_vehi_2_activated(const QModelIndex &index)
{
    //
}

void MainWindow::on_pb_modifier_clicked()
{
  //
}

void MainWindow::on_pb_recherche_clicked()
{
    ui->tab_vehi->setModel(V.tri());
}

void MainWindow::on_pb_marque_clicked()
{
    ui->tab_vehi->setModel(V.tri1());
}

void MainWindow::on_pb_date_clicked()
{
    ui->tab_vehi->setModel(V.tri2());
}

void MainWindow::on_rechercher_clicked()
{
    QString nom_m = ui->le_recherche->text();
                ui->tab_vehi_2->setModel(V.recherche(nom_m));

}

void MainWindow::on_pushButton_clicked()
{
    QPdfWriter pdf("C:/Users/azerb/Desktop/TD.pdf");

        QPainter painter(&pdf);

        int i = 4000;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30));
        painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("‪C:/Users/azerb/Desktop/modif.PNG"));
        painter.drawText(3000,1500,"LISTE DES VEHICULES");
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(2700,200,6300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"Matricule");
        painter.drawText(2300,3300,"MARQUE");
        painter.drawText(4300,3300,"couleur");
        painter.drawText(6000,3300,"panne");
        painter.drawText(8300,3300,"date");
        QSqlQuery query;
        query.prepare("select * from GESTION_VEHICULE");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(2300,i,query.value(1).toString());
            painter.drawText(4300,i,query.value(2).toString());
            painter.drawText(6300,i,query.value(3).toString());
            painter.drawText(8000,i,query.value(4).toString());

            i = i +500;
        }

        int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/azerb/Desktop/TD.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/azerb/Desktop/Nouveau Feuille de calcul Microsoft Excel.xlsx"));
}

void MainWindow::on_sendBtn_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QString link="https://mail.google.com/mail/u/1/#inbox";
    QDesktopServices::openUrl(link);
}
//mail


/*void MainWindow::on_browseBtn_clicked()
{
    //files.clear();

        QFileDialog dialog(this);
        dialog.setDirectory(QDir::homePath());
        dialog.setFileMode(QFileDialog::ExistingFiles);

        if (dialog.exec())
            //files = dialog.selectedFiles();

        QString fileListString;
       // foreach(QString file, files)
            //fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

        //ui->file->setText( fileListString );
}



void   MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP GESTION_VEHICULE" ), tr( "Mail envoyé!\n\n" ) );
    ui->rcpt->clear();
    ui->sujet->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void MainWindow::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("azer.ben.1414@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    //(const QString &from, const QString &to, const QString &subject, const QString &body)
        if( !files.isEmpty() )
            smtp->sendMail("azer.ben.1414@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
        else
            smtp->sendMail("azer.ben.1414@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->toPlainText());
}

*/
