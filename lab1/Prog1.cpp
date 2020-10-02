#include <iostream>
#include "Prog1.h"
using namespace std;

int Prog1:: getNum(int &m)
{
    cin >> m;
    while(!cin.good())
        return 1;
    return 0;
}

Prog1::Int** Prog1:: create(Int** mas, int m)
{
    int Er;
    int n;
    cout << "Enter number of cols" << endl;
    Er = Prog1:: getNum(n); // number of cols
    if(Er)
    {
        return nullptr;
    }
    try{
        mas = new Int* [m];
    }
    catch (std::bad_alloc &ba) {
        std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
        delete [] mas;
        return nullptr;
    }
    /*for(int i = 0; i < m; i++)
    {
        try{
            mas[i] = new int [n];
        }
        catch (std::bad_alloc &ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            Prog1:: errase(mas,m);
            return 1;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0;j < n;j++){
            mas[i][j] = 0;
        }
    }*/
    int h;
    int key;
    int ii = 1;
    int jj;
    int* str = new int[n];
    for(int i = 0;i < m; i++){ mas[i] = new Int; mas[i][0].n = 0;}
    while(ii) {
        for(int i = 0;i < n; i++) {str[i] = 0;}
        cout << "---------------------------" << endl;
        cout << "Enter your row number. If you want to exit enter 0." << endl;
        Er = Prog1:: getNum(ii);
        if(Er) return nullptr;
        if(ii == 0) break;
        if((ii > m)||(ii < 0)) {
            cout << "Incorrect row number " << endl;
            continue;
        }
        jj = 1;
        int k = 0;
        while(jj) {
            cout << "------------" << endl;
            cout << "Enter your col number(if you want to exit, enter 0)" << endl;
            Er = Prog1:: getNum(jj);
            if(Er) return nullptr;
            if(jj == 0)
                break;
            if((jj > n)||(jj < 0)) {
                cout << "Incorrect col number " << endl;
                continue;
            }
            cout << "Enter your key" << endl;
            Er = Prog1:: getNum(key);
            if(Er) return nullptr;
            if(key == 0) {
                cout << "Incorrect key" << endl;
                continue;
            }
            if(str[jj-1] == 0) k++;
            str[jj-1] = key;
        }
        for(int i = 0; i < mas[ii - 1][0].n;i++) { //здесь мы дополняем массив str уже существующими элементами cтроки mas[i]
            if(str[mas[ii-1][i].col] == 0)
            {
                str[mas[ii-1][i].col] = mas[ii-1][i].key;
                k++;
            }
        }
        //output(str,n);
        delete [] mas[ii - 1];
        mas[ii - 1] = new Int[k];
        mas[ii - 1][0].n = k;
        //mas[ii-1][jj-1] = key;
        int nn = 0;
        for(int j = 0; j < n; j++)
        {
            if(str[j] != 0)
            {
                mas[ii - 1][nn].key = str[j];
                mas[ii - 1][nn].col = j;
                nn++;
            }
            if(nn > k) break;
        }
    }
    delete[] str;
    //Prog1:: output(mas,m);
    return mas;
}

Prog1::Int* Prog1:: createMas(Int** mas,int m)
{
    int n = 0;
    int nn = 0;
    for(int i = 0; i < m; i++)
    {
        if(mas[i][0].n != 0) {
            nn++;
        }
    }
    Int* a = new Int[nn];
    a[0].n = nn;
    for(int i = 0;i < m; i++)
    {
        if(mas[i][0].n == 0){
            //a[n] = 0;
            //n++;
            continue;
        }
        bool flag = true;
        for(int j = 0; j < mas[i][0].n; j++)
        {
            if(mas[i][j].key < 0) {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            a[n].key = mas[i][0].key;
            a[n].col = i + 1;
            n++;
        }
        else
        {
            a[n].key = mas[i][(mas[i][0].n)-1].key;
            a[n].col = i + 1;
            n++;
        }
    }
    //output(a,m);
    return a;
}

void Prog1:: errase(Int** mas, int m) {
    for (int i = 0; i < m; i++)
        delete[] mas[i];
    delete[] mas;
}

void Prog1:: output(Int** mas, int m)
{
    cout << "Output process:" << endl;
    for(int i = 0; i < m; i++){
        if(mas[i][0].n == 0)
        {
            continue;
        }
        cout << i + 1 << ". ";
        for(int j = 0;j < mas[i][0].n;j++){
            cout << mas[i][j].key << '(' << mas[i][j].col + 1 << ')' << '|';
        }
        cout << endl;
    }
}

void Prog1:: output(Int* mas)
{
    int n = mas[0].n;
    cout << "Output process:" << endl;
    for(int i = 0; i < n; i++){
            cout << mas[i].key << "(" << mas[i].col << ")"<< '|';
    }
    cout << endl;
}