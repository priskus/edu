#include <iostream>
#include <cstring>
using namespace std;

struct A{
    double re = 0.0;
    double im = 0.0;
    double &a = im;
    A(double re, double im): re(re), im(im){}

    void act() const{
        a = 3;  //через ссылку можно менять im
//        im = 4;   //хотя напрямую нельзя
        cout << a << '\n';  //3
//        const методы считают поля класса костантами
//         исключение - ссылки, через них можно менять поля, на которые они ссылаются
    }
};

int main ()
{

    const A ac(1,1);
    ac.act();
   cout << ac.im;
    return 0;
}