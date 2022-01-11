#include <iostream>
//------------------  template class declaretion
template <typename T>
class Base{
public:
    void print (T x);
};

//-------------------description of method outside of template class
template<typename T>
void Base<T>::print(T x) {
    std::cout << "general type\n";
}

//-------------------specialization of template class declaretion
template<>
class Base<int>{
public:
    void print (int x);
};

//-------------------specialization description of method outside of template class
void Base<int>::print(int x) {
    std::cout << "int type\n";
}


int main()
{
    Base<std::string> base;
    base.print("sdf");

    Base<int> base2;
    base2.print(123);
}