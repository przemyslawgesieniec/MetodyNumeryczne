#include "gauss.h"

Gauss::Gauss() : Calkowanie()
{

}

double Gauss::calkuj(vector<double> x,double h, Funkcja *wsk)
{
    double Y=0;
    double n= x.size();
    for(int i=1;i<n;i++)
    {
        Y+= cos(M_PI*(2*i-1)/(2*n))  * (M_PI/n);
    }
    return Y;
}

