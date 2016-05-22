#ifndef FUNKCJATRYGONOMETRYCZNA_H
#define FUNKCJATRYGONOMETRYCZNA_H
#include "funkcja.h"
#include <cmath>

using namespace std;

class FunkcjaTrygonometryczna: public Funkcja
{
public:
    FunkcjaTrygonometryczna();
    string napis();
    double oblicz(double x, bool waga);
};

#endif // FUNKCJATRYGONOMETRYCZNA_H
