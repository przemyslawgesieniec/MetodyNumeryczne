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
   // double y = sqrt(7+x*x*x*x*x);
    double y = log(0.99);
    if(waga==1)
    {
        y=y/sqrt(1-x*x);
    }
    return y;
}
