#include <iostream>
using namespace std;
struct A{
    virtual void f() const{
        cout << "virt f A\n";
    }

};

struct B : public A{
    void f(){
        cout << "f B\n";
    }
};

int main() {
    B b;
    A &a = b;
    a.f();      //virt f A
                //не const можно давай туда, где ожидается const
                //произойдет cast к const

}