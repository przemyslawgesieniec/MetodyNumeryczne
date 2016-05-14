#include "funkcjatrygonometryczna.h"

FunkcjaTrygonometryczna::FunkcjaTrygonometryczna() : Funkcja()
{

}

string FunkcjaTrygonometryczna::napis()
{
  return "wykres funkcji trygonometrycznej";
}

double FunkcjaTrygonometryczna::oblicz(double x)
{
    return sin(x);
}

