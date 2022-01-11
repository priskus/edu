#include <iostream>

template <typename T>
void f(T& x){
    std::cout << x<<std::endl;
}

template<>
void f(std::string& x){
    std::cout << "string is: "<<x<<std::endl;
}

int main() {
    double a = 10.5;
    f(a);
    std::string s = "asdf";
    f(s);

}