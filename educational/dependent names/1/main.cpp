#include <iostream>
#include <vector>

template <typename T>
struct SS{
    template<int M, int N>
    struct A{};
};

template <>
struct SS<int> {
    static const int A = 0;
};

int a  = 0;

template<typename T>
void g(){
    // SS<T>::A<1, 2> a; //без typename A - имя переменной, за ней знак меньше
   typename SS<T>:: template A<1, 2> a;
    //template - указание, что за этим словом имя шаблона

}

int main() {


}

