#include <iostream>
using namespace std;
struct A{
    virtual void f(){
        cout << "f A\n";
    }
    void foo(){
        cout << "foo A\n";
    }
};

struct B : public A{
    void f() override{
        cout << "f B\n";
    }
    void foo(){
        cout << "foo B\n";
    }
};

struct C : public B{
    void f(){
        cout << "f C\n";
    }
    void foo(){
        cout << "foo C\n";
    }
};

int main() {
    C c;
    A &a = c;
    a.foo();    //foo A
    a.f();      //f B   virtual

    c.foo();    //foo B
    c.A::foo();    //foo A

}