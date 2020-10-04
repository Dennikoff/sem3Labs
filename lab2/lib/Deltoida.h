#ifndef CPPSEM3LAB2_DELTIODA_H
#define CPPSEM3LAB2_DELTIODA_H
#include <cmath>
double const PI = 3.141592;
namespace Prog2{
    struct Point {
        double x;
        double y;
    };
    class Deltoida{
    private:
        double r,t;
    public:
        explicit Deltoida(double r0 = 1.0, double t0 = 0);
        Deltoida setR(double a = 1);
        Deltoida& setT(double a = 1){t = a; return *this;};
        double getR() const {return r;};
        double getT() const {return t;};
        double getLengthKas() const{return 4*r;};
        double getLength() const{return 16*r;};
        double getS() const{return 2*PI*r*r;};
        Point getXY();
        const char* formulaX() const;
        const char* formulaY() const;
    };

    /*template<class T>
    int getNum(T &);*/
}



#endif //CPPSEM3LAB2_DELTIODA_H
