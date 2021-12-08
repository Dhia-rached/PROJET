#ifndef STATLOCAL_H
#define STATLOCAL_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Statlocal;
}

class Statlocal : public QDialog
{
    Q_OBJECT

public:
    explicit Statlocal(QWidget *parent = nullptr);
    ~Statlocal();
    QChartView *chartView ;
    void choix_bar();

private:
    Ui::Statlocal *ui;
};

#endif // STATLOCAL_H
