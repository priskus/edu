#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct Base{
    void f(double){
        std::cout << "Base";
    }
};

struct Derived: Base{
    using Base::f;  //теперь метод родителя участвует в перегрузке
    //using добавляет в область видимости то, что написали после него
    void f(int){
        std::cout << "Derived";
    };
};

int main ()
{
    Derived d;
    d.f(0.0); //Base Но если бы метод f(double) в базе был private,
              //была бы ошибка к. так как сначала выбирается правильная версия метода
              //и только потом выястняется, что метод private
    return 0;
}