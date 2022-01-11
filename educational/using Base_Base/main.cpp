#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Base0{

public:
    string s;
    Base0() : s("first")    {  cout << "Base0\n";  }
};

class Base{

public:
    int y;
    Base(int y) : y(y)    {  cout << "Base\n";  }
};

class Derived: Base, Base0{
    int z;

    using Base::Base;//все конструкторы
    // базового класса участвуют в перегрузке
    //конструктора дочернего класса
public:
    void get(){
        cout << y<< ' '<<z<<' '<<s;
    }

};

int main ()
{
    Derived d(7);   //вызовется Base(int y)
                    //остальные поля доч. класса иниц-ся по улолчанию
                    //и вызовутся конс-ры по умолч. других родительских
                    //классов класса Derived
    d.get();
    return 0;
}