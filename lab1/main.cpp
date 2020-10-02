#include <iostream>
#include "Prog1.h"

using namespace std;
int main() {
    Prog1:: Int** mas;
    int m;
    cout << "Enter number of rows" << endl;
    int Er = Prog1:: getNum(m); // number of rows
    if(Er)
    {
        return 1;
    }
    mas = Prog1:: create(mas,m);
    if(!mas) {
        cout << "ERROR" << endl;
        return 1;
    }
    Prog1:: output(mas, m);

    Prog1:: Int* a = Prog1:: createMas(mas,m);
    Prog1:: output(a);
    return 0;
}
