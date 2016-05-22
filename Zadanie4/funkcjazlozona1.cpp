#include "funkcjazlozona1.h"

FunkcjaZlozona1::FunkcjaZlozona1():Funkcja()
{

}

string FunkcjaZlozona1::napis()
{
  return "wykres funkcji zlozonej";
}

double FunkcjaZlozona1::oblicz(double x,bool waga)
{   
    double y = sqrt(1+x);
    if(waga==1)
    {
        y=y/sqrt(1-x*x);
    }
    return y;
}
