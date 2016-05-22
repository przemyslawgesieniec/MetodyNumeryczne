#include "funkcjatrygonometryczna.h"

FunkcjaTrygonometryczna::FunkcjaTrygonometryczna() : Funkcja()
{

}

string FunkcjaTrygonometryczna::napis()
{
  return "wykres funkcji trygonometrycznej";
}

double FunkcjaTrygonometryczna::oblicz(double x,bool waga)
{
    double y =  sin(x);
    if(waga==1)
    {
        y=y/sqrt(1-x*x);
    }
    return y;
}

