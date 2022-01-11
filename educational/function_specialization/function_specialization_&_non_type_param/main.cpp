#include <iostream>

template <typename T, int size>
void f(T& x){
    std::cout << x<<size<<std::endl;
}

template<int size>
void f(std::string& x){
    std::cout <<size<< " string is: "<<x<<std::endl;
}

int main()
{
    std::string s = "1231";
    std::string& ps = s;
    f<12>(ps);  //12 string is: 1231

}