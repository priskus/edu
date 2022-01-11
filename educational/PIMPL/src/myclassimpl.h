#ifndef MYCLASSIMPL_H
#define MYCLASSIMPL_H

#include <string>
#include <iostream>

class MyClassImpl {
public:
    MyClassImpl();
    ~MyClassImpl();

    int callMe( int arg );

private:
    // Просто так. Чтобы было
    int a;
    std::string s;
};

#endif // MYCLASSIMPL_H