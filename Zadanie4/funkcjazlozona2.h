#ifndef FUNKCJAZLOZONA2_H
#define FUNKCJAZLOZONA2_H
#include "funkcja.h"
#include <string>
#include <math.h>
class FunkcjaZlozona2 :public Funkcja
{
public:
    FunkcjaZlozona2();
    string napis();
    double oblicz(double x);
};

#endif // FUNKCJAZLOZONA2_H
