#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Base{
protected:
    void f(double){
        std::cout << "Base";
    }
};

class Derived: Base{
    //using Base::f;  можно написать using в private области, тогда извне недоступно Base::f
public:
    using Base::f;
    void f(int){
        std::cout << "Derived";
    };
};

int main ()
{
    Derived d;
    d.f(0.0);
    return 0;
}