#ifndef MYCLASS_H
#define MYCLASS_H

class MyClassImpl;

class MyClass {
public:
    MyClass();
    ~MyClass();

    int callMe( int arg );

private:
    MyClassImpl* pimpl;

};
#endif // MYCLASS_H