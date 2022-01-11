#include <iostream>
using namespace std;

class A {
int x = 10;
double d = 7.0;

void f(int a){
    cout << a+x;
}
public:
A() = default;
A(char c, double d) = delete;
A(int n, double d){
    x = n;
    this->d = d;
}

void f(double a){
    cout << d+x;
}
};

int main ()
{

    A a     = A('a',5.7);      // хоть char и может быть преобразован к int
                               //но выберется именно конструктор A(char c, double d)
                               //а не A(int n, double d)
                               //потому что СНАЧАЛА КОМПИЛЯТОР ИЩЕТ ИДЕАЛЬНОЕ СООТВЕТСТВИЕ
                               //ф-ции(кон-ра), а потом уже смотрит, а вообще можно ли это вызвать
                               //нет ли там private или =delete
    A a1    = A(7, 7.7);
    a1.f(4);                //для f(int) аналогичная ситуация
    return 0;
}