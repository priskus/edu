#include <iostream>

struct GrandBase{
    virtual void f() = 0;
    virtual ~GrandBase() = 0;
};
//когда вызывается delete b, компилятор видит, что это виртуальная ф-ция
//значит нужно вызвать деструктор самого последнего наследника, и так по цепочке
//до первого родителя, но если у него деструктор объявлен, но не определен,
// получаем ошибку линковщика - undefined reference to `GrandBase::~GrandBase()'
// поэтому нужно его определить:
GrandBase::~GrandBase() {
    std::cout << "~GrandBase\n";
}

struct Base: public GrandBase{
    int *a = new int();
    void f() override {}

    ~Base() override{
        delete a;
        std::cout << "~Base";
    }
};

struct Derived: public Base{
    int *b = new int();
    ~Derived() override{
        delete b;
        std::cout << "~Derived";
    }
};

int main() {
    GrandBase *b = new Derived();
    delete b;
}