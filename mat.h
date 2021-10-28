#ifndef MAT_H
#define MAT_H
#include <string>

using namespace std;

class Mat
{
public:
    Mat();
    Mat(int,int,float,string,string,string);
    int getnums();
    int getquantiter();
    float getprix();
    string getnomf();
    string getnomm();
    string gettype();

    void setnums(int);
    void setquantiter(int);
    void setprix(float);
    void setnomf(string);
    void setnomm(string);
    void settype(string);
    bool ajouter_materiel();
    void supprimer_materiel();
    void afficher_materiel();
    void modifier_materiel();



private:
    int num_serie;
    int quantiter;
    float prix;
    string nom_fournisseur;
    string nom_materiel;
    string type;


};

#endif // MAT_H
