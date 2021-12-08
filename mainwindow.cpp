#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
        switch (ret) {
        case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
            break;
        case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
            break;
        case(-1):qDebug()<<"arduino is not available";
        }
  QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    QIntValidator *val=new QIntValidator(10000000,99999999,this);
    ui->ID->setValidator(val);
     ui->tab_location->setModel(l.afficher());
      connect(ui->lineEditRech, SIGNAL(textChanged(QString)), this, SLOT(affrech()));
      QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
     if (!file.open(QIODevice::ReadOnly))
     {
         QMessageBox::information(0,"info",file.errorString());
     }
     QTextStream in (&file);
    ui->textBrowser->setText(in.readAll());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::affrech(){
ui->tab_location->setModel(l.afficherRech(ui->comboBox_2->currentText(),ui->lineEditRech->text()));
}
void MainWindow::update_label()
{
data.append(a.read_from_arduino());
qDebug()<<data;
if(data.length()==8){
if (l.rech(data.toInt()))
 {
    a.write_to_arduino("1");
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Location trouvé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    a.write_to_arduino("3");
    data.clear();
}else{
    a.write_to_arduino("2");
    QMessageBox::critical(nullptr, QObject::tr(""),
                QObject::tr("Location non trouvé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    a.write_to_arduino("3");
    data.clear();
}}
}
void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->ID->text().toInt();
    QString duree=ui->Duree->text();
    QString etat=ui->Etat->text();
    float prix=ui->Prix->text().toFloat();
    location l(id,duree,etat,prix);
   QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
       if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
           return;

       QTextStream cout(&file);
QString iden=QString::number(id);
if(iden.length()==8)
{

    bool test=l.ajouter();
    if(test){
        player->setMedia(QUrl::fromLocalFile("C:/Users/mosta/OneDrive/Desktop/beep-06.wav"));
        player->setVolume(50);
        player->play();
        QString message2="\nAjout le : "+QDate::currentDate().toString("dd/MM/yyyy");
                cout << message2;
                QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
               if (!file.open(QIODevice::ReadOnly))
               {
                   QMessageBox::information(0,"info",file.errorString());
               }
               QTextStream in (&file);
              ui->textBrowser->setText(in.readAll());

         ui->tab_location->setModel(l.afficher());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Ajouté avec succes.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
    {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr("Ajout erroné.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    player->setMedia(QUrl::fromLocalFile("/path"));
    player->setVolume(50);
    player->play();}}
}


void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->ID->text().toInt();
    QString duree=ui->Duree->text();
    QString etat=ui->Etat->text();
    float prix=ui->Prix->text().toFloat();
    location l(id,duree,etat,prix);
    QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
       if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
           return;

       QTextStream cout(&file);


    bool test=l.modifier(id);
    if(test){
        player->setMedia(QUrl::fromLocalFile("C:/Users/mosta/OneDrive/Desktop/beep-06.wav"));
        player->setVolume(50);
        player->play();
        QString message2="\nModification le : "+QDate::currentDate().toString("dd/MM/yyyy");
                cout << message2;
                QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
               if (!file.open(QIODevice::ReadOnly))
               {
                   QMessageBox::information(0,"info",file.errorString());
               }
               QTextStream in (&file);
              ui->textBrowser->setText(in.readAll());
         ui->tab_location->setModel(l.afficher());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Modifié avec succes.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
     {   QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr("Ajout erroné.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    player->setMedia(QUrl::fromLocalFile("/path"));
    player->setVolume(50);
    player->play();}
}


void MainWindow::on_pushButton_5_clicked()
{
    int row =ui->tab_location->selectionModel()->currentIndex().row();
    int id=ui->tab_location->model()->index(row,0).data().toInt();
    QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
       if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
           return;

       QTextStream cout(&file);
    bool test=l.supprimer(id);
    if(test){
        player->setMedia(QUrl::fromLocalFile("C:/Users/mosta/OneDrive/Desktop/beep-06.wav"));
        player->setVolume(50);
        player->play();
        QString message2="\nSuppression le : "+QDate::currentDate().toString("dd/MM/yyyy");
                cout << message2;
                QFile file("C:/Users/mosta/OneDrive/Desktop/history.txt");
               if (!file.open(QIODevice::ReadOnly))
               {
                   QMessageBox::information(0,"info",file.errorString());
               }
               QTextStream in (&file);
              ui->textBrowser->setText(in.readAll());
         ui->tab_location->setModel(l.afficher());
         QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Supprimé avec succes.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
      {  QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr("Suppression erroné.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    player->setMedia(QUrl::fromLocalFile("C:/Users/mosta/OneDrive/Desktop/beep-06.wav"));
    player->setVolume(50);
    player->play();}
}


void MainWindow::on_pushButton_6_clicked()
{
     ui->tab_location->setModel(l.afficherTri(ui->comboBoxTri->currentText()));
}


void MainWindow::on_pushButton_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_location->model()->rowCount();
                        const int columnCount = ui->tab_location->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des locations</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_location->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_location->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_location->isColumnHidden(column)) {
                                                QString data = ui->tab_location->model()->data(ui->tab_location->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size());
                                doc.print(&printer);

}

