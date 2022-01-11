#include "myclass.h"
#include "myclassimpl.h"

MyClass::MyClass() : pimpl( new MyClassImpl ) {
    std::cout << "MyClass ctor\n";
}

MyClass::~MyClass() {
    std::cout << "MyClass dtor\n";
    delete pimpl;
}

int MyClass::callMe( int arg ) {
    return pimpl->callMe( arg );
}