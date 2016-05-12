#include "Wielomian.h"
#include <iostream>
using namespace std;
Wielomian::Wielomian() : Funkcja()
{
    tablicaWspolczynnikow[0]=0;
    tablicaWspolczynnikow[1]=0;
    tablicaWspolczynnikow[2]=1;
    tablicaWspolczynnikow[3]=6;
    tablicaWspolczynnikow[4]=4;
    tablicaWspolczynnikow[5]=20;

}
Wielomian::Wielomian(int stopien) : Funkcja()
{

}

double Wielomian::oblicz(double x)
{

    double y = tablicaWspolczynnikow[0];
    for(int i=1; i<6 ;i++)
    {
      y=y*x+tablicaWspolczynnikow[i];
    }
    return y;

}

double Wielomian::setTablicaWspolczynnikow(int stopien,double value)
{
    this->tablicaWspolczynnikow[stopien]=value;
}

string Wielomian::napis()
{
    return "Wykres wielomianu";
}
