#include <iostream>


template <typename T>
const T& max(const T& a, const T& b){
    return a > b ? a : b;
}

int main() {

    std::cout << max<double>(10, 15.3);
    //если компилятор не знает какой тип int или double
    //принять за T, Это можно указать явно в <>

}