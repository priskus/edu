#include <iostream>

template <typename T>
void f(T t){

    *t = 100;
//    typename std::remove_pointer<T>::type x = *t; или
    std::remove_pointer_t<T> x = *t;
    x = 15;
}

int main() {
    int i = 19;
    f(&i);
    std::cout << i;
}