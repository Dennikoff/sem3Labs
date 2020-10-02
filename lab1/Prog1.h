namespace Prog1{
using namespace std;
    //template <class T>
    struct Int{
        int key;
        int col; //col number
        int n; // number of the elements
    };
    int getNum(int &);
    Int** create(Int**, int);
    void errase(Int**, int);
    void output(Int**, int);
    void output(Int*);
    Int* createMas(Int**,int);
}