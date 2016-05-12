#ifndef INTERPOLACJAWIELOMIAN_H
#define INTERPOLACJAWIELOMIAN_H
#include "interpolacja.h"
#include <vector>
using namespace std;

class InterpolacjaWielomian : public Interpolacja
{
public:
    InterpolacjaWielomian();
    double oblicz(vector <double> x, vector<double> y, double var);
protected:

};

#endif // INTERPOLACJAWIELOMIAN_H
