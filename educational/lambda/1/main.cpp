#include <iostream>      
#include <vector>
#include <algorithm>
//int x = 7; для глобальных переменных [&x] не нужно писать



struct S{
    int a = 10;
  //создаем  лямбда-ф-ю и возвращаем ее по значению наружу
  //для самостоятельного вызова
    auto foo() {
        auto f = [this](int x) {//[a] написать нельзя 
        //поля внешнего класса захватываются лишь через this 
        //или через захват с инициализацией
            std::cout << a+x;

        };
        return f;
    }
};

int main() {

    auto f = S().foo(); //S() - вызов временного объекта
    // и создали в нем лямбда-ф, объект будет уничтожен
    f(5); //теперь f захвтывает this несуществующего объекта S,
    //будет UB
    //но с [*this] - можно именно скопировать, а не указывать
    //и проблема решится
}