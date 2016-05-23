#include <iostream>
#include <QDebug>
#include <cmath>
#include <vector>
#include <limits>
#include <math.h>
#include "wielomian.h"
#include "funkcja.h"
#include "gauss.h"
#include "newtoncotes.h"
#include "calkowanie.h"
#include "funkcjatrygonometryczna.h"
#include "funkcjazlozona1.h"
#include "funkcjazlozona2.h"
#define PRZESKOK 200

using namespace std;

//void wartosciWezlow(vector<double> *wskArgiXnode, vector<double> *wskArgiYnode, Interpolacja *wskinter, Funkcja *wsk);
void podajArgumenty(double *wskX1, double *wskXn);
double policzGranice(double x1, double xn, Funkcja *wsk, Calkowanie *calka, double Y, double *wskDokladnosc, vector<double> argX, double dokladnosc, double iteracja);
int main()
{

        Funkcja * wsk;
        Wielomian *f1;
        FunkcjaTrygonometryczna *f2;
        FunkcjaZlozona1 *f4;
        FunkcjaZlozona2 *f5;

        Calkowanie * calka;
        NewtonCotes * NC;
        Gauss * gauss;

        /////////////////////////////////////////////////////////////////////////////////////////////
        int key;
        double x1;
        double xn;
        double dokladnosc;
        double *wskX1 = &x1;
        double *wskXn = &xn;
        bool waga=0;

        cout<<"Witaj w programie calkujacym metodami Newtona-Cotesa oraz kwadratura Gaussa:"<<endl;
        cout<<"Wybierz funkcje dla ktorej chcesz dokonac obliczen: "<<endl<<endl;
        cout<<"____________________________________"<<endl;
        cout<<"1) Wielomian"<<endl;
        cout<<"2) funkcja trygonometryczna"<<endl;
        cout<<"3) funkcja zlozona1"<<endl;
        cout<<"4) funkcja zlozona2"<<endl;
        cout<<"____________________________________"<<endl<<endl;
        cout<<"Wybieram funkcje nr: ";
        cin>>key;
        char wybor;
        switch (key)
        {
        case 1:
        {
            cout<<"Wielomian:"<<endl;
            cout<<"Czy chcesz samodzielnie wybrac stopien wielomianu i podac jego wspolcznniki ?(T/N)"<<endl;
            cin>>wybor;
            if(wybor=='T' || wybor=='t')
            {
               int stopien;
               cout<<"Podaj stopien wielomianu ( max 5 ):";
               cin>>stopien;
               f1 = new Wielomian(stopien);
               if(stopien>5)
               {
                   cout<<"podano za wysoki stopien wielomianu"<<endl;
                   cout<<"zadanie wykonane zostanie dladomyslnego wielomianu"<<endl;
               }
               else
               {

               cout<<"Podaj wspolcznniki wielomianu:";
               int i;
               for(i=0;i<6; i++)
               {
                   f1->setTablicaWspolczynnikow(i,0);
               }
               int value=0;
               for(i=1;i<=stopien; i++)
                    {
                        cout<<"Podaj wspolczynnik "<<char(96+i)<<endl;
                        cin>>value;
                        f1->setTablicaWspolczynnikow(4-stopien+i,value);
                    }
               cout<<"Podaj wyraz wolny:";
               cin>>value;
               f1->setTablicaWspolczynnikow(5,value);
               wsk=f1;
               }
            }
            else
            {
               cout<<"Zostalo wybrane domyslne rownanie wielomianu"<<endl;
               f1 = new Wielomian();
               wsk=f1;
            }
            break;
            }
        case 2:
            {
            cout<<"Wybrano funkcje trygonometryczna";
            f2 = new FunkcjaTrygonometryczna();
            wsk=f2;
            break;
            }
         case 3:
            {
                cout<<"Wybrano funkcje zlozona";
                f4 = new FunkcjaZlozona1();
                wsk=f4;
                break;
            }
        case 4:
           {
               cout<<"Wybrano funkcje zlozona";
               f5 = new FunkcjaZlozona2();
               wsk=f5;
               break;
           }
        default:
             {
             cout<<"nie wybrano poprawnej funkcji..."<<endl<<endl;
             break;
             }
        }
    cout<<"Podaj metode calkowania: "<<endl;
    cout<<"1) Kwadratura Newtona-Cotesa"<<endl;
    cout<<"2) Kwadratura Gausa"<<endl;
    int wybor2;
    cin>>wybor2;
    int czyWaga=0;
    switch(wybor2)
    {
        case 1:
        {
            cout<<"Wybrano Kwadrature Newtona-Cotesa."<<endl;
            cout<<"Czy chcesz uwzglednic wage? 1-Tak, 2-Nie"<<endl;
            cin>>czyWaga;
            if(czyWaga==1)
            {
                waga=1;
                x1=-1;
                xn=1;
            }
            else
            {
                podajArgumenty(wskX1,wskXn);
            }
            NC = new NewtonCotes();
            calka=NC;
            cout<<"Podaj dokladnosc: ";
            cin>>dokladnosc;
            break;
        }
        case 2:
        {
            cout<<"Wybrano Kwadrature Gausa."<<endl;
            x1=-1;
            xn=1;
            gauss = new Gauss();
            calka=gauss;
            break;
        }
        default:
        {
            cout<<"Nie wybrano metody"<<endl;
            return 0;
            break;
        }
    }
    if(x1!=-1 && xn!=1)
    {
        vector <double> argX;
        double otrzymanaDokladnosc = UINT_MAX;
        int iteracja = 2;
        double Y = UINT_MAX;
        double tmpY=0;
        while(otrzymanaDokladnosc > dokladnosc)
        {
            double n = 2 * iteracja;//liczba podzialow
            double h = (xn-x1)/ n;
            for(int i=0;i<n+1;i++)
            {
                argX.push_back(x1+h*i);
            }
            tmpY = calka->calkuj(argX,h,wsk,waga);
            otrzymanaDokladnosc = fabs(Y-tmpY);
            Y=tmpY;
            cout<<"przyblizona wartosc calki w "<<iteracja-1<<" iteracji wynosi: "<<Y<<" a dokladnosc: "<<otrzymanaDokladnosc<<endl;
            iteracja++;
            argX.clear();
        }
    }
    else if(wybor2==1)
    {
        vector <double> argX;
        double otrzymanaDokladnosc = UINT_MAX;
        int iteracja = 2;
        double Y = 0;
        //0 do 1
        x1=0;
        xn=0.5;
        double deltaX=0;
        while(otrzymanaDokladnosc > dokladnosc)
        {
            double *wskDokladnosc = &otrzymanaDokladnosc;
            Y= policzGranice(x1,xn,wsk,calka,Y,wskDokladnosc,argX,dokladnosc,iteracja);
            deltaX=xn-x1;
            x1=xn;
            xn=x1+(0.5*deltaX);
            iteracja++;
        }
        //od -1 do 0
        otrzymanaDokladnosc = UINT_MAX;
        x1=-0.5;
        xn=0;
        deltaX=0;
        while(otrzymanaDokladnosc > dokladnosc)
        {
            double *wskDokladnosc = &otrzymanaDokladnosc;
            Y= policzGranice(x1,xn,wsk,calka,Y,wskDokladnosc,argX,dokladnosc,iteracja);
            deltaX=xn-x1;
            xn=x1;
            x1=xn-(0.5*deltaX);
            iteracja++;
        }
    }
    else if(wybor2==2)
    {
        double h=0;
        vector <double> argX;
        vector <double> argY;
        for(int n=2;n<6;n++)
        {
            for(int i=1;i<=n;i++)
            {
                argX.push_back(cos(M_PI*(2*i-1)/(2*n)));
            }
            argY.push_back(calka->calkuj(argX,h,wsk,waga));
            argX.clear();
        }
        for(int i=0;i<4;i++)
        {
            cout<<argY.at(i)<<endl;
        }
    }
return 0;
}
void podajArgumenty(double *wskX1, double *wskXn)
{
    double x1,xn;
    cout<<endl<<"podaj krance przedzialu dla wybranej funkcji: "<<endl;
    cout<<"podaj LEWY kraniec przedzialu: "<<endl;
    cin>>x1;
    cout<<"podaj PRAWY kraniec przedzialu: "<<endl;
    cin>>xn;
    *wskX1=x1;
    *wskXn=xn;
}
double policzGranice(double x1,double xn,Funkcja *wsk,Calkowanie *calka,double Y,double *wskDokladnosc,vector <double> argX,double dokladnosc,double iteracja)
{
    double n = PRZESKOK;
    double tmpY=0;
    double otrzymanaDokladnosc;
    double h = (xn-x1)/ n;
    for(int i=0;i<n+1;i++)
    {
        argX.push_back(x1+h*i);
    }
    tmpY = calka->calkuj(argX,h,wsk,1);
    otrzymanaDokladnosc = fabs(tmpY);
    if(otrzymanaDokladnosc>dokladnosc)
    {
        Y+=tmpY;
    }
    else
    {
        cout<<">>Otrzymane przyblizenie jest granica<<"<<endl;
    }
    cout<<"przyblizona wartosc calki w "<<iteracja-1<<" iteracji wynosi: "<<Y<<" a dokladnosc: "<<otrzymanaDokladnosc<<endl;
    iteracja++;
    argX.clear();
    *wskDokladnosc = otrzymanaDokladnosc;
    return Y;
}
