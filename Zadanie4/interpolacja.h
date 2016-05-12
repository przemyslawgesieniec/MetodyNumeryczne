#ifndef INTERPOLACJA_H
#define INTERPOLACJA_H
#include <vector>

using namespace std;

class Interpolacja
{
public:
    Interpolacja() {};
    virtual ~Interpolacja() {}
    virtual double oblicz(vector<double> x, vector<double> y,double var)=0;
};


#endif // INTERPOLACJA_H
