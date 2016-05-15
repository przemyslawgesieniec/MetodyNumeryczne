#ifndef CALKOWANIE_H
#define CALKOWANIE_H
#include <vector>
#include "funkcja.h"
using namespace std;

class Calkowanie
{
public:
    Calkowanie(){};
    virtual ~Calkowanie() {};
    virtual double calkuj(vector<double> x,double h,Funkcja *wsk)=0;
};

#endif // CALKOWANIE_H
