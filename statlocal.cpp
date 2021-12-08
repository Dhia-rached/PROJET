#include "statlocal.h"
#include "ui_statlocal.h"

Statlocal::Statlocal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statlocal)
{
    ui->setupUi(this);
}

Statlocal::~Statlocal()
{
    delete ui;
}

void Statlocal::choix_bar()
{
QSqlQuery q1,q2,q3,q4, q5;


qreal tot=0, c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM local");
q1.exec();

q2.prepare("SELECT * FROM local WHERE etat='Disponible'");
q2.exec();

q3.prepare("SELECT * FROM local WHERE etat='NON Disponible'");
q3.exec();





while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}


if (c1>0){
c1=c1/tot;
}
if(c2>0){
c2=c2/tot;
}
if(c3>0){
c3=c3/tot;
}



// Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("Disponible");
        QBarSet *set1 = new QBarSet("NON DISPONIBLE");
        QBarSet *set2 = new QBarSet("other");


        // Assign values for each bar
        *set0 << c1;
        *set1 << c2;
        *set2 << c3;




        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        series->append(set0);
        series->append(set1);
        series->append(set2);



        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);


        // Adds categories to the axes
        QBarCategoryAxis *axis = new QBarCategoryAxis();



        // 1. Bar chart
        chart->setAxisX(axis, series);

        // Used to change the palette
        QPalette pal = qApp->palette();

        // Change the color around the chart widget and text
        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));

        // Apply palette changes to the application
        qApp->setPalette(pal);


// Used to display the chart
chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}
