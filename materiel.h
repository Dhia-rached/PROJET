#ifndef MATERIEL_H
#define MATERIEL_H

#include <QDialog>
#include<string>

using namespace std;

class materiels
{
private:
    int num_serie;
    int quantiter;
    float prix;
    string nom_fournisseur;
    string nom_materiel;
    string type;

public:
    void ajouter_materiel();
    void supprimer_materiel();
    void afficher_materiel();
    void modifier_materiel();

};
namespace Ui {
class materiel;
}

class materiel : public QDialog
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();

private slots:
    void on_Valider_clicked();

private:
    Ui::materiel *ui;
};

#endif // MATERIEL_H
