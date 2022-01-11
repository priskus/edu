#include <iostream>    
#include <vector>
#include <algorithm>
//int x = 7; для глобальных переменных [&x] не нужно писать



struct S{
private:
    int a = 1;

public:
    auto foo() {
        std::string s = "avasdff";//этот объект будет уничтожен,
        // если он создан во временном S()
        //но мы хотим передать его в лямбда по const ссылке

        auto f = [&s = std::as_const(s)](int x) {
            //as_const возвращает const ссылку на s
            std::cout << x + s.size();

        };
        return f;
    }
};

int main() {
    auto f = S().foo(); //S() - вызов временного объекта
    // и у него создали в нем лямбда-ф, объект будет уничтожен
    f(5); 
}