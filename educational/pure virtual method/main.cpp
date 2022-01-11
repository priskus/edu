#include <chrono>
#include <iostream>


class Abstract{
public:
    virtual void pure() = 0;

};

//определение чисто абстрактного метода не подразумевает возможности
//создания объекта его класса
//его просто можно будет вызвать у объекта наследника
void Abstract::pure() {
    std::cout << "This is a pure virtual method\n";
}

class Child : public Abstract{
public:
    void pure() override{
        std::cout << "This is an overrided method\n";
    }
};

int main()
{
    Child ch;
    ch.Abstract::pure();
    ch.pure();

    return 0;
}