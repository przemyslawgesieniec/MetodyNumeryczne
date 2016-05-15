#include "funkcjazlozona1.h"

FunkcjaZlozona1::FunkcjaZlozona1():Funkcja()
{

}

string FunkcjaZlozona1::napis()
{
  return "wykres funkcji zlozonej";
}

double FunkcjaZlozona1::oblicz(double x)
{
    return sqrt(1+x);
}
