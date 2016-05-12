#ifndef WIELOMIAN_H
#define WIELOMIAN_H
#include "funkcja.h"
using namespace std;
#include <string>


class Wielomian : public Funkcja
{
public:
    Wielomian();
    Wielomian(int stopien);
    string napis();
    double oblicz(double x);
    void ustawDomyslny();
    double setTablicaWspolczynnikow(int stopien, double value);
protected:
    double tablicaWspolczynnikow[6];
};

#endif // WIELOMIAN_H
