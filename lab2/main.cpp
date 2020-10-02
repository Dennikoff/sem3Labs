#include <iostream>
#include "Deltoida.h"
using namespace Prog2;
//using namespace std;
int main()
{
    Deltoida c(1,0);
    try
    {
        Deltoida c(10);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    int fl1 = 1;
    double r;
    const char *s = NULL;
    while(fl1) {
        std::cout << "Your X formula is:" << std::endl;
        s = c.formulaX();
        std::cout << s << std::endl;
        std::cout << "Your Y formula is:" << std::endl;
        s = c.formulaY();
        std::cout << s << std::endl;
        delete [] s;
        std::cout << "LengthKas = " << c.getLengthKas() << std::endl;
        std::cout << "Length of the line " << c.getLength() << std::endl;
        std::cout << "S = " << c.getS() << std::endl;
        int fl2 = 1;
            try{
                Point res = c.getXY();
                if(res.y == 0)
                    std::cout << "x = "<< res.x << ", y = " << res.y << std::endl;
                else
                    std::cout << "x = " << res.x << ", y1 = " << res.y << ", y2 = " << (-1) * res.y << std::endl;
            }
            catch(std::exception &ex)
            {
                std::cout << ex.what() << std::endl;
            }
        std::cout << "Enter new r and t to continue or press ctrl+Z to quit:" << std::endl;
        double t;
        std::cin >> r >> t;
        if(std::cin.good()){
            c.setT(t);
            try{
                c.setR(r);
            }
            catch (std::exception &ex)
            {
                std::cout << ex.what() << std::endl << std:: endl;
            }
        }
        else
            fl1 = 0;
    }
    return 0;
}