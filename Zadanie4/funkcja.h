#ifndef FUNKCJA_H
#define FUNKCJA_H
#include <string>
using namespace std;

class Funkcja
{
public:
    Funkcja() {};
    virtual ~Funkcja() {};
    virtual double oblicz(double x1)=0;
    virtual string napis()=0;
protected:
    double x1;
    double xn;
};

#endif // FUNKCJA_H
