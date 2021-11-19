#include "materiel.h"
#include "ui_materiel.h"
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <QString>
#include <string>
#include <QIntValidator>
#include <QSqlQuery>
#include <QRegExpValidator>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include<QDesktopServices>
#include <QTextStream>
#include <QTextDocument>
#include <QPrintDialog>
#include "piechart.h"

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

#include "mat.h" //fichier qui contient la class mat

materiel::materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);

    /*QPixmap pix("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/image/logo0");
    ui->label_logo->setPixmap(pix.scaled(200,150,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/image/background4");
    ui->label_back->setPixmap(pix1.scaled(1281,671,Qt::KeepAspectRatio));*/
    ui->numserie->setValidator( new QIntValidator(0, 99999999, this));
    ui->numserie_2->setValidator( new QIntValidator(0, 99999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->type->setValidator(valiNom);
    ui->nom_m->setValidator(valiNom);
    ui->nom_f->setValidator(valiNom);
    ui->nom_f_2->setValidator(valiNom);
    ui->nom_m_2->setValidator(valiNom);
    ui->type_2->setValidator(valiNom);
    ui->nom_r->setValidator(valiNom);

    QChartView *chartview =m.piechart();
        chartview->setParent(ui->horizontalFrame);
        QChartView *chartview2 =m.piechart2();
            chartview2->setParent(ui->horizontalFrame_2);
    //ui->tab_mat->setModel(m.afficher_materiel());

}

materiel::~materiel()
{
    delete ui;
}

void materiel::on_Valider_clicked()
{

    int num_serie=ui->numserie->text().toInt();
    int quantiter=ui->quantiter->text().toInt();
    int prix=ui->prix->text().toInt();
    QString nom_fournisseur=ui->nom_f->text();
    QString nom_materiel=ui->nom_m->text();
    QString type=ui->type->text();


    Mat m(num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type);
// verification du prix et de la quantiter positive
    /*bool test=true;
    if((prix<0)||(quantiter<0))
    {test=false;}*/
bool test =  m.ajouter_materiel();

    if (test==true)
    {
     //   m.ajouter_materiel();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("l'ajout effectué avec succ.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE L'AJOUT .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->tab_mat->setModel(m.afficher_materiel());
QChartView *chartview =m.piechart();
    chartview->setParent(ui->horizontalFrame);

    QChartView *chartview2 =m.piechart2();
        chartview2->setParent(ui->horizontalFrame_2);

}

void materiel::on_supp_clicked()
{

    Mat m1;
    // m1.setnums(ui->comboBox_2->currentIndex());
    bool test=m1.supprimer_materiel(ui->comboBox_2->currentIndex());
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("a suppression effectué avec succ.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE La suppression .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tab_mat->setModel(m.afficher_materiel());
    QChartView *chartview =m.piechart();
        chartview->setParent(ui->horizontalFrame);

        QChartView *chartview2 =m.piechart2();
            chartview2->setParent(ui->horizontalFrame_2);
}

//MODIFICATION
void materiel::on_Valider_2_clicked()
{
    int num_serie=ui->numserie_2->text().toInt();
    int quantiter=ui->quantiter_2->text().toInt();
    int prix=ui->prix_2->text().toInt();
    QString nom_fournisseur=ui->nom_f_2->text();
    QString nom_materiel=ui->nom_m_2->text();
    QString type=ui->type_2->text();
    Mat m(num_serie,quantiter,prix,nom_fournisseur,nom_materiel,type);

    bool test=m.modifier_materiel();



    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("la modification effectué avec succ.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE LA MODIF .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tab_mat->setModel(m.afficher_materiel());
    QChartView *chartview =m.piechart();
        chartview->setParent(ui->horizontalFrame);

        QChartView *chartview2 =m.piechart2();
            chartview2->setParent(ui->horizontalFrame_2);

}

void materiel::on_afficher_clicked()
{
    ui->tab_mat->setModel(m.afficher_materiel());
    QChartView *chartview =m.piechart();
        chartview->setParent(ui->horizontalFrame);

        QChartView *chartview2 =m.piechart2();
            chartview2->setParent(ui->horizontalFrame_2);


}

//for loading list
void materiel::on_pushButton_clicked()
{
     QSqlQueryModel*  model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT num_serie FROM GESTION_MATERIEL");
     query.exec();
     model->setQuery(query);
    ui->comboBox->setModel(model);
    QChartView *chartview =m.piechart();
        chartview->setParent(ui->horizontalFrame);

}

void materiel::on_comboBox_currentIndexChanged(int index)
{

    int n_serie=ui->comboBox->currentIndex();
     QString n_serie_s=QString::number(n_serie);
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTION_MATERIEL where num_serie='"+n_serie_s+"'");
    if(query.exec())
    {
        while (query.next())
        {
          ui->numserie_2->setText(query.value(0).toString()) ;
          ui->quantiter_2->setText(query.value(1).toString()) ;
          ui->prix_2->setText(query.value(2).toString()) ;
          ui->nom_m_2->setText(query.value(3).toString()) ;
          ui->nom_f_2->setText(query.value(4).toString()) ;
          ui->type_2->setText(query.value(5).toString()) ;
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE chargement .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}


void materiel::on_pushButton_2_clicked()
{
    QSqlQueryModel*  model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT num_serie FROM GESTION_MATERIEL");
    query.exec();
    model->setQuery(query);
   ui->comboBox_2->setModel(model);
}

void materiel::on_comboBox_2_currentIndexChanged(int index)
{
    int n_serie=ui->comboBox_2->currentIndex();
     QString n_serie_s=QString::number(n_serie);
    QSqlQuery query;
    query.prepare("SELECT * FROM GESTION_MATERIEL where num_serie='"+n_serie_s+"'");
    if(query.exec())
    {
        while (query.next())
        {
          ui->num_serie_supp->setText(query.value(0).toString()) ;

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                    QObject::tr("ECHEC DE chargement .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}


//RECHECHRE PAR NOM FOURNISSEUR
void materiel::on_pushButton_3_clicked()
{
    QString nom_f = ui->nom_r->text();
             ui->tableViewM->setModel(m.rechercher_f(nom_f));
}
//RECHECHRE PAR NOM MATERIEL

void materiel::on_pushButton_r_m_clicked()
{
    QString nom_m = ui->nom_r_2->text();
             ui->tableViewM->setModel(m.rechercher_m(nom_m));
}
//RECHECHRE PAR TYPE
void materiel::on_pushButton_r_t_clicked()
{
    QString nom_t = ui->nom_r_3->text();
             ui->tableViewM->setModel(m.rechercher_t(nom_t));
}

//TRIE PAR PRIX
void materiel::on_pushButton_trier_clicked()
{
    ui->tableViewM->setModel(m.trier());
}
// TRIE PAR NUM SERIE dans affichage
void materiel::on_trier_num_serie_clicked()
{
    ui->tab_mat->setModel(m.trier_num_serie());
}

//TRIE PAR QUANTITER
void materiel::on_pushButton_quantiter_clicked()
{
    ui->tableViewM->setModel(m.trier_quantiter());
}


void materiel::on_pdf_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/Pdf_aissa.pdf");

    QPainter painter(&printer);
   int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 40));
        painter.drawText(2200,1200,"Liste de matriel ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 20));
        painter.drawRect(1000,100,7300,2000);
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial",10));
        painter.drawText(200,3300,"num_serie");
        painter.drawText(1500,3300,"quantiter");
        painter.drawText(2500,3300,"prix");
        painter.drawText(3300,3300,"fournisseur");
        painter.drawText(4400,3300,"nom_materiel");
        painter.drawText(5800,3300,"type");


        QSqlQuery query;
        query.prepare("select * from gestion_materiel ");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1500,i,query.value(1).toString());
            painter.drawText(2500,i,query.value(2).toString());
            painter.drawText(3500,i,query.value(3).toString());
            painter.drawText(4500,i,query.value(4).toString());
            painter.drawText(5700,i,query.value(5).toString());


           i = i + 500;
        }


        int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/swide/OneDrive/Bureau/esprit 2em/projet C++/Pdf_aissa.pdf"));

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                painter.end();
            }
}

void materiel::on_pushButton_impression_clicked()
{


        QString fileName = QFileDialog::getOpenFileName(0,"Open File",QString(),"PDF File(*.pdf)");

                QPrinter printer;
                QPrintDialog *dlg = new QPrintDialog(&printer,0);
                if(dlg->exec() == QDialog::Accepted) {
                        QImage pdf(fileName);
                        QPainter painter(&printer);
                        painter.drawImage(QPoint(0,0),pdf);
                        painter.end();
                }

                delete dlg;


}



void materiel::on_pushButton_stat_clicked()
{

}

void materiel::on_comboBox_tri_currentIndexChanged(const QString &arg1)
{
       QString crit =ui->comboBox_tri->currentText();
       if(crit == "trie Prix")
       {
           ui->tableViewM->setModel(m.trier());
       }
       else if(crit == "Trie Quantiter")
       {
            ui->tableViewM->setModel(m.trier_quantiter());
       }
       else
       {
           ui->tableViewM->setModel(m.trier_num_serie());

       }

}











