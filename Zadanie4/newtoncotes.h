#ifndef NEWTONCOTES_H
#define NEWTONCOTES_H
#include "calkowanie.h"
#include <vector>
#include "funkcja.h"
using namespace std;

class NewtonCotes :public Calkowanie
{
public:
    NewtonCotes();
    double calkuj(vector<double> x, double h, Funkcja *wsk);
};

#endif // NEWTONCOTES_H
