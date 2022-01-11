#include <iostream> 
#include <vector>
#include <algorithm>

struct S{
private:
    int a = 1;

public:
    auto foo() {
        std::string s = "avasdff";

        auto f = [=](int x) {
            //через [=] захватывается и this
            //поле а внешнего класса не захватывается по значению,
            //как может показаться, ведь поля внешнего класса доступны только
            //через this. Так где будем писать а, на самом деле будет this->a
            //итог: а не захвачено по значению, и в лямбда будет висячая ссылка
            //на уничтоженный временный объект S()

            //[=] не стоит использовать
            std::cout << a+x;
        };
        return f;
    }
};

int main() {
    auto f = S().foo();
    f(5);
}