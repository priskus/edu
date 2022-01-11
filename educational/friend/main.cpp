#include <iostream>

using namespace std;

class A;

class B{
public:
    void act(A&);
};

class A{
    double re = 0.0;
    double im = 0.0;
    double &a = im;
    friend void B::act(A &);
//    friend B; //все методы В будут друзьями
    friend void play(A &);
public:
    void get(){
        cout <<re<<" "<< im;
    }
};

    void B::act(A &a) {
        a.im = 3.3;
    }

void play(A &a){
        a.re = 7.7;
    }


int main ()
{
    A a;
    B b;
    b.act(a);
    play(a);
    a.get();    //7.7 3.3
    return 0;
}