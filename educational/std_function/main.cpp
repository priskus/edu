#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
//int x = 7; для глобальных переменных [&x] не нужно писать

struct S{

    bool operator()(int x, int y) const{
        std::cout << "Hello!\n";
        return x > y;
    }
};

bool g(int x, int y){
    std::cout << "Blabla\n";
    return x == y;
}

int main() {

    std::function<bool(int, int)> f;

    f = [](int x, int y){
        std::cout << "Hi!\n";
        return x < y;
    };

    f(1,2);
    f = S();
    f(3,4);

    f = g;
    f(5,6);
}