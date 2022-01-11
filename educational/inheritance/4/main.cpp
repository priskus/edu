#include <iostream>

class Base{
    int b;
public:
    int get(){
        return b;
    }
    Base(int i) : b(i){}
};

class Derived : private Base{
    int d;
public:
    Derived(int x, int y) : Base(x), d(y) {}

};

int main() {
    Derived d(10,20);
    Base &b = d;            //ошибка, только Derived знает, что он наследник Base
}