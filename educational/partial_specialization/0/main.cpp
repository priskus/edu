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

//-------------------partial specialization of template class declaretion
template<typename T>
class Base<const T>{
public:
    void print (T x){
        std::cout << "typeid(x).name()"<<std::endl;
    }
};
//-------------------specialization  of class
template<>
class Base<int>{
public:
    void print (int x){
        std::cout << "here is Int"<<std::endl;
    }
};


int main()
{
    Base<std::string> base;
    base.print("sdf");

    Base<const int> base2;
    const int n = 123;
    base2.print(n);

    Base<int> base3;
    base3.print(777);
}