#ifndef FUNKCJAZLOZONA1_H
#define FUNKCJAZLOZONA1_H
#include "funkcja.h"
#include <string>
#include <math.h>
class FunkcjaZlozona1 :public Funkcja
{
public:
    FunkcjaZlozona1();
    string napis();
    double oblicz(double x, bool waga);
};

#endif // FUNKCJAZLOZONA1_H
