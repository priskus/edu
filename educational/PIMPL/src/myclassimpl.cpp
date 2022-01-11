#include "myclassimpl.h"


MyClassImpl::MyClassImpl() {
    std::cout << "MyClassImpl ctor\n";
}

MyClassImpl::~MyClassImpl() {
    std::cout << "MyClassImpl dtor\n";
}

int MyClassImpl::callMe( int arg ) {
    return arg;
}