#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


class Base{
protected:
    int a = 0;
public:
    void f(){
        std::cout << "Base\n";
    }
};

class Derived: public Base{
private:
    int pr =10;
public:

    int b = 1;
    void g(const Base &x){
        std::cout << x.a;  //обращаемся не по ветке наслед. а как к отбъекту другого типа
        std::cout << a;    
    }

    void g(const Derived &x){
        std::cout << x.a;  //обращаемся к отбъекту того же класса
        std::cout << x.pr;
    }
};

int main ()
{
    return 0;
}