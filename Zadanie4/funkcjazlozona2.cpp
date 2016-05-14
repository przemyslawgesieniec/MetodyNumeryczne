#include "funkcjazlozona2.h"

FunkcjaZlozona2::FunkcjaZlozona2():Funkcja()
{

}

string FunkcjaZlozona2::napis()
{
  return "wykres funkcji zlozonej";
}

double FunkcjaZlozona2::oblicz(double x)
{
    return sin(x*x)*cos(x) * 2*x*x;
}
