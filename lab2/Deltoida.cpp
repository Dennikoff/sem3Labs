#include <iostream>
#include "Deltoida.h"
#include <strstream>
#include <string.h>
#include <stdio.h>
#include <math.h>

namespace Prog2{

    Deltoida:: Deltoida(double r0, double t0)
    {
        if(r0 < 0)
        {
            throw std::exception("Invalid radius");
            /*std:: cout << "Invalid radius. r = default(1)" << std::endl;
            r0 = 1;*/
        }
        r = r0;
        t = t0;
    }

    Point Deltoida:: getXY() {
        Point res;
        res.x = 2*r*cos(t) + r*cos(2*t);
        res.y = 2*r*sin(t) - r*sin(2*t);
        return res;
    };

    Deltoida Deltoida::setR(double a)
    {
        if(a < 0)
            throw std::exception("Invalid radius");
        r = a;
        return (*this);
    }

    const char* Deltoida::formulaX() const
    {
        char s1[] = "x = 2**cos()+*cos(2*)";
        int l = strlen(s1)+ 1;
        char num[20];
        sprintf_s(num,20,"%g",r);
        l+= strlen(num)*2;
        sprintf_s(num,20,"%g",t);
        l+= strlen(num)*2;
        char* s = new char[l];
        sprintf_s(s,l,"x = 2*%g*cos(%g)+%g*cos(2*%g)",r,t,r,t);
        //std:: cout << s << std:: endl;
        return s;
    }
    const char* Deltoida::formulaY() const
    {
        char s1[] = "x = 2**sin()-*sin(2*)";
        int l = strlen(s1)+ 1;
        char num[20];
        sprintf_s(num,20,"%g",r);
        l+= strlen(num)*2;
        sprintf_s(num,20,"%g",t);
        l+= strlen(num)*2;
        char* s = new char[l];
        sprintf_s(s,l,"y = 2*%g*sin(%g)-%g*sin(2*%g)",r,t,r,t);
        //std:: cout << s << std:: endl;
        return s;
    }
    /*template <class T>
    int getNum(T &m) {
        std::cin >> m;
        if (!(std::cin.good()))
            return 1;
        return 0;
    }*/
}
