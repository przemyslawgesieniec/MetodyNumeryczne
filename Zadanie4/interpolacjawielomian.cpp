#include "interpolacjawielomian.h"
InterpolacjaWielomian::InterpolacjaWielomian() : Interpolacja()
{

}
double InterpolacjaWielomian::oblicz(vector<double> x, vector<double> y,double var)
{
    double Y=0;
    double L=1;
    double M=1;
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<x.size();j++)
        {
            if(j!=i)
            {
                 L*=(var-x[j]);
                 M*=(x.at(i)-x.at(j));
            }
        }
        Y+=y.at(i)*(L/M);
        L=1;
        M=1;
    }
    return Y;
}
