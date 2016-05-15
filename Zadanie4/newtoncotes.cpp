#include "newtoncotes.h"
#include <iostream>
using namespace std;
NewtonCotes::NewtonCotes() : Calkowanie()
{

}

double NewtonCotes::calkuj(vector<double> x,double h,Funkcja * wsk)
{
    double Y=0;
    vector<double>y;
    for(int i=0;i<x.size();i++)
    {
        y.push_back(wsk->oblicz(x.at(i)));
    }
    double tmpYnp=0;
    double tmpYp=0;
    int n =(y.size()-1)/2;
    for(int i=1;i<n;i++)
    {
        tmpYnp+=y.at(2*i-1);
    }
    for(int i=1;i<n-1;i++)
    {
        tmpYp+=y.at(2*i);
    }
    Y = (h/3.0) * (y.at(0) + 4* tmpYnp + 2* tmpYp + y.at(y.size()-1));
    return Y;
}

