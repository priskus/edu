#include <iostream>
#include <cstring>
using namespace std;

struct Complex{
    double re = 0.0;
    double im = 0.0;

    Complex(const Complex& z){
        cout << "copy construct from "<<z.re<<endl;
        re = z.re;
        im = z.im;
    }

    Complex(double x = 0.0, double y = 0.0): re(x), im(y){}

    Complex &operator+=( Complex& z){
        re += z.re;
        im += z.im;
        return *this;
    }               //в дебаге 2й конструктор вызывается после этого места
    //но зачем конструировать объект?
};

Complex operator+( Complex &a,  Complex &b){
    Complex copy = a;   //вызов к. копир.
    return copy+=b;   //expression with copy variable
    //результат оператора += сохраняется в rvalue
    //для которого, тем не менее, нужно вызвать конструктор
    //это rvalue тут же возвращается из operator+

}
int main ()
{
    Complex c(2.0);
    Complex d(3.0, 1.0);

    c+d;
    return 0;
}