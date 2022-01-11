#include <iostream>
using namespace std;
struct A{
    virtual void f(){
        cout << "virt f A\n";
    }
    void foo(){
        cout << "foo A\n";
    }
};

struct B : public A{
    void f() override{
        cout << "virt f B\n";
    }
    void foo(){
        cout << "foo B\n";
    }
};

struct C : public B{

    void foo(){
        cout << "foo C\n";
    }
};

int main() {
    C c;
    c.f();  //virt f B  У С нет своей версии,
            // но вызовется самая частная версия
            //виртуальной ф-ции - в самом дальнем наследнике
    A &a = c;
    c.f();  //virt f B

}