#include <iostream>

class Base{
    int b;
public:
    int get(){
        return b;
    }
    Base(int i) : b(i){}
};

class Derived : public Base{
    int d;
public:
    Derived(int x, int y) : Base(x), d(y) {}
    void get(){
        std::cout << d <<' '<<Base::get();
    }
};

int main() {
    Derived d(10,20);
    d.get();
}