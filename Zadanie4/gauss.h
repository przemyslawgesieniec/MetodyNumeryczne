#ifndef GAUSS_H
#define GAUSS_H
#include "calkowanie.h"
#include <vector>
#include <math.h>
#include "funkcja.h"
using namespace std;

class Gauss : public Calkowanie
{
public:
    Gauss();
    double calkuj(vector<double> x, double h, Funkcja *wsk,bool waga);
private:
vector<double> zeraCzebyszewa;
vector<double> wspCzebyszewa;
};

#endif // GAUSS_H
