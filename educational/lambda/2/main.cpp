#include <iostream>  
#include <vector>
#include <algorithm>
//int x = 7; для глобальных переменных [&x] не нужно писать



struct S{
  private:
    int a = 10;
  public:
    auto foo() {
        auto f = [b = a](int x) {//захват с инициализацией
            //заводим поле b и инициализируем его посредством a(поле класса)
            std::cout << b+x;

        };
        return f;
    }
};

int main() {
    auto f = S().foo(); //S() - вызов временного объекта
    // и создали в нем лямбда-ф, объект будет уничтожен
    //но мы скопировали в лямбда все, что нужно
    f(5); 
}