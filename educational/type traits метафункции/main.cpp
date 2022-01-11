#include <iostream>
//метафункция, которая принимает два типа и возвращает bool
template <typename U, typename V>
struct is_same{
    static const bool value = false;
};

template <typename U>
struct is_same<U, U>{
    static const bool value = true;
};

//объявление шаблонной переменной is_same_v
//для более компактного обращения:

// template <typename U, typename V>
// const bool is_same_v = is_same<U, V>::value;


template <typename U, typename V>
void f(U x, V y){

    if(is_same<U, V>::value){   // if(is_same_v<U, V>)
        std::cout << "The same\n";
    } else {
        std::cout << "Not the same\n";
    }
}

int main() {
    f(10.5, 10.5);
    f(10.5, "10.5");

}

