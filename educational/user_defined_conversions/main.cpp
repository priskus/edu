#include <iostream>

class A;

class B{
public:
    B ();
    // conversion from A (constructor):
    B (const A& x);

    // conversion from A (assignment):
    B& operator= (const A& x);

    // conversion to A (type-cast operator)
    operator A();
};

class A {
public:
    A(){
        std::cout << "constructor A\n";
    }
    A(std::string S){
        std::cout << S << std::endl;
    }
    void get(){
        std::cout << "hello!\n";
    }

    operator B() {
        std::cout << "operator in A\n";
        return B();}
};


B::B (){std::cout << "constructor B\n";}

B::B (const A& x) {std::cout << "copy in B\n";}

B & B::operator= (const A& x) {
    std::cout << "assignment\n";
    return *this;}

// conversion to A (type-cast operator) оператор преобразования типа
B::operator A() {
    std::cout << "operator in B\n";
    return A();}


int main ()
{

    A a;      // calls constructor
//    a.get();
//    B bar = foo;
    B b;      // calls constructor

    b = static_cast<B>(a);      // "copy in B" or "operator in A"
    // b = a;                      //assignment
    //  a = static_cast<A>(b);      // calls type-cast operator
    return 0;
}