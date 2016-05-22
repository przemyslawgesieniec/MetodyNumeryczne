#include "gauss.h"
#include <iostream>
using namespace std;

Gauss::Gauss() : Calkowanie()
{
    zeraCzebyszewa.push_back(-0.906180);
    zeraCzebyszewa.push_back(-0.538469);
    zeraCzebyszewa.push_back(0);
    zeraCzebyszewa.push_back(0.538469);
    zeraCzebyszewa.push_back(0.906180);

    zeraCzebyszewa.push_back(-0.861136);
    zeraCzebyszewa.push_back(-0.339981);
    zeraCzebyszewa.push_back(0.339981);
    zeraCzebyszewa.push_back(0.861136);

    zeraCzebyszewa.push_back(-0.77459);
    zeraCzebyszewa.push_back(0);
    zeraCzebyszewa.push_back(0.77459);

    zeraCzebyszewa.push_back(-0.577350);
    zeraCzebyszewa.push_back(0.577350);
}

double Gauss::calkuj(vector<double> x, double h, Funkcja *wsk, bool waga)
{
    double Y=0;
    double n=x.size();
    for(int i=0;i<n;i++)
    {
        Y+= wsk->oblicz(x.at(i),0) * (M_PI/n);
    }
    return Y;
}

